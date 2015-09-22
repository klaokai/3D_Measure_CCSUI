#ifndef CCS_CLEAN_H
#define CCS_CLEAN_H
#include "afxmt.h"
#include "windows.h"
#include "ccs_functions.h"
#include "ccs.h"
#include "cAcqEasyType.h"
bool ccs_clean(MCHR_ID *SensorID)
{
	
	printf ("Close Sensor\n");
	CloseSensor(*SensorID);
	//ReleaseEvents(&evAcquisition);

	printf ("Release Chr Lib\n");
	ReleaseChrLib();
	return true;
}

#endif