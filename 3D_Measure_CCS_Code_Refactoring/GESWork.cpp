#include "StdAfx.h"
#include "GESWork.h"
#include <time.h>
#include "afxmt.h"
GESWork::GESWork(void)
{
}

GESWork::~GESWork(void)
{
}

void GESWork::error(short rtn)				//错误输出子函数   各数值代表的含义参考文档
{ 
	switch(rtn) 
	{
	case -1: 
		printf("Communication Error !"); 
		break; 
	case 0: 
		break; 
	case 1: 
		printf("Command Error !");
		break; 
	case 2: 
		printf("Radius or chord is 0 !");
		break; 
	case 3: 
		printf("Length is 0 or overflow !"); 
		break; 
	case 4: 
		printf("Velocity or acceleration is less then 0 !"); 
		break; 
	case 5: 
		printf("Chord is greater than diameter !"); 
		break; 
	case 7: 
		printf("Parameter error !");
		break; 
	default: 
		printf("Error Code Unknow！ ");
		break; 
	}
}


short GESWork::GT_System_Initinal()				//平台初始化
{
	short rtn; 
	rtn = GT_Open();							//打开运动控制器 
	error(rtn);
	rtn = GT_Reset();						//复位运动控制器
	error(rtn);

	return rtn;
}

short GESWork::AxisInitial(short axis_num,unsigned short limit)		//控制轴初始化函数
{					

	short rtn; 
	rtn=GT_LmtSns(limit);	//设置限位开关触发电平			
	error(rtn); 
	rtn = GT_LmtsOn(1);		//1轴限位有效
	error(rtn);
	rtn = GT_LmtsOn(2);		//2轴限位有效
	error(rtn);

	rtn=GT_EncSns(0);		//编码器计数方向  默认
	error(rtn); 


	rtn=GT_HomeSns(0);		//Home 信号触发沿  默认
	error(rtn); 

	rtn=GT_AlarmOff(1);						//关闭驱动报警			
	error(rtn);
	rtn=GT_AlarmOff(2);						//关闭驱动报警			
	error(rtn);

	for(short axis_i=1;axis_i<=axis_num;++axis_i)		 //2轴 axis_i = 2 
	{
		rtn=GT_CtrlMode(axis_i,1);				//设置控制轴为脉冲输出模式 
		error(rtn);
		rtn=GT_StepDir(axis_i);					   //设置轴输出脉冲/方向信号			*****脉冲/方向
		error(rtn); 
		rtn=GT_AxisOn(axis_i);					  //驱动使能
		error(rtn);
		rtn=GT_ClrSts(axis_i);					  //控制轴状态寄存器复位
		error(rtn);

		Sleep(200);							//插入适当延时 

	} 

	return rtn;
}

short GESWork::MotionInitial()								//轴运动参数初始化
{ 
	short rtn;
	double StartVel, MaxVel, StopAcc;				//启动速度 最大速度 最大加速度
	double WorkVel, WorkAcc;						//工作速度  工作加速度

	StartVel=0.5;									//启动速度为500HZ
	MaxVel=200;										//最大速度为6m/min 
	StopAcc=6;										//急停加速度为3m/s2 
	WorkVel=20.32;									//当进给速度为24.5/5  mm/s    WorkVel=10.16 P/ms											
	WorkAcc=1.8;									//进给加速度为0.9m/s2



	rtn=GT_SetStrtVel(StartVel);					//设置系统启动速度 
	error(rtn); 
	rtn=GT_SetMaxVel(MaxVel);						//设置系统最大速度
	error(rtn);
	rtn=GT_SetStpAcc(StopAcc);						//设置系统急停加速度 
	error(rtn);

	rtn=GT_SetSynAcc(WorkAcc);						//设置进给加速度
	error(rtn); 
	rtn=GT_SetSynVel(WorkVel);						//设置进给速度
	error(rtn);
	return rtn;
}




short GESWork::GT_Buffer() //缓冲区运动指令存放函数
{

	short rtn;
	rtn=GT_StrtList(); 
	error(rtn);

	rtn=GT_MvXY(0,0, 10.16,3.6);
	error(rtn);						//定位运动起点坐标//进给速度为25.4/5 mm/s

	rtn=GT_LnXY(0,1);  
	error(rtn);

	rtn=GT_EndList(); //关闭缓冲区 
	error(rtn); 
	rtn=GT_StrtMtn(); //启动缓冲区

	error(rtn);
	return rtn;
}

short GESWork::GT_Stop()							  //关闭控制轴伺服使能
{
	short rtn;
	rtn=GT_AxisOff(1);					  //驱动关闭		
	error(rtn);
	rtn=GT_AxisOff(2);					  //驱动关闭
	error(rtn);
	return rtn;
}




