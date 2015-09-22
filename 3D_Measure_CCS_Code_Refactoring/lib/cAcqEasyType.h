#if !defined(AFX_ACQUISITION_EASY_TYPE_H_INCLUDED_)
#define AFX_ACQUISITION_EASY_TYPE_H_INCLUDED_

#include "afxmt.h"

#define MAX_CHAR										256

//do not change the order of data
#define EVENT_ACQ_EASY_KILL_THREAD						0
#define EVENT_ACQ_EASY_KILL_THREAD_DO					1
#define EVENT_ACQ_EASY_NUMBER							2

//do not change the order of data
#define EVENT_ACQUIRE_N_POINTS							0
#define EVENT_END_BUFFER								1
#define EVENT_END_MEASUREMENT							2
#define EVENT_END_ACQUIRE								3
#define EVENT_STARTING_ACQUISITION						4
#define EVENT_ACQUISITION_NUMBER						5

//do not change the order of data
//for eMCHR_GetThicknessMeasurement
#define ID_BUFFER_THICKNESS_THICKNESS					0
#define ID_BUFFER_THICKNESS_DISTANCE1					1
#define ID_BUFFER_THICKNESS_DISTANCE2					2
#define ID_BUFFER_THICKNESS_INTENSITY1					3
#define ID_BUFFER_THICKNESS_INTENSITY2					4
#define ID_BUFFER_THICKNESS_BARYCENTER1					5
#define ID_BUFFER_THICKNESS_BARYCENTER2					6
#define ID_BUFFER_THICKNESS_STATUS						7
#define ID_BUFFER_THICKNESS_COUNTER						8
#define ID_BUFFER_THICKNESS_MEASUREMENT_MAX				9		//number of max buffers for MCHR_GetThicknessMeasurement

//for eMCHR_GetAltitudeMeasurement
#define ID_BUFFER_ALTITUDE_ALTITUDE						0
#define ID_BUFFER_ALTITUDE_INTENSITY					1
#define ID_BUFFER_ALTITUDE_COUNTER						2
#define ID_BUFFER_ALTITUDE_BARYCENTER					3
#define ID_BUFFER_ALTITUDE_STATUS						4
#define ID_BUFFER_ALTITUDE_MEASUREMENT_MAX				5		//number of max buffers for MCHR_GetAltitudeMeasurement

//for eMCHR_GetDepthMeasurement
#define ID_BUFFER_DEPTH_DEPTH							0
#define ID_BUFFER_DEPTH_INTENSITY						1
#define ID_BUFFER_DEPTH_COUNTER							2
#define ID_BUFFER_DEPTH_BARYCENTER						3
#define ID_BUFFER_DEPTH_STATUS							4
#define ID_BUFFER_DEPTH_MEASUREMENT_MAX					5		//number of max buffers for MCHR_GetDepthMeasurement

//for eMCHR_GetTransmittedDataMeasurement
#define ID_BUFFER_CHR_DISTANCE_DISTANCE					0
#define ID_BUFFER_CHR_DISTANCE_INTENSITY				3
#define ID_BUFFER_CHR_DISTANCE_COUNTER					5
#define ID_BUFFER_CHR_DISTANCE_BARYCENTER				6
#define ID_BUFFER_CHR_DISTANCE_STATUS					7
#define ID_BUFFER_CHR_DISTANCE_MEASUREMENT_MAX			8

#define ID_BUFFER_CHR_THICKNESS_THICKNESS				0
#define ID_BUFFER_CHR_THICKNESS_DISTANCE1				1
#define ID_BUFFER_CHR_THICKNESS_DISTANCE2				2
#define ID_BUFFER_CHR_THICKNESS_STATUS					3
#define ID_BUFFER_CHR_THICKNESS_INTENSITY1				4
#define ID_BUFFER_CHR_THICKNESS_INTENSITY2				5
#define ID_BUFFER_CHR_THICKNESS_BARYCENTER1				6
#define ID_BUFFER_CHR_THICKNESS_BARYCENTER2				7
#define ID_BUFFER_CHR_THICKNESS_MEASUREMENT_MAX			8

