

//COLORIMETRY FUNCTIONS

/*
Acquisition functions
Configure the device in the acquisition mode (XYZ,RGB) and start acquiring data
Any float array parameter is optional and can be set to NULL 

======================================
=	Acquisition functions parameters =
======================================
SensorID			: device ID
Parameters			: Acquire parameter

pArrayColorDiff		: ???
pArraySpectralDiff	: ???
pArrayConformity	: ???
pArrayCounter		: This array will be filled with an incremented value ranging from 0 to 1200

Parameters 3,4 and 5 will be filled according to the mode (XYZ,Yxy,RGB...)

Mode description :
XYZ : ???
Yxy : ???
RGB : ???
Lab : ???
Luv : ???
Lch_ab : ???
W	: ???

*/

/*!
	\fn short MCHR_GetXYZ (MCHR_ID  SensorID,MCHR_tyAcqParam Parameters, PFLOAT *pArrayDataX,PFLOAT*pArrayDataY,PFLOAT*pArrayDataZ,PFLOAT*pArrayColorDiff,PFLOAT*pArraySpectralDiff,PFLOAT*pArrayConformity,PFLOAT*pArrayCounter);
	\if FR
		\brief Récupère les données colorimétriques CIEXYZ. 
	\else
		\brief Get the colorometric data CIEXYZ.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID			: ID du coffret.
			\param [out] MCHR_tyAcqParam Parameters : 
			\param [out] PFLOAT*pArrayDataX			: Data X
			\param [out] PFLOAT*pArrayDataY 		: Data Y
			\param [out] PFLOAT*pArrayDataZ			: Data Z
			\param [out] PFLOAT*pArrayColorDiff     : Method to calculate the difference of the color
			\param [out] PFLOAT*pArraySpectralDiff	: Method to calculate the difference of spectral
			\param [out] PFLOAT*pArrayConformity	: Tolerance to eliminate the sample no accordance.
			\param [out] PFLOAT*pArrayCounter		: Count the number of acquisitions
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID			: ID of the device.
			\param [out] MCHR_tyAcqParam Parameters : 
			\param [out] PFLOAT*pArrayDataX			: Data X
			\param [out] PFLOAT*pArrayDataY 		: Data Y
			\param [out] PFLOAT*pArrayDataZ			: Data Z
			\param [out] PFLOAT*pArrayColorDiff     : Method to calculate the difference of the color
			\param [out] PFLOAT*pArraySpectralDiff	: Method to calculate the difference of spectral
			\param [out] PFLOAT*pArrayConformity	: Tolerance to eliminate the sample no accordance.
			\param [out] PFLOAT*pArrayCounter		: Count the number of acquisitions
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetXYZ (MCHR_ID  SensorID,MCHR_tyAcqParam Parameters, PFLOAT *pArrayDataX,PFLOAT*pArrayDataY,PFLOAT*pArrayDataZ,PFLOAT*pArrayColorDiff,PFLOAT*pArraySpectralDiff,PFLOAT*pArrayConformity,PFLOAT*pArrayCounter);

/*!
	\fn short MCHR_GetYxy (MCHR_ID  SensorID,MCHR_tyAcqParam Parameters, PFLOAT *pArrayDataY,PFLOAT*pArrayDatax,PFLOAT*pArrayDatay,PFLOAT*pArrayColorDiff,PFLOAT*pArraySpectralDiff,PFLOAT*pArrayConformity,PFLOAT*pArrayCounter);
	\if FR
		\brief Récupère les données colorimétriques CIEYxy. 
	\else
		\brief Get the colorometric data CIEYxy.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID			: ID du coffret.
			\param [out] MCHR_tyAcqParam Parameters : 
			\param [out] PFLOAT*pArrayDataY			: Data Y
			\param [out] PFLOAT*pArrayDatax			: Data x
			\param [out] PFLOAT*pArrayDatay			: Data y
			\param [out] PFLOAT*pArrayColorDiff     : Method to calculate the difference of the color
			\param [out] PFLOAT*pArraySpectralDiff	: Method to calculate the difference of spectral
			\param [out] PFLOAT*pArrayConformity	: Tolerance to eliminate the sample no accordance.
			\param [out] PFLOAT*pArrayCounter		: Count the number of acquisitions
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID			: ID of the device.
			\param [out] MCHR_tyAcqParam Parameters : 
			\param [out] PFLOAT*pArrayDataY			: Data Y
			\param [out] PFLOAT*pArrayDatax			: Data x
			\param [out] PFLOAT*pArrayDatay			: Data y
			\param [out] PFLOAT*pArrayColorDiff     : Method to calculate the difference of the color
			\param [out] PFLOAT*pArraySpectralDiff	: Method to calculate the difference of spectral
			\param [out] PFLOAT*pArrayConformity	: Tolerance to eliminate the sample no accordance.
			\param [out] PFLOAT*pArrayCounter		: Count the number of acquisitions
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetYxy (MCHR_ID  SensorID,MCHR_tyAcqParam Parameters, PFLOAT *pArrayDataY,PFLOAT*pArrayDataX,PFLOAT*pArrayDatay,PFLOAT*pArrayColorDiff,PFLOAT*pArraySpectralDiff,PFLOAT*pArrayConformity,PFLOAT*pArrayCounter);

/*!
	\fn short MCHR_GetRGB (MCHR_ID  SensorID,MCHR_tyAcqParam Parameters, PFLOAT *pArrayDataR,PFLOAT*pArrayDataG,PFLOAT*pArrayDataB,PFLOAT*pArrayColorDiff,PFLOAT*pArraySpectralDiff,PFLOAT*pArrayConformity,PFLOAT*pArrayCounter);
	\if FR
		\brief Récupère les données colorimétriques sRVB. 
	\else
		\brief Get the colorometric data sRVB.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID			: ID du coffret.
			\param [out] MCHR_tyAcqParam Parameters : 
			\param [out] PFLOAT*pArrayDataR			: Data R
			\param [out] PFLOAT*pArrayDataG			: Data V
			\param [out] PFLOAT*pArrayDataB  		: Data B
			\param [out] PFLOAT*pArrayColorDiff     : Method to calculate the difference of the color
			\param [out] PFLOAT*pArraySpectralDiff	: Method to calculate the difference of spectral
			\param [out] PFLOAT*pArrayConformity	: Tolerance to eliminate the sample no accordance.
			\param [out] PFLOAT*pArrayCounter		: Count the number of acquisitions
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID			: ID of the device.
			\param [out] MCHR_tyAcqParam Parameters : 
			\param [out] PFLOAT*pArrayDataR			: Data R
			\param [out] PFLOAT*pArrayDataG			: Data V
			\param [out] PFLOAT*pArrayDataB  		: Data B
			\param [out] PFLOAT*pArrayColorDiff     : Method to calculate the difference of the color
			\param [out] PFLOAT*pArraySpectralDiff	: Method to calculate the difference of spectral
			\param [out] PFLOAT*pArrayConformity	: Tolerance to eliminate the sample no accordance.
			\param [out] PFLOAT*pArrayCounter		: Count the number of acquisitions
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetRGB (MCHR_ID  SensorID,MCHR_tyAcqParam Parameters, PFLOAT *pArrayDataR,PFLOAT*pArrayDataG,PFLOAT*pArrayDataB,PFLOAT*pArrayColorDiff,PFLOAT*pArraySpectralDiff,PFLOAT*pArrayConformity,PFLOAT*pArrayCounter);

/*!
	\fn short MCHR_GetLab (MCHR_ID  SensorID,MCHR_tyAcqParam Parameters, PFLOAT *pArrayDataL,PFLOAT*pArrayDataa,PFLOAT*pArrayDatab,PFLOAT*pArrayColorDiff,PFLOAT*pArraySpectralDiff,PFLOAT*pArrayConformity,PFLOAT*pArrayCounter);
	\if FR
		\brief Récupère les données colorimétriques CIELab. 
	\else
		\brief Get the colorometric data CIELab.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID			: ID du coffret.
			\param [out] MCHR_tyAcqParam Parameters : 
			\param [out] PFLOAT*pArrayDataL			: Data L
			\param [out] PFLOAT*pArrayDataa			: Data a
			\param [out] PFLOAT*pArrayDatab  		: Data b
			\param [out] PFLOAT*pArrayColorDiff     : Method to calculate the difference of the color
			\param [out] PFLOAT*pArraySpectralDiff	: Method to calculate the difference of spectral
			\param [out] PFLOAT*pArrayConformity	: Tolerance to eliminate the sample no accordance.
			\param [out] PFLOAT*pArrayCounter		: Count the number of acquisitions
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID			: ID of the device.
			\param [out] MCHR_tyAcqParam Parameters : 
			\param [out] PFLOAT*pArrayDataL			: Data L
			\param [out] PFLOAT*pArrayDataa			: Data a
			\param [out] PFLOAT*pArrayDatab  		: Data b
			\param [out] PFLOAT*pArrayColorDiff     : Method to calculate the difference of the color
			\param [out] PFLOAT*pArraySpectralDiff	: Method to calculate the difference of spectral
			\param [out] PFLOAT*pArrayConformity	: Tolerance to eliminate the sample no accordance.
			\param [out] PFLOAT*pArrayCounter		: Count the number of acquisitions
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetLab (MCHR_ID  SensorID,MCHR_tyAcqParam Parameters, PFLOAT *pArrayDataL,PFLOAT*pArrayDataa,PFLOAT*pArrayDatab,PFLOAT*pArrayColorDiff,PFLOAT*pArraySpectralDiff,PFLOAT*pArrayConformity,PFLOAT*pArrayCounter);

/*!
	\fn short MCHR_GetLuv (MCHR_ID  SensorID,MCHR_tyAcqParam Parameters, PFLOAT *pArrayDataL,PFLOAT*pArrayDatau,PFLOAT*pArrayDatav,PFLOAT*pArrayColorDiff,PFLOAT*pArraySpectralDiff,PFLOAT*pArrayConformity,PFLOAT*pArrayCounter);
	\if FR
		\brief Récupère les données colorimétriques CIELuv. 
	\else
		\brief Get the colorometric data CIELuv.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID			: ID du coffret.
			\param [out] MCHR_tyAcqParam Parameters : 
			\param [out] PFLOAT*pArrayDataL			: Data L
			\param [out] PFLOAT*pArrayDatau			: Data u
			\param [out] PFLOAT*pArrayDatav  		: Data v
			\param [out] PFLOAT*pArrayColorDiff     : Method to calculate the difference of the color
			\param [out] PFLOAT*pArraySpectralDiff	: Method to calculate the difference of spectral
			\param [out] PFLOAT*pArrayConformity	: Tolerance to eliminate the sample no accordance.
			\param [out] PFLOAT*pArrayCounter		: Count the number of acquisitions
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID			: ID of the device.
			\param [out] MCHR_tyAcqParam Parameters : 
			\param [out] PFLOAT*pArrayDataL			: Data L
			\param [out] PFLOAT*pArrayDatau			: Data u
			\param [out] PFLOAT*pArrayDatav  		: Data v
			\param [out] PFLOAT*pArrayColorDiff     : Method to calculate the difference of the color
			\param [out] PFLOAT*pArraySpectralDiff	: Method to calculate the difference of spectral
			\param [out] PFLOAT*pArrayConformity	: Tolerance to eliminate the sample no accordance.
			\param [out] PFLOAT*pArrayCounter		: Count the number of acquisitions
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetLuv (MCHR_ID  SensorID,MCHR_tyAcqParam Parameters, PFLOAT *pArrayDataL,PFLOAT*pArrayDatau,PFLOAT*pArrayDatav,PFLOAT*pArrayColorDiff,PFLOAT*pArraySpectralDiff,PFLOAT*pArrayConformity,PFLOAT*pArrayCounter);

/*!
	\fn short MCHR_GetLch_ab (MCHR_ID  SensorID,MCHR_tyAcqParam Parameters, PFLOAT *pArrayDataLch,PFLOAT*pArrayData,PFLOAT*pArrayDatab,PFLOAT*pArrayColorDiff,PFLOAT*pArraySpectralDiff,PFLOAT*pArrayConformity,PFLOAT*pArrayCounter);
	\if FR
		\brief Récupère les données colorimétriques CIELch. 
	\else
		\brief Get the colorometric data CIELch.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID			: ID du coffret.
			\param [out] MCHR_tyAcqParam Parameters : 
			\param [out] PFLOAT*pArrayDataLch		: Data Lch
			\param [out] PFLOAT*pArrayDataa			: Data a
			\param [out] PFLOAT*pArrayDatab  		: Data b
			\param [out] PFLOAT*pArrayColorDiff     : Method to calculate the difference of the color
			\param [out] PFLOAT*pArraySpectralDiff	: Method to calculate the difference of spectral
			\param [out] PFLOAT*pArrayConformity	: Tolerance to eliminate the sample no accordance.
			\param [out] PFLOAT*pArrayCounter		: Count the number of acquisitions
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID			: ID of the device.
			\param [out] MCHR_tyAcqParam Parameters : 
			\param [out] PFLOAT*pArrayDataLch		: Data Lch
			\param [out] PFLOAT*pArrayDataa			: Data a
			\param [out] PFLOAT*pArrayDatab  		: Data b
			\param [out] PFLOAT*pArrayColorDiff     : Method to calculate the difference of the color
			\param [out] PFLOAT*pArraySpectralDiff	: Method to calculate the difference of spectral
			\param [out] PFLOAT*pArrayConformity	: Tolerance to eliminate the sample no accordance.
			\param [out] PFLOAT*pArrayCounter		: Count the number of acquisitions
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetLch_ab (MCHR_ID  SensorID,MCHR_tyAcqParam Parameters, PFLOAT *pArrayDataLch,PFLOAT*pArrayData,PFLOAT*pArrayDatab,PFLOAT*pArrayColorDiff,PFLOAT*pArraySpectralDiff,PFLOAT*pArrayConformity,PFLOAT*pArrayCounter);

/*!
	\fn short MCHR_GetW (MCHR_ID  SensorID,MCHR_tyAcqParam Parameters, PFLOAT *pArrayDataW,PFLOAT*pArrayColorDiff,PFLOAT*pArraySpectralDiff,PFLOAT*pArrayConformity,PFLOAT*pArrayCounter);
	\if FR
		\brief Récupère l'indice de blancheur CIE W
		\brief Get the colorometric data CIE W
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID			: ID du coffret.
			\param [out] MCHR_tyAcqParam Parameters : 
			\param [out] PFLOAT*pArrayDataW			: Value of the whiteref
			\param [out] PFLOAT*pArrayColorDiff     : Method to calculate the difference of the color
			\param [out] PFLOAT*pArraySpectralDiff	: Method to calculate the difference of spectral
			\param [out] PFLOAT*pArrayConformity	: Tolerance to eliminate the sample no accordance.
			\param [out] PFLOAT*pArrayCounter		: Count the number of acquisitions
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID			: ID of the device.
			\param [out] MCHR_tyAcqParam Parameters : 
			\param [out] PFLOAT*pArrayDataW			: Data W
			\param [out] PFLOAT*pArrayColorDiff     : Method to calculate the difference of the color
			\param [out] PFLOAT*pArraySpectralDiff	: Method to calculate the difference of spectral
			\param [out] PFLOAT*pArrayConformity	: Tolerance to eliminate the sample no accordance.
			\param [out] PFLOAT*pArrayCounter		: Count the number of acquisitions
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetW (MCHR_ID  SensorID,MCHR_tyAcqParam Parameters, PFLOAT *pArrayDataW,PFLOAT*pArrayColorDiff,PFLOAT*pArraySpectralDiff,PFLOAT*pArrayConformity,PFLOAT*pArrayCounter);

/*!
	\fn short MCHR_GetFirstPixel(MCHR_ID SensorID,long *piFps)
	\if FR
		\brief Fonction detection du premier pixel.
	\else
		\brief Function Get First pixel.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [out] long *piFps : Premier pixel detecte
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [out] long *piFps : First detected pixel
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/

DLL_CHR_API short MCHR_GetFirstPixel(MCHR_ID SensorID,long *piFps);

/*!
	\fn short MCHR_SetFirstPixel(MCHR_ID SensorID,long iFps)
	\if FR
		\brief Fonction de parametrage du premier pixel.
	\else
		\brief Function Set First pixel.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long iFps : Premier pixel detecte
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long iFps : First detected pixel
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/

DLL_CHR_API short MCHR_SetFirstPixel(MCHR_ID SensorID,long iFps);

/*
Number of pixels returned in the taken in account for result
To retreive the spectrums when using MCHR_SetSpectrumBuffer, buffer size must be equal to the NumberOfPixels
*/

