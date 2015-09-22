/************************************************************************/
/*			STIL   *   Software Departement        		                */
/*----------------------------------------------------------------------*/
/*                                                                      */
/*              MCHR.H                     				                */
/*                                                                      */
/*----------------------------------------------------------------------*/
/*  Project .................................. CHR    DLL               */
/*  Reference documents                   ..."Specification DLL CHR-150"*/
/*  Programming Language  .................    Visual C++ v6.0          */
/*  Starting date          ................... 16/01/2003               */
/*  Date of last update          .............                          */
/*  Author(s)................................. DMO                      */
/*  Required files ....................        MChrDefine.h, MchrType.h */
/*  Required hardware ....................     PC Pentium 350 Mhz       */
/*  Prefix ...........                         MCHR_                    */
/*----------------------------------------------------------------------*/
/*  This HEADER file defines exported functions                         */
/*                                                                      */
/*                                                                      */
/*----------------------------------------------------------------------*/
/*  V°   |   Date    |AUTHOR|                   COMMENTS                */
/*-------+---------- +--------------------------------------------------*/
/*  01   | 16 Janu 03| DMO  | Initial version                           */
/*  02   | 18 Nov  05| DMO  | Ethernet, XE, Downloads                   */
/*       |           |      |                                           */
/*----------------------------------------------------------------------*/

/*! \file mchr.h
	\author STIL SA
	\brief 
		\if FR
			Header de definition des prototypes de fonctions pour l'API DLL_CHR.
		\else
			Function prototypes header file for DLL_CHR API.
		\endif
*/

/*!
	\example ../../Samples/Sample_CCS_INITIAL/VS2013/Example_0/Example_0.cpp 
	\example ../../Samples/Sample_CCS_INITIAL/VS2013/Example_1/Example_1.cpp 
	\example ../../Samples/Sample_CCS_INITIAL/VS2013/Example_2/Example_2.cpp 
	\example ../../Samples/Sample_CCS_INITIAL/VS2013/Example_3/Example_3.cpp 
	\example ../../Samples/Sample_CCS_INITIAL/VS2013/Example_4/Example_4.cpp 
	\example ../../Samples/Sample_CCS_INITIAL/VS2013/Example_5/Example_5.cpp 
	\example ../../Samples/Sample_CCS_INITIAL/VS2013/Example_6/Example_6.cpp 

	\example ../../Samples/Sample_CCS_OPTIMA/VS2013/Example_0/Example_0.cpp 
	\example ../../Samples/Sample_CCS_OPTIMA/VS2013/Example_1/Example_1.cpp 
	\example ../../Samples/Sample_CCS_OPTIMA/VS2013/Example_2/Example_2.cpp 
	\example ../../Samples/Sample_CCS_OPTIMA/VS2013/Example_3/Example_3.cpp 
	\example ../../Samples/Sample_CCS_OPTIMA/VS2013/Example_4/Example_4.cpp 
	\example ../../Samples/Sample_CCS_OPTIMA/VS2013/Example_5/Example_5.cpp 

	\example ../../Samples/Sample_CCS_PRIMA/VS2013/Example_0/Example_0.cpp 
	\example ../../Samples/Sample_CCS_PRIMA/VS2013/Example_1/Example_1.cpp 
	\example ../../Samples/Sample_CCS_PRIMA/VS2013/Example_2/Example_2.cpp 
	\example ../../Samples/Sample_CCS_PRIMA/VS2013/Example_3/Example_3.cpp 
	\example ../../Samples/Sample_CCS_PRIMA/VS2013/Example_4/Example_4.cpp 
	\example ../../Samples/Sample_CCS_PRIMA/VS2013/Example_5/Example_5.cpp 
	\example ../../Samples/Sample_CCS_PRIMA/VS2013/Example_6/Example_6.cpp 

	\example ../../Samples/Sample_CCS_ULTIMA/VS2013/Example_0/Example_0.cpp 
	\example ../../Samples/Sample_CCS_ULTIMA/VS2013/Example_1/Example_1.cpp 
	\example ../../Samples/Sample_CCS_ULTIMA/VS2013/Example_2/Example_2.cpp 
	\example ../../Samples/Sample_CCS_ULTIMA/VS2013/Example_3/Example_3.cpp 
	\example ../../Samples/Sample_CCS_ULTIMA/VS2013/Example_4/Example_4.cpp 
	\example ../../Samples/Sample_CCS_ULTIMA/VS2013/Example_5/Example_5.cpp 

	\example ../../Samples/Sample_CHR/VS2013/Example_0/Example_0.cpp 
	\example ../../Samples/Sample_CHR/VS2013/Example_1/Example_1.cpp 
	\example ../../Samples/Sample_CHR/VS2013/Example_2/Example_2.cpp 
	\example ../../Samples/Sample_CHR/VS2013/Example_3/Example_3.cpp 
	\example ../../Samples/Sample_CHR/VS2013/Example_4/Example_4.cpp 

	\example ../../Samples/Sample_STIL_DUO/VS2013/Example_0/Example_0.cpp 
	\example ../../Samples/Sample_STIL_DUO/VS2013/Example_1/Example_1.cpp 
	\example ../../Samples/Sample_STIL_DUO/VS2013/Example_2/Example_2.cpp 
	\example ../../Samples/Sample_STIL_DUO/VS2013/Example_3/Example_3.cpp 
	\example ../../Samples/Sample_STIL_DUO/VS2013/Example_4/Example_4.cpp 
	\example ../../Samples/Sample_STIL_DUO/VS2013/Example_5/Example_5.cpp 
	\example ../../Samples/Sample_STIL_DUO/VS2013/Example_6/Example_6.cpp 

	\example ../../Samples/Sample_RUBY/VS2013/ConsoleAcquisition/ConsoleAcquisition.cpp 
	\example ../../Samples/Sample_RUBY/VS2013/SpectroSample/DAcquisition.cpp 
	\example ../../Samples/Sample_RUBY/VS2013/SpectroSample/DCalibration.cpp 
	\example ../../Samples/Sample_RUBY/VS2013/SpectroSample/DColorDifference.cpp 
	\example ../../Samples/Sample_RUBY/VS2013/SpectroSample/DColorimetry.cpp 
	\example ../../Samples/Sample_RUBY/VS2013/SpectroSample/DCombo.cpp 
	\example ../../Samples/Sample_RUBY/VS2013/SpectroSample/DCommandLine.cpp 
	\example ../../Samples/Sample_RUBY/VS2013/SpectroSample/DConnect.cpp 
	\example ../../Samples/Sample_RUBY/VS2013/SpectroSample/DigitalOutput.cpp 
	\example ../../Samples/Sample_RUBY/VS2013/SpectroSample/DManualWhiteRef.cpp 
	\example ../../Samples/Sample_RUBY/VS2013/SpectroSample/DRawSignal.cpp 
	\example ../../Samples/Sample_RUBY/VS2013/SpectroSample/DSpectrumProperties.cpp 
	\example ../../Samples/Sample_RUBY/VS2013/SpectroSample/SpectroSample.cpp 
	\example ../../Samples/Sample_RUBY/VS2013/SpectroSample/SpectroSampleDlg.cpp 
	*/

#ifndef MCHR_H

/*!
  \def MCHR_H
  \if FR
	 Type de capteur pouvant être gere par la DLL
  \else
	 Type of sensors that can be handled by the DLL
  \endif
*/
#define MCHR_H

#include "MChrDefine.h"
#include "MChrType.h"

#if defined(_cplusplus) || defined(__cplusplus)
extern "C"  {
#endif /* _cplusplus */
   
/*
 The following ifdef block is the standard way of creating macros which make exporting 
 from a DLL simpler. All files within this DLL are compiled with the DLL_CHR_EXPORTS
 symbol defined on the command line. this symbol should not be defined on any project
 that uses this DLL. This way any other project whose source files include this file see 
 DLL_CHR_API functions as being imported from a DLL, wheras this DLL sees symbols
 defined with this macro as being exported.
*/
#ifdef DLL_CHR_EXPORTS

#define DLL_CHR_API 
// #define DLL_CHR_API __declspec(dllexport) //this line when not using a DEF file
#else
#define DLL_CHR_API   __declspec(dllimport)
#endif

/* White light interferometry (For MTS-DUO) */
#include "Sawli.h"
/*  Colorimetry (For NCS-RUBY) */
#include "Colorimetry.h"

/**************************************************************************
 /*! \brief DLL Initialization and Clean-up */                 
/**************************************************************************/

/*!
	\fn short MCHR_GetVersion (char *VersionNumber, short LengthBuffer)
	\if FR
		\brief Fonction retournant le numero de version de la DLL.
	\else
		\brief Return the DLL version number
	\endif
	\details
		\if FR
			\param [out] char *VersionNumber : Numero de version retourne.
			\param [in] short LengthBuffer : Taille du buffer de version entre en paramètre.
			\return short : un code d'erreur MCHR_ERROR (=o). Pour connaitre l'origine de l'erreur, appeller MCHR_GetLastError <br>
			\Erreurs spécifiques : MCHR_ERROR_DLL_NOT_ACTIVE ( La DLL n'a pas été initialisée.	
		\else
			\param [out] char *VersionNumber : Version number returned.
			\param [in] short LengthBuffer : Max Buffer length of the param 1 entered.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code (=0).<br>
			\brief In order to know the origin of the error, call \link MCHR_GetLastError MCHR_GetLastError \endlink. <br>
			\Brief Specific errors are: \link MCHR_ERROR_DLL_NOT_ACTIVE MCHR_ERROR_DLL_NOT_ACTIVE \endlink : the DLL has not been initialized.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "OnInitDialog"  dans le module :
	\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API short MCHR_GetVersion(char *VersionNumber, short LengthBuffer);

/* ------------------------------------------------------------- */

/*!
	\fn MCHR_Init (void)
	\if FR
		\brief Fonction d'initialisation de la DLL et alloue la mémoire requise.
	\else
		\brief DLL initialization function and allocates required memory
	\endif
	\par Arguments: \if FR Aucun \else None
	\details
		\if FR
			\return Positive en cas de succés, autrement MCHR_ERROR (=0)<br>
		\else
			\return Positive in case of success, \link MCHR_ERROR MCHR_ERROR \endlink otherwise
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "OnAcqStop()" dans le module :
	\else
		\par Compatibles Sensors : ALL
		\endif

*/
DLL_CHR_API WORD MCHR_Init (void);
/* ------------------------------------------------------------------------- */

/*!
	\fn MCHR_Release (void)
	\if FR
		\brief  Fonction de liberation des ressources globales de la DLL.
	\else
		\brief Clean-up (free global ressources of the DLL)
	\endif
	\brief <b>Arguments :</b> \if FR Aucun \else None
	\details
		\if FR
			\return Positive en cas de succés, autrement MCHR_ERROR (=0). Pour connaître l'origine de l'erreure, appeller MCHR_GetLastError.
		\else
			\return Positive in case of success, \link MCHR_ERROR MCHR_ERROR \endlink) otherwise. In order to know the origin of the error, call \link MCHR_GetLastError MCHR_GetLastError \endlink.
		\endif
		\see MCHR_GetErrorDescription
		\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "OnReleaseDLL" dans le module :
	\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API WORD MCHR_Release (void);


/*!
	\fn short MCHR_GetUsbDeviceList (char *UsbDeviceNameList[MCHR_MAX_SENSOR], short *DeviceNumber)
	\if FR
		\brief Fonction permettant de lister les peripherique CCS connectes sur les ports USB.
		\warning Attention, sur plateformes 32bits uniquement.
	\else
		\brief Get the list of USB devices of type "CCS". 
		\warning Warning, Only on 32bits platforms.
	\endif
	\details
		\if FR
			\param [out] char *UsbDeviceNameList[MCHR_MAX_SENSOR] : Liste des noms de coffret.
			\param [out] short *DeviceNumber : Nombre de coffret sur USB.
			\return short : un code d'erreur MCHR_ERROR
		\else
			\param [out] char *UsbDeviceNameList[MCHR_MAX_SENSOR] : Name list of connected USB Housing.
			\param [out] short *DeviceNumber : Number of housings (CCS) connected.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink
		\endif
		\see MCHR_GetErrorDescription <br>
		\brief
		\par  Exa<mple :
		\brief //DECLARATION <br>
		\brief short DeviceNumber = 0; <br>
		\brief char * UsbDeviceNameList [MCHR_MAX_SENSOR]; <br>
		\brief for (int j = 0; j < MCHR_MAX_SENSOR; j++) <br> 
		\brief { <br>
      	\brief UsbDeviceNameList[j] = new char [MCHR_USB_DEVICE_NAME_LENGTH]; <br>
		\brief } <br><br>
		\brief // function call - Fonctions appellées <br>
		\brief MCHR_GetUsbDeviceList (UsbDeviceNameList, &DeviceNumber); <br>
		\brief // Display the list of “CCS” USB devices (this step is optional) <br>
		\brief for (int i = 0; i < DeviceNumber; i++) <br>
		\brief {
		\brief printf ("Device n°%d : %s", i+1, UsbDeviceNameList[i]); <br>
		\brief }		
*/

DLL_CHR_API short MCHR_GetUsbDeviceList (char *UsbDeviceNameList[MCHR_MAX_SENSOR], short *DeviceNumber);


/**************************************************************************
 ** Connectiong and Disconnecting a Sensor                               **
 **************************************************************************/

/*!
	\fn MCHR_ID MCHR_OpenChr (LPCSTR SensorName, enChrType SensorType, WORD IdSerialPort, DWORD BaudRate, LPCSTR ConfigFile)
	\if FR
		\brief Obsolete! Fonction permettant d'ouvrir une connection à un CHR sur le système.
	\else
		\brief Outdated! Function that opens a connection to a CHR.
	\endif
	\details
		\if FR
			\param [in] LPCSTR SensorName : Nom du coffret à connecter.
			\param [in] enChrType SensorType : Type du coffret.
			\param [in] WORD IdSerialPort : Port serie à utiliser pour la connexion.
			\param [in] DWORD BaudRate : BAUDRATE de la connexion.
			\param [in] LPCSTR ConfigFile : Fichier de configuration à charger.
			\return short : un code d'erreur MCHR_ERROR
		\else
			\param [in] LPCSTR SensorName : Name of the housing to connect to.
			\param [in] enChrType SensorType : Type of the housing.
			\param [in] WORD IdSerialPort : Serial port to use for connection.
			\param [in] DWORD BaudRate : BAUDRATE for this communication.
			\param [in] LPCSTR ConfigFile : Configuration file to load.
			\return short : a \link MCHR_ERROR MCHR_ERROR \endlink
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API MCHR_ID MCHR_OpenChr (LPCSTR SensorName, enChrType SensorType, WORD IdSerialPort, DWORD BaudRate, LPCSTR ConfigFile);


/*!
	\fn MCHR_ID MCHR_OpenEthernetChr (LPCSTR SensorName, enChrType SensorType, char *IpAddress, CALLBACK_STATUS_CONNECTION CallBackFct, LPCSTR ConfigFile)
	\if FR
		\brief Fonction permettant d'ouvrir une connexion d'un coffret sur le système avec une liaison ethernet.
	\else
		\brief Function that opens a connection to a sensor using Ethernet port.
	\endif
	\details
		\if FR
			\param [in] LPCSTR SensorName : Nom du coffret à connecter.
			\param [in] enChrType SensorType : Type du coffret.
			\param [in] char *IpAddress : Adresse IP du coffret.
			\param [in] CALLBACK_STATUS_CONNECTION CallBackFct : Fonction de retour des statuts de connexion.
			\param [in] LPCSTR ConfigFile : Fichier de configuration à charger.
			\return short : un code d'erreur MCHR_ERROR. Pour connaitre l'origine de l'erreur, appeller MCHR_GetLastError.<br><br>
			\brief en plus des erreurs générales, les erreurs spécifiques sont:
			\arg \c MCHR_ERROR_NOT_CONNECTED: pas de capteur trouvé à l'adresse IP spécifiée. 
			\arg \c MCHR_ERROR_ADD_SENSOR: Une erreur s'est produite pendant l'ajout du capteur à la liste.
			\arg \c MCHR_ERROR_NAME_ALREADY_EXISTS: un capteur du même nom existe déja dans la liste.
			\arg \c MCHR_ERROR_IP_ADDRESS: impossible de se connecter à l'adresse spécifiée.
		\else
			\param [in] LPCSTR SensorName : Name of the housing to connect to.
			\param [in] enChrType SensorType : Type of the housing.
			\param [in] char *IpAddress : IP address of the housing.
			\param [in] CALLBACK_STATUS_CONNECTION CallBackFct : Connection status callback function.
			\param [in] LPCSTR ConfigFile : Configuration file to load.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink. In order to know the origin of the error, call \link MCHR_GetLastError MCHR_GetLastError \endlink.<br><br>
			\brief In addition to general errors, specific errors are:
			\arg \c MCHR_ERROR_NOT_CONNECTED: no sensor was found on the specified IP Address 
			\arg \c MCHR_ERROR_ADD_SENSOR: an error occurred while trying to add the sensor to the List
			\arg \c MCHR_ERROR_NAME_ALREADY_EXISTS: a sensor with the specified name exists already in the Sensor List.
			\arg \c MCHR_ERROR_IP_ADDRESS: Impossible to connect to the specified address.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> STIL-DUO only <br><br>
	\else
		\par Compatibles Sensors : STIL-DUO only 
		\endif
*/
DLL_CHR_API MCHR_ID MCHR_OpenEthernetChr (LPCSTR SensorName, enChrType SensorType, char *IpAddress, CALLBACK_STATUS_CONNECTION CallBackFct, LPCSTR ConfigFile);


/*!
	\fn MCHR_ID MCHR_OpenUsbChr (LPCSTR SensorName, enChrType SensorType, LPCSTR UsbDeviceName, CALLBACK_STATUS_CONNECTION CallBackFct, LPCSTR ConfigFile)
	\if FR
		\brief Fonction permettant d'ouvrir une connexion d'un capteur par une liaison USB 2.
		\warning Sur plateforme 32 bits uniquement!
	\else
		\brief Function that opens a connection to a sensor using USB 2 port.
		\warning On 32 bits platform only!
	\endif
	\details
		\if FR
			\param [in] LPCSTR SensorName : Nom du coffret à connecter.
			\param [in] enChrType SensorType : Type du coffret.
			\param [in] LPCSTR UsbDeviceName : Nom du coffret branche sur USB.
			\param [in] CALLBACK_STATUS_CONNECTION CallBackFct : Fonction de retour des statuts de connexion.
			\param [in] LPCSTR ConfigFile : Fichier de configuration à charger.
			\return short : un code d'erreur MCHR_ERROR <br><br>
			\brief En plus des erreurs générales, les erreurs specifiques sont:
			\arg \c MCHR_ERROR_NOT_CONNECTED: la recherche automatique du capteur sur un port USB de libre a échouée.
			\arg \c MCHR_ERROR_ADD_SENSOR: Une erreur s'est produite pendant l'ajout du capteur à la liste : probléme de communication avec le capteur.
			\arg \c MCHR_ERROR_NAME_ALREADY_EXISTS: un capteur du même nom existe déja dans la liste.
		\else
			\param [in] LPCSTR SensorName : Name of the housing to connect to.
			\param [in] enChrType SensorType : Type of the housing.
			\param [in] LPCSTR UsbDeviceName : USB Device name.
			\param [in] CALLBACK_STATUS_CONNECTION CallBackFct : Connection status callback function.
			\param [in] LPCSTR ConfigFile : Configuration file to load.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink <br><br>
			\brief In addition to general errors, specific errors are:
			\arg \c MCHR_ERROR_NOT_CONNECTED: the automatic search of a sensor on a free USB PORT has failed.
			\arg \c MCHR_ERROR_ADD_SENSOR: an error occurred while trying to add the sensor to the Sensor List: communication problem with the sensor
			\arg \c MCHR_ERROR_NAME_ALREADY_EXISTS: a sensor with the specified name exists already in the Sensor List.
		\endif
		\see MCHR_GetErrorDescription
		\if FR 
		\brief <b>Capteurs Compatibles :</b> CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL<br><br>
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
		\endif
*/

DLL_CHR_API MCHR_ID MCHR_OpenUsbChr (LPCSTR SensorName, enChrType SensorType, LPCSTR UsbDeviceName, CALLBACK_STATUS_CONNECTION CallBackFct, LPCSTR ConfigFile);


/*!
	\fn MCHR_ID MCHR_OpenSerialChr (LPCSTR SensorName, enChrType SensorType, WORD IdSerialPort, DWORD BaudRate, LPCSTR ConfigFile)
	\if FR
		\brief Fonction permettant d'etablir une connexion RS232 avec un capteur et l'ajjoute à la liste des capteurs.
	\else
		\brief Function that opens a RS232 connection to a sensor and adds it to the Sensor List.
	\endif
	\details
		\if FR
			\param [in] LPCSTR SensorName : Nom du coffret à connecter.
			\param [in] enChrType SensorType : Type du coffret.
			\param [in] WORD IdSerialPort : Port serie à utiliser pour la connexion.
			\param [in] DWORD BaudRate : BAUDRATE de la connexion.
			\param [in] LPCSTR ConfigFile : Fichier de configuration à charger.
			\return short : un code d'erreur MCHR_ERROR (=0). pour connaitre l'origine de l'erreur, appeller MCHR_GetLastError.<br>
			\brief 
		\else
			\param [in] LPCSTR SensorName : Name of the housing to connect to.
			\param [in] enChrType SensorType : Type of the housing.
			\param [in] WORD IdSerialPort : Serial port to use for connection.
			\param [in] DWORD BaudRate : BAUDRATE for this communication.
			\param [in] LPCSTR ConfigFile : Configuration file to load.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink. In order to know the origin of the error, call \link MCHR_GetLastError MCHR_GetLastError \endlink.<br><br>
			\brief In addition to general errors listed, specific errors are:
			\arg \c MCHR_ERROR_NOT_CONNECTED: no sensor was found on the specified COM Port 
			\arg \c MCHR_ERROR_NAME_ALREADY_EXISTS: a sensor with the specified name exists already in the Sensor List.
			\arg \c MCHR_ERROR_SERIAL_PORT: an error occurred while attempting to initialize the COM port
		\endif
		\see MCHR_GetErrorDescription
		\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
	\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API MCHR_ID MCHR_OpenSerialChr (LPCSTR SensorName, enChrType SensorType, WORD IdSerialPort, DWORD BaudRate, LPCSTR ConfigFile);

/*!
	\fn short MCHR_CloseChr (MCHR_ID SensorID)
	\brief
		\if FR
			\brief Fonction de liberation d'un coffret connecte.
		\else
			\brief Function that closes connection to a device.
		\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du capteur à deconnecter.
			\return short : un code d'erreur MCHR_ERROR
		\else
			\param [in] MCHR_ID  SensorID : ID of the device to disconnect.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink
		\endif
		\see MCHR_GetErrorDescription
		\brief
		\if FR 
			\brief <b>Capteurs Compatibles :</b> TOUS
		\else
			\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API short MCHR_CloseChr (MCHR_ID  SensorID);

/*!
	\fn MCHR_GetConnectionType(MCHR_ID SensorID,enChrConnection *pConnectionType)
	\if FR
		\brief Fonction renvoyant le type de connexion d'un coffret connecte.
	\else
		\brief Function that returns the connection type of a device.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] enChrConnection *pConnectionType : Type de connexion d'un coffret connecte.
			\return short : un code d'erreur MCHR_ERROR
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] enChrConnection *pConnectionType : Connection type of a connected device.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short  MCHR_GetConnectionType(MCHR_ID SensorID,enChrConnection *pConnectionType);


/**************************************************************************
 ** Basic Queries                                                        **
 **************************************************************************/

/*!
	\fn short MCHR_GetChrType (MCHR_ID  SensorID, enChrType *ChrType)
	\brief
	\if FR
		\brief Fonction renvoyant le type d'un coffret connecte.
	\else
		\brief Function that gets the type of a connected device.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] enChrType *ChrType : Type du coffret connecte.
			\return short : un code d'erreur MCHR_ERROR
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] enChrType *ChrType : Type of the connected device.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "OnGetChrType () " dans le module :
	\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API short MCHR_GetChrType (MCHR_ID  SensorID, enChrType *ChrType);


/*!
	\fn short MCHR_GetSensorName (MCHR_ID  SensorID, PCHAR pName)
	\if FR
		\brief Fonction renvoyant le nom d'un coffret connecte.
	\else
		\brief Function that gets the name of a connected device.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] PCHAR pName : Nom du coffret connecte.
			\return short : un code d'erreur MCHR_ERROR
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] PCHAR pName : Name of the connected device.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink
		\endif
	\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "UpdateSensorInfo()" dans le module :
	\else
		\par Compatibles Sensors : ALL
	\endif
*/
DLL_CHR_API short MCHR_GetSensorName (MCHR_ID  SensorID, PCHAR pName);


/*!
	\fn short MCHR_GetFirmwareVersion (MCHR_ID SensorID, char *VersionNumber, short LengthBuffer)
	\if FR
		\brief Fonction renvoyant le numero de version de firmware d'un coffret connecte.
	\else
		\brief Function that gets the firmware version of a connected device.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] char *VersionNumber : Version de firmware du coffret connecte.
			\param [in] short LengthBuffer : Taille du buffer de version entre.
			\return short : un code d'erreur MCHR_ERROR
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] CHAR *VersionNumber : Firmware version of the connected device.
			\param [in] SHORT LengthBuffer : Length of the buffer entered.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink
		\endif
		\see MCHR_GetErrorDescription
		\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "UpdateSensorInfo" dans le module :
	\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API short MCHR_GetFirmwareVersion (MCHR_ID SensorID, char *VersionNumber, short LengthBuffer);

/*!
	\fn short MCHR_GetSerialNumber (MCHR_ID SensorID, char *SerialNumber, short LengthBuffer)
	\if FR
		\brief Fonction renvoyant le numero de serie de firmware d'un coffret connecte.
	\else
		\brief Function that gets the serial number of a connected device.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] char *SerialNumber : Numero de serie du coffret connecte.
			\param [in] short LengthBuffer : Taille du buffer entre.
			\return short : un code d'erreur MCHR_ERROR
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] char *SerialNumber : Serial number of the connected device.
			\param [in] short LengthBuffer : Length of the buffer entered.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "UpdateSensorInfo" dans le module :
	\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API short MCHR_GetSerialNumber (MCHR_ID SensorID, char *SerialNumber, short LengthBuffer);


/*!
	\fn short MCHR_GetMaxPenNumber (MCHR_ID  SensorID)
	\if FR
		\brief Fonction renvoyant le nombre maximal de crayon pouvant etre configure dans un coffret connecte.
	\else
		\brief Function that gets the number of calibration tables (= length of Pen List) of a connected device.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\return short : Nombre maximum de crayon.
		\else
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\return short : Maximum number of pens.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "OnGetPenList()"  dans le module :
	\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API short MCHR_GetMaxPenNumber (MCHR_ID  SensorID);
/* ------------------------------------------------------------------------- */


/*!
	\fn short MCHR_GetPenList (MCHR_ID  SensorID, PWORD pFullScaleList)
	\if FR
		\brief Fonction de lecture de la liste des crayons configures dans un capteur connecte. <br>
		\brief Avant d appeller cette fonction il est recommandé d'appeller MCHR_GetMaxPenNumber() qui informe sur le nombre disponible  dans la table de calibration pour ce type de capteur, afin de d iniatialiser correctement le second argument.
		\warning Voir la fonction MCHR_GetPenListEx pour utiliser le parametre pFullScaleList dans un format DWORD (à partir de la DLL_CHR V3.2.0.00)!
	\else
		\brief Get the list of all optical pens (calibration tables) defined in a connected device. <br>
		\brief Before calling this function it is recommended to call MCHR_GetMaxPenNumber() which returns the number of available calibration tables for the specified type of sensor, in order to correctly initialize the second argument.
		\warning See  MCHR_GetPenListEx Function to use pFullScaleList parameter on DWORD Format (from DLL_CHR V3.2.0.00)!
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] PWORD pFullScaleList : Liste des crayons configures dans le coffret.
			\return short : un code d'erreur MCHR_ERROR
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] PWORD pFullScaleList : Pen list of all optical pens defined in the device.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "OnGetPenList()" dans le module :
	\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API short MCHR_GetPenList (MCHR_ID  SensorID, PWORD pFullScaleList);
/* ------------------------------------------------------------------------- */


/*!
	\fn short MCHR_GetFullScale (MCHR_ID  SensorID,	PWORD pFullScale)
	\if FR
		\brief Fonction permettant de lire la valeur pleine echelle du crayon selectionne.
		\warning Voir la fonction MCHR_GetFullScaleEx pour utiliser le parametre pFullScale dans un format DWORD (à partir de la DLL_CHR V3.2.0.00)!
	\else
		\brief Get the measuring range of the current optical pen of a connected device.
		\warning See  MCHR_GetFullScaletEx Function to use pFullScale parameter on DWORD Format (from DLL_CHR V3.2.0.00)!
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] PWORD pFullScale : Valeur pleine echelle du crayon selectionne.
			\return short : un code d'erreur MCHR_ERROR
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] PWORD pFullScale : Full scale value of the selected optical pen.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "OnGetFullScale () " dans le module :
	\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API short MCHR_GetFullScale (MCHR_ID  SensorID,	PWORD pFullScale);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetFullScaleInterferometric (MCHR_ID  SensorID,	PWORD pFullScale)
	\if FR
		\brief Fonction permettant de lire la valeur pleine echelle en mode interferometrique du crayon selectionne.
		\warning Voir la fonction MCHR_GetFullScaleInterferometricEx pour utiliser le parametre pFullScale dans un format DWORD (à partir de la DLL_CHR V3.2.0.00)!
	\else
		\brief Get the measuring range of the current optical pen in interferometric mode of a connected device.
		\warning See  MCHR_GetFullScaleInterferometricEx Function to use pFullScale parameter on DWORD Format (from DLL_CHR V3.2.0.00)!
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] PWORD pFullScale : Valeur pleine echelle en mode interferometrique du crayon selectionne.
			\return short : un code d'erreur MCHR_ERROR
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] PWORD pFullScale : Full scale value in interferometric mode of the current optical pen.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetFullScaleInterferometric(MCHR_ID  SensorID,	PWORD pFullScale);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetPenListEx (MCHR_ID  SensorID, PDWORD pFullScaleList)
	\if FR
		\brief Fonction de lecture de la liste des crayons configures dans un capteur connecte. <br>
		\brief Avant d appeller cette fonction il est recommandé d'appeller MCHR_GetMaxPenNumber() qui informe sur le nombre disponible  dans la table de calibration pour ce type de capteur, afin de d iniatialiser correctement le second argument.
		\warning Remplace la fonction MCHR_GetPenList.
	\else
		\brief Get the list of all optical pens (calibration tables) defined in a connected device. <br>
		\brief Before calling this function it is recommended to call MCHR_GetMaxPenNumber() which returns the number of available calibration tables for the specified type of sensor, in order to correctly initialize the second argument.
		\warning Replace  the  MCHR_GetPenList Function.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] PDWORD pFullScaleList : Liste des crayons configures dans le coffret.
			\return short : un code d'erreur MCHR_ERROR
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] PDWORD pFullScaleList : Pen list of all optical pens defined in the device.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
	\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API short MCHR_GetPenListEx (MCHR_ID  SensorID, PDWORD pFullScaleList);
/* ------------------------------------------------------------------------- */


/*!
	\fn short MCHR_GetFullScaleEx (MCHR_ID  SensorID,	PDWORD pFullScale)
	\if FR
		\brief Fonction permettant de lire la valeur pleine echelle du crayon selectionne.
		\warning Remplace la fonction MCHR_GetFullScale.
	\else
		\brief Get the measuring range of the current optical pen of a connected device.
		\warning Replace  the  MCHR_GetFullScale Function.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] PDWORD pFullScale : Valeur pleine echelle du crayon selectionne.
			\return short : un code d'erreur MCHR_ERROR
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] PDWORD pFullScale : Full scale value of the selected optical pen.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
	\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API short MCHR_GetFullScaleEx (MCHR_ID  SensorID,	PDWORD pFullScale);
/* ------------------------------------------------------------------------- */


/*!
	\fn short MCHR_GetFullScaleInterferometricEx (MCHR_ID  SensorID,	PDWORD pFullScale)
	\if FR
		\brief Fonction permettant de lire la valeur pleine echelle en mode interferometrique du crayon selectionne.
		\warning Remplace la fonction MCHR_GetFullScaleInterferometric.
	\else
		\brief Get the measuring range of the current optical pen in interferometric mode of a connected device.
		\warning Replace  the  MCHR_GetFullScaleInterferometric Function.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] PDWORD pFullScale : Valeur pleine echelle en mode interferometrique du crayon selectionne.
			\return short : un code d'erreur MCHR_ERROR
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] PDWORD pFullScale : Full scale value in interferometric mode of the current optical pen.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetFullScaleInterferometricEx(MCHR_ID  SensorID,	PDWORD pFullScale);
/* ------------------------------------------------------------------------- */

/*!
	\fn long * MCHR_GetRateList(MCHR_ID  SensorID, WORD *RateListLength)
	\if FR
		\brief Fonction retournant la liste des frequences disponibles pour le coffret connecte specifie.
	\else
		\brief Get the list of available rates for the specified connected device.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] WORD *RateListLength : Taille du tableau de frequence.
			\return long* : Tableau des frequences predefinie du coffret.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] WORD *RateListLength : Length of the frequency array.
			\return long* : Array of device's predefined frequencies (rates).
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "OnOpenSensor()" and « OnSelectSensor () » dans le module :
	\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API long * MCHR_GetRateList(MCHR_ID  SensorID, WORD *RateListLength);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetStatus (MCHR_ID  SensorID)
	\if FR
		\brief Fonction retournant l'etat du capteur selectionne.
	\else
		\brief Get the current device's state.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\return MCHR_STATUS : Statut du capteur <br><br>
			\brief Le statut peut être comme suivant :
			\arg \c MCHR_STATUS_NOT_INITIALIZED
			\arg \c MCHR_STATUS_INITIALIZED
			\arg \c MCHR_STATUS_INIT_FAILED
			\arg \c MCHR_STATUS_WAIT_COMMAND
			\arg \c MCHR_STATUS_COMMAND_IN_PROGRESS
			\arg \c MCHR_STATUS_ACQUISITION_IN_PROGRESS
			\arg \c MCHR_STATUS_CONTINUOUS_ACQ_IN_PROGRESS
			\arg \c MCHR_STATUS_STOP_ACQ_IN_PROGRESS
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\return MCHR_STATUS : Status code <br><br>
			\brief The status may have one of the following values:
			\arg \c MCHR_STATUS_NOT_INITIALIZED
			\arg \c MCHR_STATUS_INITIALIZED
			\arg \c MCHR_STATUS_INIT_FAILED
			\arg \c MCHR_STATUS_WAIT_COMMAND
			\arg \c MCHR_STATUS_COMMAND_IN_PROGRESS
			\arg \c MCHR_STATUS_ACQUISITION_IN_PROGRESS
			\arg \c MCHR_STATUS_CONTINUOUS_ACQ_IN_PROGRESS
			\arg \c MCHR_STATUS_STOP_ACQ_IN_PROGRESS
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "OnAcqStop()" dans le module :
	\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API short MCHR_GetStatus (MCHR_ID  SensorID);
/* ------------------------------------------------------------- */

/**************************************************************************
 ** Digital Outputs Configuration                                        **
 **************************************************************************/

/*!
	\fn short MCHR_GetDigitalOutput (MCHR_ID  SensorID, PWORD Data0, PWORD Data1, PWORD Data2, PWORD Data3, PWORD Data4, PWORD Data5, PWORD Data6, PWORD Data7)
	\if FR
		\brief Fonction de lecture de la configuration des donnees transmises sur la liaison serie.
	\else
		\brief Get current configuration of data transmitted on the Digital output.
	\endif
	\details
		\if FR
			FONCTION OBSOLETE : Remplacee par MCHR_GetTransmittedDigitalOutput.
		\else
			OBSOLETE FUNCTION : Replaced by \link MCHR_GetTransmittedDigitalOutput MCHR_GetTransmittedDigitalOutput \endlink.
		\endif
*/
DLL_CHR_API short MCHR_GetDigitalOutput (MCHR_ID  SensorID, PWORD Data0, PWORD Data1, PWORD Data2, PWORD Data3, PWORD Data4, PWORD Data5, PWORD Data6, PWORD Data7);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetDigitalOutput (MCHR_ID  SensorID, WORD Data0, WORD Data1, WORD Data2, WORD Data3, WORD Data4, WORD Data5, WORD Data6, WORD Data7)
	\if FR
		\brief OBSOLETE : Fonction de configuration des donnees à transmettre sur la liaison serie.
	\else
		\brief OBSOLETE : Set data to be transmitted by the digital output.
	\endif
	\details
		\if FR
			FONCTION OBSOLETE : Remplacee par MCHR_SetTransmittedDigitalOutput.
		\else
			OBSOLETE FUNCTION : Replaced by \link MCHR_SetTransmittedDigitalOutput MCHR_SetTransmittedDigitalOutput \endlink.
		\endif
*/
DLL_CHR_API short MCHR_SetDigitalOutput (MCHR_ID  SensorID, WORD Data0, WORD Data1, WORD Data2, WORD Data3, WORD Data4, WORD Data5, WORD Data6, WORD Data7);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetTransmittedDigitalOutput (MCHR_ID  SensorID, enDigitalOutputChannel *Data);
	\if FR
		\brief Fonction de lecture de la configuration des donnees transmises sur la liaison digitale.
	\else
		\brief Get current configuration of data transmitted on the Digital output.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] enDigitalOutputChannel *Data : Tableau de configuration des sorties digitales.
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] enDigitalOutputChannel *Data : Array of digital outputs channels.<br>
			\brief The number of available data items depends on controller type and may be found using the MCHR_GetMaxNumberOfTransmittedData() function.
			\note It is possible to direct some or all of the data to a digital port different than the one connected to the DLL. 
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "On MCHR_GetMaxNumberof TransmittedData()"  dans le module :
	\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API short MCHR_GetTransmittedDigitalOutput (MCHR_ID  SensorID, enDigitalOutputChannel *Data);