short GESWork::GT_ADD_Buffer_continue(double AxisX_1, double AxisY_1,double Vel)//添加缓冲区指令
{
	short rtn;

	rtn=GT_AddList();//增加运动段数
	error(rtn); 

	rtn=GT_SetSynVel(Vel);//重新设置速度
	error(rtn);

	rtn=GT_LnXY(AxisX_1,AxisY_1); //运动到坐标
	error(rtn);

	rtn=GT_EndList(); //关闭缓冲区 
	error(rtn);

	rtn=GT_StrtMtn(); //启动缓冲区
	error(rtn);

	return rtn;

}

short GESWork::GT_ADD_Buffer_trigger(double AxisX_1, double AxisY_1,double Vel)//添加缓冲区指令
{
	short rtn;

	rtn=GT_AddList();//增加运动段数
	error(rtn); 

	rtn=GT_SetSynVel(Vel);//重新设置速度
	error(rtn);

	rtn = GT_ExOpt(0x0040);       //外部触发Exo6
	error(rtn);

	rtn=GT_LnXY(AxisX_1,AxisY_1); //运动到坐标
	error(rtn);

	rtn=GT_EndList(); //关闭缓冲区 
	error(rtn);

	rtn=GT_StrtMtn(); //启动缓冲区
	error(rtn);

	return rtn;

}
short GESWork::GT_Check_status()	//检测运动状态是否停止
{	
	short rtn;
	unsigned short status;
	rtn=GT_GetCrdSts(&status);
	error(rtn);													//当status的第1位为0时，有运动)
	while(1)													//当status的第1位为1时，无运动
	{			
		if((status&0x01)==0x01)
			break;
		rtn=GT_GetCrdSts(&status);
		error(rtn);

	}

	return rtn;

}

short GESWork::GT_GetLmtZero_X()//极限位置为坐标原点
{
	short axis_num = 1;
	short rtn;
	unsigned short status;
	double prf_pos[2]={0,0};


	rtn=GT_SetSynVel(100);						//设置进给速度
	error(rtn);

	prf_pos[(axis_num-1)] = -1000000;//运动一段距离使其到达极限位置

	rtn=GT_LnXY(prf_pos[0],prf_pos[1]);
	error(rtn);

	Sleep(100);

	rtn=GT_GetSts(axis_num,&status); //读取控制轴状态
	error(rtn);

	while((status&0x40)!=0x40) // 判断是否到达极限位置
	{
		GT_GetSts(axis_num,&status); //读取控制轴状态
		if((status&0x400)==0)
		{
			printf("运动完成且未到极限位置\n");
			return  1;
		}
	}

	rtn=GT_StpMtn();					//平滑停止
	error(rtn);
	Sleep(3000);

	rtn=GT_ZeroPos(axis_num);			//工作台位置清零建立机床坐标系
	error(rtn);
	Sleep(100);
	//**********************************************************************************
	rtn=GT_SetSynVel(50);				//设置进给速度
	error(rtn);

	//移动10mm，3秒钟
	prf_pos[axis_num-1] =30000;			//往回走一小段距离以便清除限位标志位
	//原值 300000								//注意要和Sleep的延时时间相匹配

	rtn=GT_LnXY(prf_pos[0],prf_pos[1]); 
	error(rtn);	
	Sleep(2000);//原值30000
	//**********************************************************************************
	//**********************************************************************************
	//再走一次，消除上电第一次的x轴误差
	/*
	rtn=GT_ClrSts(axis_num);			//清除限位状态标志位
	error(rtn);
	Sleep(1000);

	rtn=GT_ZeroPos(axis_num);			//工作台位置清零建立机床坐标系
	error(rtn);
	Sleep(100);

	rtn=GT_SetSynVel(10.16);				//设置进给速度
	error(rtn);
	Sleep(100);

	prf_pos[(axis_num-1)] = -1000000;//运动一段距离使其到达极限位置

	rtn=GT_LnXY(prf_pos[0],prf_pos[1]); 
	error(rtn);

	Sleep(100);

	rtn=GT_GetSts(axis_num,&status); //读取控制轴状态
	error(rtn);

	while((status&0x40)!=0x40) // 判断是否到达极限位置
	{
	GT_GetSts(axis_num,&status); //读取控制轴状态
	if((status&0x400)==0)
	{
	AfxMessageBox(_T("运动完成且未到极限位置\n"));
	return  1;
	}
	}

	rtn=GT_StpMtn();					//平滑停止
	error(rtn);
	Sleep(3000);

	rtn=GT_ZeroPos(axis_num);			//工作台位置清零建立机床坐标系
	error(rtn);
	Sleep(100);
	//**********************************************************************************、
	//在该位置要与坐标原点匹配

	prf_pos[axis_num-1] = 200000;			//往回走一小段距离以便清除限位标志位
	//注意要和Sleep的延时时间相匹配

	rtn=GT_LnXY(prf_pos[0],prf_pos[1]); 
	error(rtn);
	Sleep(20000);
	*/
	//**********************************************************************************
	//**********************************************************************************
	//**********************************************************************************

	rtn=GT_ZeroPos(axis_num);			//工作台位置清零建立机床坐标系
	error(rtn);
	Sleep(100);

	rtn=GT_ClrSts(axis_num);			//清除限位状态标志位
	error(rtn);
	Sleep(1000);

	return rtn;
}


