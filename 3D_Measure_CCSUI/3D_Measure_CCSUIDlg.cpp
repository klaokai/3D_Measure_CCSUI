// 3D_Measure_CCSUIDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "3D_Measure_CCSUI.h"
#include "3D_Measure_CCSUIDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3D_Measure_CCSUIDlg �Ի���




CMy3D_Measure_CCSUIDlg::CMy3D_Measure_CCSUIDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy3D_Measure_CCSUIDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy3D_Measure_CCSUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy3D_Measure_CCSUIDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CMy3D_Measure_CCSUIDlg ��Ϣ��������

BOOL CMy3D_Measure_CCSUIDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ����Ӷ���ĳ�ʼ������
	//Acquisition parameters
	//sAcqEasyParam acqEasyParam;
	////Sensor ID
	//MCHR_ID SensorID = NULL;
	//float vel = 0;     

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի���������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy3D_Measure_CCSUIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CMy3D_Measure_CCSUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}