/* ------------------------------------------------------------------------- */


/*!
	\fn short MCHR_SetTransmittedDigitalOutput (MCHR_ID  SensorID, enDigitalOutputChannel *Data)
	\if FR
		\brief Fonction de configuration des donnees à transmettre sur la liaison digitale.
	\else
		\brief Set data to be transmitted by the digital output channel.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] enDigitalOutputChannel *Data : Tableau de configuration des sorties digitales.
			\param Le nombre de données disponible dépend du type de controller et peut etre trouver en utilisant la fonction MCHR_GetMaxNumberOfTransmittedData().
			\return short : un code d'erreur MCHR_ERROR. <br><br>
			\brief Erreurs spécifiques :
			\arg \c  MCHR_ERROR_SCANRATE_TOO_HIGH: La vitesse de mesure actuelle est trop rapide pour transmettre les donnes spécifiees sur une liaision serie
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] enDigitalOutputChannel *Data : Array of digital outputs channels.
			\param The number of available data items depends on controller type and may be found using the MCHR_GetMaxNumberOfTransmittedData() function.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code. <br><br>
			\brief Specifics errors :
			\arg \c MCHR_ERROR_SCANRATE_TOO_HIGH: the current measuring rate is too high for transmitting the specified data items on the serial link.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : ALL
		\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API short MCHR_SetTransmittedDigitalOutput (MCHR_ID  SensorID, enDigitalOutputChannel *Data);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetDigitalOutputFormat (MCHR_ID SensorID, enDigitalOutputFormat *pOutputFormat)
	\if FR
		\brief Fonction de lecture du format (ASCII/BIN) de la sortie digitale.
	\else
		\brief Get the the current digital outpout format (ASCII/BIN).
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] enDigitalOutputFormat *pOutputFormat : Tableau des formats des sorties digitales.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out]  enDigitalOutputFormat *pOutputFormat : Array with digital outputs formats.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "OnGetOutputFormat()" dans le module :
	\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API short MCHR_GetDigitalOutputFormat (MCHR_ID SensorID, enDigitalOutputFormat *pOutputFormat);
/* ------------------------------------------------------------------------- */


/*!
	\fn short MCHR_SetDigitalOutputFormat (MCHR_ID  SensorID, enDigitalOutputFormat OutputFormat)
	\if FR
		\brief Fonction de parametrage du format (ASCII/BIN) de la sortie digitale.
	\else
		\brief Set the digital outpout format (ASCII/BIN).
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] enDigitalOutputFormat *pOutputFormat : Tableau des formats des sorties digitales.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] enDigitalOutputFormat *pOutputFormat : Array with digital outputs formats.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : ALL
		\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API short MCHR_SetDigitalOutputFormat (MCHR_ID  SensorID, enDigitalOutputFormat OutputFormat);
/* ------------------------------------------------------------------------- */


/*!
	\fn short MCHR_GetSerialPort (MCHR_ID  SensorID)
	\if FR
		\brief Fonction de lecture du port serie sur lequel est  connecte le controleur.
	\else
		\brief Get the id of the serial port on which the controller is currently connected.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\return short : Numero de port du controleur.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\return short : Serial port number.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "UpdateSensorInfo" dans le module :
	\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API short MCHR_GetSerialPort (MCHR_ID  SensorID);
/* ------------------------------------------------------------- */

/*!
	\fn long MCHR_GetBaudRate (MCHR_ID  SensorID)
	\if FR
		\brief Fonction de lecture de la vitesse de communication avec le controleur connecte.
	\else
		\brief Get the current baud rate.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\return long : Baudrate du port serie.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\return long : Baud rate of the serial port.
		\endif
		\brief
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "UpdateSensorInfo()" dans le module :
	\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API long MCHR_GetBaudRate (MCHR_ID  SensorID);
/* ------------------------------------------------------------- */


/*!
	\fn short MCHR_GetMaxNumberOfTransmittedData (MCHR_ID  SensorID, WORD *MaxDataNumber)
	\if FR
		\brief Fonction de lecture du nombre Max de donnees pouvant etre transmises sur la liaison digitale.
	\else
		\brief Get the number of available data items (this depends on controller type).
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] WORD *MaxDataNumber : Nombre max de donnees transmissible.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] WORD *MaxDataNumber : Maximum number of data that can be sent via the digital output.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction  dans le module :
	\else
		\par Compatibles Sensors : ALL
		\endif
*/
DLL_CHR_API short MCHR_GetMaxNumberOfTransmittedData (MCHR_ID  SensorID, WORD *MaxDataNumber);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetIPAddress (MCHR_ID  SensorID,	char *Address)
	\if FR
		\brief Fonction permettant de lire l'adresse IP du capteur (depend du type de controleur.
	\else
		\brief Get sensor IP adress (this depends on controller type).
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] char *Address : Adresse IP du coffret.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] CHAR *Address : Controller's IP address.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "OnGetIPAddress () " dans le module :
	\else
		\par Compatibles Sensors : STIL-DUO
		\endif
*/
DLL_CHR_API short MCHR_GetIPAddress (MCHR_ID  SensorID,	char *Address);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetIPAddress (MCHR_ID  SensorID,	char *Address)
	\if FR
		\brief Fonction permettant de fixer l'adresse IP du capteur (depend du type de controleur.
	\else
		\brief Set sensor IP adress (this depends on controller type).
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] char *Address : Nouvelle adresse IP du coffret.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] char *Address : Controller's new IP address.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : STIL-DUO. 
	\else
		\par Compatibles Sensors : STIL-DUO. 
	\endif
*/
DLL_CHR_API short MCHR_SetIPAddress (MCHR_ID  SensorID,	char *Address);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetBarycenterScale (MCHR_ID  SensorID,	float *pValue)
	\if FR
		\brief Fonction permettant de lire la valeur de codage du barycentre.
	\else
		\brief Get barycenter-data ouput scale.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] float *pValue : Valeur d'echelle de mesure du barycentre.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] float *pValue : Barycenter scale value.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL.<br><br>
		\brief <b>Voir :</b> la fonction "OnAcqStop()" dans le module :
	\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
		\endif
*/
DLL_CHR_API short MCHR_GetBarycenterScale (MCHR_ID  SensorID,	float *pValue);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetBarycenterScale (MCHR_ID  SensorID,	float Value)
	\if FR
		\brief Fonction permettant de fixer la valeur de codage du barycentre.
	\else
		\brief Set scale for barycenter output.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] float pValue : Valeur d'echelle de mesure du barycentre.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] float pValue : Barycenter scale value.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
		\endif
*/
DLL_CHR_API short MCHR_SetBarycenterScale (MCHR_ID  SensorID,	float Value);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetBarycenterRef (MCHR_ID  SensorID,	float *pValue)
	\if FR
		\brief Fonction permettant de lire la valeur de reference du barycentre.
	\else
		\brief Get barycenter-data reference value.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] float *pValue : Valeur de reference du barycentre.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] float *pValue : Barycenter reference value.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "OnGetBarycenterRef()" dans le module :
	\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
		\endif
*/
DLL_CHR_API short MCHR_GetBarycenterRef (MCHR_ID  SensorID,	float *pValue);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetBarycenterRef (MCHR_ID  SensorID,	float Value)
	\if FR
		\brief Fonction permettant de fixer la valeur de reference du barycentre.
	\else
		\brief Set reference for barycenter output.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] float pValue : Valeur de reference de mesure du barycentre.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] float pValue : Barycenter reference value.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
		\endif
*/
DLL_CHR_API short MCHR_SetBarycenterRef (MCHR_ID  SensorID,	float Value);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetThicknessScale (MCHR_ID  SensorID,	float *pValue)
	\if FR
		\brief Fonction permettant de lire la valeur de codage en mode epaisseur.
	\else
		\brief Get thickness-mode output data scale.(for thickness and distance data items)(CCS only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] float pValue : Valeur de reference de mesure du barycentre.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] float pValue : Barycenter reference value.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL<br><br>
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
		\endif
*/
DLL_CHR_API short MCHR_GetThicknessScale (MCHR_ID  SensorID, float *pValue);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetThicknessScale (MCHR_ID  SensorID,	float Value)
	\if FR
		\brief Fonction permettant de fixer la valeur de codage en mode epaisseur.
	\else
		\brief Set scale for thickness and distance output in thickness mode (CCS only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] float Value : Valeur de reference de mesure du barycentre.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] float Value : Barycenter reference value.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
	\see MCHR_GetErrorDescription
*/

DLL_CHR_API short MCHR_SetThicknessScale (MCHR_ID  SensorID,	float Value);
/* ------------------------------------------------------------------------- */

/**************************************************************************
 ** Analog Outputs Configuration                                         **
 **************************************************************************/

