#include "stdafx.h"
#include "PLAN.h"
#include "BJ.h"
#include "JZ.h"
#include "GlobalVariableState.h"

PLAN::PLAN()
{
}


PLAN::~PLAN()
{
}

int PLAN::qb(int qb_starttime, int &BJ_is_empty, int &BJ_need_changerow, int &BJ_changerow_time, int &BJ_cupNO, int &qb_JZ_starttime, int &QB_JZ_Code_Length, int(&QB_JZ_code)[3][100],
	int &qb_time, int &FYP_putcup_time, int &QB_FYP_starttime, int &QB_FYP_use_holeNO, int(&QB_FYP_code)[50], int &QB_FYP_code_length, int &qb_finished_time, int &BJ_NO)
{
	int fromstart = 0;
	int fromend = 0;
	int tostart = 0;
	int toend = 0;
	int JZ_Adjust_Steps = 0;
	int FYP_Adjust_Steps = 0;
	int staytime = 0;
	int Opposit_Time = 0;


	BJ_NO = bj.ComputeCurrentCupPosition();
	if (BJ_NO == -1)
	{
		BJ_is_empty = 1;
		return 0;
	}
	else
		BJ_is_empty = 0;

	BJ_cupNO = BJ_NO + 1;

	int unfinished = 1;
	
	QB_JZ_Code_Length = jz.jiazhua_createcode(BJ_cupNO, 9, QB_JZ_code, fromstart, fromend, tostart, toend);

	while (unfinished)
	{
		check_empety_code_time(9, qb_starttime, QB_JZ_Code_Length, JZ_Adjust_Steps);
		if (JZ_Adjust_Steps > 0)
			qb_starttime = qb_starttime + JZ_Adjust_Steps;

		qb_JZ_starttime = qb_starttime;
		qb_time = qb_JZ_starttime + fromstart;

		FYP_putcup_time = qb_starttime + tostart;
		staytime = jz_downtime + jz_opentime + jz_uptime;

		QB_FYP_use_holeNO = fyp.getemptyholeNO(Opposit_Time, FYP_putcup_time, xy);
		if (Opposit_Time > 0)
		{
			qb_starttime = qb_starttime + Opposit_Time;
			continue;
		}


		fyp.createcode(QB_FYP_use_holeNO, 1, staytime, QB_FYP_code_length, QB_FYP_code);
		QB_FYP_starttime = FYP_putcup_time - FYP_ActionTime;
		//QB_FYP_starttime = qb_starttime + fromend;
		check_empety_code_time(12, QB_FYP_starttime, QB_FYP_code_length, FYP_Adjust_Steps);
		if (FYP_Adjust_Steps>0)
		{
			qb_starttime = qb_starttime + FYP_Adjust_Steps;
			continue;
		}
		unfinished = 0;

	}

	qb_finished_time = QB_FYP_starttime + QB_FYP_code_length;

	//set_BJ_state(GBJ_Content);

	return 0;
}

int PLAN::set_BJ_state(int BJstate[9][7])
{
	BJstate[GCurrent_Cup_position_Row][GCurrent_Cup_position_Col] = 0;
	if (GCurrent_Cup_position_Row <= 8 && GCurrent_Cup_position_Col > 0)
	{
		GCurrent_Cup_position_Col--;
		GRemian_Cup_Numbers--;
	}
	else if (GCurrent_Cup_position_Row < 8 && GCurrent_Cup_position_Col == 0)
	{

		GCurrent_Cup_position_Row++;
		GCurrent_Cup_position_Col = 6;
		GRemian_Cup_Numbers--;   //��Ҫ����
	}
	else
	{
		GCurrent_Cup_position_Row = 0;
		GCurrent_Cup_position_Col = 6;
		GRemian_Cup_Numbers = 63;   //��Ҫ������
	}
	return 0;
}

int PLAN::check_empety_code_time(int row, int starttime, int code_len, int& adjust_steps)
{
	int FirstRun, SecondRun;
	FirstRun = starttime;
	SecondRun = starttime;
	while (FirstRun - SecondRun<code_len)
	{
		if (FirstRun >= 100000)
		{
			adjust_steps = -1;
			return -1;
		}

		if (xy[row][FirstRun] == 0)
			FirstRun++;
		else
		{
			FirstRun++;
			SecondRun = FirstRun;
		}
	}
	adjust_steps = SecondRun - starttime;
	return SecondRun;

}

