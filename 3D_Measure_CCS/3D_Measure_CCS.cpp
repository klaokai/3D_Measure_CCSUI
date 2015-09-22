// 3D_Measure_CCS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "cAcqEasy.h"
#include "ccs_initial.h"
#include "ccs_clean.h"
#include "ccs_work.h"
#include <time.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//Acquisition parameters
	sAcqEasyParam acqEasyParam;
	//Sensor ID传感器ID
	MCHR_ID SensorID = NULL;
	float vel = 0;                   //X扫描速度起始值，单位mm/s
	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	int width = 4000;                    //X扫描步数
	int height =400;                           //Y扫描步数
	int IntensityStart =80;                    //LED光强起始值
	int IntensityStep = 0;                      //LED光强增量
	int IntensityCount = 1;//(100-IntensityStart)/IntensityStep+1;                     //LED变光强次数
	int FrequencyStart =600;                   //频率起始值
	int FrequencyStep = 0;                      //频率增量
	int FrequencyCount =1;//(2000-FrequencyStart)/FrequencyStep+1;                     //变频率次数
	int DpiStart = 4000;                      //分辨率
	int DpiStep = 0;								//分辨率增量
	int DpiCount = 1;							//分辨率增加次数
	char filename[25] = "006_4";	        //材料编号+次数 
	int average = 1;                            //averaging参数
	int holdlast = 0;                            //holdlast参数
	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	time_t rawtime;								//原始时间信息
	struct tm* timeinfo;						//事件信息
	char Time[50];                              //系统日期
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(Time,50,"%Y.%m.%d",timeinfo);	
	clock_t StartTime=0,FinishTime=0;
	double duration = 0;
	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	StartTime = clock();
	int x = 0;                                  //X方向的脉冲数
	int y = 0;                                  //Y方向的脉冲数
	int step = 0;                               //Y的步长
	char filePath_z[100];
	//data目录下文件名+年月日的dat数据文件
	sprintf_s(filePath_z,"%s%s%s%s%s",".\\data\\",filename,"_",Time,".dat");
	//初始化文件
	FILE *File_z;
	if (fopen_s(&File_z,filePath_z,"wb"))
	{
		printf("打开文件出错！");
		return false;
	}
	//开始电机的处理
	if(!ges_initial())
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
	if(!ges_messure_zero(100,50))    //测量原点（100,50）mm
		printf("\n设置测试原点失败！\n");
	else
		printf("\n设置测试原点成功！\n");
	//分别以不同分辨率、不同频率、不同LED光强进行测量
	for (int k=0; k < DpiCount; k++)
	{
		for (int i=0; i<FrequencyCount; i++)
		{
			for (int j=0; j<IntensityCount; j++)
			{
				//做了相当多的换算保证文件的正常
				vel = 25.4/DpiValue*FrequencyValue;
				float test_t = (int)(vel*2000);
				vel = test_t/2000;//脉冲为整数
				fwrite(&vel,sizeof(float),1,File_z);
				x =average*(int)(vel*(float(width)/FrequencyValue)*2000+1000);//12.5/3.2*2000;
				step = average*(int)(vel*2/FrequencyValue*1000);                          //Y扫描步长

				if(!ccs_initial(&SensorID,&acqEasyParam,IntensityValue,FrequencyValue,width,average,holdlast))
					printf("传感器初始化失败！\n");
				else
					printf("传感器初始化成功！\n");
				ccs_work(SensorID,&acqEasyParam,File_z,x,y,vel*2,step,height,width,countSum,&nowCount);
				if(!ccs_clean(&SensorID))
					printf("停止传感器失败！\n");
				else
					printf("停止传感器成功！\n");
				IntensityValue += IntensityStep;

				short rtn =0 ; //电机操作后的返回值，0表示无错误
				printf("回测试原点...");
				if(GT_ADD_Buffer_continue(0,0,25))
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
	if(!ges_stop())
		printf("停止电机失败！\n");
	else
		printf("停止电机成功！\n");
	fclose(File_z);
	printf("扫描结束！");
	FinishTime = clock();
	duration = (double)(FinishTime-StartTime)/1000;
	printf("用时%f s",duration);
	getchar();
	return 0;
}

