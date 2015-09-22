#include "StdAfx.h"
#include "GES_CCS_Ctrl.h"

#include "DataSave.h"

GES_CCS_Ctrl::GES_CCS_Ctrl(void)
{
	ges=GESControl();
	ccs=CCSControl();
	short rtn =0 ; //电机操作后的返回值，0表示无错误

	//Acquisition user buffer
	float *pAltitude = NULL;
	float *pIntensity = NULL;
	int DataCount = 0;
	short resultProcess = 0;

	//Acquisition parameters
	//sAcqEasyParam acqEasyParam;
	//Sensor ID传感器ID
	MCHR_ID SensorID = NULL;
	float vel = 0;                   //X扫描速度起始值，单位mm/s
	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	width = 4000;                    //X扫描步数
	height =400;                           //Y扫描步数
	IntensityStart =80;                    //LED光强起始值
	IntensityStep = 0;                      //LED光强增量
	IntensityCount = 1;//(100-IntensityStart)/IntensityStep+1;                     //LED变光强次数
	FrequencyStart =600;                   //频率起始值
	FrequencyStep = 0;                      //频率增量
	FrequencyCount =1;//(2000-FrequencyStart)/FrequencyStep+1;                     //变频率次数
	DpiStart = 4000;                              //分辨率
	DpiStep = 0;							//分辨率增量
	DpiCount = 1;							//分辨率增加次数
	strcpy(filename, "006_4");	            //材料编号+次数 
	average = 1;                               //averaging参数
	holdlast = 0;                            //holdlast参数
}


GES_CCS_Ctrl::~GES_CCS_Ctrl(void)
{
}


