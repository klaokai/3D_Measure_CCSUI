/*************************************************************************/
/*			STIL   *   Software Departement        		                */
/*----------------------------------------------------------------------*/
/*                                                                      */
/*              MchrError.h                      				        */
/*                                                                      */
/*----------------------------------------------------------------------*/
/*  Project .................................. CHR    DLL               */
/*  Reference documents                      "Specification DLL CHR-150"*/
/*  Programming Language  .................    Visual C++ v6.0          */
/*  Starting date          ................... 16/01/2003               */
/*  Date of last update          .............                          */
/*  Author(s)................................. DMO                      */
/*  Required Files    .........................none                     */
/*  Required hardware ....................     PC Pentium 350 Mhz       */
/*  Prefix ...........                         MCHR_                    */
/*----------------------------------------------------------------------*/
/*  This HEADER file defines the errors returned by the                 */
/*  "MCHR_GetLastError"  function and other DLL functions               */ 
/*                                                                      */
/*                                                                      */
/*----------------------------------------------------------------------*/
/*  V°   |   Date    |AUTHOR|                   COMMENTS                */
/*-------+---------- +--------------------------------------------------*/
/*  01   | 16 Janu 03| DMO  | Initial version                           */
/*  02   | 18 Nov  05| DMO  | Ethernet, XE, Downloads                   */
/*----------------------------------------------------------------------*/

#ifndef DEFINEERROR_H
#define DEFINEERROR_H


