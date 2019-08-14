
// TestDlgDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TestDlg.h"
#include "TestDlgDlg.h"
#include "afxdialogex.h"
#include "GlobalVariable.h"
#include "iostream"
#include <string>
#include <fstream>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestDlgDlg 对话框



CTestDlgDlg::CTestDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestDlgDlg::IDD, pParent)
	, m_operation_time(0)
	, Test_Misson_Number(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MSCOMM1, m_CtrlComm);
	DDX_Control(pDX, IDC_GorgeNumber, m_ComboBox);
	DDX_Control(pDX, IDC_FlashData, m_ListCtrl);
	DDX_Control(pDX, IDC_Operation, m_ListCtrl1);
}

BEGIN_MESSAGE_MAP(CTestDlgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OpenGorge, &CTestDlgDlg::OnBnClickedOpengorge)
//	ON_WM_TIMER()
ON_WM_TIMER()
ON_BN_CLICKED(IDC_SendOrder, &CTestDlgDlg::OnBnClickedSendorder)
ON_BN_CLICKED(IDC_IniMachine, &CTestDlgDlg::OnBnClickedInimachine)
ON_BN_CLICKED(IDC_TM, &CTestDlgDlg::OnBnClickedTm)
ON_BN_CLICKED(IDC_CTNI, &CTestDlgDlg::OnBnClickedCtni)
ON_BN_CLICKED(IDC_IniBJ, &CTestDlgDlg::OnBnClickedInibj)
ON_BN_CLICKED(IDC_Loop, &CTestDlgDlg::OnBnClickedLoop)

ON_BN_CLICKED(IDC_ClearAll, &CTestDlgDlg::OnBnClickedClearall)
ON_BN_CLICKED(IDC_PCT, &CTestDlgDlg::OnBnClickedPct)
ON_BN_CLICKED(IDC_33Second, &CTestDlgDlg::OnBnClicked33second)
ON_BN_CLICKED(IDC_180Second, &CTestDlgDlg::OnBnClicked180second)
ON_BN_CLICKED(IDC_Pause, &CTestDlgDlg::OnBnClickedPause)
ON_BN_CLICKED(IDC_Start, &CTestDlgDlg::OnBnClickedStart)
ON_BN_CLICKED(IDC_HCV, &CTestDlgDlg::OnBnClickedHcv)
ON_BN_CLICKED(IDC_HIV, &CTestDlgDlg::OnBnClickedHiv)
ON_BN_CLICKED(IDC_HBsAb, &CTestDlgDlg::OnBnClickedHbsab)
ON_BN_CLICKED(IDC_HBcAb, &CTestDlgDlg::OnBnClickedHbcab)
ON_BN_CLICKED(IDC_HBeAb, &CTestDlgDlg::OnBnClickedHbeab)
ON_BN_CLICKED(IDC_PCT_Whole, &CTestDlgDlg::OnBnClickedPctWhole)
ON_BN_CLICKED(IDC_CTNI_Whole, &CTestDlgDlg::OnBnClickedCtniWhole)
ON_BN_CLICKED(IDC_VD, &CTestDlgDlg::OnBnClickedVd)
ON_BN_CLICKED(IDC_SAA, &CTestDlgDlg::OnBnClickedSaa)
ON_BN_CLICKED(IDC_PIC, &CTestDlgDlg::OnBnClickedPic)
END_MESSAGE_MAP()


// CTestDlgDlg 消息处理程序

BOOL CTestDlgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	GetDlgItem(IDC_Start)->EnableWindow(false);

	CString str[] = { TEXT("序号"), TEXT("测光值") };
	CString str1[] = { TEXT("序号"), TEXT("项目名称"),TEXT("样本号"),TEXT("试剂船号") };
	
	m_ListCtrl.InsertColumn(0, str[0]);
	m_ListCtrl.InsertColumn(1, str[1]);
	m_ListCtrl.SetColumnWidth(0, 50);
	m_ListCtrl.SetColumnWidth(1, LVSCW_AUTOSIZE_USEHEADER);
	m_ListCtrl.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP | LVS_EX_ONECLICKACTIVATE | LVS_EX_GRIDLINES);
	
	m_ListCtrl1.InsertColumn(0, str1[0]);
	m_ListCtrl1.InsertColumn(1, str1[1]);
	m_ListCtrl1.InsertColumn(2, str1[2]);
	m_ListCtrl1.InsertColumn(3, str1[3]);
	m_ListCtrl1.SetColumnWidth(0, 50);
	m_ListCtrl1.SetColumnWidth(1, LVSCW_AUTOSIZE_USEHEADER);
	m_ListCtrl1.SetColumnWidth(2, 50);
	m_ListCtrl1.SetColumnWidth(3, LVSCW_AUTOSIZE_USEHEADER);
	m_ListCtrl1.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP | LVS_EX_ONECLICKACTIVATE | LVS_EX_GRIDLINES);
	
	m_ListCtrl.InsertItem(0, _T("1"));
	m_ListCtrl.InsertItem(1, _T("2"));
	m_ListCtrl.InsertItem(2, _T("3"));
	m_ListCtrl.InsertItem(3, _T("4"));
	m_ListCtrl.InsertItem(4, _T("5"));
	m_ListCtrl.InsertItem(5, _T("6"));
	m_ListCtrl.InsertItem(6, _T("7"));
	m_ListCtrl.InsertItem(7, _T("8"));
	m_ListCtrl.InsertItem(8, _T("9"));
	m_ListCtrl.InsertItem(9, _T("10"));
	m_ListCtrl.InsertItem(10, _T("11"));
	m_ListCtrl.InsertItem(11, _T("12"));
	m_ListCtrl.InsertItem(12, _T("13"));
	m_ListCtrl.InsertItem(13, _T("14"));
	m_ListCtrl.InsertItem(14, _T("15"));
	m_ListCtrl.InsertItem(15, _T("16"));
	m_ListCtrl.InsertItem(16, _T("17"));
	m_ListCtrl.InsertItem(17, _T("18"));
	m_ListCtrl.InsertItem(18, _T("19"));
	m_ListCtrl.InsertItem(19, _T("20"));
	m_ListCtrl.InsertItem(20, _T("21"));
	m_ListCtrl.InsertItem(21, _T("22"));
	m_ListCtrl.InsertItem(22, _T("23"));
	m_ListCtrl.InsertItem(23, _T("24"));
	m_ListCtrl.InsertItem(24, _T("25"));
	m_ListCtrl.InsertItem(25, _T("26"));
	m_ListCtrl.InsertItem(26, _T("27"));
	m_ListCtrl.InsertItem(27, _T("28"));
	m_ListCtrl.InsertItem(28, _T("29"));
	m_ListCtrl.InsertItem(29, _T("30"));
	m_ListCtrl.InsertItem(30, _T("31"));
	m_ListCtrl.InsertItem(31, _T("32"));
	m_ListCtrl.InsertItem(32, _T("33"));
	m_ListCtrl.InsertItem(33, _T("34"));
	m_ListCtrl.InsertItem(34, _T("35"));
	m_ListCtrl.InsertItem(35, _T("36"));
	m_ListCtrl.InsertItem(36, _T("37"));
	m_ListCtrl.InsertItem(37, _T("38"));
	m_ListCtrl.InsertItem(38, _T("39"));
	m_ListCtrl.InsertItem(39, _T("40"));
	m_ListCtrl.InsertItem(40, _T("41"));
	m_ListCtrl.InsertItem(41, _T("42"));
	m_ListCtrl.InsertItem(42, _T("43"));
	m_ListCtrl.InsertItem(43, _T("44"));
	m_ListCtrl.InsertItem(44, _T("45"));
	m_ListCtrl.InsertItem(45, _T("46"));
	m_ListCtrl.InsertItem(46, _T("47"));
	m_ListCtrl.InsertItem(47, _T("48"));
	m_ListCtrl.InsertItem(48, _T("49"));
	m_ListCtrl.InsertItem(49, _T("50"));
	m_ListCtrl.InsertItem(50, _T("51"));
	m_ListCtrl.InsertItem(51, _T("52"));
	m_ListCtrl.InsertItem(52, _T("53"));
	m_ListCtrl.InsertItem(53, _T("54"));
	m_ListCtrl.InsertItem(54, _T("55"));
	m_ListCtrl.InsertItem(55, _T("56"));
	m_ListCtrl.InsertItem(56, _T("57"));
	m_ListCtrl.InsertItem(57, _T("58"));
	m_ListCtrl.InsertItem(58, _T("59"));
	m_ListCtrl.InsertItem(59, _T("60"));
	m_ListCtrl.InsertItem(60, _T("61"));
	m_ListCtrl.InsertItem(61, _T("62"));
	m_ListCtrl.InsertItem(62, _T("63"));
	m_ListCtrl.InsertItem(63, _T("64"));
	m_ListCtrl.InsertItem(64, _T("65"));
	m_ListCtrl.InsertItem(65, _T("66"));
	m_ListCtrl.InsertItem(66, _T("67"));
	m_ListCtrl.InsertItem(67, _T("68"));
	m_ListCtrl.InsertItem(68, _T("69"));
	m_ListCtrl.InsertItem(69, _T("70"));
	m_ListCtrl.InsertItem(70, _T("71"));
	m_ListCtrl.InsertItem(71, _T("72"));
	m_ListCtrl.InsertItem(72, _T("73"));
	m_ListCtrl.InsertItem(73, _T("74"));
	m_ListCtrl.InsertItem(74, _T("75"));
	m_ListCtrl.InsertItem(75, _T("76"));
	m_ListCtrl.InsertItem(76, _T("77"));
	m_ListCtrl.InsertItem(77, _T("78"));
	m_ListCtrl.InsertItem(78, _T("79"));
	m_ListCtrl.InsertItem(79, _T("80"));
	m_ListCtrl.InsertItem(80, _T("81"));
	m_ListCtrl.InsertItem(81, _T("82"));
	m_ListCtrl.InsertItem(82, _T("83"));
	m_ListCtrl.InsertItem(83, _T("84"));
	m_ListCtrl.InsertItem(84, _T("85"));
	m_ListCtrl.InsertItem(85, _T("86"));
	m_ListCtrl.InsertItem(86, _T("87"));
	m_ListCtrl.InsertItem(87, _T("88"));
	m_ListCtrl.InsertItem(88, _T("89"));
	m_ListCtrl.InsertItem(89, _T("90"));
	m_ListCtrl.InsertItem(90, _T("91"));
	m_ListCtrl.InsertItem(91, _T("92"));
	m_ListCtrl.InsertItem(92, _T("93"));
	m_ListCtrl.InsertItem(93, _T("94"));
	m_ListCtrl.InsertItem(94, _T("95"));
	m_ListCtrl.InsertItem(95, _T("96"));
	m_ListCtrl.InsertItem(96, _T("97"));
	m_ListCtrl.InsertItem(97, _T("98"));
	m_ListCtrl.InsertItem(98, _T("99"));
	m_ListCtrl.InsertItem(99, _T("100"));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTestDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTestDlgDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTestDlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestDlgDlg::OnBnClickedOpengorge()
{
	// TODO:  在此添加控件通知处理程序代码
	int m_Index;
	switch (m_CtrlComm.get_PortOpen())
	{
	case 0:
		m_Index = ((CComboBox*)GetDlgItem(IDC_GorgeNumber))->GetCurSel();
		m_CtrlComm.put_CommPort(m_Index + 1);
		m_CtrlComm.put_PortOpen(TRUE);

		if (m_CtrlComm.get_PortOpen())
		{
			SetDlgItemText(IDC_OpenGorge, _T("关闭串口"));
			m_CtrlComm.put_Settings(_T("115200,n,8,1"));
			m_CtrlComm.put_InputMode(1);

			m_CtrlComm.put_RThreshold(1);
			m_CtrlComm.put_InputLen(0);
		}
		else
			AfxMessageBox(_T("串口打开失败"));
		break;
	case 1:
		m_CtrlComm.put_PortOpen(FALSE);
		KillTimer(1);
		if (!m_CtrlComm.get_PortOpen())
		{
			SetDlgItemText(IDC_OpenGorge, _T("打开串口"));
		}
		else
			AfxMessageBox(_T("串口关闭失败"));
		break;
	default:
		AfxMessageBox(_T("cannot open Serial Port"));
		break;
	}
	//m_ComboBox.SetCurSel(m_Index);
}


void CTestDlgDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 1)
	{
		CString m_operation_time_str;
		m_operation_time_str.Format(_T("%d"), m_operation_time);
		SetDlgItemText(IDC_CurrentTime, m_operation_time_str);

		while (true)
		{
			
			
			if (xy[5][m_ybg_time] == 0 || xy[5][m_ybg_time + 1] == 0)
			{
				m_ybg_time++;
				continue;
			}
			else if (xy[5][m_operation_time] != 0)
				m_ybg_time = m_operation_time;
			
			break;
		}
		m_ybg_residue_time = m_ybg_time - m_operation_time;
		m_ybg_residue_time_str.Format(_T("%d"), m_ybg_residue_time);
		SetDlgItemText(IDC_YBG_Residue, m_ybg_residue_time_str);

		int xy_id_moto[2] = { 0 };
		for (int i = 1; i < 35; i++)
		{
			if (i == 34)
			{
				if (xy[i][m_operation_time] != 0)
					TestNumber = xy[i][m_operation_time];
				continue;
			}
			if (xy[i][m_operation_time] != 0)
			{
				if ((xy[i][m_operation_time] != 77) && (xy[i][m_operation_time] != 88))
				{
					Transform2id(i, xy_id_moto);
					CByteArray hexdata;
					hexdata.RemoveAll();
					hexdata.Add(170);
					hexdata.Add(xy_id_moto[0]);
					hexdata.Add(xy_id_moto[1]);
					hexdata.Add(xy[i][m_operation_time]);
					hexdata.Add(187);
					m_CtrlComm.put_Output(COleVariant(hexdata));

					Sleep(10);

					if (i == 33)
					{
						if (xy[i][m_operation_time] == 3)
						{
							g_i = 0;
							g[10] = { 0 };
						}
					}
				}
			}
		}
		m_operation_time++;
		if (operation_all_over(m_operation_time) == 1)
		{
			KillTimer(1);
			m_operation_time = 0;
			AfxMessageBox(_T("operation completed!"));
		}
	}
	CDialogEx::OnTimer(nIDEvent);
}

void CTestDlgDlg::Transform2id(int row, int(&motoid)[2])
{
	switch (row)
	{
	case 1:
		motoid[0] = 1;
		motoid[1] = 0;
		break;
	case 2:
		motoid[0] = 1;
		motoid[1] = 1;
		break;
	case 3:
		motoid[0] = 1;
		motoid[1] = 2;
		break;
	case 4:
		motoid[0] = 2;
		motoid[1] = 2;
		break;
	case 5:
		motoid[0] = 2;
		motoid[1] = 1;
		break;
	case 6:
		motoid[0] = 2;
		motoid[1] = 0;
		break;
	case 7:
		motoid[0] = 3;
		motoid[1] = 0;
		break;
	case 8:
		motoid[0] = 3;
		motoid[1] = 1;
		break;
	case 9:
		motoid[0] = 3;
		motoid[1] = 2;
		break;
	case 10:
		motoid[0] = 4;
		motoid[1] = 0;
		break;
	case 11:
		motoid[0] = 4;
		motoid[1] = 1;
		break;
	case 12:
		motoid[0] = 5;
		motoid[1] = 2;
		break;
	case 13:
		motoid[0] = 5;
		motoid[1] = 1;
		break;
	case 14:
		motoid[0] = 5;
		motoid[1] = 0;
		break;
	case 15:
		motoid[0] = 10;
		motoid[1] = 2;
		break;
	case 16:
		motoid[0] = 7;
		motoid[1] = 0;
		break;
	case 17:
		motoid[0] = 7;
		motoid[1] = 1;
		break;
	case 18:
		motoid[0] = 7;
		motoid[1] = 2;
		break;
	case 19:
		motoid[0] = 7;
		motoid[1] = 3;
		break;
	case 20:
		motoid[0] = 11;
		motoid[1] = 0;
		break;
	case 21:
		motoid[0] = 11;
		motoid[1] = 1;
		break;
	case 22:
		motoid[0] = 11;
		motoid[1] = 5;
		break;
	case 23:
		motoid[0] = 11;
		motoid[1] = 4;
		break;
	case 24:
		motoid[0] = 14;
		motoid[1] = 1;
		break;
	case 25:
		motoid[0] = 14;
		motoid[1] = 2;
		break;
	case 26:
		motoid[0] = 13;
		motoid[1] = 0;
		break;
	case 27:
		motoid[0] = 13;
		motoid[1] = 1;
		break;
	case 28:
		motoid[0] = 13;
		motoid[1] = 2;
		break;
	case 29:
		motoid[0] = 12;
		motoid[1] = 0;
		break;
	case 30:
		motoid[0] = 12;
		motoid[1] = 1;
		break;
	case 31:
		motoid[0] = 12;
		motoid[1] = 2;
		break;
	case 32:
		motoid[0] = 12;
		motoid[1] = 3;
		break;
	case 33:
		motoid[0] = 10;
		motoid[1] = 6;
		break;
	default:
		break;
	}
}

int CTestDlgDlg::operation_all_over(int after_time)
{
	for (int i = after_time; i < 100000; i++)
	{
		for (int j = 0; j < 70; j++)
		{
			if (xy[j][i] != 0) return 0;
		}
	}
	return 1;
}


void CTestDlgDlg::OnBnClickedSendorder()
{
	// TODO:  在此添加控件通知处理程序代码
	SetTimer(1, 1000, NULL);
	m_operation_time = 0;
}


void CTestDlgDlg::OnBnClickedInimachine()
{
	// TODO:  在此添加控件通知处理程序代码
	for (int i = 0; i < 70; i++)
	{
		for (int j = 0; j < 100000; j++)
			xy[i][j] = 0;
	}

	xy[1][0] = 55;
	xy[2][3] = 55;
	xy[3][0] = 55;
	xy[4][0] = 55;
	xy[5][3] = 55;
	xy[6][0] = 55;
	xy[7][1] = 55;
	xy[8][1] = 55;
	xy[9][2] = 55;
	xy[10][0] = 55;
	xy[11][4] = 55;
	xy[12][4] = 55;
	xy[13][5] = 55;
	xy[14][0] = 55;
	xy[15][6] = 55;

	//灌注试剂针和样本针
	//试剂针和样本针下降
	xy[3][7] = 02;
	xy[4][7] = 02;
	//打开V01,V02,V04阀
	xy[27][7] = 01;
	xy[20][7] = 01;
	xy[31][7] = 01;
	//泵吸0.5s,灌注样本针内壁
	xy[21][8] = 05;
	//关闭V02
	xy[20][9] = 55;
	//泵吸0.5s,灌注样本针外壁
	xy[21][10] = 05;
	//关闭V04
	xy[31][11] = 55;

	//关闭V01
	xy[27][12] = 55;
	//打开V03,V05
	xy[30][12] = 01;
	xy[32][12] = 01;
	//泵吸0.5s,灌注试剂针内壁
	xy[21][13] = 05;
	//关闭V03
	xy[30][14] = 55;
	//泵吸0.5s，灌注试剂针外壁
	xy[21][15] = 05;
	//关闭V05
	xy[32][16] = 55;
	//试剂针，样本针抬起
	xy[3][17] = 55;
	xy[4][17] = 55;

	//灌注磁分离
	xy[14][12] = 02;
	xy[26][12] = 55;
	xy[19][13] = 20;
	xy[26][15] = 01;
	xy[19][16] = 55;

	xy[24][12] = 55;
	xy[25][12] = 55;
	xy[16][13] = 10;
	xy[24][15] = 01;
	xy[25][15] = 01;
	xy[16][16] = 55;

	xy[24][17] = 55;
	xy[25][17] = 55;
	xy[14][18] = 55;
}


