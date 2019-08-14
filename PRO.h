#pragma once
#include "ADD_CODE.h"
#include "PLAN.h"
#include "CONNECT.h"
#include "GlobalVariableState.h"

class PRO
{
public:
	PRO();
	~PRO();

	PLAN plan;
	ADD_CODE add_code;
	CONNECT connect;

	//ȡ�����Լ�1���������Լ�4�����衢FYP2CFL����
	void PCT(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R4_Location_NO, int qb_starttime = 0, int FY_time = 300);
	
	//������ȫѪ����Һ���Լ�5��������1���Լ�1���Լ�4������2����������ϴ������Һ���𵴡����
	void PCT_whole(int mission_NO, int SampleNO, int Reagent_Bin_NO, int Second_Reagent_Bin_NO, int R1_location_NO, int R4_Location_NO, int R5_Location_NO, int qb_starttime = 0, int FY_time = 300);

	//ȡ�������Լ�1�������������Լ�3�����Լ�4�����衢FYP2CFL����
	void CTNI(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R3_Location_NO, int R4_Location_NO, int qb_starttime = 0, int FY_time = 300);

	//������ȫѪ����Һ���Լ�5��������1���Լ�1���Լ�3���Լ�4������2����������ϴ������Һ���𵴡����
	void CTNI_whole(int mission_NO, int SampleNO, int Reagent_Bin_NO, int Second_Reagent_Bin_NO, int R1_location_NO, int R3_Location_NO, int R4_Location_NO, int R5_Location_NO, int qb_starttime = 0, int FY_time = 300);

	//����������ϡ��Һ���Լ�0��������1���������Լ�1���Լ�4������2����������ϴ������Һ���𵴡����
	void SAA(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R4_Location_NO, int qb_starttime = 0, int FY_time = 300);

	//����������ϡ��Һ���Լ�0��������1���������Լ�1������2����������ϴ���Լ�4������3���ٷ�������ϴ���ӵ���𵴡����
	void PIC(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R4_Location_NO, int qb_starttime = 0, int FY_time1 = 300, int FY_time2 = 300);

	//ȡ�����Լ�1������������1����һ��FYP2CFL��CFL2FYP���Լ�4������2���ڶ���FYP2CFL����
	void TM(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R4_Location_NO, int qb_starttime = 0, int FY_time1 = 300, int FY_time2 = 300);

	//ȡ�����Լ�1���������Լ�2������1����һ��FYP2CFL��CFL2FYP���Լ�4������2���ڶ���FYP2CFL����
	void HCV(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R2_Location_NO, int R4_Location_NO, int qb_starttime = 0, int FY_time1 = 300, int FY_time2 = 300);

	//�Լ�4���������������Լ�1����������ϴ���ӵ���𵴡����
	void HBsAb(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R4_Location_NO, int qb_starttime = 0, int FY_time1 = 300, int FY_time2 = 300);


	//�Լ�3������������1������������ϴ�����Լ�2������2������������ϴ�����Լ�1������3����������ϴ���ӵ���𵴡����
	void HBcAb(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R2_Location_NO, int R3_Location_NO, int qb_starttime = 0, int FY_time1 = 300, int FY_time2 = 300, int FY_time3 = 300);

	//�Լ�3�����������衢����������ϴ�����Լ�1�����衢�ٷ�������ϴ���Լ�2����������ϴ���ӵ���𵴡����
	void HBeAb(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R2_Location_NO, int R3_Location_NO, int qb_starttime = 0, int FY_time1 = 300, int FY_time2 = 300, int FY_time3 = 300);

	//�������Լ�4���Լ�5������1���������Լ�3������2���������Լ�2���Լ�1������3����������ϴ���ӵ���𵴡����
	void VD(int mission_NO, int SampleNO, int Reagent_Bin_NO, int Second_Reagent_Bin_NO, int R1_Location_NO, int R2_Location_NO, int R3_Location_NO, int R4_Location_NO, int R5_Location_NO, int qb_starttime = 0, int FY_time1 = 300, int FY_time2 = 300, int FY_time3 = 300);

	//ȡ�����Լ�1������������1����һ��FYP2CFL��CFL2FYP���Լ�2���Լ�4������2���ڶ���FYP2CFL����
	void HIV(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R2_Location_NO, int R4_Location_NO, int qb_starttime = 0, int FY_time1 = 300, int FY_time2 = 300);

};

