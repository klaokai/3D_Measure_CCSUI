#if !defined(AFX_ACQUISITION_EASY_H_INCLUDED_)
#define AFX_ACQUISITION_EASY_H_INCLUDED_

#include "afxmt.h"
#include "windows.h"
#include "MchrType.h"
#include "MchrDefine.h"
#include "MchrError.h"
#include "Mchr.h"
#include "cAcqEasyType.h"

class cAcqEasy
{
private:
	HANDLE hThread;
	static DWORD WINAPI ProcessThread (LPVOID lpArg);	
	DWORD ProcessThread(void);
	HANDLE	m_OnEvent[EVENT_ACQ_EASY_NUMBER];
	HANDLE	m_OnEventAcquisition[EVENT_ACQUISITION_NUMBER];
	MCHR_tyAcqParam m_acqParam;
	sAcqEasyParam m_acqEasyParam;
	bool m_IsDataAcquisitionStarting;
	bool m_IsSpectrumAcquisitionStarting;
	MCHR_ID m_chr_id;
	short m_status_acquisition;
	char m_status_message[MAX_CHAR];		
	int m_number_of_buffer_to_read;
	int m_current_index_of_buffer_to_read;
	long m_measure_index;
	HANDLE m_end_acq_event;
	HANDLE m_status_event;
	float **m_ppAcqBuffer[ID_BUFFER_MAX];	//data buffers
	DWORD **m_ppEncoderBuffer[ID_BUFFER_ENCODER_MAX];	//encoders buffers
	float **m_ppAutoAdaptativeBuffer;	//auto adaptative buffers
	bool m_IsCreateAcqBuffer;

	CCriticalSection criticalBuffer;

	void _CreateAcqBuffer(int NumberOfBuffers, int BufferLength);
	void _ReleaseAcqBuffer(int NumberOfBuffers);

	//try to determine and set the sensor mode and digital output
	bool _SetSensorModeAndDigitalOutput(sAcqEasyParam *pAcqEasyParam);

public:
	cAcqEasy(MCHR_ID SensorID);
	~cAcqEasy();

	//start spectrum acquisition
	bool StartSpectrumAcquisition(unsigned short **ppSpectrum, unsigned short *pFirstUsablePixel, unsigned short *pBufferSize);
	//stop spectrum acquisition
	bool StopSpectrumAcquisition(unsigned short **ppSpectrum);
	//read spectrum acquisition
	bool GetSpectrumAcquisition(unsigned short *pSpectrum, unsigned short DataSize, unsigned short *pCounter, enSpectrumAcquisitionResult *pSpectrumAcquisitionResult, int timeout);


	//start acquisition with acquisition parameters
	bool StartAcquisition(sAcqEasyParam acqEasyParam);
	//stop acquisition
	bool StopAcquisition();
	//select your own acquisition event
	void SetAcqEvent(HANDLE endAcqEvent) { m_end_acq_event = endAcqEvent; };
	//select your own status event
	void SetStatusEvent(HANDLE statusEvent) { m_status_event = statusEvent; };

