#pragma once
#include "GESWork.h"
#include "cAcqEasy.h"

class GESControl:public GESWork
{
public:
	GESControl(void);
	~GESControl(void);

	bool ges_initial();
	bool ges_messure_zero(int x,int y);
	bool ges_stop();
};