int PLAN::add_reagent(int project,int starttime, int FYP_hole_NO, int Reagent_Location_NO, int Reagent_Bin_NO, int &add_reagent_real_starttime,
	int &FYP_add_reagent_time, int &FYP_add_reagent_starttime, int &addSJ_FYP_occupytime, int(&add_reagent_code)[8][100], int &add_reagent_code_length, int(&add_reagent_FYP_code)[50],
	int &add_reagent_FYP_code_length)
{
	int Reagent_Adjust_Steps = 0;
	int FYP_Adjust_Step = 0;
	int Need_FindAgain = true;
	int staytime = 0;
	int unfinished = 1;
	reagent.PutReagentToFYPcode(project, Reagent_Bin_NO, Reagent_Location_NO, add_reagent_code, add_reagent_code_length);

	while (unfinished)
	{
		check_empety_code_time(3, starttime, add_reagent_code_length, Reagent_Adjust_Steps);
		if (Reagent_Adjust_Steps>0)
		{
			starttime = starttime + Reagent_Adjust_Steps;
			continue;
		}
		check_empety_code_time(5, starttime, add_reagent_code_length, Reagent_Adjust_Steps);
		if (Reagent_Adjust_Steps>0)
		{
			starttime = starttime + Reagent_Adjust_Steps;
			continue;
		}
		
		FYP_add_reagent_time = starttime + GSJG_UpDown_Time + GSJG_UpDown_Time +GPump_In_Out_Time + GSJG_Move_Time + GSJG_Move_Time + GSJG_UpDown_Time + 1;
		
		staytime = GSJG_UpDown_Time + GPump_In_Out_Time + GSJG_UpDown_Time;


		fyp.createcode(FYP_hole_NO, 2, staytime, add_reagent_FYP_code_length, add_reagent_FYP_code);

		FYP_add_reagent_starttime = FYP_add_reagent_time - FYP_ActionTime;


		check_empety_code_time(12, FYP_add_reagent_starttime, add_reagent_FYP_code_length, FYP_Adjust_Step);
		if (FYP_Adjust_Step>0)
		{
			starttime = starttime + FYP_Adjust_Step;
			continue;
		}
		unfinished = 0;
	} 

	add_reagent_real_starttime = starttime;
	return 0;
}

int PLAN::add_sample(int project,int starttime, int FYP_hole_NO, int SampleNO, int &add_sample_real_starttime, int &FYP_add_sample_time, int &FYP_add_sample_starttime, int &add_sample_FYP_occupytime,
	int(&add_sample_code)[8][100], int &add_sample_code_length, int(&add_sample_FYP_code)[50], int &add_sample_FYP_code_length)
{
	int Sample_Adjust_Steps = 0;
	int staytime = 0;
	int FYP_Adjust_Step = 0;
	int Need_FindAgain = true;
	int unfinished = 1;
	sample.PutSampleToFYPCode(project,SampleNO, add_sample_code, add_sample_code_length);
	
	while (unfinished)
	{
		check_empety_code_time(4, starttime, add_sample_code_length, Sample_Adjust_Steps);
		if (Sample_Adjust_Steps>0)
		{
			starttime = starttime + Sample_Adjust_Steps;
			continue;
		}
		check_empety_code_time(2, starttime, add_sample_code_length, Sample_Adjust_Steps);
		if (Sample_Adjust_Steps>0)
		{
			starttime = starttime + Sample_Adjust_Steps;
			continue;
		}

		FYP_add_sample_time = starttime + GYBG_UpDown_Time + GYBG_Move_Time + GYBG_UpDown_Time + GPump_In_Out_Time + GYBG_Move_Time + GYBG_UpDown_Time + 1;

		staytime = GYBG_UpDown_Time + GPump_In_Out_Time + GYBG_UpDown_Time;

		fyp.createcode(FYP_hole_NO, 2, staytime, add_sample_FYP_code_length, add_sample_FYP_code);

		FYP_add_sample_starttime = FYP_add_sample_time - FYP_ActionTime;

		check_empety_code_time(12, FYP_add_sample_starttime, add_sample_FYP_code_length, FYP_Adjust_Step);
		if (FYP_Adjust_Step>0)
		{
			starttime = starttime + FYP_Adjust_Step;
			continue;
		}
		unfinished = 0;
	} 

	add_sample_real_starttime = starttime;
	return 0;
}

