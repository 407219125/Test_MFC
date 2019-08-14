
// TestDlgDlg.h : 头文件
//

#pragma once
#include "mscomm1.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "ADD_CODE.h"
#include "BJ.h"
#include "BloodSample.h"
#include "CFL.h"
#include "DDW.h"
#include "FYP.h"
#include "GJC.h"
#include "JZ.h"
#include "Reagent.h"
#include "PLAN.h"
#include "PRO.h"

// CTestDlgDlg 对话框
class CTestDlgDlg : public CDialogEx
{
// 构造
public:
	CTestDlgDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TESTDLG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	BJ bj;
	JZ jz;
	CFL cfl;
	DDW ddw;
	ADD_CODE add_code;
	FYP fyp;
	GJC gjc;
	BloodSamole sample;
	Reagent reagent;
	PLAN plan;
	PRO pro;
	int clistctrl_number = 0;
	int fromstart;
	int fromend;
	int tostart;
	int toend;
	int m_qb_starttime;
	int m_ybg_time = 0;
	int m_ybg_residue_time;
	CString m_ybg_residue_time_str;
	afx_msg void OnBnClickedOpengorge();
	CMscomm1 m_CtrlComm;
	CComboBox m_ComboBox;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedSendorder();
	int m_operation_time;
	void Transform2id(int row, int (&id)[2]);
	int Test_Misson_Number;
	int operation_all_over(int after_time);
	int TestNumber;
	CString FGZ;
	afx_msg void OnBnClickedInimachine();
	CListCtrl m_ListCtrl;
	//int Loop(int mission_NO, int FY_time1, int FY_time2, int SampleNO, int Reagent_Bin_NO,int R1_location_NO, int R4_Location_NO, int stir_times);
	afx_msg void OnBnClickedTm();
	afx_msg void OnBnClickedCtni();
	afx_msg void OnBnClickedInibj();
	afx_msg void OnBnClickedLoop();
	DECLARE_EVENTSINK_MAP()
	void OnCommMscomm1();
	afx_msg void OnEnChangeEdit5();
	CListCtrl m_ListCtrl1;
	afx_msg void OnBnClickedClearall();
	afx_msg void OnBnClickedPct();
	afx_msg void OnBnClicked33second();
	afx_msg void OnBnClicked180second();
	afx_msg void OnBnClickedPause();
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedHcv();
	afx_msg void OnBnClickedHiv();
	afx_msg void OnBnClickedHbsab();
	afx_msg void OnBnClickedHbcab();
	afx_msg void OnBnClickedHbeab();
	afx_msg void OnBnClickedPctWhole();
	afx_msg void OnBnClickedCtniWhole();
	afx_msg void OnBnClickedVd();
	afx_msg void OnBnClickedSaa();
	afx_msg void OnBnClickedPic();
};
