#include "StdAfx.h"
#include <stdio.h>
#include "cAcqEasy.h"


//--------------------------------------------------------------------
cAcqEasy::cAcqEasy(MCHR_ID SensorID)
{
	DWORD dwThreadId = 0;
	int nIndex = 0, idx = 0, jdx = 0;

	m_current_index_of_buffer_to_read = -1;
	m_number_of_buffer_to_read = 0;
	m_IsCreateAcqBuffer = false;

	//init acquisition buffers
	for (idx = 0; idx < ID_BUFFER_MAX; idx++)
	{
		m_ppAcqBuffer[idx] = NULL;
	}
	//init encoder buffers
	for (idx = 0; idx < ID_BUFFER_ENCODER_MAX; idx++)
	{
		m_ppEncoderBuffer[idx] = NULL;
	}
	//init auto adaptative buffers
	m_ppAutoAdaptativeBuffer = NULL;
	
	m_end_acq_event = NULL;
	m_status_event = NULL;
	m_chr_id = SensorID;
	m_IsDataAcquisitionStarting = false;
	m_IsSpectrumAcquisitionStarting = false;
	m_status_acquisition = STATUS_NO_ERROR;
	//create all events for process 
	for (nIndex = 0; nIndex < EVENT_ACQ_EASY_NUMBER; nIndex++)
	{
		m_OnEvent[nIndex] = CreateEvent(NULL, FALSE, FALSE, NULL);
	}	
	//create all events for acquisition process 
	for (nIndex = 0; nIndex < EVENT_ACQUISITION_NUMBER; nIndex++)
	{
		if (nIndex == EVENT_END_ACQUIRE)
		{
			m_OnEventAcquisition[nIndex] = CreateEvent(NULL, TRUE, FALSE, NULL);
		}
		else
		{
			m_OnEventAcquisition[nIndex] = CreateEvent(NULL, FALSE, FALSE, NULL);
		}
	}	
	ZeroMemory(&m_acqParam, sizeof(MCHR_tyAcqParam));
	//open process thread
	hThread = ::CreateThread(0, 0, ProcessThread, LPVOID(this), 0, &dwThreadId);
}
//--------------------------------------------------------------------
cAcqEasy::~cAcqEasy()
{
	int nIndex = 0;

	//close process thread
	if (hThread != NULL)
	{
		SetEvent(m_OnEvent[EVENT_ACQ_EASY_KILL_THREAD]);
		if (WaitForSingleObject(m_OnEvent[EVENT_ACQ_EASY_KILL_THREAD_DO], 500) != WAIT_OBJECT_0)
		{
			TerminateThread(hThread, 0);
		}
		CloseHandle(hThread); 
		hThread = NULL;
	}
	//release process events
	for (nIndex = 0; nIndex < EVENT_ACQ_EASY_NUMBER; nIndex++)
	{
		if (m_OnEvent[nIndex]  != NULL)
		{
			CloseHandle(m_OnEvent[nIndex]);
			m_OnEvent[nIndex] = NULL;
		}
	}
	//release acquisition process events
	for (nIndex = 0; nIndex < EVENT_ACQUISITION_NUMBER; nIndex++)
	{
		if (m_OnEventAcquisition[nIndex]  != NULL)
		{
			CloseHandle(m_OnEventAcquisition[nIndex]);
			m_OnEventAcquisition[nIndex] = NULL;
		}
	}
	_ReleaseAcqBuffer(m_acqEasyParam.NumberOfBuffers);
}
//-------------------------------------------------------------------------------------------------
void cAcqEasy::_ReleaseAcqBuffer(int NumberOfBuffers)
{
	int nIndex = 0, idx = 0, jdx = 0;

	if (m_IsCreateAcqBuffer)
	{
		m_IsCreateAcqBuffer = false;
		//release acquisition buffers
		for (idx = 0; idx < ID_BUFFER_MAX; idx++)
		{
			if (m_ppAcqBuffer[idx] != NULL)
			{		
				for (jdx = 0; jdx < NumberOfBuffers; jdx++)
				{
					if (m_ppAcqBuffer[idx][jdx] != NULL)
					{
						delete[] m_ppAcqBuffer[idx][jdx];
						m_ppAcqBuffer[idx][jdx] = NULL;
					}
				}
				delete[] m_ppAcqBuffer[idx];
				m_ppAcqBuffer[idx] = NULL;
			}
		}
		//release encoders buffers
		for (idx = 0; idx < ID_BUFFER_ENCODER_MAX; idx++)
		{
			if (m_ppEncoderBuffer[idx] != NULL)
			{			
				for (jdx = 0; jdx < NumberOfBuffers; jdx++)
				{
					if (m_ppEncoderBuffer[idx][jdx] != NULL)
					{
						delete[] m_ppEncoderBuffer[idx][jdx];
						m_ppEncoderBuffer[idx][jdx] = NULL;
					}
				}
				delete[] m_ppEncoderBuffer[idx];
				m_ppEncoderBuffer[idx] = NULL;
			}
		}
		//init auto adaptative buffers
		if (m_ppAutoAdaptativeBuffer != NULL)
		{
			for (jdx = 0; jdx < NumberOfBuffers; jdx++)
			{
				if (m_ppAutoAdaptativeBuffer[jdx] != NULL)
				{
					delete[] m_ppAutoAdaptativeBuffer[jdx];
					m_ppAutoAdaptativeBuffer[jdx] = NULL;
				}
			}
			delete[] m_ppAutoAdaptativeBuffer;
			m_ppAutoAdaptativeBuffer = NULL;
		}
	}
}
//-------------------------------------------------------------------------------------------------
void cAcqEasy::_CreateAcqBuffer(int NumberOfBuffers, int BufferLength)
{
	int nIndex = 0, idx = 0, jdx = 0;
	PFLOAT pFloatBuffer = NULL;
	PDWORD pDwordBuffer = NULL;

	m_IsCreateAcqBuffer = true;
	//allocate acquisition buffers
	for (idx = 0; idx < ID_BUFFER_MAX; idx++)
	{
		m_ppAcqBuffer[idx] = new PFLOAT[NumberOfBuffers];		
		for (jdx = 0; jdx < NumberOfBuffers; jdx++)
		{
			m_ppAcqBuffer[idx][jdx] = new float[BufferLength];
		}
	}
	//allocate encoder buffers
	for (idx = 0; idx < ID_BUFFER_ENCODER_MAX; idx++)
	{
		m_ppEncoderBuffer[idx] = new PDWORD[NumberOfBuffers];
		for (jdx = 0; jdx < NumberOfBuffers; jdx++)
		{
			m_ppEncoderBuffer[idx][jdx] = new DWORD[BufferLength];
		}
	}
	//init auto adaptative buffers
	m_ppAutoAdaptativeBuffer = new PFLOAT[NumberOfBuffers];
	for (jdx = 0; jdx < NumberOfBuffers; jdx++)
	{
		m_ppAutoAdaptativeBuffer[jdx] = new float[BufferLength];
	}
}
//-------------------------------------------------------------------------------------------------
// Description : Thread Processing ----------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
DWORD WINAPI cAcqEasy::ProcessThread(LPVOID lpArg)
{
	cAcqEasy* pThis = reinterpret_cast<cAcqEasy*>(lpArg);	
	return pThis->ProcessThread();
}
#define DEFAULT_DELAY_THREAD		10
//-------------------------------------------------------------------------------------------------
DWORD cAcqEasy::ProcessThread(void)
{
	DWORD dwResult = 0;
	int TimeoutValue = m_acqEasyParam.TimeoutAcquisition;
	WORD TimeoutStep = 10;
	bool AcqReady = false;
	m_measure_index = -1;
	long _last_buffer_index = -1;
	int _previous_buffer_index = -1;
	m_number_of_buffer_to_read = 0;

	while(WaitForSingleObject(m_OnEvent[EVENT_ACQ_EASY_KILL_THREAD], m_IsDataAcquisitionStarting ? 0 : 10) != WAIT_OBJECT_0)
	{		
		if (m_IsDataAcquisitionStarting)  
		{	
			AcqReady = false;
			dwResult = WaitForMultipleObjects(EVENT_ACQUISITION_NUMBER, m_OnEventAcquisition, FALSE, TimeoutStep);
			switch(dwResult)
			{
				case WAIT_OBJECT_0 + EVENT_ACQUIRE_N_POINTS:
				case WAIT_OBJECT_0 + EVENT_END_BUFFER:
				case WAIT_OBJECT_0 + EVENT_END_MEASUREMENT:
				case WAIT_OBJECT_0 + EVENT_END_ACQUIRE:
					switch(m_acqEasyParam.TypeEvent)
					{
						case EV_ACQUIRE_N_POINTS: //EV_ACQUIRE_N_POINTS
							if (dwResult == WAIT_OBJECT_0 + EVENT_ACQUIRE_N_POINTS)
							{
								AcqReady = true;
							}
							else
							{
								m_status_acquisition = STATUS_EVENT_ERROR;
								if (m_status_event != NULL)
								{
									SetEvent(m_status_event);
#ifdef _VC6_
									sprintf(m_status_message, "ProcessThread:unexpected event (0x%X)\n", dwResult);
#else
									sprintf_s(m_status_message, "ProcessThread:unexpected event (0x%X)\n", dwResult);
#endif
								}
							}
							break;
						case EV_END_MEASUREMENTS: //EV_END_MEASUREMENTS
							if (dwResult == WAIT_OBJECT_0 + EVENT_END_MEASUREMENT)
							{
								criticalBuffer.Lock();
								if (MCHR_GetLastWrittenBuffer(m_chr_id, MCHR_END_MEASUREMENT, &_last_buffer_index, &m_measure_index) != MCHR_ERROR)
								{
									//fifo roll index----------------------------------------------------------------------
									if (_previous_buffer_index == -1)
									{										
										m_number_of_buffer_to_read = 1;
										m_current_index_of_buffer_to_read = _last_buffer_index;
									}
									else
									{
										if (_previous_buffer_index <= _last_buffer_index)
										{
											m_number_of_buffer_to_read += (_last_buffer_index - _previous_buffer_index);
										}
										else
										{
											m_number_of_buffer_to_read += ((m_acqEasyParam.NumberOfBuffers - _previous_buffer_index) + _last_buffer_index);
										}
									}
									_previous_buffer_index = _last_buffer_index;
									//---------------------------------------------------------------------------------------
									if (m_end_acq_event != NULL)
									{
										SetEvent(m_end_acq_event);
									}									
								}
								else
								{
									m_status_acquisition = STATUS_ACQ_ERROR;
									if (m_status_event != NULL)
									{
										SetEvent(m_status_event);
#ifdef _VC6_
									sprintf(m_status_message, "ProcessThread:MCHR_GetLastWrittenBuffer(End Measurements): Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
									sprintf_s(m_status_message, "ProcessThread:MCHR_GetLastWrittenBuffer(End Measurements): Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif

									}
								}
								criticalBuffer.Unlock();
							}
							else
							{
								m_status_acquisition = STATUS_EVENT_ERROR;
								if (m_status_event != NULL)
								{
									SetEvent(m_status_event);
#ifdef _VC6_
									sprintf(m_status_message, "ProcessThread:unexpected event (0x%X)\n", dwResult);
#else
									sprintf_s(m_status_message, "ProcessThread:unexpected event (0x%X)\n", dwResult);
#endif
								}
							}
							break;
						case EV_END_ACQUIRE: //EV_END_ACQUIRE
							if (dwResult == WAIT_OBJECT_0 + EVENT_END_ACQUIRE)
							{
								if (m_end_acq_event != NULL)
								{
									SetEvent(m_end_acq_event);
								}
							}
							break;
						default:	//EV_END_BUFFER
							if (dwResult == WAIT_OBJECT_0 + EVENT_END_BUFFER)
							{
								criticalBuffer.Lock();
								if (MCHR_GetLastWrittenBuffer(m_chr_id, MCHR_BUFFER_EVENT, &_last_buffer_index, &m_measure_index) != MCHR_ERROR)
								{
									//fifo roll index----------------------------------------------------------------------
									if (_previous_buffer_index == -1)
									{										
										m_number_of_buffer_to_read = 1;
										m_current_index_of_buffer_to_read = _last_buffer_index;
									}
									else
									{
										if (_previous_buffer_index <= _last_buffer_index)
										{
											m_number_of_buffer_to_read += (_last_buffer_index - _previous_buffer_index);
										}
										else
										{
											m_number_of_buffer_to_read += ((m_acqEasyParam.NumberOfBuffers - _previous_buffer_index) + _last_buffer_index);
										}
									}
									_previous_buffer_index = _last_buffer_index;
									//---------------------------------------------------------------------------------------
									if (m_end_acq_event != NULL)
									{
										SetEvent(m_end_acq_event);
									}
								}
								else
								{
									m_status_acquisition = STATUS_ACQ_ERROR;
									if (m_status_event != NULL)
									{
										SetEvent(m_status_event);
#ifdef _VC6_
										sprintf(m_status_message, "ProcessThread:MCHR_GetLastWrittenBuffer(End buffer): Error : (0x%X)", MCHR_GetLastError(m_chr_id));
#else
										sprintf_s(m_status_message, "ProcessThread:MCHR_GetLastWrittenBuffer(End buffer): Error : (0x%X)", MCHR_GetLastError(m_chr_id));
#endif
									}
								}
								criticalBuffer.Unlock();
							}
							else
							{
								m_status_acquisition = STATUS_EVENT_ERROR;
								if (m_status_event != NULL)
								{
									SetEvent(m_status_event);
#ifdef _VC6_
									sprintf(m_status_message, "ProcessThread:unexpected event (0x%X)\n", dwResult);
#else
									sprintf_s(m_status_message, "ProcessThread:unexpected event (0x%X)\n", dwResult);
#endif
								}
							}
							break;
					}			
					break;
				case WAIT_TIMEOUT:					
					if (TimeoutValue <= 0)
					{
						m_status_acquisition = STATUS_TIMEOUT_ERROR;
						if (m_status_event != NULL)
						{
							SetEvent(m_status_event);
#ifdef _VC6_
							sprintf(m_status_message, "ProcessThread:Timeout Error\n");
#else
							sprintf_s(m_status_message, "ProcessThread:Timeout Error\n");
#endif
						}
					}
					else
					{
						TimeoutValue -= TimeoutStep;
					}
					break;
				default:
					m_status_acquisition = STATUS_ACQ_ERROR;
					if (m_status_event != NULL)
					{
						SetEvent(m_status_event);
					}
					break;
			}
		}
	}
	SetEvent(m_OnEvent[EVENT_ACQ_EASY_KILL_THREAD_DO]);
	return(0);
}
//-------------------------------------------------------------------------------------------------
bool cAcqEasy::StopAcquisition()
{
	bool result = false;
	if (m_chr_id > 0)
	{
		MCHR_Abort(m_chr_id);		
		result = true;
	}
	criticalBuffer.Lock();
	m_IsDataAcquisitionStarting = false;
	_ReleaseAcqBuffer(m_acqEasyParam.NumberOfBuffers);
	criticalBuffer.Unlock();
	return(result);
}
//-------------------------------------------------------------------------------------------------
bool cAcqEasy::GetThicknessAcquisitionData(PFLOAT pArrayThickness, PFLOAT pArrayDistance1, PFLOAT pArrayIntensity1, PFLOAT pArrayBarycenter1, PFLOAT pArrayDistance2, PFLOAT pArrayIntensity2, PFLOAT pArrayBarycenter2, PFLOAT pArrayStatus, PFLOAT pArrayCounter, int* pDataCount)
{
	bool ret = false;
	DWORD sizeDataFloat = 0;
	DWORD sizeDataDWord = 0;	

	if (pDataCount != NULL)
	{
		*pDataCount = 0;
	}
	//verify parameters
	if (m_acqEasyParam.typeAcquisition != eMCHR_GetThicknessMeasurement)
	{		
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "GetThicknessAcquisitionData:Bad Parameters\n");
#else
		sprintf_s(m_status_message, "GetThicknessAcquisitionData:Bad Parameters\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}
		return(false); //bad call it is not the good function to call
	}
	if (m_acqEasyParam.TypeEvent == EV_END_MEASUREMENTS)
	{
		sizeDataFloat = (m_acqEasyParam.NumberOfPoints * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.NumberOfPoints * sizeof(DWORD));
	}
	else
	{
		sizeDataFloat = (m_acqEasyParam.BufferLength * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.BufferLength * sizeof(DWORD));
	}
	criticalBuffer.Lock();
	if (m_number_of_buffer_to_read > 0)
	{
		if ((pArrayThickness != NULL) && (m_acqEasyParam.EnableBufferThickness.Thickness == true))
		{
			memcpy(pArrayThickness, m_ppAcqBuffer[ID_BUFFER_THICKNESS_THICKNESS][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayDistance1 != NULL) && (m_acqEasyParam.EnableBufferThickness.Distance1 == true))
		{
			memcpy(pArrayDistance1, m_ppAcqBuffer[ID_BUFFER_THICKNESS_DISTANCE1][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayDistance2 != NULL) && (m_acqEasyParam.EnableBufferThickness.Distance2 == true))
		{
			memcpy(pArrayDistance2, m_ppAcqBuffer[ID_BUFFER_THICKNESS_DISTANCE2][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity1 != NULL) && (m_acqEasyParam.EnableBufferThickness.Intensity1 == true))
		{
			memcpy(pArrayIntensity1, m_ppAcqBuffer[ID_BUFFER_THICKNESS_INTENSITY1][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity2 != NULL) && (m_acqEasyParam.EnableBufferThickness.Intensity2 == true))
		{
			memcpy(pArrayIntensity2, m_ppAcqBuffer[ID_BUFFER_THICKNESS_INTENSITY2][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayBarycenter1 != NULL) && (m_acqEasyParam.EnableBufferThickness.BaryCenter1 == true))
		{
			memcpy(pArrayBarycenter1, m_ppAcqBuffer[ID_BUFFER_THICKNESS_BARYCENTER1][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayBarycenter2 != NULL) && (m_acqEasyParam.EnableBufferThickness.BaryCenter2 == true))
		{
			memcpy(pArrayBarycenter2, m_ppAcqBuffer[ID_BUFFER_THICKNESS_BARYCENTER2][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayStatus != NULL) && (m_acqEasyParam.EnableBufferThickness.Status == true))
		{
			memcpy(pArrayStatus, m_ppAcqBuffer[ID_BUFFER_THICKNESS_STATUS][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayCounter != NULL) && (m_acqEasyParam.EnableBufferThickness.Counter == true))
		{
			memcpy(pArrayCounter, m_ppAcqBuffer[ID_BUFFER_THICKNESS_COUNTER][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if (pDataCount != NULL)
		{
			*pDataCount = (sizeDataFloat / sizeof(float));
		}
		m_current_index_of_buffer_to_read = (m_current_index_of_buffer_to_read + 1) % m_acqEasyParam.NumberOfBuffers;
		m_number_of_buffer_to_read -= 1;
		ret = true;
	}
	else
	{
		m_status_acquisition = STATUS_NO_DATA;
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
#ifdef _VC6_
			sprintf(m_status_message, "GetThicknessAcquisitionData:No data to read.\n");
#else
			sprintf_s(m_status_message, "GetThicknessAcquisitionData:No data to read.\n");
#endif
		}		
	}
	criticalBuffer.Unlock();
	return(ret);
}
//-------------------------------------------------------------------------------------------------
bool cAcqEasy::GetAltitudeAcquisitionData(PFLOAT pArrayAltitude, PFLOAT pArrayIntensity, PFLOAT pArrayCounter, PFLOAT pArrayBarycenter, PFLOAT pArrayStatus, int* pDataCount)
{
	bool ret = false;
	DWORD sizeDataFloat = 0;
	DWORD sizeDataDWord = 0;

	if (pDataCount != NULL)
	{
		*pDataCount = 0;
	}
	//verify parameters
	if (m_acqEasyParam.typeAcquisition != eMCHR_GetAltitudeMeasurement)
	{
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "GetAltitudeAcquisitionData:Bad Parameters\n");
#else
		sprintf_s(m_status_message, "GetAltitudeAcquisitionData:Bad Parameters\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);			
		}
		return(false); //bad call it is not the good function to call
	}
	if (m_acqEasyParam.TypeEvent == EV_END_MEASUREMENTS)
	{
		sizeDataFloat = (m_acqEasyParam.NumberOfPoints * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.NumberOfPoints * sizeof(DWORD));
	}
	else
	{
		sizeDataFloat = (m_acqEasyParam.BufferLength * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.BufferLength * sizeof(DWORD));
	}
	criticalBuffer.Lock();
	if (m_number_of_buffer_to_read > 0)
	{
		if ((pArrayAltitude != NULL) && (m_acqEasyParam.EnableBufferAltitude.Altitude == true))
		{			
			memcpy(pArrayAltitude, m_ppAcqBuffer[ID_BUFFER_ALTITUDE_ALTITUDE][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity != NULL) && (m_acqEasyParam.EnableBufferAltitude.Intensity == true))
		{
			memcpy(pArrayIntensity, m_ppAcqBuffer[ID_BUFFER_ALTITUDE_INTENSITY][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayCounter != NULL) && (m_acqEasyParam.EnableBufferAltitude.Counter == true))
		{
			memcpy(pArrayCounter, m_ppAcqBuffer[ID_BUFFER_ALTITUDE_COUNTER][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayBarycenter != NULL) && (m_acqEasyParam.EnableBufferAltitude.BaryCenter == true))
		{
			memcpy(pArrayBarycenter, m_ppAcqBuffer[ID_BUFFER_ALTITUDE_BARYCENTER][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayStatus != NULL) && (m_acqEasyParam.EnableBufferAltitude.Status == true))
		{
			memcpy(pArrayStatus, m_ppAcqBuffer[ID_BUFFER_ALTITUDE_STATUS][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if (pDataCount != NULL)
		{
			*pDataCount = (sizeDataFloat / sizeof(float));
		}
		m_current_index_of_buffer_to_read = (m_current_index_of_buffer_to_read + 1) % m_acqEasyParam.NumberOfBuffers;
		m_number_of_buffer_to_read -= 1;
		ret = true;
	}
	else
	{
		m_status_acquisition = STATUS_NO_DATA;
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
#ifdef _VC6_
			sprintf(m_status_message, "GetAltitudeAcquisitionData:No data to read.\n");
#else
			sprintf_s(m_status_message, "GetAltitudeAcquisitionData:No data to read.\n");
#endif
		}		
	}
	criticalBuffer.Unlock();
	return(ret);
}
//-------------------------------------------------------------------------------------------------
bool cAcqEasy::GetDepthAcquisitionData(PFLOAT pArrayDepth, PFLOAT pArrayIntensity, PFLOAT pArrayCounter, PFLOAT pArrayBarycenter, PFLOAT pArrayStatus, int* pDataCount)
{
	bool ret = false;
	DWORD sizeDataFloat = 0;
	DWORD sizeDataDWord = 0;
	
	if (pDataCount != NULL)
	{
		*pDataCount = 0;
	}
	//verify parameters
	if (m_acqEasyParam.typeAcquisition != eMCHR_GetDepthMeasurement)
	{
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "GetDepthAcquisitionData:Bad Parameters\n");
#else
		sprintf_s(m_status_message, "GetDepthAcquisitionData:Bad Parameters\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}
		return(false); //bad call it is not the good function to call
	}
	if (m_acqEasyParam.TypeEvent == EV_END_MEASUREMENTS)
	{
		sizeDataFloat = (m_acqEasyParam.NumberOfPoints * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.NumberOfPoints * sizeof(DWORD));
	}
	else
	{
		sizeDataFloat = (m_acqEasyParam.BufferLength * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.BufferLength * sizeof(DWORD));
	}
	criticalBuffer.Lock();
	if (m_number_of_buffer_to_read > 0)
	{
		if ((pArrayDepth != NULL) && (m_acqEasyParam.EnableBufferDepth.Depth == true))
		{
			memcpy(pArrayDepth, m_ppAcqBuffer[ID_BUFFER_DEPTH_DEPTH][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity != NULL) && (m_acqEasyParam.EnableBufferDepth.Intensity == true))
		{
			memcpy(pArrayIntensity, m_ppAcqBuffer[ID_BUFFER_DEPTH_INTENSITY][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayCounter != NULL) && (m_acqEasyParam.EnableBufferDepth.Counter == true))
		{
			memcpy(pArrayCounter, m_ppAcqBuffer[ID_BUFFER_DEPTH_COUNTER][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayBarycenter != NULL) && (m_acqEasyParam.EnableBufferDepth.BaryCenter == true))
		{
			memcpy(pArrayBarycenter, m_ppAcqBuffer[ID_BUFFER_DEPTH_BARYCENTER][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayStatus != NULL) && (m_acqEasyParam.EnableBufferDepth.Status == true))
		{
			memcpy(pArrayStatus, m_ppAcqBuffer[ID_BUFFER_DEPTH_STATUS][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if (pDataCount != NULL)
		{
			*pDataCount = (sizeDataFloat / sizeof(float));
		}
		m_current_index_of_buffer_to_read = (m_current_index_of_buffer_to_read + 1) % m_acqEasyParam.NumberOfBuffers;
		m_number_of_buffer_to_read -= 1;
		ret = true;
	}
	else
	{
		m_status_acquisition = STATUS_NO_DATA;
#ifdef _VC6_
			sprintf(m_status_message, "GetDepthAcquisitionData:No data to read.\n");
#else
			sprintf_s(m_status_message, "GetDepthAcquisitionData:No data to read.\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}		
	}
	criticalBuffer.Unlock();
	return(ret);
}

//-------------------------------------------------------------------------------------------------
bool cAcqEasy::GetAltitudeEncoderData(PFLOAT pArrayAltitude, PFLOAT pArrayIntensity, PFLOAT pArrayCounter, PFLOAT pArrayBarycenter, PFLOAT pArrayStatus, PDWORD pArrayEncoder1, PDWORD pArrayEncoder2, PDWORD pArrayEncoder3,int* pDataCount)
{
	bool ret = false;
	DWORD sizeDataFloat = 0;
	DWORD sizeDataDWord = 0;

	if (pDataCount != NULL)
	{
		*pDataCount = 0;
	}
	//verify parameters
	if (m_acqEasyParam.typeAcquisition != eMCHR_GetAltitudeMeasurement)
	{
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "GetAltitudeAcquisitionData:Bad Parameters\n");
#else
		sprintf_s(m_status_message, "GetAltitudeAcquisitionData:Bad Parameters\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);			
		}
		return(false); //bad call it is not the good function to call
	}
	if (m_acqEasyParam.TypeEvent == EV_END_MEASUREMENTS)
	{
		sizeDataFloat = (m_acqEasyParam.NumberOfPoints * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.NumberOfPoints * sizeof(DWORD));
	}
	else
	{
		sizeDataFloat = (m_acqEasyParam.BufferLength * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.BufferLength * sizeof(DWORD));
	}
	criticalBuffer.Lock();
	if (m_number_of_buffer_to_read > 0)
	{
		if ((pArrayAltitude != NULL) && (m_acqEasyParam.EnableBufferAltitude.Altitude == true))
		{			
			memcpy(pArrayAltitude, m_ppAcqBuffer[ID_BUFFER_ALTITUDE_ALTITUDE][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity != NULL) && (m_acqEasyParam.EnableBufferAltitude.Intensity == true))
		{
			memcpy(pArrayIntensity, m_ppAcqBuffer[ID_BUFFER_ALTITUDE_INTENSITY][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayCounter != NULL) && (m_acqEasyParam.EnableBufferAltitude.Counter == true))
		{
			memcpy(pArrayCounter, m_ppAcqBuffer[ID_BUFFER_ALTITUDE_COUNTER][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayBarycenter != NULL) && (m_acqEasyParam.EnableBufferAltitude.BaryCenter == true))
		{
			memcpy(pArrayBarycenter, m_ppAcqBuffer[ID_BUFFER_ALTITUDE_BARYCENTER][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayStatus != NULL) && (m_acqEasyParam.EnableBufferAltitude.Status == true))
		{
			memcpy(pArrayStatus, m_ppAcqBuffer[ID_BUFFER_ALTITUDE_STATUS][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayEncoder1 != NULL) && (m_acqEasyParam.EnableBufferEncoder.Encoder1 == true))
		{
			memcpy(pArrayEncoder1, m_ppEncoderBuffer[ID_BUFFER_ENCODER_1][m_current_index_of_buffer_to_read], sizeDataDWord);
		}
		if ((pArrayEncoder2 != NULL) && (m_acqEasyParam.EnableBufferEncoder.Encoder1 == true))
		{
			memcpy(pArrayEncoder2, m_ppEncoderBuffer[ID_BUFFER_ENCODER_2][m_current_index_of_buffer_to_read], sizeDataDWord);
		}
		if ((pArrayEncoder3 != NULL) && (m_acqEasyParam.EnableBufferEncoder.Encoder3 == true))
		{
			memcpy(pArrayEncoder3, m_ppEncoderBuffer[ID_BUFFER_ENCODER_3][m_current_index_of_buffer_to_read], sizeDataDWord);
		}
		if (pDataCount != NULL)
		{
			*pDataCount = (sizeDataFloat / sizeof(float));
		}
		m_current_index_of_buffer_to_read = (m_current_index_of_buffer_to_read + 1) % m_acqEasyParam.NumberOfBuffers;
		m_number_of_buffer_to_read -= 1;
		ret = true;
	}
	else
	{
		m_status_acquisition = STATUS_NO_DATA;
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
#ifdef _VC6_
			sprintf(m_status_message, "GetAltitudeAcquisitionData:No data to read.\n");
#else
			sprintf_s(m_status_message, "GetAltitudeAcquisitionData:No data to read.\n");
#endif
		}		
	}
	criticalBuffer.Unlock();
	return(ret);
}

//-------------------------------------------------------------------------------------------------
bool cAcqEasy::GetEncoderData(PDWORD pArrayEncoder1, PDWORD pArrayEncoder2, PDWORD pArrayEncoder3)
{
	bool ret = false;
	DWORD sizeDataFloat = 0;
	DWORD sizeDataDWord = 0;
	
	//verify parameters
	if ((m_acqEasyParam.EnableBufferEncoder.Encoder1 == FALSE) && (m_acqEasyParam.EnableBufferEncoder.Encoder2 == FALSE) && (m_acqEasyParam.EnableBufferEncoder.Encoder3 == FALSE))
	{
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "GetEncoderData:Bad Parameters\n");
#else
		sprintf_s(m_status_message, "GetEncoderData:Bad Parameters\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}
		return(false); //bad call it is not the good function to call
	}
	if (m_acqEasyParam.TypeEvent == EV_END_MEASUREMENTS)
	{
		sizeDataFloat = (m_acqEasyParam.NumberOfPoints * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.NumberOfPoints * sizeof(DWORD));
	}
	else
	{
		sizeDataFloat = (m_acqEasyParam.BufferLength * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.BufferLength * sizeof(DWORD));
	}
	criticalBuffer.Lock();
	//if (m_current_index_of_buffer_to_read > 0)
	if(m_number_of_buffer_to_read > 0)
	{
		if ((pArrayEncoder1 != NULL) && (m_acqEasyParam.EnableBufferEncoder.Encoder1 == true))
		{
			memcpy(pArrayEncoder1, m_ppEncoderBuffer[ID_BUFFER_ENCODER_1][m_current_index_of_buffer_to_read], sizeDataDWord);
		}
		if ((pArrayEncoder2 != NULL) && (m_acqEasyParam.EnableBufferEncoder.Encoder1 == true))
		{
			memcpy(pArrayEncoder2, m_ppEncoderBuffer[ID_BUFFER_ENCODER_2][m_current_index_of_buffer_to_read], sizeDataDWord);
		}
		if ((pArrayEncoder3 != NULL) && (m_acqEasyParam.EnableBufferEncoder.Encoder3 == true))
		{
			memcpy(pArrayEncoder3, m_ppEncoderBuffer[ID_BUFFER_ENCODER_3][m_current_index_of_buffer_to_read], sizeDataDWord);
		}
		m_current_index_of_buffer_to_read = (m_current_index_of_buffer_to_read + 1) % m_acqEasyParam.NumberOfBuffers;
		m_number_of_buffer_to_read -= 1;
		ret = true;
	}

	else
	{
		m_status_acquisition = STATUS_NO_DATA;
#ifdef _VC6_
			sprintf(m_status_message, "GetEncoderData:No data to read.\n");
#else
			sprintf_s(m_status_message, "GetEncoderData:No data to read.\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}		
	}

	criticalBuffer.Unlock();
	return(ret);
}
//-------------------------------------------------------------------------------------------------
bool cAcqEasy::GetTransmittedData_ChrDistance(PFLOAT pArrayDistance, PFLOAT pArrayIntensity, PFLOAT pArrayBarycenter, int* pDataCount)
{
	bool ret = false;
	DWORD sizeDataFloat = 0;
	DWORD sizeDataDWord = 0;

	if (pDataCount != NULL)
	{
		*pDataCount = 0;
	}
	//verify parameters
	if ((m_acqEasyParam.typeAcquisition != eMCHR_GetTransmittedDataMeasurement) && (m_acqEasyParam.SensorMode == MCHR_DISTANCE_MODE))
	{
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "GetTransmittedData_ChrDistance:Bad Parameters\n");
#else
		sprintf_s(m_status_message, "GetTransmittedData_ChrDistance:Bad Parameters\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}
		return(false); //bad call it is not the good function to call
	}
	if (m_acqEasyParam.TypeEvent == EV_END_MEASUREMENTS)
	{
		sizeDataFloat = (m_acqEasyParam.NumberOfPoints * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.NumberOfPoints * sizeof(DWORD));
	}
	else
	{
		sizeDataFloat = (m_acqEasyParam.BufferLength * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.BufferLength * sizeof(DWORD));
	}
	criticalBuffer.Lock();
	if (m_number_of_buffer_to_read > 0)
	{
		if ((pArrayDistance != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.ChrDistance.Distance == true))
		{
			memcpy(pArrayDistance, m_ppAcqBuffer[ID_BUFFER_CHR_DISTANCE_DISTANCE][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.ChrDistance.Intensity == true))
		{
			memcpy(pArrayIntensity, m_ppAcqBuffer[ID_BUFFER_CHR_DISTANCE_INTENSITY][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayBarycenter != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.ChrDistance.BaryCenter == true))
		{
			memcpy(pArrayBarycenter, m_ppAcqBuffer[ID_BUFFER_CHR_DISTANCE_BARYCENTER][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if (pDataCount != NULL)
		{
			*pDataCount = (sizeDataFloat / sizeof(float));
		}
		m_current_index_of_buffer_to_read = (m_current_index_of_buffer_to_read + 1) % m_acqEasyParam.NumberOfBuffers;
		m_number_of_buffer_to_read -= 1;
		ret = true;
	}
	else
	{
		m_status_acquisition = STATUS_NO_DATA;
#ifdef _VC6_
			sprintf(m_status_message, "GetTransmittedData_ChrDistance:No data to read.\n");
#else
			sprintf_s(m_status_message, "GetTransmittedData_ChrDistance:No data to read.\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}		
	}
	criticalBuffer.Unlock();
	return(ret);
}
//-------------------------------------------------------------------------------------------------
bool cAcqEasy::GetTransmittedData_ChrThickness(PFLOAT pArrayThickness, PFLOAT pArrayDistance1, PFLOAT pArrayDistance2,  
											   PFLOAT pArrayIntensity1, PFLOAT pArrayIntensity2, PFLOAT pArrayBaryCenter1, PFLOAT pArrayBaryCenter2, int* pDataCount)
{
	bool ret = false;
	DWORD sizeDataFloat = 0;
	DWORD sizeDataDWord = 0;
	
	if (pDataCount != NULL)
	{
		*pDataCount = 0;
	}
	//verify parameters
	if ((m_acqEasyParam.typeAcquisition != eMCHR_GetTransmittedDataMeasurement) && (m_acqEasyParam.SensorMode == MCHR_THICKNESS_MODE))
	{
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "GetTransmittedData_ChrThickness:Bad Parameters\n");
#else
		sprintf_s(m_status_message, "GetTransmittedData_ChrThickness:Bad Parameters\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}
		return(false); //bad call it is not the good function to call
	}
	if (m_acqEasyParam.TypeEvent == EV_END_MEASUREMENTS)
	{
		sizeDataFloat = (m_acqEasyParam.NumberOfPoints * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.NumberOfPoints * sizeof(DWORD));
	}
	else
	{
		sizeDataFloat = (m_acqEasyParam.BufferLength * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.BufferLength * sizeof(DWORD));
	}
	criticalBuffer.Lock();
	if (m_number_of_buffer_to_read > 0)
	{
		if ((pArrayThickness != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.ChrThickness.Thickness == true))
		{
			memcpy(pArrayThickness, m_ppAcqBuffer[ID_BUFFER_CHR_THICKNESS_THICKNESS][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayDistance1 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.ChrThickness.Distance1 == true))
		{
			memcpy(pArrayDistance1, m_ppAcqBuffer[ID_BUFFER_CHR_THICKNESS_DISTANCE1][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayDistance2 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.ChrThickness.Distance2 == true))
		{
			memcpy(pArrayDistance2, m_ppAcqBuffer[ID_BUFFER_CHR_THICKNESS_DISTANCE2][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity1 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.ChrThickness.Intensity1 == true))
		{
			memcpy(pArrayIntensity1, m_ppAcqBuffer[ID_BUFFER_CHR_THICKNESS_INTENSITY1][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity2 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.ChrThickness.Intensity2 == true))
		{
			memcpy(pArrayIntensity2, m_ppAcqBuffer[ID_BUFFER_CHR_THICKNESS_INTENSITY2][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayBaryCenter1 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.ChrThickness.BaryCenter1 == true))
		{
			memcpy(pArrayBaryCenter1, m_ppAcqBuffer[ID_BUFFER_CHR_THICKNESS_BARYCENTER1][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayBaryCenter2 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.ChrThickness.BaryCenter2 == true))
		{
			memcpy(pArrayBaryCenter2, m_ppAcqBuffer[ID_BUFFER_CHR_THICKNESS_BARYCENTER2][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if (pDataCount != NULL)
		{
			*pDataCount = (sizeDataFloat / sizeof(float));
		}
		m_current_index_of_buffer_to_read = (m_current_index_of_buffer_to_read + 1) % m_acqEasyParam.NumberOfBuffers;
		m_number_of_buffer_to_read -= 1;
		ret = true;
	}
	else
	{
		m_status_acquisition = STATUS_NO_DATA;
#ifdef _VC6_
			sprintf(m_status_message, "GetTransmittedData_ChrThickness:No data to read.\n");
#else
			sprintf_s(m_status_message, "GetTransmittedData_ChrThickness:No data to read.\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}		
	}
	criticalBuffer.Unlock();
	return(ret);
}
//-------------------------------------------------------------------------------------------------
bool cAcqEasy::GetTransmittedData_CcsDistance(PFLOAT pArrayDistance, PFLOAT pArrayAutoAdaptativeModeData, PFLOAT pArrayIntensity, PFLOAT pArrayBaryCenter, 
											  PFLOAT pArrayStatus, PFLOAT pArrayCounter, PDWORD pArrayEncoder1, PDWORD pArrayEncoder2, PDWORD pArrayEncoder3, int* pDataCount)
{
	bool ret = false;
	DWORD sizeDataFloat = 0;
	DWORD sizeDataDWord = 0;
	int idx = 0;

	if (pDataCount != NULL)
	{
		*pDataCount = 0;
	}
	//verify parameters
	if ((m_acqEasyParam.typeAcquisition != eMCHR_GetTransmittedDataMeasurement) && (m_acqEasyParam.SensorMode == MCHR_DISTANCE_MODE))
	{
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "GetTransmittedData_CcsDistance:Bad Parameters\n");
#else
		sprintf_s(m_status_message, "GetTransmittedData_CcsDistance:Bad Parameters\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}
		return(false); //bad call it is not the good function to call
	}
	if (m_acqEasyParam.TypeEvent == EV_END_MEASUREMENTS)
	{
		sizeDataFloat = (m_acqEasyParam.NumberOfPoints * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.NumberOfPoints * sizeof(DWORD));
	}
	else
	{
		sizeDataFloat = (m_acqEasyParam.BufferLength * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.BufferLength * sizeof(DWORD));
	}
	criticalBuffer.Lock();
	if (m_number_of_buffer_to_read > 0)
	{
		if ((pArrayDistance != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.Distance == true))
		{
			memcpy(pArrayDistance, m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_DISTANCE_MSB][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayAutoAdaptativeModeData != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.AutoAdaptativeModeData == true))
		{
			memcpy(pArrayAutoAdaptativeModeData, m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_AUTO_ADAPTATIVE_MODE][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.Intensity == true))
		{
			memcpy(pArrayIntensity, m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_INTENSITY][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayBaryCenter != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.BaryCenter == true))
		{
			memcpy(pArrayBaryCenter, m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_BARYCENTER][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayStatus != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.Status == true))
		{
			memcpy(pArrayStatus, m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_STATUS][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayCounter != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.Counter == true))
		{
			memcpy(pArrayCounter, m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_COUNTER][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayEncoder1 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.Encoder1 == true))
		{
			//memcpy(pArrayEncoder1, m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_ENCODER1_MSB][m_current_index_of_buffer_to_read], sizeDataDWord);
			for(idx = 0; idx < (sizeDataDWord / sizeof (DWORD)); idx++)
				pArrayEncoder1[idx] = (((DWORD)(m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_ENCODER1_MSB][m_current_index_of_buffer_to_read][idx])<<15) 
				                               | (DWORD) m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_ENCODER1_LSB][m_current_index_of_buffer_to_read][idx]);
		}
		if ((pArrayEncoder2 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.Encoder2 == true))
		{
			//memcpy(pArrayEncoder2, m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_ENCODER2_MSB][m_current_index_of_buffer_to_read], sizeDataDWord);
			for(idx = 0; idx < (sizeDataDWord / sizeof (DWORD)); idx++)
				pArrayEncoder2[idx] = (((DWORD)(m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_ENCODER2_MSB][m_current_index_of_buffer_to_read][idx])<<15) 
				                               | (DWORD) m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_ENCODER2_LSB][m_current_index_of_buffer_to_read][idx]);
		}
		if ((pArrayEncoder3 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.Encoder3 == true))
		{
			//memcpy(pArrayEncoder3, m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_ENCODER3_MSB][m_current_index_of_buffer_to_read], sizeDataDWord);
			for(idx = 0; idx < (sizeDataDWord / sizeof (DWORD)); idx++)
				pArrayEncoder3[idx] = (((DWORD)(m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_ENCODER3_MSB][m_current_index_of_buffer_to_read][idx])<<15) 
				                               | (DWORD) m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_ENCODER3_LSB][m_current_index_of_buffer_to_read][idx]);
		}
		if (pDataCount != NULL)
		{
			*pDataCount += (sizeDataFloat / sizeof(float));
		}
		m_current_index_of_buffer_to_read = (m_current_index_of_buffer_to_read + 1) % m_acqEasyParam.NumberOfBuffers;
		m_number_of_buffer_to_read -= 1;
		ret = true;
	}
	else
	{
		m_status_acquisition = STATUS_NO_DATA;
#ifdef _VC6_
			sprintf(m_status_message, "GetTransmittedData_CcsDistance:No data to read.\n");
#else
			sprintf_s(m_status_message, "GetTransmittedData_CcsDistance:No data to read.\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}		
	}
	criticalBuffer.Unlock();
	return(ret);
}
//-------------------------------------------------------------------------------------------------
bool cAcqEasy::GetTransmittedData_CcsThickness(PFLOAT pArrayThickness, PFLOAT pArrayDistance1, PFLOAT pArrayDistance2, PFLOAT pArrayAutoAdaptativeModeData, PFLOAT pArrayIntensity1, 
											   PFLOAT pArrayIntensity2, PFLOAT pArrayBaryCenter1, PFLOAT pArrayBaryCenter2, PFLOAT pArrayStatus, PFLOAT pArrayCounter, 
											   PDWORD pArrayEncoder1, PDWORD pArrayEncoder2, PDWORD pArrayEncoder3, int* pDataCount)
{
	bool ret = false;
	DWORD sizeDataFloat = 0;
	DWORD sizeDataDWord = 0;
	int idx = 0;
	
	if (pDataCount != NULL)
	{
		*pDataCount = 0;
	}
	//verify parameters
	if ((m_acqEasyParam.typeAcquisition != eMCHR_GetTransmittedDataMeasurement) && (m_acqEasyParam.SensorMode == MCHR_THICKNESS_MODE))
	{
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "GetTransmittedData_CcsThickness:Bad Parameters\n");
#else
		sprintf_s(m_status_message, "GetTransmittedData_CcsThickness:Bad Parameters\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}
		return(false); //bad call it is not the good function to call
	}
	if (m_acqEasyParam.TypeEvent == EV_END_MEASUREMENTS)
	{
		sizeDataFloat = (m_acqEasyParam.NumberOfPoints * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.NumberOfPoints * sizeof(DWORD));
	}
	else
	{
		sizeDataFloat = (m_acqEasyParam.BufferLength * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.BufferLength * sizeof(DWORD));
	}
	criticalBuffer.Lock();
	if (m_number_of_buffer_to_read > 0)
	{
		if ((pArrayThickness != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Thickness == true))
		{
			memcpy(pArrayThickness, m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_THICKNESS][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayDistance1 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Distance1 == true))
		{
			memcpy(pArrayDistance1, m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_DISTANCE1][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayDistance2 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Distance2 == true))
		{
			memcpy(pArrayDistance2, m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_DISTANCE2][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayAutoAdaptativeModeData != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.AutoAdaptativeModeData == true))
		{
			memcpy(pArrayAutoAdaptativeModeData, m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_AUTO_ADAPTATIVE_MODE][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity1 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Intensity1 == true))
		{
			memcpy(pArrayIntensity1, m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_INTENSITY1][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity2 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Intensity2 == true))
		{
			memcpy(pArrayIntensity2, m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_INTENSITY2][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayBaryCenter1 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.BaryCenter1 == true))
		{
			memcpy(pArrayBaryCenter1, m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_BARYCENTER1][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayBaryCenter2 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.BaryCenter2 == true))
		{
			memcpy(pArrayBaryCenter2, m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_BARYCENTER2][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayStatus != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Status == true))
		{
			memcpy(pArrayStatus, m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_STATUS][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayCounter != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Counter == true))
		{
			memcpy(pArrayCounter, m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_COUNTER][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayEncoder1 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Encoder1 == true))
		{
			// memcpy(pArrayEncoder1, m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_ENCODER1_MSB][m_current_index_of_buffer_to_read], sizeDataDWord);
			for(idx = 0; idx < (sizeDataDWord / sizeof (DWORD)); idx++)
				pArrayEncoder1[idx] = (((DWORD)(m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_ENCODER1_MSB][m_current_index_of_buffer_to_read][idx])<<15) 
				                               | (DWORD) m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_ENCODER1_LSB][m_current_index_of_buffer_to_read][idx]);
		}
		if ((pArrayEncoder2 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Encoder2 == true))
		{
			//memcpy(pArrayEncoder2, m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_ENCODER2_MSB][m_current_index_of_buffer_to_read], sizeDataDWord);
			for(idx = 0; idx < (sizeDataDWord / sizeof (DWORD)); idx++)
				pArrayEncoder2[idx] = (((DWORD)(m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_ENCODER2_MSB][m_current_index_of_buffer_to_read][idx])<<15) 
				                               | (DWORD) m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_ENCODER2_LSB][m_current_index_of_buffer_to_read][idx]);
		}
		if ((pArrayEncoder3 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Encoder3 == true))
		{
			//memcpy(pArrayEncoder3, m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_ENCODER3_MSB][m_current_index_of_buffer_to_read], sizeDataDWord);
			for(idx = 0; idx < (sizeDataDWord / sizeof (DWORD)); idx++)
				pArrayEncoder3[idx] = (((DWORD)(m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_ENCODER3_MSB][m_current_index_of_buffer_to_read][idx])<<15) 
				                               | (DWORD) m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_ENCODER3_LSB][m_current_index_of_buffer_to_read][idx]);
		}
		if (pDataCount != NULL)
		{
			*pDataCount = (sizeDataFloat / sizeof(float));
		}
		m_current_index_of_buffer_to_read = (m_current_index_of_buffer_to_read + 1) % m_acqEasyParam.NumberOfBuffers;
		m_number_of_buffer_to_read -= 1;
		ret = true;
	}
	else
	{
		m_status_acquisition = STATUS_NO_DATA;
#ifdef _VC6_
			sprintf(m_status_message, "GetTransmittedData_CcsThickness:No data to read.\n");
#else
			sprintf_s(m_status_message, "GetTransmittedData_CcsThickness:No data to read.\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}		
	}
	criticalBuffer.Unlock();
	return(ret);
}
//-------------------------------------------------------------------------------------------------
bool cAcqEasy::GetTransmittedData_DuoDistance(PFLOAT pArrayDistance, PFLOAT pArrayIntensity, PFLOAT pArrayCounter, PFLOAT pArrayBarycenter, PFLOAT pArrayStatus, int* pDataCount)
{
	bool ret = false;
	DWORD sizeDataFloat = 0;
	DWORD sizeDataDWord = 0;

	if (pDataCount != NULL)
	{
		*pDataCount = 0;
	}
	//verify parameters
	if ((m_acqEasyParam.typeAcquisition != eMCHR_GetTransmittedDataMeasurement) && (m_acqEasyParam.SensorMode == MCHR_DISTANCE_MODE))
	{
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "GetTransmittedData_DuoDistance:Bad Parameters\n");
#else
		sprintf_s(m_status_message, "GetTransmittedData_DuoDistance:Bad Parameters\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}
		return(false); //bad call it is not the good function to call
	}
	if (m_acqEasyParam.TypeEvent == EV_END_MEASUREMENTS)
	{
		sizeDataFloat = (m_acqEasyParam.NumberOfPoints * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.NumberOfPoints * sizeof(DWORD));
	}
	else
	{
		sizeDataFloat = (m_acqEasyParam.BufferLength * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.BufferLength * sizeof(DWORD));
	}
	criticalBuffer.Lock();
	if (m_number_of_buffer_to_read > 0)
	{
		if ((pArrayDistance != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoDistance.Distance == true))
		{
			memcpy(pArrayDistance, m_ppAcqBuffer[ID_BUFFER_DUO_DISTANCE_DISTANCE_MSB][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoDistance.Intensity == true))
		{
			memcpy(pArrayIntensity, m_ppAcqBuffer[ID_BUFFER_DUO_DISTANCE_INTENSITY][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayCounter != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoDistance.Counter == true))
		{
			memcpy(pArrayCounter, m_ppAcqBuffer[ID_BUFFER_DUO_DISTANCE_COUNTER][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayBarycenter != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoDistance.BaryCenter == true))
		{
			memcpy(pArrayBarycenter, m_ppAcqBuffer[ID_BUFFER_DUO_DISTANCE_BARYCENTER][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayStatus != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoDistance.Status == true))
		{
			memcpy(pArrayStatus, m_ppAcqBuffer[ID_BUFFER_DUO_DISTANCE_STATUS][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if (pDataCount != NULL)
		{
			*pDataCount = (sizeDataFloat / sizeof(float));
		}
		m_current_index_of_buffer_to_read = (m_current_index_of_buffer_to_read + 1) % m_acqEasyParam.NumberOfBuffers;
		m_number_of_buffer_to_read -= 1;
		ret = true;
	}
	else
	{
		m_status_acquisition = STATUS_NO_DATA;
#ifdef _VC6_
			sprintf(m_status_message, "GetTransmittedData_DuoDistance:No data to read.\n");
#else
			sprintf_s(m_status_message, "GetTransmittedData_DuoDistance:No data to read.\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}		
	}
	criticalBuffer.Unlock();
	return(ret);
}
//-------------------------------------------------------------------------------------------------
bool cAcqEasy::GetTransmittedData_DuoThickness(PFLOAT pArrayThickness, PFLOAT pArrayDistance1, PFLOAT pArrayDistance2, PFLOAT pArrayCounter, 
											   PFLOAT pArrayIntensity1, PFLOAT pArrayIntensity2, PFLOAT pArrayBaryCenter1, PFLOAT pArrayBaryCenter2, PFLOAT pArrayStatus, int* pDataCount)
{
	bool ret = false;
	DWORD sizeDataFloat = 0;
	DWORD sizeDataDWord = 0;

	if (pDataCount != NULL)
	{
		*pDataCount = 0;
	}
	//verify parameters
	if ((m_acqEasyParam.typeAcquisition != eMCHR_GetTransmittedDataMeasurement) && (m_acqEasyParam.SensorMode == MCHR_THICKNESS_MODE))
	{
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "GetTransmittedData_DuoThickness:Bad Parameters\n");
#else
		sprintf_s(m_status_message, "GetTransmittedData_DuoThickness:Bad Parameters\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}
		return(false); //bad call it is not the good function to call
	}
	if (m_acqEasyParam.TypeEvent == EV_END_MEASUREMENTS)
	{
		sizeDataFloat = (m_acqEasyParam.NumberOfPoints * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.NumberOfPoints * sizeof(DWORD));
	}
	else
	{
		sizeDataFloat = (m_acqEasyParam.BufferLength * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.BufferLength * sizeof(DWORD));
	}
	criticalBuffer.Lock();
	if (m_number_of_buffer_to_read > 0)
	{
		if ((pArrayThickness != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoThickness.Thickness == true))
		{
			memcpy(pArrayThickness, m_ppAcqBuffer[ID_BUFFER_DUO_THICKNESS_THICKNESS][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayDistance1 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoThickness.Distance1 == true))
		{
			memcpy(pArrayDistance1, m_ppAcqBuffer[ID_BUFFER_DUO_THICKNESS_DISTANCE1][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayDistance2 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoThickness.Distance2 == true))
		{
			memcpy(pArrayDistance2, m_ppAcqBuffer[ID_BUFFER_DUO_THICKNESS_DISTANCE2][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayCounter != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoThickness.Counter == true))
		{
			memcpy(pArrayCounter, m_ppAcqBuffer[ID_BUFFER_DUO_THICKNESS_COUNTER][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity1 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoThickness.Intensity1 == true))
		{
			memcpy(pArrayIntensity1, m_ppAcqBuffer[ID_BUFFER_DUO_THICKNESS_INTENSITY1][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity2 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoThickness.Intensity2 == true))
		{
			memcpy(pArrayIntensity2, m_ppAcqBuffer[ID_BUFFER_DUO_THICKNESS_INTENSITY2][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayBaryCenter1 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoThickness.BaryCenter1 == true))
		{
			memcpy(pArrayBaryCenter1, m_ppAcqBuffer[ID_BUFFER_DUO_THICKNESS_BARYCENTER1][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayBaryCenter2 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoThickness.BaryCenter2 == true))
		{
			memcpy(pArrayBaryCenter2, m_ppAcqBuffer[ID_BUFFER_DUO_THICKNESS_BARYCENTER2][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayStatus != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoThickness.Status == true))
		{
			memcpy(pArrayStatus, m_ppAcqBuffer[ID_BUFFER_DUO_THICKNESS_STATUS][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if (pDataCount != NULL)
		{
			*pDataCount = (sizeDataFloat / sizeof(float));
		}
		m_current_index_of_buffer_to_read = (m_current_index_of_buffer_to_read + 1) % m_acqEasyParam.NumberOfBuffers;
		m_number_of_buffer_to_read -= 1;
		ret = true;
	}
	else
	{
		m_status_acquisition = STATUS_NO_DATA;
#ifdef _VC6_
			sprintf(m_status_message, "GetTransmittedData_DuoThickness:No data to read.\n");
#else
			sprintf_s(m_status_message, "GetTransmittedData_DuoThickness:No data to read.\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}		
	}
	criticalBuffer.Unlock();
	return(ret);
}
//-------------------------------------------------------------------------------------------------
bool cAcqEasy::GetTransmittedData_DuoSawliDistance(PFLOAT pArrayDistance, PFLOAT pArrayQuality, PFLOAT pArrayIntensity, PFLOAT pArrayCounter, PFLOAT pArrayStatus, int* pDataCount)
{
	bool ret = false;
	DWORD sizeDataFloat = 0;
	DWORD sizeDataDWord = 0;

	if (pDataCount != NULL)
	{
		*pDataCount = 0;
	}
	//verify parameters
	if ((m_acqEasyParam.typeAcquisition != eMCHR_GetTransmittedDataMeasurement) && (m_acqEasyParam.SensorMode == MCHR_DISTANCE_MODE))
	{
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "GetTransmittedData_DuoSawliDistance:Bad Parameters\n");
#else
		sprintf_s(m_status_message, "GetTransmittedData_DuoSawliDistance:Bad Parameters\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}
		return(false); //bad call it is not the good function to call
	}
	if (m_acqEasyParam.TypeEvent == EV_END_MEASUREMENTS)
	{
		sizeDataFloat = (m_acqEasyParam.NumberOfPoints * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.NumberOfPoints * sizeof(DWORD));
	}
	else
	{
		sizeDataFloat = (m_acqEasyParam.BufferLength * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.BufferLength * sizeof(DWORD));
	}
	criticalBuffer.Lock();
	if (m_number_of_buffer_to_read > 0)
	{
		if ((pArrayDistance != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoSawliDistance.Distance == true))
		{
			memcpy(pArrayDistance, m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_DISTANCE_DISTANCE_MSB][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayQuality != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoSawliDistance.Quality == true))
		{
			memcpy(pArrayQuality, m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_DISTANCE_QUALITY][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoSawliDistance.Intensity == true))
		{
			memcpy(pArrayIntensity, m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_DISTANCE_INTENSITY][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayCounter != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoSawliDistance.Counter == true))
		{
			memcpy(pArrayCounter, m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_DISTANCE_COUNTER][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayStatus != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoSawliDistance.Status == true))
		{
			memcpy(pArrayStatus, m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_DISTANCE_STATUS][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if (pDataCount != NULL)
		{
			*pDataCount = (sizeDataFloat / sizeof(float));
		}
		m_current_index_of_buffer_to_read = (m_current_index_of_buffer_to_read + 1) % m_acqEasyParam.NumberOfBuffers;
		m_number_of_buffer_to_read -= 1;
		ret = true;
	}
	else
	{
		m_status_acquisition = STATUS_NO_DATA;
#ifdef _VC6_
			sprintf(m_status_message, "GetTransmittedData_DuoSawliDistance:No data to read.\n");
#else
			sprintf_s(m_status_message, "GetTransmittedData_DuoSawliDistance:No data to read.\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}		
	}
	criticalBuffer.Unlock();
	return(ret);
}	
//-------------------------------------------------------------------------------------------------
bool cAcqEasy::GetTransmittedData_DuoSawliThickness(PFLOAT pArrayThickness1, PFLOAT pArrayThickness2, PFLOAT pArrayThickness3, PFLOAT pArrayQuality1, 
													PFLOAT pArrayQuality2, PFLOAT pArrayQuality3, PFLOAT pArrayIntensity, PFLOAT pArrayNbThickness, 
													PFLOAT pArrayCounter, PFLOAT pArrayStatus, int* pDataCount)
{
	bool ret = false;
	DWORD sizeDataFloat = 0;
	DWORD sizeDataDWord = 0;

	if (pDataCount != NULL)
	{
		*pDataCount = 0;
	}
	//verify parameters
	if ((m_acqEasyParam.typeAcquisition != eMCHR_GetTransmittedDataMeasurement) && (m_acqEasyParam.SensorMode == MCHR_THICKNESS_MODE))
	{
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "GetTransmittedData_DuoSawliThickness:Bad Parameters\n");
#else
		sprintf_s(m_status_message, "GetTransmittedData_DuoSawliThickness:Bad Parameters\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}
		return(false); //bad call it is not the good function to call
	}
	if (m_acqEasyParam.TypeEvent == EV_END_MEASUREMENTS)
	{
		sizeDataFloat = (m_acqEasyParam.NumberOfPoints * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.NumberOfPoints * sizeof(DWORD));
	}
	else
	{
		sizeDataFloat = (m_acqEasyParam.BufferLength * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.BufferLength * sizeof(DWORD));
	}
	criticalBuffer.Lock();
	if (m_number_of_buffer_to_read > 0)
	{
		if ((pArrayThickness1 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Thickness1 == true))
		{
			memcpy(pArrayThickness1, m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS1_MSB][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayThickness2 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Thickness2 == true))
		{
			memcpy(pArrayThickness2, m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS2_MSB][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayThickness3 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Thickness2 == true))
		{
			memcpy(pArrayThickness3, m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS3_MSB][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayQuality1 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Quality1 == true))
		{
			memcpy(pArrayQuality1, m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_QUALITY1][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayQuality2 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Quality2 == true))
		{
			memcpy(pArrayQuality2, m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_QUALITY2][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayQuality3 != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Quality3 == true))
		{
			memcpy(pArrayQuality3, m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_QUALITY3][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Intensity == true))
		{
			memcpy(pArrayIntensity, m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_INTENSITY][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayNbThickness != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.NbThickness == true))
		{
			memcpy(pArrayNbThickness, m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_NB_THICKNESS][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayCounter != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Counter == true))
		{
			memcpy(pArrayCounter, m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_COUNTER][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayStatus != NULL) && (m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Status == true))
		{
			memcpy(pArrayStatus, m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_STATUS][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if (pDataCount != NULL)
		{
			*pDataCount = (sizeDataFloat / sizeof(float));
		}
		m_current_index_of_buffer_to_read = (m_current_index_of_buffer_to_read + 1) % m_acqEasyParam.NumberOfBuffers;
		m_number_of_buffer_to_read -= 1;
		ret = true;
	}
	else
	{
		m_status_acquisition = STATUS_NO_DATA;
#ifdef _VC6_
			sprintf(m_status_message, "GetTransmittedData_DuoSawliThickness:No data to read.\n");
#else
			sprintf_s(m_status_message, "GetTransmittedData_DuoSawliThickness:No data to read.\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}		
	}
	criticalBuffer.Unlock();
	return(ret);
}
//-------------------------------------------------------------------------------------------------
bool cAcqEasy::GetInterferometricThicknessAcquisitionData(PFLOAT pArrayThickness1, PFLOAT pArrayThickness2, PFLOAT pArrayThickness3, PFLOAT pArrayQuality1, 
													PFLOAT pArrayQuality2, PFLOAT pArrayQuality3, PFLOAT pArrayIntensity, int* pDataCount)
{
	bool ret = false;
	DWORD sizeDataFloat = 0;
	DWORD sizeDataDWord = 0;

	if (pDataCount != NULL)
	{
		*pDataCount = 0;
	}
	//verify parameters
	if ((m_acqEasyParam.typeAcquisition != eMCHR_GetInterferometricThickness) && (m_acqEasyParam.SensorMode == MCHR_THICKNESS_MODE))
	{
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "GetInterferometricThicknessAcquisitionData:Bad Parameters\n");
#else
		sprintf_s(m_status_message, "GetInterferometricThicknessAcquisitionData:Bad Parameters\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}
		return(false); //bad call it is not the good function to call
	}
	if (m_acqEasyParam.TypeEvent == EV_END_MEASUREMENTS)
	{
		sizeDataFloat = (m_acqEasyParam.NumberOfPoints * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.NumberOfPoints * sizeof(DWORD));
	}
	else
	{
		sizeDataFloat = (m_acqEasyParam.BufferLength * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.BufferLength * sizeof(DWORD));
	}
	criticalBuffer.Lock();
	if (m_number_of_buffer_to_read > 0)
	{
		if ((pArrayThickness1 != NULL) && (m_acqEasyParam.EnableBufferInterferometricThickness.Thickness1 == true))
		{
			memcpy(pArrayThickness1, m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_THICKNESS1][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayThickness2 != NULL) && (m_acqEasyParam.EnableBufferInterferometricThickness.Thickness2 == true))
		{
			memcpy(pArrayThickness2, m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_THICKNESS2][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayThickness3 != NULL) && (m_acqEasyParam.EnableBufferInterferometricThickness.Thickness2 == true))
		{
			memcpy(pArrayThickness3, m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_THICKNESS3][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayQuality1 != NULL) && (m_acqEasyParam.EnableBufferInterferometricThickness.Quality1 == true))
		{
			memcpy(pArrayQuality1, m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_QUALITY1][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayQuality2 != NULL) && (m_acqEasyParam.EnableBufferInterferometricThickness.Quality2 == true))
		{
			memcpy(pArrayQuality2, m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_QUALITY2][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayQuality3 != NULL) && (m_acqEasyParam.EnableBufferInterferometricThickness.Quality3 == true))
		{
			memcpy(pArrayQuality3, m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_QUALITY3][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity != NULL) && (m_acqEasyParam.EnableBufferInterferometricThickness.Intensity == true))
		{
			memcpy(pArrayIntensity, m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_INTENSITY][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if (pDataCount != NULL)
		{
			*pDataCount = (sizeDataFloat / sizeof(float));
		}
		m_current_index_of_buffer_to_read = (m_current_index_of_buffer_to_read + 1) % m_acqEasyParam.NumberOfBuffers;
		m_number_of_buffer_to_read -= 1;
		ret = true;
	}
	else
	{
		m_status_acquisition = STATUS_NO_DATA;
#ifdef _VC6_
			sprintf(m_status_message, "GetInterferometricThicknessAcquisitionData:No data to read.\n");
#else
			sprintf_s(m_status_message, "GetInterferometricThicknessAcquisitionData:No data to read.\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}		
	}
	criticalBuffer.Unlock();
	return(ret);
}
//-------------------------------------------------------------------------------------------------
bool cAcqEasy::GetInterferometricThicknessSAWLIAcquisitionData(PFLOAT pArrayThickness1, PFLOAT pArrayThickness2, PFLOAT pArrayThickness3, PFLOAT pArrayQuality1, 
													PFLOAT pArrayQuality2, PFLOAT pArrayQuality3, PFLOAT pArrayIntensity, PFLOAT pArrayThickness, 
													PFLOAT pArrayCounter, PFLOAT pArrayStatus, int* pDataCount)
{
	bool ret = false;
	DWORD sizeDataFloat = 0;
	DWORD sizeDataDWord = 0;

	if (pDataCount != NULL)
	{
		*pDataCount = 0;
	}
	//verify parameters
	if ((m_acqEasyParam.typeAcquisition != eMCHR_GetInterferometricThicknessSAWLI) && (m_acqEasyParam.SensorMode == MCHR_THICKNESS_MODE))
	{
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "GetInterferometricThicknessSAWLIAcquisitionData:Bad Parameters\n");
#else
		sprintf_s(m_status_message, "GetInterferometricThicknessSAWLIAcquisitionData:Bad Parameters\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}
		return(false); //bad call it is not the good function to call
	}
	if (m_acqEasyParam.TypeEvent == EV_END_MEASUREMENTS)
	{
		sizeDataFloat = (m_acqEasyParam.NumberOfPoints * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.NumberOfPoints * sizeof(DWORD));
	}
	else
	{
		sizeDataFloat = (m_acqEasyParam.BufferLength * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.BufferLength * sizeof(DWORD));
	}
	criticalBuffer.Lock();
	if (m_number_of_buffer_to_read > 0)
	{
		if ((pArrayThickness1 != NULL) && (m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Thickness1 == true))
		{
			memcpy(pArrayThickness1, m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_THICKNESS1][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayThickness2 != NULL) && (m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Thickness2 == true))
		{
			memcpy(pArrayThickness2, m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_THICKNESS2][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayThickness3 != NULL) && (m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Thickness2 == true))
		{
			memcpy(pArrayThickness3, m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_THICKNESS3][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayQuality1 != NULL) && (m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Quality1 == true))
		{
			memcpy(pArrayQuality1, m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_QUALITY1][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayQuality2 != NULL) && (m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Quality2 == true))
		{
			memcpy(pArrayQuality2, m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_QUALITY2][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayQuality3 != NULL) && (m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Quality3 == true))
		{
			memcpy(pArrayQuality3, m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_QUALITY3][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity != NULL) && (m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Intensity == true))
		{
			memcpy(pArrayIntensity, m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_INTENSITY][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayIntensity != NULL) && (m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Thickness == true))
		{
			memcpy(pArrayThickness, m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_THICKNESS][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayCounter != NULL) && (m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Counter == true))
		{
			memcpy(pArrayCounter, m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_COUNTER][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if ((pArrayStatus != NULL) && (m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Status == true))
		{
			memcpy(pArrayStatus, m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_STATUS][m_current_index_of_buffer_to_read], sizeDataFloat);
		}
		if (pDataCount != NULL)
		{
			*pDataCount = (sizeDataFloat / sizeof(float));
		}
		m_current_index_of_buffer_to_read = (m_current_index_of_buffer_to_read + 1) % m_acqEasyParam.NumberOfBuffers;
		m_number_of_buffer_to_read -= 1;
		ret = true;
	}
	else
	{
		m_status_acquisition = STATUS_NO_DATA;
#ifdef _VC6_
			sprintf(m_status_message, "GetInterferometricThicknessSAWLIAcquisitionData:No data to read.\n");
#else
			sprintf_s(m_status_message, "GetInterferometricThicknessSAWLIAcquisitionData:No data to read.\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}		
	}
	criticalBuffer.Unlock();
	return(ret);
}
//-------------------------------------------------------------------------------------------------
bool cAcqEasy::GetAutoAdaptativeData(PFLOAT pArrayAutoAdaptative)
{
	bool ret = false;
	DWORD sizeDataFloat = 0;
	DWORD sizeDataDWord = 0;

	//verify parameters
	if (m_acqEasyParam.EnableBufferAutoAdaptive == FALSE)
	{
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "GetAutoAdaptativeData:Bad Parameters\n");
#else
		sprintf_s(m_status_message, "GetAutoAdaptativeData:Bad Parameters\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}
		return(false); //bad call it is not the good function to call
	}
	if (m_acqEasyParam.TypeEvent == EV_END_MEASUREMENTS)
	{
		sizeDataFloat = (m_acqEasyParam.NumberOfPoints * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.NumberOfPoints * sizeof(DWORD));
	}
	else
	{
		sizeDataFloat = (m_acqEasyParam.BufferLength * sizeof(float));
		sizeDataDWord = (m_acqEasyParam.BufferLength * sizeof(DWORD));
	}
	criticalBuffer.Lock();
	if (m_current_index_of_buffer_to_read > 0)
	{
		if ((pArrayAutoAdaptative != NULL) && (m_acqEasyParam.EnableBufferAutoAdaptive == true))
		{
			memcpy(pArrayAutoAdaptative, m_ppAutoAdaptativeBuffer[m_current_index_of_buffer_to_read], sizeDataDWord);
		}
		m_current_index_of_buffer_to_read = (m_current_index_of_buffer_to_read + 1) % m_acqEasyParam.NumberOfBuffers;
		m_number_of_buffer_to_read -= 1;
		ret = true;
	}
	else
	{
		m_status_acquisition = STATUS_NO_DATA;
#ifdef _VC6_
			sprintf(m_status_message, "GetAutoAdaptativeData:No data to read.\n");
#else
			sprintf_s(m_status_message, "GetAutoAdaptativeData:No data to read.\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}		
	}
	criticalBuffer.Unlock();
	return(ret);
}
//-------------------------------------------------------------------------------------------------
bool cAcqEasy::_SetSensorModeAndDigitalOutput(sAcqEasyParam *pAcqEasyParam)
{
	bool ret = true;
	enDigitalOutputChannel *pDigitalOutputChannel = NULL;
	WORD MaxNumberOfDigitalOutput = 0;
	
	// verify input parameter
	if (pAcqEasyParam == NULL)
	{
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "_ConfigureDigitalOutput:Bad Parameter (pAcqEasyParam)\n");	
#else
		sprintf_s(m_status_message, "_ConfigureDigitalOutput:Bad Parameter (pAcqEasyParam)\n");	
#endif			
		return(false);
	}
	// Configure digital output format
	if (MCHR_SetDigitalOutputFormat(m_chr_id, MCHR_BINARY) == MCHR_ERROR)
	{
		m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
		sprintf(m_status_message, "_ConfigureDigitalOutput:MCHR_SetDigitalOutputFormat: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
		sprintf_s(m_status_message, "_ConfigureDigitalOutput:MCHR_SetDigitalOutputFormat: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
		return(false);
	}
	if ((MCHR_GetMaxNumberOfTransmittedData(m_chr_id, &MaxNumberOfDigitalOutput) == MCHR_ERROR) || (MaxNumberOfDigitalOutput <= 0))
	{
		m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
		sprintf(m_status_message, "_ConfigureDigitalOutput:MCHR_GetMaxNumberOfTransmittedData: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
		sprintf_s(m_status_message, "_ConfigureDigitalOutput:MCHR_GetMaxNumberOfTransmittedData: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
		return(false);
	}	
	pDigitalOutputChannel = new enDigitalOutputChannel [MaxNumberOfDigitalOutput];
	memset (pDigitalOutputChannel, 0, sizeof (enDigitalOutputChannel) * (MaxNumberOfDigitalOutput));
	switch (pAcqEasyParam->SensorType)
	{
        case MCHR_150:
        case MCHR_450:
        case MCHR_XE:
        case MCHR_XE_E:
			if (pAcqEasyParam->EnableBufferTransmittedData.ChrDistance.BaryCenter || pAcqEasyParam->EnableBufferTransmittedData.ChrDistance.Distance || pAcqEasyParam->EnableBufferTransmittedData.ChrDistance.Intensity)
			{
				pAcqEasyParam->SensorMode = MCHR_DISTANCE_MODE;
				if (MaxNumberOfDigitalOutput >= ID_BUFFER_CHR_DISTANCE_MEASUREMENT_MAX)
				{
					pDigitalOutputChannel[ID_BUFFER_CHR_DISTANCE_DISTANCE] = (pAcqEasyParam->EnableBufferTransmittedData.ChrDistance.Distance) ?  MCHR_MAIN_SERIAL : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CHR_DISTANCE_INTENSITY] = (pAcqEasyParam->EnableBufferTransmittedData.ChrDistance.Intensity) ?  MCHR_MAIN_SERIAL : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CHR_DISTANCE_COUNTER] = MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CHR_DISTANCE_BARYCENTER] = (pAcqEasyParam->EnableBufferTransmittedData.ChrDistance.BaryCenter) ?  MCHR_MAIN_SERIAL : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CHR_DISTANCE_STATUS] = MCHR_NOT_TRANSMIT;
				}
				else
				{
					m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
					sprintf(m_status_message, "_ConfigureDigitalOutput: Bad MaxNumberOfDigitalOutput in MCHR_DISTANCE_MODE\n");
#else
					sprintf_s(m_status_message, "_ConfigureDigitalOutput: Bad MaxNumberOfDigitalOutput in MCHR_DISTANCE_MODE\n");
#endif
					ret = false;
				}
			}
			else if (pAcqEasyParam->EnableBufferTransmittedData.ChrThickness.BaryCenter1 || pAcqEasyParam->EnableBufferTransmittedData.ChrThickness.BaryCenter2 || pAcqEasyParam->EnableBufferTransmittedData.ChrThickness.Distance1 || pAcqEasyParam->EnableBufferTransmittedData.ChrThickness.Distance2 || pAcqEasyParam->EnableBufferTransmittedData.ChrThickness.Intensity1 || pAcqEasyParam->EnableBufferTransmittedData.ChrThickness.Intensity2 || pAcqEasyParam->EnableBufferTransmittedData.ChrThickness.Thickness)
			{
				pAcqEasyParam->SensorMode = MCHR_THICKNESS_MODE;
				if (MaxNumberOfDigitalOutput >= ID_BUFFER_CHR_THICKNESS_MEASUREMENT_MAX)
				{
					pDigitalOutputChannel[ID_BUFFER_CHR_THICKNESS_THICKNESS] = (pAcqEasyParam->EnableBufferTransmittedData.ChrThickness.Thickness) ?  MCHR_MAIN_SERIAL : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CHR_THICKNESS_DISTANCE1] = (pAcqEasyParam->EnableBufferTransmittedData.ChrThickness.Distance1) ?  MCHR_MAIN_SERIAL : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CHR_THICKNESS_DISTANCE2] = (pAcqEasyParam->EnableBufferTransmittedData.ChrThickness.Distance2) ?  MCHR_MAIN_SERIAL : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CHR_THICKNESS_STATUS] = MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CHR_THICKNESS_INTENSITY1] = (pAcqEasyParam->EnableBufferTransmittedData.ChrThickness.Intensity1) ?  MCHR_MAIN_SERIAL : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CHR_THICKNESS_INTENSITY2] = (pAcqEasyParam->EnableBufferTransmittedData.ChrThickness.Intensity2) ?  MCHR_MAIN_SERIAL : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CHR_THICKNESS_BARYCENTER1] = (pAcqEasyParam->EnableBufferTransmittedData.ChrThickness.BaryCenter1) ?  MCHR_MAIN_SERIAL : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CHR_THICKNESS_BARYCENTER2] = (pAcqEasyParam->EnableBufferTransmittedData.ChrThickness.BaryCenter2) ?  MCHR_MAIN_SERIAL : MCHR_NOT_TRANSMIT;
				}
				else
				{
					m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
					sprintf(m_status_message, "_ConfigureDigitalOutput: Bad MaxNumberOfDigitalOutput in MCHR_THICKNESS_MODE\n");
#else
					sprintf_s(m_status_message, "_ConfigureDigitalOutput: Bad MaxNumberOfDigitalOutput in MCHR_THICKNESS_MODE\n");
#endif
					ret = false;
				}
			}
			else
			{
				m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
				sprintf(m_status_message, "_GetSensorMode : Bad Parameter (SensorType or EnableBufferTransmittedData)\n");
#else
				sprintf_s(m_status_message, "_GetSensorMode : Bad Parameter (SensorType or EnableBufferTransmittedData)\n");
#endif
				ret = false;
			}
			break;
		case MCHR_CCS_ALPHA:
        case MCHR_CCS_OPTIMA:
        case MCHR_CCS_PRIMA:
        case MCHR_CCS_ULTIMA:
			if (pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.AutoAdaptativeModeData || pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.BaryCenter || pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.Counter || pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.Distance || pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.Encoder1 || pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.Encoder2 || pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.Encoder3 || pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.Intensity || pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.Status)
			{
				pAcqEasyParam->SensorMode = MCHR_DISTANCE_MODE;
				if (MaxNumberOfDigitalOutput >= ID_BUFFER_CCS_DISTANCE_MEASUREMENT_MAX)
				{
					pDigitalOutputChannel[ID_BUFFER_CCS_DISTANCE_DISTANCE_MSB] = (pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.Distance) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_DISTANCE_DISTANCE_LSB] = (pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.Distance) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_DISTANCE_AUTO_ADAPTATIVE_MODE] = (pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.AutoAdaptativeModeData) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_DISTANCE_INTENSITY] = (pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.Intensity) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_DISTANCE_BARYCENTER] = (pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.BaryCenter) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_DISTANCE_STATUS] = (pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.Status) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_DISTANCE_COUNTER] = (pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.Counter) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_DISTANCE_ENCODER1_MSB] = (pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.Encoder1) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_DISTANCE_ENCODER1_LSB] = (pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.Encoder1) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_DISTANCE_ENCODER2_MSB] = (pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.Encoder2) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_DISTANCE_ENCODER2_LSB] = (pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.Encoder2) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_DISTANCE_ENCODER3_MSB] = (pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.Encoder3) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_DISTANCE_ENCODER3_LSB] = (pAcqEasyParam->EnableBufferTransmittedData.CcsDistance.Encoder3) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
				}
				else
				{
					m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
					sprintf(m_status_message, "_ConfigureDigitalOutput: Bad MaxNumberOfDigitalOutput in MCHR_DISTANCE_MODE\n");
#else
					sprintf_s(m_status_message, "_ConfigureDigitalOutput: Bad MaxNumberOfDigitalOutput in MCHR_DISTANCE_MODE\n");
#endif
					ret = false;
				}
			}
			else if (pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.AutoAdaptativeModeData || pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.BaryCenter1 || pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.BaryCenter2 || pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Counter || pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Distance1 || pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Distance2 || pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Encoder1 || pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Encoder2 || pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Encoder3 || pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Intensity1)
			{
				pAcqEasyParam->SensorMode = MCHR_THICKNESS_MODE;
				if (MaxNumberOfDigitalOutput >= ID_BUFFER_CCS_THICKNESS_MEASUREMENT_MAX)
				{
					pDigitalOutputChannel[ID_BUFFER_CCS_THICKNESS_THICKNESS] = (pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Thickness) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_THICKNESS_DISTANCE1] = (pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Distance1) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_THICKNESS_DISTANCE2] = (pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Distance2) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_THICKNESS_AUTO_ADAPTATIVE_MODE] = (pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.AutoAdaptativeModeData) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_THICKNESS_INTENSITY1] = (pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Intensity1) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_THICKNESS_INTENSITY2] = (pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Intensity2) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_THICKNESS_BARYCENTER1] = (pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.BaryCenter1) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_THICKNESS_BARYCENTER2] = (pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.BaryCenter2) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_THICKNESS_STATUS] = (pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Status) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_THICKNESS_COUNTER] = (pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Counter) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_THICKNESS_ENCODER1_MSB] = (pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Encoder1) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_THICKNESS_ENCODER1_LSB] = (pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Encoder1) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_THICKNESS_ENCODER2_MSB] = (pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Encoder2) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_THICKNESS_ENCODER2_LSB] = (pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Encoder2) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_THICKNESS_ENCODER3_MSB] = (pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Encoder3) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_CCS_THICKNESS_ENCODER3_LSB] = (pAcqEasyParam->EnableBufferTransmittedData.CcsThickness.Encoder3) ?  MCHR_USB : MCHR_NOT_TRANSMIT;
				}
				else
				{
					m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
					sprintf(m_status_message, "_ConfigureDigitalOutput: Bad MaxNumberOfDigitalOutput in MCHR_THICKNESS_MODE\n");
#else
					sprintf_s(m_status_message, "_ConfigureDigitalOutput: Bad MaxNumberOfDigitalOutput in MCHR_THICKNESS_MODE\n");
#endif
					ret = false;
				}
			}
			else
			{
				m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
				sprintf(m_status_message, "_GetSensorMode : Bad Parameter (SensorType or EnableBufferTransmittedData)\n");
#else
				sprintf_s(m_status_message, "_GetSensorMode : Bad Parameter (SensorType or EnableBufferTransmittedData)\n");
#endif
				ret = false;
			}
			break;
		case MCHR_RUBY:
        case MCHR_DUO:
			if (pAcqEasyParam->EnableBufferTransmittedData.DuoDistance.BaryCenter || pAcqEasyParam->EnableBufferTransmittedData.DuoDistance.Counter || pAcqEasyParam->EnableBufferTransmittedData.DuoDistance.Distance || pAcqEasyParam->EnableBufferTransmittedData.DuoDistance.Intensity || pAcqEasyParam->EnableBufferTransmittedData.DuoDistance.Status)
			{
				pAcqEasyParam->SensorMode = MCHR_DISTANCE_MODE;
				if (MaxNumberOfDigitalOutput >= ID_BUFFER_DUO_DISTANCE_MEASUREMENT_MAX)
				{
					pDigitalOutputChannel[ID_BUFFER_DUO_DISTANCE_DISTANCE_MSB] = (pAcqEasyParam->EnableBufferTransmittedData.DuoDistance.Distance) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_DISTANCE_DISTANCE_LSB] = (pAcqEasyParam->EnableBufferTransmittedData.DuoDistance.Distance) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_DISTANCE_INTENSITY] = (pAcqEasyParam->EnableBufferTransmittedData.DuoDistance.Intensity) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_DISTANCE_COUNTER] = (pAcqEasyParam->EnableBufferTransmittedData.DuoDistance.Counter) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_DISTANCE_BARYCENTER] = (pAcqEasyParam->EnableBufferTransmittedData.DuoDistance.BaryCenter) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_DISTANCE_STATUS] = (pAcqEasyParam->EnableBufferTransmittedData.DuoDistance.Status) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
				}
				else
				{
					m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
					sprintf(m_status_message, "_ConfigureDigitalOutput: Bad MaxNumberOfDigitalOutput in MCHR_DISTANCE_MODE\n");
#else
					sprintf_s(m_status_message, "_ConfigureDigitalOutput: Bad MaxNumberOfDigitalOutput in MCHR_DISTANCE_MODE\n");
#endif
					ret = false;
				}
			}
			else if (pAcqEasyParam->EnableBufferTransmittedData.DuoThickness.BaryCenter1 || pAcqEasyParam->EnableBufferTransmittedData.DuoThickness.BaryCenter2 || pAcqEasyParam->EnableBufferTransmittedData.DuoThickness.Counter || pAcqEasyParam->EnableBufferTransmittedData.DuoThickness.Distance1 || pAcqEasyParam->EnableBufferTransmittedData.DuoThickness.Distance2 || pAcqEasyParam->EnableBufferTransmittedData.DuoThickness.Intensity1 || pAcqEasyParam->EnableBufferTransmittedData.DuoThickness.Intensity2 || pAcqEasyParam->EnableBufferTransmittedData.DuoThickness.Status || pAcqEasyParam->EnableBufferTransmittedData.DuoThickness.Thickness)
			{
				pAcqEasyParam->SensorMode = MCHR_THICKNESS_MODE;
				if (MaxNumberOfDigitalOutput >= ID_BUFFER_DUO_THICKNESS_MEASUREMENT_MAX)
				{
					pDigitalOutputChannel[ID_BUFFER_DUO_THICKNESS_THICKNESS] = (pAcqEasyParam->EnableBufferTransmittedData.DuoThickness.Thickness) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_THICKNESS_DISTANCE1] = (pAcqEasyParam->EnableBufferTransmittedData.DuoThickness.Distance1) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_THICKNESS_DISTANCE2] = (pAcqEasyParam->EnableBufferTransmittedData.DuoThickness.Distance2) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_THICKNESS_COUNTER] = (pAcqEasyParam->EnableBufferTransmittedData.DuoThickness.Counter) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_THICKNESS_INTENSITY1] = (pAcqEasyParam->EnableBufferTransmittedData.DuoThickness.Intensity1) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_THICKNESS_INTENSITY2] = (pAcqEasyParam->EnableBufferTransmittedData.DuoThickness.Intensity2) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_THICKNESS_BARYCENTER1] = (pAcqEasyParam->EnableBufferTransmittedData.DuoThickness.BaryCenter1) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_THICKNESS_BARYCENTER2] = (pAcqEasyParam->EnableBufferTransmittedData.DuoThickness.BaryCenter2) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_THICKNESS_STATUS] = (pAcqEasyParam->EnableBufferTransmittedData.DuoThickness.Status) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
				}
				else
				{
					m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
					sprintf(m_status_message, "_ConfigureDigitalOutput: Bad MaxNumberOfDigitalOutput in MCHR_THICKNESS_MODE\n");
#else
					sprintf_s(m_status_message, "_ConfigureDigitalOutput: Bad MaxNumberOfDigitalOutput in MCHR_THICKNESS_MODE\n");
#endif
					ret = false;
				}
			}
			else if (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliDistance.Counter || pAcqEasyParam->EnableBufferTransmittedData.DuoSawliDistance.Distance || pAcqEasyParam->EnableBufferTransmittedData.DuoSawliDistance.Intensity || pAcqEasyParam->EnableBufferTransmittedData.DuoSawliDistance.Intensity || pAcqEasyParam->EnableBufferTransmittedData.DuoSawliDistance.Quality || pAcqEasyParam->EnableBufferTransmittedData.DuoSawliDistance.Status)
			{
				pAcqEasyParam->SensorMode = MCHR_SAWLI_DISTANCE_MODE;
				if (MaxNumberOfDigitalOutput >= ID_BUFFER_DUO_SAWLI_DISTANCE_MEASUREMENT_MAX)
				{
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_DISTANCE_DISTANCE_MSB] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliDistance.Distance) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_DISTANCE_DISTANCE_LSB] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliDistance.Distance) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_DISTANCE_QUALITY] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliDistance.Quality) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_DISTANCE_INTENSITY] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliDistance.Intensity) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_DISTANCE_COUNTER] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliDistance.Counter) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_DISTANCE_STATUS] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliDistance.Status) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
				}
				else
				{
					m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
					sprintf(m_status_message, "_ConfigureDigitalOutput: Bad MaxNumberOfDigitalOutput in MCHR_SAWLI_DISTANCE_MODE\n");
#else
					sprintf_s(m_status_message, "_ConfigureDigitalOutput: Bad MaxNumberOfDigitalOutput in MCHR_SAWLI_DISTANCE_MODE\n");
#endif
					ret = false;
				}
			}
			else if (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Counter || pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Intensity || pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.NbThickness || pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Quality1 || pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Quality2 || pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Quality3 || pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Status || pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Thickness1 || pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Thickness2 || pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Thickness3)
			{
				pAcqEasyParam->SensorMode = MCHR_SAWLI_THICKNESS_MODE;
				if (MaxNumberOfDigitalOutput >= ID_BUFFER_DUO_SAWLI_THICKNESS_MEASUREMENT_MAX)
				{
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS1_MSB] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Thickness1) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS1_LSB] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Thickness1) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS2_MSB] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Thickness2) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS2_LSB] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Thickness2) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS3_MSB] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Thickness3) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS3_LSB] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Thickness3) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_THICKNESS_QUALITY1] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Quality1) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_THICKNESS_QUALITY2] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Quality2) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_THICKNESS_QUALITY3] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Quality3) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_THICKNESS_INTENSITY] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Intensity) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_THICKNESS_NB_THICKNESS] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.NbThickness) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_THICKNESS_COUNTER] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Counter) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
					pDigitalOutputChannel[ID_BUFFER_DUO_SAWLI_THICKNESS_STATUS] = (pAcqEasyParam->EnableBufferTransmittedData.DuoSawliThickness.Status) ?  MCHR_ETHERNET : MCHR_NOT_TRANSMIT;
				}
				else
				{
					m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
					sprintf(m_status_message, "_ConfigureDigitalOutput: Bad MaxNumberOfDigitalOutput in MCHR_SAWLI_THICKNESS_MODE\n");
#else
					sprintf_s(m_status_message, "_ConfigureDigitalOutput: Bad MaxNumberOfDigitalOutput in MCHR_SAWLI_THICKNESS_MODE\n");
#endif
					ret = false;
				}
			}
			else
			{
				m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
				sprintf(m_status_message, "_GetSensorMode : Bad Parameter (SensorType or EnableBufferTransmittedData)\n");
#else
				sprintf_s(m_status_message, "_GetSensorMode : Bad Parameter (SensorType or EnableBufferTransmittedData)\n");
#endif
				ret = false;
			}
			break;
		default :
			m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
			sprintf(m_status_message, "_GetSensorMode : Bad Parameter (SensorType)\n");