short GESWork::GT_GetLmtZero_Y()//极限位置为坐标原点
{
	short rtn;
	short axis_num = 2;
	unsigned short status;
	double prf_pos[2]={0,0};

	rtn=GT_SetSynVel(100);						//设置进给速度
	error(rtn);

	prf_pos[(axis_num-1)] = -1000000;//运动一段距离使其到达极限位置

	rtn=GT_LnXY(prf_pos[0],prf_pos[1]);
	error(rtn);

	Sleep(100);

	rtn=GT_GetSts(axis_num,&status); //读取控制轴状态
	error(rtn);

	while((status&0x40)!=0x40) // 判断是否到达极限位置
	{
		GT_GetSts(axis_num,&status); //读取控制轴状态
		if((status&0x400)==0)
		{
			printf("运动完成且未到极限位置\n");
			return  1;
		}
	}

	rtn=GT_StpMtn();					//平滑停止
	error(rtn);
	Sleep(3000);

	rtn=GT_ZeroPos(axis_num);			//工作台位置清零建立机床坐标系
	error(rtn);
	Sleep(100);
	//**********************************************************************************	
	rtn=GT_SetSynVel(50);				//设置进给速度
	error(rtn);
	//移动50mm，5秒钟
	prf_pos[axis_num-1] = 150000;			//往回走一小段距离以便清除限位标志位
	//原值500000										//注意要和Sleep的延时时间相匹配
	//**********************************************************************************
	rtn=GT_LnXY(prf_pos[0],prf_pos[1]); 
	error(rtn);

	Sleep(4000);//原值50000


	//**********************************************************************************
	rtn=GT_ZeroPos(axis_num);			//工作台位置清零建立机床坐标系
	error(rtn);
	Sleep(100);

	rtn=GT_ClrSts(axis_num);			//清除限位状态标志位
	error(rtn);
	Sleep(1000);

	return rtn;
}





//********************************************************************************************************
//********************************************************************************************************
//*****************
//以下函数未用
//
//*****************
short GESWork::GT_Read_AxisNum()					  //读取缓冲区当前指令执行到条数的编号
{	
	short rtn;
	unsigned short number;
	rtn=GT_GetMtnNm(&number);				//读取当前轨迹段编号
	return number;

}


short GESWork::GT_GetPosition()						//读取轴当前位置
{
	short rtn ;
	long atlPosX,atlPosY;

	rtn=GT_AxisOff(1);					    //驱动关闭		先关闭轴才可以关闭编码器
	error(rtn);
	rtn=GT_AxisOff(2);					    //驱动关闭
	error(rtn);

	rtn=GT_EncOn(1);						//打开1轴编码器
	error(rtn); 
	rtn=GT_EncOn(2);						//打开2轴编码器
	error(rtn); 

	GT_GetAtlPos(1, &atlPosX);				//读取控制轴的实际位置   必须先开编码器
	GT_GetAtlPos(2, &atlPosY);

	printf("\nActual Position = %ld \n ", atlPosX);
	printf("\nActual Position = %ld \n ", atlPosY);

	rtn=GT_EncOff(1);	                    //关闭1轴编码器
	error(rtn); 
	rtn=GT_EncOff(2);						//关闭2轴编码器
	error(rtn); 

	rtn=GT_AxisOn(1);					    //驱动使能
	error(rtn);
	rtn=GT_AxisOn(2);					    //驱动使能
	error(rtn);

	return rtn;
}