int PLAN::add_sample_from_cup(int sample_volum, int starttime, int from_FYP_hole_NO, int to_FYP_hole_NO, int& add_sample_from_cup_real_starttime, int&GetSampleFromCupFYPstarttime1, int(&add_sample_from_FYP_code)[50],
	int& add_sample_from_FYP_code_length, int&GetSampleFromCupFYPstarttime2, int(&add_sample_back_FYP_code)[50], int& add_sample_back_FYP_code_length, int& GetSampleFromCupCodeStarttime,
	int(&get_sample_code)[8][100], int& get_sample_code_length, int& add_sample_from_cup_finish_time)
{
	int staytime = 0;
	int unfinished = 1;
	int Sample_Adjust_Steps = 0;
	int first_fyp_occupy_time = 0;

	sample.GetSampleFromCupCode(sample_volum, get_sample_code, get_sample_code_length);
	staytime = GYBG_UpDown_Time + GPump_In_Out_Time + GSJG_UpDown_Time;
	fyp.createcode(from_FYP_hole_NO, 2, staytime, add_sample_from_FYP_code_length, add_sample_from_FYP_code);
	fyp.createcode(to_FYP_hole_NO, 2, staytime, add_sample_back_FYP_code_length, add_sample_back_FYP_code);

	while (unfinished)
	{
		GetSampleFromCupCodeStarttime = starttime - GYBG_Move_Time - GYBG_UpDown_Time;
		check_empety_code_time(5, GetSampleFromCupCodeStarttime, get_sample_code_length, Sample_Adjust_Steps);
		if (Sample_Adjust_Steps>0)
		{
			starttime = starttime + Sample_Adjust_Steps;
			continue;
		}
		check_empety_code_time(2, GetSampleFromCupCodeStarttime - 6, get_sample_code_length - 6, Sample_Adjust_Steps);
		if (Sample_Adjust_Steps>0)
		{
			starttime = starttime + Sample_Adjust_Steps;
			continue;
		}

		GetSampleFromCupFYPstarttime1 = starttime - FYP_ActionTime;

		first_fyp_occupy_time = FYP_ActionTime + staytime + FYP_ActionTime + 2;

		GetSampleFromCupFYPstarttime2 = GetSampleFromCupFYPstarttime1 + first_fyp_occupy_time;

		check_empety_code_time(12, GetSampleFromCupFYPstarttime1, 2 * first_fyp_occupy_time, Sample_Adjust_Steps);
		if (Sample_Adjust_Steps>0)
		{
			starttime = starttime + Sample_Adjust_Steps;
			continue;
		}
		add_sample_from_cup_real_starttime = starttime;
		add_sample_from_cup_finish_time = GetSampleFromCupFYPstarttime1 + first_fyp_occupy_time;
		unfinished = 0;
	}
	return 0;
}

int PLAN::mix(int starttime, int FYP_hole_NO, int SampleNO, int &add_mix_real_starttime, int &FYP_add_mix_time, int &FYP_add_mix_starttime, int &add_mix_FYP_occupytime,
	int(&add_mix_code)[8][100], int &add_mix_code_length, int(&add_mix_FYP_code)[50], int &add_mix_FYP_code_length)
{
	int Sample_Adjust_Steps = 0;
	int staytime = 0;
	int FYP_Adjust_Step = 0;
	int Need_FindAgain = true;
	int unfinished = 1;
	sample.MixCode(add_mix_code, add_mix_code_length);
	
	while (unfinished)
	{
		check_empety_code_time(4, starttime, add_mix_code_length, Sample_Adjust_Steps);
		if (Sample_Adjust_Steps>0)
		{
			starttime = starttime + Sample_Adjust_Steps;
			continue;
		}

		check_empety_code_time(2, starttime, add_mix_code_length, Sample_Adjust_Steps);
		if (Sample_Adjust_Steps>0)
		{
			starttime = starttime + Sample_Adjust_Steps;
			continue;
		}

		FYP_add_mix_time = starttime + GYBG_UpDown_Time + GYBG_Move_Time;
		//staytime = GYBG_UpDown_Time + GPump_In_Out_Time + 4 * (GPump_In_Out_Time + 1) + GYBG_UpDown_Time + GPump_In_Out_Time;
		staytime = GYBG_UpDown_Time + 8 * (GPump_In_Out_Time + 1) + GYBG_UpDown_Time - 1;
		fyp.createcode(FYP_hole_NO, 2, staytime, add_mix_FYP_code_length, add_mix_FYP_code);

		FYP_add_mix_starttime = FYP_add_mix_time - FYP_ActionTime;

		check_empety_code_time(12, FYP_add_mix_starttime, add_mix_FYP_code_length, FYP_Adjust_Step);
		if (FYP_Adjust_Step>0)
		{
			starttime = starttime + FYP_Adjust_Step;
			continue;
		}
		unfinished = 0;
	} 

	add_mix_real_starttime = starttime;

	return 0;
}