/*!
	\fn short MCHR_GetAnalogOutput (MCHR_ID  SensorID, WORD AnaIndex, PWORD Data, PWORD ZeroValue, PWORD MaxValue)
	\if FR
		\brief Fonction de lecture de la configuration d'une sortie analogique.
		\warning Voir la fonction MCHR_GetAnalogOutputEx pour utiliser les parametres ZeroValue et MaxValue dans un format DWORD (à partir de la DLL_CHR V3.2.0.00)!
	\else
		\brief Get current configuration of analog output 
		\warning See  MCHR_GetAnalogOutputEx Function to use ZeroValue and MaxValue parameters on DWORD Format (from DLL_CHR V3.2.0.00)!
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] WORD AnaIndex		: Numero de la sortie analogique à configurer
			\param [out] PWORD Data		: Pointeur sur la mesure transmise sur la voie analogique configuree dans le CHR-150, la valeur est comprise entre 0 et 7.
			\param [out] PWORD ZeroValue	: Pointeur sur la valeur de l'echelle de mesure pour laquelle on aura 0 volt sur la sortie analogique.
			\param [out]PWORD MaxValue		: Pointeur sur la valeur de l'echelle de mesure pour laquelle on aura 10 volt sur la sortie analogique.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] WORD AnaIndex :  Number of analog output to be configured
			\param [out] PWORD Data : Pointer on the transmitted measuremen of the analog voice configured in THE CHR-150, the value is between 0 and 7.
			\param [out] PWORD ZeroValue : Pointer on the measurement scale value where the analog outpout have 0 Volts.
			\param [out] PWORD MaxValue : Pointer on the measurement scale value where the analog outpout have 10 Volts.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> CHR 150, CHR-150L, STIL-DUO, CCS PRIMA, CCS OPTIMA, CCS ULTIMA<br><br>
		\else
		\par Compatibles Sensors : CHR 150, CHR-150L, STIL-DUO, CCS PRIMA, CCS OPTIMA, CCS ULTIMA
		\endif
*/
DLL_CHR_API short MCHR_GetAnalogOutput (MCHR_ID  SensorID, WORD AnaIndex, PWORD Data, PWORD ZeroValue, PWORD MaxValue);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetAnalogOutputEx (MCHR_ID  SensorID, WORD AnaIndex, PWORD Data, PDWORD ZeroValue, PDWORD MaxValue)
	\if FR
		\brief Fonction de lecture de la configuration d'une sortie analogique.
		\warning Remplace la fonction MCHR_GetAnalogOutput.
	\else
		\brief Get current configuration of analog output 
		\warning Replace  the  MCHR_GetAnalogOutput Function.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] WORD AnaIndex		: Numero de la sortie analogique à configurer
			\param [out] PWORD Data		: Pointeur sur la mesure transmise sur la voie analogique configuree dans le CHR-150, la valeur est comprise entre 0 et 7.
			\param [out] PDWORD ZeroValue	: Pointeur sur la valeur de l'echelle de mesure pour laquelle on aura 0 volt sur la sortie analogique.
			\param [out] PDWORD MaxValue	: Pointeur sur la valeur de l'echelle de mesure pour laquelle on aura 10 volt sur la sortie analogique.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] WORD AnaIndex :  Number of analog output to be configured
			\param [out] PWORD Data : Pointer on the transmitted measuremen of the analog voice configured in THE CHR-150, the value is between 0 and 7.
			\param [out] PDWORD ZeroValue : Pointer on the measurement scale value where the analog outpout have 0 Volts.
			\param [out] PDWORD MaxValue : Pointer on the measurement scale value where the analog outpout have 10 Volts.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> CHR 150, CHR-150L, STIL-DUO, CCS PRIMA, CCS OPTIMA, CCS ULTIMA<br><br>
		\else
		\par Compatibles Sensors : CHR 150, CHR-150L, STIL-DUO, CCS PRIMA, CCS OPTIMA, CCS ULTIMA
		\endif
*/
DLL_CHR_API short MCHR_GetAnalogOutputEx (MCHR_ID  SensorID, WORD AnaIndex, PWORD Data, PDWORD ZeroValue, PDWORD MaxValue);
/* ------------------------------------------------------------------------- */



/*!
	\fn short MCHR_SetAnalogOutput (MCHR_ID  SensorID, WORD AnaIndex, WORD Data, WORD ZeroValue, WORD MaxValue)
	\if FR
		\brief Fonction de configuration d'une sortie analogique du capteur CHR-150.
		\warning Voir la fonction MCHR_SetAnalogOutputEx pour utiliser les parametres ZeroValue et MaxValue dans un format DWORD (à partir de la DLL_CHR V3.2.0.00)!
	\else
		\brief Set analog output parameters
		\warning See  MCHR_SetAnalogOutputEx Function to use ZeroValue and MaxValue parameters on DWORD Format (from DLL_CHR V3.2.0.00)!
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] WORD AnaIndex : 
			\param [] WORD Data :
			\param [] WORD ZeroValue :
			\param [] WORD MaxValue :
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] WORD AnaIndex :  Number of analog output to be configured
			\param [in] PWORD Data : Pointer on the transmitted measuremen of the analog voice configured in THE CHR-150, the value is between 0 and 7.
			\param [in] PWORD ZeroValue : Pointer on the measurement scale value where the analog outpout have 0 Volts.
			\param [in] PWORD MaxValue : Pointer on the measurement scale value where the analog outpout have 10 Volts.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : CHR 150, CHR-150L, STIL-DUO, CCS PRIMA, CCS OPTIMA, CCS ULTIMA
		\else
		\par Compatibles Sensors : CHR 150, CHR-150L, STIL-DUO, CCS PRIMA, CCS OPTIMA, CCS ULTIMA
		\endif

*/

DLL_CHR_API short MCHR_SetAnalogOutput (MCHR_ID  SensorID, WORD AnaIndex, WORD Data, WORD ZeroValue, WORD MaxValue);
/* ------------------------------------------------------------------------- */


/*!
	\fn short MCHR_SetAnalogOutputEx (MCHR_ID  SensorID, WORD AnaIndex, WORD Data, DWORD ZeroValue, DWORD MaxValue)
	\if FR
		\brief Fonction de configuration d'une sortie analogique du capteur CHR-150.
		\warning Remplace la fonction MCHR_SetAnalogOutput.
	\else
		\brief Set analog output parameters
		\warning Replace  the  MCHR_SetAnalogOutput Function.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] WORD AnaIndex : 
			\param [] WORD Data :
			\param [] DWORD ZeroValue :
			\param [] DWORD MaxValue :
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] WORD AnaIndex :  Number of analog output to be configured
			\param [in] PWORD Data : Pointer on the transmitted measuremen of the analog voice configured in THE CHR-150, the value is between 0 and 7.
			\param [in] PDWORD ZeroValue : Pointer on the measurement scale value where the analog outpout have 0 Volts.
			\param [in] PDWORD MaxValue : Pointer on the measurement scale value where the analog outpout have 10 Volts.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : CHR 150, CHR-150L, STIL-DUO, CCS PRIMA, CCS OPTIMA, CCS ULTIMA
		\else
		\par Compatibles Sensors : CHR 150, CHR-150L, STIL-DUO, CCS PRIMA, CCS OPTIMA, CCS ULTIMA
		\endif

*/

DLL_CHR_API short MCHR_SetAnalogOutputEx (MCHR_ID  SensorID, WORD AnaIndex, WORD Data, DWORD ZeroValue, DWORD MaxValue);
/* ------------------------------------------------------------------------- */

/**************************************************************************
 ** Dark signal Acquisition                                              **
 **************************************************************************/

/*!
	\fn short MCHR_AcqDark (MCHR_ID  SensorID, void *pMinFreq)
	\if FR
		\brief Fonction de lancement de la fonction Dark.
	\else
		\brief This function updates the Dark signal of the sensor at all acquisition rates and informs on the minimum authorized acquisition rate. (If some rates are not authorized, see the sensor Operating and Maintenance Manual for methods for cleaning the fiber optics). The dark signals are saved in the sensor non-volatile memory. <br> 
		\brief Note that the execution of this function may take a long time (of the order of one minute for some sensor types). No other commands should be sent to the sensor before processing of this command is done.
	\endif
	\if FR
		\param [in] MCHR_ID  SensorID : ID du coffret.
		\param [out] *pMinFreq : Valeur de frequence minimum apres Dark.
		\return short : un code d'erreur MCHR_ERROR.
	\else
		\param [in] MCHR_ID  SensorID : ID of the device.
		\param [out] *pMinFreq : Minimum frequence value after Dark.
		\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
	\endif
	\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "OnSetDark()" dans le module :
	\else
		\par Compatibles Sensors : ALL
		\endif
		
*/

DLL_CHR_API short MCHR_AcqDark (MCHR_ID  SensorID, void *pMinFreq);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_AcqFastDark (MCHR_ID  SensorID, WORD Average, float InfluenceValue)
	\if FR
		\brief Fonction d'execution de la commande de Dark Rapide.
	\else
		\brief Acquire "fast dark" (at current rate only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] WORD Average : entier indiquant le nombre d’acquisition successives à moyenner pour obtenir le dark de reference. Si egal à 0 on utilise les valeurs par defaut du chr.
			\param [in] float InfluenceValue : Pourcentage de l’influence des acquisitions faites sur le nouveau dark de reference. (ignore si Average == 0) 
			\return short : un code d'erreur MCHR_ERROR. <br><br>
			\brief Erreur specifique :<br>
			\arg \c MCHR_ERROR_DARK_NOT_VALID : erreur d'acquisition du DARK signal.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] WORD Average : number of sequential acquisitions to be averaged to get the darkref.(if is egal to 0, we use the sensor value by default).
			\param [in] FLOAT InfluenceValue : precentage of acquisition influences on the new darkref. ( ignored if Average = 0 )
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code. <br>
			\brief Specific error : \link MCHR_ERROR_DARK_NOT_VALID MCHR_ERROR_DARK_NOT_VALID :  \endlink Dark  acquisition failed
		\endif
		\brief
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
	\else
		\par Compatibles Sensors : ALL
	\endif
*/
DLL_CHR_API short MCHR_AcqFastDark (MCHR_ID  SensorID, WORD Average, float InfluenceValue);
/**************************************************************************
 ** White signal Acquisition                                              **
 **************************************************************************/

/*!
	\fn short MCHR_AcqWhite (MCHR_ID  SensorID)
	\if FR
		\brief Fonction de lancement de la fonction white.
	\else
		\brief Acquire White signal
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
		\par Compatibles Sensors : ALL Except RUBY and CHR Sensors
*/

DLL_CHR_API short MCHR_AcqWhite (MCHR_ID  SensorID);
/* ------------------------------------------------------------------------- */


/*!
	\fn short MCHR_AcqNormalizedWhite (MCHR_ID  SensorID)
	\if FR
		\brief Fonction d'execution de la commande de white normalized.
	\else
		\brief Acquire normalized White signal
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
		\par Compatibles Sensors : ALL Except RUBY and CHR sensors
*/

DLL_CHR_API short MCHR_AcqNormalizedWhite (MCHR_ID  SensorID);
/* ------------------------------------------------------------- */

/**************************************************************************
 ** Measurement                                                          **
 **************************************************************************/

/*!
	\fn short MCHR_GetDepthMeasurement  (MCHR_ID  SensorID, MCHR_tyAcqParam Parameters,	PFLOAT *pArrayDepth,	PFLOAT *pArrayIntensity, PFLOAT *pArrayCounter, PFLOAT *pArrayBarycenter, PFLOAT *pArrayStatus)
	\if FR
		\brief Fonction d'acquisition d'une sequence de points en mode distance mesurant la profondeur.
		\warning Cette fonction ne peut etre utilise pour les mesure de la donnée du Barycentre pour la calibration deu capteur.
	\else
		\brief This function allows acquiring the data measured by the sensor in distance mode. The Z axis points downwards, in other words, the z-coordinate ("depth") increases when the sample point gets further from the optical pen tip. In this mode, some the sensor models deliver 5 data per measured points (Depth, Intensity, Counter, Barycenter position, State).  For other models sensor models, counter and State data are not available. <br>
		\brief Before starting the acquisition, this function configures the sensor to the Distance measuring mode and directs the selected data (i.e. data for which the array pointer argument in the function call is not NULL ) to the digital output specified when opening the sensor.
		\warning This function should not be used for measuring Barycenter data for sensor calibration.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] MCHR_tyAcqParam Parameters : data structure for setting the measurement parameters
			\param [out] PFLOAT *pArrayDepth :
			\param [out] PFLOAT *pArrayIntensity :
			\param [out] PFLOAT *pArrayCounter :
			\param [out] PFLOAT *pArrayBarycenter :
			\param [out] PFLOAT *pArrayStatus :
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] MCHR_tyAcqParam Parameters : data structure for setting the measurement parameters
			\param [out] PFLOAT *pArrayDepth : an array of pointers to distance data buffers. If NULL, distance data is not acquired. (distance is in "Depth" mode, in other words, the Z axis points downwards).
			\param [out] PFLOAT *pArrayIntensity : an array of pointers to  intensity data buffers. If NULL, intensity data is not acquired.
			\param [out] PFLOAT *pArrayCounter : an array of pointers to the counter data buffers. If NULL, intensity data is not acquired. (Note: For some sensor models counter data is not available, please consult the User Manual)
			\param [out] PFLOAT *pArrayBarycenter : an array of pointers to Barycenter data buffers. If Null, Barycenter data is not acquired. (Barycenter data is peak position on the photodetector. This data is used for sensor calibration only).
			\param [out] PFLOAT *pArrayStatus : an array of pointers to the State data buffers. If NULL, State data is not acquired. (Note: For some sensor models State data is not available, please consult the User Manual)
			\param Note: the use of several buffers for the same data enables real-time processing of the data, e.g. real time display, as shown in the example bellow.
			\return short : A MCHR_ERROR code.<br><br>
			\brief Specific errors :
			\arg \c MCHR_ERROR_TRIGGER_TYPE: the specified trigger mode does not exist
			\arg \c MCHR_ERROR_START_RECEP_THREAD: an error occurred while attempting to start the acquisition thread
			\arg \c ERROR_CHR_BUFFER_FULL: the reception buffers are full, the data is not read rapidly enough
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\else
		\par Compatibles Sensors :  All Sensors in Chromatic Confocal mode.
		\endif
		\brief
	
*/

DLL_CHR_API short MCHR_GetDepthMeasurement  (MCHR_ID  SensorID, MCHR_tyAcqParam Parameters,	PFLOAT *pArrayDepth,	PFLOAT *pArrayIntensity, PFLOAT *pArrayCounter, PFLOAT *pArrayBarycenter, PFLOAT *pArrayStatus);

/*!
	\fn short MCHR_StartSpectrumAcquisition (MCHR_ID  SensorID, PWORD pwFirstUsablePixel, PWORD pwBufferSize)
	\if FR
		\brief Fonction de lancement de l'acquisition des spectres
	\else
		\brief Function to launch the acquisition of spectrum
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] PWORD pwFirstUsablePixel : retourne le numero du premier pixel utilisé pour l'acquisition du spectre
			\param [out] PWORD pwBufferSize : retourne la taille que devra avoir le buffer d'acquisition
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] PWORD pwBufferSize : returns the size that will be the acquisition buffer
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
		\par Compatibles Sensors : CCS_PRIMA, CCS_OPTIMA CCS_ULTIMA & MCHR_CCS_INITIAL
		\par See an example :
		\brief The \link Example6.cpp “Example6” \endlink sample program illustrating the acquisition of 10 spectrum.
		\endif
		\example Example6.cpp
*/

DLL_CHR_API short MCHR_StartSpectrumAcquisition  (MCHR_ID  SensorID, PWORD pwFirstUsablePixel, PWORD pwBufferSize);

/*!
	\fn short MCHR_StopSpectrumAcquisition (MCHR_ID  SensorID)
	\if FR
		\brief Fonction d'arrêt de l'acquisition des spectres
	\else
		\brief Stop function of the acquisition of spectrum
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
		\par Compatibles Sensors : CCS_PRIMA, CCS_OPTIMA CCS_ULTIMA & MCHR_CCS_INITIAL
		\par See an example :
		\brief The \link Example6.cpp “Example6” \endlink sample program illustrating the acquisition of 10 spectrum.
		\endif
		\example Example6.cpp
*/
DLL_CHR_API short MCHR_StopSpectrumAcquisition  (MCHR_ID  SensorID);


/*!
	\fn short MCHR_GetSpectrumAcquisitionData  (MCHR_ID  SensorID, unsigned short **ppSpectrum, unsigned short *pDataSize, enSpectrumAcquisitionResult *pSpectrumAcquisitionResult, long timeout)
	\if FR
		\brief Fonction d'acquisition d'une sequence de points en mode distance mesurant l'altitude
	\else
		\brief Acquisition function for "Distance/Altitude" mode (z axis sens=upward)(this function returns 5 buffers with following data: Altitude, Intensity, Barycenter position,Counter and Status)
		\warning This function should not be used for measuring Barycenter data for sensor calibration.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] unsigned short *pSpectrum : Données du spectre lu (ne pas oublier d'effacer le buffer après utilisation)
			\param [in] unsigned short DataSize : Taille des données du spectre (données)
			\param [out] enSpectrumAcquisitionResult *pSpectrumAcquisitionResult : Resultat de l'acquisition
			\param [out] long timeout : Timeout sortir de la fonction
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] unsigned short *pSpectrum : Spectrum data read (do not forget to clear the buffer after use)
			\param [in] unsigned short DataSize : Size spectrum data (data).
			\param [out] enSpectrumAcquisitionResult *pSpectrumAcquisitionResult : Result of the acquisition
			\param [out] long timeout : Out of the timeout function
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.<br><br>
		\endif
		\par Compatibles Sensors : CCS_PRIMA, CCS_OPTIMA CCS_ULTIMA & MCHR_CCS_INITIAL.
		\par See an example :
		\brief The \link Example6.cpp “Example6” \endlink sample program illustrating the acquisition of 10 spectrum.
		\endif
		\example Example6.cpp
*/
DLL_CHR_API short MCHR_GetSpectrumAcquisitionData(MCHR_ID  SensorID, unsigned short *pSpectrum, unsigned short DataSize, unsigned short *pCounter, enSpectrumAcquisitionResult *pSpectrumAcquisitionResult, long timeout);


/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetAltitudeMeasurement  (MCHR_ID  SensorID, MCHR_tyAcqParam Parameters,	PFLOAT *pArrayAltitude,	PFLOAT *pArrayIntensity,  PFLOAT *pArrayCounter, PFLOAT *pArrayBarycenter, PFLOAT *pArrayStatus)
	\if FR
		\brief Fonction d'acquisition d'une sequence de points en mode distance mesurant l'altitude
	\else
		\brief Acquisition function for "Distance/Altitude" mode (z axis sens=upward)(this function returns 5 buffers with following data: Altitude, Intensity, Barycenter position,Counter and Status)
		\warning This function should not be used for measuring Barycenter data for sensor calibration.
	\endif
	\details
		\if FR	
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] MCHR_tyAcqParam Parameters : data structure for setting the measurement parameters
			\param [out] PFLOAT *pArrayAltitude : Altitude
			\param [out] PFLOAT *pArrayIntensity : Intensite
			\param [out] PFLOAT *pArrayCounter : Compteur de points acquis
			\param [out] PFLOAT *pArrayBarycenter : Position du barycentre
			\param [out] PFLOAT *pArrayStatus : 
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] MCHR_tyAcqParam Parameters : data structure for setting the measurement parameters
			\param [out] PFLOAT *pArrayAltitude :  a pointer to  distance data buffer. If NULL, distance data is not acquired. (distance is in "Altitude" mode, in other words, the Z axis points upwards).
			\param [out] PFLOAT *pArrayIntensity : an array of pointers to  intensity data buffers. If NULL, intensity data is not acquired.
			\param [out] PFLOAT *pArrayCounter : an array of pointers to the counter data buffers. If NULL, intensity data is not acquired. (Note: For some sensor models counter data is not available, please consult the User Manual)
			\param [out] PFLOAT *pArrayBarycenter : an array of pointers to Barycenter data buffers. If Null, Barycenter data is not acquired. (Barycenter data is peak position on the photodetector. This data is used for sensor calibration only).
			\param [out] PFLOAT *pArrayStatus : an array of pointers to the State data buffers. If NULL, State data is not acquired. (Note: For some sensor models State data is not available, please consult the User Manual)
			\param Note: the use of several buffers for the same data enables real-time processing of the data, e.g. real time display, as shown in the example bellow.
			\return short : A MCHR_ERROR code.<br><br>
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.<br><br>
			\brief Specific errors :
			\arg \c MCHR_ERROR_TRIGGER_TYPE			:	the specified trigger mode does not exist
			\arg \c MCHR_ERROR_START_RECEP_THREAD	:	an error occurred while attempting to start the acquisition thread
			\arg \c ERROR_CHR_BUFFER_FULL			:	the reception buffers are full, the data is not read rapidly enough
		\endif
		\par Compatibles Sensors : All Sensors in Chromatic Confocal mode.
		
		\endif
		
*/

DLL_CHR_API short MCHR_GetAltitudeMeasurement  (MCHR_ID  SensorID, MCHR_tyAcqParam Parameters,	PFLOAT *pArrayAltitude,	PFLOAT *pArrayIntensity,  PFLOAT *pArrayCounter, PFLOAT *pArrayBarycenter, PFLOAT *pArrayStatus);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetThicknessMeasurement  (MCHR_ID  SensorID, MCHR_tyAcqParam Parameters,	PFLOAT *pArrayThickness, 
                                     PFLOAT *pArrayDistance1,	PFLOAT *pArrayIntensity1, PFLOAT *pArrayBarycenter1,
                                     PFLOAT *pArrayDistance2,	PFLOAT *pArrayIntensity2, PFLOAT *pArrayBarycenter2,
 									          PFLOAT *pArrayStatus, PFLOAT *pArrayCounter)
	\if FR
		\brief Fonction d'acquisition d'une sequence de points en mode epaisseur
	\else
		\brief Acquisition function for "Thickness" mode (this function returns 8 buffers with following data: Thickness, distance 1, intensity1, barycenter 1, distance 2,  intensity 2, barycenter 2, status)<br>
		\brief Before starting the acquisition, this function configures the sensor to the Thickness measuring mode and directs the selected data (i.e. data for which the array pointer argument in the function call is not NULL ) to the digital output specified when opening the CHR.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] MCHR_tyAcqParam Parameters : data structure for setting the measurement parameters
			\param [out] PFLOAT *pArrayThickness : Epaisseur
			\param [out] PFLOAT *pArrayDistance1 : Distance 1
			\param [out] PFLOAT *pArrayIntensity1 : Intensite 1
			\param [out] PFLOAT *pArrayBarycenter1 : Position du barycentre 1
			\param [out] PFLOAT *pArrayDistance2 : Distance 2
			\param [out] PFLOAT *pArrayIntensity2 : Intensite 2
			\param [out] PFLOAT *pArrayBarycenter2 : Position du barycentre 2
			\param [out] PFLOAT *pArrayStatus :
			\param [out] PFLOAT *pArrayCounter : an array of pointers to the counter data buffers. If NULL, intensity data is not acquired. (Note: For some sensor models counter data is not available, please consult the User Manual)
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] MCHR_tyAcqParam Parameters : data structure for setting the measurement parameters
			\param [out] PFLOAT *pArrayThickness :  a pointer to  distance data buffer. If NULL, distance data is not acquired. (distance is in "Thickness" mode, in other words).
			\param [out] PFLOAT *pArrayDistance1 : Distance 1
			\param [out] PFLOAT *pArrayIntensity1 : Intensity 1an array of pointers to  intensity data buffers. If NULL, intensity data is not acquired.
			\param [out] PFLOAT *pArrayBarycenter1 : an array of pointers to Barycenter data buffers. If Null, Barycenter 1 data is not acquired. (Barycenter data is peak position on the photodetector. This data is used for sensor calibration only).
			\param [out] PFLOAT *pArrayDistance2 : Distance 2
			\param [out] PFLOAT *pArrayIntensity2 : an array of pointers to  intensity data buffers. If NULL, intensity data is not acquired.
			\param [out] PFLOAT *pArrayBarycenter2 : an array of pointers to Barycenter 2 data buffers. If Null, Barycenter data is not acquired. (Barycenter data is peak position on the photodetector. This data is used for sensor calibration only).
			\param [out] PFLOAT *pArrayStatus : an array of pointers to the State data buffers. If NULL, State data is not acquired. (Note: For some sensor models State data is not available, please consult the User Manual)
			\param [out] PFLOAT *pArrayCounter : an array of pointers to the counter data buffers. If NULL, intensity data is not acquired. (Note: For some sensor models counter data is not available, please consult the User Manual)
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.<br><br>
			\brief Specific errors :
			\arg \c MCHR_ERROR_TRIGGER_TYPE: the specified trigger mode does not exist
			\arg \c MCHR_ERROR_START_RECEP_THREAD: an error occurred while attempting to start the acquisition thread
			\arg \c ERROR_CHR_BUFFER_FULL: the reception buffers are full, the data is not read rapidly enough
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS Sensors in Chromatic Confocal mode<br><br>
		\else
		\par Compatibles Sensors : ALL Sensors in Chromatic Confocal mode
		\endif