short GESWork::GT_Stop_AxisNum(short Set_AxisNum)//停止缓冲区指令运动到第Set_AxisNum-1条
{
	short rtn,Stop_AxisNum; 
	unsigned short status;
	rtn=GT_GetCrdSts(&status);
	error(rtn);
	while((status&0x01)==0x00)//当status的第1位为1时，无运动
	{//当status的第1位为0时，有运动
		rtn=GT_GetCrdSts(&status);
		error(rtn);
		Stop_AxisNum=GT_Read_AxisNum();

		if(Stop_AxisNum==Set_AxisNum)
		{
			rtn=GT_StpMtn();								//平滑停止轨迹运动
			return rtn;
		}

	}
	return rtn;
}


short GESWork::Home(unsigned short axis,long pos,long offset,double vel_high,double vel_low) 
{ 
	short rtn;
	double prf_pos[4];
	unsigned short status,crd_status; 
	GT_ClrSts(axis);//清回原点轴状态 
	GT_CaptHome(axis); //将回原点轴设置为 
	//原点捕获方式 
	GT_SetSynVel(vel_high); //设置回原点的速度 
	GT_SetSynAcc(0.01); //设置回原点的加速度 
	GT_GetPrfPnt(prf_pos); //读取各轴的规划位置 
	prf_pos[axis-1] = pos; //设置回原点轴的目标位置
	GT_LnXY(prf_pos[0],prf_pos[1]);

	do 
	{ 
		GT_GetCrdSts(&crd_status); //读取坐标系状态 
		if(crd_status&1) //如果运动已经完成
		{ //仍然没有触发Home信号 
			return 1; //返回错误代码1 
		} 
		GT_GetSts(axis,&status); //读取控制轴状态
	}while(!(status&0x8)); //等待Home信号触发 


	GT_StpMtn(); //平滑停止


	do
	{ 
		GT_GetCrdSts(&crd_status); //读取坐标系状态
	}while(!(crd_status&1)); //等待运动完成 


	GT_GetCapt(axis,&pos); //读取捕获位置
	GT_SetSynVel(vel_low); //低速运动到原点 
	prf_pos[axis-1]= pos;
	rtn=GT_LnXY(prf_pos[0],prf_pos[1]); 


	do
	{ 
		GT_GetCrdSts(&crd_status); //读取坐标系状态
	}while(!(crd_status&1)); //等待运动完成 


	prf_pos[axis-1]+= offset; //运动一小段距离离开Home开关
	GT_LnXY(prf_pos[0],prf_pos[1]);


	do 
	{ 
		GT_GetCrdSts(&crd_status); //读取坐标系状态
	}while(!(crd_status&1)); //等待运动完成


	Sleep(1000); //插入适当延时，等待工作台停稳 
	GT_ZeroPos(axis); //工作台位置清零建立机床坐标系
	return 0; 
}

short GESWork::GT_GetStartZero()//回到上电时的坐标(一定要是在调用GT_GetLmtZero函数建立系统极限坐标原点且回到该原点后方可调用该函数回到上电时的原点)
{
	short rtn;

	rtn=GT_AddList();//增加运动段数
	error(rtn);

	rtn=GT_LnXY(0,0); //运动到坐标
	error(rtn);

	rtn=GT_LnXY(0,437120);//运动到坐标
	error(rtn);

	rtn=GT_EndList(); //关闭缓冲区 
	error(rtn);

	rtn=GT_StrtMtn(); //启动缓冲区
	error(rtn);

	return rtn;



}



short GESWork::GT_GetZero()//回零，回到程序刚开始的零点(系统零点为刚上电时的坐标)
{

	short rtn;

	rtn=GT_AddList();//增加运动段数
	error(rtn); 

	rtn=GT_SetSynVel(40.64);//重新设置速度
	error(rtn);
	rtn=GT_LnXY(0,0); //运动到坐标
	error(rtn);

	rtn=GT_EndList(); //关闭缓冲区 
	error(rtn);

	rtn=GT_StrtMtn(); //启动缓冲区
	error(rtn);

	return rtn;

}
/*
short GESWork::GT_Check_Limit()//限位标志检查
{
short rtn;
unsigned short statusX,statusY;
rtn=GT_GetSts(1,&statusX);				//读取指定控制轴限位、报警、原点捕获信号状态
error(rtn);
rtn=GT_GetSts(2,&statusY);
error(rtn);
if((statusX&0x0800) == 0 )
{
printf("X轴限位失效\n");
return 100;
}


if((statusX&0x20)!=0)
printf("达到X轴正限位\n");
if((statusX&0x40)!=0)
printf("达到X轴负限位\n");

if((statusY&0x0800)==0)
{
printf("Y轴限位失效\n");
return 100;
}

if((statusY&0x20)!=0)
{
printf("达到Y轴正限位\n");
}
if((statusY&0x40)!=0)
printf("达到Y轴负限位\n");
return rtn;

}
*/