#else
			sprintf_s(m_status_message, "_GetSensorMode : Bad Parameter (SensorType)\n");
#endif
			ret = false;
			break;
	}
	//set sensor mode
	if (ret)
	{
		if (MCHR_SetMeasureMode (m_chr_id, pAcqEasyParam->SensorMode) == MCHR_ERROR)
		{
			m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
			sprintf(m_status_message, "_ConfigureSensorMode:MCHR_SetMeasureMode: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
			sprintf_s(m_status_message, "_ConfigureSensorMode:MCHR_SetMeasureMode: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
			ret = false;
		}
	}
	//set digital output
	if (ret)
	{
		if (MCHR_SetTransmittedDigitalOutput(m_chr_id, pDigitalOutputChannel) == MCHR_ERROR)
		{
			m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
			sprintf(m_status_message, "_ConfigureSensorMode:MCHR_SetTransmittedDigitalOutput: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
			sprintf_s(m_status_message, "_ConfigureSensorMode:MCHR_SetTransmittedDigitalOutput: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
			ret = false;
		}
	}
	if (pDigitalOutputChannel != NULL)
	{
		delete[] pDigitalOutputChannel;
		pDigitalOutputChannel = NULL;
	}
	return(ret);
}
//-------------------------------------------------------------------------------------------------
bool cAcqEasy::StartAcquisition(sAcqEasyParam acqEasyParam)
{
	int idx = 0, jdx = 0;
	bool ret = true;

	//bad parameters
	if ((acqEasyParam.NumberOfBuffers <= 0) || (acqEasyParam.BufferLength <= 0))
	{
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "StartAcquisition:Bad Parameters\n");
#else
		sprintf_s(m_status_message, "StartAcquisition:Bad Parameters\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}
		return(false);
	}
	//verify frequency
	if (acqEasyParam.Frequency == 0)
	{
		m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
		sprintf(m_status_message, "StartAcquisition:The frequency must be greater than zero\n");
#else
		sprintf_s(m_status_message, "StartAcquisition:The frequency must be greater than zero\n");
#endif
		if (m_status_event != NULL)
		{
			SetEvent(m_status_event);
		}
		return(false);
	}
	//Already starting ?
	if (m_IsDataAcquisitionStarting)
	{
		StopAcquisition();
	}
	//starting
	criticalBuffer.Lock();
	memcpy(&m_acqEasyParam, &acqEasyParam, sizeof(sAcqEasyParam));
	ZeroMemory(&m_acqParam, sizeof(MCHR_tyAcqParam));
	m_acqParam.NumberOfBuffers = m_acqEasyParam.NumberOfBuffers;
	m_acqParam.BufferLength = m_acqEasyParam.BufferLength;	
	m_acqParam.NumberPointsTRE = m_acqEasyParam.NumberPointsTRE;
	m_acqParam.TriggerFlag = m_acqEasyParam.Trigger.Enable;
	m_acqParam.TriggerType = m_acqEasyParam.Trigger.Type;
	m_acqParam.HighLevelOrRisingEdgeActivated = m_acqEasyParam.Trigger.Level;
	m_acqParam.NumberOfPoints = m_acqEasyParam.NumberOfPoints;
	switch(m_acqEasyParam.TypeEvent)
	{
		case EV_ACQUIRE_N_POINTS: //EV_ACQUIRE_N_POINTS				
			m_acqParam.EventEndBuffer = m_OnEventAcquisition[EVENT_ACQUIRE_N_POINTS];
			break;
		case EV_END_MEASUREMENTS: //EV_END_MEASUREMENTS				
			m_acqParam.EventEndMeasurement = m_OnEventAcquisition[EVENT_END_MEASUREMENT];
			break;
		case EV_END_ACQUIRE: //EV_END_ACQUIRE				
			m_acqParam.EventEndAcquire = m_OnEventAcquisition[EVENT_END_ACQUIRE];
			break;
		default : //EV_END_BUFFER
			m_acqParam.EventEndBuffer = m_OnEventAcquisition[EVENT_END_BUFFER];
			break;
	}
	_CreateAcqBuffer( m_acqParam.NumberOfBuffers, m_acqEasyParam.BufferLength);
	//encoder settings
	if ((m_acqEasyParam.EnableBufferEncoder.Encoder1) || (m_acqEasyParam.EnableBufferEncoder.Encoder2) || (m_acqEasyParam.EnableBufferEncoder.Encoder3))
	{
		//encoder buffer initialization
		ret = (MCHR_SetEncoderBuffer (m_chr_id, (m_acqEasyParam.EnableBufferEncoder.Encoder1) ? m_ppEncoderBuffer[ID_BUFFER_ENCODER_1] : NULL,
											(m_acqEasyParam.EnableBufferEncoder.Encoder2) ? m_ppEncoderBuffer[ID_BUFFER_ENCODER_2] : NULL,
											(m_acqEasyParam.EnableBufferEncoder.Encoder3) ? m_ppEncoderBuffer[ID_BUFFER_ENCODER_3] : NULL) != MCHR_ERROR);
		if (!ret)
		{
			m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
			sprintf(m_status_message, "StartAcquisition:MCHR_SetEncoderBuffer: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
			sprintf_s(m_status_message, "StartAcquisition:MCHR_SetEncoderBuffer: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
		}
	}
	if (ret)
	{
		//auto adaptative settings
		if (m_acqEasyParam.EnableBufferAutoAdaptive)
		{
			//auto adaptative buffer initialization
			ret = (MCHR_SetAutoAdaptiveBuffer (m_chr_id, (m_acqEasyParam.EnableBufferAutoAdaptive) ? m_ppAutoAdaptativeBuffer : NULL) != MCHR_ERROR);
			if (!ret)
			{
				m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
				sprintf(m_status_message, "StartAcquisition:MCHR_SetAutoAdaptiveBuffer: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
				sprintf_s(m_status_message, "StartAcquisition:MCHR_SetAutoAdaptiveBuffer: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
			}
		}
	}
	if (ret)
	{
		//acquisition settings
		switch(m_acqEasyParam.typeAcquisition)
		{
			//MCHR_GetThicknessMeasurement
			case eMCHR_GetThicknessMeasurement : 				
				ret = (MCHR_GetThicknessMeasurement  (m_chr_id, m_acqParam,	
														(m_acqEasyParam.EnableBufferThickness.Thickness) ? m_ppAcqBuffer[ID_BUFFER_THICKNESS_THICKNESS] : NULL, 
														(m_acqEasyParam.EnableBufferThickness.Distance1) ? m_ppAcqBuffer[ID_BUFFER_THICKNESS_DISTANCE1] : NULL, 
														(m_acqEasyParam.EnableBufferThickness.Intensity1) ? m_ppAcqBuffer[ID_BUFFER_THICKNESS_INTENSITY1] : NULL, 
														(m_acqEasyParam.EnableBufferThickness.BaryCenter1) ? m_ppAcqBuffer[ID_BUFFER_THICKNESS_BARYCENTER1] : NULL, 
														(m_acqEasyParam.EnableBufferThickness.Distance2) ? m_ppAcqBuffer[ID_BUFFER_THICKNESS_DISTANCE2] : NULL, 
														(m_acqEasyParam.EnableBufferThickness.Intensity2) ? m_ppAcqBuffer[ID_BUFFER_THICKNESS_INTENSITY2] : NULL, 
														(m_acqEasyParam.EnableBufferThickness.BaryCenter2) ? m_ppAcqBuffer[ID_BUFFER_THICKNESS_BARYCENTER2] : NULL, 
														(m_acqEasyParam.EnableBufferThickness.Status) ? m_ppAcqBuffer[ID_BUFFER_THICKNESS_STATUS] : NULL, 
														(m_acqEasyParam.EnableBufferThickness.Counter) ? m_ppAcqBuffer[ID_BUFFER_THICKNESS_COUNTER] : NULL
														) != MCHR_ERROR);
				if (!ret)
				{
					m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
				sprintf(m_status_message, "StartAcquisition:MCHR_GetThicknessMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
				sprintf_s(m_status_message, "StartAcquisition:MCHR_GetThicknessMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
				}
				break;
			//MCHR_GetAltitudeMeasurement
			case eMCHR_GetAltitudeMeasurement : 
				ret = (MCHR_GetAltitudeMeasurement  (m_chr_id, m_acqParam,	
														(m_acqEasyParam.EnableBufferAltitude.Altitude) ? m_ppAcqBuffer[ID_BUFFER_ALTITUDE_ALTITUDE] : NULL, 
														(m_acqEasyParam.EnableBufferAltitude.Intensity) ? m_ppAcqBuffer[ID_BUFFER_ALTITUDE_INTENSITY] : NULL, 
														(m_acqEasyParam.EnableBufferAltitude.Counter) ? m_ppAcqBuffer[ID_BUFFER_ALTITUDE_COUNTER] : NULL, 
														(m_acqEasyParam.EnableBufferAltitude.BaryCenter) ? m_ppAcqBuffer[ID_BUFFER_ALTITUDE_BARYCENTER] : NULL, 
														(m_acqEasyParam.EnableBufferAltitude.Status) ? m_ppAcqBuffer[ID_BUFFER_ALTITUDE_STATUS] : NULL
														) != MCHR_ERROR);
														
				if (!ret)
				{
					m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
				sprintf(m_status_message, "StartAcquisition:MCHR_GetAltitudeMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
				sprintf_s(m_status_message, "StartAcquisition:MCHR_GetAltitudeMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
				}
				break;
			//MCHR_GetDepthMeasurement
			case eMCHR_GetDepthMeasurement : 
				ret = (MCHR_GetDepthMeasurement (m_chr_id, m_acqParam,	
														(m_acqEasyParam.EnableBufferDepth.Depth) ? m_ppAcqBuffer[ID_BUFFER_DEPTH_DEPTH] : NULL, 
														(m_acqEasyParam.EnableBufferDepth.Intensity) ? m_ppAcqBuffer[ID_BUFFER_DEPTH_INTENSITY] : NULL, 
														(m_acqEasyParam.EnableBufferDepth.Counter) ? m_ppAcqBuffer[ID_BUFFER_DEPTH_COUNTER] : NULL, 
														(m_acqEasyParam.EnableBufferDepth.BaryCenter) ? m_ppAcqBuffer[ID_BUFFER_DEPTH_BARYCENTER] : NULL, 
														(m_acqEasyParam.EnableBufferDepth.Status) ? m_ppAcqBuffer[ID_BUFFER_DEPTH_STATUS] : NULL
														) != MCHR_ERROR);
				if (!ret)
				{
					m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
				sprintf(m_status_message, "StartAcquisition:MCHR_GetDepthMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
				sprintf_s(m_status_message, "StartAcquisition:MCHR_GetDepthMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
				}
			break;		
			//MCHR_GetInterferometricThickness
			case eMCHR_GetInterferometricThickness:
				ret = (MCHR_GetInterferometricThickness(m_chr_id, m_acqParam,
														(m_acqEasyParam.EnableBufferInterferometricThickness.Thickness1) ? m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_THICKNESS1] : NULL, 
														(m_acqEasyParam.EnableBufferInterferometricThickness.Thickness2) ? m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_THICKNESS2] : NULL, 
														(m_acqEasyParam.EnableBufferInterferometricThickness.Thickness3) ? m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_THICKNESS3] : NULL, 
														(m_acqEasyParam.EnableBufferInterferometricThickness.Quality1) ? m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_QUALITY1] : NULL, 
														(m_acqEasyParam.EnableBufferInterferometricThickness.Quality2) ? m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_QUALITY2] : NULL, 
														(m_acqEasyParam.EnableBufferInterferometricThickness.Quality3) ? m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_QUALITY3] : NULL, 
														(m_acqEasyParam.EnableBufferInterferometricThickness.Intensity) ? m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_INTENSITY] : NULL
														) != MCHR_ERROR); 
				if (!ret)
				{
					m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
				sprintf(m_status_message, "StartAcquisition:MCHR_GetInterferometricThickness: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
				sprintf_s(m_status_message, "StartAcquisition:MCHR_GetInterferometricThickness: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
				}											
				break;
			//MCHR_GetInterferometricThicknessSAWLI
			case eMCHR_GetInterferometricThicknessSAWLI:
					ret = (MCHR_GetInterferometricThicknessSAWLI(m_chr_id, m_acqParam,
														(m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Thickness1) ? m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_THICKNESS1] : NULL, 
														(m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Thickness2) ? m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_THICKNESS2] : NULL, 
														(m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Thickness3) ? m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_THICKNESS3] : NULL, 
														(m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Quality1) ? m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_QUALITY1] : NULL, 
														(m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Quality2) ? m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_QUALITY2] : NULL, 
														(m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Quality3) ? m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_QUALITY3] : NULL, 
														(m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Intensity) ? m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_INTENSITY] : NULL,
														(m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Thickness) ? m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_THICKNESS] : NULL,
														(m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Counter) ? m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_COUNTER] : NULL,
														(m_acqEasyParam.EnableBufferInterferometricThicknessSAWLI.Status) ? m_ppAcqBuffer[ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_STATUS] : NULL
														) != MCHR_ERROR); 
				if (!ret)
				{
					m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
				sprintf(m_status_message, "StartAcquisition:MCHR_GetInterferometricThicknessSAWLI: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
				sprintf_s(m_status_message, "StartAcquisition:MCHR_GetInterferometricThicknessSAWLI: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
				}											
				break;
			//MCHR_GetTransmittedDataMeasurement
			case eMCHR_GetTransmittedDataMeasurement : 
				//Automatic mode setting				
				ret = _SetSensorModeAndDigitalOutput(&m_acqEasyParam);				
				if (!ret)
				{
#ifdef _VC6_
					sprintf(m_status_message, "StartAcquisition: SensorMode : Impossible to determine the sensor mode.\n");
#else
					sprintf_s(m_status_message, "StartAcquisition: SensorMode : Impossible to determine the sensor mode.\n");
#endif
					break;
				}
				//Sensor Type
				switch (m_acqEasyParam.SensorType)
				{
                                    case MCHR_150:
                                    case MCHR_450:
                                    case MCHR_XE:
                                    case MCHR_XE_E:
										if (m_acqEasyParam.SensorMode == MCHR_DISTANCE_MODE)
										{									
											ret = (MCHR_GetTransmittedDataMeasurement(m_chr_id, m_acqParam,	
																					(m_acqEasyParam.EnableBufferTransmittedData.ChrDistance.Distance) ? m_ppAcqBuffer[ID_BUFFER_CHR_DISTANCE_DISTANCE] : NULL, 
																					NULL,NULL,
																					(m_acqEasyParam.EnableBufferTransmittedData.ChrDistance.Intensity) ? m_ppAcqBuffer[ID_BUFFER_CHR_DISTANCE_INTENSITY] : NULL, 
																					NULL,
																					NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.ChrDistance.BaryCenter) ? m_ppAcqBuffer[ID_BUFFER_CHR_DISTANCE_BARYCENTER] : NULL, 
																					NULL, 
																					NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
																					) != MCHR_ERROR);																					
																					if (!ret)
																					{
																						m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
																						sprintf(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
																						sprintf_s(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
																					}
										}
										else if (m_acqEasyParam.SensorMode == MCHR_THICKNESS_MODE)
										{
											ret = (MCHR_GetTransmittedDataMeasurement(m_chr_id, m_acqParam,	
																					(m_acqEasyParam.EnableBufferTransmittedData.ChrThickness.Thickness) ? m_ppAcqBuffer[ID_BUFFER_CHR_THICKNESS_THICKNESS] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.ChrThickness.Distance1) ? m_ppAcqBuffer[ID_BUFFER_CHR_THICKNESS_DISTANCE1] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.ChrThickness.Distance2) ? m_ppAcqBuffer[ID_BUFFER_CHR_THICKNESS_DISTANCE2] : NULL, 
																					NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.ChrThickness.Intensity1) ? m_ppAcqBuffer[ID_BUFFER_CHR_THICKNESS_INTENSITY1] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.ChrThickness.Intensity2) ? m_ppAcqBuffer[ID_BUFFER_CHR_THICKNESS_INTENSITY2] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.ChrThickness.BaryCenter1) ? m_ppAcqBuffer[ID_BUFFER_CHR_THICKNESS_BARYCENTER1] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.ChrThickness.BaryCenter2) ? m_ppAcqBuffer[ID_BUFFER_CHR_THICKNESS_BARYCENTER2] : NULL, 
																					NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
																					) != MCHR_ERROR);
																					if (!ret)
																					{
																						m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
																						sprintf(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
																						sprintf_s(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
																					}
										}
										else
										{
											m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
											sprintf(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement:(SensorType or SensorMode) Bad Parameters\n");
#else
											sprintf_s(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement:(SensorType or SensorMode) Bad Parameters\n");
#endif
											ret = FALSE;
										}
										break;
									case MCHR_CCS_ALPHA:
                                    case MCHR_CCS_OPTIMA:
                                    case MCHR_CCS_PRIMA:
                                    case MCHR_CCS_ULTIMA:
                                    case MCHR_CCS_INITIAL:
										if (m_acqEasyParam.SensorMode == MCHR_DISTANCE_MODE)
										{
											ret = (MCHR_GetTransmittedDataMeasurement(m_chr_id, m_acqParam,	
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.Distance) ? m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_DISTANCE_MSB] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.Distance) ? m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_DISTANCE_MSB] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.AutoAdaptativeModeData) ? m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_AUTO_ADAPTATIVE_MODE] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.Intensity) ? m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_INTENSITY] : NULL, 
																					NULL, NULL,
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.BaryCenter) ? m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_BARYCENTER] : NULL, 
																					NULL,
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.Status) ? m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_STATUS] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.Counter) ? m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_COUNTER] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.Encoder1) ? m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_ENCODER1_LSB] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.Encoder1) ? m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_ENCODER1_MSB] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.Encoder2) ? m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_ENCODER2_LSB] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.Encoder2) ? m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_ENCODER2_MSB] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.Encoder3) ? m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_ENCODER3_LSB] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsDistance.Encoder3) ? m_ppAcqBuffer[ID_BUFFER_CCS_DISTANCE_ENCODER3_MSB] : NULL																	
																					) != MCHR_ERROR);
																					if (!ret)
																					{
																						m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
																						sprintf(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
																						sprintf_s(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
																					}
										}
										else if (m_acqEasyParam.SensorMode == MCHR_THICKNESS_MODE)
										{
											ret = (MCHR_GetTransmittedDataMeasurement(m_chr_id, m_acqParam,	
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Thickness) ? m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_THICKNESS] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Distance1) ? m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_DISTANCE1] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Distance2) ? m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_DISTANCE2] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.AutoAdaptativeModeData) ? m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_AUTO_ADAPTATIVE_MODE] : NULL, 																					
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Intensity1) ? m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_INTENSITY1] : NULL, 																					
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Intensity2) ? m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_INTENSITY2] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.BaryCenter1) ? m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_BARYCENTER1] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.BaryCenter2) ? m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_BARYCENTER2] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Status) ? m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_STATUS] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Counter) ? m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_COUNTER] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Encoder1) ? m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_ENCODER1_LSB] : NULL, 																					
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Encoder1) ? m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_ENCODER1_MSB] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Encoder2) ? m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_ENCODER2_LSB] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Encoder2) ? m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_ENCODER2_MSB] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Encoder3) ? m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_ENCODER3_LSB] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.CcsThickness.Encoder3) ? m_ppAcqBuffer[ID_BUFFER_CCS_THICKNESS_ENCODER3_MSB] : NULL																	
																					) != MCHR_ERROR);
																					if (!ret)
																					{
																						m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
																						sprintf(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
																						sprintf_s(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
																					}
										}
										else
										{
											m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
											sprintf(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement:(SensorType) Bad Parameters\n");
#else
											sprintf_s(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement:(SensorType) Bad Parameters\n");
#endif
											ret = FALSE;
										}
										break;
                                    case MCHR_RUBY:
                                    case MCHR_DUO:
										if (m_acqEasyParam.SensorMode == MCHR_DISTANCE_MODE)
										{
 											ret = (MCHR_GetTransmittedDataMeasurement(m_chr_id, m_acqParam,	
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoDistance.Distance) ? m_ppAcqBuffer[ID_BUFFER_DUO_DISTANCE_DISTANCE_MSB] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoDistance.Distance) ? m_ppAcqBuffer[ID_BUFFER_DUO_DISTANCE_DISTANCE_MSB] : NULL, 
																					NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoDistance.Intensity) ? m_ppAcqBuffer[ID_BUFFER_DUO_DISTANCE_INTENSITY] : NULL, 																					
																					NULL, 																					
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoDistance.Counter) ? m_ppAcqBuffer[ID_BUFFER_DUO_DISTANCE_COUNTER] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoDistance.BaryCenter) ? m_ppAcqBuffer[ID_BUFFER_DUO_DISTANCE_BARYCENTER] : NULL, 
																					NULL, NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoDistance.Status) ? m_ppAcqBuffer[ID_BUFFER_DUO_DISTANCE_STATUS] : NULL, 
																					NULL, NULL, NULL, NULL, NULL, NULL																	
																					) != MCHR_ERROR);
																					if (!ret)
																					{
																						m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
																						sprintf(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
																						sprintf_s(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
																					}
										}
										else if (m_acqEasyParam.SensorMode == MCHR_THICKNESS_MODE)
										{
												ret = (MCHR_GetTransmittedDataMeasurement(m_chr_id, m_acqParam,	
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoThickness.Thickness) ? m_ppAcqBuffer[ID_BUFFER_DUO_THICKNESS_THICKNESS] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoThickness.Distance1) ? m_ppAcqBuffer[ID_BUFFER_DUO_THICKNESS_DISTANCE1] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoThickness.Distance2) ? m_ppAcqBuffer[ID_BUFFER_DUO_THICKNESS_DISTANCE2] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoThickness.Counter) ? m_ppAcqBuffer[ID_BUFFER_DUO_THICKNESS_COUNTER] : NULL, 																					
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoThickness.Intensity1) ? m_ppAcqBuffer[ID_BUFFER_DUO_THICKNESS_INTENSITY1] : NULL, 																					
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoThickness.Intensity2) ? m_ppAcqBuffer[ID_BUFFER_DUO_THICKNESS_INTENSITY2] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoThickness.BaryCenter1) ? m_ppAcqBuffer[ID_BUFFER_DUO_THICKNESS_BARYCENTER1] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoThickness.BaryCenter2) ? m_ppAcqBuffer[ID_BUFFER_DUO_THICKNESS_BARYCENTER2] : NULL, 
																					NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoThickness.Status) ? m_ppAcqBuffer[ID_BUFFER_DUO_THICKNESS_STATUS] : NULL, 
																					NULL, NULL, NULL, NULL, NULL, NULL																		
																					) != MCHR_ERROR);
																					if (!ret)
																					{
																						m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
																						sprintf(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
																						sprintf_s(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
																					}
										}
										else if (m_acqEasyParam.SensorMode == MCHR_SAWLI_DISTANCE_MODE)
										{    
											ret = (MCHR_GetTransmittedDataMeasurement(m_chr_id, m_acqParam,	
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliDistance.Distance) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_DISTANCE_DISTANCE_MSB] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliDistance.Distance) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_DISTANCE_DISTANCE_MSB] : NULL, 
																					NULL, NULL, NULL, NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliDistance.Quality) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_DISTANCE_QUALITY] : NULL, 
																					NULL, NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliDistance.Intensity) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_DISTANCE_INTENSITY] : NULL, 																					
																					NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliDistance.Counter) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_DISTANCE_COUNTER] : NULL, 																					
																					NULL, NULL, NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliDistance.Status) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_DISTANCE_STATUS] : NULL
																					) != MCHR_ERROR);
																					if (!ret)
																					{
																						m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
																						sprintf(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
																						sprintf_s(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
																					}
										}
										else if (m_acqEasyParam.SensorMode == MCHR_SAWLI_THICKNESS_MODE)
										{
											ret = (MCHR_GetTransmittedDataMeasurement(m_chr_id, m_acqParam,	
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Thickness1) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS1_MSB] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Thickness1) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS1_MSB] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Thickness2) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS2_MSB] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Thickness2) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS2_MSB] : NULL, 																					
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Thickness3) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS3_MSB] : NULL, 																					
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Thickness3) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS3_MSB] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Quality1) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_QUALITY1] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Quality2) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_QUALITY2] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Quality3) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_QUALITY3] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Intensity) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_INTENSITY] : NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.NbThickness) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_NB_THICKNESS] : NULL, 																					
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Counter) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_COUNTER] : NULL, 
																					NULL, NULL, NULL, 
																					(m_acqEasyParam.EnableBufferTransmittedData.DuoSawliThickness.Status) ? m_ppAcqBuffer[ID_BUFFER_DUO_SAWLI_THICKNESS_STATUS] : NULL																	
																					) != MCHR_ERROR);
																					if (!ret)
																					{
																						m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
																						sprintf(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
																						sprintf_s(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
																					}
										}
										else
										{
											m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
																					sprintf(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement:(SensorType) Bad Parameters\n");
#else
																					sprintf_s(m_status_message, "StartAcquisition:MCHR_GetTransmittedDataMeasurement:(SensorType) Bad Parameters\n");
#endif	
											ret = FALSE;
										}
										break;
									default:
										m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
										sprintf(m_status_message, "StartAcquisition:(SensorType) Bad Parameters\n");
#else
										sprintf_s(m_status_message, "StartAcquisition:(SensorType) Bad Parameters\n");
#endif
										ret = FALSE;
										break;

				}														
				break;
			default :
				m_status_acquisition = STATUS_PARAM_ERROR;
#ifdef _VC6_
				sprintf(m_status_message, "StartAcquisition:(typeAcquisition) Bad Parameters\n");
#else
				sprintf_s(m_status_message, "StartAcquisition:(typeAcquisition) Bad Parameters\n");
#endif
				ret = FALSE;
				break;
		}
	}
	m_IsDataAcquisitionStarting = ret;
	criticalBuffer.Unlock();	
	if ((m_status_acquisition != STATUS_NO_ERROR) && (m_status_event != NULL))
	{
		SetEvent(m_status_event);		
	}
	return(ret);
}
//--------------------------------------------------------------------
short cAcqEasy::GetStatusAcquisition(char *pMessage)
{
	if (pMessage != NULL)
	{
#ifdef _VC6_
		strcpy(pMessage, m_status_message);
#else
		strcpy_s(pMessage, MAX_CHAR, m_status_message);
#endif
	}
	short status = m_status_acquisition;
	m_status_acquisition = STATUS_NO_ERROR;
	return(status);
}
//--------------------------------------------------------------------