*/

DLL_CHR_API short MCHR_GetThicknessMeasurement  (MCHR_ID  SensorID, MCHR_tyAcqParam Parameters,	PFLOAT *pArrayThickness, 
                                     PFLOAT *pArrayDistance1,	PFLOAT *pArrayIntensity1, PFLOAT *pArrayBarycenter1,
                                     PFLOAT *pArrayDistance2,	PFLOAT *pArrayIntensity2, PFLOAT *pArrayBarycenter2,
 									          PFLOAT *pArrayStatus, PFLOAT *pArrayCounter);
/* ------------------------------------------------------------------------- */

/*!
	\fn short short MCHR_GetDataMeasurement  (MCHR_ID  SensorID, MCHR_tyAcqParam Parameters,	
										  PFLOAT *pArrayData0,	PFLOAT *pArrayData1, PFLOAT *pArrayData2, PFLOAT *pArrayData3, 
										  PFLOAT *pArrayData4, PFLOAT *pArrayData5, PFLOAT *pArrayData6, 
										  PFLOAT *pArrayData7)
	\if FR
		\brief Fonction d'acquisition d'une sequence de points dans le mode courant du CHR
		\warning l'interpretation des donnees depend du mode de mesure en cours
	\else
		\brief Rapid Acquisition Function for the current operating mode (This function returns 8 buffers.
		\warning The interpretation of the 8 data depends on the current mode
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] MCHR_tyAcqParam Parameters : Structure de paramètres pour configurer l'acquisition
			\param [out] PFLOAT *pArrayData0 : Tableau de pointeur(s) sur les buffers de donnees de la 1ère mesure (la signification depend du mode de mesure). Si le pointeur est NULL, la fonction n'acquière pas cette donnee.
			\param [out] PFLOAT *pArrayData1 : 
			\param [out] PFLOAT *pArrayData2 : 
			\param [out] PFLOAT *pArrayData3 : 
			\param [out] PFLOAT *pArrayData4 : 
			\param [out] PFLOAT *pArrayData5 : 
			\param [out] PFLOAT *pArrayData6 : 
			\param [out] PFLOAT *pArrayData7 :
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] MCHR_tyAcqParam Parameters : data structure for setting the measurement parameters
			\param [out] PFLOAT *pArrayData0 : Array of pointer on the data buffers for the measurement 1 ( the signification depend of measurement mode ). If is NULL, this data is ignored
			\param [out] PFLOAT *pArrayData1 : Array of pointer on the data buffers for the measurement 2 ( the signification depend of measurement mode ). If is NULL, this data is ignored
			\param [out] PFLOAT *pArrayData2 : Array of pointer on the data buffers for the measurement 3 ( the signification depend of measurement mode ). If is NULL, this data is ignored
			\param [out] PFLOAT *pArrayData3 : Array of pointer on the data buffers for the measurement 4 ( the signification depend of measurement mode ). If is NULL, this data is ignored
			\param [out] PFLOAT *pArrayData4 : Array of pointer on the data buffers for the measurement 5 ( the signification depend of measurement mode ). If is NULL, this data is ignored
			\param [out] PFLOAT *pArrayData5 : Array of pointer on the data buffers for the measurement 6 ( the signification depend of measurement mode ). If is NULL, this data is ignored
			\param [out] PFLOAT *pArrayData6 : Array of pointer on the data buffers for the measurement 7 ( the signification depend of measurement mode ). If is NULL, this data is ignored
			\param [out] PFLOAT *pArrayData7 : Array of pointer on the data buffers for the measurement 8 ( the signification depend of measurement mode ). If is NULL, this data is ignored
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/

DLL_CHR_API short MCHR_GetDataMeasurement  (MCHR_ID  SensorID, MCHR_tyAcqParam Parameters,	
										  PFLOAT *pArrayData0,	PFLOAT *pArrayData1, PFLOAT *pArrayData2, PFLOAT *pArrayData3, 
										  PFLOAT *pArrayData4, PFLOAT *pArrayData5, PFLOAT *pArrayData6, 
										  PFLOAT *pArrayData7);


/*!
	\fn short MCHR_InvertDistance  (MCHR_ID  SensorID, BOOL bInvert);
	\if FR
		\brief Fonction permettant le basculement Profondeur <> Altitude
	\else
		\brief Function fo tip up Deph <> Altitude
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] BOOL bInvert :  No null for Altitude, null for Depth
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] BOOL bInvert :  No null for Altitude, null for Depth
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
		\par Compatibles Sensors : ALL 
*/
DLL_CHR_API short MCHR_InvertDistance  (MCHR_ID  SensorID, BOOL bInvert);


/*!
	\fn short short MCHR_GetTransmittedDataMeasurement  (MCHR_ID  SensorID, MCHR_tyAcqParam Parameters,	PFLOAT *pArrayData0,	
                                PFLOAT *pArrayData1, PFLOAT *pArrayData2, PFLOAT *pArrayData3, PFLOAT *pArrayData4, 
                                PFLOAT *pArrayData5, PFLOAT *pArrayData6, PFLOAT *pArrayData7,
                                PFLOAT *pArrayData8, PFLOAT *pArrayData9, PFLOAT *pArrayData10,
                                PFLOAT *pArrayData11, PFLOAT *pArrayData12, PFLOAT *pArrayData13,
                                PFLOAT *pArrayData14, PFLOAT *pArrayData15);
	\if FR
		\brief Fonction d'acquisition d'une sequence de points dans le mode courant du CCS
		\warning l'interpretation des donnees depend du mode de mesure en cours
	\else
		\brief Rapid Acquisition Function for the current operating mode (This function returns 16 buffers).
		\warning The interpretation of the 16 data depends on the current mode
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] MCHR_tyAcqParam Parameters : data structure for setting the measurement parameters
			\param Merci de consulter la description de la fonction MCHR_SetTransmittedDigitalData() pour la definition des ojets des donnes de 0..15 pour chaque mode de mesure.
			\return short : un code d'erreur MCHR_ERROR.<br><br>
			\arg \c MCHR_ERROR_TRIGGER_TYPE: Le mode de trigger specifie n'existe pas
			\arg \c MCHR_ERROR_START_RECEP_THREAD: an error occurred while attempting to start the acquisition thread
			\arg \c ERROR_CHR_BUFFER_FULL: the reception buffers are full, the data is not read rapidly enough
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] MCHR_tyAcqParam Parameters : data structure for setting the measurement parameters
			\param Consult the description for the definition of data items 0..15 to be transmitted for each measuring mode by sensor :
			\arg \c <a target="_blank" href="duo.htm"><b>STIL DUO</b></a> - <a target="_blank" href="initial.htm"><b>STIL INITIAL</b></a> - <a target="_blank" href="prima.htm"><b>CCS PRIMA</b></a> - <a target="_blank" href="ultima.htm"><b>CCS ULTIMA</b></a> - <a target="_blank" href="optima.htm"><b>CCS OPTIMA</b></a>
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code. <br><br>
			\arg \c MCHR_ERROR_TRIGGER_TYPE: the specified trigger mode does not exist 
			\arg \c MCHR_ERROR_START_RECEP_THREAD: an error occurred while attempting to start the acquisition thread
			\arg \c ERROR_CHR_BUFFER_FULL: the reception buffers are full, the data is not read rapidly enough
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> All Sensors in Chromatic Confocal mode<br><br>
		\brief <b>Voir :</b> la fonction "OnAcqStop()" dans le module :
	\else
		\par Compatibles Sensors : All Sensors in Chromatic Confocal mode
	\endif
*/

DLL_CHR_API short MCHR_GetTransmittedDataMeasurement  (MCHR_ID  SensorID, MCHR_tyAcqParam Parameters,	PFLOAT *pArrayData0,	
                                PFLOAT *pArrayData1, PFLOAT *pArrayData2, PFLOAT *pArrayData3, PFLOAT *pArrayData4, 
                                PFLOAT *pArrayData5, PFLOAT *pArrayData6, PFLOAT *pArrayData7,
                                PFLOAT *pArrayData8, PFLOAT *pArrayData9, PFLOAT *pArrayData10,
                                PFLOAT *pArrayData11, PFLOAT *pArrayData12, PFLOAT *pArrayData13,
                                PFLOAT *pArrayData14, PFLOAT *pArrayData15);


/*!
	\fn short MCHR_GetInterferometricThickness  (MCHR_ID  SensorID, MCHR_tyAcqParam Parameters,	
                                     PFLOAT *pArrayThickness1, PFLOAT *pArrayThickness2, PFLOAT *pArrayThickness3,
                                     PFLOAT *pArrayQuality1,	PFLOAT *pArrayQuality2, PFLOAT *pArrayQuality3,
                                     PFLOAT *pArrayIntensity)
	\if FR
		\brief Fonction d'acquisition d'une sequence de points en mode interferometrique avec capteur CHR-150
	\else
		\brief Acquisition function for the Interferometric mode (this function returns 7 buffers for a series of measured points: Thickness1, Thickness2, Thickness3, Quality1, Quality2, Quality3, Intensity) <br>
		\brief Before starting the acquisition, this function configures the sensor to the Distance measuring mode and directs the selected data (i.e. data for which the array pointer argument in the function call is not NULL ) to the digital output specified when opening the CHR.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] MCHR_tyAcqParam Parameters :
			\param [out] PFLOAT *pArrayThickness1 : Epaisseur 1
			\param [out] PFLOAT *pArrayThickness2 : Epaisseur 2
			\param [out] PFLOAT *pArrayThickness3 : Epaisseur 3
			\param [out] PFLOAT *pArrayQuality1 : Qualite 1
			\param [out] PFLOAT *pArrayQuality2 : Qualite 2
			\param [out] PFLOAT *pArrayQuality3 : Qualite 3
			\param [out] PFLOAT *pArrayIntensity : Intensite
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] MCHR_tyAcqParam Parameters : data structure for setting the measurement parameters
			\param [out] PFLOAT *pArrayThickness1 :  a pointer to  distance data buffer. If NULL, distance data is not acquired. (distance is in "Thickness" mode, in other words).
			\param [out] PFLOAT *pArrayThickness2 : a pointer to  distance data buffer. If NULL, distance data is not acquired. (distance is in "Thickness" mode, in other words).
			\param [out] PFLOAT *pArrayThickness3 :  a pointer to  distance data buffer. If NULL, distance data is not acquired. (distance is in "Thickness" mode, in other words).
			\param [out] PFLOAT *pArrayQuality1 :  a pointer to  quality data buffer. If NULL, quality data is not acquired.
			\param [out] PFLOAT *pArrayQuality2 : a pointer to  quality data buffer. If NULL, quality data is not acquired.
			\param [out] PFLOAT *pArrayQuality3 : a pointer to  quality data buffer. If NULL, quality data is not acquired.
			\param [out] PFLOAT *pArrayIntensity : an array of pointers to  intensity data buffers. If NULL, intensity data is not acquired.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.<br><br>
			\brief Specific errors :
			\arg \c MCHR_ERROR_TRIGGER_TYPE: the specified trigger mode does not exist
			\arg \c MCHR_ERROR_START_RECEP_THREAD: an error occurred while attempting to start the acquisition thread
			\arg \c ERROR_CHR_BUFFER_FULL: the reception buffers are full, the data is not read rapidly enough
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> CHR 150, CHR-150PC, CHR-150L avec l'option Interferometric.<br><br>
		\brief <b>Voir :</b> la fonction "OnAcqStop()" dans le module :
	\else
		\par Compatibles Sensors : CHR 150, CHR-150PC, CHR-150L with Interferometric option 
	\endif
		
*/

DLL_CHR_API short MCHR_GetInterferometricThickness  (MCHR_ID  SensorID, MCHR_tyAcqParam Parameters,	
                                     PFLOAT *pArrayThickness1, PFLOAT *pArrayThickness2, PFLOAT *pArrayThickness3,
                                     PFLOAT *pArrayQuality1,	PFLOAT *pArrayQuality2, PFLOAT *pArrayQuality3,
                                     PFLOAT *pArrayIntensity);

/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetEncoderBuffer (MCHR_ID  SensorID, PDWORD *pArrayEncoder1,	PDWORD *pArrayEncoder2, PDWORD *pArrayEncoder3)
	\if FR
		\brief Fonction d'initialisation des buffers d'acquisition des codeurs
	\else
		\brief Initialization function for the buffers of encoder acquisition
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] PDWORD *pArrayEncoder1 :
			\param [] PDWORD *pArrayEncoder2 : 
			\param [] PDWORD *pArrayEncoder3 : 
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] PDWORD *pArrayEncoder1 : Arrays of encoder 1
			\param [in] PDWORD *pArrayEncoder2 : Arrays of encoder 2
			\param [in] PDWORD *pArrayEncoder3 : Arrays of encoder 3
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA
		\endif
*/
DLL_CHR_API short MCHR_SetEncoderBuffer (MCHR_ID  SensorID, PDWORD *pArrayEncoder1,	PDWORD *pArrayEncoder2, PDWORD *pArrayEncoder3);

/*!
	\fn short MCHR_SetAutoAdaptiveBuffer (MCHR_ID  SensorID, PFLOAT *pArrayAutoAdaptive)
	\if FR
		\brief Fonction d'initialisation du buffer de la frequence en mode autoadaptatif ou du niveau Led en mode AutoLed
	\else
		\brief Initialization function for the frequency buffers in autoadaptative mode or for Led level in Autoled mode
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] PFLOAT *pArrayAutoAdaptive :
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] PFLOAT *pArrayAutoAdaptive : address of buffer for collecting the auto-adaptive mode data
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, STIL-INITIAL
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, STIL-INITIAL
		\endif
*/

DLL_CHR_API short MCHR_SetAutoAdaptiveBuffer (MCHR_ID  SensorID, PFLOAT *pArrayAutoAdaptive);

/*!
	\fn short MCHR_StartAcquisition  (MCHR_ID  SensorID);
	\if FR
		\brief Fonction de lancement manuel de l'acquisition en attente de trigger
	\else
		\brief Function Wait for trigger, then start acquisition
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : ALL
		\else
		\par Compatibles Sensors : ALL
		\endif
*/

DLL_CHR_API short MCHR_StartAcquisition  (MCHR_ID  SensorID);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetMeasureDuration (MCHR_ID  SensorID, double *Duration);
	\if FR
		\brief Fonction donnant la duree d'une serie de mesure
	\else
		\brief Function Get the duration of a sequence of measurements
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] double *Duration : Duree d'une sequence de mesure
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] double *Duration : duration of a sequence of measurements
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\else
		\par Compatibles Sensors : ALL
		\endif
*/

DLL_CHR_API short MCHR_GetMeasureDuration (MCHR_ID  SensorID, double *Duration);
/* ------------------------------------------------------------- */

/*!
	\fn short MCHR_GetLastWrittenBuffer (MCHR_ID  SensorID, enAcqEventType EventType, long *IndexBuffer, long *IndexPoint)
	\if FR
		\brief Fonction retournant l'indice du dernier buffer ecrit pendant l'acquisition de points
	\else
		\brief Function Get the index of the last buffer written to during the acquisition which is currently in progress
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] enAcqEventType EventType :  
			\param [] long *IndexBuffer : Numero du buffer =-1 si pas d'acquisition en cours
			\param [] long *IndexPoint : Numero du point de mesure dans le buffer en cours = -1 si pas d'acquisition en cours
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] enAcqEventType EventType : Acquisition Event Type
			\param [out] long *IndexBuffer : Buffer number, if it is egal at -1 = no current acquisition.
			\param [out] long *IndexPoint : point number, if it is egal at -1 = no current acquisition.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\else
		\par Compatibles Sensors : ALL
		\endif
*/

DLL_CHR_API short MCHR_GetLastWrittenBuffer (MCHR_ID  SensorID, enAcqEventType EventType, long *IndexBuffer, long *IndexPoint);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetLastWrittenPoint (MCHR_ID  SensorID, long *Index)
	\if FR
		\brief Fonction retournant l'indice du dernier point de mesure ecrit dans le buffer courant pendant l'acquisition de points
	\else
		\brief Function Get the index of the last point written to the current buffer during the acquisition which is currently in progress
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] long *Index :
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] long *Index : point number, if it is egal at -1 = no current acquisition.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
	\else
		\par Compatibles Sensors : ALL
		\endif
*/

DLL_CHR_API short MCHR_GetLastWrittenPoint (MCHR_ID  SensorID, long *Index);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetLevelEdgeFlag (MCHR_ID  SensorID,	enLevelEdgeFlag *Value)
	\if FR
		\brief Fonction permettant de lire le niveau du signal ou le sens du front
	\else
		\brief Function Get active edge (or active state) for trigger (CCS only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] enLevelEdgeFlag *Value : valeur du bord actif
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] enLevelEdgeFlag *Value : value of the active edge
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\brief
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA
		\endif
*/

DLL_CHR_API short MCHR_GetLevelEdgeFlag (MCHR_ID  SensorID,	enLevelEdgeFlag *Value);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetLevelEdgeFlag (MCHR_ID  SensorID,	enLevelEdgeFlag Value)
	\if FR
		\brief Fonction permettant de fixer le niveau du signal ou le sens du front
	\else
		\brief Function Select active edge (or active state) for trigger signals (CCS only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] enLevelEdgeFlag Value :
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] enLevelEdgeFlag Value : value of the active edge
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA
	\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA
		\endif
*/

DLL_CHR_API short MCHR_SetLevelEdgeFlag (MCHR_ID  SensorID,	enLevelEdgeFlag Value);
/* ------------------------------------------------------------------------- */


/**************************************************************************
 ** Basic Setting                                                        **
 **************************************************************************/

/*!
	\fn short MCHR_SendConfig (MCHR_ID  SensorID,	LPCSTR ConfigFile)
	\if FR
		\brief Fonction de parametrage du système CHR
	\else
		\brief Function Send a configuration from a file to the CHR
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] LPCSTR ConfigFile : Nom du fichier comprenant les configuration par default du capteur. Si NULL, la configuration actuelle est pris en compte
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] LPCSTR ConfigFile : The name of a file comprising the default cTonfiguration for the sensor. If null, the current sensor configuration is read.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
	\else
		\par Compatibles Sensors : ALL
		\endif
*/

DLL_CHR_API short MCHR_SendConfig (MCHR_ID  SensorID,	LPCSTR ConfigFile);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_ReceiveConfig (MCHR_ID  SensorID, LPCSTR ConfigFile)
	\if FR
		\brief Fonction de lecture des parametres du CHR
	\else
		\brief Function Get the configuration from the CHR to a file
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] LPCSTR ConfigFile :
			\return short : un code d'erreur MCHR_ERROR. <br><br>
			\brief En plus des erreurs générales, les erreurs spécifiques sont :
			\arg \c  MCHR_ERROR_RECEIVE_CONFIG_CHR: Erreur de reception de la configuration du capteur.
			\arg \c  MCHR_ERROR_WRITE_CONFIG_FILE: Erreur pendant l'essai d'écriture de la configuration dans le fichier spécifié.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] LPCSTR ConfigFile : The name of a file comprising the default cTonfiguration for the sensor. If null, the current sensor configuration is read.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code. <br><br>
			\brief In addition to general errors, specific errors are:
			\arg \c  MCHR_ERROR_RECEIVE_CONFIG_CHR: error getting the sensor configuration
			\arg \c  MCHR_ERROR_WRITE_CONFIG_FILE: error while trying to write the configuration to the specified file
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
	\else
		\par Compatibles Sensors : ALL
		\endif
*/

DLL_CHR_API short MCHR_ReceiveConfig (MCHR_ID  SensorID, LPCSTR ConfigFile);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SaveCurrentConfiguration(MCHR_ID  SensorID)
	\if FR
		\brief Fonction permettant de sauvegarder la configuration du capteur specifie dans l'EEPROM
	\else
		\brief Function Save the configuration of the specified CHR to the EEPROM
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
		\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
	\else
		\par Compatibles Sensors : ALL
		\endif
*/

DLL_CHR_API short MCHR_SaveCurrentConfiguration(MCHR_ID  SensorID);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetScanRate (MCHR_ID  SensorID, WORD *pScanRate)
	\if FR
		\brief Fonction de lecture de la cadence du CHR
	\else
		\brief Function Get current acquisition pre-defined rate id
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] WORD *pScanRate : frequence d'acquisition du capteur
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] WORD *pScanRate : current acquisition pre-defined rate id
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
	\else
		\par Compatibles Sensors : ALL
		\endif
*/


DLL_CHR_API short MCHR_GetScanRate (MCHR_ID  SensorID, WORD *pScanRate);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetScanRate (MCHR_ID  SensorID, WORD ScanRate)
	\if FR
		\brief Fonction de parametrage de la cadence du CHR
	\else
		\brief Function Set CHR Acquisition rate
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] WORD ScanRate : Cadence du CHR
			\return short : un code d'erreur MCHR_ERROR. <br><br>
			\brief Erreur specifique :
			\arg \c MCHR_ERROR_SCANRATE_TOO_HIGH: la vitesse est trop elevee pour transmettre toutes les détails des données actuelement configurés
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] WORD ScanRate : CHR Acquisition rate
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code. <br><br>
			\brief Specific error :
			\arg \c MCHR_ERROR_SCANRATE_TOO_HIGH: the rate is too high for transmitting all data items currently configured
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : ALL
	\else
		\par Compatibles Sensors : ALL
		\endif
*/

DLL_CHR_API short MCHR_SetScanRate (MCHR_ID  SensorID, WORD ScanRate);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetAveraging (MCHR_ID  SensorID, PWORD pAveragingValue)
	\if FR
		\brief Fonction de lecture du taux de moyennage du CHR
	\else
		\brief Function Get current averaging mode
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] PWORD pAveragingValue : 
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] PWORD pAveragingValue : a pointer to the averaging factor.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\else
		\par Compatibles Sensors : ALL
		\endif
*/

DLL_CHR_API short MCHR_GetAveraging (MCHR_ID  SensorID, PWORD pAveragingValue);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetAveraging (MCHR_ID  SensorID, WORD AveragingValue)
	\if FR
		\brief Fonction de parametrage du taux de moyennage du CHR
	\else
		\brief Function Set averaging factor (ratio of acquisition rate to output rate)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] WORD AveragingValue : Taux de moyennage du CHR
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] WORD AveragingValue : Ratio of averaging acquisition rate
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : ALL
	\else
		\par Compatibles Sensors : ALL
		\endif
*/

DLL_CHR_API short MCHR_SetAveraging (MCHR_ID  SensorID, WORD AveragingValue);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetOpticalPen (MCHR_ID  SensorID,	PWORD pOpticalPen, PWORD pFullScale)
	\if FR
		\brief Fonction de lecture du crayon optique selectionne  dans le CHR
		\warning Voir la fonction MCHR_GetOpticalPenEx pour utiliser le parametre pFullScale dans un format DWORD (à partir de la DLL_CHR V3.2.0.00)!
	\else
		\brief Function Get current optical pen (= index of current calibration table)
		\warning See  MCHR_GetOpticalPenEx Function to use pFullScale parameter on DWORD Format (from DLL_CHR V3.2.0.00)!
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] PWORD pOpticalPen : 
			\param [] PWORD pFullScale : 
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] PWORD pOpticalPen : a pointer to the identifier of the calibration table selected.
			\param [out] PWORD pFullScale : a pointer to the measuring range (value given in microns) a pen number of MCHR_NO_PEN (999)  or a measuring range of 65535 indicate the no pen is currently selected.
			\return short : A A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\brief
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
	\else
		\par Compatibles Sensors : ALL except STIL-INITIAL
		\endif
		
*/