#define ID_BUFFER_CCS_DISTANCE_DISTANCE_MSB				0
#define ID_BUFFER_CCS_DISTANCE_DISTANCE_LSB				1
#define ID_BUFFER_CCS_DISTANCE_AUTO_ADAPTATIVE_MODE		2
#define ID_BUFFER_CCS_DISTANCE_INTENSITY				3
#define ID_BUFFER_CCS_DISTANCE_BARYCENTER				6
#define ID_BUFFER_CCS_DISTANCE_STATUS					8
#define ID_BUFFER_CCS_DISTANCE_COUNTER					9
#define ID_BUFFER_CCS_DISTANCE_ENCODER1_MSB				10
#define ID_BUFFER_CCS_DISTANCE_ENCODER1_LSB				11
#define ID_BUFFER_CCS_DISTANCE_ENCODER2_MSB				12
#define ID_BUFFER_CCS_DISTANCE_ENCODER2_LSB				13
#define ID_BUFFER_CCS_DISTANCE_ENCODER3_MSB				14
#define ID_BUFFER_CCS_DISTANCE_ENCODER3_LSB				15
#define ID_BUFFER_CCS_DISTANCE_MEASUREMENT_MAX			16

#define ID_BUFFER_CCS_THICKNESS_THICKNESS				0
#define ID_BUFFER_CCS_THICKNESS_DISTANCE1				1
#define ID_BUFFER_CCS_THICKNESS_DISTANCE2				2
#define ID_BUFFER_CCS_THICKNESS_AUTO_ADAPTATIVE_MODE	3
#define ID_BUFFER_CCS_THICKNESS_INTENSITY1				4
#define ID_BUFFER_CCS_THICKNESS_INTENSITY2				5
#define ID_BUFFER_CCS_THICKNESS_BARYCENTER1				6
#define ID_BUFFER_CCS_THICKNESS_BARYCENTER2				7
#define ID_BUFFER_CCS_THICKNESS_STATUS					8
#define ID_BUFFER_CCS_THICKNESS_COUNTER					9
#define ID_BUFFER_CCS_THICKNESS_ENCODER1_MSB			10
#define ID_BUFFER_CCS_THICKNESS_ENCODER1_LSB			11
#define ID_BUFFER_CCS_THICKNESS_ENCODER2_MSB			12
#define ID_BUFFER_CCS_THICKNESS_ENCODER2_LSB			13
#define ID_BUFFER_CCS_THICKNESS_ENCODER3_MSB			14
#define ID_BUFFER_CCS_THICKNESS_ENCODER3_LSB			15
#define ID_BUFFER_CCS_THICKNESS_MEASUREMENT_MAX			16

#define ID_BUFFER_DUO_DISTANCE_DISTANCE_MSB				0
#define ID_BUFFER_DUO_DISTANCE_DISTANCE_LSB				1
#define ID_BUFFER_DUO_DISTANCE_INTENSITY				3
#define ID_BUFFER_DUO_DISTANCE_COUNTER					5
#define ID_BUFFER_DUO_DISTANCE_BARYCENTER				6
#define ID_BUFFER_DUO_DISTANCE_STATUS					9
#define ID_BUFFER_DUO_DISTANCE_MEASUREMENT_MAX			10

#define ID_BUFFER_DUO_THICKNESS_THICKNESS				0
#define ID_BUFFER_DUO_THICKNESS_DISTANCE1				1
#define ID_BUFFER_DUO_THICKNESS_DISTANCE2				2
#define ID_BUFFER_DUO_THICKNESS_COUNTER					3
#define ID_BUFFER_DUO_THICKNESS_INTENSITY1				4
#define ID_BUFFER_DUO_THICKNESS_INTENSITY2				5
#define ID_BUFFER_DUO_THICKNESS_BARYCENTER1				6
#define ID_BUFFER_DUO_THICKNESS_BARYCENTER2				7
#define ID_BUFFER_DUO_THICKNESS_STATUS					9
#define ID_BUFFER_DUO_THICKNESS_MEASUREMENT_MAX			10

#define ID_BUFFER_DUO_SAWLI_DISTANCE_DISTANCE_MSB		0
#define ID_BUFFER_DUO_SAWLI_DISTANCE_DISTANCE_LSB		1
#define ID_BUFFER_DUO_SAWLI_DISTANCE_QUALITY			6
#define ID_BUFFER_DUO_SAWLI_DISTANCE_INTENSITY			9
#define ID_BUFFER_DUO_SAWLI_DISTANCE_COUNTER			11
#define ID_BUFFER_DUO_SAWLI_DISTANCE_STATUS				15
#define ID_BUFFER_DUO_SAWLI_DISTANCE_MEASUREMENT_MAX	16

