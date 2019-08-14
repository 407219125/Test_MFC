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

	//取杯、试剂1、样本、试剂4、搅拌、FYP2CFL……
	void PCT(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R4_Location_NO, int qb_starttime = 0, int FY_time = 300);
	
	//样本、全血处理液（试剂5）、搅拌1、试剂1、试剂4、搅拌2、孵育、清洗、底物液、震荡、测光
	void PCT_whole(int mission_NO, int SampleNO, int Reagent_Bin_NO, int Second_Reagent_Bin_NO, int R1_location_NO, int R4_Location_NO, int R5_Location_NO, int qb_starttime = 0, int FY_time = 300);

	//取杯、加试剂1、加样本、加试剂3、加试剂4、搅拌、FYP2CFL……
	void CTNI(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R3_Location_NO, int R4_Location_NO, int qb_starttime = 0, int FY_time = 300);

	//样本、全血处理液（试剂5）、搅拌1、试剂1、试剂3、试剂4、搅拌2、孵育、清洗、底物液、震荡、测光
	void CTNI_whole(int mission_NO, int SampleNO, int Reagent_Bin_NO, int Second_Reagent_Bin_NO, int R1_location_NO, int R3_Location_NO, int R4_Location_NO, int R5_Location_NO, int qb_starttime = 0, int FY_time = 300);

	//样本、样本稀释液（试剂0）、搅拌1、换杯、试剂1、试剂4、搅拌2、孵育、清洗、底物液、震荡、测光
	void SAA(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R4_Location_NO, int qb_starttime = 0, int FY_time = 300);

	//样本、样本稀释液（试剂0）、搅拌1、换杯、试剂1、搅拌2、孵育、清洗、试剂4、搅拌3、再孵育、清洗、加底物、震荡、测光
	void PIC(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R4_Location_NO, int qb_starttime = 0, int FY_time1 = 300, int FY_time2 = 300);

	//取杯、试剂1、样本、搅拌1、第一次FYP2CFL、CFL2FYP、试剂4、搅拌2、第二次FYP2CFL……
	void TM(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R4_Location_NO, int qb_starttime = 0, int FY_time1 = 300, int FY_time2 = 300);

	//取杯、试剂1、样本、试剂2、搅拌1、第一次FYP2CFL、CFL2FYP、试剂4、搅拌2、第二次FYP2CFL……
	void HCV(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R2_Location_NO, int R4_Location_NO, int qb_starttime = 0, int FY_time1 = 300, int FY_time2 = 300);

	//试剂4、样本、孵育、试剂1、孵育、清洗、加底物、震荡、测光
	void HBsAb(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R4_Location_NO, int qb_starttime = 0, int FY_time1 = 300, int FY_time2 = 300);


	//试剂3、样本、搅拌1、孵育（不清洗）、试剂2、搅拌2、孵育（不清洗）、试剂1、搅拌3、孵育、清洗、加底物、震荡、测光
	void HBcAb(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R2_Location_NO, int R3_Location_NO, int qb_starttime = 0, int FY_time1 = 300, int FY_time2 = 300, int FY_time3 = 300);

	//试剂3、样本、搅拌、孵育（不清洗）、试剂1、搅拌、再孵育、清洗、试剂2、孵育、清洗、加底物、震荡、测光
	void HBeAb(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R2_Location_NO, int R3_Location_NO, int qb_starttime = 0, int FY_time1 = 300, int FY_time2 = 300, int FY_time3 = 300);

	//样本、试剂4、试剂5、搅拌1、孵育、试剂3、搅拌2、孵育、试剂2、试剂1、搅拌3、孵育、清洗、加底物、震荡、测光
	void VD(int mission_NO, int SampleNO, int Reagent_Bin_NO, int Second_Reagent_Bin_NO, int R1_Location_NO, int R2_Location_NO, int R3_Location_NO, int R4_Location_NO, int R5_Location_NO, int qb_starttime = 0, int FY_time1 = 300, int FY_time2 = 300, int FY_time3 = 300);

	//取杯、试剂1、样本、搅拌1、第一次FYP2CFL、CFL2FYP、试剂2、试剂4、搅拌2、第二次FYP2CFL……
	void HIV(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R2_Location_NO, int R4_Location_NO, int qb_starttime = 0, int FY_time1 = 300, int FY_time2 = 300);

};