//-------------------------------------------------------------------------------------------------
bool cAcqEasy::StartSpectrumAcquisition(unsigned short **ppSpectrum, unsigned short *pFirstUsablePixel, unsigned short *pBufferSize)
{
	bool ret = true;

	// Configure Spectrum Mode
	if (MCHR_SetSpectrumMode(m_chr_id, 1) == MCHR_ERROR)
	{
		m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
		sprintf(m_status_message, "StartAcquisition:MCHR_SetSpectrumMode: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
		sprintf_s(m_status_message, "StartAcquisition:MCHR_SetSpectrumMode: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
		ret = false;
	}	
	else
	{		
		if (MCHR_StartSpectrumAcquisition(m_chr_id, pFirstUsablePixel, pBufferSize) == MCHR_ERROR)
		{
			m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
			sprintf(m_status_message, "StartAcquisition:MCHR_StartSpectrumAcquisition: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
			sprintf_s(m_status_message, "StartAcquisition:MCHR_StartSpectrumAcquisition: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
			ret = false;	
		}
		*ppSpectrum = new unsigned short[*pBufferSize];
	}
	m_IsSpectrumAcquisitionStarting = ret;
	return(ret);

}
//-------------------------------------------------------------------------------------------------
bool cAcqEasy::StopSpectrumAcquisition(unsigned short **ppSpectrum)
{
	bool ret = true;
	
	if (MCHR_StopSpectrumAcquisition(m_chr_id) == MCHR_ERROR)
	{
		m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
		sprintf(m_status_message, "StopSpectrumAcquisition:MCHR_StopSpectrumAcquisition: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
		sprintf_s(m_status_message, "StopSpectrumAcquisition:MCHR_StopSpectrumAcquisition: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
		ret = false;
	}
	else
	{
		if (MCHR_SetSpectrumMode(m_chr_id, 0) == MCHR_ERROR)
		{
			m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
			sprintf(m_status_message, "StopSpectrumAcquisition:MCHR_SetSpectrumMode: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
			sprintf_s(m_status_message, "StopSpectrumAcquisition:MCHR_SetSpectrumMode: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
			ret = false;
		}	
	}
	if (*ppSpectrum != NULL)
	{
		delete[] *ppSpectrum;
		*ppSpectrum = NULL;
	}
	return(ret);
}
//--------------------------------------------------------------------
bool cAcqEasy::GetSpectrumAcquisition(unsigned short *pSpectrum, unsigned short DataSize, unsigned short *pCounter, enSpectrumAcquisitionResult *pSpectrumAcquisitionResult, int timeout)
{
	bool ret = true;
	
	if (MCHR_GetSpectrumAcquisitionData(m_chr_id, pSpectrum, DataSize, pCounter, pSpectrumAcquisitionResult, timeout) == MCHR_ERROR)
	{
		m_status_acquisition = STATUS_MCHR_FUNCTION;
#ifdef _VC6_
		sprintf(m_status_message, "GetSpectrumAcquisition:MCHR_StopSpectrumAcquisition: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#else
		sprintf_s(m_status_message, "GetSpectrumAcquisition:MCHR_GetSpectrumAcquisitionData: Error : (0x%X)\n", MCHR_GetLastError(m_chr_id));
#endif
		ret = false;
	}
	return(ret);
}
//--------------------------------------------------------------------
