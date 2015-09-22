#pragma once

#include "cAcqEasy.h"
#define NUMBER_OF_BUFFERS	2
class CCSWork
{
public:
	CCSWork(void);
	~CCSWork(void);

	bool InitChrLib();
	bool ReleaseChrLib();
	bool OpenSensor(MCHR_ID *pSensorID, enChrType SensorType);
	bool StartAcquisition(cAcqEasy *pAcquisitionEasy, sAcqEasyParam acqEasyParameters);
	bool SetParameter(MCHR_ID SensorID,int intensity,int frequency,int average,int holdlast);
	bool CloseSensor(MCHR_ID SensorID);
	bool CreateEvents(cAcqEasy *pAcquisitionEasy, HANDLE* pAcquisitionEvent);
	void ReleaseEvents(HANDLE *pAcquisitionEvent);
	short Process(cAcqEasy *pAcquisitionEasy, HANDLE AcquisitionEvent, 
		sAcqEasyParam acqEasyParameters, 
		float* pAltitude, float*pIntensity, int* pDataCount);
};