DLL_CHR_API short MCHR_GetOpticalPen (MCHR_ID  SensorID,	PWORD pOpticalPen, PWORD pFullScale);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetOpticalPenEx (MCHR_ID  SensorID,	PWORD pOpticalPen, PDWORD pFullScale)
	\if FR
		\brief Fonction de lecture du crayon optique selectionne  dans le CHR
		\warning Remplace la fonction MCHR_GetOpticalPen.
	\else
		\brief Function Get current optical pen (= index of current calibration table)
		\warning Replace  the  MCHR_GetOpticalPen Function.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] PWORD pOpticalPen : 
			\param [] PDWORD pFullScale : 
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] PWORD pOpticalPen : a pointer to the identifier of the calibration table selected.
			\param [out] PDWORD pFullScale : a pointer to the measuring range (value given in microns) a pen number of MCHR_NO_PEN (999)  or a measuring range of 65535 indicate the no pen is currently selected.
			\return short : A A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\brief
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
	\else
		\par Compatibles Sensors : ALL except STIL-INITIAL
		\endif
		
*/

DLL_CHR_API short MCHR_GetOpticalPenEx (MCHR_ID  SensorID,	PWORD pOpticalPen, PDWORD pFullScale);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetOpticalPen (MCHR_ID  SensorID,	WORD OpticalPen, PWORD pFullScale)
	\if FR
		\brief Fonction de parametrage du crayon optique du CHR
		\warning Voir la fonction MCHR_SetOpticalPenEx pour utiliser le parametre pFullScale dans un format DWORD (à partir de la DLL_CHR V3.2.0.00)!
	\else
		\brief Function Set the optical pen selection (this function selects one of the existing calibration tables in the CHR)
		\warning See  MCHR_SetOpticalPennEx Function to use pFullScale parameter on DWORD Format (from DLL_CHR V3.2.0.00)!
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] WORD OpticalPen :
			\param [in] PWORD pFullScale :
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [] WORD OpticalPen : a pointer to the identifier of the calibration table selected
			\param [] PWORD pFullScale : a pointer to the measuring range (value given in microns) a pen number of MCHR_NO_PEN (999)  or a measuring range of 65535 indicate the no pen is currently selected.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : ALL
	\else
		\par Compatibles Sensors : ALL except STIL-INITIAL
		\endif
*/

DLL_CHR_API short MCHR_SetOpticalPen (MCHR_ID  SensorID,	WORD OpticalPen, PWORD pFullScale);
/* ------------------------------------------------------------------------- */


/*!
	\fn short MCHR_SetOpticalPenEx (MCHR_ID  SensorID,	WORD OpticalPen, PDWORD pFullScale)
	\if FR
		\brief Fonction de parametrage du crayon optique du CHR
		\warning Remplace la fonction MCHR_SetOpticalPen.
	\else
		\brief Function Set the optical pen selection (this function selects one of the existing calibration tables in the CHR)
		\warning Replace  the  MCHR_SetOpticalPen Function.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] WORD OpticalPen :
			\param [in] PDWORD pFullScale :
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [] WORD OpticalPen : a pointer to the identifier of the calibration table selected
			\param [] PDWORD pFullScale : a pointer to the measuring range (value given in microns) a pen number of MCHR_NO_PEN (999)  or a measuring range of 65535 indicate the no pen is currently selected.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : ALL
	\else
		\par Compatibles Sensors : ALL except STIL-INITIAL
		\endif
*/

DLL_CHR_API short MCHR_SetOpticalPenEx (MCHR_ID  SensorID,	WORD OpticalPen, PDWORD pFullScale);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetMeasureMode (MCHR_ID  SensorID, enMeasureMode *Mode)
	\if FR
		\brief Fonction de lecture du mode de mesure en cours d'utilisation (Distance ou Epaisseur)
	\else
		\brief Function Get current measurement mode (Distance or Thickness).
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] enMeasureMode *Mode : mode de mesure en cours d'utilisation
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] enMeasureMode *Mode : current measurement mode
			\return short : A A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\else
		\par Compatibles Sensors : ALL
		\endif
*/

DLL_CHR_API short MCHR_GetMeasureMode (MCHR_ID  SensorID, enMeasureMode *Mode);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetMeasureMode (MCHR_ID  SensorID, enMeasureMode Mode)
	\if FR
		\brief Fonction de configuration du mode de mesure
	\else
		\brief Function Set measurement mode (distance/thickness)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] enMeasureMode Mode : Mode de mesure selectionne
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] enMeasureMode Mode : Current measurement mode
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : ALL
		\else
		\par Compatibles Sensors : ALL
		\endif
*/

DLL_CHR_API short MCHR_SetMeasureMode (MCHR_ID  SensorID, enMeasureMode Mode);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetRefractiveIndex (MCHR_ID  SensorID, float *RefractiveIndexValue)
	\if FR
		\brief Fonction de lecture de l'indice de refraction
	\else
		\brief Function Get the refractive index
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] float *RefractiveIndexValue : Indice de Refraction utilise
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] float *RefractiveIndexValue : Current Refractive Index
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\else
		\par Compatibles Sensors : ALL
		\endif
*/

DLL_CHR_API short MCHR_GetRefractiveIndex (MCHR_ID  SensorID, float *RefractiveIndexValue);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetRefractiveIndex (MCHR_ID  SensorID, float RefractiveIndexValue)
	\if FR
		\brief Fonction de parametrage de l'indice de refraction
	\else
		\brief Function Set the refractive index
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] float RefractiveIndexValue : Indice de refraction selectionne
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] float RefractiveIndexValue : Selected Refractive Index
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : ALL except STIL-DUO in SAWLI mode 
		\else
		\par Compatibles Sensors : ALL except STIL-DUO in SAWLI mode 
		\endif
*/

DLL_CHR_API short MCHR_SetRefractiveIndex (MCHR_ID  SensorID, float RefractiveIndexValue);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetDetectionThreshold (MCHR_ID  SensorID, float *ThresholdValue)
	\if FR
		\brief Fonction de lecture du seuil de detection
	\else
		\brief Function Get the peak detection threshold
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] float *ThresholdValue : Seuil de detection utilise
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] FLOAT *ThresholdValue : Current Threshold value
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
	\else
		\par Compatibles Sensors : ALL
		\endif
*/

DLL_CHR_API short MCHR_GetDetectionThreshold (MCHR_ID  SensorID, float *ThresholdValue);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetDetectionThreshold (MCHR_ID  SensorID, float ThresholdValue)
	\if FR
		\brief Fonction de parametrage du seuil de detection
	\else
		\brief Function Set the peak detection threshold
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] float ThresholdValue : Seuil de detection selectionne
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] float ThresholdValue : Selected Threshold value
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : ALL
		\else
		\par Compatibles Sensors : ALL
		\endif
*/

DLL_CHR_API short MCHR_SetDetectionThreshold (MCHR_ID  SensorID, float ThresholdValue);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetMinDarkFrequency (MCHR_ID  SensorID, WORD *pScanRate)
	\if FR
		\brief Fonction de lecture de la cadence du CHR
	\else
		\brief Function Get current acquisition pre-defined rate id
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] WORD *pScanRate : 
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] WORD *pScanRate : the min authorized rate, in Hz
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-DUO, STIL-INITIAL<br><br>
	\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-DUO, STIL-INITIAL
	\endif
*/

DLL_CHR_API short MCHR_GetMinDarkFrequency (MCHR_ID  SensorID, WORD *pScanRate);
/* ------------------------------------------------------------------------- */


/**************************************************************************
 ** Advanced Setting                                                        **
 **************************************************************************/

/*!
	\fn short MCHR_GetLed (MCHR_ID  SensorID,	PWORD pValue)
	\if FR
		\brief Fonction permettant de lire la valeur de l'intensite de la LED
	\else
		\brief Function Get LED intensity value
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] PWORD pValue : Valeur de l'intensite de la LED 
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID	: ID of the device.
			\param [out]	PWORD pValue		: Current LED intensity value
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> CCS PRIMA, CCS OPTIMA, STIL-INITIAL, STIL-DUO in Chromatic Confocal mode.<br><br>
		\brief <b>Voir :</b> la fonction "OnAcqStop()" dans le module :
	\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, STIL-INITIAL, STIL-DUO in Chromatic Confocal mode
		\endif
*/

DLL_CHR_API short MCHR_GetLed (MCHR_ID  SensorID,	PWORD pValue);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetLed (MCHR_ID  SensorID,	WORD Value)
	\if FR
		\brief Fonction permettant de fixer la valeur de l'intensite de la LED
	\else
		\brief Function Set LED intensity value
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] WORD Value : Valeur de l'intensite de la LED selectionnee 
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] WORD Value : Selected LED intensity value
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, STIL-INITIAL, STIL-DUO in Chromatic Confocal mode
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, STIL-INITIAL, STIL-DUO in Chromatic Confocal mode
		\endif
*/

DLL_CHR_API short MCHR_SetLed (MCHR_ID  SensorID,	WORD Value);
/* ------------------------------------------------------------------------- */

/*
 Fonction permettant de lire le mode de selection du pic (MCHR_HIGH_PEAK, MCHR_FIRST_PEAK, MCHR_LAST_PEAK
 Get current peak selection mode (CCS only)
*/

/*!
	\fn short MCHR_GetPeakSelectionMode (MCHR_ID  SensorID,	enPeakSelectionMode *pPeakMode)
	\if FR
		\brief Fonction permettant de lire le mode de selection du pic (CCS uniquement)
	\else
		\brief Function Get current peak selection mode (CCS only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] enPeakSelectionMode *pPeakMode : mode de selection du pic utilise
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] enPeakSelectionMode *pPeakMode : current peak selection mode
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL<br><br>
		\brief <b>Voir :</b> la fonction "OnGetPeakSelectionMode()" dans le module :
	\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
			\endif
*/

DLL_CHR_API short MCHR_GetPeakSelectionMode (MCHR_ID  SensorID,	enPeakSelectionMode *pPeakMode);
/* ------------------------------------------------------------------------- */

/*
 Fonction permettant de configurer le mode de selection du pic (MCHR_HIGH_PEAK, MCHR_FIRST_PEAK, MCHR_LAST_PEAK
 Set Peak-selction mode (CCS only)
*/

/*!
	\fn short MCHR_SetPeakSelectionMode (MCHR_ID  SensorID,	enPeakSelectionMode PeakMode)
	\if FR
		\brief Fonction permettant de configurer le mode de selection du pic (CCS uniquement)
	\else
		\brief Function Set Peak-selction mode (CCS only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] enPeakSelectionMode PeakMode : mode de selection du pic choisi
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] enPeakSelectionMode PeakMode *pPeakMode : selected peak selection mode
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
		\endif
*/

DLL_CHR_API short MCHR_SetPeakSelectionMode (MCHR_ID  SensorID,	enPeakSelectionMode PeakMode);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetThicknessDetectionThresholds (MCHR_ID  SensorID,	float *pFirstPeakThreshold, float *pSecondPeakThreshold)
	\if FR
		\brief Fonction permettant de lire les seuils de detection du premier pic et du 2eme Pic en mode epaisseur
	\else
		\brief Function Get current detection thresholds for thickness mode
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] float *pFirstPeakThreshold : Premier pic detecte
			\param [] float *pSecondPeakThreshold : Second pic detecte
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] float *pFirstPeakThreshold : First detected peak 
			\param [out] float *pSecondPeakThreshold : Second detected peak
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL<br><br>
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
	\endif
*/

DLL_CHR_API short MCHR_GetThicknessDetectionThresholds (MCHR_ID  SensorID,	float *pFirstPeakThreshold, float *pSecondPeakThreshold);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetThicknessDetectionThresholds (MCHR_ID  SensorID,	float FirstPeakThreshold, float SecondPeakThreshold)
	\if FR
		\brief Fonction permettant de fixer les seuils de detection du premier pic et du 2eme Pic en mode epaisseur
	\else
		\brief Function Set detection-thresholds in case of thickness mode
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] float FirstPeakThreshold : Affectation de la valeur du seuil du premier pic
			\param [in] float SecondPeakThreshold : Affectation de la valeur du seuil du second pic
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] float FirstPeakThreshold : First selected peak threshold 
			\param [in] float SecondPeakThreshold : Second selected peak threshold
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
		\endif
*/

DLL_CHR_API short MCHR_SetThicknessDetectionThresholds (MCHR_ID  SensorID,	float FirstPeakThreshold, float SecondPeakThreshold);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetHoldLastValue (MCHR_ID  SensorID,	PWORD pValue)
	\if FR
		\brief Fonction permettant de lire la valeur du mode "hold last value" (memorisation de la dernière valeur pendant n acquisition)
	\else
		\brief Function Get "Hold last value" parameter. 0 or positive. (CCS only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] PWORD pValue : valeur du mode "hold last value"
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] PWORD pValue : "Hold last value" parameter
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL<br><br>
		\brief <b>Voir :</b> la fonction "OnAcqStop()" dans le module :
	\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
		\endif
*/

DLL_CHR_API short MCHR_GetHoldLastValue (MCHR_ID  SensorID,	PWORD pValue);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetHoldLastValue (MCHR_ID  SensorID,	WORD Value)
	\if FR
		\brief Fonction permettant de fixer la valeur du mode "hold last value" (memorisation de la dernière valeur pendant n acquisition)
	\else
		\brief Function Get "Hold last value" parameter. (CCS only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] WORD Value : valeur du mode "hold last value" selectionne
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] WORD Value : Selected "Hold last value" parameter
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
		\endif
*/

DLL_CHR_API short MCHR_SetHoldLastValue (MCHR_ID  SensorID,	WORD Value);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetRefractiveIndexFile (MCHR_ID  SensorID, PWORD pwIndexFileIndice,PREFRACTIVE_FILE_INFO)
	\if FR
		\brief Fonction de lecture du nom du fichier d'indice de refraction
	\else
		\brief Function Get the refractive index file
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] PWORD pwIndexFileIndice : pointeur sur le nom de fichier d'indice selectionne
			\param [] PREFRACTIVE_FILE_INFO : 
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] PWORD pwIndexFileIndice : pointer on the file name of index selected
			\param [out] PREFRACTIVE_FILE_INFO : Information file
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/

DLL_CHR_API short MCHR_GetRefractiveIndexFile (MCHR_ID  SensorID, PWORD pwIndexFileIndice,PREFRACTIVE_FILE_INFO);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetRefractiveIndexFile (MCHR_ID  SensorID, WORD wIndexFileIndice,LPSTR szMaterialDesc)
	\if FR
		\brief Fonction de parametrage du fichier d'indice de refraction
	\else
		\brief Function Set the refractive index
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] WORD wIndexFileIndice : pointeur sur le nom de fichier d'indice à selectionner
			\param [in] LPSTR szMaterialDesc :
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] WORD wIndexFileIndice :  pointer on the file name of index selected
			\param [in] LPSTR szMaterialDesc : descriptive of material
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/

DLL_CHR_API short MCHR_SetRefractiveIndexFile (MCHR_ID  SensorID, WORD wIndexFileIndice,LPSTR szMaterialDesc);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetAutoDarkMode (MCHR_ID  SensorID,	enAutoDarkMode *pMode)
	\if FR
		\brief Fonction permettant de lire la valeur du mode de Dark Automatique.
	\else
		\brief Function Get automatic-dark activation flag (CCS only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] enAutoDarkMode *pMode : 
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] enAutoDarkMode *pMode :  make take one of the following values : 
			\arg  MCHR_MANUAL DARK : “Auto adaptive dark “ mode Disable
			\arg  MCHR_AUTO_DARK: “Auto adaptive dark “ mode Enable
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "OnGetAutoDarkMode()" dans le module :
	\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
		\endif
*/

DLL_CHR_API short MCHR_GetAutoDarkMode (MCHR_ID  SensorID,	enAutoDarkMode *pMode);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetAutoDarkMode (MCHR_ID  SensorID,	enAutoDarkMode pMode)
	\if FR
		\brief Fonction permettant de fixer la valeur du mode de Dark Automatique
	\else
		\brief Function Activate/Deactivate Automatic Dark mode (CCS only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] enAutoDarkMode pMode : valeur du mode de Dark Automatique selectionne
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] enAutoDarkMode pMode : Selected Automatic Dark mode value
			\arg \c  MCHR_MANUAL DARK : Disable “Auto adaptive dark “ mode 
			\arg \c  MCHR_AUTO_DARK: Enable “Auto adaptive dark “ mode 
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA, STIL-INITIAL
		\endif
*/

DLL_CHR_API short MCHR_SetAutoDarkMode (MCHR_ID  SensorID,	enAutoDarkMode pMode);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetAutoModeThreshold (MCHR_ID  SensorID,	PWORD Value)
	\if FR
		\brief Fonction permettant de lire  la valeur de seuil pour les modes automatique (Auto LED et Auto Rate)
	\else
		\brief Function Get Threshold Automatic mode value (Auto LED et Auto Rate)(CCS only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] PWORD Value : Valeur de seuil pour les modes automatiques utilises
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] PWORD Value : Current Threshold Automatic mode value
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> CCS PRIMA, CCS OPTIMA, STIL-INITIAL<br><br>
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, STIL-INITIAL
		\endif
*/

DLL_CHR_API short MCHR_GetAutoModeThreshold (MCHR_ID  SensorID,	PWORD Value);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetAutoModeThreshold (MCHR_ID  SensorID,	WORD Value)
	\if FR
		\brief Fonction permettant de fixer la valeur de seuil pour les modes automatique (Auto LED et Auto Rate)
	\else
		\brief Function Activate/Deactivate Automatic Dark mode (Auto LED et Auto Rate)(CCS only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] WORD Value : Valeur de seuil pour les modes automatique choisie
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] WORD Value : Selected Threshold Automatic mode value
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, STIL-INITIAL
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, STIL-INITIAL
		\endif
*/

DLL_CHR_API short MCHR_SetAutoModeThreshold (MCHR_ID  SensorID,	WORD Value);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetAutoRateMode (MCHR_ID  SensorID,	BOOL *Flag)
	\if FR
		\warning  OBSOLETE
	\else
		\warning  OBSOLETE
	\endif
*/

DLL_CHR_API short MCHR_GetAutoRateMode (MCHR_ID  SensorID,	BOOL *Flag);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetAutoRateMode (MCHR_ID  SensorID,	BOOL Flag)
	\if FR
		\brief Fonction permettant de passer en mode frequence Automatique
	\else
		\brief Function allowing to actvate the automatic frequency mode(CCS only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] BOOL Flag : valeur = 0 mode desactive ou valeur = 1 mode active
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] BOOL Flag : value = 0 mode not activated or value = 1 mode activated
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/

DLL_CHR_API short MCHR_SetAutoRateMode (MCHR_ID  SensorID,	BOOL Flag);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetAutoLedMode (MCHR_ID  SensorID,	BOOL *pFlag)
	\if FR
		\brief Fonction permettant de Lire la valeur du flag AutoLed
	\else
		\brief Function to Get the AutoLed value flag
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] BOOL *pFlag : valeur = 0 mode desactive ou valeur = 1 mode active
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] BOOL *pFlag : value = 0 mode not activated or value = 1 mode activated
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> CCS PRIMA, CCS OPTIMA, STIL-INITIAL<br><br>
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, STIL-INITIAL
		\brief The "OnGetAutoLedMode()" function in the \link SampleCHRDlg.cpp SampleCHRDlg.cpp \endlink module.<br>
		\endif
	
		
*/

DLL_CHR_API short MCHR_GetAutoLedMode (MCHR_ID  SensorID,	BOOL *pFlag);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetAutoLedMode (MCHR_ID  SensorID,	BOOL Flag)
	\if FR
		\brief Fonction permettant de fixer la valeur du flag AutoLed
	\else
		\brief Function to Set the AutoLed value flag
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] BOOL Flag : valeur = 0 mode desactive ou valeur = 1 mode active
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] BOOL Flag : value = 0 mode not activated or value = 1 mode activated
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, STIL-INITIAL
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, STIL-INITIAL
		\endif
*/

DLL_CHR_API short MCHR_SetAutoLedMode (MCHR_ID  SensorID,	BOOL Flag);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetExposureTime (MCHR_ID  SensorID, PWORD ExposureTime)
	\if FR
		\brief Fonction de lecture du temps d'exposition du CHR-450 en microsecondes
	\else
		\brief Function Get CHR current exposure time in microseconds
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] PWORD ExposureTime : temps d'exposition du CHR-450
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] PWORD ExposureTime : CHR current exposure time
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS exceptés CHR 150, CHR-150PC, CHR150L.<br><br>
		\brief <b>Voir :</b> la fonction "OnGetExposureTime()" dans le module :
	\else
		\par Compatibles Sensors : ALL except: CHR 150, CHR-150PC, CHR150L
		\endif
*/

DLL_CHR_API short MCHR_GetExposureTime (MCHR_ID  SensorID, PWORD ExposureTime);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetExposureTimeDW (MCHR_ID  SensorID, PDWORD ExposureTime)
	\if FR
		\brief Fonction de lecture du temps d'exposition du CHR-450 en microsecondes 
	\else
		\brief Function Get CHR current exposure time in microseconds
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out]PDWORD ExposureTime : temps d'exposition du CHR-450
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] PDWORD ExposureTime : CHR current exposure time
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription

*/

DLL_CHR_API short MCHR_GetExposureTimeDW (MCHR_ID  SensorID, PDWORD ExposureTime);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetExposureTime (MCHR_ID  SensorID, WORD ExposureTime)
	\if FR
		\brief Fonction de parametrage de la cadence du CHR-450 par le temps d'exposition
	\else
		\brief Function Set CHR Acquisition rate by specifying exposure time
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] WORD ExposureTime : Selection du temps d'exposition du CHR-450 en microsecondes
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] WORD ExposureTime : CHR selected exposure time in microseconds
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/

DLL_CHR_API short MCHR_SetExposureTime (MCHR_ID  SensorID, WORD ExposureTime);

/*!
	\fn short MCHR_SetExposureTimeDW (MCHR_ID  SensorID, DWORD ExposureTime)
	\if FR
		\brief Fonction de parametrage de la cadence du CHR-450 par le temps d'exposition
	\else
		\brief Function Set CHR Acquisition rate by specifying exposure time
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] DWORD ExposureTime : Selection du temps d'exposition du CHR-450 en microsecondes
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] DWORD ExposureTime : CHR selected exposure time in microseconds
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/

DLL_CHR_API short MCHR_SetExposureTimeDW (MCHR_ID  SensorID, DWORD ExposureTime);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetFreeFrequency (MCHR_ID  SensorID, long iFrequency)
	\if FR
		\brief Fonction de parametrage de la cadence des CHR et des CCS frequence
	\else
		\brief Function Set CHR Acquisition rate by specifying frequency
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long iFrequency : Selection de la cadence des CHR et des frequences CCS
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long iFrequency : Selection of the sensor frequency
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\if FR 
			\par Capteurs Compatibles :TOUS.
		\else
			\par Compatibles Sensors : ALL.
		\endif
*/

DLL_CHR_API short MCHR_SetFreeFrequency (MCHR_ID  SensorID, long iFrequency);

/*
 Fonction de parametrage de la cadence des CHR et des CCS frequence
 Set CHR Acquisition rate by specifying frequency
*/

/*!
	\fn short MCHR_GetFreeFrequency (MCHR_ID  SensorID, long* iFrequency)
	\if FR
		\brief Fonction de lecture de la cadence des CHR et des CCS frequence
	\else
		\brief Function Get CHR Acquisition rate by specifying frequency
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] long *iFrequency : Selection de la cadence des CHR et des frequences CCS
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] long *iFrequency : Selection of the sensor frequency
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
		\par Compatibles Sensors : ALL
*/

DLL_CHR_API short MCHR_GetFreeFrequency (MCHR_ID  SensorID, long* iFrequency);

/* ------------------------------------------------------------------------- */

/**************************************************************************
 ** Interferometric mode Setting                                         **
 **************************************************************************/
/*
 Fonction de d'activation ou de desactivation du mode fenetre en mode interferometrique
 Get the activation state of the "limited range" mode (interferometric mode only)
*/

/*!
	\fn short MCHR_GetBracketedMode (MCHR_ID  SensorID, BOOL *BracketedModeEnabled)
	\if FR
		\brief Fonction de d'activation ou de desactivation du mode fenetre en mode interferometrique
	\else
		\brief Function Get the activation state of the "limited range" mode (interferometric mode only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] BOOL *BracketedModeEnabled : valeur = 0 mode desactive ou valeur = 1 mode active
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] BOOL *BracketedModeEnabled : value = 0 mode not activated or value = 1 mode activated
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> CHR 150, CHR-150PC, CHR-150L, with Interferometric option<br><br>
		\brief <b>Voir :</b> la fonction "OnGetBracketedMode()" dans le module :
	\else
		\par Compatibles Sensors : CHR 150, CHR-150PC, CHR-150L, with Interferometric option
		\brief The "OnGetBracketedMode()" function in the \link SampleCHRDlg.cpp SampleCHRDlg.cpp \endlink module.
		\endif
*/

