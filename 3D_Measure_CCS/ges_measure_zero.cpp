#include "ges_measure_zero.h"	
#include "stdafx.h"
#include "ges_work.h"
#include <windows.h>
bool ges_messure_zero(int x,int y)
{
	int isMyCyc = false;
	int xSetPoint;
	int ySetPoint;
	bool MyPointFlag = false;
	//判断输入x不能大于400、y不能大于350
	if( x>400 || y>350 )
	{
		printf("超出最大测量范围！");
		return false;
	}

	xSetPoint = x*1000*2+10000;
	ySetPoint = y*1000*2+10000;

	short rtn =0; //电机操作后的返回值，0表示无错误
	if(false == MyPointFlag)
	{
		rtn =GT_GetLmtZero_X();										//X轴运动到极限位置并设置为坐标原点
		if(rtn!=0)
		{
			printf("X轴设置原点失败！");
			return false;
		}
		//*******************************************
		//检测电机状态
		/*(3)*/
		rtn = GT_Check_status();
		if(rtn!=0)
		{
			printf("检测电机状态失败！");
			return false;
		}

		Sleep(3000);
		//Sleep(xSetPoint*0.1);

		rtn =GT_GetLmtZero_Y();										//Y轴运动到极限位置并设置为坐标原点
		if(rtn!=0)
		{
			printf("Y轴设置原点失败！");
			return false;
		}

		//Sleep(ySetPoint*0.1);		

		//*******************************************
		//检测电机状态
		/*(3)*/
		rtn = GT_Check_status();
		if(rtn!=0)
		{
			printf("检测电机状态失败！");
			return false;
		}

		Sleep(3000);

		MyPointFlag = TRUE;
	}

	if(FALSE == isMyCyc)
	{

		//************************************************************************
		//电机指令缓冲区设置需要运动的轨迹初始化（X、Y轴未运动）
		/*(2)*/
		rtn = GT_Buffer();
		if(rtn!=0)
		{
			printf("电机缓冲区运动指令设置失败！");
			return false;
		}

		isMyCyc = TRUE;
	}

	//*******************************************
	//检测电机状态
	/*(3)*/
	rtn = GT_Check_status();
	if(rtn!=0)
	{
		printf("检测电机状态失败！");
		return false;
	}

	Sleep(3000);//原值6000


	//给的目的地参数必须使电机的位置运动到另一点，不能运动0(并不是参数为0)个脉冲
	//**************************************************************************************
	/*(4)*/
	rtn = GT_ADD_Buffer_continue(xSetPoint,ySetPoint,20.32);//默认速度
	if(rtn!=0)
	{
		printf("电机缓冲区指令执行失败！");
		return false;
	}
	else
	{
		//***************************************************************************************
		/*(5)*/
		rtn = GT_Check_status();
		if(rtn!=0)
		{
			printf("检测电机状态失败！");
			return false;
		}	

		Sleep(3000);

		printf("到达测量原点！");
	
	}
	return true;
}