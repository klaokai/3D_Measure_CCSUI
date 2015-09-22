/************************************************************************/
/*			STIL   *   Software Departement        		                */
/*----------------------------------------------------------------------*/
/*                                                                      */
/*              MchrDefine.h                     				        */
/*                                                                      */
/*----------------------------------------------------------------------*/
/*  Project .................................. CHR    DLL               */
/*  Reference documents													*/
/*  Programming Language  .................    Visual C++ v6.0          */
/*  Starting date          ................... 16/01/2003               */
/*  Date of last update          .............                          */
/*  Author(s)................................. DMO                      */
/*  Required Files    .........................none                     */
/*  Required hardware ....................     PC Pentium 350 Mhz       */
/*  Prefix ...........                         MCHR_                    */
/*----------------------------------------------------------------------*/
/*  This HEADER file defines constants                                  */
/*                                                                      */
/*                                                                      */
/*----------------------------------------------------------------------*/
/*  V?  |   Date    |AUTHOR|                   COMMENTS                */
/*-------+---------- +--------------------------------------------------*/
/*  01   | 05 Sept 03| DMO  | Initial version                           */
/*  02   | 18 Nov  05| DMO  | Ethernet, XE, download                    */
/*  03   | 07 Mar. 08| RSA	| Max number devices set to 8				*/
/*----------------------------------------------------------------------*/

#ifndef MCHRDEFINE_H
#define MCHRDEFINE_H