//int CTestDlgDlg::Loop(int mission_NO, int FY_time1, int FY_time2, int SampleNO, int Reagent_Bin_NO,
//	int R1_location_NO, int R4_Location_NO, int stir_times)
//{
//	//控制变量
//	bool unfinished = true;
//	int adjust_time = 0;
//
//	//取杯相关变量
//	int starttime = 0;
//	int BJ_is_empty = 0;
//	int BJ_need_changerow = 0;
//	int BJ_changerow_time = 0;
//	int BJ_cupNO = 0;
//	int QB_JZ_starttime = 0;
//	int QB_JZ_code_length = 0;
//	int QB_JZ_code[3][100] = { 0 };
//	int QB_time = 0;
//	int FYP_putcup_time = 0;
//	int QB_FYP_starttime = 0;
//	int QB_FYP_use_holeNO = 0;
//	int QB_FYP_code[50] = { 0 };
//	int QB_FYP_code_length = 0;
//	int QB_finished_time = 0;
//
//	//第一次加试剂相关变量
//	int add_reagent1_stattime = 0;
//	bool intNeed_To_Attenuation = false;
//	int add_reagent1_real_starttime = 0;
//	int FYP_add_reagent1_time = 0;
//	int FYP_add_reagent1_starttime = 0;
//	int addSJ_FYP_occupytime = 0;
//	int add_reagent1_code[8][100] = { 0 };
//	int add_reagent1_code_length = 0;
//	int add_reagent1_FYP_code[50] = { 0 };
//	int add_reagent1_FYP_code_length = 0;
//
//	//加样本相关变量
//	int sample_stattime = 0;
//	int add_sample_real_starttime = 0;
//	int FYP_add_sample_time = 0;
//	int FYP_add_sample_starttime = 0;
//	int add_sample_FYP_occupytime = 0;
//	int add_sample_code[8][100] = { 0 };
//	int add_sample_code_length = 0;
//	int add_sample_FYP_code[50] = { 0 };
//	int add_sample_FYP_code_length = 0;
//
//	//搅拌1相关变量
//	int mix1_stattime = 0;
//	int add_mix1_real_starttime = 0;
//	int FYP_add_mix1_time = 0;
//	int FYP_add_mix1_starttime = 0;
//	int add_mix1_FYP_occupytime = 0;
//	int add_mix1_code[8][100] = { 0 };
//	int add_mix1_code_length = 0;
//	int add_mix1_FYP_code[50] = { 0 };
//	int add_mix1_FYP_code_length = 0;
//
//	//第一次进磁分离相关变量
//	int add_mix1_FYP_finished_time = 0;
//	int FYP_out_time1 = 0;
//	int FYP2CFL_real_starttime1 = 0;
//	int FYP2CFL_JZ_starttime1 = 0;
//	int FYP2CFL_JZ_code1[3][100] = { 0 };
//	int FYP2CFL_JZ_code_length1 = 0;
//	int FYP2CFL_FYP_starttime1 = 0;
//	int FYP2CFL_FYP_code1[50] = { 0 };
//	int FYP2CFL_FYP_code_length1 = 0;
//	int CFL_hole_NO1 = 0;
//	int FYP2CFL_CFL_arrive_time1 = 0;
//
//	//磁分离到孵育盘相关变量
//	int CFL2FYP_starttime = 0;
//	int CFL2FYP_real_starttime = 0;
//	int CFL2FYP_JZ_starttime = 0;
//	int CFL2FYP_JZ_code[3][100] = { 0 };
//	int CFL2FYP_JZ_code_length = 0;
//	int CFL2FYP_FYP_arrive_time = 0;
//	int CFL2FYP_FYP_holeNO = 0;
//	int CFL2FYP_FYP_starttime = 0;
//	int CFL2FYP_FYP_code[50] = { 0 };
//	int CFL2FYP_FYP_code_length = 0;
//
//	//第二次加试剂相关变量
//	int addR4_time = 0;
//	int add_reagent4_stattime = 0;
//	int add_reagent4_real_starttime = 0;
//	int FYP_add_reagent4_time = 0;
//	int FYP_add_reagent4_starttime = 0;
//	int addSJ_FYP_occupytime4 = 0;
//	int add_reagent4_code[8][100] = { 0 };
//	int add_reagent4_code_length = 0;
//	int add_reagent4_FYP_code[50] = { 0 };
//	int add_reagent4_FYP_code_length = 0;
//
//	//搅拌2相关变量
//	int mix2_stattime = 0;
//	int add_mix2_real_starttime = 0;
//	int FYP_add_mix2_time = 0;
//	int FYP_add_mix2_starttime = 0;
//	int add_mix2_FYP_occupytime = 0;
//	int add_mix2_code[8][100] = { 0 };
//	int add_mix2_code_length = 0;
//	int add_mix2_FYP_code[50] = { 0 };
//	int add_mix2_FYP_code_length = 0;
//
//	//第二次进磁分离相关变量
//	int add_mix2_FYP_finished_time = 0;
//	int second2CFL_time = 0;
//	int FYP2CFL_real_starttime2 = 0;
//	int FYP2CFL_JZ_starttime2 = 0;
//	int FYP2CFL_JZ_code2[3][100] = { 0 };
//	int FYP2CFL_JZ_code_length2 = 0;
//	int FYP2CFL_FYP_starttime2 = 0;
//	int FYP2CFL_FYP_code2[50] = { 0 };
//	int FYP2CFL_FYP_code_length2 = 0;
//	int CFL_hole_NO2 = 0;
//	int FYP2CFL_CFL_arrive_time2 = 0;
//
//	//磁分离进振荡器相关变量
//	int CFL2ZDQ_starttime = 0;
//	int CFL2ZDQ_real_starttime = 0;
//	int CFL2ZDQ_JZ_starttime = 0;
//	int CFL2ZDQ_JZ_code[3][100] = { 0 };
//	int CFL2ZDQ_JZ_code_length = 0;
//	int CFL2ZDQ_ZDQ_arrive_time = 0;
//	int CFL2ZDQ_hole_NO = 0;
//
//	//振荡器进杯架相关变量
//	int ZDQ2BJ_starttime = 0;
//	int ZDQ2BJ_real_starttime = 0;
//	int ZDQ2BJ_JZ_starttime = 0;
//	int ZDQ2BJ_JZ_code[3][100] = { 0 };
//	int ZDQ2BJ_JZ_code_length = 0;
//	int ZDQ2BJ_BJ_arrive_time = 0;
//
//	qb(starttime,BJ_is_empty, BJ_need_changerow, BJ_changerow_time, BJ_cupNO, QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code,
//		QB_time, FYP_putcup_time, QB_FYP_starttime, QB_FYP_use_holeNO, QB_FYP_code, QB_FYP_code_length, QB_finished_time);
//	add_reagent1_stattime = QB_finished_time + FYP_ActionTime - (GSJG_UpDown_Time + GSJG_Move_Time + GSJG_UpDown_Time +
//		GPump_In_Out_Time + GSJG_UpDown_Time + GSJG_Move_Time + 1);
//	while (unfinished)
//	{
//		add_reagent1_stattime += adjust_time;
//		add_reagent(add_reagent1_stattime, QB_FYP_use_holeNO, R1_location_NO, Reagent_Bin_NO, intNeed_To_Attenuation, 0,
//			add_reagent1_real_starttime, FYP_add_reagent1_time, addSJ_FYP_occupytime, add_reagent1_code, add_reagent1_code_length,
//			add_reagent1_FYP_code, add_reagent1_FYP_code_length, FYP_add_reagent1_starttime);
//
//		adjust_time = add_reagent1_real_starttime - add_reagent1_stattime;
//		if (adjust_time > 0)
//			continue;
//
//		sample_stattime = add_reagent1_real_starttime + add_reagent1_code_length - 2 * GP01_Open_WashInside_Time - GP01_Open_WashOutside_Time - GSJG_UpDown_Time - GSJG_Move_Time;
//		add_sample(sample_stattime, QB_FYP_use_holeNO, SampleNO, stir_times, add_sample_real_starttime, FYP_add_sample_time,
//			FYP_add_sample_starttime, add_sample_FYP_occupytime, add_sample_code, add_sample_code_length, add_sample_FYP_code,
//			add_sample_FYP_code_length);
//
//		adjust_time = add_sample_real_starttime - sample_stattime;
//		if (adjust_time > 0)
//			continue;
//
//		mix1_stattime = add_sample_real_starttime + add_sample_code_length;
//		add_sample(mix1_stattime, QB_FYP_use_holeNO, SampleNO, 1, add_mix1_real_starttime, FYP_add_mix1_time,
//			FYP_add_mix1_starttime, add_mix1_FYP_occupytime, add_mix1_code, add_mix1_code_length, add_mix1_FYP_code,
//			add_mix1_FYP_code_length);
//
//		adjust_time = add_mix1_real_starttime - mix1_stattime;
//		if (adjust_time > 0)
//			continue;
//
//		add_mix1_FYP_finished_time = FYP_add_mix1_starttime + add_mix1_FYP_code_length;
//		FYP_out_time1 = add_mix1_FYP_finished_time + FY_time1;
//		FYP2CFL(FYP_out_time1, QB_FYP_use_holeNO, FYP2CFL_real_starttime1, FYP2CFL_JZ_starttime1, FYP2CFL_JZ_code1, FYP2CFL_JZ_code_length1,
//			FYP2CFL_FYP_starttime1, FYP2CFL_FYP_code1, FYP2CFL_FYP_code_length1, CFL_hole_NO1, FYP2CFL_CFL_arrive_time1);
//
//		adjust_time = FYP2CFL_real_starttime1 - FYP_out_time1;
//		if (adjust_time > 0)
//			continue;
//
//		CFL2FYP_starttime = (FYP2CFL_CFL_arrive_time1 / 17 + 24) * 17 + 2;
//		CFL2FYP(CFL2FYP_starttime, CFL2FYP_real_starttime, CFL2FYP_JZ_starttime, CFL2FYP_JZ_code, CFL2FYP_JZ_code_length,
//			CFL2FYP_FYP_arrive_time, CFL2FYP_FYP_holeNO, CFL2FYP_FYP_starttime, CFL2FYP_FYP_code, CFL2FYP_FYP_code_length);
//
//		adjust_time = CFL2FYP_real_starttime - CFL2FYP_starttime;
//		if (adjust_time > 0)
//			continue;
//
//		addR4_time = CFL2FYP_FYP_starttime + CFL2FYP_FYP_code_length + FYP_ActionTime;
//		add_reagent4_stattime = addR4_time - (GSJG_UpDown_Time + GSJG_Move_Time + GSJG_UpDown_Time
//			+ GPump_In_Out_Time + GSJG_UpDown_Time + GSJG_Move_Time + 1);
//		add_reagent(add_reagent4_stattime, CFL2FYP_FYP_holeNO, R4_Location_NO, Reagent_Bin_NO, intNeed_To_Attenuation, 0,
//			add_reagent4_real_starttime, FYP_add_reagent4_time, addSJ_FYP_occupytime4, add_reagent4_code, add_reagent4_code_length,
//			add_reagent4_FYP_code, add_reagent4_FYP_code_length, FYP_add_reagent4_starttime);
//
//		adjust_time = add_reagent4_real_starttime - add_reagent4_stattime;
//		if (adjust_time > 0)
//			continue;
//
//		mix2_stattime = add_reagent4_real_starttime + add_reagent4_code_length - 2 * GP01_Open_WashInside_Time - GP01_Open_WashOutside_Time;
//		add_sample(mix2_stattime, CFL2FYP_FYP_holeNO, SampleNO, 1, add_mix2_real_starttime, FYP_add_mix2_time,
//			FYP_add_mix2_starttime, add_mix2_FYP_occupytime, add_mix2_code, add_mix2_code_length, add_mix2_FYP_code,
//			add_mix2_FYP_code_length);
//
//		adjust_time = add_mix2_real_starttime - mix2_stattime;
//		if (adjust_time > 0)
//			continue;
//
//		add_mix2_FYP_finished_time = FYP_add_mix2_starttime + add_mix2_FYP_code_length;
//		second2CFL_time = add_mix2_FYP_finished_time + FY_time2;
//		FYP2CFL(second2CFL_time, CFL2FYP_FYP_holeNO, FYP2CFL_real_starttime2, FYP2CFL_JZ_starttime2,
//			FYP2CFL_JZ_code2, FYP2CFL_JZ_code_length2, FYP2CFL_FYP_starttime2, FYP2CFL_FYP_code2,
//			FYP2CFL_FYP_code_length2, CFL_hole_NO2, FYP2CFL_CFL_arrive_time2);
//
//		adjust_time = FYP2CFL_real_starttime2 - second2CFL_time;
//		if (adjust_time > 0)
//			continue;
//
//		CFL2ZDQ_starttime = (FYP2CFL_CFL_arrive_time2 / 17 + 24) * 17 + 2;//待两圈
//		CFL2ZDQ(CFL2ZDQ_starttime, CFL2ZDQ_real_starttime, CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code,
//			CFL2ZDQ_JZ_code_length, CFL2ZDQ_ZDQ_arrive_time, CFL2ZDQ_hole_NO);
//
//		adjust_time = CFL2ZDQ_real_starttime - CFL2ZDQ_starttime;
//		if (adjust_time > 12)
//			continue;
//
//		ZDQ2BJ_starttime = CFL2ZDQ_ZDQ_arrive_time + 148;//测试在振荡器待148s
//		ZDQ2BJ(ZDQ2BJ_starttime, ZDQ2BJ_real_starttime, CFL2ZDQ_hole_NO, ZDQ2BJ_JZ_starttime,
//			ZDQ2BJ_JZ_code, ZDQ2BJ_JZ_code_length, ZDQ2BJ_BJ_arrive_time, BJ_cupNO);
//
//		adjust_time = ZDQ2BJ_real_starttime - ZDQ2BJ_starttime;
//		if (adjust_time > 0)
//			continue;
//		unfinished = false;
//	}
//
//
//	//添加操作代码及孔占用代码
//	//取杯代码
//	add_code.add_JZ_move_code(QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code);
//	add_code.add_FYP_move_code(QB_FYP_starttime, QB_FYP_code_length, QB_FYP_code);
//	//加试剂1代码
//	add_code.add_SJ_code(add_reagent1_real_starttime, add_reagent1_code_length, add_reagent1_code);
//	add_code.add_FYP_move_code(FYP_add_reagent1_starttime, add_reagent1_FYP_code_length, add_reagent1_FYP_code);
//	//加样本代码
//	add_code.add_sample_code(add_sample_real_starttime, add_sample_code_length, add_sample_code);
//	add_code.add_FYP_move_code(FYP_add_sample_starttime, add_sample_FYP_code_length, add_sample_FYP_code);
//	//搅拌1代码
//	add_code.add_mix_code(add_mix1_real_starttime, add_mix1_code_length, add_mix1_code);
//	add_code.add_FYP_move_code(add_mix1_real_starttime + GYBG_UpDown_Time, add_mix1_FYP_code_length, add_mix1_FYP_code);
//	//孵育盘到磁分离代码
//	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime1, FYP2CFL_JZ_code_length1, FYP2CFL_JZ_code1);
//	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime1, FYP2CFL_FYP_code_length1, FYP2CFL_FYP_code1);
//	add_code.add_FYP_hole_occupy(QB_FYP_use_holeNO, FYP_putcup_time, FYP_out_time1);//孵育盘孔第一次占用
//	//磁分离到孵育盘代码
//	add_code.add_JZ_move_code(CFL2FYP_JZ_starttime, CFL2FYP_JZ_code_length, CFL2FYP_JZ_code);
//	add_code.add_FYP_move_code(CFL2FYP_FYP_starttime, CFL2FYP_FYP_code_length, CFL2FYP_FYP_code);
//	add_code.add_CFL_hole_occupy(CFL_hole_NO1, FYP2CFL_CFL_arrive_time1, CFL2FYP_starttime);//磁分离孔第一次占用
//	//加试剂4代码
//	add_code.add_SJ_code(add_reagent4_real_starttime, add_reagent4_code_length, add_reagent4_code);
//	add_code.add_FYP_move_code(FYP_add_reagent4_starttime, add_reagent4_FYP_code_length, add_reagent4_FYP_code);
//	//搅拌2代码
//	add_code.add_mix_code(add_mix2_real_starttime, add_mix2_code_length, add_mix2_code);
//	add_code.add_FYP_move_code(add_mix2_real_starttime + GYBG_UpDown_Time, add_mix2_FYP_code_length, add_mix2_FYP_code);
//	//孵育盘到磁分离第二次代码
//	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime2, FYP2CFL_JZ_code_length2, FYP2CFL_JZ_code2);
//	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime2, FYP2CFL_FYP_code_length2, FYP2CFL_FYP_code2);
//	add_code.add_FYP_hole_occupy(CFL2FYP_FYP_holeNO, CFL2FYP_FYP_arrive_time, second2CFL_time);//孵育盘孔第二次占用
//	//磁分离到振荡器代码
//	add_code.add_JZ_move_code(CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code_length, CFL2ZDQ_JZ_code);
//	add_code.add_CFL_hole_occupy(CFL_hole_NO2, FYP2CFL_CFL_arrive_time2, CFL2ZDQ_starttime);//磁分离孔第二次占用
//	//振荡器到光检测代码
//	add_code.add_JZ_move_code(ZDQ2BJ_JZ_starttime, ZDQ2BJ_JZ_code_length, ZDQ2BJ_JZ_code);
//	add_code.add_ZDQ_hole_occupy(CFL2ZDQ_hole_NO, CFL2ZDQ_ZDQ_arrive_time, ZDQ2BJ_starttime);//振荡器孔占用
//
//	//振荡器振动
//	add_code.add_ZDQ_motor_code();
//	//磁分离转动
//	add_code.add_CFL_move_code(ZDQ2BJ_starttime + 100, cfl_CFLcyclesteptime);
//
//
//
//
//	//添加磁分离注射排液底物代码
//	int length = 0;
//	int zhushe1_time = 0;
//	int paiye1_time = 0;
//	int zhushe2_time = 0;
//	int paiye2_time = 0;
//	int diwu_time = 0;
//	int CFLcode1[8][30] = { 0 };
//	int CFLcode2[8][30] = { 0 };
//	int CFLcode3[8][30] = { 0 };
//	int CFLcode4[8][30] = { 0 };
//	int CFLcode5[8][30] = { 0 };
//	cfl.CFLzhushe1codegenerate(CFLcode1, length);
//	cfl.CFLpaiye1codegenerate(CFLcode2, length);
//	cfl.CFLzhushe2codegenerate(CFLcode3, length);
//	cfl.CFLpaiye2codegenerate(CFLcode4, length);
//	cfl.CFLdiwucodegenerate(CFLcode5, length);
//	//第一圈
//	zhushe1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 2) * 17 + 1;
//	paiye1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 5) * 17 + 1;
//	zhushe2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 6) * 17 + 1;
//	paiye2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 9) * 17 + 1;
//	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
//	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
//	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
//	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
//	//第二圈
//	zhushe1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 2 + 12) * 17 + 1;
//	paiye1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 5 + 12) * 17 + 1;
//	zhushe2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 6 + 12) * 17 + 1;
//	paiye2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 9 + 12) * 17 + 1;
//	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
//	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
//	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
//	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
//	//第三圈
//	zhushe1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 2) * 17 + 1;
//	paiye1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 5) * 17 + 1;
//	zhushe2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 6) * 17 + 1;
//	paiye2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 9) * 17 + 1;
//	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
//	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
//	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
//	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
//	//第四圈
//	zhushe1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 2 + 12) * 17 + 1;
//	paiye1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 5 + 12) * 17 + 1;
//	zhushe2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 6 + 12) * 17 + 1;
//	paiye2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 9 + 12) * 17 + 1;
//	diwu_time = (FYP2CFL_CFL_arrive_time2 / 17 + 10 + 12) * 17 + 1;
//	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
//	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
//	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
//	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
//	add_code.add_CFL_operation_code(diwu_time, length, CFLcode5);
//
//	return 0;
//}


