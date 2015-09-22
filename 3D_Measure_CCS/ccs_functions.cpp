#include "ccs_functions.h"
#include "stdafx.h"
#include "conio.h"
#include "cAcqEasy.h"
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
//初始化库
bool InitChrLib()
{
	char szVersion[MAX_CHAR];

	//DLL initialization
	if (!MCHR_Init())
	{
		printf("Error : InitChrLib() : DLL Initialization failed.\n");
		return(false);
	}
	//Reading the version number of the DLL
	memset(szVersion, 0, MAX_CHAR);
	if (MCHR_GetVersion (szVersion, sizeof(szVersion)) != MCHR_ERROR_NONE)
	{
		printf("Error : InitChrLib() : MCHR_GetVersion\n");  
		return(false);
	}
	printf("DLL CHR V%s\n", szVersion);
	return(true);
}
//---------------------------------------------------------------------------------
//释放库
bool ReleaseChrLib()
{
	if (MCHR_Release() != MCHR_ERROR_NONE)
	{
		printf("Error : ReleaseChrLib() : MCHR_Release\n");  
		return(false);
	}
	return true;
}
//---------------------------------------------------------------------------------
//打开传感器
bool OpenSensor(MCHR_ID *pSensorID, enChrType SensorType)
{
	char szSensorName[256];
	char *UsbCCSDeviceList[MCHR_MAX_SENSOR];
	CString NewText;
	short deviceNumber = 0, idx = 0;
	bool result = true;

	if (pSensorID == NULL)
	{
		printf("Error : OpenSensor() : Bad parameter (pSensorID)\n");  
		return(false);
	}
	memset(szSensorName, 0, sizeof(szSensorName));
	//allocate sensor list
	for (idx = 0; idx < MCHR_MAX_SENSOR; idx++)
	{
		UsbCCSDeviceList[idx] = new char[256];
		memset(UsbCCSDeviceList[idx], 0, 256);
	}
	//get usb device list
	if ((MCHR_GetUsbDeviceList(UsbCCSDeviceList, &deviceNumber) != MCHR_ERROR) && (deviceNumber > 0))
	{
		//open the first sensor found
		*pSensorID = MCHR_OpenUsbChr (UsbCCSDeviceList[0], SensorType, UsbCCSDeviceList[0], NULL, NULL);	
		if (*pSensorID != 0)
		{
			MCHR_GetSensorName(*pSensorID, szSensorName);
			printf("%s Sensor Open: SensorID = %d\n", szSensorName, *pSensorID);
		}
		else
		{
			printf("Error : OpenSensor() : Sensor Open failed : 0x%X\n", MCHR_GetLastError(NULL));
			result = false;
		}
	}
	else
	{
		printf("Error : OpenSensor() : Sensor usb device list failed or no sensor present : 0x%X\n", MCHR_GetLastError(NULL));
		result = false;
	}
	//release sensor list
	for (idx = 0; idx < MCHR_MAX_SENSOR; idx++)
	{
		if (UsbCCSDeviceList[idx] != NULL)
		{
			delete[] UsbCCSDeviceList[idx];
			UsbCCSDeviceList[idx] = NULL;
		}
	}
	return (result);
}
//-----------------------------------------------------------------------------------------
//创建事件
bool CreateEvents(cAcqEasy *pAcquisitionEasy, HANDLE* pAcquisitionEvent)
{	
	if (pAcquisitionEasy == NULL)
	{
		printf("Error : CreateEvents() : Bad parameter (pAcquisitionEasy)\n");  
		return(false);
	}
	
	*pAcquisitionEvent = CreateEvent(NULL,FALSE,FALSE,NULL);
	if (*pAcquisitionEvent != NULL)
	{
		if (pAcquisitionEasy != NULL)
		{
			pAcquisitionEasy->SetAcqEvent(*pAcquisitionEvent);
			return(true);
		}
	}
	return (false);
}
//-----------------------------------------------------------------------------------------
//释放事件
void ReleaseEvents(HANDLE *pAcquisitionEvent)
{
	if (*pAcquisitionEvent != NULL)
	{
		CloseHandle(*pAcquisitionEvent);
		*pAcquisitionEvent = NULL;
	}	
}