#if defined(_cplusplus) || defined(__cplusplus)
extern "C" {
#endif /* _cplusplus */

/*
 ERREURS RETOURNEES PAR LES FONCTIONS DE LA DLL
 INTERPRETATION OF ERRORS RETURNED BY THE DLL FUNCTIONS
*/

/*!
  \def MCHR_ERROR
  \if FR
	 La fonction est sortie en erreur, utilisez \link MCHR_GetLastError MCHR_GetLastError \endlink pour en connaitre son origine
  \else
	 The function is in error, call \link MCHR_GetLastError MCHR_GetLastError \endlink to know the origin of the error
  \endif
*/
#define  MCHR_ERROR                      0
/*!
  \def MCHR_ERROR_NONE 
  \if FR
	 Pas d'erreur, la fonction s'est correctement exécutée
  \else
	 No ERROR, the function is OK.
  \endif
*/
#define  MCHR_ERROR_NONE                 1
/*!
  \def MCHR_ERROR_CODE 
  \if FR
	 Début du codage des types d'erreur.
  \else
	 Starting of ERROR CODE
  \endif
*/
#define  MCHR_ERROR_CODE                 0xf000

/*!
  \def MCHR_ERROR_NOT_CONNECTED
  \if FR
	 Problème de communication avec le CHR
  \else
	 Error encountered when trying to communicate with the CHR
  \endif
*/

#define  MCHR_ERROR_NOT_CONNECTED       (MCHR_ERROR_CODE +  0x01)  

/*!
  \def MCHR_ERROR_SERIAL_PORT
  \if FR
	 La fonction a rencontre un problème pour initialiser le port serie (IdSerialPort > 0) specifie.
  \else
	 Error encountered when trying to initialize the specified COM PORT (IdSerialPort > 0)
  \endif
*/

#define  MCHR_ERROR_SERIAL_PORT         (MCHR_ERROR_CODE +  0x03)  


/*!
  \def MCHR_ERROR_READ_CONFIG_FILE
  \if FR
	 Un problème est survenu lors de la lecture du fichier de configuration specifie.
  \else
	 Error encountered when trying to read the specified confoguration file
  \endif
*/

#define  MCHR_ERROR_READ_CONFIG_FILE    (MCHR_ERROR_CODE +  0x04)  


/*!
  \def MCHR_ERROR_WRITE_CONFIG_FILE
  \if FR
	 Un problème est survenu lors de l'ecriture du fichier de configuration specifie.
  \else
	 Error encountered when trying to write the specified configuration file
  \endif
*/

#define  MCHR_ERROR_WRITE_CONFIG_FILE   (MCHR_ERROR_CODE +  0x05)  


/*!
  \def MCHR_ERROR_RECEIVE_CONFIG_CHR
  \if FR
	 Un problème est survenu lors de la recuperation de la configuration du CHR.
  \else
	 Error encountered when trying to get the CHR configuration
  \endif
*/

#define  MCHR_ERROR_RECEIVE_CONFIG_CHR  (MCHR_ERROR_CODE +  0x06)


/*!
  \def MCHR_ERROR_SEND_CONFIG_CHR
  \if FR
	 Un problème est survenu lors de la transmission de la configuration du CHR.
  \else
	 Error encountered during  CHR configuration transmission
  \endif
*/
#define  MCHR_ERROR_SEND_CONFIG_CHR     (MCHR_ERROR_CODE +  0x07)


/*!
  \def MCHR_ERROR_NAME_ALREADY_EXIST
  \if FR
	 Le nom du CHR recherche existe dejà dans la liste des CHR initialises.
  \else
	 The name of the specified CHR exist already in the list of initialized CHR
  \endif
*/
#define  MCHR_ERROR_NAME_ALREADY_EXIST  (MCHR_ERROR_CODE +  0x08) 



/*!
  \def MCHR_ERROR_ADD_SENSOR
  \if FR
	 Il y a une erreur lors de l'ajout du capteur.
  \else
	 Error while adding a new CHR
  \endif
*/
#define  MCHR_ERROR_ADD_SENSOR          (MCHR_ERROR_CODE +  0x09)


/*!
  \def MCHR_ERROR_UNKNOWN_SENSOR
  \if FR
	 Le CHR n'existe pas dans la liste des CHR initialises.
  \else
	 The specified CHR does not exist in the list of initialized CHR
  \endif
*/
#define  MCHR_ERROR_UNKNOWN_SENSOR       (MCHR_ERROR_CODE + 0x0a)


/*!
  \def MCHR_ERROR_NO_SENSOR_CONNECTED
  \if FR
	 Pas de capteur CHR connecte.
  \else
	 No CHR is currently connected
  \endif
*/
#define  MCHR_ERROR_NO_SENSOR_CONNECTED (MCHR_ERROR_CODE + 0x0b)  



/*!
  \def MCHR_ERROR_PARAM_NOT_VALID
  \if FR
	 Le paramètre de la fonction demandee n'est pas valide.
  \else
	 Invalid argument for the required function
  \endif
*/
#define  MCHR_ERROR_PARAM_NOT_VALID     (MCHR_ERROR_CODE + 0x0c)  



/*!
  \def MCHR_ERROR_DIALOG_CHR
  \if FR
	 Une erreur de dialogue est apparue lors d'un echange avec le CHR.
  \else
	 Dialog error encountered while communicationg with the CHR
  \endif
*/
#define  MCHR_ERROR_DIALOG_CHR          (MCHR_ERROR_CODE + 0x0d)  



/*!
  \def MCHR_ERROR_START_RECEP_THREAD
  \if FR
	 Une erreur s'est produite lors de l'initialisation du thread de reception.
  \else
	 Error encountered while initializing the Reception Thread
  \endif
*/
#define  MCHR_ERROR_START_RECEP_THREAD  (MCHR_ERROR_CODE + 0x0e)  



/*!
  \def MCHR_ERROR_NOTHING_TO_ABORT
  \if FR
	 S'il n'y a aucune commande à arrêter.
  \else
	 No command is being executed while "Abort" command is received
  \endif
*/
#define  MCHR_ERROR_NOTHING_TO_ABORT    (MCHR_ERROR_CODE + 0x0f)


/*!
  \def MCHR_ERROR_ABORT_COMMAND
  \if FR
	 Si impossible d'arrêter une commande.
  \else
	 Abort command failed
  \endif
*/
#define  MCHR_ERROR_ABORT_COMMAND       (MCHR_ERROR_CODE + 0x10)  


/*!
  \def MCHR_ERROR_DLL_NOT_ACTIVE
  \if FR
	 Si la DLL n'a pas ete initialisee et activee.
  \else
	 The DLL has not been initialized and activated
  \endif
*/
#define  MCHR_ERROR_DLL_NOT_ACTIVE      (MCHR_ERROR_CODE + 0x11)


/*!
  \def MCHR_ERROR_CHR_BUSY
  \if FR
	 Si la DLL est dejà occupee à traiter une commande.
  \else
	 The DLL is busy executing a previous command
  \endif
*/
#define  MCHR_ERROR_CHR_BUSY            (MCHR_ERROR_CODE + 0x12) 


/*!
  \def MCHR_ERROR_SCANRATE_TOO_HIGH
  \if FR
	 La Frequence de mesure est trop elevee pour transmettre all required data.
  \else
	 The acquisition rate is too high, impossible to transmit all requested data at this rate
  \endif
*/
#define  MCHR_ERROR_SCANRATE_TOO_HIGH   (MCHR_ERROR_CODE + 0x13)  


/*!
  \def MCHR_ERROR_ONLY_CHR450_FUNCTION
  \if FR
	 La fonction demande n'est valide que pour  un CHR-450.
  \else
	 The specified function is autorized for CHR 450 only, the current CHR is not a 450
  \endif
*/
#define  MCHR_ERROR_ONLY_CHR450_FUNCTION (MCHR_ERROR_CODE + 0x14)  



/*!
  \def MCHR_ERROR_ACQUISTION_STOPPED
  \if FR
	 Erreur de la fonction car il n'y a pas d'acquisition en cours.
  \else
	 No acquisition is currently in progress
  \endif
*/
#define  MCHR_ERROR_ACQUISITION_STOPPED   (MCHR_ERROR_CODE + 0x15)  



/*!
  \def MCHR_ERROR_INTERNAL_FUNCTION
  \if FR
	 Erreur interne de la fonction.
  \else
	 Unspecified error during function execution
  \endif
*/
#define  MCHR_ERROR_INTERNAL_FUNCTION    (MCHR_ERROR_CODE + 0x16)  



/*!
  \def MCHR_ERROR_NOT_IN_INTERFEROMETRIC_MODE
  \if FR
	 Erreur de la fonction car le CHR n'est pas en mode interferometrique.
  \else
	 The specified function is autorized on interferometric mode only, the CHR is not in this mode
  \endif
*/
#define  MCHR_ERROR_NOT_IN_INTERFEROMETRIC_MODE   (MCHR_ERROR_CODE + 0x17)



/*!
  \def MCHR_ERROR_DARK_NOT_VALID
  \if FR
	 Erreur lors de la commande Fast Dark.
  \else
	 Error during "Fast Dark" command execution
  \endif
*/
#define  MCHR_ERROR_DARK_NOT_VALID       (MCHR_ERROR_CODE + 0x18) 



/*!
  \def MCHR_ERROR_INTERFEROMETRIC_MODE_NOT_AUTHORIZED
  \if FR
	 Le mode Interferometrique n'est pas autorise sur ce capteur.
  \else
	 The interferometric mode is not authorized with this sensor
  \endif
*/
#define  MCHR_ERROR_INTERFEROMETRIC_MODE_NOT_AUTHORIZED (MCHR_ERROR_CODE + 0x19) 



/*!
  \def MCHR_ERROR_NOT_VALID_CHR_CMD
  \if FR
	 La commande envoye sur le capteur n'est pas valide.
  \else
	 The command is not authorized for the current sensor type
  \endif
*/
#define  MCHR_ERROR_NOT_VALID_CHR_CMD (MCHR_ERROR_CODE + 0x1a)



/*!
  \def MCHR_ERROR_READ_CALIBRATION_FILE
  \if FR
	 Un problème est survenu lors de la lecture du fichier de calibration.
  \else
	 Impossible to read calibration file
  \endif
*/
#define  MCHR_ERROR_READ_CALIBRATION_FILE (MCHR_ERROR_CODE + 0x1b)  


/*!
  \def MCHR_ERROR_SEND_CALIBRATION_TABLE
  \if FR
	 Un problème est survenu lors de l'envoi de la table de calibration vers le capteur specifie.
  \else
	 Impossible to send the calibration file
  \endif
*/
#define  MCHR_ERROR_SEND_CALIBRATION_TABLE (MCHR_ERROR_CODE + 0x1c)


/*!
  \def MCHR_ERROR_IP_ADDRESS
  \if FR
	 L'adresse IP specifie n'est pas valide.
  \else
	 Illegal IP address
  \endif
*/
#define  MCHR_ERROR_IP_ADDRESS       (MCHR_ERROR_CODE +  0x1d)



/*!
  \def MCHR_ERROR_BUFFER_FULL
  \if FR
	 Les buffers de receptions sont plein, Cadence de lecture trop lente.
  \else
	 Reception buffer overflow, reading rate is too slow
  \endif
*/
#define  MCHR_ERROR_BUFFER_FULL     (MCHR_ERROR_CODE +  0x1e)     



/*!
  \def MCHR_ERROR_TRIGGER_TYPE
  \if FR
	 Le mode de trigger demande n'existe pas.
  \else
	 Unrecognized trigger type
  \endif
*/
#define  MCHR_ERROR_TRIGGER_TYPE    (MCHR_ERROR_CODE +  0x1f)     



/*!
  \def MCHR_ERROR_READ_FIRMWARE_FILE
  \if FR
	 Erreur de lecture du fichier firmware.
  \else
	 Impossible to read the firmware file
  \endif
*/
#define  MCHR_ERROR_READ_FIRMWARE_FILE (MCHR_ERROR_CODE +  0x20)  



/*!
  \def MCHR_ERROR_READ_ADDITIONAL_FILE
  \if FR
	 Erreur de lecture du fichier menu.
  \else
	 Impossible to read the menu file
  \endif
*/
#define  MCHR_ERROR_READ_ADDITIONAL_FILE (MCHR_ERROR_CODE +  0x21)



/*!
  \def MCHR_ERROR_SEND_FIRMWARE_FILE
  \if FR
	 Erreur d'envoi du fichier firmware.
  \else
	 Impossible to send the firmware file
  \endif
*/
#define  MCHR_ERROR_SEND_FIRMWARE_FILE (MCHR_ERROR_CODE +  0x22)  


/*!
  \def MCHR_ERROR_SEND_ADDITIONAL_FILE
  \if FR
	 Erreur d'envoi du fichier menu.
  \else
	 Impossible to send the menu file
  \endif
*/

#define  MCHR_ERROR_SEND_ADDITIONAL_FILE (MCHR_ERROR_CODE +  0x23)



/*!
  \def MCHR_ERROR_RUN_FIRMWARE
  \if FR
	 Une erreur est survenue lors de l'execution de la nouvelle version du firmware.
  \else
	 Error while trying to run the new firmware version
  \endif
*/
#define  MCHR_ERROR_RUN_FIRMWARE (MCHR_ERROR_CODE +  0x24)


/*!
  \def MCHR_ERROR_SAVE_FIRMWARE
  \if FR
	 Erreur de sauvegarde du firmware.
  \else
	 Error while trying to save the new firmware version
  \endif
*/

#define  MCHR_ERROR_SAVE_FIRMWARE (MCHR_ERROR_CODE +  0x25)       


/*!
  \def MCHR_ERROR_RESTART_CHR
  \if FR
	 Erreur de redemarrage apres sauvegarde du firmware.
  \else
	 Error while trying restart the sensor after saving the new firmware version
  \endif
*/

#define  MCHR_ERROR_RESTART_CHR (MCHR_ERROR_CODE +  0x26)         



/*!
  \def MCHR_ERROR_ONLY_CHR150_FUNCTION
  \if FR
	 La fonction demande n'est valide que pour  un CHR-150.
  \else
	 The specified function is autorized for CHR 150 only, the current CHR is not a 150
  \endif
*/

#define  MCHR_ERROR_ONLY_CHR150_FUNCTION (MCHR_ERROR_CODE + 0x27) /* La fonction demande n'est valide que pour  un CHR-150 */
                                                                  /* The specified function is autorized for CHR 150 only, the current CHR is not a 150 */

/*!
  \def MCHR_ERROR_ONLY_CCS_FUNCTION
  \if FR
	 La fonction demande n'est valide que pour  un CCS.
  \else
	 The specified function is autorized for CCS only, the current CHR is not a 150
  \endif
*/

#define  MCHR_ERROR_ONLY_CCS_FUNCTION (MCHR_ERROR_CODE + 0x28)



/*!
  \def MCHR_ERROR_NO_TRANSMITTED_DATA
  \if FR
	 Aucune donnee n'est configuree sur la sortie numerique utilisee.
  \else
	 No data item is configured to be transmitted on current digital output channel
  \endif
*/
#define MCHR_ERROR_NO_TRANSMITTED_DATA  (MCHR_ERROR_CODE + 0x29)    




/*!
  \def MCHR_ERROR_ETHERNET_NOT_SUPPORTED
  \if FR
	 La Liaison Ethernet n'est pas supporte sur ce capteur.
  \else
	 The Ethernet link is not supported on this sensor
  \endif
*/
#define MCHR_ERROR_ETHERNET_NOT_SUPPORTED  (MCHR_ERROR_CODE + 0x2a)    



/*!
  \def MCHR_ERROR_SEND_SERIAL_NUMBER
  \if FR
	 L'envoi du numero de serie à echoue.
  \else
	 Failed to send Serial Number
  \endif
*/
#define MCHR_ERROR_SEND_SERIAL_NUMBER      (MCHR_ERROR_CODE + 0x2b)  




/*!
  \def MCHR_ERROR_ONLY_ILB_FUNCTION
  \if FR
	 La fonction demande n'est valide que pour  un capteur ILB.
  \else
	 The specified function is autorized for an ILB sensor
  \endif
*/
#define  MCHR_ERROR_ONLY_ILB_FUNCTION (MCHR_ERROR_CODE + 0x2c)



/*!
  \def MCHR_ERROR_FUNCTION_NOT_AVAILABLE
  \if FR
	 La fonction demande n'est pas disponible sur le capteur.
  \else
	 The specified function is not available on the device
  \endif
*/
#define  MCHR_ERROR_FUNCTION_NOT_AVAILABLE (MCHR_ERROR_CODE + 0x2d)    



/*!
  \def MCHR_ERROR_FREQUENCY_TOO_HIGH
  \if FR
	 La frequence est trop elevee.
  \else
	 Frequency too high
  \endif
*/
#define  MCHR_ERROR_FREQUENCY_TOO_HIGH (MCHR_ERROR_CODE + 0x2e)    



/*!
  \def MCHR_ERROR_FREQUENCY_TOO_LOW
  \if FR
	 La frequence est trop basse.
  \else
	 Frequency too low
  \endif
*/
#define  MCHR_ERROR_FREQUENCY_TOO_LOW (MCHR_ERROR_CODE + 0x2f)



/*!
  \def MCHR_ERROR_WHITE_TOO_HIGH
  \if FR
	 Erreur lors de la commande d'acquisition du Blanc : le signal est trop haut.
  \else
	 Error during "White Acquisition" command execution : the signal is too High
  \endif
*/
#define MCHR_ERROR_WHITE_TOO_HIGH       (MCHR_ERROR_CODE + 0x3a) 


/*!
  \def MCHR_ERROR_WHITE_TOO_LOW
  \if FR
	 Erreur lors de la commande d'acquisition du Blanc : le signal est trop bas.
  \else
	 Error during "White Acquisition" command execution : the signal is too low
  \endif
*/
#define MCHR_ERROR_WHITE_TOO_LOW        (MCHR_ERROR_CODE + 0x3b) 


/*!
  \def MCHR_ERROR_WHITE_SATURED
  \if FR
	 Erreur lors de la commande d'acquisition du Blanc : le signal est sature.
  \else
	 Error during "White Acquisition" command execution : the signal is satured
  \endif
*/
#define MCHR_ERROR_WHITE_SATURED       (MCHR_ERROR_CODE + 0x3c) 



/*!
  \def MCHR_ERROR_ONLY_ETHERNET_CONNECTION
  \if FR
	 La fonction demande n'est valide que pour une connection Ethernet.
  \else
	 The function is avalaible only for an ethernet connection
  \endif
*/
#define MCHR_ERROR_ONLY_ETHERNET_CONNECTION (MCHR_ERROR_CODE + 0x3d) 




/*!
  \def MCHR_ERROR_ILB_PARAM
  \if FR
	 Probleme dans l'envoi / reception de parametres ILB.
  \else
	 Error during setting / getting ILB parameters
  \endif
*/
#define MCHR_ERROR_ILB_PARAM (MCHR_ERROR_CODE + 0x3e)  


/*!
  \def MCHR_ERROR_NOT_CHR150_FUNCTION
  \if FR
	 La fonction demande n'est pas valide pour  un CHR-150.
  \else
	 The specified function is unautorized for CHR 150 
  \endif
*/
#define  MCHR_ERROR_NOT_CHR150_FUNCTION (MCHR_ERROR_CODE + 0x3f) /* La fonction demande n'est valide que pour  un CHR-150 */


/*!
  \def MCHR_ERROR_TO_START_WHITE_REF_ACQ
  \if FR
	 Erreur de lancement de l'acquisition du whiteRef
  \else
	 Failure to start the acquisition of WhiteRef
  \endif
*/

#define  MCHR_ERROR_TO_START_WHITE_REF_ACQ (MCHR_ERROR_CODE + 0x40) /* La fonction demande n'est valide que pour  un CHR-150 */

/*!
  \def MCHR_ERROR_TO_STOP_WHITE_REF_ACQ
  \if FR
	 Erreur d'arrêt de l'acquisition du whiteRef
  \else
	 Failure to stop the acquisition of WhiteRef
  \endif
*/

#define  MCHR_ERROR_TO_STOP_WHITE_REF_ACQ (MCHR_ERROR_CODE + 0x41) /* La fonction demande n'est valide que pour  un CHR-150 */

/*!
  \def MCHR_ERROR_TO_STOP_WHITE_REF_ACQ
  \if FR
	 Erreur Autorisation d'accès
  \else
	 Failure Permission access
  \endif
*/
#define  MCHR_ERROR_UNAUTHORIZED_ACCESS	(MCHR_ERROR_CODE + 0x42)  /* Permission access */

/*!
  \def MCHR_ERROR_FREQ_SMALLER_THAN_MIN_DARK_FREQ
  \if FR
	 Erreur fréquence du scanrate en dessous de la fréquence du dark minimum
  \else
	 Failure the resquested frequency is smaller then the min dark frequency
  \endif
*/
#define  MCHR_ERROR_FREQ_SMALLER_THAN_MIN_DARK_FREQ (MCHR_ERROR_CODE + 0x43) 


/*!
  \def MCHR_ERROR_SENSOR_ALREADY_IN_USE
  \if FR
	 Le capteur est déjà utilisé par une autre instance ou processus.
  \else
	 The sensor is already in use with another instance or process.
  \endif
*/
#define  MCHR_ERROR_SENSOR_ALREADY_IN_USE  (MCHR_ERROR_CODE + 0x44)  



/*!
  \def MCHR_ERROR_UNKNOWN
  \if FR
	 Erreur inconue.
  \else
	 Unknown error
  \endif
*/
#define  MCHR_ERROR_UNKNOWN           (MCHR_ERROR_CODE + 0x0100)

/* ------------------------------------------------------------------- */

#if defined(_cplusplus) || defined(__cplusplus)
}
#endif /* _cplusplus */

#endif