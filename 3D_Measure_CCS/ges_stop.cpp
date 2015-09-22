#include "stdafx.h"
#include "ges_stop.h"

bool ges_stop()
{
    //**********************************************************************************
	//电机停止
	/*(9)*/
	short rtn =0 ; //电机操作后的返回值，0表示无错误
	rtn = GT_Stop();	//关闭控制轴伺服使能
	if(rtn!=0)
	{
		printf("关闭控制轴伺服使能失败！");
		return false;
	}
	rtn = GT_Close();						//关闭运动控制器

	if(rtn!=0)
	{
		error(rtn);
		printf("关闭运动控制器失败！");
	    return false;
	}
	return true;
}