void CTestDlgDlg::OnBnClickedTm()
{
	// TODO:  在此添加控件通知处理程序代码
	CString SampleNO, Reagent_Bin_NO;
	GetDlgItemText(IDC_SampleNO, SampleNO);
	GetDlgItemText(IDC_Reagent_Bin_NO, Reagent_Bin_NO);

	if (GBJ_Content[8][0]==0)
	{
		MessageBox(_T("请先初始化杯架！"));
		return;
	}

	if (m_operation_time == 0)
		m_qb_starttime = 0;
	else
		m_qb_starttime = m_operation_time + 5;

	pro.TM(clistctrl_number + 1, _ttoi(SampleNO), _ttoi(Reagent_Bin_NO), 0, 3, m_qb_starttime,300,300);
	
	if (GBJ_Content[8][0] == 0)
		SetDlgItemText(IDC_BJState, _T("当前杯架无杯，待操作完成后停机更换！"));
	

	CString TotalTime_str, TotalTime_str_Current;
	GetDlgItemText(IDC_TotalTime, TotalTime_str_Current);
	if (totaltime>_ttoi(TotalTime_str_Current))
	{
		TotalTime_str.Format(_T("%d"), totaltime);
		SetDlgItemText(IDC_TotalTime, TotalTime_str);
	}
	
	CString ComputerNO;
	ComputerNO.Format(_T("%d"), clistctrl_number+1);
	m_ListCtrl1.InsertItem(clistctrl_number, ComputerNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 1, _T("TM"));
	m_ListCtrl1.SetItemText(clistctrl_number, 2, SampleNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 3, Reagent_Bin_NO);
	clistctrl_number++;




	/*fstream out;
	out.open("C:\\Users\\欧尼酱\\Desktop\\improcess.csv", ios::app);
	out << totaltime << endl;*/

	/*fstream out;
	out.open("C:\\Users\\欧尼酱\\Desktop\\TestData.csv", ios::out);
	for (int m = 1; m < 70; m++)
	{
		for (int n = 0; n < 4000; n++)
		{
			out << xy[m][n] << ",";
		}
		out << endl;
	}*/
}


