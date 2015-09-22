#include "StdAfx.h"
#include "CCSControl.h"


CCSControl::CCSControl(void)
{
}


CCSControl::~CCSControl(void)
{
}

bool CCSControl::ccs_initial(MCHR_ID *SensorID,sAcqEasyParam* acqEasyParam, 
	int intensity,int frequency,int width,int average,int holdlast)
{
	if (InitChrLib())
	{
		//open sensor
		printf ("正在打开传感器(请等待)\n");
		if (OpenSensor(SensorID, MCHR_CCS_PRIMA))
		{
			printf ("设定参数中\n");
			if (SetParameter(*SensorID,intensity,frequency,average,holdlast))
			{
				//set acquisition parameters
				ZeroMemory(acqEasyParam, sizeof(sAcqEasyParam));
				// Set number of points to acquire (should be > 0)
				//(*acqEasyParam).NumberOfPoints = width;
				// Set buffer size (should be > 0)
				(*acqEasyParam).BufferLength = width;
				// Set Number of acquisition buffers per data (should be > 1)
				(*acqEasyParam).NumberOfBuffers = NUMBER_OF_BUFFERS;
				//set altitude and counter buffering enabled
				(*acqEasyParam).EnableBufferAltitude.Altitude = true;	
				(*acqEasyParam).EnableBufferAltitude.Counter = true;
				(*acqEasyParam).EnableBufferAltitude.Intensity = true;
				//set timeout acquisition : should be at least = ((BufferLength * averaging) / rate) + 100
				(*acqEasyParam).TimeoutAcquisition = 40000;
				//set name of acquisition function used
				(*acqEasyParam).typeAcquisition = eMCHR_GetAltitudeMeasurement;
				//set controller type
				(*acqEasyParam).SensorType = MCHR_CCS_PRIMA;
				//event type (here end of measurements)
				(*acqEasyParam).TypeEvent = EV_END_BUFFER;
				//Set frenquency
				(*acqEasyParam).Frequency = frequency;	
				//trigger settings
				(*acqEasyParam).Trigger.Enable = true;
				(*acqEasyParam).Trigger.Type = MCHR_TYPE_TRE;
				(*acqEasyParam).NumberPointsTRE = width;
			}

		}
		else
		{
			printf("打开传感器失败！\n");
			return false;
		}
	}
	else
	{
		printf("初始化ChrLib失败！\n");
		return false;
	}
	return true;
}

bool CCSControl::ccs_clean(MCHR_ID *SensorID)
{
	printf ("Close Sensor\n");
	CloseSensor(*SensorID);
	//ReleaseEvents(&evAcquisition);

	printf ("Release Chr Lib\n");
	ReleaseChrLib();
	return true;
}