DLL_CHR_API short MCHR_GetBracketedMode (MCHR_ID  SensorID, BOOL *BracketedModeEnabled);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetBracketedMode (MCHR_ID  SensorID, BOOL BracketedModeEnabled)
	\if FR
		\brief Fonction de d'activation ou de desactivation du mode fenetre en mode interfermetrique
	\else
		\brief Function Set the activation state of the "limited range" mode (interferometric mode only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] BOOL BracketedModeEnabled : valeur = 0 mode desactive ou valeur = 1 mode active
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] BOOL BracketedModeEnabled : value = 0 mode not activated or value = 1 mode activated
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : CHR 150, CHR-150PC, CHR-150L, with Interferometric option
		\else
		\par Compatibles Sensors : CHR 150, CHR-150PC, CHR-150L, with Interferometric option
		\endif
*/

DLL_CHR_API short MCHR_SetBracketedMode (MCHR_ID  SensorID, BOOL BracketedModeEnabled);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetLeftDetectionLimit (MCHR_ID  SensorID, float *LeftLimitValue)
	\if FR
		\brief Fonction de lecture de la limite de detection gauche en mode interfermetrique
	\else
		\brief Function Get the left-side detection limit (interferometric mode only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] float *LeftLimitValue : valeur de la limite de detection gauche en mode interfermetrique
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] FLOAT *LeftLimitValue : value of left-side detection limit in interferometric mode
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> CCS PRIMA, CCS OPTIMA, CCS ULTIMA<br><br>
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA
		\endif
*/

DLL_CHR_API short MCHR_GetLeftDetectionLimit (MCHR_ID  SensorID, float *LeftLimitValue);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetLeftDetectionLimit (MCHR_ID  SensorID, float LeftLimitValue)
	\if FR
		\brief Fonction de parametrage de la limite de detection gauche en mode interferometrique
	\else
		\brief Function Set the left-side detection limit (interferometric mode only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] float LeftLimitValue : valeur de la limite de detection gauche en mode interferometrique
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] float LeftLimitValue : value of left-side detection limit in interferometric mode
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : CHR 150, CHR-150PC, CHR-150L, with Interferometric option
		\else
		\par Compatibles Sensors : CHR 150, CHR-150PC, CHR-150L, with Interferometric option
		\endif
*/

DLL_CHR_API short MCHR_SetLeftDetectionLimit (MCHR_ID  SensorID, float LeftLimitValue);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetRightDetectionLimit (MCHR_ID  SensorID, float *RightLimitValue)
	\if FR
		\brief Fonction de lecture de la limite de detection droite en mode interferometrique
	\else
		\brief Function Get the right-side detection limit (interferometric mode only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] float *RightLimitValue : valeur de la limite de detection droite en mode interferometrique
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] float *RightLimitValue : value of right-side detection limit in interferometric mode
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> CHR 150, CHR-150PC, CHR-150L, with Interferometric option<br><br>
		\brief <b>Voir :</b> la fonction "OnGetRightDetectionLimit()" dans le module :
	\else
		\par Compatibles Sensors : CHR 150, CHR-150PC, CHR-150L, with Interferometric option
		\endif
*/

DLL_CHR_API short MCHR_GetRightDetectionLimit (MCHR_ID  SensorID, float *RightLimitValue);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetRightDetectionLimit (MCHR_ID  SensorID, float RightLimitValue)
	\if FR
		\brief Fonction de parametrage de la limite de detection droite en mode interferometrique
	\else
		\brief Function Set the right-side detection limit (interferometric mode only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] float RightLimitValue : valeur de la limite de detection droite en mode interferometrique
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] float RightLimitValue : value of right-side detection limit in interferometric mode
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : CHR 150, CHR-150PC, CHR-150L, with Interferometric option
		\else
		\par Compatibles Sensors : CHR 150, CHR-150PC, CHR-150L, with Interferometric option
		\endif
*/

DLL_CHR_API short MCHR_SetRightDetectionLimit (MCHR_ID  SensorID, float RightLimitValue);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetQualityThreshold (MCHR_ID  SensorID, WORD *ThresholdValue)
	\if FR
		\brief Fonction de lecture du seuil de qualite en mode interfermetrique
	\else
		\brief Function Get the qualite threshold (interferometric mode only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] WORD *ThresholdValue : valeur du seuil de qualite en mode interfermetrique
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] WORD *ThresholdValue : value of the quality threshold
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> CHR 150, CHR-150PC, CHR-150L, with Interferometric option<br><br>
		\brief <b>Voir :</b> la fonction "OnGetQualityThreshold ()"  dans le module :
	\else
		\par Compatibles Sensors : CHR 150, CHR-150PC, CHR-150L, with Interferometric option
		\endif
*/


DLL_CHR_API short MCHR_GetQualityThreshold (MCHR_ID  SensorID, WORD *ThresholdValue);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SetQualityThreshold (MCHR_ID  SensorID, WORD ThresholdValue)
	\if FR
		\brief Fonction de parametrage du seuil de qualite en mode interferometrique
	\else
		\brief Function Set Quality threshold (interferometric mode only)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] WORD ThresholdValue : valeur du seuil de qualite en mode interfermetrique
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] WORD ThresholdValue : value of the quality threshold
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR \par Compatibles Sensors : CHR 150, CHR-150PC, CHR-150L, with Interferometric option
		\else
		\par Compatibles Sensors : CHR 150, CHR-150PC, CHR-150L, with Interferometric option
		\endif
*/

DLL_CHR_API short MCHR_SetQualityThreshold (MCHR_ID  SensorID, WORD ThresholdValue);
/* ------------------------------------------------------------------------- */


/**************************************************************************
 ** Miscellaneous functions                                              **
 **************************************************************************/

/*!
	\fn short MCHR_Abort  (MCHR_ID  SensorID)
	\if FR
		\brief Fonction permettant d'arreter la commande en cours soit une acquisition ou une commande
	\else
		\brief Function Stop the acquisition currently in progress, or the command that is currently executed
	\endif
	\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
	\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\else
		\par Compatibles Sensors : ALL
		\endif
			
*/
DLL_CHR_API short MCHR_Abort  (MCHR_ID  SensorID);
/* ------------------------------------------------------------- */

/*!
	\fn WORD MCHR_GetLastError (MCHR_ID  SensorID)
	\if FR
		\brief Fonction retournant la dernière erreur survenue
	\else
		\brief Function Get last error
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
			\arg \c 0x01	:	Error encountered when trying to communicate with the CHR 
				\arg \c 0x03	:	Error encountered when trying to initialize the specified COM PORT (IdSerialPort > 0) 
				\arg \c 0x04	:	Error encountered when trying to read the specified confoguration file
				\arg \c 0x05	:	Error encountered when trying to write the specified configuration file 
				\arg \c 0x06	:	Error encountered when trying to get the CHR configuration
				\arg \c 0x07	:	Error encountered during CHR configuration transmission
				\arg \c 0x08	:	The name of the specified CHR exist already in the list of initialized CHR 
				\arg \c 0x09	:	Error while adding a new CHR 
				\arg \c 0x0a	:	The specified CHR does not exist in the list of initialized CHR 
				\arg \c 0x0b	:	No CHR is currently connected.
				\arg \c 0x0c	:	Invalid argument for the required function 
				\arg \c 0x0d	:	Dialog error encountered while communicationg with the CHR
				\arg \c 0x0e	:	Error encountered while initializing the Reception Thread 
				\arg \c 0x0f	:	No command is being executed while "Abort" command is received 
				\arg \c 0x10	:	Abort command failed.				
				\arg \c 0x11	:	The DLL has not been initialized and activated. 
				\arg \c 0x12	:	The DLL is busy executing a previous command.
				\arg \c 0x13	:	The acquisition rate is too high, impossible to transmit all requested data at this rate 
				\arg \c 0x14	:	The specified function is autorized for CHR 450 only, the current CHR is not a 450 
				\arg \c 0x15	:	No acquisition is currently in progress.
				\arg \c 0x16	:	Unspecified error during function execution.
				\arg \c 0x17	:	The specified function is autorized on interferometric mode only, the CHR is not in this mode 
				\arg \c 0x18	:	Error during "Fast Dark" command execution.
				\arg \c 0x19	:	The interferometric mode is not authorized with this sensor.
				\arg \c 0x1a	:	The command is not authorized for the current sensor type
				\arg \c 0x1c	:	Impossible to send the calibration file
				\arg \c 0x1b	:	Impossible to read calibration file 
				\arg \c 0x1d	:	Illegal IP address. 
				\arg \c 0x1e	:	Reception buffer overflow, reading rate is too slow.
				\arg \c 0x1f	:	Unrecognized trigger type 
				\arg \c 0x20	:	Impossible to read the firmware file 
				\arg \c 0x21	:	Impossible to read the menu file
				\arg \c 0x22	:	Impossible to send the firmware file 
				\arg \c 0x23	:	Impossible to send the menu file
				\arg \c 0x24	:	Error while trying to run the new firmware version
				\arg \c 0x25	:	Error while trying to save the new firmware version 
				\arg \c 0x26	:	Error while trying restart the sensor after saving the new firmware version 
				\arg \c 0x27	:	The specified function is autorized for CHR 150 only, the current CHR is not a 150 
				\arg \c 0x28	:	The specified function is autorized for CCS only, the current CHR is not a 150 
				\arg \c 0x29	:	No data item is configured to be transmitted on current digital output channel 
				\arg \c 0x2a	:	The Ethernet link is not supported on this sensor.
				\arg \c 0x2b	:	Failed to send Serial Number 
				\arg \c 0x2c	:	The specified function is autorized for an ILB sensor
				\arg \c 0x2d	:	The specified function is not available on the device. 
				\arg \c 0x2e	:	Frequency too high.
				\arg \c 0x2f	:	Frequency too low.
				\arg \c 0x3a	:	Error during "White Acquisition" command execution : the signal is too High
				\arg \c 0x3b	:	Error during "White Acquisition" command execution : the signal is too low 
				\arg \c	0x3c	:	Error during "White Acquisition" command execution : the signal is satured 
				\arg \c 0x3d	:	The function is avalaible only for an ethernet connection.
				\arg \c 0x3e	:	Error during setting / getting ILB parameters. 
				\arg \c 0x3f	:	The specified function is unautorized for CHR 150 
				\arg \c 0x40	:	Failure to start the acquisition of WhiteRef
				\arg \c 0x41	:	Failure to stop the acquisition of WhiteRef 
				\arg \c 0x0100	:	Unknown error 
		\endif
		\brief
		\if FR 
			\brief <b>Capteurs Compatibles :</b> TOUS.
		\else
			\brief <b>Compatibles Sensors :</b> ALL.
		\endif
*/
DLL_CHR_API WORD MCHR_GetLastError (MCHR_ID  SensorID);
/* ------------------------------------------------------------- */

/*!
	\fn short MCHR_SendCommand(MCHR_ID  SensorID, LPCSTR Command, LPSTR Response)
	\if FR
		\brief Fonction envoyant une commande libre au capteur specifie
	\else
		\brief Function Send a commande to the specified CHR
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] LPCSTR Command :
			\param [] LPSTR Response :
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] LPCSTR Command : a character string comprising the command to send
			\param [out] LPSTR Response : a character string comprising the sensor response
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\else
		\par Compatibles Sensors : ALL
		\endif
*/

DLL_CHR_API short MCHR_SendCommand(MCHR_ID  SensorID, LPCSTR Command, LPSTR Response);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_ReadSignal (MCHR_ID  SensorID, enSignalType FirstSignalType, WORD *FirstSignal, enSignalType SecondSignalType, WORD *SecondSignal)
	\if FR
		\brief Fonction recuperant les signaux bruts et traites dans le capteur specifie
		\warning Appeler GetNbrPixels pour connaître la taille du buffer à passer en paramètres 
	\else
		\brief Function Read raw and treated signals to the specified CHR
		\warning Call GetNbrPixels to know the buffer size to set in parameters
		\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] enSignalType FirstSignalType : selects the type of the first signal.
			\param [] WORD *FirstSignal : a buffer for receiving the first signal (size=number of spectrometer pixels).
			\param [] enSignalType SecondSignalType : selects the type of the second signal.
			\param [] WORD *SecondSignal : a buffer for receiving the second signal (same size).
			\arg Signal types may be one of the following:
				\arg \c MCHR_RAW_SIGNAL,
				\arg \c MCHR_PRETREATED_SIGNAL,
				\arg \c MCHR_DARK_SIGNAL,
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] enSignalType FirstSignalType : selects the type of the first signal.
			\param [out] WORD *FirstSignal : a buffer for receiving the first signal (size=number of spectrometer pixels).
			\param [in] enSignalType SecondSignalType : selects the type of the second signal.
			\param [out] WORD *SecondSignal : a buffer for receiving the second signal (same size).
			\arg Signal types may be one of the following:
				\arg \c MCHR_RAW_SIGNAL,
				\arg \c MCHR_PRETREATED_SIGNAL,
				\arg \c MCHR_DARK_SIGNAL,
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\see MCHR_GetErrorDescription
	\brief
		\endif
		\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
		\brief <b>Voir :</b> la fonction "OnReadSignal()" dans le module :
	\else
		\par Compatibles Sensors : ALL
		\endif
*/

DLL_CHR_API short MCHR_ReadSignal (MCHR_ID  SensorID, enSignalType FirstSignalType, WORD *FirstSignal, enSignalType SecondSignalType, WORD *SecondSignal);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_ReadSignalFloat (MCHR_ID  SensorID, enSignalType FirstSignalType, float *FirstSignal, enSignalType SecondSignalType, float *SecondSignal)
	\if FR
		\brief Fonction à utiliser pour recuperer le fichier d'indice de refraction
		\warning Appeler GetNbrPixels pour connaître la taille du buffer à passer en paramètres
	\else
		\brief Function Read refractive index file
		\warning Call GetNbrPixels to know the buffer size 
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] enSignalType FirstSignalType :
			\param [] float *FirstSignal :
			\param [] enSignalType SecondSignalType :
			\param [] float *SecondSignal :
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] enSignalType FirstSignalType : selects the type of the first signal.
			\param [out] FLOAT *FirstSignal : a buffer for receiving the first signal (size=number of spectrometer pixels).
			\param [in] enSignalType SecondSignalType : selects the type of the second signal.
			\param [out] FLOAT *SecondSignal : a buffer for receiving the second signal (same size).
			\arg Signal types may be one of the following:
				\arg \c MCHR_RAW_SIGNAL,
				\arg \c MCHR_PRETREATED_SIGNAL,
				\arg \c MCHR_DARK_SIGNAL,
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
		
*/
DLL_CHR_API short MCHR_ReadSignalFloat (MCHR_ID  SensorID, enSignalType FirstSignalType, float *FirstSignal, enSignalType SecondSignalType, float *SecondSignal);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetNbrMaxPixels (MCHR_ID  SensorID,long *piMaxNbPixels)
	\if FR
		\brief Fonction permettant de connaître le nombre de pixels du capteur
		\warning Cette fonction doit être appelee pour la fonction ReadSignal
	\else
		\brief Function to Get Max Number of Pixels of the sensor
		\warning This function must be called for the ReadSignal function
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] long *piMaxNbPixels :
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] long *piMaxNbPixels : maximum numbers of pixels
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
	\else
		\par Compatibles Sensors : ALL
	\endif
*/
DLL_CHR_API short MCHR_GetNbrMaxPixels (MCHR_ID  SensorID,long *piMaxNbPixels);


/*!
	\fn short MCHR_RecenterEncoders (MCHR_ID  SensorID, BOOL Encoder1, BOOL Encoder2, BOOL Encoder3)
	\if FR
		\brief Fonction permettant de recentrer les codeurs
	\else
		\brief Function to recenter encoders (only CCS)
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] BOOL Encoder1 :
			\param [in] BOOL Encoder2 :
			\param [in] BOOL Encoder3 :
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] BOOL Encoder1 : true to recenter encoder 1, false otherwise.
			\param [in] BOOL Encoder2 : true to recenter encoder 2, false otherwise.
			\param [in] BOOL Encoder3 : true to recenter encoder 3, false otherwise.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> CCS PRIMA, CCS OPTIMA, CCS ULTIMA. <br><br>
		\else
		\par Compatibles Sensors : CCS PRIMA, CCS OPTIMA, CCS ULTIMA
	\endif
*/

DLL_CHR_API short MCHR_RecenterEncoders (MCHR_ID  SensorID, BOOL Encoder1, BOOL Encoder2, BOOL Encoder3);
/* ------------------------------------------------------------------------- */


/**************************************************************************
 ** Maintenance                                                          **
 **************************************************************************/
/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

/*!
	\fn short MCHR_GetMeasurementForCalibration  (MCHR_ID  SensorID, MCHR_tyAcqParam Parameters,	PFLOAT *pArrayDepth,	PFLOAT *pArrayIntensity, PFLOAT *pArrayBarycenter);
	\if FR
		\brief Fonction d'acquisition d'une sequence de points utilisable pour une calibration du CHR
		\warning CETTE FONCTION EST UNIQUEMENT RESERVEE POUR UNE UTILISATION USINE
	\else
		\brief Function Acquisition of a series of points for sensor calibration
		\warning THIS FUNCTION IS RESERVED FOR FACTORY USE ONLY.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] MCHR_tyAcqParam Parameters :
			\param [] PFLOAT *pArrayDepth : a pointer array to the Thickness1 data buffers
			\param [] PFLOAT *pArrayIntensity :
			\param [] PFLOAT *pArrayBarycenter :
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] MCHR_tyAcqParam Parameters : data structure for setting the measurement parameters
			\param [out] PFLOAT *pArrayDepth : a pointer array to the Thickness1 data buffers
			\param [out] PFLOAT *pArrayIntensity : data structure for setting the measurement parameters 
			\param [out] PFLOAT *pArrayBarycenter : a pointer array to the Thickness3 data buffers
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.<br><br>
	\else
		\par Compatibles Sensors : CHR 150, CHR-150PC, CHR-150L
		\endif
*/

DLL_CHR_API short MCHR_GetMeasurementForCalibration  (MCHR_ID  SensorID, MCHR_tyAcqParam Parameters,	PFLOAT *pArrayDepth,	PFLOAT *pArrayIntensity, PFLOAT *pArrayBarycenter);
                      
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SendCalibration  (MCHR_ID  SensorID, short PenID, char *ptrCalibrationFile, CALLBACK_SEND_FILE CallBackFct);
	\if FR
		\brief Fonction d'envoi d'une table de calibration sur le capteur specifie
		\warning CETTE FONCTION EST UNIQUEMENT RESERVEE POUR UNE UTILISATION USINE
	\else
		\brief Function Download of a calibration table into the sensor
		\warning THIS FUNCTION IS RESERVED FOR FACTORY USE ONLY
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] short PenID :
			\param [in] char *ptrCalibrationFile :
			\param [in] CALLBACK_SEND_FILE CallBackFct :
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] short PenID : ID of the pen selected
			\param [in] char *ptrCalibrationFile : a pointer to LUT file name
			\param [out] CALLBACK_SEND_FILE CallBackFct : Optional callback function
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
			\arg \c MCHR_ERROR_READ_CALIBRATION_FILE : error while attempting to read LUT File
			\arg \c MCHR_ERROR_SEND_CALIBRATION_TABLE : download error
		\endif
		\see MCHR_GetErrorDescription
		\brief
		\if FR 
			\brief <b>Capteurs Compatibles :</b> TOUS.
		\else
			\par Compatibles Sensors : ALL
		\endif
*/

DLL_CHR_API short MCHR_SendCalibration  (MCHR_ID  SensorID, short PenID, char *ptrCalibrationFile, CALLBACK_SEND_FILE CallBackFct);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SendFirmware (MCHR_ID  SensorID, char *FirmwareFile, char *AdditionalFile,  CALLBACK_SEND_FILE CallBackFct);
	\if FR
		\brief Fonction d'envoi du firmware dans le CHR (CHR 450, 450XE, 450XE-e)
	\else
		\brief Function Download the firmware to the CHR (CHR 450, 450XE, 450XE-e) without saving it to the non-volatile memory
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] char *FirmwareFile : Nom du fichier contenant le firmware (.exe) à telecharger   = NULL si on ne souhaite pas telecharger le firmware (.exe)
			\param [in] char *AdditionalFile : Nom du fichier complementaire contenant le Menu à telecharger pour CHR 450. Nom du fichier complementaire 'stil.bin' à telecharger pour un CHR150. = NULL si on ne souhaite pas telecharger le menu complementaire
			\param [out] CALLBACK_SEND_FILE CallBackFct : Valeur de retour
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] char *FirmwareFile : Name of firmware (*.exe) to be downloaded. = NULL if we don't want to download the firmware.
			\param [in] char *AdditionalFile : Name of menu file to be downloaded for CHR 450 OR 'stil.bin' for a CHR 150.  = NULL if we don't want to download the menu file.
			\param [out] CALLBACK_SEND_FILE CallBackFct : Reply 
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
		\par Compatibles Sensors : CHR 450, 450XE, 450XE-e
*/

DLL_CHR_API short MCHR_SendFirmware (MCHR_ID  SensorID, char *FirmwareFile, char *AdditionalFile,  CALLBACK_SEND_FILE CallBackFct);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SaveFirmware (MCHR_ID  SensorID, char *FirmwareFile, char *AdditionalFile,  CALLBACK_SEND_FILE CallBackFct);
	\if FR
		\brief Fonction de sauvegarde du firmware dans le CHR.
		\warning Valide definitivement le firmware et ou le menu envoyes par la commande MCHR_SendFirmware pour un CHR450, 450XE, 450XE-e. Pour un CHR 150: envoi + sauvegarde du firmware dans l'EEPROM 
	\else
		\brief Function writes a new CHR firmware version.
		\warning  Version previously sent with MCHR_SendFirmware, to the non-volatile memory and erases the previous version definitively. For a CHR 150, this function downloads and saves the new version definitively.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] char *FirmwareFile : Name of firmware (*.exe) to be saved.
			\param [in] char *AdditionalFile : Name of additonal file to be saved
			\param [out] CALLBACK_SEND_FILE CallBackFct : reply
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] char *FirmwareFile : Name of firmware (*.exe) to be saved.
			\param [in] char *AdditionalFile : Name of additonal file to be saved
			\param [out] CALLBACK_SEND_FILE CallBackFct : reply
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/

DLL_CHR_API short MCHR_SaveFirmware (MCHR_ID  SensorID, char *FirmwareFile, char *AdditionalFile,  CALLBACK_SEND_FILE CallBackFct);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_SendSerialNumber (MCHR_ID  SensorID, char *SerialNumber);
	\if FR
		\brief Fonction permettant d'envoyer un numero de serie au capteur.
	\else
		\brief Function to Set a Serial number to a sensor.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] char *SerialNumber : the new serial number
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] char *SerialNumber : the new serial number
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/

DLL_CHR_API short MCHR_SendSerialNumber (MCHR_ID  SensorID, char *SerialNumber);

/*!
	\fn short MCHR_SetDebugMessage (BOOL Enabled);
	\if FR
		\brief  Fonction activant des messages de debug.
	\else
		\brief Function to Activate debug message.
	\endif
	\details
		\if FR
			\param [in] BOOL Enabled : valeur = 0 mode non active ou valeur = 1 mode active
		\else
			\param [in] BOOL Enabled : value = 0 mode non activated or value = 1 mode activated
		\endif
*/

DLL_CHR_API void MCHR_SetDebugMessage (BOOL Enabled);
/* ------------------------------------------------------------- */