//---------------------------------------------------------------------------------
//开始获取
bool StartAcquisition(cAcqEasy *pAcquisitionEasy, sAcqEasyParam acqEasyParameters)
{
	if (pAcquisitionEasy == NULL)
	{
		printf("Error : StartAcquisition() : Bad parameter (pAcquisitionEasy)\n");  
		return(false);
	}
	if (!pAcquisitionEasy->StartAcquisition(acqEasyParameters))
	{
		printf("Error : StartAcquisition() : Error code : 0x%X\n", MCHR_GetLastError(pAcquisitionEasy->GetSensorId()));		
		return (false);
	}
	return(true);
}
//---------------------------------------------------------------------------------
//关闭传感器
bool CloseSensor(MCHR_ID SensorID)
{
	if (SensorID > 0)
	{
		if (MCHR_CloseChr(SensorID) != MCHR_ERROR_NONE)
		{
			printf("Error : CloseSensor() : Error code : 0x%X\n", MCHR_GetLastError(SensorID));		
			return (false);
		}	
	}
	else
	{
		printf("Error : CloseSensor() : Incorrect Id : %d\n", SensorID);		
		return (false);
	}	
	return (true);
}
//---------------------------------------------------------------------------------
//设置参数
bool SetParameter(MCHR_ID SensorID,int intensity,int frequency,int average,int holdlast)
{
	////set 1000hz acquisition frequency
	//if(MCHR_SetScanRate (SensorID, MCHR_SCAN_RATE_CCS_PRIMA_400HZ) == MCHR_ERROR)
	//{
	//	printf("Error : SetParameter() : MCHR_SetScanRate, Error code : %X\n", MCHR_GetLastError(SensorID));
	//	return (false);
	//}
	//Set the led intensity
	if(MCHR_SetLed (SensorID, intensity) == MCHR_ERROR)
	{
		printf("Error : SetParameter() : MCHR_SetLed, Error code : %X\n", MCHR_GetLastError(SensorID));
		return (false);
	}
	if(MCHR_SetFreeFrequency (SensorID, frequency) == MCHR_ERROR)
	{
		printf("Error : SetParameter() : MCHR_SetFreeFrequency, Error code : %X\n", MCHR_GetLastError(SensorID));
		return (false);
	}
	//set averaging for acquisition
	if(MCHR_SetAveraging (SensorID,average) == MCHR_ERROR)
	{
		printf("Error : SetParameter() : MCHR_SetAveraging, Error code : %X\n", MCHR_GetLastError(SensorID));
		return (false);
	}
	//set holdlast for acquisition
	if(MCHR_SetHoldLastValue (SensorID,holdlast) == MCHR_ERROR)
	{
		printf("Error : SetParameter() : MCHR_SetHoldLastValue, Error code : %X\n", MCHR_GetLastError(SensorID));
		return (false);
	}
	return(true);
}
//---------------------------------------------------------------------------------
//运行
short Process(cAcqEasy *pAcquisitionEasy, HANDLE AcquisitionEvent, sAcqEasyParam acqEasyParameters, float* pAltitude, float* pIntensity,int* pDataCount)
{
	if (pAcquisitionEasy == NULL)
	{
		printf("Error : Process() : Bad parameter (pAcquisitionEasy)\n");  
		return(false);
	}
	if (AcquisitionEvent == NULL)
	{
		printf("Error : Process() : Bad parameter (AcquisitionEvent)\n");  
		return(false);
	}
	if (WaitForSingleObject(AcquisitionEvent, acqEasyParameters.TimeoutAcquisition) == WAIT_OBJECT_0)
	{
		if (!pAcquisitionEasy->GetAltitudeAcquisitionData(pAltitude, pIntensity, NULL, NULL, NULL, pDataCount))
		{
			printf("Error : Process() GetAltitudeAcquisitionData : Error\n");
			return (pAcquisitionEasy->GetStatusAcquisition(NULL));
		}
	}
	else
	{
		printf("Error : Process() GetAltitudeAcquisitionData : Timeout\n");
		return (STATUS_TIMEOUT_ERROR);
	}
	return(STATUS_NO_ERROR);
}
//---------------------------------------------------------------------------------