#define ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS1_MSB	0
#define ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS1_LSB	1
#define ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS2_MSB	2
#define ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS2_LSB	3
#define ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS3_MSB	4
#define ID_BUFFER_DUO_SAWLI_THICKNESS_THICKNESS3_LSB	5
#define ID_BUFFER_DUO_SAWLI_THICKNESS_QUALITY1			6
#define ID_BUFFER_DUO_SAWLI_THICKNESS_QUALITY2			7
#define ID_BUFFER_DUO_SAWLI_THICKNESS_QUALITY3			8
#define ID_BUFFER_DUO_SAWLI_THICKNESS_INTENSITY			9
#define ID_BUFFER_DUO_SAWLI_THICKNESS_NB_THICKNESS		10
#define ID_BUFFER_DUO_SAWLI_THICKNESS_COUNTER			11
#define ID_BUFFER_DUO_SAWLI_THICKNESS_STATUS			15
#define ID_BUFFER_DUO_SAWLI_THICKNESS_MEASUREMENT_MAX	16

#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_THICKNESS1		0
#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_THICKNESS2		1
#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_THICKNESS3		2
#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_QUALITY1			4
#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_QUALITY2			5
#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_QUALITY3			6
#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_INTENSITY			7
#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_THICKNESS			8
#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_COUNTER			9
#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_STATUS			10
#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_SAWLI_MEASUREMENT_MAX	11

#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_THICKNESS1		0
#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_THICKNESS2		1
#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_THICKNESS3		2
#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_QUALITY1		3
#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_QUALITY2		4
#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_QUALITY3		5
#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_INTENSITY		6
#define ID_BUFFER_INTERFEROMETRIC_THICKNESS_MEASUREMENT_MAX	7
 

//for (MCHR_SetEncoderBuffer)
#define ID_BUFFER_ENCODER_1								0
#define ID_BUFFER_ENCODER_2								1
#define ID_BUFFER_ENCODER_3								2
#define ID_BUFFER_ENCODER_MAX							3		//number of total buffers for each encoder

#define ID_BUFFER_MAX									16		//number of total buffers for each acquisition function
#define MAX_BUFFER_NUMBER								5000	//number of max buffer number

#define STATUS_NO_ERROR									0
#define STATUS_TIMEOUT_ERROR							1
#define STATUS_PARAM_ERROR								2
#define STATUS_ACQ_ERROR								3
#define STATUS_EVENT_ERROR								4
#define STATUS_NO_DATA									5
#define STATUS_MCHR_FUNCTION							6

enum eAcqEasyFunc{eMCHR_GetThicknessMeasurement, eMCHR_GetAltitudeMeasurement, eMCHR_GetDepthMeasurement, eMCHR_GetTransmittedDataMeasurement, eMCHR_GetInterferometricThickness, eMCHR_GetInterferometricThicknessSAWLI};

typedef struct
{
	bool Thickness;							//Enabled the acquisition Thickness
	bool Distance1;							//Enabled the acquisition Distance 1
	bool Distance2;							//Enabled the acquisition Distance 2
	bool Intensity1;						//Enabled the acquisition Intensity 1 	
	bool Intensity2;						//Enabled the acquisition Intensity 2
	bool BaryCenter1;						//Enabled the acquisition BaryCenter 1
	bool BaryCenter2;						//Enabled the acquisition BaryCenter 2
	bool Status;							//Enabled the acquisition Status
	bool Counter;							//Enabled the acquisition Counter
} sEnableBufferThickness;


typedef struct
{
	bool Altitude;							//Enabled the acquisition Altitude
	bool Intensity;							//Enabled the acquisition Intensity  			
	bool Counter;							//Enabled the acquisition Counter
	bool BaryCenter;						//Enabled the acquisition BaryCenter 
	bool Status;							//Enabled the acquisition Status	
} sEnableBufferAltitude;

typedef struct
{
	bool Depth;								//Enabled the acquisition Depth
	bool Intensity;							//Enabled the acquisition Intensity  			
	bool Counter;							//Enabled the acquisition Counter
	bool BaryCenter;						//Enabled the acquisition BaryCenter 
	bool Status;							//Enabled the acquisition Status	
} sEnableBufferDepth;

typedef struct
{
	bool Distance;							//Enabled the acquisition Distance
	bool Intensity;							//Enabled the acquisition Intensity  			
	bool Counter;							//Enabled the acquisition Counter
	bool BaryCenter;						//Enabled the acquisition BaryCenter 
	bool Status;							//Enabled the acquisition Status	
} sChrDistance;

typedef struct
{
	bool Thickness;							//Enabled the acquisition Thickness
	bool Distance1;							//Enabled the acquisition Distance1  			
	bool Distance2;							//Enabled the acquisition Distance2
	bool Status;							//Enabled the acquisition Status 
	bool Intensity1;						//Enabled the acquisition Intensity1	
	bool Intensity2;						//Enabled the acquisition Intensity2	
	bool BaryCenter1;						//Enabled the acquisition Barycenter1	
	bool BaryCenter2;						//Enabled the acquisition Barycenter2	
} sChrThickness;
 