int PLAN::CFL2FYP(int starttime, int& CFL2FYP_real_starttime, int& CFL2FYP_JZ_starttime,
	int(&CFL2FYP_JZ_code)[3][100], int& CFL2FYP_JZ_code_length, int& CFL2FYP_FYP_arrive_time,
	int& CFL2FYP_FYP_holeNO, int& CFL2FYP_FYP_starttime, int(&CFL2FYP_FYP_code)[50], int& CFL2FYP_FYP_code_length)
{
	int opposit_time = 0;
	int adjust_steps = 0;
	int from = 13;
	int to = 9;
	int fromstart;
	int fromend;
	int tostart;
	int toend;
	bool unfinished = true;
	//��һ��
	CFL2FYP_JZ_code_length = jz.jiazhua_createcode(from, to, CFL2FYP_JZ_code, fromstart, fromend, tostart, toend);
	while (unfinished)
	{
		//�ڶ���
		CFL2FYP_JZ_starttime = starttime - jz_movetime;
		//������
		check_empety_code_time(9, CFL2FYP_JZ_starttime, CFL2FYP_JZ_code_length, adjust_steps);
		if (adjust_steps == 0)
		{
			//���Ĳ�
		}
		else
		{
			starttime += adjust_steps;
			continue;
		}
		//���Ĳ�
		CFL2FYP_FYP_arrive_time = starttime + jz_downtime + jz_closetime + jz_uptime + jz_movetime;
		//���岽,Ѱ�ҿտ�
		CFL2FYP_FYP_holeNO = fyp.getemptyholeNO(opposit_time, CFL2FYP_FYP_arrive_time, xy);
		if (opposit_time == 0)
		{
			//������
		}
		else
		{
			starttime += opposit_time;
			continue;
		}
		//������
		CFL2FYP_FYP_starttime = CFL2FYP_FYP_arrive_time - FYP_ActionTime;
		int CFL2FYP_FYP_staytime = jz_downtime + jz_opentime + jz_uptime;
		//���߲�
		fyp.createcode(CFL2FYP_FYP_holeNO, 1, CFL2FYP_FYP_staytime, CFL2FYP_FYP_code_length, CFL2FYP_FYP_code);
		//�ڰ˲�
		check_empety_code_time(12, CFL2FYP_FYP_starttime, CFL2FYP_FYP_code_length, adjust_steps);
		if (adjust_steps == 0)
		{
			//�ھŲ�
		}
		else
		{
			starttime += adjust_steps;
			continue;
		}
		CFL2FYP_real_starttime = starttime;
		unfinished = false;
	}
	return 0;
}