bool GES_CCS_Ctrl::ges_ccs_control(sAcqEasyParam* acqEasyParam,MCHR_ID SensorID,
	HANDLE evAcquisition,cAcqEasy* pAcqEasy,
	FILE *File_z,int x,int y,int step,float vel,int height,int width,int countSum,int* nowCount)
{

	rtn = ges.GT_System_Initinal();						//平台初始化
	if(rtn!=0)
	{
		printf("电机初始化失败！");
		return false;
	}

	rtn = ges.AxisInitial(2,15);							//控制轴初始化函数						
	if(rtn!=0)
	{
		printf("电机控制轴初始化失败！");

		return false;

	}															   
	rtn = ges.MotionInitial();							//轴运动参数初始化
	if(rtn!=0)
	{
		printf("电机控制轴运动参数初始化失败！");
		return false;
	}

	//电机指令缓冲区设置需要运动的轨迹初始化（X、Y轴未运动）
	/*(2)*/
	rtn = ges.GT_Buffer();

	if(rtn!=0)
	{

		printf("电机缓冲区运动指令设置失败！");
		return false;
	}

	for(int i=1;i<=height;i++)
	{
		(*nowCount)++;
		printf("已完成 %.2f %% !!!\n",((*nowCount)*1.0/countSum*100));
		rtn = ges.GT_Check_status();
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
		ges.GT_ADD_Buffer_trigger(x,y,vel);//速度12.5mm/s
		Sleep(10);
		GT_ExOpt(0x0000);
		//控制CCS
		resultProcess = ccs.Process(pAcqEasy, evAcquisition, *acqEasyParam,
			pAltitude, pIntensity,&DataCount); 
		if (resultProcess == STATUS_NO_ERROR)
		{
			//保存数据
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
			rtn = ges.GT_Check_status();
			if(rtn!=0)
			{
				printf("检测电机状态失败！");
				return false;
			}	
		}
		rtn = ges.GT_ADD_Buffer_continue(0,y,100);
		if(rtn!=0)
		{
			printf("电机缓冲区指令执行失败！");
			return false;
		}
		else
		{
			rtn = ges.GT_Check_status();
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

bool GES_CCS_Ctrl::ccs_work(MCHR_ID SensorID,sAcqEasyParam* acqEasyParam, FILE*File_z,int x,int y,int vel,int step,int height,int width,int countSum,int* nowCount)
{
	//User Event
	HANDLE evAcquisition = NULL;
	//cAcqEasy Class
	cAcqEasy* pAcqEasy = NULL;
	//create cAcqEasy class
	pAcqEasy = new cAcqEasy(SensorID);
	if (ccs.CreateEvents(pAcqEasy, &evAcquisition))
	{				
		//start acquisition
		printf ("Start Acquisition\n");
		if (ccs.StartAcquisition(pAcqEasy, *acqEasyParam))
		{
			ges_ccs_control(acqEasyParam,SensorID,evAcquisition,pAcqEasy,File_z,x,y,step,(float)vel,height,width,countSum,nowCount);
			//GT_ExOpt(0x0000);       //外部触发Exo6置0
			//Sleep(1000);
			//printf ("Allocate user buffer memory\n");
			//pAltitude = new float[buffer_width];
			//pCounter = new float[buffer_width];
			//pIntensity = new float[buffer_width];
			////read acquisition result
			//GT_ADD_Buffer_trigger(test_x,test_y,test_v);//速度12.5mm/s
			//resultProcess = Process(pAcqEasy, evAcquisition, *acqEasyParam, pAltitude, pCounter, pIntensity,&DataCount); 
			//if (resultProcess == STATUS_NO_ERROR)
			//{
			//	if (!DataSave(File_z,pAltitude,1,buffer_width))
			//		printf("DataSave Error!");
			//	if (!DataSave(File_z,pIntensity,1,buffer_width))
			//		printf("DataSave Error!");
			//}	
			//else
			//{
			//	if (resultProcess != STATUS_TIMEOUT_ERROR)
			//	{
			//		printf("Main : Process() : Error 0x%X\n", resultProcess);
			//	}
			//}
			//delete[] pAltitude;
			//delete[] pCounter;
			//delete[] pIntensity;
		}
		printf ("Stop Acquisition\n");
		pAcqEasy->StopAcquisition();	
		ccs.ReleaseEvents(&evAcquisition);
	}
	delete pAcqEasy;
	return true;
}

void GES_CCS_Ctrl::WorkingProcess(void)
{
	time_t rawtime;
	struct tm* timeinfo;
	char Time[50];                              //系统日期
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(Time,50,"%Y.%m.%d",timeinfo);	
	clock_t StartTime=0,FinishTime=0;
	double duration = 0;

	StartTime = clock();
	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	int x = 0;                                  //X方向的脉冲数
	int y = 0;                                  //Y方向的脉冲数
	int step = 0;                               //Y的步长
	char filePath_z[100];
	sprintf_s(filePath_z,"%s%s%s%s%s",".\\data\\",filename,"_",Time,".dat");
	FILE *File_z;
	if (fopen_s(&File_z,filePath_z,"wb"))
	{
		printf("打开文件出错！");
		return;
	}
	if(!ges.ges_initial())
		printf("电机初始化失败！\n");
	else
		printf("电机初始化成功！\n");
	int FrequencyValue = FrequencyStart;
	int IntensityValue = IntensityStart;
	int DpiValue = DpiStart;
	fwrite(&width,sizeof(int),1,File_z);
	fwrite(&DpiStart,sizeof(int),1,File_z);
	fwrite(&DpiStep,sizeof(int),1,File_z);
	fwrite(&DpiCount,sizeof(int),1,File_z);
	fwrite(&height,sizeof(int),1,File_z);
	fwrite(&IntensityStart,sizeof(int),1,File_z);
	fwrite(&IntensityStep,sizeof(int),1,File_z);
	fwrite(&IntensityCount,sizeof(int),1,File_z);
	fwrite(&FrequencyStart,sizeof(int),1,File_z);
	fwrite(&FrequencyStep,sizeof(int),1,File_z);
	fwrite(&FrequencyCount,sizeof(int),1,File_z);
	fwrite(&average,sizeof(int),1,File_z);
	//float resolution = 25.4 / (test_v / FrequencyStart * average);
	//fwrite(&resolution,sizeof(int),1,File_z);
	int countSum = DpiCount * height * FrequencyCount * IntensityCount; //拍摄的总行数
	int nowCount = 0;                                                     //当前已拍摄的行数
	printf("正在测试原点...");
	if(!ges.ges_messure_zero(100,50))    //测量原点（100,50）mm
		printf("\n设置测试原点失败！\n");
	else
		printf("\n设置测试原点成功！\n");
	for (int k=0; k < DpiCount; k++)
	{
		for (int i=0; i<FrequencyCount; i++)
		{
			for (int j=0; j<IntensityCount; j++)
			{
				vel = (int)(25.4/DpiValue*FrequencyValue);
				float test_t = (float)(vel*2000);
				vel = test_t/2000;//脉冲为整数
				fwrite(&vel,sizeof(float),1,File_z);
				x =average*(int)(vel*(float(width)/FrequencyValue)*2000+1000);//12.5/3.2*2000;
				step = average*(int)(vel*2/FrequencyValue*1000);                          //Y扫描步长

				if(!ccs.ccs_initial(&SensorID,&acqEasyParam,IntensityValue,FrequencyValue,width,average,holdlast))
					printf("传感器初始化失败！\n");
				else
					printf("传感器初始化成功！\n");
				ccs_work(SensorID,&acqEasyParam,File_z,x,y,(int)vel*2,step,height,width,countSum,&nowCount);
				if(!ccs.ccs_clean(&SensorID))
					printf("停止传感器失败！\n");
				else
					printf("停止传感器成功！\n");
				IntensityValue += IntensityStep;

				short rtn =0 ; //电机操作后的返回值，0表示无错误
				printf("回测试原点...");
				if(ges.GT_ADD_Buffer_continue(0,0,25))
					printf("回原点失败！\n");
				else 
					printf("回原点成功!\n");

			}
			FrequencyValue += FrequencyStep;
			IntensityValue = IntensityStart;
		}
		FrequencyValue = FrequencyStart;
		IntensityValue = IntensityStart;
		DpiValue += DpiStep;
	}
	if(!ges.ges_stop())
		printf("停止电机失败！\n");
	else
		printf("停止电机成功！\n");
	fclose(File_z);
	printf("扫描结束！");
	FinishTime = clock();
	duration = (double)(FinishTime-StartTime)/1000;
	printf("用时%f s",duration);
	getchar();
}