void CTestDlgDlg::OnBnClickedCtni()
{
	// TODO:  在此添加控件通知处理程序代码
	CString SampleNO1, Reagent_Bin_NO1;
	GetDlgItemText(IDC_SampleNO, SampleNO1);
	GetDlgItemText(IDC_Reagent_Bin_NO, Reagent_Bin_NO1);
	
	if (GBJ_Content[8][0] == 0)
	{
		MessageBox(_T("请先初始化杯架！"));
		return;
	}

	if (m_operation_time == 0)
		m_qb_starttime = 0;
	else
		m_qb_starttime = m_operation_time + 5;

	pro.CTNI(clistctrl_number + 1, _ttoi(SampleNO1), _ttoi(Reagent_Bin_NO1), 0, 2, 3, m_qb_starttime,306);
	
	if (GBJ_Content[8][0] == 0)
		SetDlgItemText(IDC_BJState, _T("当前杯架无杯，待操作完成后停机更换！"));

	CString TotalTime_str, TotalTime_str_Current;
	GetDlgItemText(IDC_TotalTime, TotalTime_str_Current);
	if (totaltime>_ttoi(TotalTime_str_Current))
	{
		TotalTime_str.Format(_T("%d"), totaltime);
		SetDlgItemText(IDC_TotalTime, TotalTime_str);
	}

	CString ComputerNO;
	ComputerNO.Format(_T("%d"), clistctrl_number+1);
	m_ListCtrl1.InsertItem(clistctrl_number, ComputerNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 1, _T("CTNI"));
	m_ListCtrl1.SetItemText(clistctrl_number, 2, SampleNO1);
	m_ListCtrl1.SetItemText(clistctrl_number, 3, Reagent_Bin_NO1);
	clistctrl_number++;

	/*fstream out;
	out.open("C:\\Users\\欧尼酱\\Desktop\\TestData.csv", ios::out);
	for (int m = 1; m < 70; m++)
	{
		for (int n = 0; n < 4000; n++)
		{
			out << xy[m][n] << ",";
		}
		out << endl;
	}*/
}


void CTestDlgDlg::OnBnClickedInibj()
{
	// TODO:  在此添加控件通知处理程序代码
	for (int i = 0; i<9; i++)
	{
		for (int j = 0; j<7; j++)
		{
			GBJ_Content[i][j] = 1;
		}
	}
	GBJ_Current_Row = 0;
	GBJ_Rows = 9;
	GBJ_cols = 7;
	GCurrent_Cup_position_Col = 6;
	GCurrent_Cup_position_Row = 0;
	GRemian_Cup_Numbers = 9 * 7;

	for (int m = 0; m < 70; m++)
	{
		for (int n = 0; n < 100000; n++)
			xy[m][n] = 0;
	}
	xy[33][0] = 4;
	xy[33][1] = 5;
	SetDlgItemText(IDC_YBG_Residue, _T(""));
	SetDlgItemText(IDC_BJState, _T(""));
	m_ybg_residue_time = 0;
}


void CTestDlgDlg::OnBnClickedLoop()
{
	// TODO:  在此添加控件通知处理程序代码
	//for (int m = 0; m < 70; m++)
	//{
	//	for (int n = 0; n < 100000; n++)
	//		xy[m][n] = 0;
	//}
	//add_code.add_CFL_move_code(3000, 17);

	//Loop(1, 300, 300, 5, 6, 1, 4, 0);
	//Loop(2, 300, 300, 5, 6, 2, 3, 0);
	//Loop(3, 300, 300, 5, 6, 2, 3, 0);
	//Loop(4, 300, 300, 5, 6, 2, 3, 0);
	//Loop(5, 300, 300, 5, 6, 2, 3, 0);
	//Loop(6, 300, 300, 5, 6, 2, 3, 0);
	//Loop(7, 300, 300, 5, 6, 2, 3, 0);

	///*fstream out;
	//out.open("C:\\Users\\欧尼酱\\Desktop\\TestData.csv", ios::out);
	//for (int m = 1; m < 70; m++)
	//{
	//	for (int n = 0; n < 4000; n++)
	//	{
	//		out << xy[m][n] << ",";
	//	}
	//	out << endl;
	//}*/
}
BEGIN_EVENTSINK_MAP(CTestDlgDlg, CDialogEx)
	ON_EVENT(CTestDlgDlg, IDC_MSCOMM1, 1, CTestDlgDlg::OnCommMscomm1, VTS_NONE)
END_EVENTSINK_MAP()


