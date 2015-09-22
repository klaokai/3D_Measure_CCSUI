#ifndef GES_CCS_CONTROL_H
#define GES_CCS_CONTROL_H
#include "stdio.h"
#include "ges_work.h"
#include "cAcqEasyType.h"
#include "cAcqEasy.h"
#include "afxmt.h"
#include "DataSave.h"
bool ges_ccs_control(sAcqEasyParam* acqEasyParam,MCHR_ID SensorID,HANDLE evAcquisition,cAcqEasy* pAcqEasy,FILE *File_z,int x,int y,int step,float vel,int height,int width,int countSum,int* nowCount)
{
	short rtn =0 ; //电机操作后的返回值，0表示无错误
		
	//Acquisition user buffer
	float *pAltitude = NULL;
	float *pIntensity = NULL;
    int DataCount = 0;
    short resultProcess = 0;
	rtn = GT_System_Initinal();									//平台初始化
	if(rtn!=0)
	{
		printf("电机初始化失败！");
		return false;
	}

	rtn = AxisInitial(2,15);									//控制轴初始化函数						
	if(rtn!=0)
	{
		printf("电机控制轴初始化失败！");

		return false;

	}															   
	rtn = MotionInitial();										//轴运动参数初始化
	if(rtn!=0)
	{
		printf("电机控制轴运动参数初始化失败！");
		return false;
	}

	//电机指令缓冲区设置需要运动的轨迹初始化（X、Y轴未运动）
	/*(2)*/
	rtn = GT_Buffer();

	if(rtn!=0)
	{

		printf("电机缓冲区运动指令设置失败！");
		return false;
	}

	for(int i=1;i<=height;i++)
	{
		(*nowCount)++;
		printf("已完成 %.2f %% !!!\n",((*nowCount)*1.0/countSum*100));
		rtn = GT_Check_status();
		if(rtn!=0)
		{
			printf("检测电机状态失败！");
			return false;
		}
		GT_ExOpt(0x0000);       //外部触发Exo6置0
		Sleep(10);
		pAltitude = new float[width];
		pIntensity = new float[width];
		//read acquisition result
		GT_ADD_Buffer_trigger(x,y,vel);//速度12.5mm/s
		Sleep(10);
		GT_ExOpt(0x0000);
		resultProcess = Process(pAcqEasy, evAcquisition, *acqEasyParam, pAltitude, pIntensity,&DataCount); 
		if (resultProcess == STATUS_NO_ERROR)
		{
			if (!DataSave(File_z,pAltitude,1,width))
				printf("DataSave Error!");
			if (!DataSave(File_z,pIntensity,1,width))
				printf("DataSave Error!");
		}	
		else
		{
			if (resultProcess != STATUS_TIMEOUT_ERROR)
			{
				printf("Main : Process() : Error 0x%X\n", resultProcess);
			}
		}
		
		y = y + step;//12.5um	pluse = 0.5um
		if(rtn!=0)
		{
			printf("电机缓冲区指令执行失败！");
			return false;
		}
		else
		{
			rtn = GT_Check_status();
			if(rtn!=0)
			{
				printf("检测电机状态失败！");
				return false;
			}	
		}
		rtn = GT_ADD_Buffer_continue(0,y,100);
		if(rtn!=0)
		{
			printf("电机缓冲区指令执行失败！");
			return false;
		}
		else
		{
			rtn = GT_Check_status();
			if(rtn!=0)
			{
				printf("检测电机状态失败！");
				return false;
			}	
			Sleep(1000);//?
		}
		delete[] pAltitude;
		delete[] pIntensity;
	}
	return true;
}
#endif