/*!
	\fn short MCHR_GetFtpDir(MCHR_ID SensorID, char * sFileName,PMCHR_FILE_DATA pFileData, long *plNbFiles);
	\if FR
		\brief Fonction recupère la liste des fichiers disponibles sur le capteur.
		\warning Pour connaitre le nombre de fichiers appeler cette fonction avec pFileData NULL (CETTE FONCTION EST UNIQUEMENT RESERVEE POUR UNE UTILISATION USINE)
	\else
		\brief Function Get the list of avaialable files.
		\warning THIS FUNCTION IS RESERVED FOR FACTORY USE ONLY
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [O] char * sFileName : nom du fichier recherche (*.*)
			\param [] PMCHR_FILE_DATA pFileData : tableau de structure qui doit être initialise avec le nombre de fichiers existant
			\param [] long *plNbFiles :
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] char * sFileName : sherched file name (*.*)
			\param [out] PMCHR_FILE_DATA pFileData : structure array that must be set with the existing files number
			\param [out] long *plNbFiles :
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/

DLL_CHR_API short MCHR_GetFtpDir(MCHR_ID SensorID, char * sFileName,PMCHR_FILE_DATA pFileData, long *plNbFiles);

/* ------------------------------------------------------------- */
/*!
	\fn short MCHR_GetFtpNumberOfFiles(MCHR_ID SensorID, char * sFileName, long *plNbFiles);
	\if FR
		\brief Fonction recupère le nombre de fichiers disponibles sur le capteur.
	\else
		\brief Function Get the number of files avaialable on the sensor.
		\warning THIS FUNCTION IS RESERVED FOR FACTORY USE ONLY
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [O] char * sFileName : nom du fichier recherche (*.*)
			\param [] long *plNbFiles : nombre de fichiers disponibles sur le capteur
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] char * sFileName : sherched file name (*.*)
			\param [out] long *plNbFiles : number of files avaialable on the sensor
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetFtpNumberOfFiles(MCHR_ID SensorID, char * sFileName, long *plNbFiles);

/* ------------------------------------------------------------- */
/*!
	\fn short MCHR_GetFtpFileName(MCHR_ID SensorID, MCHR_FILE_DATA_EX *pFileData, long numFile);
	\if FR
		\brief Fonction recupère les caractéristique du fichier en fonction de son index.
	\else
		\brief Function Get the characteristics of the file according to its index.
		\warning THIS FUNCTION IS RESERVED FOR FACTORY USE ONLY
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [O] char * sFileName : nom du fichier
			\param [] long numFile : index du ficheir
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] char * sFileName : file name
			\param [out] long numFile : index of file
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetFtpFileName(MCHR_ID SensorID, MCHR_FILE_DATA_EX *pFileData, long numFile);

/*!
	\fn short MCHR_DownloadFile(MCHR_ID SensorID, char * src,char *dest);
	\if FR
		\brief PRIVATE
		\warning CETTE FONCTION EST UNIQUEMENT RESERVEE POUR UNE UTILISATION USINE
	\else
		\brief PRIVATE
		\warning THIS FUNCTION IS RESERVED FOR FACTORY USE ONLY
	\endif
*/

DLL_CHR_API short MCHR_DownloadFile(MCHR_ID SensorID, char * src,char *dest);

/*!
	\fn short MCHR_UploadFile(MCHR_ID SensorID, char * src,char *dest,HWND hWindowToNotify,UINT uiMessID);
	\if FR
		\brief Fonction Envoi d'un fichier depuis le PC vers le CCS
		\warning CETTE FONCTION EST UNIQUEMENT RESERVEE POUR UNE UTILISATION USINE
	\else
		\brief Function file download
		\warning THIS FUNCTION IS RESERVED FOR FACTORY USE ONLY
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] char * src : Chemin absolu du fichier
			\param [in] char *dest : Nom du fichier  de destination
			\param [out] HWND hWindowToNotify : Identifiant de la fenêtre pour l'envoi de la progression
			\param [out] UINT uiMessID : ID du message qui est envoye à la fenêtre
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] char * src : Absolute file source path
			\param [in] char *dest : Destination file name
			\param [out] HWND hWindowToNotify : Window Id for progress bargraph
			\param [out] UINT uiMessID : ID of the message send to the window
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
*/

DLL_CHR_API short MCHR_UploadFile(MCHR_ID SensorID, char * src,char *dest,HWND hWindowToNotify,UINT uiMessID);

/*!
	\fn short MCHR_UploadFileEx(MCHR_ID SensorID, char * src, char *dest, CALLBACK_SEND_FILE CallBackFct);
	\if FR
		\brief Fonction Envoi d'un fichier depuis le PC vers le CCS
		\warning CETTE FONCTION EST UNIQUEMENT RESERVEE POUR UNE UTILISATION USINE
	\else
		\brief Function file download
		\warning THIS FUNCTION IS RESERVED FOR FACTORY USE ONLY
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] char * src : Chemin absolu du fichier
			\param [in] char *dest : Nom du fichier  de destination
			\param [out] CALLBACK_SEND_FILE CallBackFct : Option de function retour
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] char * src : Absolute file source path
			\param [in] char *dest : Destination file name
			\param [out] CALLBACK_SEND_FILE CallBackFct : Optional callback function
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
*/
DLL_CHR_API short MCHR_UploadFileEx(MCHR_ID SensorID, char * src, char *dest, CALLBACK_SEND_FILE CallBackFct);

/*!
	\fn short MCHR_SetSpectrumMode(MCHR_ID SensorID, WORD Value);
	\if FR
		\brief Fonction Activation ou Desactivation du mode spectre.		
	\else
		\brief Function Enable or Disable spectrum mode		
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] WORD Value : 1 pour activer le mode spectre et 0 pour désactiver
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] WORD Value : 1 for enable the spectrum mode, 0 for disable.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
	\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetSpectrumMode (MCHR_ID  SensorID,	WORD Value);

/*!
	\fn short MCHR_SetLedType(MCHR_ID SensorID,enLedType LedType);
	\if FR
		\brief Fonction Type de LED selectionne (Source interne, source externe)
		\warning CETTE FONCTION EST UNIQUEMENT RESERVEE POUR UNE UTILISATION USINE
	\else
		\brief Function Led type selected. Source type can be either Internal LED or External source
		\warning THIS FUNCTION IS RESERVED FOR FACTORY USE ONLY
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] enLedType LedType : Type de Led selectionne
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] enLedType LedType : Selected Led Type
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
	\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetLedType(MCHR_ID SensorID,enLedType LedType);

/*!
	\fn short MCHR_GetLedType(MCHR_ID SensorID,enLedType *pLedType);
	\if FR
		\brief Fonction detection Type de LED (Source interne, source externe)
		\warning CETTE FONCTION EST UNIQUEMENT RESERVEE POUR UNE UTILISATION USINE
	\else
		\brief Function Led type detected. Source type can be either Internal LED or External source
		\warning THIS FUNCTION IS RESERVED FOR FACTORY USE ONLY
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] enLedType *pLedType : Type de Led detectee
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] enLedType *pLedType : Detected Led Type
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
	\see MCHR_GetErrorDescription
*/

DLL_CHR_API short MCHR_GetLedType(MCHR_ID SensorID,enLedType *pLedType);

/*!
	\fn short MCHR_GetUsablePixels (MCHR_ID  SensorID,PWORD pwFirstUsablePixel,PWORD pwNumberOfUsablePixels);
	\if FR
		\brief Fonction detection des pixels du capteur utilisables
	\else
		\brief Function detection usable sensor pixels
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] PWORD pwFirstUsablePixel : premier pixel utilisable
			\param [out] PWORD pwNumberOfUsablePixels : nombre de pixels utilisables
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] PWORD pwFirstUsablePixel : first usable pixel
			\param [out] PWORD pwNumberOfUsablePixels : number of usable pixels
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
		\par Compatibles Sensors : ALL
*/


DLL_CHR_API short MCHR_GetUsablePixels (MCHR_ID  SensorID,PWORD pwFirstUsablePixel,PWORD pwNumberOfUsablePixels);

/*!
	\fn short MCHR_GetCCDMaxPixels (MCHR_ID  SensorID);
	\if FR
		\brief Fonction detection du nombre maximum de pixels du capteur
	\else
		\brief Function detection of maximum number of pixels of the sensor
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] PWORD pwMaxPixel : nombre maximum de pixels du capteur
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [] PWORD pwMaxPixel : maximum number of pixels of the sensor
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
*/


 DLL_CHR_API short MCHR_GetCCDMaxPixels (MCHR_ID  SensorID,PWORD pwMaxPixel);


/*!
	\fn short MCHR_GetErrorDescription (WORD shErrorID,LPSTR pszErrorBuffer,long iBufferLength)
	\if FR 
		\brief Cette fonction reçoit l'erreur et en retourne sa description.
	\else
		\brief This function gets an error id and returns the description of the error. 
	\endif
	\details
		\if FR
			\param [in] WORD shErrorID: Code erreur retourne par GetLastError
			\param [out] LPSTR pszErrorBuffer: 
			\param [in] long iBufferLength: 
		\else
			\param [in] WORD shErrorID: error code returned by GetLastError
				\arg \c 0x01	:	Error encountered when trying to communicate with the CHR 
				\arg \c 0x03	:	Error encountered when trying to initialize the specified COM PORT (IdSerialPort > 0) 
				\arg \c 0x04	:	Error encountered when trying to read the specified confoguration file
				\arg \c 0x05	:	Error encountered when trying to write the specified configuration file 
				\arg \c 0x06	:	Error encountered when trying to get the CHR configuration
				\arg \c 0x07	:	Error encountered during CHR configuration transmission
				\arg \c 0x08	:	The name of the specified CHR exist already in the list of initialized CHR 
				\arg \c 0x09	:	Error while adding a new CHR 
				\arg \c 0x0a	:	The specified CHR does not exist in the list of initialized CHR 
				\arg \c 0x0b	:	No CHR is currently connected.
				\arg \c 0x0c	:	Invalid argument for the required function 
				\arg \c 0x0d	:	Dialog error encountered while communicationg with the CHR
				\arg \c 0x0e	:	Error encountered while initializing the Reception Thread 
				\arg \c 0x0f	:	No command is being executed while "Abort" command is received 
				\arg \c 0x10	:	Abort command failed.				
				\arg \c 0x11	:	The DLL has not been initialized and activated. 
				\arg \c 0x12	:	The DLL is busy executing a previous command.
				\arg \c 0x13	:	The acquisition rate is too high, impossible to transmit all requested data at this rate 
				\arg \c 0x14	:	The specified function is autorized for CHR 450 only, the current CHR is not a 450 
				\arg \c 0x15	:	No acquisition is currently in progress.
				\arg \c 0x16	:	Unspecified error during function execution.
				\arg \c 0x17	:	The specified function is autorized on interferometric mode only, the CHR is not in this mode 
				\arg \c 0x18	:	Error during "Fast Dark" command execution.
				\arg \c 0x19	:	The interferometric mode is not authorized with this sensor.
				\arg \c 0x1a	:	The command is not authorized for the current sensor type
				\arg \c 0x1c	:	Impossible to send the calibration file
				\arg \c 0x1b	:	Impossible to read calibration file 
				\arg \c 0x1d	:	Illegal IP address. 
				\arg \c 0x1e	:	Reception buffer overflow, reading rate is too slow.
				\arg \c 0x1f	:	Unrecognized trigger type 
				\arg \c 0x20	:	Impossible to read the firmware file 
				\arg \c 0x21	:	Impossible to read the menu file
				\arg \c 0x22	:	Impossible to send the firmware file 
				\arg \c 0x23	:	Impossible to send the menu file
				\arg \c 0x24	:	Error while trying to run the new firmware version
				\arg \c 0x25	:	Error while trying to save the new firmware version 
				\arg \c 0x26	:	Error while trying restart the sensor after saving the new firmware version 
				\arg \c 0x27	:	The specified function is autorized for CHR 150 only, the current CHR is not a 150 
				\arg \c 0x28	:	The specified function is autorized for CCS only, the current CHR is not a 150 
				\arg \c 0x29	:	No data item is configured to be transmitted on current digital output channel 
				\arg \c 0x2a	:	The Ethernet link is not supported on this sensor.
				\arg \c 0x2b	:	Failed to send Serial Number 
				\arg \c 0x2c	:	The specified function is autorized for an ILB sensor
				\arg \c 0x2d	:	The specified function is not available on the device. 
				\arg \c 0x2e	:	Frequency too high.
				\arg \c 0x2f	:	Frequency too low.
				\arg \c 0x3a	:	Error during "White Acquisition" command execution : the signal is too High
				\arg \c 0x3b	:	Error during "White Acquisition" command execution : the signal is too low 
				\arg \c	0x3c	:	Error during "White Acquisition" command execution : the signal is satured 
				\arg \c 0x3d	:	The function is avalaible only for an ethernet connection.
				\arg \c 0x3e	:	Error during setting / getting ILB parameters. 
				\arg \c 0x3f	:	The specified function is unautorized for CHR 150 
				\arg \c 0x40	:	Failure to start the acquisition of WhiteRef
				\arg \c 0x41	:	Failure to stop the acquisition of WhiteRef 
				\arg \c 0x0100	:	Unknown error
				
				
			\param [out] LPSTR pszErrorBuffer: the string buffer for the error description
			\param [in]  long iBufferLength: the length of the string
		\endif
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> TOUS.
	\else
		\brief <b>Compatibles Sensors :</b> ALL.
	\endif
	
*/
DLL_CHR_API short MCHR_GetErrorDescription(WORD shErrorID, LPSTR pszErrorBuffer, long iBufferLength);



/************************************************************************/
/* White ref state acquisition                                          */
/************************************************************************/
/*!
	\fn short MCHR_StopWhiteRefStateAcquisition(MCHR_ID  SensorID)
	\if FR
		\brief Fonction d'arrêt de l'acquisition du white ref.
	\else
		\brief Stops white ref acquisition.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_StopWhiteRefStateAcquisition(MCHR_ID  SensorID);

/*!
	\fn short MCHR_StartWhiteRefStateAcquisition(MCHR_ID  SensorID)
	\if FR
		\brief Fonction de demarrage de l'acquisition du white ref.
	\else
		\brief Starts white ref acquisition.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_StartWhiteRefStateAcquisition(MCHR_ID  SensorID);

/*!
	\fn short MCHR_StartWhiteNormalisationRefStateAcquisition(MCHR_ID  SensorID)
	\if FR
		\brief Fonction de demarrage de l'acquisition du white ref de normalisation.
	\else
		\brief Starts normalization white ref acquisition.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_StartWhiteNormalisationRefStateAcquisition(MCHR_ID  SensorID);

/*!
	\fn short MCHR_GetLastWhiteRefState(MCHR_ID  SensorID,WORD *pwLastState)
	\if FR
		\brief Fonction permettant de lire l'etat du White ref.
	\else
		\brief Reads white ref status.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] WORD *pwLastState : Statut du White ref.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] WORD *pwLastState : White ref Status.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetLastWhiteRefState(MCHR_ID  SensorID,WORD *pwLastState);

/*!
	\fn short MCHR_GetWhiteRefMaxThreshold(MCHR_ID  SensorID, long *iMaxWhiteRefThreshold)
	\if FR
		\brief Fonction permettant de lire le seuil maximum du white ref.
	\else
		\brief Reads white ref max threshold.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] long * : Seuil White ref Maximum.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] long * : Max white ref threshold.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetWhiteRefMaxThreshold(MCHR_ID  SensorID, long *iMaxWhiteRefThreshold);

/*!
	\fn short MCHR_SetWhiteRefMaxThreshold(MCHR_ID  SensorID, long iMaxWhiteRefThreshold)
	\if FR
		\brief Fonction permettant de parametrer le seuil maximum du white ref.
	\else
		\brief Sets white ref max threshold.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long : Seuil White ref Maximum.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long : Max white ref threshold.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetWhiteRefMaxThreshold(MCHR_ID  SensorID, long iMaxWhiteRefThreshold);

/*!
	\fn short MCHR_SetWhiteRefMinThreshold(MCHR_ID  SensorID, long iMinWhiteRefThreshold)
	\if FR
		\brief Fonction permettant de parametrer le seuil minimum du white ref.
	\else
		\brief Sets white ref min threshold.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long : Seuil White ref Minimum.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long : Min white ref threshold.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetWhiteRefMinThreshold(MCHR_ID  SensorID, long iMinWhiteRefThreshold);

/*!
	\fn short MCHR_GetWhiteRefMinThreshold(MCHR_ID  SensorID, long *iMinWhiteRefThreshold)
	\if FR
		\brief Fonction permettant de lire le seuil minimum du white ref.
	\else
		\brief Reads white ref min threshold.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] long * : Seuil White ref Minimum.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] long * : Min white ref threshold.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetWhiteRefMinThreshold(MCHR_ID  SensorID, long *iMinWhiteRefThreshold);

/*!
	\fn short MCHR_GetWhiteRefAvg(MCHR_ID  SensorID, long *iWhiterefAveragingFactor)
	\if FR
		\brief Fonction permettant de lire le taux de moyennage du white ref.
	\else
		\brief Reads white ref averaging factor.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] long *iWhiterefAveragingFactor : Facteur de moyennage du white ref.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] long *iWhiterefAveragingFactor : White ref averaging factor.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetWhiteRefAvg(MCHR_ID  SensorID, long *iWhiterefAveragingFactor);

/*!
	\fn short MCHR_SetWhiteRefAvg(MCHR_ID  SensorID, long iWhiterefAveragingFactor)
	\if FR
		\brief Fonction permettant de parametrer le taux de moyennage du white ref.
	\else
		\brief Sets white ref averaging factor.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long iWhiterefAveragingFactor: Facteur de moyennage du white ref.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long iWhiterefAveragingFactor: White ref averaging factor.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetWhiteRefAvg(MCHR_ID  SensorID, long iWhiterefAveragingFactor);

/*!
	\fn short MCHR_GetWhiteRefCuttingValue(MCHR_ID  SensorID, long *iWhiterefCuttingValue)
	\if FR
		\brief Fonction permettant de lire la valeur de coupe du white ref.
	\else
		\brief Reads white ref cutting value.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] long *iWhiterefCuttingValue : Valeur de coupe du white ref.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] long *iWhiterefCuttingValue : White ref cutting value.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetWhiteRefCuttingValue(MCHR_ID  SensorID, long *iWhiterefCuttingValue);

/*!
	\fn short MCHR_SetWhiteRefCuttingValue(MCHR_ID  SensorID, long iWhiterefCuttingValue)
	\if FR
		\brief Fonction permettant de parametrer la valeur de coupe du white ref.
	\else
		\brief Sets white ref cutting value.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long iWhiterefCuttingValue : Valeur de coupe du white ref.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long iWhiterefCuttingValue : White ref cutting value.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetWhiteRefCuttingValue(MCHR_ID  SensorID, long iWhiterefCuttingValue);

/*!
	\fn short MCHR_GetWhiteRefFrq(MCHR_ID  SensorID, long *iWhiterefFrequency)
	\if FR
		\brief Fonction permettant de lire la frequence du white ref.
	\else
		\brief Reads white ref frequency.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] long *iWhiterefFrequency : Frequence du white ref.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] long *iWhiterefFrequency : White ref frequency.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetWhiteRefFrq(MCHR_ID  SensorID, long *iWhiterefFrequency);

/*!
	\fn short MCHR_SetWhiteRefFrq(MCHR_ID  SensorID, long iWhiterefFrequency)
	\if FR
		\brief Fonction permettant de parametrer la frequence du white ref.
	\else
		\brief Sets white ref frequency.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long iWhiterefFrequency : Frequence du white ref.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long iWhiterefFrequency : White ref frequency.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetWhiteRefFrq(MCHR_ID  SensorID, long iWhiterefFrequency);

/*!
	\fn short MCHR_GetWhiteRefNormaMinThreshold(MCHR_ID  SensorID, long *iValue)
	\if FR
		\brief Fonction permettant de lire le seuil minimum du white ref de normalisation.
	\else
		\brief Reads normalization white ref minimum threshold.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] long *iValue : Valeur min du white ref de nomalisation.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] long *iValue : Normalization White ref min threshold.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetWhiteRefNormaMinThreshold(MCHR_ID  SensorID, long *iValue);

/*!
	\fn short MCHR_SetWhiteRefNormaMinThreshold(MCHR_ID  SensorID, long iValue)
	\if FR
		\brief Fonction permettant de parametrer le seuil minimum du white ref de normalisation.
	\else
		\brief Sets normalization white ref minimum threshold.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long iValue : Valeur min du white ref de nomalisation.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long iValue : Normalization White ref min threshold.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetWhiteRefNormaMinThreshold(MCHR_ID  SensorID, long iValue);

/*!
	\fn short MCHR_GetWhiteRefNormaMaxThreshold(MCHR_ID  SensorID, long *iValue)
	\if FR
		\brief Fonction permettant de lire le seuil maximum du white ref de normalisation.
	\else
		\brief Reads normalization white ref maximum threshold.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] long *iValue : Valeur max du white ref de nomalisation.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] long *iValue : Normalization White ref max threshold.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetWhiteRefNormaMaxThreshold(MCHR_ID  SensorID, long *iValue);

/*!
	\fn short MCHR_SetWhiteRefNormaMaxThreshold(MCHR_ID  SensorID, long iValue)
	\if FR
		\brief Fonction permettant de parametrer le seuil maximum du white ref de normalisation.
	\else
		\brief Sets normalization white ref maximum threshold.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long iValue : Valeur max du white ref de nomalisation.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long iValue : Normalization White ref max threshold.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetWhiteRefNormaMaxThreshold(MCHR_ID  SensorID, long iValue);

/*!
	\fn short MCHR_GetWhiteRefNormaAvg(MCHR_ID  SensorID, long *iValue)
	\if FR
		\brief Fonction permettant de lire le taux de moyennage du white ref de normalisation.
	\else
		\brief Reads normalization white ref averaging factor.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] long *iValue : Facteur de moyennage du white ref de normalisation.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] long *iValue : Normaliztion white ref averaging factor.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetWhiteRefNormaAvg(MCHR_ID  SensorID, long *iValue);

/*!
	\fn short MCHR_SetWhiteRefNormaAvg(MCHR_ID  SensorID, long iValue)
	\if FR
		\brief Fonction permettant de parametrer le taux de moyennage du white ref de normalisation.
	\else
		\brief Sets normalization white ref averaging factor.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long iValue : Facteur de moyennage du white ref de nomalisation.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long iValue : Normalization white ref averaging factor.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetWhiteRefNormaAvg(MCHR_ID  SensorID, long iValue);

/*!
	\fn short MCHR_GetWhiteRefNormaFrq(MCHR_ID  SensorID, long *iValue)
	\if FR
		\brief Fonction permettant de lire la frequence du white ref de normalisation.
	\else
		\brief Reads white ref frequency.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] long *iValue : Frequence du white ref de normalisation.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] long *iValue : Normalization white ref frequency.
			\return short : A A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetWhiteRefNormaFrq(MCHR_ID  SensorID, long *iValue);

/*!
	\fn short MCHR_SetWhiteRefNormaFrq(MCHR_ID  SensorID, long iValue)
	\if FR
		\brief Fonction permettant de parametrer la frequence du white ref de normalisation.
	\else
		\brief Sets normalization white ref frequency.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long *iValue : Frequence du white ref de normalisation.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long *iValue : Normalization white ref frequency.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetWhiteRefNormaFrq(MCHR_ID  SensorID, long iValue);

/*!
	\fn short MCHR_GenerateOrEnableWhiteRef(MCHR_ID SensorID,short Preprocessed, short Generate, long iFirstPixel, long iNbPixels, char * pszFileName)
	\if FR
		\brief Fonction permettant de preparer le prise de white ref.
	\else
		\brief Prepare white ref computation.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [] short Preprocessed : Signal utilise ('0' : Preprocessed, '1' : normalissation).
			\param [] short Generate : Mode de selection ('0' : Generer un nouveau fichier, '1' : lire un fichier existant).
			\param [] long iFirstPixel : Premier pixel utile pour l'acquisition du white ref.
			\param [] long iNbPixels : Nombre de pixel utile pour l'acquisition du white ref.
			\param [] char *pszFileName : Terminaison du nom de fichier de white ref.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] short Preprocessed : Signal used for computation ('0' : Preprocessed, '1' : normalization).
			\param [in] short Generate : File use mode ('0' : Generate new white ref file, '1' : read existing white ref file).
			\param [in] long iFirstPixel : First pixel used for white ref acquisition.
			\param [in] long iNbPixels : Number of pixels used for white ref acquisition.
			\param [in] char *pszFileName : White ref end of file name.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GenerateOrEnableWhiteRef(MCHR_ID SensorID, short Preprocessed, short  Generate, long iFirstPixel, long iNbPixels, char * pszFileName);

/*!
	\fn short MCHR_GetWhiteRefAveraging(MCHR_ID SensorID, long *piMxs)
	\if FR
		\brief Fonction permettant de lire le taux de moyennage du white ref.
		\deprecated
	\else
		\brief Reads white ref averaging factor.
		\deprecated		
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] long *piMxs : Facteur de moyennage du white ref.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] long *piMxs : White ref averaging factor.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetWhiteRefAveraging(MCHR_ID SensorID, long *piMxs);

/*!
	\fn short MCHR_SetWhiteRefAveraging(MCHR_ID SensorID, long iMxs)
	\if FR
		\brief Fonction permettant de parametrer le taux de moyennage du white ref.
		\deprecated.
	\else
		\brief Sets white ref averaging factor.
		\deprecated
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long iMxs : Facteur de moyennage du white ref.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long iMxs : White ref averaging factor.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetWhiteRefAveraging(MCHR_ID SensorID, long iMxs);

/*!
	\fn short MCHR_GetAutoWhiteRef (MCHR_ID  SensorID, long *iEnabled)
	\if FR
		\brief Recupere l'etat de l'autowhiteref.
	\else
		\brief Get autowhiteref status.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] long *iEnabled : 1 si l'autowhiteref est actif, 0  sinon.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] long *iEnabled : 1 if Autowhiteref is enabled, 0  otherwise.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
		\par Compatibles Sensors : ALL
*/
DLL_CHR_API short MCHR_GetAutoWhiteRef (MCHR_ID  SensorID, long *iEnabled);