int PLAN::FYP2GJC(int starttime, int FYP_hole_NO, int& FYP2GJC_real_starttime, int& FYP2GJC_JZ_starttime, int(&FYP2GJC_JZ_code)[3][100], 
	int& FYP2GJC_JZ_code_length, int& FYP2GJC_FYP_starttime, int(&FYP2GJC_FYP_code)[50], int& FYP2GJC_FYP_code_length, int& FYP2GJC_GJC_arrive_time)
{
	bool flag = true;
	//����1
	JZ jz;
	//�����Ǳ���
	int from = 9;  //������λ
	int to = 8;    //����λ
				   //����������
	int fromstart;
	int fromend;
	int tostart;
	int toend;
	FYP2GJC_JZ_code_length = jz.jiazhua_createcode(from, to, FYP2GJC_JZ_code, fromstart, fromend, tostart, toend);


	while (true)
	{
		if (flag)
		{
			//����2
			FYP fyp;
			//�����Ǳ���
			int isChangeCupStation = 1;
			int StayTime = jz_downtime + jz_opentime + jz_uptime;
			fyp.createcode(FYP_hole_NO, isChangeCupStation, StayTime, FYP2GJC_FYP_code_length, FYP2GJC_FYP_code);

		}

		//����3
		FYP2GJC_JZ_starttime = starttime - jz_movetime;

		//����4
		int row_jz = 9;     //��צλ��xy���9��
		int adjust_steps_jz;
		int check_jz = check_empety_code_time(row_jz, FYP2GJC_JZ_starttime, FYP2GJC_JZ_code_length, adjust_steps_jz);
		if (adjust_steps_jz != 0)
		{
			starttime = starttime + adjust_steps_jz;
			flag = false;
			continue;
		}

		//����5
		FYP2GJC_FYP_starttime = starttime - FYP_ActionTime;
		//����6
		int row_fyp = 12;   //FYPת����xy���12��
		int adjust_steps_fyp;
		int check_fyp = check_empety_code_time(row_fyp, FYP2GJC_FYP_starttime, FYP2GJC_JZ_code_length, adjust_steps_fyp);
		if (adjust_steps_fyp != 0)
		{
			starttime = starttime + adjust_steps_fyp;
			flag = false;
			continue;
		}

		//����7
		FYP2GJC_GJC_arrive_time = starttime + jz_downtime + jz_opentime + jz_uptime + jz_movetime;

		//����8
		int gjc_length;
		int gjc_code[50] = { 0 };
		gjc.db_createcode(gjc_length, gjc_code);
		
		//����9
		int row_gjc = 49;   //�������ܱ��49��
		int adjust_steps_gjc;
		int check_gjc = check_empety_code_time(row_gjc, FYP2GJC_GJC_arrive_time, gjc_length, adjust_steps_gjc);
		if (adjust_steps_gjc != 0)
		{
			starttime = starttime + adjust_steps_gjc;
			flag = true;
			continue;
		}
		break;
	}

	//����10
	FYP2GJC_real_starttime = starttime;

	return 0;
}

void PLAN::FYP2CFL(int starttime, int FYP_hole_NO, int& FYP2CFL_real_starttime, int& FYP2CFL_JZ_starttime,
	int(&FYP2CFL_JZ_code)[3][100], int &FYP2CFL_JZ_code_length, int &FYP2CFL_FYP_starttime,
	int(&FYP2CFL_FYP_code)[50], int &FYP2CFL_FYP_code_length, int &CFL_hole_NO, int &FYP2FL_CFL_arrive_time)
{
	int adjust_steps = 0;
	int from = 9;
	int to = 13;
	int fromstart;
	int fromend;
	int tostart;
	int toend;
	bool unfinished = true;

	//��һ��
	FYP2CFL_JZ_code_length = jz.jiazhua_createcode(from, to, FYP2CFL_JZ_code, fromstart, fromend, tostart, toend);

	//�ڶ���
	fyp.createcode(FYP_hole_NO, 1, jz_downtime + jz_opentime + jz_uptime, FYP2CFL_FYP_code_length, FYP2CFL_FYP_code);

	while (unfinished)
	{
		//������
		FYP2CFL_JZ_starttime = starttime - jz_movetime;

		//���Ĳ�
		check_empety_code_time(9, FYP2CFL_JZ_starttime, FYP2CFL_JZ_code_length, adjust_steps);
		if (adjust_steps == 0)
		{
			//������岽
		}
		else
		{
			starttime = starttime + adjust_steps;
			continue;
		}

		//���岽
		FYP2CFL_FYP_starttime = starttime - FYP_ActionTime;

		//������
		check_empety_code_time(12, FYP2CFL_FYP_starttime, FYP2CFL_FYP_code_length, adjust_steps);
		if (adjust_steps == 0)
		{

			//���߲�
		}
		else
		{
			starttime = starttime + adjust_steps;
			continue;
		}

		//���߲�
		FYP2FL_CFL_arrive_time = starttime + jz_downtime + jz_opentime + jz_uptime + jz_movetime;

		//�ڰ˲�
		if (0 < FYP2FL_CFL_arrive_time % 17 && FYP2FL_CFL_arrive_time % 17<15)
		{
			
		}

		/*else if (FYP2FL_CFL_arrive_time % 17 > 15)
		{
			adjust_steps =  2;
			starttime += adjust_steps;
			continue;
		}*/
		else
		{
			adjust_steps = 1;
			starttime += adjust_steps;
			continue;
		}

		//�ھŲ�
		CFL_hole_NO = cfl.computeCFLNR(xy, FYP2FL_CFL_arrive_time);
		if (CFL_hole_NO != 0)
		{
			//��ʮ��
		}
		else {
			adjust_steps = (17 - FYP2FL_CFL_arrive_time % 17) + 1;
			starttime += adjust_steps;
			continue;
		}

		//��ʮ��
		FYP2CFL_real_starttime = starttime;
		unfinished = false;
	}
}