typedef struct
{
	bool Distance;							//Enabled the acquisition Distance
	bool AutoAdaptativeModeData;			//Enabled the acquisition AutoAdaptativeModeData  			
	bool Intensity;							//Enabled the acquisition Intensity
	bool BaryCenter;						//Enabled the acquisition Barycenter 
	bool Status;							//Enabled the acquisition Status	
	bool Counter;							//Enabled the acquisition Counter	
	bool Encoder1;							//Enabled the acquisition Encoder1	
	bool Encoder2;							//Enabled the acquisition Encoder2	
	bool Encoder3;							//Enabled the acquisition Encoder3	
} sCcsDistance;

typedef struct
{
	bool Thickness;							//Enabled the acquisition Thickness
	bool Distance1;							//Enabled the acquisition Distance1  			
	bool Distance2;							//Enabled the acquisition Distance2
	bool AutoAdaptativeModeData;			//Enabled the acquisition AutoAdaptativeModeData 
	bool Intensity1;						//Enabled the acquisition Intensity1	
	bool Intensity2;						//Enabled the acquisition Intensity2	
	bool BaryCenter1;						//Enabled the acquisition Barycenter1	
	bool BaryCenter2;						//Enabled the acquisition Barycenter2	
	bool Status;							//Enabled the acquisition Status	
	bool Counter;							//Enabled the acquisition Counter	
	bool Encoder1;							//Enabled the acquisition Encoder1	
	bool Encoder2;							//Enabled the acquisition Encoder2	
	bool Encoder3;							//Enabled the acquisition Encoder3	
} sCcsThickness;

typedef struct
{
	bool Distance;							//Enabled the acquisition Distance
	bool Intensity;							//Enabled the acquisition Intensity
	bool Counter;							//Enabled the acquisition Counter	
	bool BaryCenter;						//Enabled the acquisition Barycenter 
	bool Status;							//Enabled the acquisition Status	
} sDuoDistance;

typedef struct
{
	bool Thickness;							//Enabled the acquisition Thickness
	bool Distance1;							//Enabled the acquisition Distance1  			
	bool Distance2;							//Enabled the acquisition Distance2
	bool Counter;							//Enabled the acquisition Counter	
	bool Intensity1;						//Enabled the acquisition Intensity1	
	bool Intensity2;						//Enabled the acquisition Intensity2	
	bool BaryCenter1;						//Enabled the acquisition Barycenter1	
	bool BaryCenter2;						//Enabled the acquisition Barycenter2	
	bool Status;							//Enabled the acquisition Status	
} sDuoThickness;

typedef struct
{
	bool Distance;							//Enabled the acquisition Distance
	bool Quality;							//Enabled the acquisition Quality
	bool Intensity;							//Enabled the acquisition Intensity
	bool Counter;							//Enabled the acquisition Counter	
	bool Status;							//Enabled the acquisition Status	
} sDuoSawliDistance;

typedef struct
{
	bool Thickness1;						//Enabled the acquisition Thickness1
	bool Thickness2;						//Enabled the acquisition Thickness2
	bool Thickness3;						//Enabled the acquisition Thickness3
	bool Quality1;							//Enabled the acquisition Quality1
	bool Quality2;							//Enabled the acquisition Quality2
	bool Quality3;							//Enabled the acquisition Quality3
	bool Intensity;							//Enabled the acquisition Intensity
	bool NbThickness;						//Enabled the acquisition NbThickness
	bool Counter;							//Enabled the acquisition Counter	
	bool Status;							//Enabled the acquisition Status	
} sDuoSawliThickness;

typedef struct
{
	bool Thickness1;
    bool Thickness2;
    bool Thickness3;
    bool Quality1;
    bool Quality2;
    bool Quality3;
    bool Intensity;
} sEnableBufferInterferometricThickness;

typedef struct
{
	bool Thickness1;
	bool Thickness2;
	bool Thickness3;
	bool Quality1;
	bool Quality2;
	bool Quality3;
	bool Intensity;
	bool Thickness;
	bool Status;
	bool Counter;
} sEnableBufferInterferometricThicknessSAWLI;