/*!
	\fn short MCHR_SetAutoWhiteRef (MCHR_ID  SensorID, long iEnabled)
	\if FR
		\brief Active/Desactive l'autowhiteref.
	\else
		\brief Activate/Desactivate autowhiteref.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long iEnabled : 1 pour activer l'autowhiteref, 0  sinon.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long iEnabled : 1 to activate autowhiteref, 0  otherwise.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetAutoWhiteRef (MCHR_ID  SensorID, long iEnabled);

/*!
	\fn short MCHR_AcqWhiteRef (MCHR_ID  SensorID)
	\if FR
		\brief Lancement de l'acquisition du whiteref.
	\else
		\brief Launch whiteref acquisition.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
		\par Compatibles Sensors : ALL Except RUBY and CHR sensors
*/
DLL_CHR_API short MCHR_AcqWhiteRef (MCHR_ID  SensorID);

/*!
	\fn short MCHR_SetDoubleFrequencyParameters(MCHR_ID SensorID, short iEnabled, long iLowFreq, long iHighFrq, short IntensityNormalization)
	\if FR
		\brief Fonction permettant de parametrer le mode double frequence. 
		\warning Seulement pour les coffrets type CCS.
	\else
		\brief Function to set the double frequency mode. 
		\warning Only available for CCS devices.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] short Enabled : Activation du mode double frequence (0 : inactif, 1 : actif).
			\param [in] long iLowFreq : Frequence basse.
			\param [in] long iHighFrq : Frequence haute.
			\param [in] short IntensityNormalization : Normalisation de l'intensite (0 : pas de normalisation, 1 : normalisation).
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] short Enabled : Activate double frequency mode (0 : not active, 1 : active).
			\param [in] long iLowFreq : Low Frequency.
			\param [in] long iHighFrq : High Frequency.
			\param [in] short IntensityNormalization : Intensity normalization (0 : no normalization, 1 : normalization).
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
		\brief
		\if FR 
			\par <b>Capteurs Compatibles :</b> CCS PRIMA, STIL-INITIAL.
		\else
			\par Compatibles Sensors : CCS PRIMA, STIL-INITIAL.
		\endif
*/
DLL_CHR_API short MCHR_SetDoubleFrequencyParameters(MCHR_ID SensorID, short Enabled, long iLowFreq, long iHighFrq, short  IntensityNormalization);

/*!
	\fn short MCHR_GetDoubleFrequencyParameters(MCHR_ID SensorID, short *pEnabled, long *piLowFreq,  long *piHighFrq, short  *pIntensityNormalization)
	\if FR
		\brief Fonction permettant d'obtenir le mode double frequence.
	\else
		\brief Function to get the double frequency mode.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] short *Enabled : Activation du mode double frequence (0 : inactif, 1 : actif).
			\param [in] long *iLowFreq : Frequence basse.
			\param [in] long *iHighFrq : Frequence haute.
			\param [in] short *IntensityNormalization : Normalisation de l'intensite (0 : pas de normalisation, 1 : normalisation).
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] short *Enabled : Activate double frequency mode (0 : not active, 1 : active).
			\param [out] long *iLowFreq : Low Frequency.
			\param [out] long *iHighFrq : High Frequency.
			\param [out] short *IntensityNormalization : Intensity normalization (0 : no normalization, 1 : normalization).
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
		\par Compatibles Sensors : CCS PRIMA, STIL-INITIAL
*/
DLL_CHR_API short MCHR_GetDoubleFrequencyParameters(MCHR_ID SensorID, short *pEnabled, long *piLowFreq, long *piHighFrq, short  *pIntensityNormalization);

/*!
	\fn short MCHR_SetNonExistantSecondPeakHandling(MCHR_ID SensorID,enSecondPeakHandling enPeakHandling)
	\if FR
		\brief Fonction permettant de definir le type de prise en compte des pics lors de la mesure.
	\else
		\brief Function setting measurement second peak handling type.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] enSecondPeakHandling enPeakHandling : Type de prise en compte des pics.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] enSecondPeakHandling enPeakHandling : Measurement second peak handling type.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetNonExistantSecondPeakHandling(MCHR_ID SensorID,enSecondPeakHandling enPeakHandling);

/*!
	\fn short MCHR_GetNonExistantSecondPeakHandling(MCHR_ID SensorID,enSecondPeakHandling *enPeakHandling)
	\if FR
		\brief Fonction permettant de recuperer le type de prise en compte des pics lors de la mesure.
	\else
		\brief Function getting measurement second peak handling type.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] \link enSecondPeakHandling enSecondPeakHandling \endlink *enPeakHandling : Type de prise en compte des pics.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] enSecondPeakHandling *enPeakHandling : Measurement second peak handling type.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetNonExistantSecondPeakHandling(MCHR_ID SensorID,enSecondPeakHandling *enPeakHandling);

/*!
	\fn short MCHR_LockKeyboard(MCHR_ID SensorID,BOOL bLock)
	\if FR
		\brief Fonction permettant de bloquer/debloquer le clavier d'un coffret.
		\warning Seulement pour CHR 150, RUBY, DUO or TRIO.
	\else
		\brief Locks or unlocks the device's keyboard.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] BOOL bLock : true pour activer le blocage et false pour le desactiver.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] BOOL bLock : true to activate blocking and false to desactivate it.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> Seulement CHR 150, RUBY, DUO or TRIO.<br><br>
	\else
		\par Compatibles Sensors : Only CHR 150, RUBY, DUO or TRIO.
		\endif
*/
DLL_CHR_API short MCHR_LockKeyboard(MCHR_ID SensorID,BOOL bLock);

/*!
	\fn short MCHR_GetSpectralCalibration(MCHR_ID  SensorID, double *pCoefArray, long *piCoefArraySize)
	\if FR
		\brief Fonction permettant de recuperer les coeficients de calibration spectrale.
		\warning Seulement pour CHR 150, RUBY, DUO or TRIO.
	\else
		\brief Function getting spectral calibration coeficients.
		\warning Only for CHR 150, RUBY, DUO or TRIO.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] double *pCoefArray : Tableau de coeficients de calibration.
			\param [out] long *piCoefArraySize : Taille du tableau de coeficients.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] double *pCoefArray : Calibration coeficients array.
			\param [out] long *piCoefArraySize : Size of the calibration coeficients array.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetSpectralCalibration(MCHR_ID  SensorID, double *pCoefArray, long *piCoefArraySize);

/*!
	\fn short MCHR_SetSpectralCalibration(MCHR_ID  SensorID, double *pCoefArray, lonf iCoefArraySize)
	\if FR
		\brief Fonction permettant de parametrer les coeficients de calibration spectrale.
	\else
		\brief Function setting spectral calibration coeficients.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] double *pCoefArray : Tableau de coeficients de calibration.
			\param [in] long piCoefArraySize : Taille du tableau de coeficients.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] double *pCoefArray : Calibration coeficients array.
			\param [in] long piCoefArraySize : Size of the calibration coeficients array.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
		\par Compatibles Sensors : CHR 150, RUBY, DUO or TRIO
*/
DLL_CHR_API short MCHR_SetSpectralCalibration(MCHR_ID  SensorID, double *pCoefArray, long iCoefArraySize);

/*!
	\fn short MCHR_GetSpectralRefractivesIndexes(MCHR_ID  SensorID, double *pCoefArray, long *piCoefArraySize)
	\if FR
		\brief Fonction permettant de recuperer les indice de refractions.
	\else
		\brief Function getting refractive indexes.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] double *pCoefArray : Tableau de coeficients de refraction.
			\param [out] long *piCoefArraySize : Taille du tableau de coeficients.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] double *pCoefArray : Refarctive indexes coeficients array.
			\param [out] long *piCoefArraySize : Size of the calibration coeficients array.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
		\brief
		\if FR 
			\brief <b>Capteurs Compatibles :</b>ATTENTION UNIQUEMENT  CHR 150, RUBY, DUO or TRIO
		\else
			\par Compatibles Sensors :WARNING CHR 150, RUBY, DUO or TRIO ONLY
		\endif
*/
DLL_CHR_API short MCHR_GetSpectralRefractivesIndexes(MCHR_ID  SensorID, double *pCoefArray, long *piCoefArraySize);

/*!
	\fn short MCHR_SetSpectralRefractivesIndexes(MCHR_ID  SensorID, double *pCoefArray, long iCoefArraySize)
	\if FR
		\brief Fonction permettant de parametrer les indice de refractions.
	\else
		\brief Function setting refractive indexes.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] double *pCoefArray : Tableau d'indices de refraction.
			\param [in] long piCoefArraySize : Taille du tableau d'indice.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] double *pCoefArray : Refractive indexes coeficients array.
			\param [in] long piCoefArraySize : Size of the refractive indexes array.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\par Compatibles Sensors : WARNING CHR 150, RUBY, DUO or TRIO ONLY 
	\else
		\par Compatibles Sensors : WARNING CHR 150, RUBY, DUO or TRIO ONLY 
		\endif
*/
DLL_CHR_API short MCHR_SetSpectralRefractivesIndexes(MCHR_ID  SensorID, double *pCoefArray, long iCoefArraySize);

/*!
	\fn short MCHR_EnableExternalThicknessProcessing(MCHR_ID  SensorID, BOOL bEnable,WORD wRefractiveIndexFileID)
	\if FR
		\brief Fonction permettant d'activer le calcul d'epaisseur extrenalise.
	\else
		\brief Function activating external thickness processing.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] BOOL bEnable : true pour activer la fonctionnalite.
			\param [in] WORD wRefractiveIndexFileID : Fichier d'indice de refraction.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] BOOL bEnable : true to enable external thickness processing.
			\param [in] WORD wRefractiveIndexFileID : Refractive indexes file.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
		\par Compatibles Sensors : ALL Except RUBY Sensor
*/
DLL_CHR_API short MCHR_EnableExternalThicknessProcessing(MCHR_ID  SensorID, BOOL bEnable, WORD wRefractiveIndexFileID);


/**************************************************************************
 ** White signal Acquisition                                              **
 **************************************************************************/
//???
//DLL_CHR_API short MCHR_GetWhiteRefMaxThreshold(MCHR_ID SensorID,long *piMxs);
//DLL_CHR_API short MCHR_SetWhiteRefMaxThreshold(MCHR_ID SensorID,long iMxs);


/**************************************************************************
 ** Black signal Acquisition                                              **
 **************************************************************************/

/*!
	\fn short MCHR_GetBlackMaxThreshold(MCHR_ID SensorID, long *piMxs);
	\if FR
		\brief Obtient le seuil maximum du black ref
	\else
		\brief Obtient the black Maximum Threshold 
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] long  *piMxs : Value of the black Max Threshold
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] long  *piMxs :  Value of the black Max Threshold
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetBlackMaxThreshold(MCHR_ID SensorID, long *piMxs);

/*!
	\fn short MCHR_SetBlackMaxThreshold(MCHR_ID SensorID, long iMxs);
	\if FR
		\brief Configure le seuil maximum du black ref
	\else
		\brief Set the bblack Maximum Threshold 
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long  iMxs : Value of the black Max Threshold
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long  iMxs :  Value of the black Max Threshold
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetBlackMaxThreshold(MCHR_ID SensorID, long iMxs);

/*!
	\fn short MCHR_GetBlackAveraging(MCHR_ID SensorID, long *piMxs);
	\if FR
		\brief Obtient le moyennage du black signal
	\else
		\brief Get the Averaging of the black signal
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long  *piMxs : Value of the black averaging
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long  *piMxs : Value of the black averaging
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetBlackAveraging(MCHR_ID SensorID, long *piMxs);

/*!
	\fn short MCHR_SetBlackAveraging(MCHR_ID SensorID, long iMxs);
	\if FR
		\brief Configure le moyennage du black signal
	\else
		\brief Set the Averaging of the black signal
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long  iMxs : Value of the black averaging
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long  iMxs : Value of the black averaging
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetBlackAveraging(MCHR_ID SensorID, long iMxs);

/*!
	\fn short MCHR_AcqBlack (MCHR_ID  SensorID, void *pMinFreq);
	\if FR
		\brief Acquiere le black signal à toutes fréquences, et retourne la fréquence minimun.
	\else
		\brief Acquire black signal at all frequencies, and returns the minimum frequency.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] INT  iMxs : Value of the black averaging
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] void *pMinFreq : Mimimun frequency
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_AcqBlack (MCHR_ID  SensorID, void *pMinFreq);

//Acquire "fast dark" (at current rate only)
//DLL_CHR_API short MCHR_AcqFastBlack (MCHR_ID  SensorID, WORD Average, float InfluenceValue);

/*!
	\fn short MCHR_GetMaxCalibrationFileValue (MCHR_ID  SensorID,	PWORD pFullScale);
	\if FR
		\brief Obtient La valeur maximum du fichier de calibration.
		\warning Voir la fonction MCHR_GetMaxCalibrationFileValueEx pour utiliser le parametre pFullScale dans un format DWORD (à partir de la DLL_CHR V3.2.0.00)!
	\else
		\brief Get the maximum value of the calibration file.
		\warning See  MCHR_GetMaxCalibrationFileValueEx Function to use pFullScale parameter on DWORD Format (from DLL_CHR V3.2.0.00)!
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] PWORD pFullScale : 
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] PWORD pFullScale : Maximum value 
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetMaxCalibrationFileValue (MCHR_ID  SensorID,	PWORD pFullScale);


/*!
	\fn short MCHR_GetMaxCalibrationFileValueEx (MCHR_ID  SensorID,	PDWORD pFullScale);
	\if FR
		\brief Obtient La valeur maximum du fichier de calibration.
		\warning Remplace la fonction MCHR_GetMaxCalibrationFileValue.
	\else
		\brief Get the maximum value of the calibration file.
		\warning Replace  the  MCHR_GetMaxCalibrationFileValue Function.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] PDWORD pFullScale : 
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] PDWORD pFullScale : Maximum value 
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetMaxCalibrationFileValueEx (MCHR_ID  SensorID,	PDWORD pFullScale);

/*!
	\fn short MCHR_SetLanguage (MCHR_ID  SensorID, char *szLanguage);
	\if FR
		\brief Configure le language d'utilisation.
	\else
		\brief Set the sensor language.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] char *szLanguage : Code du language
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] char *szLanguage : code of language
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetLanguage (MCHR_ID  SensorID, char *szLanguage);

/*!
	\fn short MCHR_GetLanguage (MCHR_ID  SensorID, char *szLanguage, long iLength);
	\if FR
		\brief Obtient le language d'utilisation.
	\else
		\brief Get the sensor language.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] char *szLanguage : Code du language
			\param [in] long iLength : longueur de la chaine
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] CHAR *szLanguage : code of language
			\param [in] long iLength : size of string
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetLanguage (MCHR_ID  SensorID, char *szLanguage, long iLength);


/*!
	\fn short MCHR_SendColorReference  (MCHR_ID  SensorID, char *ColorRefFile, CALLBACK_SEND_FILE CallBackFct)
	\if FR
		\brief Fonction d'envoi du fichier de reference de couleur dans le SPECTRO.
	\else
		\brief Function Download the Color Reference file to the SPECTRO.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] char *ColorRefFile : Nom du fichier contenant les paramètres de reference de couleurs à telecharger
			\param [out] CALLBACK_SEND_FILE CallBackFct : Fonction callback appelee pendant le telechargement
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] char *ColorRefFile : file name with the color reference parameters to be downloaded
			\param [out] CALLBACK_SEND_FILE CallBackFct : Function callback during the download
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/

DLL_CHR_API short MCHR_SendColorReference  (MCHR_ID  SensorID, char *ColorRefFile, CALLBACK_SEND_FILE CallBackFct);

/*!
	\fn short MCHR_SendReferenceSpectrum  (MCHR_ID  SensorID, char *RefSpectrumFile, CALLBACK_SEND_FILE CallBackFct)
	\if FR
		\brief Fonction d'envoi du fichier de spectre de reference dans le SPECTRO.
	\else
		\brief Function Download the Reference Spectrum file to the SPECTRO.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] char *RefSpectrumFile :  Nom du fichier contenant le spectre de reference à telecharger
			\param [out] CALLBACK_SEND_FILE CallBackFct : 
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] char *RefSpectrumFile : name file with the reference spectral to be downloaded
			\param [out] CALLBACK_SEND_FILE CallBackFct :  Function callback during the download
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/

DLL_CHR_API short MCHR_SendReferenceSpectrum  (MCHR_ID  SensorID, char *RefSpectrumFile, CALLBACK_SEND_FILE CallBackFct);


/*!
	\fn short MCHR_GetSmoothingValue(MCHR_ID  SensorID, long *pSmoothingValue)
	\if FR
		\brief Fonction de lecture de l'indice de lissage.
	\else
		\brief Function Get current smoothing index.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long *pSmoothingValue : 
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long *pSmoothingValue : Value of smoothing index
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/

DLL_CHR_API short MCHR_GetSmoothingValue(MCHR_ID  SensorID, long *pSmoothingValue);
/* ------------------------------------------------------------------------- */

/*!
	\fn short MCHR_GetFirstCCDPixelRead(MCHR_ID  SensorID, long *iPixel);
	\if FR
		\brief Obtient le premier pixel lu par le CDD
	\else
		\brief Get the first pixel readed by the CDD.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long *iPixel : Valeur du premier pixel.
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] long *iPixel : Value of the first pixel.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetFirstCCDPixelRead(MCHR_ID  SensorID, long *iPixel);

/*!
	\fn short MCHR_SetSmoothingValue (MCHR_ID  SensorID, long SmoothingValue)
	\if FR
		\brief Fonction de parametrage de l'indice de lissage.
	\else
		\brief Function Set smothing value.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long SmoothingValue : 
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long SmoothingValue : Value of smoothing index
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription

*/

DLL_CHR_API short MCHR_SetSmoothingValue (MCHR_ID  SensorID, long SmoothingValue);

/*!
	\fn short MCHR_GetMultiplexChannel(MCHR_ID  SensorID, WORD *piChannel)
	\if FR
		\brief Fonction pour detecter l'ID du canal utilise sur le capteur. (0 par defaut)
	\else
		\brief Function Get the chanel ID currently used by the sensor (by default 0).
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] WORD *piChannel : ID du canal utilise
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] WORD *piChannel : Chanel ID in use
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
	\see MCHR_GetErrorDescription
	\if FR 
		\brief <b>Capteurs Compatibles :</b> MULTIPLEX CCS PRIMA.<br><br>
	\else
		\par Compatibles Sensors : MULTIPLEX CCS PRIMA
	\endif
*/
DLL_CHR_API short MCHR_GetMultiplexChannel(MCHR_ID  SensorID, WORD *piChannel);

/*!
	\fn short MCHR_SetMultiplexChannel(MCHR_ID  SensorID, WORD iChannel)
	\if FR
		\brief Fonction pour parametrer l'ID du canal utilise sur le capteur.
	\else
		\brief Function Set the chanel ID used by the sensor.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] WORD iChannel : ID du canal selectionne
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] WORD iChannel : Selected Chanel ID 
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\par Compatibles Sensors : MULTIPLEX CCS PRIMA
	\else
		\par Compatibles Sensors : MULTIPLEX CCS PRIMA
	\endif
*/
DLL_CHR_API short MCHR_SetMultiplexChannel(MCHR_ID  SensorID, WORD iChannel);

/* Returns the number of channels provided by the sensor */

/*!
	\fn short MCHR_GetMultiplexChannelNumber(MCHR_ID  SensorID, WORD *pwChannelNumber)
	\if FR
		\brief Fonction pour detecter le nombre de canaux dont le capteur est pourvu.
	\else
		\brief Function Get the number of channels provided by the sensor.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] WORD *pwChannelNumber : Nombre de canaux du capteur
			\return short : un code d'erreur MCHR_ERROR.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] WORD *pwChannelNumber : Number of chanels
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
	\brief
	\if FR 
		\brief <b>Capteurs Compatibles :</b> MULTIPLEX CCS PRIMA<br><br>
	\else
		\par Compatibles Sensors : MULTIPLEX CCS PRIMA
	\endif
*/

DLL_CHR_API short MCHR_GetMultiplexChannelNumber(MCHR_ID  SensorID, WORD *pwChannelNumber);

/*!
	\fn short MCHR_AcqMultiplexDark(MCHR_ID  SensorID, long *pMinFreq,WORD wNbFreqElem)
	\if FR
		\brief Fonction Acquisition du signal Dark sur tous les canaux du CCS PRIMA multiplexe. ( contraire de MCHR_AcqDark qui acquiere le Dark uniquement sur le canal courant).
	\else
		\brief Function Acquire dark signal for all CCS PRIMA multiplex channels. (in contrast with the MCHR_AcqDark which acquires ans saves the Dark for the current channel only).
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] long *pMinFreq : Tableau d'entiers alloué par l'appelant et rempli par la DLL avec les frequences minimum permises sur chaque canal
			\param [out] WORD wNbFreqElem : Nombre des elements alloues pour pMinFreq (doit etre egal au nombre de canaux disponibles sur le capteur)
			\return short : un code d'erreur MCHR_ERROR. la fonction retourne une erreur si elle est appelé pour un seul canal du capteur.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] long *pMinFreq : Array of integer allocated by the caller that with be filled by the DLL with the minimum frequencies allowed for each channels
			\param [out] WORD wNbFreqElem : Number of elements allocated for pMinFreq (should be equal to the number of channels available on the device)
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code. The function return an error if called for single-channel sensors.
		\endif
		\see MCHR_GetErrorDescription
		\if FR 
		\brief <b>Capteurs Compatibles :</b> MULTIPLEX CCS PRIMA. <br><br>
	\else
		\par Compatibles Sensors : MULTIPLEX CCS PRIMA. 
	\endif
*/

DLL_CHR_API short MCHR_AcqMultiplexDark(MCHR_ID  SensorID, long *pMinFreq, WORD wNbFreqElem);
/* ------------------------------------------------------------------------- */

#if defined(_cplusplus) || defined(__cplusplus)
}
#endif /* _cplusplus */

#endif