int PLAN::CFL2ZDQ(int starttime, int& CFL2ZDQ_real_starttime, int& CFL2ZDQ_JZ_starttime, int(&CFL2ZDQ_JZ_code)[3][100],
	int& CFL2ZDQ_JZ_code_length, int& CFL2ZDQ_ZDQ_arrive_time, int& CFL2ZDQ_hole_NO)
{
	int From = 13; // from Ϊ13��CFLλ��
	int To = 1;   //toΪ10(ZDQ 1��λ)
	int Row = 9;//����һ���ȴ�λ����
	int jiazhuacode[3][100] = { 0 };   //��צ������ɵĴ���
	int Fromstart = 0;             //��צ��fromλ��׼����ȥ��ʱ��
	int Fromend = 0;               //��צ��fromλ���Ѿ�������ʱ��
	int Tostart = 0;			   //��צ��toλ��׼����ȥ��ʱ��
	int Toend = 0;				   //��צ��toλ���Ѿ�������ʱ��

	int adjust_steps;		   //
	int opposit_time;		   //

	//bool UnFinish = true;      //ѭ��������־λ

	//����1
	/*
	1��	��int jiazhua_createcode
	����ֵΪ��צռ��ʱ�䳤��CFL2ZDQ_JZ_code_length��from Ϊ13��CFLλ����
	toΪ10(ZDQ 1��λ)�ȵø�JZռ��ʱ������پ���ȷ����ZDQ�ĸ���λ��
	*/
	CFL2ZDQ_JZ_code_length = jz.jiazhua_createcode(From, To, jiazhuacode, Fromstart, Fromend, Tostart, Toend);


	//ѭ������StartUseTime
	while (true)
	{
		//����2
		//��צ��ʼ�˶�ʱ��CFL2ZDQ_JZ_starttime = starttime - jz_movetime(��צ�˶�ʱ��2s��������GlobalVariable��State)��
		CFL2ZDQ_JZ_starttime = starttime - jz_movetime;

		//����3
		int SecondRun = check_empety_code_time(Row, CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code_length, adjust_steps);
		if (adjust_steps != 0)
		{
			starttime = starttime + adjust_steps;
			continue;       //continue�������ǣ�һ��adjust_steps��Ϊ0�����������һ��ѭ��������CFL2ZDQ_JZ_starttime
		}

		//����4
		CFL2ZDQ_ZDQ_arrive_time = starttime + jz_downtime + jz_closetime + jz_uptime + jz_movetime;

		//����5
		CFL2ZDQ_hole_NO = ddw.GetemptyholeNO(opposit_time, starttime, xy);
		if (opposit_time == 0) break;  //����õ���opposit_time=0��������whileѭ��
		//����õ���opposit_time>0����ӵ�2����ʼִ��
		else starttime = starttime + opposit_time;
	}

	//����6
	CFL2ZDQ_JZ_code_length = jz.jiazhua_createcode(From, 9 + CFL2ZDQ_hole_NO, CFL2ZDQ_JZ_code, Fromstart, Fromend, Tostart, Toend);
	//����7
	CFL2ZDQ_real_starttime = starttime;
	return 0;
}