void CTestDlgDlg::OnCommMscomm1()
{
	// TODO:  在此处添加消息处理程序代码
	Sleep(20);
	VARIANT variant_inp;
	COleSafeArray safearry_inp;
	LONG len, k;
	BYTE rxdata[2048];
	CString strtemp;
	CString temp;
	if (m_CtrlComm.get_CommEvent() == 2)
	{

		variant_inp = m_CtrlComm.get_Input();//将接收缓冲区数据放入VARIANT结构体中
		safearry_inp = variant_inp;//把返回值存放在安全数组里
		len = safearry_inp.GetOneDimSize();//数据一共有多少字节
		for (k = 0; k < len; k++)
		{
			safearry_inp.GetElement(&k, rxdata + k);//把安全数组里的数据转移到字节数组buf中，方便打印
		}
		rxdata[len] = 0;//防止乱码
		for (k = 0; k < len; k++)
		{
			BYTE bt = *(char*)(rxdata + k);
			strtemp.Format(_T("%02X"), bt);//X表示以16进制读取bt数值,02表示不足两位前面补0
		}

		//寻找"AA"开始,每12个字节拦截一次
		LONG m = 0;
		while (m<len)
		{
			BYTE x[4];
			safearry_inp.GetElement(&m, x + 0);
			if (x[0] != 170)
			{
				m++;
				continue;
			}
			if (m + 11 >= len)
				break;

			LONG m1 = m + 1;
			LONG m2 = m + 10;
			LONG m3 = m + 11;
			safearry_inp.GetElement(&m1, x + 1);
			safearry_inp.GetElement(&m2, x + 2);
			safearry_inp.GetElement(&m3, x + 3);
			if (x[1] != 170 || x[2] != 187 || x[3] != 187)
			{
				m++;
				continue;
			}

			BYTE a[12];
			int n = m;
			int i = 0;
			for (m; m < n + 12; m++)
			{
				safearry_inp.GetElement(&m, a + i);
				i++;
			}
			//过滤出光检测0A板6号电机
			if (a[2] == 10 && a[3] == 6)
			{
				CString t[4];
				t[0].Format(_T("%d"), a[4]);
				t[1].Format(_T("%d"), a[5]);
				t[2].Format(_T("%d"), a[6]);
				t[3].Format(_T("%d"), a[7]);
				int h[4];
				h[0] = _ttoi(t[0]);
				h[1] = _ttoi(t[1]);
				h[2] = _ttoi(t[2]);
				h[3] = _ttoi(t[3]);
				g[g_i] = h[0] * pow(256, 3) + h[1] * pow(256, 2) + h[2] * pow(256, 1) + h[3] * pow(256, 0);
				int g_i_count;
				g_i_count = g_i + 1;
				CString GJCPacket_g_i, FGZ_temp;
				GJCPacket_g_i.Format(_T("%d"), g_i_count);
				SetDlgItemText(IDC_GJCPacket, GJCPacket_g_i);
				g_i++;

				if (g_i)
				{
					for (int i = 0; i < g_i; i++)
					{
						g_average += g[i];
					}
					g_average = g_average / g_i;
					CString g_averageTemp;
					g_averageTemp.Format(_T("%I64d"), g_average);
					//g_i = 0;
					g_average = 0;

					switch (TestNumber)
					{
					case 1:
						SetDlgItemText(IDC_OneTest, g_averageTemp);
						m_ListCtrl.SetItemText(0, 1,g_averageTemp);
						break;
					case 2:
						SetDlgItemText(IDC_TwoTest, g_averageTemp);
						m_ListCtrl.SetItemText(1, 1, g_averageTemp);
						break;
					case 3:
						SetDlgItemText(IDC_ThreeTset, g_averageTemp);
						m_ListCtrl.SetItemText(2, 1, g_averageTemp);
						break;
					case 4:
						SetDlgItemText(IDC_FourTest, g_averageTemp);
						m_ListCtrl.SetItemText(3, 1, g_averageTemp);
						break;
					case 5:
						SetDlgItemText(IDC_FiveTest, g_averageTemp);
						m_ListCtrl.SetItemText(4, 1, g_averageTemp);
						break;
					case 6:
						SetDlgItemText(IDC_OneTest6, g_averageTemp);
						m_ListCtrl.SetItemText(5, 1, g_averageTemp);
						break;
					case 7:
						SetDlgItemText(IDC_TwoTest7, g_averageTemp);
						m_ListCtrl.SetItemText(6, 1, g_averageTemp);
						break;
					case 8:
						SetDlgItemText(IDC_ThreeTset8, g_averageTemp);
						m_ListCtrl.SetItemText(7, 1, g_averageTemp);
						break;
					case 9:
						SetDlgItemText(IDC_FourTest9, g_averageTemp);
						m_ListCtrl.SetItemText(8, 1, g_averageTemp);
						break;
					case 10:
						SetDlgItemText(IDC_FiveTest10, g_averageTemp);
						m_ListCtrl.SetItemText(9, 1, g_averageTemp);
						break;
					case 11:
						m_ListCtrl.SetItemText(10, 1, g_averageTemp);
						break;
					case 12:
						m_ListCtrl.SetItemText(11, 1, g_averageTemp);
						break;
					case 13:
						m_ListCtrl.SetItemText(12, 1, g_averageTemp);
						break;
					case 14:
						m_ListCtrl.SetItemText(13, 1, g_averageTemp);
						break;
					case 15:
						m_ListCtrl.SetItemText(14, 1, g_averageTemp);
						break;
					case 16:
						m_ListCtrl.SetItemText(15, 1, g_averageTemp);
						break;
					case 17:
						m_ListCtrl.SetItemText(16, 1, g_averageTemp);
						break;
					case 18:
						m_ListCtrl.SetItemText(17, 1, g_averageTemp);
						break;
					case 19:
						m_ListCtrl.SetItemText(18, 1, g_averageTemp);
						break;
					case 20:
						m_ListCtrl.SetItemText(19, 1, g_averageTemp);
						break;
					case 21:
						m_ListCtrl.SetItemText(20, 1, g_averageTemp);
						break;
					case 22:
						m_ListCtrl.SetItemText(21, 1, g_averageTemp);
						break;
					case 23:
						m_ListCtrl.SetItemText(22, 1, g_averageTemp);
						break;
					case 24:
						m_ListCtrl.SetItemText(23, 1, g_averageTemp);
						break;
					case 25:
						m_ListCtrl.SetItemText(24, 1, g_averageTemp);
						break;
					case 26:
						m_ListCtrl.SetItemText(25, 1, g_averageTemp);
						break;
					case 27:
						m_ListCtrl.SetItemText(26, 1, g_averageTemp);
						break;
					case 28:
						m_ListCtrl.SetItemText(27, 1, g_averageTemp);
						break;
					case 29:
						m_ListCtrl.SetItemText(28, 1, g_averageTemp);
						break;
					case 30:
						m_ListCtrl.SetItemText(29, 1, g_averageTemp);
						break;
					case 31:
						m_ListCtrl.SetItemText(30, 1, g_averageTemp);
						break;
					case 32:
						m_ListCtrl.SetItemText(31, 1, g_averageTemp);
						break;
					case 33:
						m_ListCtrl.SetItemText(32, 1, g_averageTemp);
						break;
					case 34:
						m_ListCtrl.SetItemText(33, 1, g_averageTemp);
						break;
					case 35:
						m_ListCtrl.SetItemText(34, 1, g_averageTemp);
						break;
					case 36:
						m_ListCtrl.SetItemText(35, 1, g_averageTemp);
						break;
					case 37:
						m_ListCtrl.SetItemText(36, 1, g_averageTemp);
						break;
					case 38:
						m_ListCtrl.SetItemText(37, 1, g_averageTemp);
						break;
					case 39:
						m_ListCtrl.SetItemText(38, 1, g_averageTemp);
						break;
					case 40:
						m_ListCtrl.SetItemText(39, 1, g_averageTemp);
						break;
					case 41:
						m_ListCtrl.SetItemText(40, 1, g_averageTemp);
						break;
					case 42:
						m_ListCtrl.SetItemText(41, 1, g_averageTemp);
						break;
					case 43:
						m_ListCtrl.SetItemText(42, 1, g_averageTemp);
						break;
					case 44:
						m_ListCtrl.SetItemText(43, 1, g_averageTemp);
						break;
					case 45:
						m_ListCtrl.SetItemText(44, 1, g_averageTemp);
						break;
					case 46:
						m_ListCtrl.SetItemText(45, 1, g_averageTemp);
						break;
					case 47:
						m_ListCtrl.SetItemText(46, 1, g_averageTemp);
						break;
					case 48:
						m_ListCtrl.SetItemText(47, 1, g_averageTemp);
						break;
					case 49:
						m_ListCtrl.SetItemText(48, 1, g_averageTemp);
						break;
					case 50:
						m_ListCtrl.SetItemText(49, 1, g_averageTemp);
						break;
					case 51:
						m_ListCtrl.SetItemText(50, 1, g_averageTemp);
						break;
					case 52:
						m_ListCtrl.SetItemText(51, 1, g_averageTemp);
						break;
					case 53:
						m_ListCtrl.SetItemText(52, 1, g_averageTemp);
						break;
					case 54:
						m_ListCtrl.SetItemText(53, 1, g_averageTemp);
						break;
					case 55:
						m_ListCtrl.SetItemText(54, 1, g_averageTemp);
						break;
					case 56:
						m_ListCtrl.SetItemText(55, 1, g_averageTemp);
						break;
					case 57:
						m_ListCtrl.SetItemText(56, 1, g_averageTemp);
						break;
					case 58:
						m_ListCtrl.SetItemText(57, 1, g_averageTemp);
						break;
					case 59:
						m_ListCtrl.SetItemText(58, 1, g_averageTemp);
						break;
					case 60:
						m_ListCtrl.SetItemText(59, 1, g_averageTemp);
						break;
					case 61:
						m_ListCtrl.SetItemText(60, 1, g_averageTemp);
						break;
					case 62:
						m_ListCtrl.SetItemText(61, 1, g_averageTemp);
						break;
					case 63:
						m_ListCtrl.SetItemText(62, 1, g_averageTemp);
						break;
					case 64:
						m_ListCtrl.SetItemText(63, 1, g_averageTemp);
						break;
					case 65:
						m_ListCtrl.SetItemText(64, 1, g_averageTemp);
						break;
					case 66:
						m_ListCtrl.SetItemText(65, 1, g_averageTemp);
						break;
					case 67:
						m_ListCtrl.SetItemText(66, 1, g_averageTemp);
						break;
					case 68:
						m_ListCtrl.SetItemText(67, 1, g_averageTemp);
						break;
					case 69:
						m_ListCtrl.SetItemText(68, 1, g_averageTemp);
						break;
					case 70:
						m_ListCtrl.SetItemText(69, 1, g_averageTemp);
						break;
					case 71:
						m_ListCtrl.SetItemText(70, 1, g_averageTemp);
						break;
					case 72:
						m_ListCtrl.SetItemText(71, 1, g_averageTemp);
						break;
					case 73:
						m_ListCtrl.SetItemText(72, 1, g_averageTemp);
						break;
					case 74:
						m_ListCtrl.SetItemText(73, 1, g_averageTemp);
						break;
					case 75:
						m_ListCtrl.SetItemText(74, 1, g_averageTemp);
						break;
					case 76:
						m_ListCtrl.SetItemText(75, 1, g_averageTemp);
						break;
					case 77:
						m_ListCtrl.SetItemText(76, 1, g_averageTemp);
						break;
					case 78:
						m_ListCtrl.SetItemText(77, 1, g_averageTemp);
						break;
					case 79:
						m_ListCtrl.SetItemText(78, 1, g_averageTemp);
						break;
					case 80:
						m_ListCtrl.SetItemText(79, 1, g_averageTemp);
						break;
					case 81:
						m_ListCtrl.SetItemText(80, 1, g_averageTemp);
						break;
					case 82:
						m_ListCtrl.SetItemText(81, 1, g_averageTemp);
						break;
					case 83:
						m_ListCtrl.SetItemText(82, 1, g_averageTemp);
						break;
					case 84:
						m_ListCtrl.SetItemText(83, 1, g_averageTemp);
						break;
					case 85:
						m_ListCtrl.SetItemText(84, 1, g_averageTemp);
						break;
					case 86:
						m_ListCtrl.SetItemText(85, 1, g_averageTemp);
						break;
					case 87:
						m_ListCtrl.SetItemText(86, 1, g_averageTemp);
						break;
					case 88:
						m_ListCtrl.SetItemText(87, 1, g_averageTemp);
						break;
					case 89:
						m_ListCtrl.SetItemText(88, 1, g_averageTemp);
						break;
					case 90:
						m_ListCtrl.SetItemText(89, 1, g_averageTemp);
						break;
					case 91:
						m_ListCtrl.SetItemText(90, 1, g_averageTemp);
						break;
					case 92:
						m_ListCtrl.SetItemText(91, 1, g_averageTemp);
						break;
					case 93:
						m_ListCtrl.SetItemText(92, 1, g_averageTemp);
						break;
					case 94:
						m_ListCtrl.SetItemText(93, 1, g_averageTemp);
						break;
					case 95:
						m_ListCtrl.SetItemText(94, 1, g_averageTemp);
						break;
					case 96:
						m_ListCtrl.SetItemText(95, 1, g_averageTemp);
						break;
					case 97:
						m_ListCtrl.SetItemText(96, 1, g_averageTemp);
						break;
					case 98:
						m_ListCtrl.SetItemText(97, 1, g_averageTemp);
						break;
					case 99:
						m_ListCtrl.SetItemText(98, 1, g_averageTemp);
						break;
					case 100:
						m_ListCtrl.SetItemText(99, 1, g_averageTemp);
						break;
					default:
						break;
					}

				}
			}
			/*for (int j = 0; j < 12; j++)
			{
				BYTE bt = *(char*)(a + j);
				temp.Format(_T("%02X"), bt);
				m_strRXDData += temp;
			}
			m_strRXDData += "\r\n";*/
		}

		//SetDlgItemText(IDC_EDIT2_RXD, m_strRXDData);
	}
}


void CTestDlgDlg::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CTestDlgDlg::OnBnClickedClearall()
{
	// TODO:  在此添加控件通知处理程序代码
	for (int i = 0; i < 70; i++)
	{
		for (int j = 0; j < 100000; j++)
			xy[i][j] = 0;
	}
	clistctrl_number = 0;
	m_ListCtrl1.DeleteAllItems();
}


void CTestDlgDlg::OnBnClickedPct()
{
	// TODO:  在此添加控件通知处理程序代码
	CString SampleNO, Reagent_Bin_NO;
	GetDlgItemText(IDC_SampleNO, SampleNO);
	GetDlgItemText(IDC_Reagent_Bin_NO, Reagent_Bin_NO);

	if (GBJ_Content[8][0] == 0)
	{
		MessageBox(_T("请先初始化杯架！"));
		return;
	}

	if (m_operation_time == 0)
		m_qb_starttime = 0;
	else
		m_qb_starttime = m_operation_time + 5;

	pro.PCT(clistctrl_number + 1, _ttoi(SampleNO), _ttoi(Reagent_Bin_NO), 0, 3, m_qb_starttime,301);

	if (GBJ_Content[8][0] == 0)
		SetDlgItemText(IDC_BJState, _T("当前杯架无杯，待操作完成后停机更换！"));

	CString TotalTime_str, TotalTime_str_Current;
	GetDlgItemText(IDC_TotalTime, TotalTime_str_Current);
	if (totaltime>_ttoi(TotalTime_str_Current))
	{
		TotalTime_str.Format(_T("%d"), totaltime);
		SetDlgItemText(IDC_TotalTime, TotalTime_str);
	}

	CString ComputerNO;
	ComputerNO.Format(_T("%d"), clistctrl_number + 1);
	m_ListCtrl1.InsertItem(clistctrl_number, ComputerNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 1, _T("PCT"));
	m_ListCtrl1.SetItemText(clistctrl_number, 2, SampleNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 3, Reagent_Bin_NO);
	clistctrl_number++;

	/*fstream out;
	out.open("C:\\Users\\欧尼酱\\Desktop\\TestData.csv", ios::out);
	for (int m = 1; m < 70; m++)
	{
		for (int n = 0; n < 4000; n++)
		{
			out << xy[m][n] << ",";
		}
		out << endl;
	}*/
}


