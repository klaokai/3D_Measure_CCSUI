// 3D_Measure_CCSUIDlg.h : 头文件
//

#pragma once

#include "ges.h"

// CMy3D_Measure_CCSUIDlg 对话框
class CMy3D_Measure_CCSUIDlg : public CDialog
{
// 构造
public:
	CMy3D_Measure_CCSUIDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY3D_MEASURE_CCSUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

//私有数据
private:
	int width;                    //X扫描步数
	int height;                           //Y扫描步数
	int IntensityStart;                    //LED光强起始值
	int IntensityStep;                      //LED光强增量
	int IntensityCount;//(100-IntensityStart)/IntensityStep+1;                     //LED变光强次数
	int FrequencyStart;                   //频率起始值
	int FrequencyStep;                      //频率增量
	int FrequencyCount;//(2000-FrequencyStart)/FrequencyStep+1;                     //变频率次数
	int DpiStart;                              //分辨率
	int DpiStep;							//分辨率增量
	int DpiCount;							//分辨率增加次数
	char filename[25];	            //材料编号+次数 
	int average;                               //averaging参数
	int holdlast;                            //holdlast参数
};