int PLAN::ZDQ2GJC(int starttime, int& ZDQ2GJC_real_starttime, int ZDQ_hole_NO, int& ZDQ2GJC_JZ_starttime, int(&ZDQ2GJC_JZ_code)[3][100],
	int& ZDQ2GJC_JZ_code_length, int& ZDQ2GJC_GJC_arrive_time)
{
	int Fromstart;             //��צ��fromλ��׼����ȥ��ʱ��
	int Fromend;               //��צ��fromλ���Ѿ�������ʱ��
	int Tostart;			   //��צ��toλ��׼����ȥ��ʱ��
	int Toend;				   //��צ��toλ���Ѿ�������ʱ��
	int From = 9 + ZDQ_hole_NO; //from Ϊ9+ZDQ_hole_NO��ZDQλ��
	int To = 8;

	int adjust_steps_1;		   //
	int adjust_steps_2;		   //


	//����1
	ZDQ2GJC_JZ_code_length = jz.jiazhua_createcode(From, To, ZDQ2GJC_JZ_code, Fromstart, Fromend, Tostart, Toend);


	//whileѭ���������ظ������
	while (true)
	{
		//����2
		ZDQ2GJC_JZ_starttime = starttime - jz_movetime;

		//����3
		int SecondRun_1 = check_empety_code_time(9, ZDQ2GJC_JZ_starttime, ZDQ2GJC_JZ_code_length, adjust_steps_1);
		if (adjust_steps_1 != 0)
		{
			starttime = starttime + adjust_steps_1;
			continue;   //���adjust_steps_1��Ϊ0����ô��ֱ�ӽ�����һ��ѭ��������starttime
		}
		//����4
		ZDQ2GJC_GJC_arrive_time = starttime + jz_downtime + jz_closetime + jz_uptime + jz_movetime;

		//����5
		int SecondRun_2 = check_empety_code_time(49, ZDQ2GJC_JZ_starttime - 2, 43, adjust_steps_2);
		if (adjust_steps_2 == 0) break;
		else
		{
			starttime = starttime + adjust_steps_2;
		}

	}

	//����6
	ZDQ2GJC_real_starttime = starttime;
	return 0;
}

int PLAN::ZDQ2BJ(int starttime, int& ZDQ2BJ_real_starttime, int ZDQ_hole_NO, int& ZDQ2BJ_JZ_starttime,
	int(&ZDQ2BJ_JZ_code)[3][100], int& ZDQ2BJ_JZ_code_length, int& ZDQ2BJ_BJ_arrive_time, int BJ_use_NO)
{
	int Fromstart;             //��צ��fromλ��׼����ȥ��ʱ��
	int Fromend;               //��צ��fromλ���Ѿ�������ʱ��
	int Tostart;			   //��צ��toλ��׼����ȥ��ʱ��
	int Toend;				   //��צ��toλ���Ѿ�������ʱ��
	int From = 9 + ZDQ_hole_NO; //from Ϊ9+ZDQ_hole_NO��ZDQλ��
	int To = BJ_use_NO;

	int adjust_steps_1 = 0;		

	//����1
	ZDQ2BJ_JZ_code_length = jz.jiazhua_createcode(From, To, ZDQ2BJ_JZ_code, Fromstart, Fromend, Tostart, Toend);

	//whileѭ���������ظ������
	while (true)
	{
		//����2
		ZDQ2BJ_JZ_starttime = starttime - jz_movetime;

		//����3
		int SecondRun_1 = check_empety_code_time(9, ZDQ2BJ_JZ_starttime, ZDQ2BJ_JZ_code_length, adjust_steps_1);
		if (adjust_steps_1 != 0)
		{
			starttime = starttime + adjust_steps_1;
			continue;   //���adjust_steps_1��Ϊ0����ô��ֱ�ӽ�����һ��ѭ��������starttime
		}
		//����4
		ZDQ2BJ_BJ_arrive_time = starttime + jz_downtime + jz_closetime + jz_uptime + jz_movetime;
		break;
	}
	//����5
	ZDQ2BJ_real_starttime = starttime;
	return 0;
}