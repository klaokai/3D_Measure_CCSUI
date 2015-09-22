#pragma once

#include "GESControl.h"
#include "CCSControl.h"

class GES_CCS_Ctrl
{
private:
	//Acquisition parameters
	sAcqEasyParam acqEasyParam;
	//Sensor ID传感器ID
	MCHR_ID SensorID ;
	float vel ;                   //X扫描速度起始值，单位mm/s
	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	int width;                    //X扫描步数
	int height;                           //Y扫描步数
	int IntensityStart ;                    //LED光强起始值
	int IntensityStep ;                      //LED光强增量
	int IntensityCount ;//(100-IntensityStart)/IntensityStep+1;                     //LED变光强次数
	int FrequencyStart ;                   //频率起始值
	int FrequencyStep ;                      //频率增量
	int FrequencyCount ;//(2000-FrequencyStart)/FrequencyStep+1;                     //变频率次数
	int DpiStart ;                              //分辨率
	int DpiStep ;							//分辨率增量
	int DpiCount ;							//分辨率增加次数
	char filename[25] ;	            //材料编号+次数 
	int average ;                               //averaging参数
	int holdlast ;                            //holdlast参数
	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

	GESControl ges;
	CCSControl ccs;

	short rtn; //电机操作后的返回值，0表示无错误

	//Acquisition user buffer
	float *pAltitude;
	float *pIntensity;
	int DataCount;
	short resultProcess;
public:
	GES_CCS_Ctrl(void);
	~GES_CCS_Ctrl(void);
	
	bool ges_ccs_control(sAcqEasyParam* acqEasyParam,MCHR_ID SensorID,
		HANDLE evAcquisition,cAcqEasy* pAcqEasy,
		FILE *File_z,int x,int y,int step,float vel,int height,int width,int countSum,int* nowCount);

	//工作
	bool ccs_work(MCHR_ID SensorID,sAcqEasyParam* acqEasyParam,
		FILE*File_z,int x,int y,int vel,int step,int height,int width,int countSum,int* nowCount);

	void WorkingProcess(void);

};

