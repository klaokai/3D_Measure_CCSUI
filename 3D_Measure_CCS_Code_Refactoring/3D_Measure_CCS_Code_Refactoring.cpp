// 3D_Measure_CCS_Code_Refactoring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "GES_CCS_Ctrl.h"

int _tmain(int argc, _TCHAR* argv[])
{
	
	GES_CCS_Ctrl machineControl=GES_CCS_Ctrl();
	machineControl.WorkingProcess();
	
	return 0;
}

