#pragma once

#include "Resource.h"
#include "CCSWork.h"

class CCSControl:public CCSWork
{
public:
	CCSControl(void);
	~CCSControl(void);
	//≥ı ºªØ
	bool ccs_initial(MCHR_ID *SensorID,sAcqEasyParam* acqEasyParam,
		int intensity,int frequency,int buffer_width,int average,int holdlast);
	
	//πÿ±’
	bool ccs_clean(MCHR_ID *SensorID);

};