#if defined(_cplusplus) || defined(__cplusplus)
extern "C" {
#endif /* _cplusplus */

/*!
  \def MCHR_MAX_SENSOR
  \if FR
	 Nombre maximum de capteur pouvant être gere par la DLL
  \else
	 Maximum number of sensors that can be handled by the DLL
  \endif
*/
#define MCHR_MAX_SENSOR        16

/*!
  \def MCHR_MAX_REFRACTIVE_INDEX
  \if FR
	 Nombre maximum de d'indice de refraction pouvant être gere par un capteur
  \else
	 Maximum number of refractive indexes that can be handled by a sensor
  \endif
*/
#define MCHR_MAX_REFRACTIVE_INDEX 8

/*!
  \def MCHR_USB_DEVICE_NAME_LENGTH
  \if FR
	 Taille max du nom de peripherique USB
  \else
	 Max length of Usb device name
  \endif
*/
#define MCHR_USB_DEVICE_NAME_LENGTH   50

/*!
  \def MCHR_MAX_DIGITAL_DATA
  \if FR
	 Nombre de donnees max mesurees par un capteur
  \else
	 Max number of data measured at each physical point
  \endif
*/
#define MCHR_MAX_DIGITAL_DATA 16

/*!
  \def MCHR_ANALOG_OUTPUT_NUMBER
  \if FR
	 Nombre de sorties analogique max d'un capteur
  \else
	 Max number of analog outputs for a sensor
  \endif
*/
#define MCHR_ANALOG_OUTPUT_NUMBER  2

/*!
  \def MCHR_MAX_ENCODER
  \if FR
	 Nombre de codeur max pour un capteur
  \else
	 Max number of encoders for a sensor
  \endif
*/
#define MCHR_MAX_ENCODER       3

/*!
  \def MCHR_MAX_PEN_CHR_150
  \if FR
	 Nombre de crayon max dans un CHR-150.
  \else
	 Max number of opticals pens ( = calibration tables) by CHR 150
  \endif
*/
#define MCHR_MAX_PEN_CHR_150     6
/*!
  \def MCHR_MAX_PEN_CHR_450
  \if FR
	 Nombre de crayon max dans un CHR-450.
  \else
	 Max number of opticals pens ( = calibration tables) by CHR 450
  \endif
*/
#define MCHR_MAX_PEN_CHR_450     6
/*!
  \def MCHR_MAX_PEN_CHR_XE
  \if FR
	 Nombre de crayon max dans un CHR-XE.
  \else
	 Max number of opticals pens ( = calibration tables) by CHR XE
  \endif
*/
#define MCHR_MAX_PEN_CHR_XE      6
/*!
  \def MCHR_MAX_PEN_CHR_XE_E
  \if FR
	 Nombre de crayon max dans un CHR-XE.
  \else
	 Max number of opticals pens ( = calibration tables) by CHR XE
  \endif
*/
#define MCHR_MAX_PEN_CHR_XE_E    20
/*!
  \def MCHR_MAX_PEN_CCS_ALPHA
  \if FR
	 Nombre de crayon max dans un CCS ALPHA.
  \else
	 Max number of opticals pens ( = calibration tables) by CCS ALPHA
  \endif
*/
#define MCHR_MAX_PEN_CCS_ALPHA   20
/*!
  \def MCHR_MAX_PEN_CCS_PRIMA
  \if FR
	 Nombre de crayon max dans un CCS PRIMA.
  \else
	 Max number of opticals pens ( = calibration tables) by CCS PRIMA.
  \endif
*/
#define MCHR_MAX_PEN_CCS_PRIMA   20
/*!
  \def MCHR_MAX_PEN_CCS_OPTIMA
  \if FR
	 Nombre de crayon max dans un CCS OPTIMA.
  \else
	 Max number of opticals pens ( = calibration tables) by CCS OPTIMA
  \endif
*/
#define MCHR_MAX_PEN_CCS_OPTIMA  20
/*!
  \def MCHR_MAX_PEN_CCS_ULTIMA
  \if FR
	 Nombre de crayon max dans un CCS ULTIMA.
  \else
	 Max number of opticals pens ( = calibration tables) by CCS ULTIMA
  \endif
*/
#define MCHR_MAX_PEN_CCS_ULTIMA  20
/*!
  \def MCHR_MAX_PEN_CCS_INITIAL
  \if FR
	 Nombre de crayon max dans un CCS INITIAL.
  \else
	 Max number of opticals pens ( = calibration tables) by CCS INITIAL.
  \endif
*/
#define MCHR_MAX_PEN_CCS_INITIAL   1
/*!
  \def MCHR_MAX_PEN_TRIO
  \if FR
	 Nombre de crayon max dans un TRIO.
  \else
	 Max number of opticals pens ( = calibration tables) by TRIO.
  \endif
*/
#define MCHR_MAX_PEN_TRIO  20
/*!
  \def MCHR_MAX_PEN_RUBY
  \if FR
	 Nombre de crayon max dans un RUBY.
  \else
	 Max number of opticals pens ( = calibration tables) by RUBY
  \endif
*/
#define MCHR_MAX_PEN_RUBY  20
/*!
  \def MCHR_MAX_PEN_CHR
  \if FR
	 Nombre de crayon max dans un CHR.
  \else
	 Max number of opticals pens ( = calibration tables) by CHR.
  \endif
*/
#define MCHR_MAX_PEN_CHR      MCHR_MAX_PEN_CHR_150
/*!
  \def MCHR_MAX_EXPOSURE_CHR_150
  \if FR
	 Definition du temps d'exposition MAXIMUM pour un capteur.
	 \warning Fonction non autorisee pour le CHR 150.
  \else
	 MAXIMUM exposure time in microsec for a sensor.
	 \warning COMMAND NOT AUTHORIZED for CHR 150.
  \endif
*/
#define MCHR_MAX_EXPOSURE_CHR_150  0    /* Non applicable sur CHR-150 */
										/* Command not authorized for CHR 150 */
/*!
  \def MCHR_MIN_EXPOSURE_CHR_150
  \if FR
	 Definition du temps d'exposition MINIMUM pour un capteur.
	 \warning Fonction non autorisee pour le CHR 150.
  \else
	 MINIMUM exposure time in microsec for a sensor.
	 \warning COMMAND NOT AUTHORIZED for CHR 150.
  \endif
*/
#define MCHR_MIN_EXPOSURE_CHR_150  0    /* Non applicable sur CHR-150 */
									    /* Command not authorized for CHR 150 */
/*!
  \def MCHR_MAX_EXPOSURE_CHR_450
  \if FR
	 Definition du temps d'exposition MAXIMUM pour un CHR 450 <br>
	 30000 correspond ?la fréquence 33Hz.
  \else
	 MAXIMUM exposure time in microsec for CHR 450. <br>
	 30000 correspond to the frequency 33Hz.
  \endif
*/
#define MCHR_MAX_EXPOSURE_CHR_450  30000   /* Correspond ?la Freq 33Hhz */
										   /* Corresponds to 33Hz */
/*!
  \def MCHR_MIN_EXPOSURE_CHR_450
  \if FR
	 Definition du temps d'exposition MINIMUM pour un CHR 450.
	 250 correspond ?la fréquence 4 KHz.
  \else
	 MINIMUM exposure time in microsec for CHR 450.
	 250 correspond to the frequency 4 kHz.
  \endif
*/
#define MCHR_MIN_EXPOSURE_CHR_450    250   /* Correspond la freq 4Khz */
										   /* Corresponds to 4KHz */
/*!
  \def MCHR_MAX_EXPOSURE_CHR_XE
  \if FR
	 Definition du temps d'exposition MAXIMUM pour un CHR XE <br>
	 30000 correspond ?la fréquence 33Hz.
  \else
	 MAXIMUM exposure time in microsec for CHR XE <br>
	 30000 correspond to the frequency 33Hz.
  \endif
*/
#define MCHR_MAX_EXPOSURE_CHR_XE   30000   /* Correspond ?la Freq 33Hhz */
										   /* Corresponds to 33Hz */
/*!
  \def MCHR_MIN_EXPOSURE_CHR_XE
  \if FR
	 Definition du temps d'exposition MINIMUM pour un CHR XE.
	 100 correspond ?la fréquence 10 KHz.
  \else
	 MINIMUM exposure time in microsec for CHR XE.
	 100 correspond to the frequency 10 kHz.
  \endif
*/
#define MCHR_MIN_EXPOSURE_CHR_XE     100   /* Correspond la freq 10Khz */
										   /* Corresponds to 10KHz */
/*!
  \def MCHR_MAX_EXPOSURE_CHR_XE_E
  \if FR
	 Definition du temps d'exposition MAXIMUM pour un CHR XE_E <br>
	 30000 correspond ?la fréquence 33 Hz.
  \else
	 MAXIMUM exposure time in microsec for CHR XE_E. <br>
	 30000 correspond to the frequency 33 Hz.
  \endif
*/
#define MCHR_MAX_EXPOSURE_CHR_XE_E 30000   /* Correspond ?la Freq 33Hhz */
										   /* Corresponds to 33Hz */
/*!
  \def MCHR_MIN_EXPOSURE_XE_E
  \if FR
	 Definition du temps d'exposition MINIMUM pour un CHR XE_E.
	 32 correspond ?la fréquence 31,250 Khz.
  \else
	 MINIMUM exposure time in microsec for CHR XE_E.
	 32 correspond to the frequency 31,250 Khz.
  \endif
*/
#define MCHR_MIN_EXPOSURE_CHR_XE_E    32   /* Correspond la freq 31Khz250 */
										   /* Corresponds to 31250 Hz */
/*!
  \def MCHR_MAX_EXPOSURE_CCS_ALPHA
  \if FR
	 Definition du temps d'exposition MAXIMUM pour un CCS ALPHA <br>
	 25000 correspond ?la fréquence 40 Hz.
  \else
	 MAXIMUM exposure time in microsec for CCS ALPHA. <br>
	 25000 correspond to the frequency 40 Hz.
  \endif
*/
#define MCHR_MAX_EXPOSURE_CCS_ALPHA 25000   /* Correspond ?la Freq 40 Hz */
										    /* Corresponds to 40 Hz */
/*!
  \def MCHR_MIN_EXPOSURE_CCS_ALPHA
  \if FR
	 Definition du temps d'exposition MINIMUM pour un CCS ALPHA.
	 500 correspond ?la fréquence 2 KHz.
  \else
	 MINIMUM exposure time in microsec for CHR CCS ALPHA.
	 500 correspond to the frequency 2 kHz.
  \endif
*/
#define MCHR_MIN_EXPOSURE_CCS_ALPHA   500   /* Correspond la freq 2Khz */
										    /* Corresponds to 2000 Hz */
/*!
  \def MCHR_MAX_EXPOSURE_CCS_INITIAL
  \if FR
	 Definition du temps d'exposition MAXIMUM pour un CCS INITIAL <br>
	 10000 correspond ?la fréquence 100 Hz.
  \else
	 MAXIMUM exposure time in microsec for CHR CCS INITIAL. <br>
	 10000 correspond to the frequency 100 Hz.
  \endif
*/
#define MCHR_MAX_EXPOSURE_CCS_INITIAL 10000  /* Correspond ?la Freq 100Hhz */
												/* Corresponds to 100Hz */
/*!
  \def MCHR_MIN_EXPOSURE_CCS_INITIAL
  \if FR
	 Definition du temps d'exposition MINIMUM pour un CCS INITIAL.
	 500 correspond ?la fréquence 2 KHz.
  \else
	 MINIMUM exposure time in microsec for CHR CCS INITIAL.
	 500 correspond to the frequency 2 kHz.
  \endif
*/
#define MCHR_MIN_EXPOSURE_CCS_INITIAL   500  /* Correspond la freq 2Khz */
												/* Corresponds to 2000 Hz */
/*!
  \def MCHR_MAX_EXPOSURE_CCS_PRIMA
  \if FR
	 Definition du temps d'exposition MAXIMUM pour un CCS PRIMA <br>
	 10000 correspond ?la fréquence 100Hz.
  \else
	 MAXIMUM exposure time in microsec for CCS PRIMA. <br>
	 10000 correspond to the frequency 100Hz.
  \endif
*/
#define MCHR_MAX_EXPOSURE_CCS_PRIMA 10000	/* Correspond ?la Freq 100Hhz */
											/* Corresponds to 100Hz */
/*!
  \def MCHR_MIN_EXPOSURE_CCS_PRIMA
  \if FR
	 Definition du temps d'exposition MINIMUM pour un CCS PRIMA.
	 500 correspond ?la fréquence 2 KHz.
  \else
	 MINIMUM exposure time in microsec for CCS PRIMA.
	 500 correspond to the frequency 2 kHz.
  \endif
*/
#define MCHR_MIN_EXPOSURE_CCS_PRIMA   500  /* Correspond la freq 2Khz */
												/* Corresponds to 2000 Hz */
/*!
  \def MCHR_MAX_EXPOSURE_CCS_OPTIMA
  \if FR
	 Definition du temps d'exposition MAXIMUM pour un CCS_OPTIMA <br>
	 10000 correspond ?la fréquence 100Hz.
  \else
	 MAXIMUM exposure time in microsec for CCS_OPTIMA. <br>
	 10000 correspond to the frequency 100Hz.
  \endif
*/
#define MCHR_MAX_EXPOSURE_CCS_OPTIMA 10000		/* Correspond ?la Freq 100Hhz */
													/* Corresponds to 100Hz */
/*!
  \def MCHR_MIN_EXPOSURE_CCS_OPTIMA
  \if FR
	 Definition du temps d'exposition MINIMUM pour un CCS OPTIMA.
	 200 correspond ?la fréquence 5 KHz.
  \else
	 MINIMUM exposure time in microsec for CCS OPTIMA.
	 200 correspond to the frequency 4 kHz.
  \endif
*/
#define MCHR_MIN_EXPOSURE_CCS_OPTIMA   200		/* Correspond la freq 5000 hz */
													/* Corresponds to 5 kHz */
/*!
  \def MCHR_MAX_EXPOSURE_CCS_ULTIMA
  \if FR
	 Definition du temps d'exposition MAXIMUM pour un CCS ULTIMA<br>
	 10000 correspond ?la fréquence 100Hz.
  \else
	 MAXIMUM exposure time in microsec for CCS ULTIMA. <br>
	 10000 correspond to the frequency 100Hz.
  \endif
*/
#define MCHR_MAX_EXPOSURE_CCS_ULTIMA 10000		/* Correspond ?la Freq 100Hhz */
													/* Corresponds to 100Hz */
/*!
  \def MCHR_MIN_EXPOSURE_CCS_ULTIMA
  \if FR
	 Definition du temps d'exposition MINIMUM pour un CCS ULTIMA.
	 32 correspond ?la fréquence 31,250 KHz.
  \else
	 MINIMUM exposure time in microsec for CCS ULTIMA.
	 32 correspond to the frequency 31,250 kHz.
  \endif
*/
#define MCHR_MIN_EXPOSURE_CCS_ULTIMA    32		/* Correspond la freq 31250 hz */
													/* Corresponds to 31250 Hz */
/*!
  \def MCHR_MAX_EXPOSURE_TRIO
  \if FR
	 Definition du temps d'exposition MAXIMUM pour un TRIO <br>
	 25000 correspond ?la fréquence 40Hz.
  \else
	 MAXIMUM exposure time in microsec for TRIO. <br>
	 25000 correspond to the frequency 40Hz.
  \endif
*/
#define MCHR_MAX_EXPOSURE_TRIO 25000		/* Correspond ?la Freq 40Hz */
/*!
  \def MCHR_MIN_EXPOSURE_TRIO
  \if FR
	 Definition du temps d'exposition MINIMUM pour un TRIO.
	 500 correspond ?la fréquence 2 KHz.
  \else
	 MINIMUM exposure time in microsec for TRIO.
	 500 correspond to the frequency 2 kHz.
  \endif
*/
#define MCHR_MIN_EXPOSURE_TRIO 500			/* Correspond ?la Freq 2000Hhz */
/*!
  \def MCHR_MAX_EXPOSURE_RUBY
  \if FR
	 Definition du temps d'exposition MAXIMUM pour un RUBY
	\else
	 MAXIMUM exposure time in microsec for RUBY.

  \endif
*/
#define MCHR_MAX_EXPOSURE_RUBY 250000L		/* Correspond ?la Freq 100Hhz */
/*!
  \def MCHR_MIN_EXPOSURE_CHR_450
  \if FR
	 Definition du temps d'exposition MINIMUM pour un RUBY.
	 500 correspond ?la fréquence 2 KHz.
  \else
	 MINIMUM exposure time in microsec for RUBY.
	 500 correspond to the frequency 2 kHz.
  \endif
*/
#define MCHR_MIN_EXPOSURE_RUBY 500		/* Correspond ?la Freq 2Khz */

/*!
  \def MCHR_NO_PEN
  \if FR
	 Identificateur d'absence de crayon configure
  \else
	 Full scale value attributed to undefined calibration table
  \endif
*/
#define MCHR_NO_PEN    999

/*!
  \def MCHR_NOT_FREQ_MIN
  \if FR
	 Identificateur d'absence de Frequence min du Dark
  \else
	 Dark min frequency value attributed to undefined Dark
  \endif
*/
#define MCHR_NOT_FREQ_MIN  999

/*!
  \def enum MCHR_STATUS
  \if FR
	 Definition des etats de l'objet Capteur
  \else
	 Definition of possible states of the CHR
  \endif
*/
enum MCHR_STATUS
{
	/*! \brief not initialized */
   MCHR_STATUS_NOT_INITIALIZED=1,			//not initialized
   /*! \brief initialized */
   MCHR_STATUS_INITIALIZED,					//initialized
   /*! \brief initialization failed */
   MCHR_STATUS_INIT_FAILED,					//initialization failed
   /*! \brief waiting for command */
   MCHR_STATUS_WAIT_COMMAND,				//waiting for command
   /*! \brief not initialized */
   MCHR_STATUS_COMMAND_IN_PROGRESS,         //command processing in progress
   /*! \brief finite acquisition in progress */
   MCHR_STATUS_ACQUISITION_IN_PROGRESS,     //finite acquisition in progress
   /*! \brief finite acquisition in progress */
   MCHR_STATUS_CONTINUOUS_ACQ_IN_PROGRESS,  //continuous acquisition in progress
   /*! \brief Acquisition-abort in progress */
   MCHR_STATUS_STOP_ACQ_IN_PROGRESS,        //Acquisition-abort in progress
   /*! \brief communication failed */
   MCHR_STATUS_COM_FAILED,					//communication failed
   /*! \brief Sensor already in use by another instance */
   MCHR_STATUS_ALREADY_IN_USE,					// Sensor already in use by another instance

};

/*!
  \def enum enSpectrumAcquisitionResult
  \if FR
	 Definition des etats de l'objet de l'acquisition du spectre
  \else
	 Definition of possible states of the spectrum acquisition
  \endif
*/
enum enSpectrumAcquisitionResult
{	
	/*! \brief data present */
	SPECTRUM_ACQUISITION_DATA_READY,
	/*! \brief no data present */
	SPECTRUM_ACQUISITION_BUFFER_EMPTY, 
	/*! \brief error */
	SPECTRUM_ACQUISITION_ERROR,
	/*! \brief timeout */
	SPECTRUM_ACQUISITION_TIMEOUT,		
};


// Other declarations
#define MAX_NAME_LENGTH					128

#if defined(_cplusplus) || defined(__cplusplus)
}
#endif /* _cplusplus */
#endif