/*!
	\fn short MCHR_GetNumberOfPixels(MCHR_ID SensorID,long *piFps);
	\if FR
		\brief Recupere le nombre de pixel pour definir un spectre.
	\else
		\brief Get the number of pixels to define a spectral.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long *piFps : Nombre de pixels.
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long *piFps : Numbers of pixels.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetNumberOfPixels(MCHR_ID SensorID,long *piFps);

/*!
	\fn short MCHR_SetNumberOfPixels(MCHR_ID SensorID,long iFps);
	\if FR
		\brief Parametre le nombre de pixel pour definir un spectre.
	\else
		\brief Set the number of pixels to define a spectral.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long *piFps : Nombre de pixels.
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long *piFps : Numbers of pixels.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetNumberOfPixels(MCHR_ID SensorID,long iFps);

/*!
	\fn short MCHR_GetSampling(MCHR_ID SensorID,long *piSampling);
	\if FR
		\brief Recupere le pas d'échantillonage du spectre.
	\else
		\brief Get the spectral sampling
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long *piSampling :  
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long *piSampling : Spectral sampling ( nothing, 1nm, 5nm, 10nm).
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetSampling(MCHR_ID SensorID,long *piSampling);

/*!
	\fn short MCHR_SetSampling(MCHR_ID SensorID,long iSampling);
	\if FR
		\brief Parametre le pas d'échantillonage du spectre.
	\else
		\brief Set the spectral sampling
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long *piSampling :  
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long *piSampling : Spectral sampling ( nothing, 1nm, 5nm, 10nm).
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetSampling(MCHR_ID SensorID,long iSampling);

/*!
	\fn short MCHR_GetMaximumNumberPixel(MCHR_ID SensorID,long *piMax);
	\if FR
		\brief Obtient le nombre maximum de pixels.
	\else
		\brief Get the the maximum numbers of pixels
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long *piMax :  
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long *piMax : Maximum Numbers of pixels.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetMaximumNumberPixel(MCHR_ID SensorID,long *piMax);

/*!
	\fn short MCHR_SetMaximumNumberPixel(MCHR_ID SensorID,long *piMax);
	\if FR
		\brief PAramétre le nombre maximum de pixels.
	\else
		\brief Set the the maximum numbers of pixels
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long iMax :  
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long iMax : Maximum Numbers of pixels.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetMaximumNumberPixel(MCHR_ID SensorID,long iMax);

/*!
	\fn short MCHR_GetMinimumNumberPixel(MCHR_ID SensorID,long *piMin);
	\if FR
		\brief Obtient le nombre minimum de pixels.
	\else
		\brief Get the the minimum numbers of pixels
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long *piMin :  
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long *piMins : Maximum Numbers of pixels.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetMinimumNumberPixel(MCHR_ID SensorID,long *piMin);

/*!
	\fn short MCHR_SetMinimumNumberPixel(MCHR_ID SensorID,long iMin);
	\if FR
		\brief Parametre le nombre minmum de pixels.
	\else
		\brief Set the the minimum numbers of pixels
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param [in] long iMin :  
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param [in] long iMin : Minimum Numbers of pixels.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetMinimumNumberPixel(MCHR_ID SensorID,long iMin);

/*!
	\fn short MCHR_GetRealTimeSignalType(MCHR_ID SensorID,enRealTimeSignalType *);
	\if FR
		\brief Obtient le type de signal exporté (brut ou traité), le signal traité correspond à la réflectance de l’échantillon.
	\else
		\brief Get the type of signal exported (raw or processed), the processed signal is equivalent to the reflectance of the sample.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param enRealTimeSignalType :  
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param enRealTimeSignalType : type of signal
				\arg \c RT_NO_SIGNAL,
				\arg \c RT_RAW_SIGNAL,
				\arg \c RT_PRETRAITED_SIGNAL,
				\aeg \c NBR_MAX_RT_SIGNAL_TYPE,
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetRealTimeSignalType(MCHR_ID SensorID,enRealTimeSignalType *pRealTimeSignalType);

/*!
	\fn short MCHR_SetRealTimeSignalType(MCHR_ID SensorID,enRealTimeSignalType);
	\if FR
		\brief Parametre le type de signal exporté (brut ou traité), le signal traité correspond à la réflectance de l’échantillon.
	\else
		\brief Set the type of signal exported (raw or processed), the processed signal is equivalent to the reflectance of the sample.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param enRealTimeSignalType :  
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param enRealTimeSignalType : type of signal
				\arg \c RT_NO_SIGNAL,
				\arg \c RT_RAW_SIGNAL,
				\arg \c RT_PRETRAITED_SIGNAL,
				\aeg \c NBR_MAX_RT_SIGNAL_TYPE,
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetRealTimeSignalType(MCHR_ID SensorID, enRealTimeSignalType realTimeSignalType);

/*!
	\fn short MCHR_MeasureTarget(MCHR_ID SensorID);
	\if FR
		\brief 
	\else
		\brief Function to read the mesure of the target
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
		\endif
*/
DLL_CHR_API short MCHR_MeasureTarget(MCHR_ID SensorID);