typedef struct
{
	sChrDistance ChrDistance;				//Enabled the acquisition ChrDistance	
	sChrThickness ChrThickness;				//Enabled the acquisition ChrThickness	
	sCcsDistance CcsDistance;				//Enabled the acquisition CcsDistance	
	sCcsThickness CcsThickness;				//Enabled the acquisition CcsThickness	
	sDuoDistance DuoDistance;				//Enabled the acquisition DuoDistance	
	sDuoThickness DuoThickness;				//Enabled the acquisition DuoThickness	
	sDuoSawliDistance DuoSawliDistance;		//Enabled the acquisition DuoSawliDistance	
	sDuoSawliThickness DuoSawliThickness;	//Enabled the acquisition DuoSawliThickness	
} sEnableBufferTransmittedData;


typedef struct
{
	bool Encoder1;							//Enabled the acquisition Encoder 1
	bool Encoder2;							//Enabled the acquisition Encoder 2  			
	bool Encoder3;							//Enabled the acquisition Encoder 3
} sEnableBufferEncoder;

typedef struct
{
	bool Enable;							//This parameter activates or deactivates Trigger mode (if Trigger mode is active acquisition will wait for a "Trigger in" signal to start, otherwise acquisition starts immediately). 
	enTriggerType Type;						//This parameter indicates the trigger mode (TRG /TRE/TRN/ TRS)  			
	enLevelEdgeFlag  Level;					//This parameter is significant only if TriggerFlag is set to “TRUE?and only for CCS and STIL-INITIAL sensors.	It indicates which edge of the Sync-In signal pulse is active (for TRG, TRE, and TRS) or which state of this signal is active (for TRN). Authorized values are: MCHR_FALLING_EDGE, MCHR_RISING_EDGE, MCHR_LOW_LEVEL, MCHR_HIGH_LEVEL.
} sTriggerParameters;

typedef enum 
{
	//if the user wants to wait for an event type "EventEndBuffer"
   EV_END_BUFFER = 0,		
	//if the user wants to wait for an event type "EventAcquire_n_Points"
   EV_ACQUIRE_N_POINTS,		
	//if the user wants to wait for an event type "EventEndMeasurements"
   EV_END_MEASUREMENTS,		
	//if the user wants to wait for an event type "EventEndAcquire"
   EV_END_ACQUIRE		
 } evTypeEvents;


typedef struct
{
	eAcqEasyFunc typeAcquisition;															//type of function to use
	sEnableBufferThickness EnableBufferThickness;											//Enabled the acquisition Thickness (eMCHR_GetThicknessMeasurement)
	sEnableBufferAltitude EnableBufferAltitude;												//Enabled the acquisition Altitude (eMCHR_GetAltitudeMeasurement)
	sEnableBufferDepth EnableBufferDepth;													//Enabled the acquisition Depth (eMCHR_GetDepthMeasurement)
	sEnableBufferTransmittedData EnableBufferTransmittedData;								//Enabled the acquisition TransmittedData (eMCHR_GetTransmittedDataMeasurement)
	sEnableBufferEncoder EnableBufferEncoder;												//Enabled the acquisition Encoder
	sEnableBufferInterferometricThickness EnableBufferInterferometricThickness;				//Enabled the acquisition InterferometricThickness
	sEnableBufferInterferometricThicknessSAWLI EnableBufferInterferometricThicknessSAWLI;	//Enabled the acquisition InterferometricThicknessSAWLI
	bool EnableBufferAutoAdaptive;															//Enabled the acquisition AutoAdaptive
	WORD NumberOfBuffers;																	//The number of buffers per data type for receiving the measured data (Should be greater than or equal to 1).
	DWORD BufferLength;																		//Size of the buffers for receiving the measured data (in words: one word=data for one measured point)
	WORD TimeoutAcquisition;																//timeout for acquisition delay in ms 	
	DWORD NumberOfPoints;																	//Number of point to measure. If this parameters is set to 0, measurement will be continuous (i.e. will last forever or until stopped by the user) and no event " EventEndMeasurement" will be generated		
	DWORD NumberPointsTRE;																	//Number of points for TRE mode:  This parameter indicates the number of points to acquire after each Sync-in pulse.		
	enChrType SensorType;																	//Controller types(MCHR_CCS_PRIMA, MCHR_DUO, ...) used only for eMCHR_GetTransmittedDataMeasurement
	enMeasureMode SensorMode;																//Measuring modes(MCHR_DISTANCE_MODE, MCHR_THICKNESS_MODE, ...) used only for eMCHR_GetTransmittedDataMeasurement
	evTypeEvents TypeEvent;																	//The event that the user wants to wait.
	sTriggerParameters Trigger;
	unsigned short Frequency;
} sAcqEasyParam;



#endif //AFX_ACQUISITION_EASY_H_INCLUDED_