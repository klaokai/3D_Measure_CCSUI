#pragma once

void error(short rtn);//错误输出子函数   各数值代表的含义参考文档

short AxisInitial(short axis_num,unsigned short limit);//控制轴初始化函数

short MotionInitial();//轴运动参数初始化

short GT_System_Initinal();  //平台初始化

short GT_Buffer();//缓冲区运动指令存放函数

short GT_GetPosition();//读取轴当前位置

short GT_Stop();//关闭控制轴伺服使能

short GT_Check_Limit();//限位标志检查

short GT_ADD_Buffer_continue(double AxisX_1, double AxisY_1,double Vel);

short GT_ADD_Buffer_trigger(double AxisX_1, double AxisY_1,double Vel);

short GT_Check_status()	;//检测运动状态是否停止

short GT_GetLmtZero_X();//X运动到极限位置并设置为系统坐标的原点

short GT_GetLmtZero_Y();//Y运动到极限位置并设置为系统坐标的原点

//********************************************************************************************************

short GT_GetZero();//回零，回到程序刚开始的零点（上电坐标为系统原点）

short Home(unsigned short axis,long pos,long offset,double vel_high,double vel_low) ;//home信号回零

short GT_ADD_Buffer_continue(double AxisX_1, double AxisY_1,double AxisX_2, double AxisY_2);//添加缓冲区指令

short GT_GetStartZero();//回到上电时的坐标(极限坐标为系统原点)

short GT_Stop_AxisNum(short Set_AxisNum);//停止缓冲区指令运动到第Set_AxisNum-1条

short GT_Read_AxisNum();//读取缓冲区当前指令执行到条数的编号