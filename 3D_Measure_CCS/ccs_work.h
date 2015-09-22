#ifndef CCS_WORK_H
#define CCS_WORK_H
#include "afxmt.h"
#include "windows.h"
#include "ccs_functions.h"
#include "cAcqEasyType.h"
#include "ges_work.h"
#include "ges_ccs_control.h"
bool ccs_work(MCHR_ID SensorID,sAcqEasyParam* acqEasyParam,FILE*File_z,int x,int y,int vel,int step,int height,int width,int countSum,int* nowCount)
{
	//User Event
	HANDLE evAcquisition = NULL;
	//cAcqEasy Class
	cAcqEasy* pAcqEasy = NULL;
	//create cAcqEasy class
	pAcqEasy = new cAcqEasy(SensorID);
	if (CreateEvents(pAcqEasy, &evAcquisition))
	{				
		//start acquisition
		printf ("Start Acquisition\n");
		if (StartAcquisition(pAcqEasy, *acqEasyParam))
		{
			ges_ccs_control(acqEasyParam,SensorID,evAcquisition,pAcqEasy,File_z,x,y,step,vel,height,width,countSum,nowCount);
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
		ReleaseEvents(&evAcquisition);
	}
	delete pAcqEasy;
	return true;
}
#endif