/*!
	\fn short MCHR_GetReferenceCoordinate (MCHR_ID  SensorID,	PFLOAT pfX, PFLOAT pfY, PFLOAT pfZ);
	\if FR
		\brief Obtient les coordonnées colorimétriques de la cible
	\else
		\brief Get the target colorimetric coordinates.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param PFLOAT pfX : Pointer to an array of target colorimetric coordinate X.
			\param PFLOAT pfY : Pointer to an array of target colorimetric coordinate Y.
			\param PFLOAT pfZ : Pointer to an array of target colorimetric coordinate Z.
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param PFLOAT pfX : Pointer to an array of target colorimetric coordinate X.
			\param PFLOAT pfY : Pointer to an array of target colorimetric coordinate Y.
			\param PFLOAT pfZ : Pointer to an array of target colorimetric coordinate Z.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetReferenceCoordinate (MCHR_ID  SensorID,	PFLOAT pfX, PFLOAT pfY, PFLOAT pfZ);

/*!
	\fn short MCHR_GetIlluminantCoordinate (MCHR_ID  SensorID,	PFLOAT pfX, PFLOAT pfY, PFLOAT pfZ);
	\if FR
		\brief Obtient les coordonnées colorimétriques de l'illuminant
	\else
		\brief Get the illuminant colorimetric coordinates 
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param PFLOAT pfX : 
			\param PFLOAT pfY :
			\param PFLOAT pfZ :
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param PFLOAT pfX : Pointer to an array of target colorimetric coordinate X. 
			\param PFLOAT pfY : Pointer to an array of target colorimetric coordinate Y.
			\param PFLOAT pfZ : Pointer to an array of target colorimetric coordinate Z.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetIlluminantCoordinate (MCHR_ID  SensorID,	PFLOAT pfX, PFLOAT pfY, PFLOAT pfZ);

/*!
	\fn short MCHR_SetIlluminants (MCHR_ID  SensorID, enIlluminant);
	\if FR
		\brief Configure l'illuminant CIE à utiliser pour le calcul des coordonnées colorimétriques. 
	\else
		\brief Set the CIE illuminant to calculate of colorimetrics coordinates.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param enIlluminant :
				\arg \c A.
				\arg \c C.
				\aeg \c D.
				\arg \c F.
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param enIlluminant :
				\arg \c A.
				\arg \c C.
				\aeg \c D.
				\arg \c F.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetIlluminants (MCHR_ID  SensorID, enIlluminant );

/*!
	\fn short MCHR_GetIlluminants (MCHR_ID  SensorID, enIlluminant *);
	\if FR
		\brief Obtient l'illuminant CIE à utiliser pour le calcul des coordonnées colorimétriques. 
	\else
		\brief Get the CIE illuminant to calculate of colorimetrics coordinates.
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param enIlluminant : 
				\arg \c A.
				\arg \c C.
				\aeg \c D.
				\arg \c F.
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param enIlluminant : Choice of illuminant
				\arg \c A.
				\arg \c C.
				\aeg \c D.
				\arg \c F.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetIlluminants (MCHR_ID  SensorID, enIlluminant *);

/*!
	\fn short MCHR_SetObserver (MCHR_ID  SensorID, enObservateur);
	\if FR
		\brief Configure l’observateur standard CIE à utiliser pour le calcul des coordonnées colorimétriques.
	\else
		\brief Set the standart observer to calculate the colorimetrics coordinates. 
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param enObservateur : 
				\arg \c OBS_CIE1931 : CIE1931 (2°),
				\arg \c OBS_CIE1964 : CIE1964 (10°).
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param enObservateur : Value of observer
				\arg \c OBS_CIE1931 : CIE1931 (2°),
				\arg \c OBS_CIE1964 : CIE1964 (10°).
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetObserver (MCHR_ID  SensorID, enObservateur);

/*!
	\fn short MCHR_GetObserver (MCHR_ID  SensorID, enObservateur*);
	\if FR
		\brief Obtient l’observateur standard CIE à utiliser pour le calcul des coordonnées colorimétriques.
	\else
		\brief Get the standart observer to calculate the colorimetrics coordinates. 
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param enObservateur : 
				\arg \c OBS_CIE1931 : CIE1931 (2°),
				\arg \c OBS_CIE1964 : CIE1964 (10°).
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param enObservateur : Value of observer
				\arg \c OBS_CIE1931 : CIE1931 (2°),
				\arg \c OBS_CIE1964 : CIE1964 (10°)
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetObserver (MCHR_ID  SensorID, enObservateur*);

/*!
	\fn short MCHR_SetColorIndicator (MCHR_ID  SensorID, enIndiceCouleur);
	\if FR
		\brief Configure le calcul des différences de couleur (coordonnées colorimétriques).  
	\else
		\brief Set the value to calculate the color difference. 
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param enIndiceCouleur : 
				\arg \c IND_COLOR_Eab	: delta Eab,
				\arg \c IND_COLOR_E2000 : delta E2000,
				\arg \c IND_COLOR_CMC	: CMC,
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param enIndiceCouleur : Value of calculation
				\arg \c IND_COLOR_Eab	: delta Eab,
				\arg \c IND_COLOR_E2000 : delta E2000,
				\arg \c IND_COLOR_CMC	: CMC,
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetColorIndicator (MCHR_ID  SensorID, enIndiceCouleur);

/*!
	\fn short MCHR_GetColorIndicator (MCHR_ID  SensorID, enIndiceCouleur*);
	\if FR
		\brief Obtient le calcul des différences de couleur (coordonnées colorimétriques).  
	\else
		\brief Get the value to calculate the color difference. 
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param enIndiceCouleur : 
				\arg \c IND_COLOR_Eab	: delta Eab,
				\arg \c IND_COLOR_E2000 : delta E2000,
				\arg \c IND_COLOR_CMC	: CMC,
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param enIndiceCouleur : Value of calculation
				\arg \c IND_COLOR_Eab	: delta Eab,
				\arg \c IND_COLOR_E2000 : delta E2000,
				\arg \c IND_COLOR_CMC	: CMC,
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetColorIndicator (MCHR_ID  SensorID, enIndiceCouleur*);

/*!
	\fn short MCHR_SetSpectralIndicator (MCHR_ID  SensorID, enIndiceSpectre);
	\if FR
		\brief Configure le calcul des différences de spectre.
	\else
		\brief Set the value to calculate the spectral difference. 
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param enIndiceSpectre : 
				\arg \c IND_SPECTRE_RMS : RootMeanSquar,
				\arg \c IND_SPECTRE_GFC : Goodness-Fitness Coefficient,
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param enIndiceSpectre : Value of calculation
				\arg \c IND_SPECTRE_RMS : RootMeanSquar,
				\arg \c IND_SPECTRE_GFC : Goodness-Fitness Coefficient,
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetSpectralIndicator (MCHR_ID  SensorID, enIndiceSpectre);

/*!
	\fn short MCHR_GetSpectralIndicator (MCHR_ID  SensorID, enIndiceSpectre*);
	\if FR
		\brief Obtient le calcul des différences de spectre.
	\else
		\brief Set the value to calculate the spectral difference. 
	\endif
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param enIndiceSpectre : 
				\arg \c IND_SPECTRE_RMS : RootMeanSquar,
				\arg \c IND_SPECTRE_GFC : Goodness-Fitness Coefficient,
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param enIndiceSpectre : Value of calculation
				\arg \c IND_SPECTRE_RMS : RootMeanSquar,
				\arg \c IND_SPECTRE_GFC : Goodness-Fitness Coefficient,
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetSpectralIndicator (MCHR_ID  SensorID, enIndiceSpectre*);

/*!
	\fn short MCHR_SetColorDifferenceMode (MCHR_ID  SensorID, enTypeConformite);
	\if FR
		\brief Configure le type de calcul des différences entre mesure courante et mesure cible. Les deux types disponibles sont soit une différence de couleur ou de spectre.      
	\else
		\brief Set the calculation type of difference between current measurement and target measurement.
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param enIndiceSpectre : 
				\arg \c CONFORMITE_DESACTIVE,
				\arg \c CONFORMITE_COULEUR,
				\arg \c CONFORMITE_SPECTRE,
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param enIndiceSpectre : Value of calculation
				\arg \c CONFORMITE_DESACTIVE,
				\arg \c CONFORMITE_COULEUR,
				\arg \c CONFORMITE_SPECTRE,
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetColorDifferenceMode (MCHR_ID  SensorID, enTypeConformite);

/*!
	\fn short MCHR_GetColorDifferenceMode (MCHR_ID  SensorID, enTypeConformite*);
	\if FR
		\brief Configure le type de calcul des différences entre mesure courante et mesure cible. Les deux types disponibles sont soit une différence de couleur ou de spectre.      
	\else
		\brief Get the calculation type of difference between current measurement and target measurement.
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\param enIndiceSpectre : 
				\arg \c CONFORMITE_DESACTIVE,
				\arg \c CONFORMITE_COULEUR,
				\arg \c CONFORMITE_SPECTRE,
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\param enIndiceSpectre : Value of calculation
				\arg \c CONFORMITE_DESACTIVE,
				\arg \c CONFORMITE_COULEUR,
				\arg \c CONFORMITE_SPECTRE,
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetColorDifferenceMode (MCHR_ID  SensorID, enTypeConformite*);

/*!
	\fn short MCHR_SetColorTolerance (MCHR_ID  SensorID, double);
	\if FR
		\brief Configure la valeur de tolérance d’un calcul de différence entre spectres ou coordonnées colorimétriques.    
	\else
		\brief Set the tolerance value of calculation berween spectral or colorimetrics coordinates.
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_SetColorTolerance (MCHR_ID  SensorID, double);

/*!
	\fn short MCHR_GetColorTolerance (MCHR_ID  SensorID, double*);
	\if FR
		\brief Configure la valeur de tolérance d’un calcul de différence entre spectres ou coordonnées colorimétriques.    
	\else
		\brief Get the tolerance value of calculation berween spectral or colorimetrics coordinates.
	\details
		\if FR
			\param [in] MCHR_ID  SensorID : ID du coffret.
			\return short : un code d'erreur \link MCHR_ERROR MCHR_ERROR \endlink.
		\else
			\param [in] MCHR_ID  SensorID : ID of the device.
			\return short : A \link MCHR_ERROR MCHR_ERROR \endlink code.
		\endif
		\see MCHR_GetErrorDescription
*/
DLL_CHR_API short MCHR_GetColorTolerance (MCHR_ID  SensorID, double*);




/*
Use this function to specify a buffer receiving the spectrums
ppSpectrumBuffer is a pointer to a pointer array of the size of the buffer_number
Each of this buffer is pointing to an array of pointer. Each of them point to an array of WORD, which size is specified in wSpectroSize
The size should be equals to the value returned by SPECTRO_GetNumberOfPixels()
For an example, please have a look at the SpectroSample, "DAcquisition.cpp"

      ppSpectrumBuffer
         |
		[*][*][*][*][*][*][*][*] ... (buffer number)
		 /|\
			\
	    [*][*][*]... (buffer length)
		/|\
		   \
		   [WORD][WORD][WORD][WORD][WORD][WORD][WORD][WORD]... buffer size
*/

/*!
	\fn short MCHR_SetSpectrumBuffer (MCHR_ID  SensorID, double*);
	\if FR
		\brief PRIVE   
	\else
		\brief PRIVATE
*/
DLL_CHR_API short MCHR_SetSpectrumBuffer(MCHR_ID SensorID,WORD***ppSpectrumBuffer,WORD wSpectroSize);

