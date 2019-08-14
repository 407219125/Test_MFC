#pragma once

#include "BJ.h"
#include "JZ.h"
#include "FYP.h"
#include "Reagent.h"
#include "BloodSample.h"
#include "CFL.h"
#include "DDW.h"
#include "GJC.h"
#include "ADD_CODE.h"
#include "GlobalVariableState.h"

class PLAN
{
public:
	PLAN();
	~PLAN();
	//定义各类对象
	BJ bj;
	JZ jz;
	FYP fyp;
	Reagent reagent;
	BloodSamole sample;
	CFL cfl;
	DDW ddw;
	GJC gjc;

	int qb(int qb_starttime, int &BJ_is_empty, int &BJ_need_changerow, int &BJ_changerow_time, int &BJ_cupNO, int &qb_JZ_starttime, int &QB_JZ_Code_Length, int(&QB_JZ_code)[3][100],
		int &qb_time, int &FYP_putcup_time, int &QB_FYP_starttime, int &QB_FYP_use_holeNO, int(&QB_FYP_code)[50], int &QB_FYP_code_length, int &qb_finished_time, int &BJ_NO);
	int check_empety_code_time(int row, int starttime, int code_len, int& adjust_steps);
	int set_BJ_state(int BJstate[9][7]);
	int add_reagent(int project,int starttime, int FYP_hole_NO, int Reagent_Location_NO, int Reagent_Bin_NO, int &add_reagent_real_starttime,
		int &FYP_add_reagent_time, int &FYP_add_reagent_starttime, int &addSJ_FYP_occupytime, int(&add_reagent_code)[8][100], int &add_reagent_code_length, int(&add_reagent_FYP_code)[50],
		int &add_reagent_FYP_code_length);
	int add_sample(int project,int starttime, int FYP_hole_NO, int SampleNO, int &add_sample_real_starttime, int &FYP_add_sample_time, int &FYP_add_sample_starttime, int &add_sample_FYP_occupytime,
		int(&add_sample_code)[8][100], int &add_sample_code_length, int(&add_sample_FYP_code)[50], int &add_sample_FYP_code_length);
	int add_sample_from_cup(int sample_volum,int starttime, int from_FYP_hole_NO, int to_FYP_hole_NO, int& add_sample_from_cup_real_starttime, int&GetSampleFromCupFYPstarttime1, int(&add_sample_from_FYP_code)[50],
		int& add_sample_from_FYP_code_length, int&GetSampleFromCupFYPstarttime2, int(&add_sample_back_FYP_code)[50], int& add_sample_back_FYP_code_length, int& GetSampleFromCupCodeStarttime,
		int(&get_sample_code)[8][100], int& get_sample_code_length, int& add_sample_from_cup_finish_time);
	int mix(int starttime, int FYP_hole_NO, int SampleNO, int &add_mix_real_starttime, int &FYP_add_mix_time, int &FYP_add_mix_starttime, int &add_mix_FYP_occupytime,
		int(&add_mix_code)[8][100], int &add_mix_code_length, int(&add_mix_FYP_code)[50], int &add_mix_FYP_code_length);
	int CFL2FYP(int starttime, int& CFL2FYP_real_starttime, int& CFL2FYP_JZ_starttime,
		int(&CFL2FYP_JZ_code)[3][100], int& CFL2FYP_JZ_code_length, int& CFL2FYP_FYP_arrive_time,
		int& CFL2FYP_FYP_holeNO, int& CFL2FYP_FYP_starttime, int(&CFL2FYP_FYP_code)[50], int& CFL2FYP_FYP_code_length);
	int FYP2GJC(int starttime, int FYP_hole_NO, int& FYP2GJC_real_starttime, int& FYP2GJC_JZ_starttime, int(&FYP2GJC_JZ_code)[3][100],
		int& FYP2GJC_JZ_code_length, int& FYP2GJC_FYP_starttime, int(&FYP2GJC_FYP_code)[50], int& FYP2GJC_FYP_code_length, int& FYP2GJC_GJC_arrive_time);
	void FYP2CFL(int starttime, int FYP_hole_NO, int& FYP2CFL_real_starttime, int& FYP2CFL_JZ_starttime,
		int(&FYP2CFL_JZ_code)[3][100], int &FYP2CFL_JZ_code_length, int &FYP2CFL_FYP_starttime,
		int(&FYP2CFL_FYP_code)[50], int &FYP2CFL_FYP_code_length, int &CFL_hole_NO, int &FYP2FL_CFL_arrive_time);
	int CFL2ZDQ(int starttime, int& CFL2ZDQ_real_starttime, int& CFL2ZDQ_JZ_starttime, int(&CFL2ZDQ_JZ_code)[3][100],
		int& CFL2ZDQ_JZ_code_length, int& CFL2ZDQ_ZDQ_arrive_time, int& CFL2ZDQ_hole_NO);
	int ZDQ2GJC(int starttime, int& ZDQ2GJC_real_starttime, int ZDQ_hole_NO, int& ZDQ2GJC_JZ_starttime, int(&ZDQ2GJC_JZ_code)[3][100],
		int& ZDQ2GJC_JZ_code_length, int& ZDQ2GJC_GJC_arrive_time);
	int ZDQ2BJ(int starttime, int& ZDQ2BJ_real_starttime, int ZDQ_hole_NO, int& ZDQ2BJ_JZ_starttime,
		int(&ZDQ2BJ_JZ_code)[3][100], int& ZDQ2BJ_JZ_code_length, int& ZDQ2BJ_BJ_arrive_time, int BJ_use_NO);
};

