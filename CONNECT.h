#pragma once
#include "GlobalVariableState.h"
class CONNECT
{
public:
	CONNECT();
	~CONNECT();

	int reagent_after_qb(int QB_finished_time);

	int reagent_after_reagent(int add_reagent_real_starttime, int add_reagent_code_length);

	int reagent_after_sample(int add_sample_real_starttime, int add_sample_code_length);

	int reagent_after_FYP(int CFL2FYP_FYP_starttime, int CFL2FYP_FYP_code_length);

	int reagent_after_mix(int FYP_add_mix_starttime, int add_mix_FYP_code_length, int FY_time);

	int reagent_after_mix(int add_mix_real_starttime, int add_mix_code_length);

	int sample_after_qb(int QB_finished_time);

	int sample_after_reagent(int add_reagent_real_starttime, int add_reagent_code_length);


	int mix_after_sample(int add_sample_real_starttime, int add_sample_code_length);

	int mix_after_reagent(int add_reagent_real_starttime, int add_reagent_code_length);


	int CFL_after_mix(int FYP_add_mix_starttime, int add_mix_FYP_code_length, int FY_time);

	int FYP_after_CFL(int FYP2CFL_CFL_arrive_time);

	int ZDQ_after_CFL(int FYP2CFL_CFL_arrive_time);

	int GJC_after_ZDG(int CFL2ZDQ_ZDQ_arrive_time);

};

