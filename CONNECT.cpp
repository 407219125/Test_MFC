#include "stdafx.h"
#include "CONNECT.h"


CONNECT::CONNECT()
{
}


CONNECT::~CONNECT()
{
}

	int CONNECT::reagent_after_qb(int QB_finished_time)
{
	int starttime = 0;
	starttime = QB_finished_time + FYP_ActionTime - (GSJG_UpDown_Time + GSJG_Move_Time + GSJG_UpDown_Time +
		GPump_In_Out_Time + GSJG_UpDown_Time + GSJG_Move_Time + 1);
	return starttime;
}

	int CONNECT::reagent_after_reagent(int add_reagent_real_starttime, int add_reagent_code_length)
{
	int starttime = 0;
	starttime = add_reagent_real_starttime + add_reagent_code_length;
	return starttime;
}

	int CONNECT::reagent_after_sample(int add_sample_real_starttime, int add_sample_code_length)
{
	int starttime = 0;
	starttime = add_sample_real_starttime + add_sample_code_length - 2 * GP01_Open_WashInside_Time -
		GP01_Open_WashOutside_Time - GYBG_UpDown_Time - 2;
	return starttime;
}

	int CONNECT::reagent_after_FYP(int CFL2FYP_FYP_starttime, int CFL2FYP_FYP_code_length)
{
	int starttime = 0;
	starttime = CFL2FYP_FYP_starttime + CFL2FYP_FYP_code_length + FYP_ActionTime - (GSJG_UpDown_Time + GSJG_Move_Time + GSJG_UpDown_Time
		+ GPump_In_Out_Time + GSJG_UpDown_Time + GSJG_Move_Time + 1);
	return starttime;
}

	int CONNECT::reagent_after_mix(int FYP_add_mix_starttime, int add_mix_FYP_code_length, int FY_time)
	{
		int starttime = 0;
		starttime = FYP_add_mix_starttime + add_mix_FYP_code_length + FY_time;
		return starttime;
	}

	int CONNECT::reagent_after_mix(int add_mix_real_starttime, int add_mix_code_length)
	{
		int starttime = 0;
		starttime = add_mix_real_starttime + add_mix_code_length - 2 * GP01_Open_WashInside_Time -
			GP01_Open_WashOutside_Time - GSJG_UpDown_Time - 2;
		return starttime;
	}

	int CONNECT::sample_after_qb(int QB_finished_time)
{
	int starttime = 0;
	starttime = QB_finished_time + FYP_ActionTime - (GYBG_UpDown_Time + GYBG_Move_Time + GYBG_UpDown_Time +
		GPump_In_Out_Time + GYBG_UpDown_Time + GYBG_Move_Time + 1);
	return starttime;
}

	int CONNECT::sample_after_reagent(int add_reagent_real_starttime, int add_reagent_code_length)
{
	int starttime = 0;
	starttime = add_reagent_real_starttime + add_reagent_code_length - 2 * GP01_Open_WashInside_Time - GP01_Open_WashOutside_Time - GSJG_UpDown_Time - 2;
	return starttime;
}


	int CONNECT::mix_after_sample(int add_sample_real_starttime, int add_sample_code_length)
{
	int starttime = 0;
	starttime = add_sample_real_starttime + add_sample_code_length;
	return starttime;
}

	int CONNECT::mix_after_reagent(int add_reagent_real_starttime, int add_reagent_code_length)
{
	int starttime = 0;
	starttime = add_reagent_real_starttime + add_reagent_code_length - 2 * GP01_Open_WashInside_Time - GP01_Open_WashOutside_Time - 2;
	return starttime;
}


	int CONNECT::CFL_after_mix(int FYP_add_mix_starttime, int add_mix_FYP_code_length, int FY_time)
{
	int starttime = 0;
	starttime = FYP_add_mix_starttime + add_mix_FYP_code_length + FY_time;
	return starttime;
}

	int CONNECT::FYP_after_CFL(int FYP2CFL_CFL_arrive_time)
{
	int starttime = 0;
	starttime = (FYP2CFL_CFL_arrive_time / 17 + 24) * 17 + 1;
	return starttime;
}

	int CONNECT::ZDQ_after_CFL(int FYP2CFL_CFL_arrive_time)
{
	int starttime = 0;
	starttime = (FYP2CFL_CFL_arrive_time / 17 + 24) * 17 + 1;
	return starttime;
}

	int CONNECT::GJC_after_ZDG(int CFL2ZDQ_ZDQ_arrive_time)
{
	int starttime = 0;
	starttime = CFL2ZDQ_ZDQ_arrive_time + 148;
	return starttime;
}