void CTestDlgDlg::OnBnClicked33second()
{
	// TODO:  在此添加控件通知处理程序代码
	for (int i = 0; i < 33; i+=6)
	{
		xy[1][i] = 40;
		xy[1][i+1] = 77;
		xy[1][i+2] = 88;
		xy[1][i+3] = 20;
		xy[1][i+4] = 77;
		xy[1][i+5] = 88;
	}
	xy[1][36] = 55;
	xy[1][37] = 77;
	xy[1][38] = 88;
}


void CTestDlgDlg::OnBnClicked180second()
{
	// TODO:  在此添加控件通知处理程序代码
	for (int i = 0; i < 180; i += 6)
	{
		xy[1][i] = 40;
		xy[1][i + 1] = 77;
		xy[1][i + 2] = 88;
		xy[1][i + 3] = 20;
		xy[1][i + 4] = 77;
		xy[1][i + 5] = 88;
	}
	xy[1][180] = 55;
	xy[1][181] = 77;
	xy[1][182] = 88;
}


void CTestDlgDlg::OnBnClickedPause()
{
	// TODO:  在此添加控件通知处理程序代码
	KillTimer(1);
	GetDlgItem(IDC_Start)->EnableWindow(true);
	GetDlgItem(IDC_Pause)->EnableWindow(false);
}


void CTestDlgDlg::OnBnClickedStart()
{
	// TODO:  在此添加控件通知处理程序代码
	SetTimer(1, 1000, NULL);
	GetDlgItem(IDC_Start)->EnableWindow(false);
	GetDlgItem(IDC_Pause)->EnableWindow(true);
}




void CTestDlgDlg::OnBnClickedHcv()
{
	// TODO:  在此添加控件通知处理程序代码
	CString SampleNO, Reagent_Bin_NO;
	GetDlgItemText(IDC_SampleNO, SampleNO);
	GetDlgItemText(IDC_Reagent_Bin_NO, Reagent_Bin_NO);

	if (GBJ_Content[8][0] == 0)
	{
		MessageBox(_T("请先初始化杯架！"));
		return;
	}

	if (m_operation_time == 0)
		m_qb_starttime = 0;
	else
		m_qb_starttime = m_operation_time + 5;

	pro.HCV(clistctrl_number + 1, _ttoi(SampleNO), _ttoi(Reagent_Bin_NO), 0, 1, 3, m_qb_starttime,900,600);

	if (GBJ_Content[8][0] == 0)
		SetDlgItemText(IDC_BJState, _T("当前杯架无杯，待操作完成后停机更换！"));

	CString TotalTime_str, TotalTime_str_Current;
	GetDlgItemText(IDC_TotalTime, TotalTime_str_Current);
	if (totaltime>_ttoi(TotalTime_str_Current))
	{
		TotalTime_str.Format(_T("%d"), totaltime);
		SetDlgItemText(IDC_TotalTime, TotalTime_str);
	}

	CString ComputerNO;
	ComputerNO.Format(_T("%d"), clistctrl_number + 1);
	m_ListCtrl1.InsertItem(clistctrl_number, ComputerNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 1, _T("HCV"));
	m_ListCtrl1.SetItemText(clistctrl_number, 2, SampleNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 3, Reagent_Bin_NO);
	clistctrl_number++;

	/*fstream out;
	out.open("C:\\Users\\欧尼酱\\Desktop\\TestData.csv", ios::out);
	for (int m = 1; m < 70; m++)
	{
		for (int n = 0; n < 4000; n++)
			{
				out << xy[m][n] << ",";
			}
		out << endl;
	}*/
}


void CTestDlgDlg::OnBnClickedHiv()
{
	// TODO:  在此添加控件通知处理程序代码
	CString SampleNO, Reagent_Bin_NO;
	GetDlgItemText(IDC_SampleNO, SampleNO);
	GetDlgItemText(IDC_Reagent_Bin_NO, Reagent_Bin_NO);

	if (GBJ_Content[8][0] == 0)
	{
		MessageBox(_T("请先初始化杯架！"));
		return;
	}

	if (m_operation_time == 0)
		m_qb_starttime = 0;
	else
		m_qb_starttime = m_operation_time + 5;

	pro.HIV(clistctrl_number + 1, _ttoi(SampleNO), _ttoi(Reagent_Bin_NO), 0, 1, 3, m_qb_starttime,300,303);

	if (GBJ_Content[8][0] == 0)
		SetDlgItemText(IDC_BJState, _T("当前杯架无杯，待操作完成后停机更换！"));

	CString TotalTime_str, TotalTime_str_Current;
	GetDlgItemText(IDC_TotalTime, TotalTime_str_Current);
	if (totaltime>_ttoi(TotalTime_str_Current))
	{
		TotalTime_str.Format(_T("%d"), totaltime);
		SetDlgItemText(IDC_TotalTime, TotalTime_str);
	}

	CString ComputerNO;
	ComputerNO.Format(_T("%d"), clistctrl_number + 1);
	m_ListCtrl1.InsertItem(clistctrl_number, ComputerNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 1, _T("HIV"));
	m_ListCtrl1.SetItemText(clistctrl_number, 2, SampleNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 3, Reagent_Bin_NO);
	clistctrl_number++;

	/*fstream out;
	out.open("C:\\Users\\欧尼酱\\Desktop\\TestData.csv", ios::out);
	for (int m = 1; m < 70; m++)
	{
		for (int n = 0; n < 4000; n++)
		{
			out << xy[m][n] << ",";
		}
		out << endl;
	}*/
}


void CTestDlgDlg::OnBnClickedHbsab()
{
	// TODO:  在此添加控件通知处理程序代码
	CString SampleNO, Reagent_Bin_NO;
	GetDlgItemText(IDC_SampleNO, SampleNO);
	GetDlgItemText(IDC_Reagent_Bin_NO, Reagent_Bin_NO);

	if (GBJ_Content[8][0] == 0)
	{
		MessageBox(_T("请先初始化杯架！"));
		return;
	}

	if (m_operation_time == 0)
		m_qb_starttime = 0;
	else
		m_qb_starttime = m_operation_time + 5;

	pro.HBsAb(clistctrl_number + 1, _ttoi(SampleNO), _ttoi(Reagent_Bin_NO), 0, 3, m_qb_starttime,600,600);

	if (GBJ_Content[8][0] == 0)
		SetDlgItemText(IDC_BJState, _T("当前杯架无杯，待操作完成后停机更换！"));


	CString TotalTime_str, TotalTime_str_Current;
	GetDlgItemText(IDC_TotalTime, TotalTime_str_Current);
	if (totaltime>_ttoi(TotalTime_str_Current))
	{
		TotalTime_str.Format(_T("%d"), totaltime);
		SetDlgItemText(IDC_TotalTime, TotalTime_str);
	}

	CString ComputerNO;
	ComputerNO.Format(_T("%d"), clistctrl_number + 1);
	m_ListCtrl1.InsertItem(clistctrl_number, ComputerNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 1, _T("HBsAb"));
	m_ListCtrl1.SetItemText(clistctrl_number, 2, SampleNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 3, Reagent_Bin_NO);
	clistctrl_number++;
}


void CTestDlgDlg::OnBnClickedHbcab()
{
	// TODO:  在此添加控件通知处理程序代码
	CString SampleNO, Reagent_Bin_NO;
	GetDlgItemText(IDC_SampleNO, SampleNO);
	GetDlgItemText(IDC_Reagent_Bin_NO, Reagent_Bin_NO);

	if (GBJ_Content[8][0] == 0)
	{
		MessageBox(_T("请先初始化杯架！"));
		return;
	}

	if (m_operation_time == 0)
		m_qb_starttime = 0;
	else
		m_qb_starttime = m_operation_time + 5;

	pro.HBcAb(clistctrl_number + 1, _ttoi(SampleNO), _ttoi(Reagent_Bin_NO), 0, 1, 2, m_qb_starttime);

	if (GBJ_Content[8][0] == 0)
		SetDlgItemText(IDC_BJState, _T("当前杯架无杯，待操作完成后停机更换！"));


	CString TotalTime_str, TotalTime_str_Current;
	GetDlgItemText(IDC_TotalTime, TotalTime_str_Current);
	if (totaltime>_ttoi(TotalTime_str_Current))
	{
		TotalTime_str.Format(_T("%d"), totaltime);
		SetDlgItemText(IDC_TotalTime, TotalTime_str);
	}

	CString ComputerNO;
	ComputerNO.Format(_T("%d"), clistctrl_number + 1);
	m_ListCtrl1.InsertItem(clistctrl_number, ComputerNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 1, _T("HBsAb"));
	m_ListCtrl1.SetItemText(clistctrl_number, 2, SampleNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 3, Reagent_Bin_NO);
	clistctrl_number++;
}


void CTestDlgDlg::OnBnClickedHbeab()
{
	// TODO:  在此添加控件通知处理程序代码
	CString SampleNO, Reagent_Bin_NO;
	GetDlgItemText(IDC_SampleNO, SampleNO);
	GetDlgItemText(IDC_Reagent_Bin_NO, Reagent_Bin_NO);

	if (GBJ_Content[8][0] == 0)
	{
		MessageBox(_T("请先初始化杯架！"));
		return;
	}

	if (m_operation_time == 0)
		m_qb_starttime = 0;
	else
		m_qb_starttime = m_operation_time + 5;

	pro.HBeAb(clistctrl_number + 1, _ttoi(SampleNO), _ttoi(Reagent_Bin_NO), 0, 1, 2, m_qb_starttime);

	if (GBJ_Content[8][0] == 0)
		SetDlgItemText(IDC_BJState, _T("当前杯架无杯，待操作完成后停机更换！"));


	CString TotalTime_str, TotalTime_str_Current;
	GetDlgItemText(IDC_TotalTime, TotalTime_str_Current);
	if (totaltime>_ttoi(TotalTime_str_Current))
	{
		TotalTime_str.Format(_T("%d"), totaltime);
		SetDlgItemText(IDC_TotalTime, TotalTime_str);
	}

	CString ComputerNO;
	ComputerNO.Format(_T("%d"), clistctrl_number + 1);
	m_ListCtrl1.InsertItem(clistctrl_number, ComputerNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 1, _T("HBeAb"));
	m_ListCtrl1.SetItemText(clistctrl_number, 2, SampleNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 3, Reagent_Bin_NO);
	clistctrl_number++;
}