	void SetSensorId(MCHR_ID Id) { m_chr_id = Id; }
	MCHR_ID GetSensorId(void) { return (m_chr_id); }
	bool GetAltitudeAcquisitionData(PFLOAT pArrayAltitude, PFLOAT pArrayIntensity, PFLOAT pArrayCounter, PFLOAT pArrayBarycenter, PFLOAT pArrayStatus, int* pCount);
	bool GetThicknessAcquisitionData(PFLOAT pArrayThickness, PFLOAT pArrayDistance1, PFLOAT pArrayIntensity1, PFLOAT pArrayBarycenter1, PFLOAT pArrayDistance2, PFLOAT pArrayIntensity2, PFLOAT pArrayBarycenter2, PFLOAT pArrayStatus, PFLOAT pArrayCounter, int* pDataCount);	
	bool GetDepthAcquisitionData(PFLOAT pArrayDepth, PFLOAT pArrayIntensity, PFLOAT pArrayCounter, PFLOAT pArrayBarycenter, PFLOAT pArrayStatus, int* pDataCount);
	bool GetInterferometricThicknessAcquisitionData(PFLOAT pArrayThickness1, PFLOAT pArrayThickness2, PFLOAT pArrayThickness3, PFLOAT pArrayQuality1, PFLOAT pArrayQuality2, PFLOAT pArrayQuality3, PFLOAT pArrayIntensity, int* pDataCount);
	bool GetInterferometricThicknessSAWLIAcquisitionData(PFLOAT pArrayThickness1, PFLOAT pArrayThickness2, PFLOAT pArrayThickness3, PFLOAT pArrayQuality1, PFLOAT pArrayQuality2, PFLOAT pArrayQuality3, PFLOAT pArrayIntensity, PFLOAT pArrayThickness, PFLOAT pArrayCounter, PFLOAT pArrayStatus, int* pDataCount);
	bool GetAltitudeEncoderData(PFLOAT pArrayAltitude, PFLOAT pArrayIntensity, PFLOAT pArrayCounter, PFLOAT pArrayBarycenter, PFLOAT pArrayStatus, PDWORD pArrayEncoder1, PDWORD pArrayEncoder2, PDWORD pArrayEncoder3,int* pDataCount);
	bool GetEncoderData(PDWORD pArrayEncoder1, PDWORD pArrayEncoder2, PDWORD pArrayEncoder3);
	bool GetAutoAdaptativeData(PFLOAT pArrayAutoAdaptative);
	bool GetTransmittedData_ChrDistance(PFLOAT pArrayDistance, PFLOAT pArrayIntensity, PFLOAT pArrayBarycenter, int* pDataCount);
	bool GetTransmittedData_ChrThickness(PFLOAT pArrayThickness, PFLOAT pArrayDistance1, PFLOAT pArrayDistance2, PFLOAT pArrayIntensity1, PFLOAT pArrayIntensity2, PFLOAT pArrayBarycenter1, PFLOAT pArrayBarycenter2, int* pDataCount);
	bool GetTransmittedData_CcsDistance(PFLOAT pArrayDistance, PFLOAT pArrayAutoAdaptativeModeData, PFLOAT pArrayIntensity, PFLOAT pArrayBarycenter, PFLOAT pArrayStatus, PFLOAT pArrayCounter, PDWORD pArrayEncoder1, PDWORD pArrayEncoder2, PDWORD pArrayEncoder3, int* pDataCount);
	bool GetTransmittedData_CcsThickness(PFLOAT pArrayThickness, PFLOAT pArrayDistance1, PFLOAT pArrayDistance2, PFLOAT pArrayAutoAdaptativeModeData, PFLOAT pArrayIntensity1, PFLOAT pArrayIntensity2, PFLOAT pArrayBaryCenter1, PFLOAT pArrayBaryCenter2, PFLOAT pArrayStatus, PFLOAT pArrayCounter, PDWORD pArrayEncoder1, PDWORD pArrayEncoder2, PDWORD pArrayEncoder3, int* pDataCount);
	bool GetTransmittedData_DuoDistance(PFLOAT pArrayDistance, PFLOAT pArrayIntensity, PFLOAT pArrayCounter, PFLOAT pArrayBarycenter, PFLOAT pArrayStatus, int* pDataCount);
	bool GetTransmittedData_DuoThickness(PFLOAT pArrayThickness, PFLOAT pArrayDistance1, PFLOAT pArrayDistance2, PFLOAT pArrayCounter, PFLOAT pArrayIntensity1, PFLOAT pArrayIntensity2, PFLOAT pArrayBaryCenter1, PFLOAT pArrayBaryCenter2, PFLOAT pArrayStatus, int* pDataCount);
	bool GetTransmittedData_DuoSawliDistance(PFLOAT pArrayDistance, PFLOAT pArrayQuality, PFLOAT pArrayIntensity, PFLOAT pArrayCounter, PFLOAT pArrayStatus, int* pDataCount);
	bool GetTransmittedData_DuoSawliThickness(PFLOAT pArrayThickness1, PFLOAT pArrayThickness2, PFLOAT pArrayThickness3, PFLOAT pArrayQuality1, PFLOAT pArrayQuality2, PFLOAT pArrayQuality3, PFLOAT pArrayIntensity, PFLOAT pArrayNbThickness, PFLOAT pArrayCounter, PFLOAT pArrayStatus, int* pDataCount);
	short GetStatusAcquisition(char *pMessage);
};

#endif //AFX_ACQUISITION_EASY_H_INCLUDED_