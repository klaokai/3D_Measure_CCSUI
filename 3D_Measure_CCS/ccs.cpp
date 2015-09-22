// Example 0.cpp? définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "conio.h"
#include "cAcqEasy.h"
#include "ccs.h"
#include "DataSave.h"
#include "ccs_functions.h"

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif



/*
Example 0 Version 1.1 :
	This example shows how to launche an acquisition of a finite number of data points (NB_POINTS) for CCS PRIMA.
	This example does not wait for any trigger.
	It uses a library (cAcqEasy) that facilitates programming of the acquisition.
	For more details about this library read docummentation cAcqEasy.doc
*/

//using namespace std;






int ccs()
{
	//Acquisition parameters
	sAcqEasyParam acqEasyParam;
	//Sensor ID
	MCHR_ID SensorID;
	//User Event
	HANDLE evAcquisition;
	//cAcqEasy Class
	cAcqEasy *pAcqEasy;

	//Acquisition user buffer
	float *pAltitude = NULL;
	float *pCounter = NULL;


	int idx = 0, DataCount = 0;
	short resultProcess = 0;

	
	pAcqEasy = NULL;
	SensorID = 0;
	evAcquisition = NULL;
	pAltitude = NULL;
	pCounter = NULL;

	//Application Code
	printf ("This example shows how to launche an acquisition of a finite number of data points (NB_POINTS) for CCS PRIMA.(Version 1.1).\n");
	printf ("This example does not wait for any trigger.\n");

	printf ("Init Chr Lib\n");
	if (InitChrLib())
	{
		//open sensor
		printf ("Open Sensor (please wait)\n");
		if (OpenSensor(&SensorID, MCHR_CCS_PRIMA))
		{
			//create cAcqEasy class
			pAcqEasy = new cAcqEasy(SensorID);
			if (CreateEvents(pAcqEasy, &evAcquisition))
			{
				//Set hardware parameters if you need
				printf ("Set Parameters\n");
				if (SetParameter(SensorID))
				{
					//set acquisition parameters
					ZeroMemory(&acqEasyParam, sizeof(sAcqEasyParam));
					// Set number of points to acquire (should be > 0)
					acqEasyParam.NumberOfPoints = NB_POINTS;
					// Set buffer size (should be > 0)
					acqEasyParam.BufferLength = NB_POINTS;
					// Set Number of acquisition buffers per data (should be > 1)
					acqEasyParam.NumberOfBuffers = NUMBER_OF_BUFFERS;
					//set altitude and counter buffering enabled
					acqEasyParam.EnableBufferAltitude.Altitude = true;	
					acqEasyParam.EnableBufferAltitude.Counter = true;
					//set timeout acquisition : should be at least = ((BufferLength * averaging) / rate) + 100
					acqEasyParam.TimeoutAcquisition = 20000;
					//set name of acquisition function used
					acqEasyParam.typeAcquisition = eMCHR_GetAltitudeMeasurement;
					//set controller type
					acqEasyParam.SensorType = MCHR_CCS_PRIMA;
					//event type (here end of measurements)
					acqEasyParam.TypeEvent = EV_END_MEASUREMENTS;
					//Set frenquency
					acqEasyParam.Frequency = 1000;				
					//start acquisition
					printf ("Start Acquisition\n");
					if (StartAcquisition(pAcqEasy, acqEasyParam))
					{
						printf ("Allocate user buffer memory\n");
						pAltitude = new float[NB_POINTS];
						pCounter = new float[NB_POINTS];
						//read acquisition result
						resultProcess = Process(pAcqEasy, evAcquisition, acqEasyParam, pAltitude, pCounter, &DataCount); 
						if (resultProcess == STATUS_NO_ERROR)
						{
							if (!DataSave(pAltitude,1,NB_POINTS))
								printf("DataSave Error!");
							//display acquisition result
							for (idx = 0; idx < DataCount; idx++)
							{
								printf ("[%03d]Altitude  = %0.2f (Counter : %.0f)\n", idx, (float)pAltitude[idx], pCounter[idx]);
							}
							printf ("\n");
						}	
						else
						{
							if (resultProcess != STATUS_TIMEOUT_ERROR)
							{
								printf("Main : Process() : Error 0x%X\n", resultProcess);
							}
						}
					}
					printf ("Stop Acquisition\n");
					pAcqEasy->StopAcquisition();
					printf ("Close Sensor\n");
					CloseSensor(SensorID);
					ReleaseEvents(&evAcquisition);
				}
			}
		}
		printf ("Release Chr Lib\n");
		ReleaseChrLib();
	}
	printf ("Free user buffer memory\n");
	if (pAcqEasy != NULL)
	{
		delete pAcqEasy;
		pAcqEasy = NULL;
	}
	if (pAltitude != NULL)
	{
		delete[] pAltitude;
		pAltitude = NULL;
	}
	if (pCounter != NULL)
	{
		delete[] pCounter;
		pCounter = NULL;
	}
	printf ("Acquisition is over, please press any key to exit\n");	
	_getch();
	
	return 0;
}