void CTestDlgDlg::OnBnClickedPctWhole()
{
	// TODO:  在此添加控件通知处理程序代码
	CString SampleNO, Reagent_Bin_NO, Reagent_Bin_NO1;
	GetDlgItemText(IDC_SampleNO, SampleNO);
	GetDlgItemText(IDC_Reagent_Bin_NO, Reagent_Bin_NO);
	GetDlgItemText(IDC_Reagent_Bin_NO1, Reagent_Bin_NO1);
	
	if (GBJ_Content[8][0] == 0)
	{
		MessageBox(_T("请先初始化杯架！"));
		return;
	}

	if (m_operation_time == 0)
		m_qb_starttime = 0;
	else
		m_qb_starttime = m_operation_time + 5;

	pro.PCT_whole(clistctrl_number + 1, _ttoi(SampleNO), _ttoi(Reagent_Bin_NO), _ttoi(Reagent_Bin_NO1), 0, 3, 0, m_qb_starttime);

	if (GBJ_Content[8][0] == 0)
		SetDlgItemText(IDC_BJState, _T("当前杯架无杯，待操作完成后停机更换！"));


	CString TotalTime_str, TotalTime_str_Current;
	GetDlgItemText(IDC_TotalTime, TotalTime_str_Current);
	if (totaltime>_ttoi(TotalTime_str_Current))
	{
		TotalTime_str.Format(_T("%d"), totaltime);
		SetDlgItemText(IDC_TotalTime, TotalTime_str);
	}

	CString ComputerNO;
	ComputerNO.Format(_T("%d"), clistctrl_number + 1);
	m_ListCtrl1.InsertItem(clistctrl_number, ComputerNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 1, _T("PCT全血"));
	m_ListCtrl1.SetItemText(clistctrl_number, 2, SampleNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 3, Reagent_Bin_NO);
	clistctrl_number++;

	/*fstream out;
	out.open("C:\\Users\\欧尼酱\\Desktop\\TestData.csv", ios::out);
	for (int m = 1; m < 70; m++)
	{
		for (int n = 0; n < 4000; n++)
		{
			out << xy[m][n] << ",";
		}
		out << endl;
	}*/
}


void CTestDlgDlg::OnBnClickedCtniWhole()
{
	// TODO:  在此添加控件通知处理程序代码
	CString SampleNO, Reagent_Bin_NO, Reagent_Bin_NO1;
	GetDlgItemText(IDC_SampleNO, SampleNO);
	GetDlgItemText(IDC_Reagent_Bin_NO, Reagent_Bin_NO);
	GetDlgItemText(IDC_Reagent_Bin_NO1, Reagent_Bin_NO1);
	if (GBJ_Content[8][0] == 0)
	{
		MessageBox(_T("请先初始化杯架！"));
		return;
	}

	if (m_operation_time == 0)
		m_qb_starttime = 0;
	else
		m_qb_starttime = m_operation_time + 5;

	pro.CTNI_whole(clistctrl_number + 1, _ttoi(SampleNO), _ttoi(Reagent_Bin_NO), _ttoi(Reagent_Bin_NO1), 0, 2, 3, 0, m_qb_starttime);

	if (GBJ_Content[8][0] == 0)
		SetDlgItemText(IDC_BJState, _T("当前杯架无杯，待操作完成后停机更换！"));


	CString TotalTime_str, TotalTime_str_Current;
	GetDlgItemText(IDC_TotalTime, TotalTime_str_Current);
	if (totaltime>_ttoi(TotalTime_str_Current))
	{
		TotalTime_str.Format(_T("%d"), totaltime);
		SetDlgItemText(IDC_TotalTime, TotalTime_str);
	}

	CString ComputerNO;
	ComputerNO.Format(_T("%d"), clistctrl_number + 1);
	m_ListCtrl1.InsertItem(clistctrl_number, ComputerNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 1, _T("CTNI全血"));
	m_ListCtrl1.SetItemText(clistctrl_number, 2, SampleNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 3, Reagent_Bin_NO);
	clistctrl_number++;
}


void CTestDlgDlg::OnBnClickedVd()
{
	// TODO:  在此添加控件通知处理程序代码
	CString SampleNO, Reagent_Bin_NO, Reagent_Bin_NO1;
	GetDlgItemText(IDC_SampleNO, SampleNO);
	GetDlgItemText(IDC_Reagent_Bin_NO, Reagent_Bin_NO);
	GetDlgItemText(IDC_Reagent_Bin_NO1, Reagent_Bin_NO1);

	if (GBJ_Content[8][0] == 0)
	{
		MessageBox(_T("请先初始化杯架！"));
		return;
	}

	if (m_operation_time == 0)
		m_qb_starttime = 0;
	else
		m_qb_starttime = m_operation_time + 5;

	pro.VD(clistctrl_number + 1, _ttoi(SampleNO), _ttoi(Reagent_Bin_NO), _ttoi(Reagent_Bin_NO1), 0, 1, 2, 3, 1, m_qb_starttime,900,1200,300);

	if (GBJ_Content[8][0] == 0)
		SetDlgItemText(IDC_BJState, _T("当前杯架无杯，待操作完成后停机更换！"));


	CString TotalTime_str, TotalTime_str_Current;
	GetDlgItemText(IDC_TotalTime, TotalTime_str_Current);
	if (totaltime>_ttoi(TotalTime_str_Current))
	{
		TotalTime_str.Format(_T("%d"), totaltime);
		SetDlgItemText(IDC_TotalTime, TotalTime_str);
	}

	CString ComputerNO;
	ComputerNO.Format(_T("%d"), clistctrl_number + 1);
	m_ListCtrl1.InsertItem(clistctrl_number, ComputerNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 1, _T("VD"));
	m_ListCtrl1.SetItemText(clistctrl_number, 2, SampleNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 3, Reagent_Bin_NO);
	clistctrl_number++;
}


void CTestDlgDlg::OnBnClickedSaa()
{
	// TODO:  在此添加控件通知处理程序代码
	CString SampleNO, Reagent_Bin_NO, Reagent_Bin_NO1;
	GetDlgItemText(IDC_SampleNO, SampleNO);
	GetDlgItemText(IDC_Reagent_Bin_NO, Reagent_Bin_NO);
	GetDlgItemText(IDC_Reagent_Bin_NO1, Reagent_Bin_NO1);

	if (GBJ_Content[8][0] == 0)
	{
		MessageBox(_T("请先初始化杯架！"));
		return;
	}

	if (m_operation_time == 0)
		m_qb_starttime = 0;
	else
		m_qb_starttime = m_operation_time + 5;

	pro.SAA(clistctrl_number + 1, _ttoi(SampleNO), _ttoi(Reagent_Bin_NO), 0, 3, m_qb_starttime);

	if (GBJ_Content[8][0] == 0)
		SetDlgItemText(IDC_BJState, _T("当前杯架无杯，待操作完成后停机更换！"));


	CString TotalTime_str, TotalTime_str_Current;
	GetDlgItemText(IDC_TotalTime, TotalTime_str_Current);
	if (totaltime>_ttoi(TotalTime_str_Current))
	{
		TotalTime_str.Format(_T("%d"), totaltime);
		SetDlgItemText(IDC_TotalTime, TotalTime_str);
	}

	CString ComputerNO;
	ComputerNO.Format(_T("%d"), clistctrl_number + 1);
	m_ListCtrl1.InsertItem(clistctrl_number, ComputerNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 1, _T("SAA"));
	m_ListCtrl1.SetItemText(clistctrl_number, 2, SampleNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 3, Reagent_Bin_NO);
	clistctrl_number++;

	/*fstream out;
	out.open("C:\\Users\\欧尼酱\\Desktop\\TestData.csv", ios::out);
	for (int m = 1; m < 70; m++)
	{
		for (int n = 0; n < 4000; n++)
		{
			out << xy[m][n] << ",";
		}
		out << endl;
	}*/
}


void CTestDlgDlg::OnBnClickedPic()
{
	// TODO:  在此添加控件通知处理程序代码
	CString SampleNO, Reagent_Bin_NO, Reagent_Bin_NO1;
	GetDlgItemText(IDC_SampleNO, SampleNO);
	GetDlgItemText(IDC_Reagent_Bin_NO, Reagent_Bin_NO);
	GetDlgItemText(IDC_Reagent_Bin_NO1, Reagent_Bin_NO1);

	if (GBJ_Content[8][0] == 0)
	{
		MessageBox(_T("请先初始化杯架！"));
		return;
	}

	if (m_operation_time == 0)
		m_qb_starttime = 0;
	else
		m_qb_starttime = m_operation_time + 5;

	pro.PIC(clistctrl_number + 1, _ttoi(SampleNO), _ttoi(Reagent_Bin_NO), 0, 3, m_qb_starttime);

	if (GBJ_Content[8][0] == 0)
		SetDlgItemText(IDC_BJState, _T("当前杯架无杯，待操作完成后停机更换！"));


	CString TotalTime_str, TotalTime_str_Current;
	GetDlgItemText(IDC_TotalTime, TotalTime_str_Current);
	if (totaltime>_ttoi(TotalTime_str_Current))
	{
		TotalTime_str.Format(_T("%d"), totaltime);
		SetDlgItemText(IDC_TotalTime, TotalTime_str);
	}

	CString ComputerNO;
	ComputerNO.Format(_T("%d"), clistctrl_number + 1);
	m_ListCtrl1.InsertItem(clistctrl_number, ComputerNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 1, _T("PIC"));
	m_ListCtrl1.SetItemText(clistctrl_number, 2, SampleNO);
	m_ListCtrl1.SetItemText(clistctrl_number, 3, Reagent_Bin_NO);
	clistctrl_number++;

	//fstream out;
	//out.open("C:\\Users\\欧尼酱\\Desktop\\TestData.csv", ios::out);
	//for (int m = 1; m < 70; m++)
	//{
	//	for (int n = 0; n < 4000; n++)
	//	{
	//		out << xy[m][n] << ",";
	//	}
	//	out << endl;
	//}
}
