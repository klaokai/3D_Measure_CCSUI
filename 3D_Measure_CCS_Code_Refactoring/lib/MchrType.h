/*************************************************************************/
/*			STIL   *   Software Departement        		                */
/*----------------------------------------------------------------------*/
/*                                                                      */
/*              MchrType.h                      				        */
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
/*  This HEADER file defines types and event handles                    */ 
/*                                                                      */
/*                                                                      */
/*----------------------------------------------------------------------*/
/*  V?  |   Date    |AUTHOR|                   COMMENTS                */
/*-------+---------- +--------------------------------------------------*/
/*  01   | 16 Janu 03| DMO  | Initial version                           */
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*  02   | 08 Dec  03| DMO  | Add CHR-450 fonctionnality                */
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*  03   | 04 Nov  05| DMO  | Add CHR-450XE fonctionnality              */
/*       |           |      | Add download functions                    */
/*----------------------------------------------------------------------*/

#ifndef MCHRTYPE_H
#define MCHRTYPE_H

#if defined(_cplusplus) || defined(__cplusplus)
extern "C" {
#endif /* _cplusplus */

/*!	\typedef unsigned short MCHR_ID
	\brief 
		\if FR
			Identifiant du controleur.
		\else
			Controller's ID.
		\endif
*/
typedef unsigned short MCHR_ID;



/* CHR types */

/*! \enum enChrType
	\brief 	
       \if FR
      	Types de controleur.
     \else
     	Controller types.
     \endif
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enChrType
{
#else
typedef enum 
{
#endif
	/*! \if FR CAPTEUR CHR 150. \else SENSOR CHR 150 \endif */
   MCHR_150,
	/*! \if FR CAPTEUR CHR 450. \else SENSOR CHR 450 \endif */
   MCHR_450,
	/*! \if FR CAPTEUR CHR XE. \else SENSOR CHR XE \endif */
   MCHR_XE,				
	/*! \if FR CAPTEUR XE_E. \else SENSOR CHR XE_E \endif */
   MCHR_XE_E,
	/*! \if FR CAPTEUR CCS ALPHA. \else SENSOR CCS ALPHA \endif */
	MCHR_CCS_ALPHA,
	/*! \if FR CAPTEUR CCS PRIMA. \else SENSOR CCS PRIMA \endif */
	MCHR_CCS_PRIMA,
	/*! \if FR CAPTEUR CCS OPTIMA. \else SENSOR CCS OPTIMA \endif */
	MCHR_CCS_OPTIMA,
	/*! \if FR CAPTEUR CCS ULTIMA. \else SENSOR CCS ULTIMA \endif */
	MCHR_CCS_ULTIMA,
	/*! \if FR CAPTEUR CCS INITIAL. \else SENSOR CCS INITIAL \endif */
	MCHR_CCS_INITIAL,
	/*! \if FR CAPTEUR STIL DUO. \else SENSOR STIL DUO \endif */
   MCHR_DUO,
	/*! \if FR CAPTEUR STIL TRIO. \else SENSOR STIL TRIO \endif */
   MCHR_TRIO,
	/*! \if FR CAPTEUR RUBY. \else SENSOR RUBY \endif */
   MCHR_RUBY,
   MCHR_MAX_MODEL
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enChrType;
#endif

/*! \enum enChrConnection 
	\brief
		\if FR Types de connexion controleurs.
		\else Controller connection types.
		\endif
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enChrConnection
{
#else
typedef enum 
{
#endif
	/*! \if FR Utilisation d'une connexion sur port serie. \else < Use serial port connection. \endif */
   MCHR_SERIAL_CONNECTION,		
   /*! \if FR Utilisation d'une connexion sur port Ethernet. \else < Use Ethernet port connection. \endif */
   MCHR_ETHERNET_CONNECTION,	
   /*! \if FR Utilisation d'une connexion USB. \else < Use USB connection. \endif */
	MCHR_USB_CONNECTION,		
	/*! \if FR Limite du nombre de type de connexion. \else < Connection type limit number. \endif */
   MCHR_MAX_CONNECTION_TYPE		
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enChrConnection;
#endif


/*! \enum enSCAN_RATE_LIST_CHR150
	\brief
		\if FR Liste des frequences parametrables pour un controleur CHR 150.
		\else CHR 150 controller frequency possible values.
		\endif
	\warning 
		\if FR Seulement pour coffret CHR 150.
		\else Only for CHR 150 controller.
		\endif
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enSCAN_RATE_LIST_CHR150
{
#else
typedef enum 
{
#endif
	/*! \if FR Frequence de 30Hz predefinie sur CHR-150. \else 30Hz predefined scanrate for CHR-150. \endif */
   MCHR_SCAN_RATE_CHR150_30HZ=3,	
   /*! \if FR Frequence de 100Hz predefinie sur CHR-150. \else 100Hz predefined scanrate for CHR-150. \endif */
   MCHR_SCAN_RATE_CHR150_100HZ,		
   /*! \if FR Frequence de 300Hz predefinie sur CHR-150. \else 300Hz predefined scanrate for CHR-150. \endif */
   MCHR_SCAN_RATE_CHR150_300HZ,		
   /*! \if FR Frequence de 1000Hz predefinie sur CHR-150. \else 1000Hz predefined scanrate for CHR-150. \endif */
   MCHR_SCAN_RATE_CHR150_1000HZ,	
   /*! \if FR Limite des frequences predefinient sur CHR-150. \else Predefined scanrate limit for CHR-150. \endif */
   MCHR_MAX_SCAN_RATE_CHR150		

#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enSCAN_RATE_LIST_CHR150;
#endif


/*! \enum enSCAN_RATE_LIST_CHR450
	\brief
		\if FR Liste des frequences parametrables pour un controleur CHR 450.
		\else List of rate identifiers for CHR-450.
		\endif
	\warning 
		\if FR Seulement pour coffret CHR 450.
		\else Only for CHR 450 controller.
		\endif
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enSCAN_RATE_LIST_CHR450
{
#else
typedef enum 
{
#endif
	/*! \if FR Frequence de LIBRE predefinie sur CHR-150. \else FREE predefined scanrate for CHR-150. \endif */
   MCHR_SCAN_RATE_CHR450_LIBRE,
	/*! \if FR Frequence de 33Hz predefinie sur CHR450. \else 33Hz predefined scanrate for CHR450. \endif */
   MCHR_SCAN_RATE_CHR450_33HZ,
	/*! \if FR Frequence de 40Hz predefinie sur CHR450. \else 40Hz predefined scanrate for CHR450. \endif */
   MCHR_SCAN_RATE_CHR450_40HZ,
	/*! \if FR Frequence de 100Hz predefinie sur CHR450. \else 100Hz predefined scanrate for CHR450. \endif */
   MCHR_SCAN_RATE_CHR450_100HZ,
	/*! \if FR Frequence de 200Hz predefinie sur CHR450. \else 200Hz predefined scanrate for CHR450. \endif */
   MCHR_SCAN_RATE_CHR450_200HZ,
	/*! \if FR Frequence de 400Hz predefinie sur CHR450. \else 400Hz predefined scanrate for CHR450. \endif */
   MCHR_SCAN_RATE_CHR450_400HZ,
	/*! \if FR Frequence de 1000Hz predefinie sur CHR450. \else 1000Hz predefined scanrate for CHR450. \endif */
   MCHR_SCAN_RATE_CHR450_1000HZ,
	/*! \if FR Frequence de 2000Hz predefinie sur CHR450. \else 2000Hz predefined scanrate for CHR450. \endif */
   MCHR_SCAN_RATE_CHR450_2000HZ,
	/*! \if FR Frequence de 4000Hz predefinie sur CHR450. \else 4000Hz predefined scanrate for CHR450. \endif */
   MCHR_SCAN_RATE_CHR450_4000HZ,
	/*! \if FR Frequence Max predefinie sur CHR450. \else Max predefined scanrate for CHR450. \endif */
   MCHR_MAX_SCAN_RATE_CHR450
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enSCAN_RATE_LIST_CHR450;
#endif


/*! \enum enSCAN_RATE_LIST_CHRXE
	\brief
		\if FR Liste des frequences parametrables pour un controleur CHRXE.
		\else List of rate identifiers for CHRXE.
		\endif
	\warning 
		\if FR Seulement pour coffret CHRXE.
		\else Only for CHRXE controller.
		\endif
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enSCAN_RATE_LIST_CHRXE
{
#else
typedef enum 
{
#endif

	/*! \if FR Frequence libre predefinie sur CHRXE. \else FREE predefined scanrate for CHRXE. \endif */
   MCHR_SCAN_RATE_CHRXE_LIBRE,
   /*! \if FR Frequence de 33Hz predefinie sur CHRXE. \else 33Hz predefined scanrate for CHRXE. \endif */
   MCHR_SCAN_RATE_CHRXE_33HZ,
   /*! \if FR Frequence de 40Hz predefinie sur CHRXE. \else 40Hz predefined scanrate for CHRXE. \endif */
   MCHR_SCAN_RATE_CHRXE_40HZ,
   /*! \if FR Frequence de 100Hz predefinie sur CHRXE. \else 100Hz predefined scanrate for CHRXE. \endif */
   MCHR_SCAN_RATE_CHRXE_100HZ,
   /*! \if FR Frequence de 200Hz predefinie sur CHRXE. \else 200Hz predefined scanrate for CHRXE. \endif */
   MCHR_SCAN_RATE_CHRXE_200HZ,
   /*! \if FR Frequence de 400Hz predefinie sur CHRXE. \else 400Hz predefined scanrate for CHRXE. \endif */
   MCHR_SCAN_RATE_CHRXE_400HZ,
   /*! \if FR Frequence de 1000Hz predefinie sur CHRXE. \else 1000Hz predefined scanrate for CHRXE. \endif */
   MCHR_SCAN_RATE_CHRXE_1000HZ,
   /*! \if FR Frequence de 2000Hz predefinie sur CHRXE. \else 2000Hz predefined scanrate for CHRXE. \endif */
   MCHR_SCAN_RATE_CHRXE_2000HZ,
   /*! \if FR Frequence de 4000Hz predefinie sur CHRXE. \else 4000Hz predefined scanrate for CHRXE. \endif */
   MCHR_SCAN_RATE_CHRXE_4000HZ,
   /*! \if FR Frequence de 5000Hz predefinie sur CHRXE. \else 5000Hz predefined scanrate for CHRXE. \endif */
   MCHR_SCAN_RATE_CHRXE_5000HZ,
   /*! \if FR Frequence de 6000Hz predefinie sur CHRXE. \else 6000Hz predefined scanrate for CHRXE. \endif */
   MCHR_SCAN_RATE_CHRXE_6000HZ,
   /*! \if FR Frequence de 7000Hz predefinie sur CHRXE. \else 7000Hz predefined scanrate for CHRXE. \endif */
   MCHR_SCAN_RATE_CHRXE_7000HZ,
	/*! \if FR Frequence de 8000Hz predefinie sur CHRXE. \else 8000Hz predefined scanrate for CHRXE. \endif */
   MCHR_SCAN_RATE_CHRXE_8000HZ,
   /*! \if FR Frequence de 9000Hz predefinie sur CHRXE. \else 9000Hz predefined scanrate for CHRXE. \endif */
   MCHR_SCAN_RATE_CHRXE_9000HZ,
   /*! \if FR Frequence de 10000Hz predefinie sur CHRXE. \else 10000Hz predefined scanrate for CHRXE. \endif */
   MCHR_SCAN_RATE_CHRXE_10000HZ,
   /*! \if FR Frequence Max predefinie sur CHRXE. \else Max predefined scanrate for CHRXE. \endif */
   MCHR_MAX_SCAN_RATE_CHRXE
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enSCAN_RATE_LIST_CHRXE;
#endif

/*! \enum enSCAN_RATE_LIST_CHRXE_E
	\brief
		\if FR Liste des frequences parametrables pour un controleur CHRXe-E.
		\else list of rate identifiers for CHRXe-E.
		\endif
	\warning 
		\if FR Seulement pour coffret CHRXe-E.
		\else Only for CHRXe-E controller.
		\endif
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enSCAN_RATE_LIST_CHRXE_E
{
#else
typedef enum 
{
#endif

	/*! \if FR Frequence Libre predefinie sur CHRXE_E. \else FREE predefined scanrate for CHRXE_E. \endif */
   MCHR_SCAN_RATE_CHRXE_E_LIBRE,
   /*! \if FR Frequence de 100Hz predefinie sur CHRXE_E. \else 100Hz predefined scanrate for CHRXE_E. \endif */
   MCHR_SCAN_RATE_CHRXE_E_100HZ,
   /*! \if FR Frequence de 200Hz predefinie sur CHRXE_E. \else 200Hz predefined scanrate for CHRXE_E. \endif */
   MCHR_SCAN_RATE_CHRXE_E_200HZ,
   /*! \if FR Frequence de 400Hz predefinie sur CHRXE_E. \else 400Hz predefined scanrate for CHRXE_E. \endif */
   MCHR_SCAN_RATE_CHRXE_E_400HZ,
   /*! \if FR Frequence de 1000Hz predefinie sur CHRXE_E. \else 1000Hz predefined scanrate for CHRXE_E. \endif */
   MCHR_SCAN_RATE_CHRXE_E_1000HZ,
   /*! \if FR Frequence de 2000Hz predefinie sur CHRXE_E. \else 2000Hz predefined scanrate for CHRXE_E. \endif */
   MCHR_SCAN_RATE_CHRXE_E_2000HZ,
   /*! \if FR Frequence de 4000Hz predefinie sur CHRXE_E. \else 4000Hz predefined scanrate for CHRXE_E. \endif */
   MCHR_SCAN_RATE_CHRXE_E_4000HZ,
   /*! \if FR Frequence de 6250Hz predefinie sur CHRXE_E. \else 6250Hz predefined scanrate for CHRXE_E. \endif */
   MCHR_SCAN_RATE_CHRXE_E_6250HZ,
   /*! \if FR Frequence de 10000Hz predefinie sur CHRXE_E. \else 10000Hz predefined scanrate for CHRXE_E. \endif */
   MCHR_SCAN_RATE_CHRXE_E_10000HZ,
   /*! \if FR Frequence de 15625Hz predefinie sur CHRXE_E. \else 15625Hz predefined scanrate for CHRXE_E. \endif */
   MCHR_SCAN_RATE_CHRXE_E_15625HZ,
   /*! \if FR Frequence de 20000Hz predefinie sur CHRXE_E. \else 20000Hz predefined scanrate for CHRXE_E. \endif */
   MCHR_SCAN_RATE_CHRXE_E_20000HZ,
   /*! \if FR Frequence de 25000Hz predefinie sur CHRXE_E. \else 25000Hz predefined scanrate for CHRXE_E. \endif */
   MCHR_SCAN_RATE_CHRXE_E_25000HZ,
   /*! \if FR Frequence de 31250Hz predefinie sur CHRXE_E. \else 31250Hz predefined scanrate for CHRXE_E. \endif */
   MCHR_SCAN_RATE_CHRXE_E_31250HZ,
	 /*! \if FR Frequence Max predefinie sur CHRXE_E. \else Max predefined scanrate for CHRXE_E. \endif */
   MCHR_MAX_SCAN_RATE_CHRXE_E
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enSCAN_RATE_LIST_CHRXE_E;
#endif


/*! \enum enSCAN_RATE_LIST_CCS_ALPHA
	\brief
		\if FR Liste des frequences parametrables pour un controleur CCS-Alpha.
		\else list of rate identifiers for CCS-Alpha.
		\endif
	\warning 
		\if FR Seulement pour coffret CCS-Alpha.
		\else Only for CCS-Alpha controller.
		\endif
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enSCAN_RATE_LIST_CCS_ALPHA
{
#else
typedef enum 
{
#endif
	/*! \if FR Frequence Libre predefinie sur CCS_ALPHA. \else Free predefined scanrate for CCS_ALPHA. \endif */
   MCHR_SCAN_RATE_CCS_ALPHA_LIBRE,
   /*! \if FR Frequence de 40Hz predefinie sur CCS_ALPHA. \else 40Hz predefined scanrate for CCS_ALPHA. \endif */
   MCHR_SCAN_RATE_CCS_ALPHA_40HZ,
   /*! \if FR Frequence de 100Hz predefinie sur CCS_ALPHA. \else 100Hz predefined scanrate for CCS_ALPHA. \endif */
   MCHR_SCAN_RATE_CCS_ALPHA_100HZ,
   /*! \if FR Frequence de 200Hz predefinie sur CCS_ALPHA. \else 200Hz predefined scanrate for CCS_ALPHA. \endif */
   MCHR_SCAN_RATE_CCS_ALPHA_200HZ,
   /*! \if FR Frequence de 400Hz predefinie sur CCS_ALPHA. \else 400Hz predefined scanrate for CCS_ALPHA. \endif */
   MCHR_SCAN_RATE_CCS_ALPHA_400HZ,
   /*! \if FR Frequence de 1000Hz predefinie sur CCS_ALPHA. \else 1000Hz predefined scanrate for CCS_ALPHA. \endif */
   MCHR_SCAN_RATE_CCS_ALPHA_1000HZ,
   /*! \if FR Frequence de 2000Hz predefinie sur CCS_ALPHA. \else 2000Hz predefined scanrate for CCS_ALPHA. \endif */
   MCHR_SCAN_RATE_CCS_ALPHA_2000HZ,
   /*! \if FR Frequence Max predefinie sur CCS_ALPHA. \else Max predefined scanrate for CCS_ALPHA. \endif */
   MCHR_MAX_SCAN_RATE_CCS_ALPHA
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enSCAN_RATE_LIST_CCS_ALPHA;
#endif


/*! \enum enSCAN_RATE_LIST_CCS_PRIMA
	\brief
		\if FR Liste des frequences parametrables pour un controleur CCS_PRIMA.
		\else list of rate identifiers for CCS_PRIMA.
		\endif
	\warning 
		\if FR Seulement pour coffret CCS_PRIMA.
		\else Only for CCS_PRIMA controller.
		\endif
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enSCAN_RATE_LIST_CCS_PRIMA
{
#else
typedef enum 
{
#endif
	 /*! \if FR Frequence libre predefinie sur CCS_PRIMA. \else Free predefined scanrate for CCS_PRIMA. \endif */
   MCHR_SCAN_RATE_CCS_PRIMA_LIBRE,
    /*! \if FR Frequence de 100Hz predefinie sur CCS_PRIMA. \else 100Hz predefined scanrate for CCS_PRIMA. \endif */
   MCHR_SCAN_RATE_CCS_PRIMA_100HZ,
    /*! \if FR Frequence de 200Hz predefinie sur CCS_PRIMA. \else 200Hz predefined scanrate for CCS_PRIMA. \endif */
   MCHR_SCAN_RATE_CCS_PRIMA_200HZ,
    /*! \if FR Frequence de 400Hz predefinie sur CCS_PRIMA. \else 400Hz predefined scanrate for CCS_PRIMA. \endif */
   MCHR_SCAN_RATE_CCS_PRIMA_400HZ,
    /*! \if FR Frequence de 1000Hz predefinie sur CCS_PRIMA. \else 1000Hz predefined scanrate for CCS_PRIMA. \endif */
   MCHR_SCAN_RATE_CCS_PRIMA_1000HZ,
    /*! \if FR Frequence de 2000Hz predefinie sur CCS_PRIMA. \else 2000Hz predefined scanrate for CCS_PRIMA. \endif */
   MCHR_SCAN_RATE_CCS_PRIMA_2000HZ,
    /*! \if FR Frequence Max predefinie sur CCS_PRIMA. \else Max predefined scanrate for CCS_PRIMA. \endif */
   MCHR_MAX_SCAN_RATE_CCS_PRIMA
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enSCAN_RATE_LIST_CCS_PRIMA;
#endif


/*! \enum enSCAN_RATE_LIST_CCS_OPTIMA
	\brief
		\if FR Liste des frequences parametrables pour un controleur CCS_OPTIMA.
		\else list of rate identifiers for CCS_OPTIMA.
		\endif
	\warning 
		\if FR Seulement pour coffret CCS_OPTIMA.
		\else Only for CCS_OPTIMA controller.
		\endif
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enSCAN_RATE_LIST_CCS_OPTIMA
{
#else
typedef enum 
{
#endif

   /*! \if FR Frequence libre predefinie sur CCS_OPTIMA. \else Free predefined scanrate for CCS_OPTIMA. \endif */
   MCHR_SCAN_RATE_CCS_OPTIMA_LIBRE,
	/*! \if FR Frequence de 100Hz predefinie sur CCS_OPTIMA. \else 100Hz predefined scanrate for CCS_OPTIMA. \endif */
   MCHR_SCAN_RATE_CCS_OPTIMA_100HZ,
   /*! \if FR Frequence de 200Hz predefinie sur CCS_OPTIMA. \else 200Hz predefined scanrate for CCS_OPTIMA. \endif */
   MCHR_SCAN_RATE_CCS_OPTIMA_200HZ,
   /*! \if FR Frequence de 500Hz predefinie sur CCS_OPTIMA. \else 500Hz predefined scanrate for CCS_OPTIMA. \endif */
   MCHR_SCAN_RATE_CCS_OPTIMA_500HZ,
   /*! \if FR Frequence de 1000Hz predefinie sur CCS_OPTIMA. \else 1000Hz predefined scanrate for CCS_OPTIMA. \endif */
   MCHR_SCAN_RATE_CCS_OPTIMA_1000HZ,
   /*! \if FR Frequence de 2000Hz predefinie sur CCS_OPTIMA. \else 2000Hz predefined scanrate for CCS_OPTIMA. \endif */
   MCHR_SCAN_RATE_CCS_OPTIMA_2000HZ,
   /*! \if FR Frequence de 5000Hz predefinie sur CCS_OPTIMA. \else 5000Hz predefined scanrate for CCS_OPTIMA. \endif */
   MCHR_SCAN_RATE_CCS_OPTIMA_5000HZ,
   /*! \if FR Frequence de Max predefinie sur CCS_OPTIMA. \else Max predefined scanrate for CCS_OPTIMA. \endif */
   MCHR_MAX_SCAN_RATE_CCS_OPTIMA
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enSCAN_RATE_LIST_CCS_OPTIMA;
#endif

//RSA : 28/09/2007 : supprime frequence 100 & 300hz
/*! \enum enSCAN_RATE_LIST_CCS_ULTIMA
	\brief
		\if FR Liste des frequences parametrables pour un controleur CCS_ULTIMA.
		\else list of rate identifiers for CCS_ULTIMA.
		\endif
	\warning 
		\if FR Seulement pour coffret CCS_ULTIMA.
		\else Only for CCS_ULTIMA controller.
		\endif
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enSCAN_RATE_LIST_CCS_ULTIMA
{
#else
typedef enum 
{
#endif

	/*! \if FR Frequence libre predefinie sur CCS_ULTIMA. \else Free predefined scanrate for CCS_ULTIMA. \endif */
   MCHR_SCAN_RATE_CCS_ULTIMA_LIBRE,
   	/*! \if FR Frequence de 500Hz predefinie sur CCS_ULTIMA. \else 500Hz predefined scanrate for CCS_ULTIMA. \endif */
   MCHR_SCAN_RATE_CCS_ULTIMA_500HZ,
   	/*! \if FR Frequence de 1000Hz predefinie sur CCS_ULTIMA. \else 1000Hz predefined scanrate for CCS_ULTIMA. \endif */
   MCHR_SCAN_RATE_CCS_ULTIMA_1000HZ,
   	/*! \if FR Frequence de 2000Hz predefinie sur CCS_ULTIMA. \else 2000Hz predefined scanrate for CCS_ULTIMA. \endif */
   MCHR_SCAN_RATE_CCS_ULTIMA_2000HZ,
   	/*! \if FR Frequence de 5000Hz predefinie sur CCS_ULTIMA. \else 5000Hz predefined scanrate for CCS_ULTIMA. \endif */
   MCHR_SCAN_RATE_CCS_ULTIMA_5000HZ,
   	/*! \if FR Frequence de 10000Hz predefinie sur CCS_ULTIMA. \else 10000Hz predefined scanrate for CCS_ULTIMA. \endif */
   MCHR_SCAN_RATE_CCS_ULTIMA_10000HZ,
   	/*! \if FR Frequence de 15625Hz predefinie sur CCS_ULTIMA. \else 15625Hz predefined scanrate for CCS_ULTIMA. \endif */
   MCHR_SCAN_RATE_CCS_ULTIMA_15625HZ,
   	/*! \if FR Frequence de 20000Hz predefinie sur CCS_ULTIMA. \else 20000Hz predefined scanrate for CCS_ULTIMA. \endif */
   MCHR_SCAN_RATE_CCS_ULTIMA_20000HZ,
   	/*! \if FR Frequence de 25000Hz predefinie sur CCS_ULTIMA. \else 25000Hz predefined scanrate for CCS_ULTIMA. \endif */
   MCHR_SCAN_RATE_CCS_ULTIMA_25000HZ,
   	/*! \if FR Frequence de 31250Hz predefinie sur CCS_ULTIMA. \else 31250Hz predefined scanrate for CCS_ULTIMA. \endif */
   MCHR_SCAN_RATE_CCS_ULTIMA_31250HZ,
   	/*! \if FR Frequence Max predefinie sur CCS_ULTIMA. \else Max predefined scanrate for CCS_ULTIMA. \endif */
   MCHR_MAX_SCAN_RATE_CCS_ULTIMA,
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enSCAN_RATE_LIST_CCS_ULTIMA;
#endif


/*! \enum enSCAN_RATE_LIST_CCS_INITIAL
	\brief
		\if FR Liste des frequences parametrables pour un controleur CCS_INITIAL.
		\else list of rate identifiers for CCS_INITIAL.
		\endif
	\warning 
		\if FR Seulement pour coffret CCS_INITIAL.
		\else Only for CCS_INITIAL controller.
		\endif
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enSCAN_RATE_LIST_CCS_INITIAL
{
#else
typedef enum 
{
#endif

	/*! \if FR Frequence de 100Hz predefinie sur CCS_INITIAL. \else 100Hz predefined scanrate for CCS_INITIAL. \endif */
   MCHR_SCAN_RATE_CCS_INITIAL_LIBRE,
   /*! \if FR Frequence de 100Hz predefinie sur CCS_INITIAL. \else 100Hz predefined scanrate for CCS_INITIAL. \endif */
   MCHR_SCAN_RATE_CCS_INITIAL_100HZ,
   /*! \if FR Frequence de 100Hz predefinie sur CCS_INITIAL. \else 100Hz predefined scanrate for CCS_INITIAL. \endif */
   MCHR_SCAN_RATE_CCS_INITIAL_200HZ,
   /*! \if FR Frequence de 100Hz predefinie sur CCS_INITIAL. \else 100Hz predefined scanrate for CCS_INITIAL. \endif */
   MCHR_SCAN_RATE_CCS_INITIAL_400HZ,
   /*! \if FR Frequence de 100Hz predefinie sur CCS_INITIAL. \else 100Hz predefined scanrate for CCS_INITIAL. \endif */
   MCHR_SCAN_RATE_CCS_INITIAL_1000HZ,
   /*! \if FR Frequence de 100Hz predefinie sur CCS_INITIAL. \else 100Hz predefined scanrate for CCS_INITIAL. \endif */
   MCHR_SCAN_RATE_CCS_INITIAL_2000HZ,
   /*! \if FR Frequence de 100Hz predefinie sur CCS_INITIAL. \else 100Hz predefined scanrate for CCS_INITIAL. \endif */
   MCHR_MAX_SCAN_RATE_CCS_INITIAL
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enSCAN_RATE_LIST_CCS_INITIAL;
#endif


/*! \enum enSCAN_RATE_LIST_TRIO
	\brief
		\if FR Liste des frequences parametrables pour un controleur TRIO.
		\else list of rate identifiers for TRIO.
		\endif
	\warning 
		\if FR Seulement pour coffret TRIO.
		\else Only for TRIO controller.
		\endif
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enSCAN_RATE_LIST_TRIO
{
#else
typedef enum 
{
#endif
   /*! \if FR Frequence libre predefinie sur TRIO. \else Free predefined scanrate for TRIO. \endif */
   MCHR_SCAN_RATE_TRIO_FREE, 
   /*! \if FR Frequence de 40Hz predefinie sur TRIO. \else 40Hz predefined scanrate for TRIO. \endif */
   MCHR_SCAN_RATE_TRIO_40HZ,  
   /*! \if FR Frequence de 100Hz predefinie sur TRIO. \else 100Hz predefined scanrate for TRIO. \endif */
   MCHR_SCAN_RATE_TRIO_100HZ,  
   /*! \if FR Frequence de 200Hz predefinie sur TRIO. \else 200Hz predefined scanrate for TRIO. \endif */
   MCHR_SCAN_RATE_TRIO_200HZ,  
   /*! \if FR Frequence de 400Hz predefinie sur TRIO. \else 400Hz predefined scanrate for TRIO. \endif */
   MCHR_SCAN_RATE_TRIO_400HZ,
   /*! \if FR Frequence de 1000Hz predefinie sur TRIO. \else 1000Hz predefined scanrate for TRIO. \endif */
   MCHR_SCAN_RATE_TRIO_1000HZ,
   /*! \if FR Frequence de 2000Hz predefinie sur TRIO. \else 2000Hz predefined scanrate for TRIO. \endif */
   MCHR_SCAN_RATE_TRIO_2000HZ,
   /*! \if FR Frequence Max predefinie sur TRIO. \else Max predefined scanrate for TRIO. \endif */
   MCHR_MAX_SCAN_RATE_TRIO,

#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enSCAN_RATE_LIST_TRIO;
#endif

/*! \enum enSCAN_RATE_LIST_DUO
	\brief
		\if FR Liste des frequences parametrables pour un controleur DUO.
		\else list of rate identifiers for DUO.
		\endif
	\warning 
		\if FR Seulement pour coffret DUO.
		\else Only for DUO/TRIO controller.
		\endif
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enSCAN_RATE_LIST_DUO
{
#else
typedef enum 
{
#endif
   /*! \if FR Frequence libre predefinie sur DUO. \else Free predefined scanrate for DUO. \endif */
   MCHR_SCAN_RATE_DUO_FREE, 
   /*! \if FR Frequence de 40Hz predefinie sur DUO. \else 40Hz predefined scanrate for DUO. \endif */
   MCHR_SCAN_RATE_DUO_40HZ,  
   /*! \if FR Frequence de 100Hz predefinie sur DUO. \else 100Hz predefined scanrate for DUO. \endif */
   MCHR_SCAN_RATE_DUO_100HZ,  
   /*! \if FR Frequence de 200Hz predefinie sur DUO. \else 200Hz predefined scanrate for DUO. \endif */
   MCHR_SCAN_RATE_DUO_200HZ,  
   /*! \if FR Frequence de 400Hz predefinie sur DUO. \else 400Hz predefined scanrate for DUO. \endif */
   MCHR_SCAN_RATE_DUO_400HZ,
   /*! \if FR Frequence de 1000Hz predefinie sur DUO. \else 1000Hz predefined scanrate for DUO. \endif */
   MCHR_SCAN_RATE_DUO_1000HZ,
   /*! \if FR Frequence de 2000Hz predefinie sur DUO. \else 2000Hz predefined scanrate for DUO. \endif */
   MCHR_SCAN_RATE_DUO_2000HZ,
   /*! \if FR Frequence Max predefinie sur DUO. \else Max predefined scanrate for DUO. \endif */
   MCHR_MAX_SCAN_RATE_DUO,

#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enSCAN_RATE_LIST_DUO;
#endif

/*! \enum enSCAN_RATE_LIST_RUBY
	\brief
		\if FR Liste des frequences parametrables pour un controleur RUBY.
		\else list of rate identifiers for RUBY.
		\endif
	\warning 
		\if FR Seulement pour coffret RUBY.
		\else Only for RUBY controller.
		\endif
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enSCAN_RATE_LIST_RUBY
{
#else
typedef enum 
{
#endif
	/*! \if FR Frequence libre predefinie sur RUBY. \else Free predefined scanrate for RUBY. \endif */
   MCHR_SCAN_RATE_RUBY_FREE,
   /*! \if FR Frequence de 4Hz predefinie sur RUBY. \else 4Hz predefined scanrate for RUBY. \endif */
   MCHR_SCAN_RATE_RUBY_4HZ,
   /*! \if FR Frequence de 10Hz predefinie sur RUBY. \else 10Hz predefined scanrate for RUBY. \endif */
   MCHR_SCAN_RATE_RUBY_10HZ,
   /*! \if FR Frequence de 20Hz predefinie sur RUBY. \else 20Hz predefined scanrate for RUBY. \endif */
   MCHR_SCAN_RATE_RUBY_20HZ,
   /*! \if FR Frequence de 40Hz predefinie sur RUBY. \else 40Hz predefined scanrate for RUBY. \endif */
   MCHR_SCAN_RATE_RUBY_40HZ,  
   /*! \if FR Frequence de 100Hz predefinie sur RUBY. \else 100Hz predefined scanrate for RUBY. \endif */
   MCHR_SCAN_RATE_RUBY_100HZ,  
   /*! \if FR Frequence de 200Hz predefinie sur RUBY. \else 200Hz predefined scanrate for RUBY. \endif */
   MCHR_SCAN_RATE_RUBY_200HZ,  
   /*! \if FR Frequence de 400Hz predefinie sur RUBY. \else 400Hz predefined scanrate for RUBY. \endif */
   MCHR_SCAN_RATE_RUBY_400HZ,
   /*! \if FR Frequence de 1000Hz predefinie sur RUBY. \else 1000Hz predefined scanrate for RUBY. \endif */
   MCHR_SCAN_RATE_RUBY_1000HZ,
   /*! \if FR Frequence de 2000Hz predefinie sur RUBY. \else 2000Hz predefined scanrate for RUBY. \endif */
   MCHR_SCAN_RATE_RUBY_2000HZ,
   /*! \if FR Frequence Max predefinie sur RUBY. \else Max predefined scanrate for RUBY. \endif */
   MCHR_MAX_SCAN_RATE_RUBY,
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enSCAN_RATE_LIST_RUBY;
#endif


/*! \enum enCPUType
	\brief
		\if FR Type de CPU embarqu?
		\else Embedded CPU type.
		\endif
	\warning 
		\if FR Utilisation par STIL SA uniquement.
		\else STIL SA use only.
		\endif
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enCPUType
{
#else
typedef enum 
{
#endif
	CPU_JREX_PM_1G,
	CPU_JREX_PM_1_8G,
	CPU_DG41MJ_L_3G,
	CPU_DG41AN_LUF_3G,
	CPU_DG41AN_WIN_3G,
	CPU_DG41AN_L_3G,
	CPU_DG41AN_LRUBY_3G,
	CPU_DH61DL_L_3G,
	CPU_DH61DL_LRUBY_3G,
	NBR_MAX_CPU,
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enCPUType;
#endif
   

/*! \def MCHR_MAX_SCAN_RATE
	\brief
		\if FR Frequence d'acquisition maximum.
		\else Max Scan Frequency Rate.
		\endif
*/
#define   MCHR_MAX_SCAN_RATE   MCHR_MAX_SCAN_RATE_CHRXE


/*! \enum enMeasureMode
	\brief
		\if FR Modes de mesure. 
		\else Measuring modes. 
		\endif
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enMeasureMode
{
#else
typedef enum 
{
#endif
	/*! \if FR Mode mesure de distance en confocal chromatique. \else Chromatic Confocal Distance measuring mode. \endif */
	MCHR_DISTANCE_MODE = 0,			
	/*! \if FR Mode mesure d'epaisseur en confocal chromatique. \else Chromatic Confocal Thickness measuring mode. \endif */
	MCHR_THICKNESS_MODE = 1,		
	/*! \if FR Mode mesure d'epaisseur en interferometrie lumiere blanche (ILB). \warning Seulement pour STIL-DUO \else SAWLI Thickness measuring mode. \warning Only for STIL-DUO \endif */
	MCHR_SAWLI_THICKNESS_MODE = 2,	
	/*! \if FR Mode mesure de distance en interferometrie lumiere blanche (ILB). \warning Seulement pour STIL-DUO \else SAWLI Distance measuring mode. \warning Only for STIL-DUO \endif */
	MCHR_SAWLI_DISTANCE_MODE = 3,
	/*! \if FR Mesure spectrometrique dans le repere XYZ. \warning Seulement pour NCS-RUBY \else Spectrometric mesurement using XYZ scaling. \warning Only for NCS-RUBY \endif */
	MCHR_MESURE_XYZ = 4,		
	/*! \if FR Mesure spectrometrique dans le repere Yxy. \warning Seulement pour NCS-RUBY \else Spectrometric mesurement using yxy scaling. \warning Only for NCS-RUBY \endif */
	MCHR_MESURE_Yxy = 5,
	/*! \if FR Mesure spectrometrique dans le repere RGB. \warning Seulement pour NCS-RUBY \else Spectrometric mesurement using RGB scaling. \warning Only for NCS-RUBY \endif */
	MCHR_MESURE_RGB = 6,
	/*! \if FR Mesure spectrometrique dans le repere Lab. \warning Seulement pour NCS-RUBY \else Spectrometric mesurement using Lab scaling. \warning Only for NCS-RUBY \endif */
	MCHR_MESURE_Lab = 7,
	/*! \if FR Mesure spectrometrique dans le repere Luv. \warning Seulement pour NCS-RUBY \else Spectrometric mesurement using Luv scaling. \warning Only for NCS-RUBY \endif */
	MCHR_MESURE_Luv = 8,
	/*! \if FR Mesure spectrometrique dans le repere LChab. \warning Seulement pour NCS-RUBY \else Spectrometric mesurement using LChab scaling. \warning Only for NCS-RUBY \endif */
	MCHR_MESURE_LCh_ab = 9,
	/*! \if FR Mesure spectrometrique dans le repere W. \warning Seulement pour NCS-RUBY \else Spectrometric mesurement using W scaling. \warning Only for NCS-RUBY \endif */
	MCHR_MESURE_W = 10,
	/*! \if FR Mode mesure de distance en confocal chromatique. \else Chromatic Confocal Distance measuring mode. \endif */
	MCHR_DISTANCE_AND_SPECTRUM_MODE = 8,			
	/*! \if FR Mode mesure d'epaisseur en confocal chromatique. \else Chromatic Confocal Thickness measuring mode. \endif */
	MCHR_THICKNESS_AND_SPECTRUM_MODE = 9,		
	/*! \if FR Limite du nombre de mode mesure. \else Limit number of measuring modes. \endif */
	MCHR_MAX_MODE = 11

#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enMeasureMode;
#endif

/*! \enum enDigitalOutputFormat
	\brief
		\if FR 
			Type de sortie digitale. 
		\else 
			Digital Output Format. 
		\endif
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enDigitalOutputFormat
{
#else
typedef enum 
{
#endif
	/*! \if FR Donnees formatees en ASCII. \else ASCII data format. \endif */
   MCHR_ASCII,
   /*! \if FR Donnees formatees en binaire. \else Binary data format. \endif */
   MCHR_BINARY,
   /*! \if FR Donnees transférée pas paquet. \warning Seulement pour STIL-DUO et CHR-450 \else Data transfered using packets. \warning Only for STIL-DUO and CHR-450 \endif */
	MCHR_PACKET,
   /*! \if FR Limite du nombre de type de format de donnees. \else Limit number of data types. \endif */
   MCHR_MAX_FORMAT
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enDigitalOutputFormat;
#endif


/*! \enum enDigitalOutputChannel
	\brief
		\if FR 
			Type de sortie digitale. 
		\else 
			Digital Output Channel. 
		\endif
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enDigitalOutputChannel
{
#else
typedef enum 
{
#endif
	/*! \if FR Donnees non transmises. \else Data not transmitted. \endif */
	MCHR_NOT_TRANSMIT,
	/*! \if FR Donnees transmises sur le port serie. \else Data transmitted via serial port. \endif */
	MCHR_MAIN_SERIAL,
	/*! \if FR Donnees transmises sur le port serie auxiliaire. \else Data transmitted via auxiliary serial port. \endif */
	MCHR_AUX_SERIAL,
	/*! \if FR Donnees transmises sur le port Ethernet. \warning Seulement pour STIL-DUO et CHR-450 \else Data transmitted via ethernet port. \warning Only for STIL-DUO and CHR-450 \endif */
	MCHR_ETHERNET,
	/*! \if FR Donnees transmises sur le port USB. \warning Seulement pour CCS et STIL INITIAL \else Data transmitted via USB port. \warning Only for CCS and STIL INITIAL \endif */
	MCHR_USB=3,
	/*! \if FR Enumeration maximale du type de donnees transmises. \else Maximum enum for transmitted data types. \endif */
	MCHR_MAX_OUTPUT_CHANNEL
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enDigitalOutputChannel;
#endif


/*! \enum enTriggerType
	\brief
		\if FR 
			Type de Trigger. 
		\else 
			Trigger type.
		\endif
	\warning 
		\if FR Les types de Trigger disponibles dependent du type de controleur.
		\else available trigger types depend on controller type.
		\endif
		
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enTriggerType
{
#else
typedef enum
{
#endif
	MCHR_TYPE_NONE,
	/*! \brief 
				\if FR  : Commence quand l'impulsion Trig est reçu, sans r?armer
				\else : Start when a Trig pulse is received, do not re-arm
				\endif
	*/ 
	MCHR_TYPE_TRG,
	/*! \brief 
				\if FR  : Débute ou stop la mesure dès la réception de 3 impulsions Trig et r?arme
				\else : Start/Stop measurement upon successive Trig pulses,  and re-arm
				\endif
	*/
	MCHR_TYPE_TRS,
	/*! \brief 
				\if FR  : 
				\else : Send a burst of N points when a Trig pulse is received, and re-arm
				\endif
	*/
	MCHR_TYPE_TRE,
	/*! \brief 
				\if FR  : 
				\else : Start/Stop measurement upon Trig-signal state, and re-arm
				\endif
	*/
	MCHR_TYPE_TRN,
	MCHR_MAX_TYPE
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enTriggerType;
#endif


/*! \enum enAcqEventType
	\brief
		\if FR 
			Acquisition du type d'evenement. 
		\else 
			Acquisition Event Type.
		\endif		
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enAcqEventType
{
#else
typedef enum 
{
#endif
	/*! \if FR Correspond ?l'evenement d'acquisition du point de la structure. \else Corresponds to EventAcquire_n_Points of this structure. \endif */
	MCHR_ONE_STEP_EVENT,
	/*! \if FR Correspond . \else Corresponds to EventEndBuffer of the acquisition parameter structure.  \endif */
	MCHR_BUFFER_EVENT,
   /*! \if FR Correspond. \else Corresponds to EventEndMeasurement of this structure. \endif */
	MCHR_END_MEASUREMENT,
	MCHR_MAX_EVENT
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enAcqEventType;
#endif

// MCHR_LOOKUP_TABLE, Added january 2th 2008
/*! \enum enSignalType
	\brief
		\if FR 
			Types de signaux. 
		\else 
			Signals types.
		\endif		
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enSignalType
{
#else
typedef enum 
{
#endif
	/*! \if FR Correspond. \else NO SIGNAL. \endif */
   MCHR_NOT_SIGNAL,
      /*! \if FR Correspond. \else RAW SIGNAL \endif */
   MCHR_RAW_SIGNAL,
      /*! \if FR Correspond. \else PRETREATED SIGNAL. \endif */
   MCHR_PRETREATED_SIGNAL,
   /*! \if FR Correspond. \else DARK SIGNAL \endif */
   MCHR_DARK_SIGNAL,
   /*! \if FR Correspond. \else WHITE REFERENCE SIGNAL. \endif */
   MCHR_WHITEREF_SIGNAL,
   /*! \if FR Correspond. \else LOOKUP TABLE OF CALIBRATION. \endif */
   MCHR_LOOKUP_TABLE,
   /*! \if FR Correspond. \else REFRACTIVE INDEX \endif */
   MCHR_REFRACTIVE_INDEX,
   /*! \if FR Correspond. \else THE OPTICAL DARK SIGNAL \endif */
   MCHR_OPTICAL_DARK,
   /*! \if FR Correspond. \else THE ELECTONIC DARK SIGNAL \endif */
   MCHR_ELECTRONIC_DARK,
   /*! \if FR Correspond. \else THE NORMALISATION WHITE SIGNAL. \endif */
   MCHR_NORMALIZATION_WHITE,
	/*! \if FR Correspond. \else THE SIGNAL OF REFERENCE. \endif */
   MCHR_REFERENCE_SIGNAL,
   MCHR_MAX_SIGNAL
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enSignalType;
#endif


/*! \enum enPeakSelectionMode
	\brief
		\if FR 
			Mode de selection de pic. 
		\else 
			Peak selection mode.
		\endif		
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enPeakSelectionMode
{
#else
typedef enum 
{
#endif
   MCHR_HIGH_PEAK,
   MCHR_FIRST_PEAK,
   MCHR_LAST_PEAK,
	MCHR_MAX_PEAK_MODE
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enPeakSelectionMode;
#endif



/*! \enum enAutoDarkMode
	\brief
		\if FR 
			Mode de Dark Automatique. 
		\else 
			Auto Dark mode.
		\endif		
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enAutoDarkMode
{
#else
typedef enum 
{
#endif
   MCHR_MANUAL_DARK,
   MCHR_AUTO_DARK,
	MCHR_MAX_AUTO_DARK_MODE
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enAutoDarkMode;
#endif

/*! \enum enLedType
	\brief
		\if FR 
			Type de Led. 
		\else 
			Led type.
		\endif		
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enLedType
{
#else
typedef enum 
{
#endif
	//Values for CHR devices (LPA function used)
	//0
	MCHR_CCS_LED_NO_SOURCE,		
	//1
	MCHR_CCS_LED_INNER,			
	//2
	MCHR_CCS_HALOGEN,			
	//3
	MCHR_CCS_LED_XENON,			
	//Values for CCS devices (SRC function used)
	//0
	MCHR_LED_OUTER=0,			
	//1
	MCHR_LED_INNER,				
   
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enLedType;
#endif


/*! \enum enLevelEdgeFlag
	\brief
		\if FR 
			Definition du niveau du Signal et du front. 
		\else 
			Level or Edge definition.
		\endif		
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enLevelEdgeFlag
{
#else
typedef enum 
{
#endif
   MCHR_HIGH_LEVEL = 0,
   MCHR_LOW_LEVEL,
   MCHR_RISING_EDGE = 0,
   MCHR_FALLING_EDGE,
	MCHR_MAX_LEVEL_EDGE_FLAG
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enLevelEdgeFlag;
#endif



/*! \enum enSecondPeakHandling
	\brief
		\if FR 
			Second pic. 
		\else 
			Second peak handling.
		\endif		
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enSecondPeakHandling
{
#else
typedef enum 
{
#endif
   MCHR_SECOND_PEAK_NULL,
   MCHR_SECOND_PEAK_IS_PEAK_ONE
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enSecondPeakHandling;
#endif



/*! \enum enLanguage
	\brief
		\if FR 
			Determine le nombre max de langages et les identifie  
		\else 
			Max Number langages et identification.
		\endif		
*/

#if defined(_cplusplus) || defined(__cplusplus)
enum enLanguage
{
#else
typedef enum 
{
#endif
	ENGLISH,
	FRENCH,
	NBR_MAX_LANGUAGE
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enLanguage;
#endif

/*! \enum enObservateur
	\brief
		\if FR 
			\brief Observateur standart disponible pour 1931 (2?, 1964 (10?	 
		\else 
			\brief Standart observator available to 1931 (2?, 1964 (10?	
		\endif		
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enObservateur
{
#else
typedef enum 
{
#endif
	/*! \brief CIE1931 (2?, */
   OBS_CIE1931,
   /*! \brief CIE1964 (10?. */
   OBS_CIE1964,
   NBR_MAX_OBSERVATEUR
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enObservateur;
#endif

/*! \enum enIlluminant
	\brief
		\if FR 
			\brief Illuminant standart (CIE) disponible pour le calcul de coordonnées colorimétriques A B C D F.

		\else 
			\brief Standart Illinant (CIE) avaible to calculate the colorimetry Coordinate A B C D.

		\endif		
*/

#if defined(_cplusplus) || defined(__cplusplus)
enum enIlluminant
{
#else
typedef enum 
{
#endif
   ILLUM_A,
   ILLUM_D65,
   ILLUM_C,
   ILLUM_D50,
   ILLUM_D55,
   ILLUM_D75,
   ILLUM_FL01,
   ILLUM_FL02,
   ILLUM_FL03,
   ILLUM_FL04,
   ILLUM_FL05,
   ILLUM_FL06,
   ILLUM_FL07,
   ILLUM_FL08,
   ILLUM_FL09,
   ILLUM_FL10,
   ILLUM_FL11,
   ILLUM_FL12,
   ILLUM_HP1,
   ILLUM_HP2,
   ILLUM_HP3,
   ILLUM_HP4,
   ILLUM_HP5,
   NBR_MAX_ILLUMINANT
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enIlluminant;
#endif

/*! \enum enIndiceCouleur
	\brief
		\if FR 
			\brief Indice de couleur
		\else 
			\brief Indice Of the color.

*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enIndiceCouleur
{
#else
typedef enum 
{
#endif
   IND_COLOR_E2000,
   IND_COLOR_Eab,
   IND_COLOR_CMC,
   NBR_IND_COLOR
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enIndiceCouleur;
#endif

/*! \enum enIndiceSpectre
	\brief
		\if FR 
			Les differents indice de spectre 
		\else 
			The differrent spectral index
		\endif		
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enIndiceSpectre
{
#else
typedef enum 
{
#endif
   IND_SPECTRE_RMS,
   IND_SPECTRE_GFC,
   NBR_IND_SPECTRE
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enIndiceSpectre;
#endif

/*! \enum enTypeConformite
	\brief
		\if FR 
			\brief Definit le type de comparaison entre couleur ? et couleur rererence en mode spectral ou mode couleur.
		\else 
			\Brief Define the comparison type between ? color and referent color spectral mode or color mode.

		\endif		
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enTypeConformite
{
#else
typedef enum 
{
#endif
   CONFORMITE_DESACTIVE,
   CONFORMITE_COULEUR,
   CONFORMITE_SPECTRE,
   NBR_MAX_TYPE_CONFORMITE
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enTypeConformite;
#endif

/*! \enum enTypeEtendueSpectrale
	\brief
		\if FR 
			 Les types de spectres étendus
		\else 
			 The types of etendue spectral
		\endif		
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enTypeEtendueSpectrale
{
#else
typedef enum 
{
#endif
   ETENDUE_ISO,
   ETENDUE_STD,
   ETENDUE_COURT,
   ETENDUE_OPTIMISE,
   NBR_MAX_ETENDUE_SPECTRALE
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enTypeEtendueSpectrale;
#endif

/*! \enum enTypeAcqFreqBlanc
	\brief
		\if FR 
			\brief Definit le type d'acquisition pour le calibrage du blanc, en mode automatique ou en mode manuel.

		\else 
			\brief define the acquisition type to calibrate the white in automatic mode or manual mode
		\endif		
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enTypeAcqFreqBlanc
{
#else
typedef enum 
{
#endif
   FREQ_BLANC_COURANTE,
   FREQ_BLANC_AUTO,
   NBR_MAX_TYPE_FREQ_BLANC
#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enTypeAcqFreqBlanc;
#endif

/*! \enum enRealTimeSignalType
	\brief
		\if FR 
			\brief Selection du type de spectre envoy?en temps reel 
			\arg \c Pas de Spectre
			\arg \c Spectre Brut
			\arg \c Spectre pre-traiter

		\else 
			\brief Selection of spectrum type send in real time. 
			\arg \c No spectrum
			\arg \c Spectrum raw
			\arg \c Spectrum pre-treated

		\endif		
*/
#if defined(_cplusplus) || defined(__cplusplus)
enum enRealTimeSignalType
{
#else
typedef enum 
{
#endif
   REALTIME_NO_SIGNAL,
   REALTIME_RAW_SIGNAL,
   REALTIME_PRETRAITED_SIGNAL,
   NBR_MAX_RT_SIGNAL_TYPE

#if defined(_cplusplus) || defined(__cplusplus)
};
#else
} enRealTimeSignalType;
#endif





/*
Structure de paramètres d'acquisition
Acquisition parameters Structure 
*/
/*! Acquisition parameters Structure */
typedef struct _AcqParam
{
	/*
	Nombre de points ?acquerir. Si la valeur vaut 0 l'acquisition se fera en continu
	Number of points to acquire. If this parameter is set to 0, acquisition will be continuous.
	*/
	/*! 
	\brief
		\if FR 
			
		\else 
			Number of point to measure. If this parameters is set to 0, measurement will be continuous (i.e. will last forever or until stopped by the user) and no event " EventEndMeasurement" will be generated
		\endif		
	*/
   DWORD NumberOfPoints;

	/*
	Indique si la tâche d'acquisition doit initialiser le CHR-150 en attente de trigger ou si la tâche  d'acquisition doit demarrer immediatement.
	Trigger flag. This parameter indicates if the CHR sould wait a trig signal before starting, or not.
	*/
	/*! 
	\brief
		\if FR 
			
		\else 
			This parameter activates or deactivates Trigger mode (if Trigger mode is active acquisition will wait for a "Trigger in" signal to start, otherwise acquisition starts immediately). 
		\endif		
	*/
   BOOL TriggerFlag;
	/*!
	\brief
		\if FR 
			
		\else 
			This parameter is significant only if TriggerFlag is set to “TRUE?
		\endif		
	*/
	/*
	Indique le type de trigger utilise
	Trigger Type. This parameter indicates the trigger mode (TRG /TRE/TRN/ TRS)
	*/
	enum enTriggerType TriggerType;

	/*
	Indique le niveau ou le type de front actif
	LevelEdgeFlag: This parameter indicates the active edge
	*/
	/*!
	\brief
		\if FR 
			
		\else 
			This parameter is significant only if TriggerFlag is set to “TRUE?and only for CCS and STIL-INITIAL sensors.
			It indicates which edge of the Sync-In signal pulse is active (for TRG, TRE, and TRS) or which state of this signal is active (for TRN).
			Authorized values are: MCHR_FALLING_EDGE, MCHR_RISING_EDGE, MCHR_LOW_LEVEL, MCHR_HIGH_LEVEL.
		\endif		
	*/
	enLevelEdgeFlag  HighLevelOrRisingEdgeActivated;

   /* 
   Nombre d'image ?acquerir en mode TRE
   Number of points for TRE mode:  This parameter indicates the number of points to acquire after each Sync-in pulse
   */
	/*!
	\brief
		\if FR 
			
		\else 
			This parameter is significant only if TriggerFlag is set to “TRUE?and if TriggerType is set to MCHR_TYPE_TRE.
			It determines the number of points that are latched after each TRE pulse.
			For CHR 150 sensor the only valid value is 1. 
			FOR CCS sensors, STIL-DUO and STIL-INITIAL sensors valid values are 1 to 999.
		\endif		
	*/
   DWORD NumberPointsTRE;
      
	/*
	Indique le nombre de buffers pour les differents types de donnees. Ce paramètre doit être superieur ?0. 
   Number of buffers per data item. This parameter should be greater than 0
	*/
   /*!
	\brief
		\if FR 
			
		\else 
			The number of buffers per data type for receiving the measured data (Should be greater than or equal to 1).
		\endif		
	*/
   DWORD NumberOfBuffers;

	/*
	Nombre de point max contenus dans les buffers de reception des donnees mesurees
    Max number of points (data) per buffer
	*/
   /*!
	\brief
		\if FR 
			
		\else 
			Size of the buffers for receiving the measured data (in words: one word=data for one measured point).
		\endif		
	*/
	DWORD BufferLength;

	/*
	Definie le nombre de points ?acquerir avant de signaler un evenement.
	This parameters gives the number of data to acquire before signaling an event
	*/
	/*!
	\brief
		\if FR 
			
		\else 
			This parameter is significant only if the EventAcquire_n_Points is activated.
			It determines the number of points to be measured before creating the “EventAcquire_n_Points?event.
			This parameter should be an integer divider of BufferLength (e.g. if BufferLength=10,
			The authorized values of NumberOfPointsBeforeSignal are 1, 2, 5 and 10). In addition,
			If this parameter is set to 0, no event “EventAcquire_n_Points" will be generated.
		\endif		
	*/
	DWORD NumberOfPointsBeforeSignal;

	/*
	evènement signalant l'acquisition de NumberOfPointBeforeSignal 
	Event indicating that "NumberOfPointBeforeSignal " points have been acquired
	*/
	/*!
	\brief
		\if FR 
			
		\else 
			Event that indicates that NumberOfPointsBeforeSignal points have been acquired (set by the DLL).
		\endif		
	*/
	HANDLE EventAcquire_n_Points;

	/*
	evènement signalant la fin de remplissage d'un buffer de mesures. 
	Event indicating that one or several buffer is/are full.
	*/
	/*!
	\brief
		\if FR 
			
		\else 
			Event that indicates that an acquisition buffer is full (set by the DLL).
		\endif		
	*/
	HANDLE EventEndBuffer;

   /*
	evènement signalant la fin de l'acquisition des NumberOfPoints points de mesures demandes. Si NumberOfPoints vaut 0, cet evenement n'aura jamais lieu.
	Event indicating measurement end ("NumberOfPoint" points have been acquired)
	*/
	/*!
	\brief
		\if FR 
			
		\else 
			Event that indicates that NumberOfPoints points have been acquired (set by the DLL).
			Note: if NumberOfPoints equals 0, this event will never occur.
		\endif		
	*/
	HANDLE EventEndMeasurement;

   /*
	 Evènement permettant de stopper l'acquisition avant la fin
    User-set event indicating that acquisition should be stopped (aborted)
	*/
	/*!
	\brief
		\if FR 
			
		\else 
			Obsolete, kept for compatibility with earlier versions.
		\endif		
	*/
   HANDLE EventEndAcquire;

   /*
	 Evenement permettant de signaler le debut effectif de l'acquisition
    Event indicationg the actual start of acquisition upon reception of trigger signal
	*/
   /*!
	\brief
		\if FR 
			
		\else 
			Event that indicates that acquisition has actually been started (set by the DLL).
			This event may be used for controlling triggered acquisition.
		\endif		
	*/
   HANDLE EventStartingAcquisition;

/*!
	\brief
		\if FR 
			\brief liste des types : tyAcqParam
			\arg \c DWORD 				NumberOfPoints
			\arg \c BOOL 				TriggerFlag
			\arg \c enTriggerType 		TriggerType
			\arg \c enLevelEdgeFlag		HighLevelOrRisingEdgeActivated
			\arg \c DWORD	 			NumberPointsTRE
			\arg \c WORD	 			NumberOfBuffers
			\arg \c	DWORD 				BufferLength
			\arg \c	DWORD 				NumberOfPointsBeforeSignal
			\arg \c	HANDLE	 			EventAcquire_n_Points
			\arg \c	HANDLE	 			EventEndBuffer
			\arg \c HANDLE	 			EventEndMeasurements
			\arg \c HANDLE 				EventEndAcquire
			\arg \c HANDLE 				EventStartingAcquisition
		\else 
			\brief  Type name: tyAcqParam 
			\arg \c DWORD 				NumberOfPoints
			\arg \c BOOL 				TriggerFlag
			\arg \c enTriggerType 		TriggerType
			\arg \c enLevelEdgeFlag		HighLevelOrRisingEdgeActivated
			\arg \c DWORD	 			NumberPointsTRE
			\arg \c WORD	 			NumberOfBuffers
			\arg \c	DWORD 				BufferLength
			\arg \c	DWORD 				NumberOfPointsBeforeSignal
			\arg \c	HANDLE	 			EventAcquire_n_Points
			\arg \c	HANDLE	 			EventEndBuffer
			\arg \c HANDLE	 			EventEndMeasurements
			\arg \c HANDLE 				EventEndAcquire
			\arg \c HANDLE 				EventStartingAcquisition
		\endif		
	*/

}  MCHR_tyAcqParam;


//#define EventEndMeasurement EventEndMeasurementTest
   /* 
   Definition des types pour les fonctions callback
   Type definition for callback functions
   */

   /*! Sensor response to know the reception of sent file */ 
typedef void (* CALLBACK_SEND_FILE)(BOOL FlagInit, long Param1, long Param2) ;

	/*! Sensor response to know the status of connection */ 
typedef void (* CALLBACK_STATUS_CONNECTION)(long Param1, long Param2) ;
 
/*!  Structure of DATA */
typedef struct _MCHR_FILE_DATA_ {
	/*! Destination Directory of sent file */ 
	BOOL bIsDirectory; 
	/*! Size of sent file */
	DWORD nFileSize;
	/*! Name of sent file */
	char cFileName[MAX_PATH];
	/*! Creation time of sent file */
	long ftCreationTime;
	/*! Name of sent file */
	WCHAR cWideFileName[MAX_PATH];
} MCHR_FILE_DATA,  *PMCHR_FILE_DATA;

/*!  Structure of DATA */
typedef struct _MCHR_FILE_DATA_EX_ {
	/*! Destination Directory of sent file */ 
	BOOL bIsDirectory; 
	/*! Size of sent file */
	DWORD nFileSize;
	/*! Name of sent file */
	char cFileName[MAX_PATH];
	/*! Creation time of sent file */
	long ftCreationTime;
} MCHR_FILE_DATA_EX,  *PMCHR_FILE_DATA_EX;

/*! Structure of refractive information file */ 
typedef struct _MCHR_REFRACTIVE_FILE_INFO_ {
	/*! Description BY CHARACTERS*/
	char szDescription[MAX_PATH];
	/*! The description by UNICODE*/
	WCHAR  szDescriptionWideChar[MAX_PATH];
	/*! Min value of the refractive file */
	float fMin;
	/*! Max value of the refractive file */
	float fMax;
	/*! Average value of the refractive file */
	float fAvg;
} REFRACTIVE_FILE_INFO,*PREFRACTIVE_FILE_INFO;


#if defined(_cplusplus) || defined(__cplusplus)
}
#endif /* _cplusplus */
#endif