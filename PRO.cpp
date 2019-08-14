#include "stdafx.h"
#include "PRO.h"


PRO::PRO()
{
}

PRO::~PRO()
{
}

//ȡ�������Լ�1�������������Լ�4������ 
void PRO::PCT(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R4_Location_NO, int qb_starttime, int FY_time)
{
	//���Ʊ���
	bool unfinished = true;
	int adjust_time = 0;

	//ȡ����ر���
	int BJ_is_empty = 0;
	int BJ_need_changerow = 0;
	int BJ_changerow_time = 0;
	int BJ_cupNO = 0;
	int QB_JZ_starttime = 0;
	int QB_JZ_code_length = 0;
	int QB_JZ_code[3][100] = { 0 };
	int QB_time = 0;
	int FYP_putcup_time = 0;
	int QB_FYP_starttime = 0;
	int QB_FYP_use_holeNO = 0;
	int QB_FYP_code[50] = { 0 };
	int QB_FYP_code_length = 0;
	int QB_finished_time = 0;
	int BJ_NO = 0;

	//���Լ�1��ر���
	int add_reagent1_starttime = 0;
	int add_reagent1_real_starttime = 0;
	int FYP_add_reagent1_time = 0;
	int FYP_add_reagent1_starttime = 0;
	int addSJ1_FYP_occupytime = 0;
	int add_reagent1_code[8][100] = { 0 };
	int add_reagent1_code_length = 0;
	int add_reagent1_FYP_code[50] = { 0 };
	int add_reagent1_FYP_code_length = 0;

	//��������ر���
	int sample_starttime = 0;
	int add_sample_real_starttime = 0;
	int FYP_add_sample_time = 0;
	int FYP_add_sample_starttime = 0;
	int add_sample_FYP_occupytime = 0;
	int add_sample_code[8][100] = { 0 };
	int add_sample_code_length = 0;
	int add_sample_FYP_code[50] = { 0 };
	int add_sample_FYP_code_length = 0;

	//���Լ�4��ر���
	int add_reagent4_starttime = 0;
	int add_reagent4_real_starttime = 0;
	int FYP_add_reagent4_time = 0;
	int FYP_add_reagent4_starttime = 0;
	int addSJ4_FYP_occupytime = 0;
	int add_reagent4_code[8][100] = { 0 };
	int add_reagent4_code_length = 0;
	int add_reagent4_FYP_code[50] = { 0 };
	int add_reagent4_FYP_code_length = 0;

	//������ر���
	int mix_starttime = 0;
	int add_mix_real_starttime = 0;
	int FYP_add_mix_time = 0;
	int FYP_add_mix_starttime = 0;
	int add_mix_FYP_occupytime = 0;
	int add_mix_code[8][100] = { 0 };
	int add_mix_code_length = 0;
	int add_mix_FYP_code[50] = { 0 };
	int add_mix_FYP_code_length = 0;

	//���ŷ�����ر���
	int FYP_out_time = 0;
	int FYP2CFL_real_starttime = 0;
	int FYP2CFL_JZ_starttime = 0;
	int FYP2CFL_JZ_code[3][100]={ 0 };
	int FYP2CFL_JZ_code_length = 0;
	int FYP2CFL_FYP_starttime = 0;
	int FYP2CFL_FYP_code[50] = { 0 };
	int FYP2CFL_FYP_code_length = 0;
	int CFL_hole_NO = 0;
	int FYP2CFL_CFL_arrive_time = 0;

	//�ŷ����������ر���
	int CFL2ZDQ_starttime = 0;
	int CFL2ZDQ_real_starttime = 0;
	int CFL2ZDQ_JZ_starttime = 0;
	int CFL2ZDQ_JZ_code[3][100] = { 0 };
	int CFL2ZDQ_JZ_code_length = 0;
	int CFL2ZDQ_ZDQ_arrive_time = 0;
	int CFL2ZDQ_hole_NO = 0;

	//������������ر���
	int ZDQ2GJC_starttime = 0;
	int ZDQ2GJC_real_starttime = 0;
	int ZDQ2GJC_JZ_starttime = 0;
	int ZDQ2GJC_JZ_code[3][100] = { 0 };
	int ZDQ2GJC_JZ_code_length = 0;
	int ZDQ2GJC_GJC_arrive_time = 0;

	plan.qb(qb_starttime, BJ_is_empty, BJ_need_changerow, BJ_changerow_time, BJ_cupNO, QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code,
		QB_time, FYP_putcup_time, QB_FYP_starttime, QB_FYP_use_holeNO, QB_FYP_code, QB_FYP_code_length, QB_finished_time,BJ_NO);
	plan.set_BJ_state(GBJ_Content);
	//������ز���
	if (BJ_NO == 0)
	{
		//���뻻����������
		int code[10] = { 0 };
		int CodeLength1;
		CodeLength1 = plan.bj.BJmovnextrow(code);
		int time = QB_JZ_starttime + jz_downtime + jz_opentime + jz_uptime + jz_movetime;
		for (int j = 0; j < CodeLength1; j++)
			xy[8][j + time] = code[j];
	}
	add_reagent1_starttime = connect.reagent_after_qb(QB_finished_time);

	while (unfinished)
	{
		add_reagent1_starttime += adjust_time;

		plan.add_reagent(10, add_reagent1_starttime, QB_FYP_use_holeNO, R1_location_NO, Reagent_Bin_NO, add_reagent1_real_starttime,
			FYP_add_reagent1_time, FYP_add_reagent1_starttime, addSJ1_FYP_occupytime, add_reagent1_code, add_reagent1_code_length,
			add_reagent1_FYP_code, add_reagent1_FYP_code_length);
		adjust_time = add_reagent1_real_starttime - add_reagent1_starttime;
		if (adjust_time > 0)
			continue;

		sample_starttime = connect.sample_after_reagent(add_reagent1_real_starttime, add_reagent1_code_length);
		plan.add_sample(2, sample_starttime, QB_FYP_use_holeNO, SampleNO, add_sample_real_starttime, FYP_add_sample_time,
			FYP_add_sample_starttime, add_sample_FYP_occupytime, add_sample_code, add_sample_code_length, add_sample_FYP_code,
			add_sample_FYP_code_length);
		adjust_time = add_sample_real_starttime - sample_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent4_starttime = connect.reagent_after_sample(add_sample_real_starttime, add_sample_code_length);
		plan.add_reagent(10, add_reagent4_starttime, QB_FYP_use_holeNO, R4_Location_NO, Reagent_Bin_NO, add_reagent4_real_starttime, FYP_add_reagent4_time,
			FYP_add_reagent4_starttime, addSJ4_FYP_occupytime, add_reagent4_code, add_reagent4_code_length, add_reagent4_FYP_code, add_reagent4_FYP_code_length);
		adjust_time = add_reagent4_real_starttime - add_reagent4_starttime;
		if (adjust_time > 0)
			continue;

		mix_starttime = connect.mix_after_reagent(add_reagent4_real_starttime, add_reagent4_code_length);
		plan.mix(mix_starttime, QB_FYP_use_holeNO, SampleNO, add_mix_real_starttime, FYP_add_mix_time, FYP_add_mix_starttime,
			add_mix_FYP_occupytime, add_mix_code, add_mix_code_length, add_mix_FYP_code, add_mix_FYP_code_length);
		adjust_time = add_mix_real_starttime - mix_starttime;
		if (adjust_time > 0)
			continue;

		FYP_out_time = connect.CFL_after_mix(FYP_add_mix_starttime, add_mix_FYP_code_length, FY_time);
		plan.FYP2CFL(FYP_out_time, QB_FYP_use_holeNO, FYP2CFL_real_starttime, FYP2CFL_JZ_starttime, FYP2CFL_JZ_code, FYP2CFL_JZ_code_length,
			FYP2CFL_FYP_starttime, FYP2CFL_FYP_code, FYP2CFL_FYP_code_length, CFL_hole_NO, FYP2CFL_CFL_arrive_time);
		adjust_time = FYP2CFL_real_starttime - FYP_out_time;
		if (adjust_time > 0)
			continue;

		CFL2ZDQ_starttime = connect.ZDQ_after_CFL(FYP2CFL_CFL_arrive_time);
		plan.CFL2ZDQ(CFL2ZDQ_starttime, CFL2ZDQ_real_starttime, CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code,
			CFL2ZDQ_JZ_code_length, CFL2ZDQ_ZDQ_arrive_time, CFL2ZDQ_hole_NO);
		adjust_time = CFL2ZDQ_real_starttime - CFL2ZDQ_starttime;
		if (adjust_time > 13)
			continue;

		ZDQ2GJC_starttime = connect.GJC_after_ZDG(CFL2ZDQ_ZDQ_arrive_time);//������������148s
		plan.ZDQ2GJC(ZDQ2GJC_starttime, ZDQ2GJC_real_starttime, CFL2ZDQ_hole_NO, ZDQ2GJC_JZ_starttime,
			ZDQ2GJC_JZ_code, ZDQ2GJC_JZ_code_length, ZDQ2GJC_GJC_arrive_time);
		adjust_time = ZDQ2GJC_real_starttime - ZDQ2GJC_starttime;
		if (adjust_time > 0)
			continue;

		unfinished = false;
	}

	

	//��Ӳ�������
	//ȡ������
	add_code.add_JZ_move_code(QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code);
	add_code.add_FYP_move_code(QB_FYP_starttime, QB_FYP_code_length, QB_FYP_code);
	//�Լ�1����
	add_code.add_SJ_code(add_reagent1_real_starttime, add_reagent1_code_length, add_reagent1_code);
	add_code.add_FYP_move_code(FYP_add_reagent1_starttime, add_reagent1_FYP_code_length, add_reagent1_FYP_code);
	//��������
	add_code.add_sample_code(add_sample_real_starttime, add_sample_code_length, add_sample_code);
	add_code.add_FYP_move_code(FYP_add_sample_starttime, add_sample_FYP_code_length, add_sample_FYP_code);
	//�Լ�4����
	add_code.add_SJ_code(add_reagent4_real_starttime, add_reagent4_code_length, add_reagent4_code);
	add_code.add_FYP_move_code(FYP_add_reagent4_starttime, add_reagent4_FYP_code_length, add_reagent4_FYP_code);
	//�ӽ������
	add_code.add_mix_code(add_mix_real_starttime, add_mix_code_length, add_mix_code);
	add_code.add_FYP_move_code(FYP_add_mix_starttime, add_mix_FYP_code_length, add_mix_FYP_code);
	//�����̵��ŷ������
	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime, FYP2CFL_JZ_code_length, FYP2CFL_JZ_code);
	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime, FYP2CFL_FYP_code_length, FYP2CFL_FYP_code);
	add_code.add_FYP_hole_occupy(QB_FYP_use_holeNO, FYP_putcup_time, FYP_out_time);//�����̿�ռ��
																				   //�ŷ��뵽��������
	add_code.add_JZ_move_code(CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code_length, CFL2ZDQ_JZ_code);
	add_code.add_CFL_hole_occupy(CFL_hole_NO, FYP2CFL_CFL_arrive_time, CFL2ZDQ_real_starttime);//�ŷ����ռ��
																							   //�������������
	add_code.add_JZ_move_code(ZDQ2GJC_JZ_starttime, ZDQ2GJC_JZ_code_length, ZDQ2GJC_JZ_code);
	add_code.add_ZDQ_hole_occupy(CFL2ZDQ_hole_NO, CFL2ZDQ_ZDQ_arrive_time, ZDQ2GJC_real_starttime);//������ռ��
																							  //������̴���
	int GJC_code_length = 0;
	int GJC_code[3][50] = { 0 };
	plan.gjc.createcode(36, mission_NO, GJC_code_length, GJC_code);
	int GJC_starttime = ZDQ2GJC_GJC_arrive_time;
	add_code.add_GJC_code(GJC_starttime - 1, GJC_code_length, GJC_code);
	add_code.add_GJC_hole_occupy(GJC_starttime - 1, GJC_starttime + 43);//�����ռ��
																		//������
	add_code.add_ZDQ_motor_code();
	//�ŷ���ת��
	add_code.add_CFL_move_code(GJC_starttime + 1200, cfl_CFLcyclesteptime);
	
	totaltime = GJC_starttime + 1200;

	//��Ӵŷ���ע����Һ�������
	int length = 0;
	int zhushe1_time = 0;
	int paiye1_time = 0;
	int zhushe2_time = 0;
	int paiye2_time = 0;
	int diwu_time = 0;
	int CFLcode1[8][30] = { 0 };
	int CFLcode2[8][30] = { 0 };
	int CFLcode3[8][30] = { 0 };
	int CFLcode4[8][30] = { 0 };
	int CFLcode5[8][30] = { 0 };
	plan.cfl.CFLzhushe1codegenerate(CFLcode1, length);
	plan.cfl.CFLpaiye1codegenerate(CFLcode2, length);
	plan.cfl.CFLzhushe2codegenerate(CFLcode3, length);
	plan.cfl.CFLpaiye2codegenerate(CFLcode4, length);
	plan.cfl.CFLdiwucodegenerate(CFLcode5, length);
	//��һȦ
	zhushe1_time = (FYP2CFL_CFL_arrive_time / 17 + 2) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time / 17 + 5) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time / 17 + 6) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time / 17 + 9) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//�ڶ�Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time / 17 + 2 + 12) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time / 17 + 5 + 12) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time / 17 + 6 + 12) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time / 17 + 9 + 12) * 17 + 1;
	diwu_time = (FYP2CFL_CFL_arrive_time / 17 + 10 + 12) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	add_code.add_CFL_operation_code(diwu_time, length, CFLcode5);
}

//������ȫѪ����Һ���Լ�5��������1���Լ�1���Լ�4������2����������ϴ������Һ���𵴡����
void PRO::PCT_whole(int mission_NO, int SampleNO, int Reagent_Bin_NO, int Second_Reagent_Bin_NO, int R1_location_NO, int R4_Location_NO, int R5_Location_NO, int qb_starttime, int FY_time)
{
	//���Ʊ���
	bool unfinished = true;
	int adjust_time = 0;

	//ȡ����ر���
	int BJ_is_empty = 0;
	int BJ_need_changerow = 0;
	int BJ_changerow_time = 0;
	int BJ_cupNO = 0;
	int QB_JZ_starttime = 0;
	int QB_JZ_code_length = 0;
	int QB_JZ_code[3][100] = { 0 };
	int QB_time = 0;
	int FYP_putcup_time = 0;
	int QB_FYP_starttime = 0;
	int QB_FYP_use_holeNO = 0;
	int QB_FYP_code[50] = { 0 };
	int QB_FYP_code_length = 0;
	int QB_finished_time = 0;
	int BJ_NO = 0;

	//��������ر���
	int sample_starttime = 0;
	int add_sample_real_starttime = 0;
	int FYP_add_sample_time = 0;
	int FYP_add_sample_starttime = 0;
	int add_sample_FYP_occupytime = 0;
	int add_sample_code[8][100] = { 0 };
	int add_sample_code_length = 0;
	int add_sample_FYP_code[50] = { 0 };
	int add_sample_FYP_code_length = 0;

	//���Լ�5��ر���
	int add_reagent5_starttime = 0;
	int add_reagent5_real_starttime = 0;
	int FYP_add_reagent5_time = 0;
	int FYP_add_reagent5_starttime = 0;
	int addSJ5_FYP_occupytime = 0;
	int add_reagent5_code[8][100] = { 0 };
	int add_reagent5_code_length = 0;
	int add_reagent5_FYP_code[50] = { 0 };
	int add_reagent5_FYP_code_length = 0;

	//������ر���
	int mix1_starttime = 0;
	int add_mix1_real_starttime = 0;
	int FYP_add_mix1_time = 0;
	int FYP_add_mix1_starttime = 0;
	int add_mix1_FYP_occupytime = 0;
	int add_mix1_code[8][100] = { 0 };
	int add_mix1_code_length = 0;
	int add_mix1_FYP_code[50] = { 0 };
	int add_mix1_FYP_code_length = 0;

	//���Լ�1��ر���
	int add_reagent1_starttime = 0;
	int add_reagent1_real_starttime = 0;
	int FYP_add_reagent1_time = 0;
	int FYP_add_reagent1_starttime = 0;
	int addSJ1_FYP_occupytime = 0;
	int add_reagent1_code[8][100] = { 0 };
	int add_reagent1_code_length = 0;
	int add_reagent1_FYP_code[50] = { 0 };
	int add_reagent1_FYP_code_length = 0;

	//���Լ�4��ر���
	int add_reagent4_starttime = 0;
	int add_reagent4_real_starttime = 0;
	int FYP_add_reagent4_time = 0;
	int FYP_add_reagent4_starttime = 0;
	int addSJ4_FYP_occupytime = 0;
	int add_reagent4_code[8][100] = { 0 };
	int add_reagent4_code_length = 0;
	int add_reagent4_FYP_code[50] = { 0 };
	int add_reagent4_FYP_code_length = 0;

	//������ر���
	int mix2_starttime = 0;
	int add_mix2_real_starttime = 0;
	int FYP_add_mix2_time = 0;
	int FYP_add_mix2_starttime = 0;
	int add_mix2_FYP_occupytime = 0;
	int add_mix2_code[8][100] = { 0 };
	int add_mix2_code_length = 0;
	int add_mix2_FYP_code[50] = { 0 };
	int add_mix2_FYP_code_length = 0;

	//���ŷ�����ر���
	int FYP_out_time = 0;
	int FYP2CFL_real_starttime = 0;
	int FYP2CFL_JZ_starttime = 0;
	int FYP2CFL_JZ_code[3][100]={ 0 };
	int FYP2CFL_JZ_code_length = 0;
	int FYP2CFL_FYP_starttime = 0;
	int FYP2CFL_FYP_code[50] = { 0 };
	int FYP2CFL_FYP_code_length = 0;
	int CFL_hole_NO = 0;
	int FYP2CFL_CFL_arrive_time = 0;

	//�ŷ����������ر���
	int CFL2ZDQ_starttime = 0;
	int CFL2ZDQ_real_starttime = 0;
	int CFL2ZDQ_JZ_starttime = 0;
	int CFL2ZDQ_JZ_code[3][100] = { 0 };
	int CFL2ZDQ_JZ_code_length = 0;
	int CFL2ZDQ_ZDQ_arrive_time = 0;
	int CFL2ZDQ_hole_NO = 0;

	//������������ر���
	int ZDQ2GJC_starttime = 0;
	int ZDQ2GJC_real_starttime = 0;
	int ZDQ2GJC_JZ_starttime = 0;
	int ZDQ2GJC_JZ_code[3][100] = { 0 };
	int ZDQ2GJC_JZ_code_length = 0;
	int ZDQ2GJC_GJC_arrive_time = 0;

	plan.qb(qb_starttime, BJ_is_empty, BJ_need_changerow, BJ_changerow_time, BJ_cupNO, QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code,
		QB_time, FYP_putcup_time, QB_FYP_starttime, QB_FYP_use_holeNO, QB_FYP_code, QB_FYP_code_length, QB_finished_time,BJ_NO);
	plan.set_BJ_state(GBJ_Content);
	//������ز���
	if (BJ_NO == 0)
	{
		//���뻻����������
		int code[10] = { 0 };
		int CodeLength1;
		CodeLength1 = plan.bj.BJmovnextrow(code);
		int time = QB_JZ_starttime + jz_downtime + jz_opentime + jz_uptime + jz_movetime;
		for (int j = 0; j < CodeLength1; j++)
			xy[8][j + time] = code[j];
	}
	sample_starttime = connect.sample_after_qb(QB_finished_time);

	while (unfinished)
	{
		sample_starttime += adjust_time;

		plan.add_sample(2, sample_starttime, QB_FYP_use_holeNO, SampleNO, add_sample_real_starttime, FYP_add_sample_time,
			FYP_add_sample_starttime, add_sample_FYP_occupytime, add_sample_code, add_sample_code_length, add_sample_FYP_code,
			add_sample_FYP_code_length);
		adjust_time = add_sample_real_starttime - sample_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent5_starttime = connect.reagent_after_sample(add_sample_real_starttime, add_sample_code_length);
		plan.add_reagent(10, add_reagent5_starttime, QB_FYP_use_holeNO, R5_Location_NO, Second_Reagent_Bin_NO, add_reagent5_real_starttime, FYP_add_reagent5_time,
			FYP_add_reagent5_starttime, addSJ5_FYP_occupytime, add_reagent5_code, add_reagent5_code_length, add_reagent5_FYP_code, add_reagent5_FYP_code_length);
		adjust_time = add_reagent5_real_starttime - add_reagent5_starttime;
		if (adjust_time > 0)
			continue;

		mix1_starttime = connect.mix_after_reagent(add_reagent5_real_starttime, add_reagent5_code_length);
		plan.mix(mix1_starttime, QB_FYP_use_holeNO, SampleNO, add_mix1_real_starttime, FYP_add_mix1_time, FYP_add_mix1_starttime,
			add_mix1_FYP_occupytime, add_mix1_code, add_mix1_code_length, add_mix1_FYP_code, add_mix1_FYP_code_length);
		adjust_time = add_mix1_real_starttime - mix1_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent1_starttime = connect.reagent_after_mix(add_mix1_real_starttime, add_mix1_code_length);
		plan.add_reagent(10, add_reagent1_starttime, QB_FYP_use_holeNO, R1_location_NO, Reagent_Bin_NO, add_reagent1_real_starttime,
			FYP_add_reagent1_time, FYP_add_reagent1_starttime, addSJ1_FYP_occupytime, add_reagent1_code, add_reagent1_code_length,
			add_reagent1_FYP_code, add_reagent1_FYP_code_length);
		adjust_time = add_reagent1_real_starttime - add_reagent1_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent4_starttime = connect.reagent_after_reagent(add_reagent1_real_starttime, add_reagent1_code_length);
		plan.add_reagent(10, add_reagent4_starttime, QB_FYP_use_holeNO, R4_Location_NO, Reagent_Bin_NO, add_reagent4_real_starttime, FYP_add_reagent4_time,
			FYP_add_reagent4_starttime, addSJ4_FYP_occupytime, add_reagent4_code, add_reagent4_code_length, add_reagent4_FYP_code, add_reagent4_FYP_code_length);
		adjust_time = add_reagent4_real_starttime - add_reagent4_starttime;
		if (adjust_time > 0)
			continue;

		mix2_starttime = connect.mix_after_reagent(add_reagent4_real_starttime, add_reagent4_code_length);
		plan.mix(mix2_starttime, QB_FYP_use_holeNO, SampleNO, add_mix2_real_starttime, FYP_add_mix2_time, FYP_add_mix2_starttime,
			add_mix2_FYP_occupytime, add_mix2_code, add_mix2_code_length, add_mix2_FYP_code, add_mix2_FYP_code_length);
		adjust_time = add_mix2_real_starttime - mix2_starttime;
		if (adjust_time > 0)
			continue;

		FYP_out_time = connect.CFL_after_mix(FYP_add_mix2_starttime, add_mix2_FYP_code_length, FY_time);
		plan.FYP2CFL(FYP_out_time, QB_FYP_use_holeNO, FYP2CFL_real_starttime, FYP2CFL_JZ_starttime, FYP2CFL_JZ_code, FYP2CFL_JZ_code_length,
			FYP2CFL_FYP_starttime, FYP2CFL_FYP_code, FYP2CFL_FYP_code_length, CFL_hole_NO, FYP2CFL_CFL_arrive_time);
		adjust_time = FYP2CFL_real_starttime - FYP_out_time;
		if (adjust_time > 0)
			continue;

		CFL2ZDQ_starttime = connect.ZDQ_after_CFL(FYP2CFL_CFL_arrive_time);
		plan.CFL2ZDQ(CFL2ZDQ_starttime, CFL2ZDQ_real_starttime, CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code,
			CFL2ZDQ_JZ_code_length, CFL2ZDQ_ZDQ_arrive_time, CFL2ZDQ_hole_NO);
		adjust_time = CFL2ZDQ_real_starttime - CFL2ZDQ_starttime;
		if (adjust_time > 13)
			continue;

		ZDQ2GJC_starttime = connect.GJC_after_ZDG(CFL2ZDQ_ZDQ_arrive_time);//������������148s
		plan.ZDQ2GJC(ZDQ2GJC_starttime, ZDQ2GJC_real_starttime, CFL2ZDQ_hole_NO, ZDQ2GJC_JZ_starttime,
			ZDQ2GJC_JZ_code, ZDQ2GJC_JZ_code_length, ZDQ2GJC_GJC_arrive_time);
		adjust_time = ZDQ2GJC_real_starttime - ZDQ2GJC_starttime;
		if (adjust_time > 0)
			continue;

		unfinished = false;
	}

	//��Ӳ�������
	//ȡ������
	add_code.add_JZ_move_code(QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code);
	add_code.add_FYP_move_code(QB_FYP_starttime, QB_FYP_code_length, QB_FYP_code);
	//��������
	add_code.add_sample_code(add_sample_real_starttime, add_sample_code_length, add_sample_code);
	add_code.add_FYP_move_code(FYP_add_sample_starttime, add_sample_FYP_code_length, add_sample_FYP_code);
	//�Լ�5����
	add_code.add_SJ_code(add_reagent5_real_starttime, add_reagent5_code_length, add_reagent5_code);
	add_code.add_FYP_move_code(FYP_add_reagent5_starttime, add_reagent5_FYP_code_length, add_reagent5_FYP_code);
	//�ӽ���1����
	add_code.add_mix_code(add_mix1_real_starttime, add_mix1_code_length, add_mix1_code);
	add_code.add_FYP_move_code(FYP_add_mix1_starttime, add_mix1_FYP_code_length, add_mix1_FYP_code);
	//�Լ�1����
	add_code.add_SJ_code(add_reagent1_real_starttime, add_reagent1_code_length, add_reagent1_code);
	add_code.add_FYP_move_code(FYP_add_reagent1_starttime, add_reagent1_FYP_code_length, add_reagent1_FYP_code);
	//�Լ�4����
	add_code.add_SJ_code(add_reagent4_real_starttime, add_reagent4_code_length, add_reagent4_code);
	add_code.add_FYP_move_code(FYP_add_reagent4_starttime, add_reagent4_FYP_code_length, add_reagent4_FYP_code);
	//�ӽ������
	add_code.add_mix_code(add_mix2_real_starttime, add_mix2_code_length, add_mix2_code);
	add_code.add_FYP_move_code(FYP_add_mix2_starttime, add_mix2_FYP_code_length, add_mix2_FYP_code);
	//�����̵��ŷ������
	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime, FYP2CFL_JZ_code_length, FYP2CFL_JZ_code);
	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime, FYP2CFL_FYP_code_length, FYP2CFL_FYP_code);
	add_code.add_FYP_hole_occupy(QB_FYP_use_holeNO, FYP_putcup_time, FYP_out_time);//�����̿�ռ��
	//�ŷ��뵽��������
	add_code.add_JZ_move_code(CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code_length, CFL2ZDQ_JZ_code);
	add_code.add_CFL_hole_occupy(CFL_hole_NO, FYP2CFL_CFL_arrive_time, CFL2ZDQ_real_starttime);//�ŷ����ռ��
	//�������������
	add_code.add_JZ_move_code(ZDQ2GJC_JZ_starttime, ZDQ2GJC_JZ_code_length, ZDQ2GJC_JZ_code);
	add_code.add_ZDQ_hole_occupy(CFL2ZDQ_hole_NO, CFL2ZDQ_ZDQ_arrive_time, ZDQ2GJC_starttime);//������ռ��
	//������̴���
	int GJC_code_length = 0;
	int GJC_code[3][50] = { 0 };
	plan.gjc.createcode(36, mission_NO, GJC_code_length, GJC_code);
	int GJC_starttime = ZDQ2GJC_GJC_arrive_time;
	add_code.add_GJC_code(GJC_starttime - 1, GJC_code_length, GJC_code);
	add_code.add_GJC_hole_occupy(GJC_starttime - 1, GJC_starttime + 43);//�����ռ��
	//������
	add_code.add_ZDQ_motor_code();
	//�ŷ���ת��
	add_code.add_CFL_move_code(GJC_starttime + 1200, cfl_CFLcyclesteptime);
	
	totaltime = GJC_starttime + 1200;

	//��Ӵŷ���ע����Һ�������
	int length = 0;
	int zhushe1_time = 0;
	int paiye1_time = 0;
	int zhushe2_time = 0;
	int paiye2_time = 0;
	int diwu_time = 0;
	int CFLcode1[8][30] = { 0 };
	int CFLcode2[8][30] = { 0 };
	int CFLcode3[8][30] = { 0 };
	int CFLcode4[8][30] = { 0 };
	int CFLcode5[8][30] = { 0 };
	plan.cfl.CFLzhushe1codegenerate(CFLcode1, length);
	plan.cfl.CFLpaiye1codegenerate(CFLcode2, length);
	plan.cfl.CFLzhushe2codegenerate(CFLcode3, length);
	plan.cfl.CFLpaiye2codegenerate(CFLcode4, length);
	plan.cfl.CFLdiwucodegenerate(CFLcode5, length);
	//��һȦ
	zhushe1_time = (FYP2CFL_CFL_arrive_time / 17 + 2) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time / 17 + 5) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time / 17 + 6) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time / 17 + 9) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//�ڶ�Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time / 17 + 2 + 12) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time / 17 + 5 + 12) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time / 17 + 6 + 12) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time / 17 + 9 + 12) * 17 + 1;
	diwu_time = (FYP2CFL_CFL_arrive_time / 17 + 10 + 12) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	add_code.add_CFL_operation_code(diwu_time, length, CFLcode5);
}

//ȡ�������Լ�1�������������Լ�3�����Լ�4������ 
void PRO::CTNI(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R3_Location_NO, int R4_Location_NO, int qb_starttime, int FY_time)
{
	//���Ʊ���
	bool unfinished = true;
	int adjust_time = 0;

	//ȡ����ر���
	int BJ_is_empty = 0;
	int BJ_need_changerow = 0;
	int BJ_changerow_time = 0;
	int BJ_cupNO = 0;
	int QB_JZ_starttime = 0;
	int QB_JZ_code_length = 0;
	int QB_JZ_code[3][100] = { 0 };
	int QB_time = 0;
	int FYP_putcup_time = 0;
	int QB_FYP_starttime = 0;
	int QB_FYP_use_holeNO = 0;
	int QB_FYP_code[50] = { 0 };
	int QB_FYP_code_length = 0;
	int QB_finished_time = 0;
	int BJ_NO = 0;

	//���Լ�1��ر���
	int add_reagent1_starttime = 0;
	int add_reagent1_real_starttime = 0;
	int FYP_add_reagent1_time = 0;
	int FYP_add_reagent1_starttime = 0;
	int addSJ1_FYP_occupytime = 0;
	int add_reagent1_code[8][100] = { 0 };
	int add_reagent1_code_length = 0;
	int add_reagent1_FYP_code[50] = { 0 };
	int add_reagent1_FYP_code_length = 0;

	//��������ر���
	int sample_starttime = 0;
	int add_sample_real_starttime = 0;
	int FYP_add_sample_time = 0;
	int FYP_add_sample_starttime = 0;
	int add_sample_FYP_occupytime = 0;
	int add_sample_code[8][100] = { 0 };
	int add_sample_code_length = 0;
	int add_sample_FYP_code[50] = { 0 };
	int add_sample_FYP_code_length = 0;

	//���Լ�3��ر���
	int add_reagent3_starttime = 0;
	int add_reagent3_real_starttime = 0;
	int FYP_add_reagent3_time = 0;
	int FYP_add_reagent3_starttime = 0;
	int addSJ3_FYP_occupytime = 0;
	int add_reagent3_code[8][100] = { 0 };
	int add_reagent3_code_length = 0;
	int add_reagent3_FYP_code[50] = { 0 };
	int add_reagent3_FYP_code_length = 0;

	//���Լ�4��ر���
	int add_reagent4_starttime = 0;
	int add_reagent4_real_starttime = 0;
	int FYP_add_reagent4_time = 0;
	int FYP_add_reagent4_starttime = 0;
	int addSJ4_FYP_occupytime = 0;
	int add_reagent4_code[8][100] = { 0 };
	int add_reagent4_code_length = 0;
	int add_reagent4_FYP_code[50] = { 0 };
	int add_reagent4_FYP_code_length = 0;

	//������ر���
	int mix_starttime = 0;
	int add_mix_real_starttime = 0;
	int FYP_add_mix_time = 0;
	int FYP_add_mix_starttime = 0;
	int add_mix_FYP_occupytime = 0;
	int add_mix_code[8][100] = { 0 };
	int add_mix_code_length = 0;
	int add_mix_FYP_code[50] = { 0 };
	int add_mix_FYP_code_length = 0;

	//���ŷ�����ر���
	int FYP_out_time = 0;
	int FYP2CFL_real_starttime = 0;
	int FYP2CFL_JZ_starttime = 0;
	int FYP2CFL_JZ_code[3][100]={ 0 };
	int FYP2CFL_JZ_code_length = 0;
	int FYP2CFL_FYP_starttime = 0;
	int FYP2CFL_FYP_code[50] = { 0 };
	int FYP2CFL_FYP_code_length = 0;
	int CFL_hole_NO = 0;
	int FYP2CFL_CFL_arrive_time = 0;

	//�ŷ����������ر���
	int CFL2ZDQ_starttime = 0;
	int CFL2ZDQ_real_starttime = 0;
	int CFL2ZDQ_JZ_starttime = 0;
	int CFL2ZDQ_JZ_code[3][100] = { 0 };
	int CFL2ZDQ_JZ_code_length = 0;
	int CFL2ZDQ_ZDQ_arrive_time = 0;
	int CFL2ZDQ_hole_NO = 0;

	//������������ر���
	int ZDQ2GJC_starttime = 0;
	int ZDQ2GJC_real_starttime = 0;
	int ZDQ2GJC_JZ_starttime = 0;
	int ZDQ2GJC_JZ_code[3][100] = { 0 };
	int ZDQ2GJC_JZ_code_length = 0;
	int ZDQ2GJC_GJC_arrive_time = 0;

	plan.qb(qb_starttime, BJ_is_empty, BJ_need_changerow, BJ_changerow_time, BJ_cupNO, QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code,
		QB_time, FYP_putcup_time, QB_FYP_starttime, QB_FYP_use_holeNO, QB_FYP_code, QB_FYP_code_length, QB_finished_time,BJ_NO);
	plan.set_BJ_state(GBJ_Content);
	//������ز���
	if (BJ_NO == 0)
	{
		//���뻻����������
		int code[10] = { 0 };
		int CodeLength1;
		CodeLength1 = plan.bj.BJmovnextrow(code);
		int time = QB_JZ_starttime + jz_downtime + jz_opentime + jz_uptime + jz_movetime;
		for (int j = 0; j < CodeLength1; j++)
			xy[8][j + time] = code[j];
	}
	add_reagent1_starttime = connect.reagent_after_qb(QB_finished_time);

	while (unfinished)
	{
		add_reagent1_starttime += adjust_time;

		plan.add_reagent(10, add_reagent1_starttime, QB_FYP_use_holeNO, R1_location_NO, Reagent_Bin_NO, add_reagent1_real_starttime,
			FYP_add_reagent1_time, FYP_add_reagent1_starttime, addSJ1_FYP_occupytime, add_reagent1_code, add_reagent1_code_length,
			add_reagent1_FYP_code, add_reagent1_FYP_code_length);
		adjust_time = add_reagent1_real_starttime - add_reagent1_starttime;
		if (adjust_time > 0)
			continue;

		sample_starttime = connect.sample_after_reagent(add_reagent1_real_starttime, add_reagent1_code_length);
		plan.add_sample(12,sample_starttime, QB_FYP_use_holeNO, SampleNO, add_sample_real_starttime, FYP_add_sample_time,
			FYP_add_sample_starttime, add_sample_FYP_occupytime, add_sample_code, add_sample_code_length, add_sample_FYP_code,
			add_sample_FYP_code_length);
		adjust_time = add_sample_real_starttime - sample_starttime;
		if (adjust_time > 0)
			continue;
		
		add_reagent3_starttime = connect.reagent_after_sample(add_sample_real_starttime, add_sample_code_length);
		plan.add_reagent(10,add_reagent3_starttime, QB_FYP_use_holeNO, R3_Location_NO, Reagent_Bin_NO, add_reagent3_real_starttime, FYP_add_reagent3_time, 
			FYP_add_reagent3_starttime, addSJ3_FYP_occupytime, add_reagent3_code, add_reagent3_code_length,add_reagent3_FYP_code, add_reagent3_FYP_code_length);
		adjust_time = add_reagent3_real_starttime - add_reagent3_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent4_starttime = connect.reagent_after_reagent(add_reagent3_real_starttime, add_reagent3_code_length);
		plan.add_reagent(10,add_reagent4_starttime, QB_FYP_use_holeNO, R4_Location_NO, Reagent_Bin_NO, add_reagent4_real_starttime, FYP_add_reagent4_time, 
			FYP_add_reagent4_starttime, addSJ4_FYP_occupytime,add_reagent4_code,add_reagent4_code_length,
			add_reagent4_FYP_code, add_reagent4_FYP_code_length);
		adjust_time = add_reagent4_real_starttime - add_reagent4_starttime;
		if (adjust_time > 0)
			continue;
		
		mix_starttime = connect.mix_after_reagent(add_reagent4_real_starttime, add_reagent4_code_length);
		plan.mix(mix_starttime, QB_FYP_use_holeNO, SampleNO, add_mix_real_starttime, FYP_add_mix_time,
			FYP_add_mix_starttime, add_mix_FYP_occupytime, add_mix_code, add_mix_code_length, add_mix_FYP_code,
			add_mix_FYP_code_length);
		adjust_time = add_mix_real_starttime - mix_starttime;
		if (adjust_time > 0)
			continue;

		FYP_out_time = connect.CFL_after_mix(FYP_add_mix_starttime, add_mix_FYP_code_length, FY_time);
		plan.FYP2CFL(FYP_out_time, QB_FYP_use_holeNO, FYP2CFL_real_starttime, FYP2CFL_JZ_starttime, FYP2CFL_JZ_code, FYP2CFL_JZ_code_length,
			FYP2CFL_FYP_starttime, FYP2CFL_FYP_code, FYP2CFL_FYP_code_length, CFL_hole_NO, FYP2CFL_CFL_arrive_time);
		adjust_time = FYP2CFL_real_starttime - FYP_out_time;
		if (adjust_time > 0)
			continue;

		CFL2ZDQ_starttime = connect.ZDQ_after_CFL(FYP2CFL_CFL_arrive_time);
		plan.CFL2ZDQ(CFL2ZDQ_starttime, CFL2ZDQ_real_starttime, CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code,
			CFL2ZDQ_JZ_code_length, CFL2ZDQ_ZDQ_arrive_time, CFL2ZDQ_hole_NO);
		adjust_time = CFL2ZDQ_real_starttime - CFL2ZDQ_starttime;
		if (adjust_time > 13)
			continue;

		ZDQ2GJC_starttime = connect.GJC_after_ZDG(CFL2ZDQ_ZDQ_arrive_time);//������������148s
		plan.ZDQ2GJC(ZDQ2GJC_starttime, ZDQ2GJC_real_starttime, CFL2ZDQ_hole_NO, ZDQ2GJC_JZ_starttime,
			ZDQ2GJC_JZ_code, ZDQ2GJC_JZ_code_length, ZDQ2GJC_GJC_arrive_time);
		adjust_time = ZDQ2GJC_real_starttime - ZDQ2GJC_starttime;
		if (adjust_time > 0)
			continue;
		unfinished = false;
	}

	//��Ӳ�������
	//ȡ������
	add_code.add_JZ_move_code(QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code);
	add_code.add_FYP_move_code(QB_FYP_starttime, QB_FYP_code_length, QB_FYP_code);
	//�Լ�1����
	add_code.add_SJ_code(add_reagent1_real_starttime, add_reagent1_code_length, add_reagent1_code);
	add_code.add_FYP_move_code(FYP_add_reagent1_starttime, add_reagent1_FYP_code_length, add_reagent1_FYP_code);
	//��������
	add_code.add_sample_code(add_sample_real_starttime, add_sample_code_length, add_sample_code);
	add_code.add_FYP_move_code(FYP_add_sample_starttime, add_sample_FYP_code_length, add_sample_FYP_code);
	//�Լ�3����
	add_code.add_SJ_code(add_reagent3_real_starttime, add_reagent3_code_length, add_reagent3_code);
	add_code.add_FYP_move_code(FYP_add_reagent3_starttime, add_reagent3_FYP_code_length, add_reagent3_FYP_code);
	//�Լ�4����
	add_code.add_SJ_code(add_reagent4_real_starttime, add_reagent4_code_length, add_reagent4_code);
	add_code.add_FYP_move_code(FYP_add_reagent4_starttime, add_reagent4_FYP_code_length, add_reagent4_FYP_code);
	//�ӽ������
	add_code.add_mix_code(add_mix_real_starttime, add_mix_code_length, add_mix_code);
	add_code.add_FYP_move_code(FYP_add_mix_starttime, add_mix_FYP_code_length, add_mix_FYP_code);
	//�����̵��ŷ������
	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime, FYP2CFL_JZ_code_length, FYP2CFL_JZ_code);
	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime, FYP2CFL_FYP_code_length, FYP2CFL_FYP_code);
	add_code.add_FYP_hole_occupy(QB_FYP_use_holeNO, FYP_putcup_time, FYP_out_time);//�����̿�ռ��
	//�ŷ��뵽��������
	add_code.add_JZ_move_code(CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code_length, CFL2ZDQ_JZ_code);
	add_code.add_CFL_hole_occupy(CFL_hole_NO, FYP2CFL_CFL_arrive_time, CFL2ZDQ_real_starttime);//�ŷ����ռ��
	//�������������
	add_code.add_JZ_move_code(ZDQ2GJC_JZ_starttime, ZDQ2GJC_JZ_code_length, ZDQ2GJC_JZ_code);
	add_code.add_ZDQ_hole_occupy(CFL2ZDQ_hole_NO, CFL2ZDQ_ZDQ_arrive_time, ZDQ2GJC_real_starttime);//������ռ��
	//������̴���
	int GJC_code_length = 0;
	int GJC_code[3][50] = { 0 };
	plan.gjc.createcode(36, mission_NO, GJC_code_length, GJC_code);
	int GJC_starttime = ZDQ2GJC_GJC_arrive_time;
	add_code.add_GJC_code(GJC_starttime - 1, GJC_code_length, GJC_code);
	add_code.add_GJC_hole_occupy(GJC_starttime - 1, GJC_starttime + 43);//�����ռ��
	//������
	add_code.add_ZDQ_motor_code();
	//�ŷ���ת��
	add_code.add_CFL_move_code(GJC_starttime + 1200, cfl_CFLcyclesteptime);
	
	totaltime = GJC_starttime + 1200;
	

	//��Ӵŷ���ע����Һ�������
	int length = 0;
	int zhushe1_time = 0;
	int paiye1_time = 0;
	int zhushe2_time = 0;
	int paiye2_time = 0;
	int diwu_time = 0;
	int CFLcode1[8][30] = { 0 };
	int CFLcode2[8][30] = { 0 };
	int CFLcode3[8][30] = { 0 };
	int CFLcode4[8][30] = { 0 };
	int CFLcode5[8][30] = { 0 };
	plan.cfl.CFLzhushe1codegenerate(CFLcode1, length);
	plan.cfl.CFLpaiye1codegenerate(CFLcode2, length);
	plan.cfl.CFLzhushe2codegenerate(CFLcode3, length);
	plan.cfl.CFLpaiye2codegenerate(CFLcode4, length);
	plan.cfl.CFLdiwucodegenerate(CFLcode5, length);
	//��һȦ
	zhushe1_time = (FYP2CFL_CFL_arrive_time / 17 + 2) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time / 17 + 5) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time / 17 + 6) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time / 17 + 9) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//�ڶ�Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time / 17 + 2 + 12) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time / 17 + 5 + 12) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time / 17 + 6 + 12) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time / 17 + 9 + 12) * 17 + 1;
	diwu_time = (FYP2CFL_CFL_arrive_time / 17 + 10 + 12) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	add_code.add_CFL_operation_code(diwu_time, length, CFLcode5);

}

//������ȫѪ����Һ���Լ�5��������1���Լ�1���Լ�3���Լ�4������2����������ϴ������Һ���𵴡����
void PRO::CTNI_whole(int mission_NO, int SampleNO, int Reagent_Bin_NO, int Second_Reagent_Bin_NO, int R1_location_NO, int R3_Location_NO, int R4_Location_NO, int R5_Location_NO, int qb_starttime, int FY_time)
{
	//���Ʊ���
	bool unfinished = true;
	int adjust_time = 0;

	//ȡ����ر���
	int BJ_is_empty = 0;
	int BJ_need_changerow = 0;
	int BJ_changerow_time = 0;
	int BJ_cupNO = 0;
	int QB_JZ_starttime = 0;
	int QB_JZ_code_length = 0;
	int QB_JZ_code[3][100] = { 0 };
	int QB_time = 0;
	int FYP_putcup_time = 0;
	int QB_FYP_starttime = 0;
	int QB_FYP_use_holeNO = 0;
	int QB_FYP_code[50] = { 0 };
	int QB_FYP_code_length = 0;
	int QB_finished_time = 0;
	int BJ_NO = 0;

	//��������ر���
	int sample_starttime = 0;
	int add_sample_real_starttime = 0;
	int FYP_add_sample_time = 0;
	int FYP_add_sample_starttime = 0;
	int add_sample_FYP_occupytime = 0;
	int add_sample_code[8][100] = { 0 };
	int add_sample_code_length = 0;
	int add_sample_FYP_code[50] = { 0 };
	int add_sample_FYP_code_length = 0;

	//���Լ�5��ر���
	int add_reagent5_starttime = 0;
	int add_reagent5_real_starttime = 0;
	int FYP_add_reagent5_time = 0;
	int FYP_add_reagent5_starttime = 0;
	int addSJ5_FYP_occupytime = 0;
	int add_reagent5_code[8][100] = { 0 };
	int add_reagent5_code_length = 0;
	int add_reagent5_FYP_code[50] = { 0 };
	int add_reagent5_FYP_code_length = 0;

	//����1��ر���
	int mix1_starttime = 0;
	int add_mix1_real_starttime = 0;
	int FYP_add_mix1_time = 0;
	int FYP_add_mix1_starttime = 0;
	int add_mix1_FYP_occupytime = 0;
	int add_mix1_code[8][100] = { 0 };
	int add_mix1_code_length = 0;
	int add_mix1_FYP_code[50] = { 0 };
	int add_mix1_FYP_code_length = 0;

	//���Լ�1��ر���
	int add_reagent1_starttime = 0;
	int add_reagent1_real_starttime = 0;
	int FYP_add_reagent1_time = 0;
	int FYP_add_reagent1_starttime = 0;
	int addSJ1_FYP_occupytime = 0;
	int add_reagent1_code[8][100] = { 0 };
	int add_reagent1_code_length = 0;
	int add_reagent1_FYP_code[50] = { 0 };
	int add_reagent1_FYP_code_length = 0;

	//���Լ�3��ر���
	int add_reagent3_starttime = 0;
	int add_reagent3_real_starttime = 0;
	int FYP_add_reagent3_time = 0;
	int FYP_add_reagent3_starttime = 0;
	int addSJ3_FYP_occupytime = 0;
	int add_reagent3_code[8][100] = { 0 };
	int add_reagent3_code_length = 0;
	int add_reagent3_FYP_code[50] = { 0 };
	int add_reagent3_FYP_code_length = 0;

	//���Լ�4��ر���
	int add_reagent4_starttime = 0;
	int add_reagent4_real_starttime = 0;
	int FYP_add_reagent4_time = 0;
	int FYP_add_reagent4_starttime = 0;
	int addSJ4_FYP_occupytime = 0;
	int add_reagent4_code[8][100] = { 0 };
	int add_reagent4_code_length = 0;
	int add_reagent4_FYP_code[50] = { 0 };
	int add_reagent4_FYP_code_length = 0;

	//����2��ر���
	int mix2_starttime = 0;
	int add_mix2_real_starttime = 0;
	int FYP_add_mix2_time = 0;
	int FYP_add_mix2_starttime = 0;
	int add_mix2_FYP_occupytime = 0;
	int add_mix2_code[8][100] = { 0 };
	int add_mix2_code_length = 0;
	int add_mix2_FYP_code[50] = { 0 };
	int add_mix2_FYP_code_length = 0;

	//���ŷ�����ر���
	int FYP_out_time = 0;
	int FYP2CFL_real_starttime = 0;
	int FYP2CFL_JZ_starttime = 0;
	int FYP2CFL_JZ_code[3][100]={ 0 };
	int FYP2CFL_JZ_code_length = 0;
	int FYP2CFL_FYP_starttime = 0;
	int FYP2CFL_FYP_code[50] = { 0 };
	int FYP2CFL_FYP_code_length = 0;
	int CFL_hole_NO = 0;
	int FYP2CFL_CFL_arrive_time = 0;

	//�ŷ����������ر���
	int CFL2ZDQ_starttime = 0;
	int CFL2ZDQ_real_starttime = 0;
	int CFL2ZDQ_JZ_starttime = 0;
	int CFL2ZDQ_JZ_code[3][100] = { 0 };
	int CFL2ZDQ_JZ_code_length = 0;
	int CFL2ZDQ_ZDQ_arrive_time = 0;
	int CFL2ZDQ_hole_NO = 0;

	//������������ر���
	int ZDQ2GJC_starttime = 0;
	int ZDQ2GJC_real_starttime = 0;
	int ZDQ2GJC_JZ_starttime = 0;
	int ZDQ2GJC_JZ_code[3][100] = { 0 };
	int ZDQ2GJC_JZ_code_length = 0;
	int ZDQ2GJC_GJC_arrive_time = 0;

	plan.qb(qb_starttime, BJ_is_empty, BJ_need_changerow, BJ_changerow_time, BJ_cupNO, QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code,
		QB_time, FYP_putcup_time, QB_FYP_starttime, QB_FYP_use_holeNO, QB_FYP_code, QB_FYP_code_length, QB_finished_time,BJ_NO);
	plan.set_BJ_state(GBJ_Content);
	//������ز���
	if (BJ_NO == 0)
	{
		//���뻻����������
		int code[10] = { 0 };
		int CodeLength1;
		CodeLength1 = plan.bj.BJmovnextrow(code);
		int time = QB_JZ_starttime + jz_downtime + jz_opentime + jz_uptime + jz_movetime;
		for (int j = 0; j < CodeLength1; j++)
			xy[8][j + time] = code[j];
	}
	sample_starttime = connect.sample_after_qb(QB_finished_time);

	while (unfinished)
	{
		sample_starttime += adjust_time;

		plan.add_sample(12, sample_starttime, QB_FYP_use_holeNO, SampleNO, add_sample_real_starttime, FYP_add_sample_time,
			FYP_add_sample_starttime, add_sample_FYP_occupytime, add_sample_code, add_sample_code_length, add_sample_FYP_code,
			add_sample_FYP_code_length);
		adjust_time = add_sample_real_starttime - sample_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent5_starttime = connect.reagent_after_sample(add_sample_real_starttime, add_sample_code_length);
		plan.add_reagent(10, add_reagent5_starttime, QB_FYP_use_holeNO, R5_Location_NO, Second_Reagent_Bin_NO, add_reagent5_real_starttime, FYP_add_reagent5_time,
			FYP_add_reagent5_starttime, addSJ5_FYP_occupytime, add_reagent5_code, add_reagent5_code_length, add_reagent5_FYP_code, add_reagent5_FYP_code_length);
		adjust_time = add_reagent5_real_starttime - add_reagent5_starttime;
		if (adjust_time > 0)
			continue;

		mix1_starttime = connect.mix_after_reagent(add_reagent5_real_starttime, add_reagent5_code_length);
		plan.mix(mix1_starttime, QB_FYP_use_holeNO, SampleNO, add_mix1_real_starttime, FYP_add_mix1_time, FYP_add_mix1_starttime,
			add_mix1_FYP_occupytime, add_mix1_code, add_mix1_code_length, add_mix1_FYP_code, add_mix1_FYP_code_length);
		adjust_time = add_mix1_real_starttime - mix1_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent1_starttime = connect.reagent_after_mix(add_mix1_real_starttime, add_mix1_code_length);
		plan.add_reagent(10, add_reagent1_starttime, QB_FYP_use_holeNO, R1_location_NO, Reagent_Bin_NO, add_reagent1_real_starttime,
			FYP_add_reagent1_time, FYP_add_reagent1_starttime, addSJ1_FYP_occupytime, add_reagent1_code, add_reagent1_code_length,
			add_reagent1_FYP_code, add_reagent1_FYP_code_length);
		adjust_time = add_reagent1_real_starttime - add_reagent1_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent3_starttime = connect.reagent_after_reagent(add_reagent1_real_starttime, add_reagent1_code_length);
		plan.add_reagent(10, add_reagent3_starttime, QB_FYP_use_holeNO, R3_Location_NO, Reagent_Bin_NO, add_reagent3_real_starttime, FYP_add_reagent3_time,
			FYP_add_reagent3_starttime, addSJ3_FYP_occupytime, add_reagent3_code, add_reagent3_code_length, add_reagent3_FYP_code, add_reagent3_FYP_code_length);
		adjust_time = add_reagent3_real_starttime - add_reagent3_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent4_starttime = connect.reagent_after_reagent(add_reagent3_real_starttime, add_reagent3_code_length);
		plan.add_reagent(10, add_reagent4_starttime, QB_FYP_use_holeNO, R4_Location_NO, Reagent_Bin_NO, add_reagent4_real_starttime, FYP_add_reagent4_time,
			FYP_add_reagent4_starttime, addSJ4_FYP_occupytime, add_reagent4_code, add_reagent4_code_length, add_reagent4_FYP_code, add_reagent4_FYP_code_length);
		adjust_time = add_reagent4_real_starttime - add_reagent4_starttime;
		if (adjust_time > 0)
			continue;

		mix2_starttime = connect.mix_after_reagent(add_reagent4_real_starttime, add_reagent4_code_length);
		plan.mix(mix2_starttime, QB_FYP_use_holeNO, SampleNO, add_mix2_real_starttime, FYP_add_mix2_time, FYP_add_mix2_starttime,
			add_mix2_FYP_occupytime, add_mix2_code, add_mix2_code_length, add_mix2_FYP_code, add_mix2_FYP_code_length);
		adjust_time = add_mix2_real_starttime - mix2_starttime;
		if (adjust_time > 0)
			continue;

		FYP_out_time = connect.CFL_after_mix(FYP_add_mix2_starttime, add_mix2_FYP_code_length, FY_time);
		plan.FYP2CFL(FYP_out_time, QB_FYP_use_holeNO, FYP2CFL_real_starttime, FYP2CFL_JZ_starttime, FYP2CFL_JZ_code, FYP2CFL_JZ_code_length,
			FYP2CFL_FYP_starttime, FYP2CFL_FYP_code, FYP2CFL_FYP_code_length, CFL_hole_NO, FYP2CFL_CFL_arrive_time);
		adjust_time = FYP2CFL_real_starttime - FYP_out_time;
		if (adjust_time > 0)
			continue;

		CFL2ZDQ_starttime = connect.ZDQ_after_CFL(FYP2CFL_CFL_arrive_time);
		plan.CFL2ZDQ(CFL2ZDQ_starttime, CFL2ZDQ_real_starttime, CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code,
			CFL2ZDQ_JZ_code_length, CFL2ZDQ_ZDQ_arrive_time, CFL2ZDQ_hole_NO);
		adjust_time = CFL2ZDQ_real_starttime - CFL2ZDQ_starttime;
		if (adjust_time > 13)
			continue;

		ZDQ2GJC_starttime = connect.GJC_after_ZDG(CFL2ZDQ_ZDQ_arrive_time);//������������148s
		plan.ZDQ2GJC(ZDQ2GJC_starttime, ZDQ2GJC_real_starttime, CFL2ZDQ_hole_NO, ZDQ2GJC_JZ_starttime,
			ZDQ2GJC_JZ_code, ZDQ2GJC_JZ_code_length, ZDQ2GJC_GJC_arrive_time);
		adjust_time = ZDQ2GJC_real_starttime - ZDQ2GJC_starttime;
		if (adjust_time > 0)
			continue;

		unfinished = false;
	}

	//��Ӳ�������
	//ȡ������
	add_code.add_JZ_move_code(QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code);
	add_code.add_FYP_move_code(QB_FYP_starttime, QB_FYP_code_length, QB_FYP_code);
	//��������
	add_code.add_sample_code(add_sample_real_starttime, add_sample_code_length, add_sample_code);
	add_code.add_FYP_move_code(FYP_add_sample_starttime, add_sample_FYP_code_length, add_sample_FYP_code);
	//�Լ�5����
	add_code.add_SJ_code(add_reagent5_real_starttime, add_reagent5_code_length, add_reagent5_code);
	add_code.add_FYP_move_code(FYP_add_reagent5_starttime, add_reagent5_FYP_code_length, add_reagent5_FYP_code);
	//�ӽ���1����
	add_code.add_mix_code(add_mix1_real_starttime, add_mix1_code_length, add_mix1_code);
	add_code.add_FYP_move_code(FYP_add_mix1_starttime, add_mix1_FYP_code_length, add_mix1_FYP_code);
	//�Լ�1����
	add_code.add_SJ_code(add_reagent1_real_starttime, add_reagent1_code_length, add_reagent1_code);
	add_code.add_FYP_move_code(FYP_add_reagent1_starttime, add_reagent1_FYP_code_length, add_reagent1_FYP_code);
	//�Լ�3����
	add_code.add_SJ_code(add_reagent3_real_starttime, add_reagent3_code_length, add_reagent3_code);
	add_code.add_FYP_move_code(FYP_add_reagent3_starttime, add_reagent3_FYP_code_length, add_reagent3_FYP_code);
	//�Լ�4����
	add_code.add_SJ_code(add_reagent4_real_starttime, add_reagent4_code_length, add_reagent4_code);
	add_code.add_FYP_move_code(FYP_add_reagent4_starttime, add_reagent4_FYP_code_length, add_reagent4_FYP_code);
	//�ӽ���2����
	add_code.add_mix_code(add_mix2_real_starttime, add_mix2_code_length, add_mix2_code);
	add_code.add_FYP_move_code(FYP_add_mix2_starttime, add_mix2_FYP_code_length, add_mix2_FYP_code);
	//�����̵��ŷ������
	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime, FYP2CFL_JZ_code_length, FYP2CFL_JZ_code);
	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime, FYP2CFL_FYP_code_length, FYP2CFL_FYP_code);
	add_code.add_FYP_hole_occupy(QB_FYP_use_holeNO, FYP_putcup_time, FYP_out_time);//�����̿�ռ��
	//�ŷ��뵽��������
	add_code.add_JZ_move_code(CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code_length, CFL2ZDQ_JZ_code);
	add_code.add_CFL_hole_occupy(CFL_hole_NO, FYP2CFL_CFL_arrive_time, CFL2ZDQ_real_starttime);//�ŷ����ռ��
	//�������������
	add_code.add_JZ_move_code(ZDQ2GJC_JZ_starttime, ZDQ2GJC_JZ_code_length, ZDQ2GJC_JZ_code);
	add_code.add_ZDQ_hole_occupy(CFL2ZDQ_hole_NO, CFL2ZDQ_ZDQ_arrive_time, ZDQ2GJC_starttime);//������ռ��
	//������̴���
	int GJC_code_length = 0;
	int GJC_code[3][50] = { 0 };
	plan.gjc.createcode(36, mission_NO, GJC_code_length, GJC_code);
	int GJC_starttime = ZDQ2GJC_GJC_arrive_time;
	add_code.add_GJC_code(GJC_starttime - 1, GJC_code_length, GJC_code);
	add_code.add_GJC_hole_occupy(GJC_starttime - 1, GJC_starttime + 43);//�����ռ��
	//������
	add_code.add_ZDQ_motor_code();
	//�ŷ���ת��
	add_code.add_CFL_move_code(GJC_starttime + 1200, cfl_CFLcyclesteptime);
	
	totaltime = GJC_starttime + 1200;

	//��Ӵŷ���ע����Һ�������
	int length = 0;
	int zhushe1_time = 0;
	int paiye1_time = 0;
	int zhushe2_time = 0;
	int paiye2_time = 0;
	int diwu_time = 0;
	int CFLcode1[8][30] = { 0 };
	int CFLcode2[8][30] = { 0 };
	int CFLcode3[8][30] = { 0 };
	int CFLcode4[8][30] = { 0 };
	int CFLcode5[8][30] = { 0 };
	plan.cfl.CFLzhushe1codegenerate(CFLcode1, length);
	plan.cfl.CFLpaiye1codegenerate(CFLcode2, length);
	plan.cfl.CFLzhushe2codegenerate(CFLcode3, length);
	plan.cfl.CFLpaiye2codegenerate(CFLcode4, length);
	plan.cfl.CFLdiwucodegenerate(CFLcode5, length);
	//��һȦ
	zhushe1_time = (FYP2CFL_CFL_arrive_time / 17 + 2) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time / 17 + 5) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time / 17 + 6) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time / 17 + 9) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//�ڶ�Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time / 17 + 2 + 12) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time / 17 + 5 + 12) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time / 17 + 6 + 12) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time / 17 + 9 + 12) * 17 + 1;
	diwu_time = (FYP2CFL_CFL_arrive_time / 17 + 10 + 12) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	add_code.add_CFL_operation_code(diwu_time, length, CFLcode5);
}

//����������ϡ��Һ���Լ�0��������1���������Լ�1���Լ�4������2����������ϴ������Һ���𵴡����
void PRO::SAA(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R4_Location_NO, int qb_starttime, int FY_time)
{
	//���Ʊ���
	bool unfinished = true;
	int adjust_time = 0;

	//ȡ��1��ر���
	int BJ_is_empty1 = 0;
	int BJ_need_changerow1 = 0;
	int BJ_changerow_time1 = 0;
	int BJ_cupNO1 = 0;
	int QB1_JZ_starttime = 0;
	int QB1_JZ_code_length = 0;
	int QB1_JZ_code[3][100] = { 0 };
	int QB1_time = 0;
	int FYP_putcup_time1 = 0;
	int QB1_FYP_starttime = 0;
	int QB1_FYP_use_holeNO = 0;
	int QB1_FYP_code[50] = { 0 };
	int QB1_FYP_code_length = 0;
	int QB1_finished_time = 0;
	int BJ_NO1 = 0;

	//��������ر���
	int sample_starttime = 0;
	int add_sample_real_starttime = 0;
	int FYP_add_sample_time = 0;
	int FYP_add_sample_starttime = 0;
	int add_sample_FYP_occupytime = 0;
	int add_sample_code[8][100] = { 0 };
	int add_sample_code_length = 0;
	int add_sample_FYP_code[50] = { 0 };
	int add_sample_FYP_code_length = 0;

	//���Լ�0��ر���
	int add_reagent0_starttime = 0;
	int add_reagent0_real_starttime = 0;
	int FYP_add_reagent0_time = 0;
	int FYP_add_reagent0_starttime = 0;
	int addSJ0_FYP_occupytime = 0;
	int add_reagent0_code[8][100] = { 0 };
	int add_reagent0_code_length = 0;
	int add_reagent0_FYP_code[50] = { 0 };
	int add_reagent0_FYP_code_length = 0;

	//����1��ر���
	int mix1_starttime = 0;
	int add_mix1_real_starttime = 0;
	int FYP_add_mix1_time = 0;
	int FYP_add_mix1_starttime = 0;
	int add_mix1_FYP_occupytime = 0;
	int add_mix1_code[8][100] = { 0 };
	int add_mix1_code_length = 0;
	int add_mix1_FYP_code[50] = { 0 };
	int add_mix1_FYP_code_length = 0;

	//ȡ��2��ر���
	int BJ_is_empty2 = 0;
	int BJ_need_changerow2 = 0;
	int BJ_changerow_time2 = 0;
	int BJ_cupNO2 = 0;
	int QB2_JZ_starttime = 0;
	int QB2_JZ_code_length = 0;
	int QB2_JZ_code[3][100] = { 0 };
	int QB2_time = 0;
	int FYP_putcup_time2 = 0;
	int QB2_FYP_starttime = 0;
	int QB2_FYP_use_holeNO = 0;
	int QB2_FYP_code[50] = { 0 };
	int QB2_FYP_code_length = 0;
	int QB2_finished_time = 0;
	int BJ_NO2 = 0;

	//�ӱ���ȡ������ر���
	int add_sample_from_cup_starttime = 0;
	int add_sample_from_cup_real_starttime = 0;
	int GetSampleFromCupFYPstarttime1 = 0;
	int add_sample_from_FYP_code[50] = { 0 };
	int add_sample_from_FYP_code_length = 0;
	int GetSampleFromCupFYPstarttime2 = 0;
	int add_sample_back_FYP_code[50] = { 0 };
	int add_sample_back_FYP_code_length = 0;
	int GetSampleFromCupCodeStarttime = 0;
	int get_sample_code[8][100] = { 0 };
	int get_sample_code_length = 0;
	int add_sample_from_cup_finish_time = 0;

	//���Լ�1��ر���
	int add_reagent1_starttime = 0;
	int add_reagent1_real_starttime = 0;
	int FYP_add_reagent1_time = 0;
	int FYP_add_reagent1_starttime = 0;
	int addSJ1_FYP_occupytime = 0;
	int add_reagent1_code[8][100] = { 0 };
	int add_reagent1_code_length = 0;
	int add_reagent1_FYP_code[50] = { 0 };
	int add_reagent1_FYP_code_length = 0;

	//���Լ�4��ر���
	int add_reagent4_starttime = 0;
	int add_reagent4_real_starttime = 0;
	int FYP_add_reagent4_time = 0;
	int FYP_add_reagent4_starttime = 0;
	int addSJ4_FYP_occupytime = 0;
	int add_reagent4_code[8][100] = { 0 };
	int add_reagent4_code_length = 0;
	int add_reagent4_FYP_code[50] = { 0 };
	int add_reagent4_FYP_code_length = 0;

	//����2��ر���
	int mix2_starttime = 0;
	int add_mix2_real_starttime = 0;
	int FYP_add_mix2_time = 0;
	int FYP_add_mix2_starttime = 0;
	int add_mix2_FYP_occupytime = 0;
	int add_mix2_code[8][100] = { 0 };
	int add_mix2_code_length = 0;
	int add_mix2_FYP_code[50] = { 0 };
	int add_mix2_FYP_code_length = 0;

	//���ŷ�����ر���
	int FYP_out_time = 0;
	int FYP2CFL_real_starttime = 0;
	int FYP2CFL_JZ_starttime = 0;
	int FYP2CFL_JZ_code[3][100] = { 0 };
	int FYP2CFL_JZ_code_length = 0;
	int FYP2CFL_FYP_starttime = 0;
	int FYP2CFL_FYP_code[50] = { 0 };
	int FYP2CFL_FYP_code_length = 0;
	int CFL_hole_NO = 0;
	int FYP2CFL_CFL_arrive_time = 0;

	//�ŷ����������ر���
	int CFL2ZDQ_starttime = 0;
	int CFL2ZDQ_real_starttime = 0;
	int CFL2ZDQ_JZ_starttime = 0;
	int CFL2ZDQ_JZ_code[3][100] = { 0 };
	int CFL2ZDQ_JZ_code_length = 0;
	int CFL2ZDQ_ZDQ_arrive_time = 0;
	int CFL2ZDQ_hole_NO = 0;

	//������������ر���
	int ZDQ2GJC_starttime = 0;
	int ZDQ2GJC_real_starttime = 0;
	int ZDQ2GJC_JZ_starttime = 0;
	int ZDQ2GJC_JZ_code[3][100] = { 0 };
	int ZDQ2GJC_JZ_code_length = 0;
	int ZDQ2GJC_GJC_arrive_time = 0;

	plan.qb(qb_starttime, BJ_is_empty1, BJ_need_changerow1, BJ_changerow_time1, BJ_cupNO1, QB1_JZ_starttime, QB1_JZ_code_length, QB1_JZ_code,
		QB1_time, FYP_putcup_time1, QB1_FYP_starttime, QB1_FYP_use_holeNO, QB1_FYP_code, QB1_FYP_code_length, QB1_finished_time, BJ_NO1);
	plan.set_BJ_state(GBJ_Content);

	if (BJ_NO1 == 0)
	{

		//���뻻����������
		int code[10] = { 0 };
		int CodeLength1;
		CodeLength1 = plan.bj.BJmovnextrow(code);
		int time = QB1_JZ_starttime + jz_downtime + jz_opentime + jz_uptime + jz_movetime;
		for (int j = 0; j < CodeLength1; j++)
			xy[8][j + time] = code[j];
	}
	
	int QB1_FYP_occupy = FYP_putcup_time1;
	while (true)
	{
		QB1_FYP_occupy++;
		plan.qb(QB1_finished_time, BJ_is_empty2, BJ_need_changerow2, BJ_changerow_time2, BJ_cupNO2, QB2_JZ_starttime, QB2_JZ_code_length, QB2_JZ_code,
			QB2_time, FYP_putcup_time2, QB2_FYP_starttime, QB2_FYP_use_holeNO, QB2_FYP_code, QB2_FYP_code_length, QB2_finished_time, BJ_NO2);
		if (QB2_FYP_use_holeNO == QB1_FYP_use_holeNO)
			add_code.add_FYP_hole_occupy(QB1_FYP_use_holeNO, FYP_putcup_time1, QB1_FYP_occupy);//�����̿�ռ��
		else
			break;
	}
	plan.set_BJ_state(GBJ_Content);

	if (BJ_NO2 == 0)
	{

		//���뻻����������
		int code[10] = { 0 };
		int CodeLength1;
		CodeLength1 = plan.bj.BJmovnextrow(code);
		int time = QB2_JZ_starttime + jz_downtime + jz_opentime + jz_uptime + jz_movetime;
		for (int j = 0; j < CodeLength1; j++)
			xy[8][j + time] = code[j];
	}

	sample_starttime = connect.sample_after_qb(QB2_finished_time);
	while (unfinished)
	{
		sample_starttime += adjust_time;

		plan.add_sample(9, sample_starttime, QB1_FYP_use_holeNO, SampleNO, add_sample_real_starttime, FYP_add_sample_time,
			FYP_add_sample_starttime, add_sample_FYP_occupytime, add_sample_code, add_sample_code_length, add_sample_FYP_code,
			add_sample_FYP_code_length);
		adjust_time = add_sample_real_starttime - sample_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent0_starttime = connect.reagent_after_sample(add_sample_real_starttime, add_sample_code_length);
		plan.add_reagent(9, add_reagent0_starttime, QB1_FYP_use_holeNO, -1, -1, add_reagent0_real_starttime, FYP_add_reagent0_time,
			FYP_add_reagent0_starttime, addSJ0_FYP_occupytime, add_reagent0_code, add_reagent0_code_length, add_reagent0_FYP_code, add_reagent0_FYP_code_length);
		adjust_time = add_reagent0_real_starttime - add_reagent0_starttime;
		if (adjust_time > 0)
			continue;

		mix1_starttime = connect.mix_after_reagent(add_reagent0_real_starttime, add_reagent0_code_length);
		plan.mix(mix1_starttime, QB1_FYP_use_holeNO, SampleNO, add_mix1_real_starttime, FYP_add_mix1_time, FYP_add_mix1_starttime,
			add_mix1_FYP_occupytime, add_mix1_code, add_mix1_code_length, add_mix1_FYP_code, add_mix1_FYP_code_length);
		adjust_time = add_mix1_real_starttime - mix1_starttime;
		if (adjust_time > 0)
			continue;

		add_sample_from_cup_starttime = add_mix1_real_starttime + add_mix1_code_length + GYBG_Move_Time + GYBG_UpDown_Time;
		plan.add_sample_from_cup(10, add_sample_from_cup_starttime, QB1_FYP_use_holeNO, QB2_FYP_use_holeNO, add_sample_from_cup_real_starttime,
			GetSampleFromCupFYPstarttime1, add_sample_from_FYP_code, add_sample_from_FYP_code_length, GetSampleFromCupFYPstarttime2,
			add_sample_back_FYP_code, add_sample_back_FYP_code_length, GetSampleFromCupCodeStarttime, get_sample_code,
			get_sample_code_length, add_sample_from_cup_finish_time);
		adjust_time = add_sample_from_cup_real_starttime - add_sample_from_cup_starttime;
		if (adjust_time > 0)
			continue;


		add_reagent1_starttime = GetSampleFromCupFYPstarttime2 + add_sample_back_FYP_code_length;
		plan.add_reagent(9, add_reagent1_starttime, QB2_FYP_use_holeNO, R1_location_NO, Reagent_Bin_NO, add_reagent1_real_starttime,
			FYP_add_reagent1_time, FYP_add_reagent1_starttime, addSJ1_FYP_occupytime, add_reagent1_code, add_reagent1_code_length,
			add_reagent1_FYP_code, add_reagent1_FYP_code_length);
		adjust_time = add_reagent1_real_starttime - add_reagent1_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent4_starttime = connect.reagent_after_reagent(add_reagent1_real_starttime, add_reagent1_code_length);
		plan.add_reagent(9, add_reagent4_starttime, QB2_FYP_use_holeNO, R4_Location_NO, Reagent_Bin_NO, add_reagent4_real_starttime, FYP_add_reagent4_time,
			FYP_add_reagent4_starttime, addSJ4_FYP_occupytime, add_reagent4_code, add_reagent4_code_length, add_reagent4_FYP_code, add_reagent4_FYP_code_length);
		adjust_time = add_reagent4_real_starttime - add_reagent4_starttime;
		if (adjust_time > 0)
			continue;

		mix2_starttime = connect.mix_after_reagent(add_reagent4_real_starttime, add_reagent4_code_length);
		plan.mix(mix2_starttime, QB2_FYP_use_holeNO, SampleNO, add_mix2_real_starttime, FYP_add_mix2_time, FYP_add_mix2_starttime,
			add_mix2_FYP_occupytime, add_mix2_code, add_mix2_code_length, add_mix2_FYP_code, add_mix2_FYP_code_length);
		adjust_time = add_mix2_real_starttime - mix2_starttime;
		if (adjust_time > 0)
			continue;

		FYP_out_time = connect.CFL_after_mix(FYP_add_mix2_starttime, add_mix2_FYP_code_length, FY_time);
		plan.FYP2CFL(FYP_out_time, QB2_FYP_use_holeNO, FYP2CFL_real_starttime, FYP2CFL_JZ_starttime, FYP2CFL_JZ_code, FYP2CFL_JZ_code_length,
			FYP2CFL_FYP_starttime, FYP2CFL_FYP_code, FYP2CFL_FYP_code_length, CFL_hole_NO, FYP2CFL_CFL_arrive_time);
		adjust_time = FYP2CFL_real_starttime - FYP_out_time;
		if (adjust_time > 0)
			continue;

		CFL2ZDQ_starttime = connect.ZDQ_after_CFL(FYP2CFL_CFL_arrive_time);
		plan.CFL2ZDQ(CFL2ZDQ_starttime, CFL2ZDQ_real_starttime, CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code,
			CFL2ZDQ_JZ_code_length, CFL2ZDQ_ZDQ_arrive_time, CFL2ZDQ_hole_NO);
		adjust_time = CFL2ZDQ_real_starttime - CFL2ZDQ_starttime;
		if (adjust_time > 13)
			continue;

		ZDQ2GJC_starttime = connect.GJC_after_ZDG(CFL2ZDQ_ZDQ_arrive_time);//������������148s
		plan.ZDQ2GJC(ZDQ2GJC_starttime, ZDQ2GJC_real_starttime, CFL2ZDQ_hole_NO, ZDQ2GJC_JZ_starttime,
			ZDQ2GJC_JZ_code, ZDQ2GJC_JZ_code_length, ZDQ2GJC_GJC_arrive_time);
		adjust_time = ZDQ2GJC_real_starttime - ZDQ2GJC_starttime;
		if (adjust_time > 0)
			continue;

		unfinished = false;
	}


	//��Ӳ�������
	//ȡ��1����
	add_code.add_JZ_move_code(QB1_JZ_starttime, QB1_JZ_code_length, QB1_JZ_code);
	add_code.add_FYP_move_code(QB1_FYP_starttime, QB1_FYP_code_length, QB1_FYP_code);
	//ȡ��2����
	add_code.add_JZ_move_code(QB2_JZ_starttime, QB2_JZ_code_length, QB2_JZ_code);
	add_code.add_FYP_move_code(QB2_FYP_starttime, QB2_FYP_code_length, QB2_FYP_code);
	//��������
	add_code.add_sample_code(add_sample_real_starttime, add_sample_code_length, add_sample_code);
	add_code.add_FYP_move_code(FYP_add_sample_starttime, add_sample_FYP_code_length, add_sample_FYP_code);
	//�Լ�0����
	add_code.add_SJ_code(add_reagent0_real_starttime, add_reagent0_code_length, add_reagent0_code);
	add_code.add_FYP_move_code(FYP_add_reagent0_starttime, add_reagent0_FYP_code_length, add_reagent0_FYP_code);
	//�ӽ���1����
	add_code.add_mix_code(add_mix1_real_starttime, add_mix1_code_length, add_mix1_code);
	add_code.add_FYP_move_code(FYP_add_mix1_starttime, add_mix1_FYP_code_length, add_mix1_FYP_code);
	//�ӱ���ȡ��������һ������
	add_code.add_sample_from_fyp_code(GetSampleFromCupCodeStarttime, get_sample_code_length, get_sample_code);
	add_code.add_FYP_move_code(GetSampleFromCupFYPstarttime1, add_sample_from_FYP_code_length, add_sample_from_FYP_code);
	add_code.add_FYP_move_code(GetSampleFromCupFYPstarttime2, add_sample_back_FYP_code_length, add_sample_back_FYP_code);
	//�Լ�1����
	add_code.add_SJ_code(add_reagent1_real_starttime, add_reagent1_code_length, add_reagent1_code);
	add_code.add_FYP_move_code(FYP_add_reagent1_starttime, add_reagent1_FYP_code_length, add_reagent1_FYP_code);
	//�Լ�4����
	add_code.add_SJ_code(add_reagent4_real_starttime, add_reagent4_code_length, add_reagent4_code);
	add_code.add_FYP_move_code(FYP_add_reagent4_starttime, add_reagent4_FYP_code_length, add_reagent4_FYP_code);
	//�ӽ���2����
	add_code.add_mix_code(add_mix2_real_starttime, add_mix2_code_length, add_mix2_code);
	add_code.add_FYP_move_code(FYP_add_mix2_starttime, add_mix2_FYP_code_length, add_mix2_FYP_code);
	//�����̵��ŷ������
	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime, FYP2CFL_JZ_code_length, FYP2CFL_JZ_code);
	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime, FYP2CFL_FYP_code_length, FYP2CFL_FYP_code);
	add_code.add_FYP_hole_occupy(QB2_FYP_use_holeNO, FYP_putcup_time2, FYP_out_time);//�����̿�ռ��
	//�ŷ��뵽��������
	add_code.add_JZ_move_code(CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code_length, CFL2ZDQ_JZ_code);
	add_code.add_CFL_hole_occupy(CFL_hole_NO, FYP2CFL_CFL_arrive_time, CFL2ZDQ_real_starttime);//�ŷ����ռ��
	//�������������
	add_code.add_JZ_move_code(ZDQ2GJC_JZ_starttime, ZDQ2GJC_JZ_code_length, ZDQ2GJC_JZ_code);
	add_code.add_ZDQ_hole_occupy(CFL2ZDQ_hole_NO, CFL2ZDQ_ZDQ_arrive_time, ZDQ2GJC_starttime);//������ռ��
	//������̴���
	int GJC_code_length = 0;
	int GJC_code[3][50] = { 0 };
	plan.gjc.createcode(36, mission_NO, GJC_code_length, GJC_code);
	int GJC_starttime = ZDQ2GJC_GJC_arrive_time;
	add_code.add_GJC_code(GJC_starttime - 1, GJC_code_length, GJC_code);
	add_code.add_GJC_hole_occupy(GJC_starttime - 1, GJC_starttime + 43);//�����ռ��
	//������
	add_code.add_ZDQ_motor_code();
	//�ŷ���ת��
	add_code.add_CFL_move_code(GJC_starttime + 1200, cfl_CFLcyclesteptime);
	
	totaltime = GJC_starttime + 1200;

	//FYP2GJC��ر���
	int FYP2GJC_starttime = 0;
	int FYP2GJC_real_starttime = 0;
	int FYP2GJC_JZ_starttime = 0;
	int FYP2GJC_JZ_code[3][100] = { 0 };
	int FYP2GJC_JZ_code_length = 0;
	int FYP2GJC_FYP_starttime = 0;
	int FYP2GJC_FYP_code[50] = { 0 };
	int FYP2GJC_FYP_code_length = 0;
	int FYP2GJC_GJC_arrive_time = 0;
	FYP2GJC_starttime = add_sample_from_cup_finish_time;
	plan.FYP2GJC(FYP2GJC_starttime, QB1_FYP_use_holeNO, FYP2GJC_real_starttime, FYP2GJC_JZ_starttime, FYP2GJC_JZ_code, FYP2GJC_JZ_code_length,
		FYP2GJC_FYP_starttime, FYP2GJC_FYP_code, FYP2GJC_FYP_code_length, FYP2GJC_GJC_arrive_time);
	add_code.add_JZ_move_code(FYP2GJC_JZ_starttime, FYP2GJC_JZ_code_length, FYP2GJC_JZ_code);
	add_code.add_FYP_move_code(FYP2GJC_FYP_starttime, FYP2GJC_FYP_code_length, FYP2GJC_FYP_code);
	//��������
	int GJC_db_code_length = 0;
	int GJC_db_code[50] = { 0 };
	plan.gjc.db_createcode(GJC_db_code_length, GJC_db_code);
	int GJC_db_starttime = FYP2GJC_GJC_arrive_time;
	add_code.add_GJC_db_code(GJC_db_starttime - 1, GJC_db_code_length, GJC_db_code);
	add_code.add_FYP_hole_occupy(QB1_FYP_use_holeNO, FYP_putcup_time1, FYP2GJC_GJC_arrive_time);//�����̿�ռ��
	add_code.add_GJC_hole_occupy(GJC_db_starttime - 1, GJC_db_starttime + 7);//�����ռ��




	//��Ӵŷ���ע����Һ�������
	int length = 0;
	int zhushe1_time = 0;
	int paiye1_time = 0;
	int zhushe2_time = 0;
	int paiye2_time = 0;
	int diwu_time = 0;
	int CFLcode1[8][30] = { 0 };
	int CFLcode2[8][30] = { 0 };
	int CFLcode3[8][30] = { 0 };
	int CFLcode4[8][30] = { 0 };
	int CFLcode5[8][30] = { 0 };
	plan.cfl.CFLzhushe1codegenerate(CFLcode1, length);
	plan.cfl.CFLpaiye1codegenerate(CFLcode2, length);
	plan.cfl.CFLzhushe2codegenerate(CFLcode3, length);
	plan.cfl.CFLpaiye2codegenerate(CFLcode4, length);
	plan.cfl.CFLdiwucodegenerate(CFLcode5, length);
	//��һȦ
	zhushe1_time = (FYP2CFL_CFL_arrive_time / 17 + 2) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time / 17 + 5) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time / 17 + 6) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time / 17 + 9) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//�ڶ�Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time / 17 + 2 + 12) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time / 17 + 5 + 12) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time / 17 + 6 + 12) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time / 17 + 9 + 12) * 17 + 1;
	diwu_time = (FYP2CFL_CFL_arrive_time / 17 + 10 + 12) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	add_code.add_CFL_operation_code(diwu_time, length, CFLcode5);
}

//����������ϡ��Һ���Լ�0��������1���������Լ�1������2����������ϴ���Լ�4������3���ٷ�������ϴ���ӵ���𵴡����
void PRO::PIC(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R4_Location_NO, int qb_starttime, int FY_time1, int FY_time2)
{
	//���Ʊ���
	bool unfinished = true;
	int adjust_time = 0;

	//ȡ��1��ر���
	int BJ_is_empty1 = 0;
	int BJ_need_changerow1 = 0;
	int BJ_changerow_time1 = 0;
	int BJ_cupNO1 = 0;
	int QB1_JZ_starttime = 0;
	int QB1_JZ_code_length = 0;
	int QB1_JZ_code[3][100] = { 0 };
	int QB1_time = 0;
	int FYP_putcup_time1 = 0;
	int QB1_FYP_starttime = 0;
	int QB1_FYP_use_holeNO = 0;
	int QB1_FYP_code[50] = { 0 };
	int QB1_FYP_code_length = 0;
	int QB1_finished_time = 0;
	int BJ_NO1 = 0;

	//ȡ��2��ر���
	int BJ_is_empty2 = 0;
	int BJ_need_changerow2 = 0;
	int BJ_changerow_time2 = 0;
	int BJ_cupNO2 = 0;
	int QB2_JZ_starttime = 0;
	int QB2_JZ_code_length = 0;
	int QB2_JZ_code[3][100] = { 0 };
	int QB2_time = 0;
	int FYP_putcup_time2 = 0;
	int QB2_FYP_starttime = 0;
	int QB2_FYP_use_holeNO = 0;
	int QB2_FYP_code[50] = { 0 };
	int QB2_FYP_code_length = 0;
	int QB2_finished_time = 0;
	int BJ_NO2 = 0;

	//��������ر���
	int sample_starttime = 0;
	int add_sample_real_starttime = 0;
	int FYP_add_sample_time = 0;
	int FYP_add_sample_starttime = 0;
	int add_sample_FYP_occupytime = 0;
	int add_sample_code[8][100] = { 0 };
	int add_sample_code_length = 0;
	int add_sample_FYP_code[50] = { 0 };
	int add_sample_FYP_code_length = 0;

	//���Լ�0��ر���
	int add_reagent0_starttime = 0;
	int add_reagent0_real_starttime = 0;
	int FYP_add_reagent0_time = 0;
	int FYP_add_reagent0_starttime = 0;
	int addSJ0_FYP_occupytime = 0;
	int add_reagent0_code[8][100] = { 0 };
	int add_reagent0_code_length = 0;
	int add_reagent0_FYP_code[50] = { 0 };
	int add_reagent0_FYP_code_length = 0;

	//����1��ر���
	int mix1_starttime = 0;
	int add_mix1_real_starttime = 0;
	int FYP_add_mix1_time = 0;
	int FYP_add_mix1_starttime = 0;
	int add_mix1_FYP_occupytime = 0;
	int add_mix1_code[8][100] = { 0 };
	int add_mix1_code_length = 0;
	int add_mix1_FYP_code[50] = { 0 };
	int add_mix1_FYP_code_length = 0;

	//�ӱ���ȡ����ر���
	int add_sample_from_cup_starttime = 0;
	int add_sample_from_cup_real_starttime = 0;
	int GetSampleFromCupFYPstarttime1 = 0;
	int add_sample_from_FYP_code[50] = { 0 };
	int add_sample_from_FYP_code_length = 0;
	int GetSampleFromCupFYPstarttime2 = 0;
	int add_sample_back_FYP_code[50] = { 0 };
	int add_sample_back_FYP_code_length = 0;
	int GetSampleFromCupCodeStarttime = 0;
	int get_sample_code[8][100] = { 0 };
	int get_sample_code_length = 0;
	int add_sample_from_cup_finish_time = 0;

	//���Լ�1��ر���
	int add_reagent1_starttime = 0;
	int add_reagent1_real_starttime = 0;
	int FYP_add_reagent1_time = 0;
	int FYP_add_reagent1_starttime = 0;
	int addSJ1_FYP_occupytime = 0;
	int add_reagent1_code[8][100] = { 0 };
	int add_reagent1_code_length = 0;
	int add_reagent1_FYP_code[50] = { 0 };
	int add_reagent1_FYP_code_length = 0;

	//����2��ر���
	int mix2_starttime = 0;
	int add_mix2_real_starttime = 0;
	int FYP_add_mix2_time = 0;
	int FYP_add_mix2_starttime = 0;
	int add_mix2_FYP_occupytime = 0;
	int add_mix2_code[8][100] = { 0 };
	int add_mix2_code_length = 0;
	int add_mix2_FYP_code[50] = { 0 };
	int add_mix2_FYP_code_length = 0;

	//��һ�ν��ŷ�����ر���
	int FYP_out_time1 = 0;
	int FYP2CFL_real_starttime1 = 0;
	int FYP2CFL_JZ_starttime1 = 0;
	int FYP2CFL_JZ_code1[3][100]={ 0 };
	int FYP2CFL_JZ_code_length1 = 0;
	int FYP2CFL_FYP_starttime1 = 0;
	int FYP2CFL_FYP_code1[50] = { 0 };
	int FYP2CFL_FYP_code_length1 = 0;
	int CFL_hole_NO1 = 0;
	int FYP2CFL_CFL_arrive_time1 = 0;

	//�ŷ��뵽��������ر���
	int CFL2FYP_starttime = 0;
	int CFL2FYP_real_starttime = 0;
	int CFL2FYP_JZ_starttime = 0;
	int CFL2FYP_JZ_code[3][100] = { 0 };
	int CFL2FYP_JZ_code_length = 0;
	int CFL2FYP_FYP_arrive_time = 0;
	int CFL2FYP_FYP_holeNO = 0;
	int CFL2FYP_FYP_starttime = 0;
	int CFL2FYP_FYP_code[50] = { 0 };
	int CFL2FYP_FYP_code_length = 0;

	//���Լ�4��ر���
	int add_reagent4_starttime = 0;
	int add_reagent4_real_starttime = 0;
	int FYP_add_reagent4_time = 0;
	int FYP_add_reagent4_starttime = 0;
	int addSJ4_FYP_occupytime = 0;
	int add_reagent4_code[8][100] = { 0 };
	int add_reagent4_code_length = 0;
	int add_reagent4_FYP_code[50] = { 0 };
	int add_reagent4_FYP_code_length = 0;

	//����3��ر���
	int mix3_starttime = 0;
	int add_mix3_real_starttime = 0;
	int FYP_add_mix3_time = 0;
	int FYP_add_mix3_starttime = 0;
	int add_mix3_FYP_occupytime = 0;
	int add_mix3_code[8][100] = { 0 };
	int add_mix3_code_length = 0;
	int add_mix3_FYP_code[50] = { 0 };
	int add_mix3_FYP_code_length = 0;

	//�ڶ��ν��ŷ�����ر���
	int FYP_out_time2 = 0;
	int FYP2CFL_real_starttime2 = 0;
	int FYP2CFL_JZ_starttime2 = 0;
	int FYP2CFL_JZ_code2[3][100]={ 0 };
	int FYP2CFL_JZ_code_length2 = 0;
	int FYP2CFL_FYP_starttime2 = 0;
	int FYP2CFL_FYP_code2[50] = { 0 };
	int FYP2CFL_FYP_code_length2 = 0;
	int CFL_hole_NO2 = 0;
	int FYP2CFL_CFL_arrive_time2 = 0;

	//�ŷ����������ر���
	int CFL2ZDQ_starttime = 0;
	int CFL2ZDQ_real_starttime = 0;
	int CFL2ZDQ_JZ_starttime = 0;
	int CFL2ZDQ_JZ_code[3][100] = { 0 };
	int CFL2ZDQ_JZ_code_length = 0;
	int CFL2ZDQ_ZDQ_arrive_time = 0;
	int CFL2ZDQ_hole_NO = 0;

	//������������ر���
	int ZDQ2GJC_starttime = 0;
	int ZDQ2GJC_real_starttime = 0;
	int ZDQ2GJC_JZ_starttime = 0;
	int ZDQ2GJC_JZ_code[3][100] = { 0 };
	int ZDQ2GJC_JZ_code_length = 0;
	int ZDQ2GJC_GJC_arrive_time = 0;

	plan.qb(qb_starttime, BJ_is_empty1, BJ_need_changerow1, BJ_changerow_time1, BJ_cupNO1, QB1_JZ_starttime, QB1_JZ_code_length, QB1_JZ_code,
		QB1_time, FYP_putcup_time1, QB1_FYP_starttime, QB1_FYP_use_holeNO, QB1_FYP_code, QB1_FYP_code_length, QB1_finished_time, BJ_NO1);
	plan.set_BJ_state(GBJ_Content);
	if (BJ_NO1 == 0)
	{
		//���뻻����������
		int code[10] = { 0 };
		int CodeLength1;
		CodeLength1 = plan.bj.BJmovnextrow(code);
		int time = QB1_JZ_starttime + jz_downtime + jz_opentime + jz_uptime + jz_movetime;
		for (int j = 0; j < CodeLength1; j++)
			xy[8][j + time] = code[j];
	}

	int QB1_FYP_use_occupy = FYP_putcup_time1;
	while (true)
	{
		QB1_FYP_use_occupy++;
		plan.qb(QB1_finished_time, BJ_is_empty2, BJ_need_changerow2, BJ_changerow_time2, BJ_cupNO2, QB2_JZ_starttime, QB2_JZ_code_length, QB2_JZ_code,
			QB2_time, FYP_putcup_time2, QB2_FYP_starttime, QB2_FYP_use_holeNO, QB2_FYP_code, QB2_FYP_code_length, QB2_finished_time, BJ_NO2);
		if (QB2_FYP_use_holeNO == QB1_FYP_use_holeNO)
		{
			add_code.add_FYP_hole_occupy(QB1_FYP_use_holeNO, FYP_putcup_time1, QB1_FYP_use_occupy);//�����̿�1��ռ��
		}
		else
		{
			break;
		}
	}
	plan.set_BJ_state(GBJ_Content);
	if (BJ_NO2 == 0)
	{
		//���뻻����������
		int code[10] = { 0 };
		int CodeLength1;
		CodeLength1 = plan.bj.BJmovnextrow(code);
		int time = QB2_JZ_starttime + jz_downtime + jz_opentime + jz_uptime + jz_movetime;
		for (int j = 0; j < CodeLength1; j++)
			xy[8][j + time] = code[j];
	}

	sample_starttime = connect.sample_after_qb(QB2_finished_time);
	while (unfinished)
	{
		sample_starttime += adjust_time;

		plan.add_sample(9, sample_starttime, QB1_FYP_use_holeNO, SampleNO, add_sample_real_starttime, FYP_add_sample_time,
			FYP_add_sample_starttime, add_sample_FYP_occupytime, add_sample_code, add_sample_code_length, add_sample_FYP_code,
			add_sample_FYP_code_length);
		adjust_time = add_sample_real_starttime - sample_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent0_starttime = connect.reagent_after_sample(add_sample_real_starttime, add_sample_code_length);
		plan.add_reagent(9, add_reagent0_starttime, QB1_FYP_use_holeNO, -1, -1, add_reagent0_real_starttime, FYP_add_reagent0_time,
			FYP_add_reagent0_starttime, addSJ0_FYP_occupytime, add_reagent0_code, add_reagent0_code_length, add_reagent0_FYP_code, add_reagent0_FYP_code_length);
		adjust_time = add_reagent0_real_starttime - add_reagent0_starttime;
		if (adjust_time > 0)
			continue;

		mix1_starttime = connect.mix_after_reagent(add_reagent0_real_starttime, add_reagent0_code_length);
		plan.mix(mix1_starttime, QB1_FYP_use_holeNO, SampleNO, add_mix1_real_starttime, FYP_add_mix1_time, FYP_add_mix1_starttime,
			add_mix1_FYP_occupytime, add_mix1_code, add_mix1_code_length, add_mix1_FYP_code, add_mix1_FYP_code_length);
		adjust_time = add_mix1_real_starttime - mix1_starttime;
		if (adjust_time > 0)
			continue;

		add_sample_from_cup_starttime = add_mix1_real_starttime + add_mix1_code_length + GYBG_Move_Time + GYBG_UpDown_Time;
		plan.add_sample_from_cup(10, add_sample_from_cup_starttime, QB1_FYP_use_holeNO, QB2_FYP_use_holeNO, add_sample_from_cup_real_starttime,
			GetSampleFromCupFYPstarttime1, add_sample_from_FYP_code, add_sample_from_FYP_code_length, GetSampleFromCupFYPstarttime2,
			add_sample_back_FYP_code, add_sample_back_FYP_code_length, GetSampleFromCupCodeStarttime, get_sample_code,
			get_sample_code_length, add_sample_from_cup_finish_time);
		adjust_time = add_sample_from_cup_real_starttime - add_sample_from_cup_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent1_starttime = GetSampleFromCupFYPstarttime2 + add_sample_back_FYP_code_length - 3;
		plan.add_reagent(9, add_reagent1_starttime, QB2_FYP_use_holeNO, R1_location_NO, Reagent_Bin_NO, add_reagent1_real_starttime,
			FYP_add_reagent1_time, FYP_add_reagent1_starttime, addSJ1_FYP_occupytime, add_reagent1_code, add_reagent1_code_length,
			add_reagent1_FYP_code, add_reagent1_FYP_code_length);
		adjust_time = add_reagent1_real_starttime - add_reagent1_starttime;
		if (adjust_time > 0)
			continue;

		mix2_starttime = connect.mix_after_reagent(add_reagent1_real_starttime, add_reagent1_code_length);
		plan.mix(mix2_starttime, QB2_FYP_use_holeNO, SampleNO, add_mix2_real_starttime, FYP_add_mix2_time,
			FYP_add_mix2_starttime, add_mix2_FYP_occupytime, add_mix2_code, add_mix2_code_length, add_mix2_FYP_code,
			add_mix2_FYP_code_length);
		adjust_time = add_mix2_real_starttime - mix2_starttime;
		if (adjust_time > 0)
			continue;

		FYP_out_time1 = connect.CFL_after_mix(FYP_add_mix2_starttime, add_mix2_FYP_code_length, FY_time1);
		plan.FYP2CFL(FYP_out_time1, QB2_FYP_use_holeNO, FYP2CFL_real_starttime1, FYP2CFL_JZ_starttime1, FYP2CFL_JZ_code1, FYP2CFL_JZ_code_length1,
			FYP2CFL_FYP_starttime1, FYP2CFL_FYP_code1, FYP2CFL_FYP_code_length1, CFL_hole_NO1, FYP2CFL_CFL_arrive_time1);
		adjust_time = FYP2CFL_real_starttime1 - FYP_out_time1;
		if (adjust_time > 0)
			continue;

		CFL2FYP_starttime = connect.FYP_after_CFL(FYP2CFL_CFL_arrive_time1);
		plan.CFL2FYP(CFL2FYP_starttime, CFL2FYP_real_starttime, CFL2FYP_JZ_starttime, CFL2FYP_JZ_code, CFL2FYP_JZ_code_length,
			CFL2FYP_FYP_arrive_time, CFL2FYP_FYP_holeNO, CFL2FYP_FYP_starttime, CFL2FYP_FYP_code, CFL2FYP_FYP_code_length);
		adjust_time = CFL2FYP_real_starttime - CFL2FYP_starttime;
		if (adjust_time > 13)
			continue;

		add_reagent4_starttime = connect.reagent_after_FYP(CFL2FYP_FYP_starttime, CFL2FYP_FYP_code_length);
		plan.add_reagent(21, add_reagent4_starttime, CFL2FYP_FYP_holeNO, R4_Location_NO, Reagent_Bin_NO, add_reagent4_real_starttime, FYP_add_reagent4_time,
			FYP_add_reagent4_starttime, addSJ4_FYP_occupytime, add_reagent4_code, add_reagent4_code_length, add_reagent4_FYP_code, add_reagent4_FYP_code_length);
		adjust_time = add_reagent4_real_starttime - add_reagent4_starttime;
		if (adjust_time > 0)
			continue;

		mix3_starttime = connect.mix_after_reagent(add_reagent4_real_starttime, add_reagent4_code_length);
		plan.mix(mix3_starttime, CFL2FYP_FYP_holeNO, SampleNO, add_mix3_real_starttime, FYP_add_mix3_time, FYP_add_mix3_starttime,
			add_mix3_FYP_occupytime, add_mix3_code, add_mix3_code_length, add_mix3_FYP_code, add_mix3_FYP_code_length);
		adjust_time = add_mix3_real_starttime - mix3_starttime;
		if (adjust_time > 0)
			continue;

		FYP_out_time2 = connect.CFL_after_mix(FYP_add_mix3_starttime, add_mix3_FYP_code_length, FY_time2);
		plan.FYP2CFL(FYP_out_time2, CFL2FYP_FYP_holeNO, FYP2CFL_real_starttime2, FYP2CFL_JZ_starttime2, FYP2CFL_JZ_code2, FYP2CFL_JZ_code_length2,
			FYP2CFL_FYP_starttime2, FYP2CFL_FYP_code2, FYP2CFL_FYP_code_length2, CFL_hole_NO2, FYP2CFL_CFL_arrive_time2);
		adjust_time = FYP2CFL_real_starttime2 - FYP_out_time2;
		if (adjust_time > 0)
			continue;

		CFL2ZDQ_starttime = connect.ZDQ_after_CFL(FYP2CFL_CFL_arrive_time2);
		plan.CFL2ZDQ(CFL2ZDQ_starttime, CFL2ZDQ_real_starttime, CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code,
			CFL2ZDQ_JZ_code_length, CFL2ZDQ_ZDQ_arrive_time, CFL2ZDQ_hole_NO);
		adjust_time = CFL2ZDQ_real_starttime - CFL2ZDQ_starttime;
		if (adjust_time > 13)
			continue;

		ZDQ2GJC_starttime = connect.GJC_after_ZDG(CFL2ZDQ_ZDQ_arrive_time);
		plan.ZDQ2GJC(ZDQ2GJC_starttime, ZDQ2GJC_real_starttime, CFL2ZDQ_hole_NO, ZDQ2GJC_JZ_starttime,
			ZDQ2GJC_JZ_code, ZDQ2GJC_JZ_code_length, ZDQ2GJC_GJC_arrive_time);
		adjust_time = ZDQ2GJC_real_starttime - ZDQ2GJC_starttime;
		if (adjust_time > 0)
			continue;

		unfinished = false;
	}


	//��Ӳ�������
	//ȡ��1����
	add_code.add_JZ_move_code(QB1_JZ_starttime, QB1_JZ_code_length, QB1_JZ_code);
	add_code.add_FYP_move_code(QB1_FYP_starttime, QB1_FYP_code_length, QB1_FYP_code);
	//ȡ��2����
	add_code.add_JZ_move_code(QB2_JZ_starttime, QB2_JZ_code_length, QB2_JZ_code);
	add_code.add_FYP_move_code(QB2_FYP_starttime, QB2_FYP_code_length, QB2_FYP_code);
	//��������
	add_code.add_sample_code(add_sample_real_starttime, add_sample_code_length, add_sample_code);
	add_code.add_FYP_move_code(FYP_add_sample_starttime, add_sample_FYP_code_length, add_sample_FYP_code);
	//�Լ�0����
	add_code.add_SJ_code(add_reagent0_real_starttime, add_reagent0_code_length, add_reagent0_code);
	add_code.add_FYP_move_code(FYP_add_reagent0_starttime, add_reagent0_FYP_code_length, add_reagent0_FYP_code);
	//�ӽ���1����
	add_code.add_mix_code(add_mix1_real_starttime, add_mix1_code_length, add_mix1_code);
	add_code.add_FYP_move_code(FYP_add_mix1_starttime, add_mix1_FYP_code_length, add_mix1_FYP_code);
	//�ӱ���ȡ��������һ������
	add_code.add_sample_from_fyp_code(GetSampleFromCupCodeStarttime, get_sample_code_length, get_sample_code);
	add_code.add_FYP_move_code(GetSampleFromCupFYPstarttime1, add_sample_from_FYP_code_length, add_sample_from_FYP_code);
	add_code.add_FYP_move_code(GetSampleFromCupFYPstarttime2, add_sample_back_FYP_code_length, add_sample_back_FYP_code);
	//�Լ�1����
	add_code.add_SJ_code(add_reagent1_real_starttime, add_reagent1_code_length, add_reagent1_code);
	add_code.add_FYP_move_code(FYP_add_reagent1_starttime, add_reagent1_FYP_code_length, add_reagent1_FYP_code);
	//�ӽ���2����
	add_code.add_mix_code(add_mix2_real_starttime, add_mix2_code_length, add_mix2_code);
	add_code.add_FYP_move_code(FYP_add_mix2_starttime, add_mix2_FYP_code_length, add_mix2_FYP_code);
	//��һ�η����̵��ŷ������
	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime1, FYP2CFL_JZ_code_length1, FYP2CFL_JZ_code1);
	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime1, FYP2CFL_FYP_code_length1, FYP2CFL_FYP_code1);
	add_code.add_FYP_hole_occupy(QB2_FYP_use_holeNO, FYP_putcup_time2, FYP_out_time1);//�����̿׵�һ��ռ��
	//�ŷ��뵽�����̴���
	add_code.add_JZ_move_code(CFL2FYP_JZ_starttime, CFL2FYP_JZ_code_length, CFL2FYP_JZ_code);
	add_code.add_FYP_move_code(CFL2FYP_FYP_starttime, CFL2FYP_FYP_code_length, CFL2FYP_FYP_code);
	add_code.add_CFL_hole_occupy(CFL_hole_NO1, FYP2CFL_CFL_arrive_time1, CFL2FYP_starttime);//�ŷ���׵�һ��ռ��
	//���Լ�4����
	add_code.add_SJ_code(add_reagent4_real_starttime, add_reagent4_code_length, add_reagent4_code);
	add_code.add_FYP_move_code(FYP_add_reagent4_starttime, add_reagent4_FYP_code_length, add_reagent4_FYP_code);
	//����3����
	add_code.add_mix_code(add_mix3_real_starttime, add_mix3_code_length, add_mix3_code);
	add_code.add_FYP_move_code(FYP_add_mix3_starttime, add_mix3_FYP_code_length, add_mix3_FYP_code);
	//�����̵��ŷ���ڶ��δ���
	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime2, FYP2CFL_JZ_code_length2, FYP2CFL_JZ_code2);
	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime2, FYP2CFL_FYP_code_length2, FYP2CFL_FYP_code2);
	add_code.add_FYP_hole_occupy(CFL2FYP_FYP_holeNO, CFL2FYP_FYP_arrive_time, FYP_out_time2);//�����̿׵ڶ���ռ��
	//�ŷ��뵽��������
	add_code.add_JZ_move_code(CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code_length, CFL2ZDQ_JZ_code);
	add_code.add_CFL_hole_occupy(CFL_hole_NO2, FYP2CFL_CFL_arrive_time2, CFL2ZDQ_starttime);//�ŷ���׵ڶ���ռ��
	//�������������
	add_code.add_JZ_move_code(ZDQ2GJC_JZ_starttime, ZDQ2GJC_JZ_code_length, ZDQ2GJC_JZ_code);
	add_code.add_ZDQ_hole_occupy(CFL2ZDQ_hole_NO, CFL2ZDQ_ZDQ_arrive_time, ZDQ2GJC_starttime);//������ռ��
	//���������ӹ���
	int GJC_code_length = 0;
	int GJC_code[3][50] = { 0 };
	plan.gjc.createcode(36, mission_NO, GJC_code_length, GJC_code);
	int GJC_starttime = ZDQ2GJC_GJC_arrive_time;
	add_code.add_GJC_code(GJC_starttime - 1, GJC_code_length, GJC_code);
	add_code.add_GJC_hole_occupy(GJC_starttime - 1, GJC_starttime + 43);//�����ռ��
	//������
	add_code.add_ZDQ_motor_code();
	//�ŷ���ת��
	add_code.add_CFL_move_code(GJC_starttime + 1200, cfl_CFLcyclesteptime);
	
	totaltime = GJC_starttime + 1200;

	//FYP2GJC��ر���
	int FYP2GJC_starttime = 0;
	int FYP2GJC_real_starttime = 0;
	int FYP2GJC_JZ_starttime = 0;
	int FYP2GJC_JZ_code[3][100] = { 0 };
	int FYP2GJC_JZ_code_length = 0;
	int FYP2GJC_FYP_starttime = 0;
	int FYP2GJC_FYP_code[50] = { 0 };
	int FYP2GJC_FYP_code_length = 0;
	int FYP2GJC_GJC_arrive_time = 0;
	FYP2GJC_starttime = add_sample_from_cup_finish_time;
	plan.FYP2GJC(FYP2GJC_starttime, QB1_FYP_use_holeNO, FYP2GJC_real_starttime, FYP2GJC_JZ_starttime, FYP2GJC_JZ_code, FYP2GJC_JZ_code_length,
		FYP2GJC_FYP_starttime, FYP2GJC_FYP_code, FYP2GJC_FYP_code_length, FYP2GJC_GJC_arrive_time);
	add_code.add_JZ_move_code(FYP2GJC_JZ_starttime, FYP2GJC_JZ_code_length, FYP2GJC_JZ_code);
	add_code.add_FYP_move_code(FYP2GJC_FYP_starttime, FYP2GJC_FYP_code_length, FYP2GJC_FYP_code);
	//��������
	int GJC_db_code_length = 0;
	int GJC_db_code[50] = { 0 };
	plan.gjc.db_createcode(GJC_db_code_length, GJC_db_code);
	int GJC_db_starttime = FYP2GJC_GJC_arrive_time;
	add_code.add_GJC_db_code(GJC_db_starttime - 1, GJC_db_code_length, GJC_db_code);
	add_code.add_FYP_hole_occupy(QB1_FYP_use_holeNO, FYP_putcup_time1, FYP2GJC_GJC_arrive_time);//�����̿�ռ��
	add_code.add_GJC_hole_occupy(GJC_db_starttime - 1, GJC_db_starttime + 7);//�����ռ��

	//��Ӵŷ���ע����Һ�������
	int length = 0;
	int zhushe1_time = 0;
	int paiye1_time = 0;
	int zhushe2_time = 0;
	int paiye2_time = 0;
	int diwu_time = 0;
	int CFLcode1[8][30] = { 0 };
	int CFLcode2[8][30] = { 0 };
	int CFLcode3[8][30] = { 0 };
	int CFLcode4[8][30] = { 0 };
	int CFLcode5[8][30] = { 0 };
	plan.cfl.CFLzhushe1codegenerate(CFLcode1, length);
	plan.cfl.CFLpaiye1codegenerate(CFLcode2, length);
	plan.cfl.CFLzhushe2codegenerate(CFLcode3, length);
	plan.cfl.CFLpaiye2codegenerate(CFLcode4, length);
	plan.cfl.CFLdiwucodegenerate(CFLcode5, length);
	//��һȦ
	zhushe1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 2) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 5) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 6) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 9) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//�ڶ�Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 2 + 12) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 5 + 12) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 6 + 12) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 9 + 12) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//����Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 2) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 5) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 6) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 9) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//����Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 2 + 12) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 5 + 12) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 6 + 12) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 9 + 12) * 17 + 1;
	diwu_time = (FYP2CFL_CFL_arrive_time2 / 17 + 10 + 12) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	add_code.add_CFL_operation_code(diwu_time, length, CFLcode5);
}

//ȡ�����Լ�1�����������衢��һ��FYP2CFL��FY_time1����CFL2FYP�����Լ�4�����衢
void PRO::TM(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R4_Location_NO, int qb_starttime, int FY_time1, int FY_time2)
{
	//���Ʊ���
	bool unfinished = true;
	int adjust_time = 0;

	//ȡ����ر���
	int BJ_is_empty = 0;
	int BJ_need_changerow = 0;
	int BJ_changerow_time = 0;
	int BJ_cupNO = 0;
	int QB_JZ_starttime = 0;
	int QB_JZ_code_length = 0;
	int QB_JZ_code[3][100] = { 0 };
	int QB_time = 0;
	int FYP_putcup_time = 0;
	int QB_FYP_starttime = 0;
	int QB_FYP_use_holeNO = 0;
	int QB_FYP_code[50] = { 0 };
	int QB_FYP_code_length = 0;
	int QB_finished_time = 0;
	int BJ_NO = 0;

	//���Լ�1��ر���
	int add_reagent1_starttime = 0;
	int add_reagent1_real_starttime = 0;
	int FYP_add_reagent1_time = 0;
	int FYP_add_reagent1_starttime = 0;
	int addSJ1_FYP_occupytime = 0;
	int add_reagent1_code[8][100] = { 0 };
	int add_reagent1_code_length = 0;
	int add_reagent1_FYP_code[50] = { 0 };
	int add_reagent1_FYP_code_length = 0;

	//��������ر���
	int sample_starttime = 0;
	int add_sample_real_starttime = 0;
	int FYP_add_sample_time = 0;
	int FYP_add_sample_starttime = 0;
	int add_sample_FYP_occupytime = 0;
	int add_sample_code[8][100] = { 0 };
	int add_sample_code_length = 0;
	int add_sample_FYP_code[50] = { 0 };
	int add_sample_FYP_code_length = 0;

	//����1��ر���
	int mix1_starttime = 0;
	int add_mix1_real_starttime = 0;
	int FYP_add_mix1_time = 0;
	int FYP_add_mix1_starttime = 0;
	int add_mix1_FYP_occupytime = 0;
	int add_mix1_code[8][100] = { 0 };
	int add_mix1_code_length = 0;
	int add_mix1_FYP_code[50] = { 0 };
	int add_mix1_FYP_code_length = 0;

	//��һ�ν��ŷ�����ر���
	int FYP_out_time1 = 0;
	int FYP2CFL_real_starttime1 = 0;
	int FYP2CFL_JZ_starttime1 = 0;
	int FYP2CFL_JZ_code1[3][100]={ 0 };
	int FYP2CFL_JZ_code_length1 = 0;
	int FYP2CFL_FYP_starttime1 = 0;
	int FYP2CFL_FYP_code1[50] = { 0 };
	int FYP2CFL_FYP_code_length1 = 0;
	int CFL_hole_NO1 = 0;
	int FYP2CFL_CFL_arrive_time1 = 0;

	//�ŷ��뵽��������ر���
	int CFL2FYP_starttime = 0;
	int CFL2FYP_real_starttime = 0;
	int CFL2FYP_JZ_starttime = 0;
	int CFL2FYP_JZ_code[3][100] = { 0 };
	int CFL2FYP_JZ_code_length = 0;
	int CFL2FYP_FYP_arrive_time = 0;
	int CFL2FYP_FYP_holeNO = 0;
	int CFL2FYP_FYP_starttime = 0;
	int CFL2FYP_FYP_code[50] = { 0 };
	int CFL2FYP_FYP_code_length = 0;

	//���Լ�4��ر���
	int add_reagent4_starttime = 0;
	int add_reagent4_real_starttime = 0;
	int FYP_add_reagent4_time = 0;
	int FYP_add_reagent4_starttime = 0;
	int addSJ4_FYP_occupytime = 0;
	int add_reagent4_code[8][100] = { 0 };
	int add_reagent4_code_length = 0;
	int add_reagent4_FYP_code[50] = { 0 };
	int add_reagent4_FYP_code_length = 0;

	//����2��ر���
	int mix2_starttime = 0;
	int add_mix2_real_starttime = 0;
	int FYP_add_mix2_time = 0;
	int FYP_add_mix2_starttime = 0;
	int add_mix2_FYP_occupytime = 0;
	int add_mix2_code[8][100] = { 0 };
	int add_mix2_code_length = 0;
	int add_mix2_FYP_code[50] = { 0 };
	int add_mix2_FYP_code_length = 0;

	//���ŷ�����ر���
	int FYP_out_time2 = 0;
	int FYP2CFL_real_starttime2 = 0;
	int FYP2CFL_JZ_starttime2 = 0;
	int FYP2CFL_JZ_code2[3][100]={ 0 };
	int FYP2CFL_JZ_code_length2 = 0;
	int FYP2CFL_FYP_starttime2 = 0;
	int FYP2CFL_FYP_code2[50] = { 0 };
	int FYP2CFL_FYP_code_length2 = 0;
	int CFL_hole_NO2 = 0;
	int FYP2CFL_CFL_arrive_time2 = 0;

	//�ŷ����������ر���
	int CFL2ZDQ_starttime = 0;
	int CFL2ZDQ_real_starttime = 0;
	int CFL2ZDQ_JZ_starttime = 0;
	int CFL2ZDQ_JZ_code[3][100] = { 0 };
	int CFL2ZDQ_JZ_code_length = 0;
	int CFL2ZDQ_ZDQ_arrive_time = 0;
	int CFL2ZDQ_hole_NO = 0;

	//������������ر���
	int ZDQ2GJC_starttime = 0;
	int ZDQ2GJC_real_starttime = 0;
	int ZDQ2GJC_JZ_starttime = 0;
	int ZDQ2GJC_JZ_code[3][100] = { 0 };
	int ZDQ2GJC_JZ_code_length = 0;
	int ZDQ2GJC_GJC_arrive_time = 0;

	plan.qb(qb_starttime, BJ_is_empty, BJ_need_changerow, BJ_changerow_time, BJ_cupNO, QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code,
		QB_time, FYP_putcup_time, QB_FYP_starttime, QB_FYP_use_holeNO, QB_FYP_code, QB_FYP_code_length, QB_finished_time,BJ_NO);
	plan.set_BJ_state(GBJ_Content);
	//������ز���
	if (BJ_NO == 0)
	{
		//���뻻����������
		int code[10] = { 0 };
		int CodeLength1;
		CodeLength1 = plan.bj.BJmovnextrow(code);
		int time = QB_JZ_starttime + jz_downtime + jz_opentime + jz_uptime + jz_movetime;
		for (int j = 0; j < CodeLength1; j++)
			xy[8][j + time] = code[j];
	}
	add_reagent1_starttime = connect.reagent_after_qb(QB_finished_time);

	while (unfinished)
	{
		add_reagent1_starttime += adjust_time;

		plan.add_reagent(10, add_reagent1_starttime, QB_FYP_use_holeNO, R1_location_NO, Reagent_Bin_NO, add_reagent1_real_starttime,
			FYP_add_reagent1_time, FYP_add_reagent1_starttime, addSJ1_FYP_occupytime, add_reagent1_code, add_reagent1_code_length,
			add_reagent1_FYP_code, add_reagent1_FYP_code_length);
		adjust_time = add_reagent1_real_starttime - add_reagent1_starttime;
		if (adjust_time > 0)
			continue;

		sample_starttime = connect.sample_after_reagent(add_reagent1_real_starttime, add_reagent1_code_length);
		plan.add_sample(2, sample_starttime, QB_FYP_use_holeNO, SampleNO, add_sample_real_starttime, FYP_add_sample_time,
			FYP_add_sample_starttime, add_sample_FYP_occupytime, add_sample_code, add_sample_code_length, add_sample_FYP_code,
			add_sample_FYP_code_length);
		adjust_time = add_sample_real_starttime - sample_starttime;
		if (adjust_time > 0)
			continue;

		mix1_starttime = connect.mix_after_sample(add_sample_real_starttime, add_sample_code_length);
		plan.mix(mix1_starttime, QB_FYP_use_holeNO, SampleNO, add_mix1_real_starttime, FYP_add_mix1_time,
			FYP_add_mix1_starttime, add_mix1_FYP_occupytime, add_mix1_code, add_mix1_code_length, add_mix1_FYP_code,
			add_mix1_FYP_code_length);
		adjust_time = add_mix1_real_starttime - mix1_starttime;
		if (adjust_time > 0)
			continue;

		FYP_out_time1 = connect.CFL_after_mix(FYP_add_mix1_starttime, add_mix1_FYP_code_length, FY_time1);
		plan.FYP2CFL(FYP_out_time1, QB_FYP_use_holeNO, FYP2CFL_real_starttime1, FYP2CFL_JZ_starttime1, FYP2CFL_JZ_code1, FYP2CFL_JZ_code_length1,
			FYP2CFL_FYP_starttime1, FYP2CFL_FYP_code1, FYP2CFL_FYP_code_length1, CFL_hole_NO1, FYP2CFL_CFL_arrive_time1);
		adjust_time = FYP2CFL_real_starttime1 - FYP_out_time1;
		if (adjust_time > 0)
			continue;

		CFL2FYP_starttime = connect.FYP_after_CFL(FYP2CFL_CFL_arrive_time1);
		plan.CFL2FYP(CFL2FYP_starttime, CFL2FYP_real_starttime, CFL2FYP_JZ_starttime, CFL2FYP_JZ_code, CFL2FYP_JZ_code_length,
			CFL2FYP_FYP_arrive_time, CFL2FYP_FYP_holeNO, CFL2FYP_FYP_starttime, CFL2FYP_FYP_code, CFL2FYP_FYP_code_length);
		adjust_time = CFL2FYP_real_starttime - CFL2FYP_starttime;
		if (adjust_time > 13)
			continue;

		add_reagent4_starttime = connect.reagent_after_FYP(CFL2FYP_FYP_starttime, CFL2FYP_FYP_code_length);
		plan.add_reagent(10, add_reagent4_starttime, CFL2FYP_FYP_holeNO, R4_Location_NO, Reagent_Bin_NO, add_reagent4_real_starttime, FYP_add_reagent4_time,
			FYP_add_reagent4_starttime, addSJ4_FYP_occupytime, add_reagent4_code, add_reagent4_code_length, add_reagent4_FYP_code, add_reagent4_FYP_code_length);
		adjust_time = add_reagent4_real_starttime - add_reagent4_starttime;
		if (adjust_time > 0)
			continue;

		mix2_starttime = connect.mix_after_reagent(add_reagent4_real_starttime, add_reagent4_code_length);
		plan.mix(mix2_starttime, CFL2FYP_FYP_holeNO, SampleNO, add_mix2_real_starttime, FYP_add_mix2_time,
			FYP_add_mix2_starttime, add_mix2_FYP_occupytime, add_mix2_code, add_mix2_code_length, add_mix2_FYP_code,
			add_mix2_FYP_code_length);
		adjust_time = add_mix2_real_starttime - mix2_starttime;
		if (adjust_time > 0)
			continue;

		FYP_out_time2 = connect.CFL_after_mix(FYP_add_mix2_starttime, add_mix2_FYP_code_length, FY_time2);
		plan.FYP2CFL(FYP_out_time2, CFL2FYP_FYP_holeNO, FYP2CFL_real_starttime2, FYP2CFL_JZ_starttime2, FYP2CFL_JZ_code2, FYP2CFL_JZ_code_length2,
			FYP2CFL_FYP_starttime2, FYP2CFL_FYP_code2, FYP2CFL_FYP_code_length2, CFL_hole_NO2, FYP2CFL_CFL_arrive_time2);
		adjust_time = FYP2CFL_real_starttime2 - FYP_out_time2;
		if (adjust_time > 0)
			continue;

		CFL2ZDQ_starttime = connect.ZDQ_after_CFL(FYP2CFL_CFL_arrive_time2);
		plan.CFL2ZDQ(CFL2ZDQ_starttime, CFL2ZDQ_real_starttime, CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code,
			CFL2ZDQ_JZ_code_length, CFL2ZDQ_ZDQ_arrive_time, CFL2ZDQ_hole_NO);
		adjust_time = CFL2ZDQ_real_starttime - CFL2ZDQ_starttime;
		if (adjust_time > 13)
			continue;

		ZDQ2GJC_starttime = connect.GJC_after_ZDG(CFL2ZDQ_ZDQ_arrive_time);
		plan.ZDQ2GJC(ZDQ2GJC_starttime, ZDQ2GJC_real_starttime, CFL2ZDQ_hole_NO, ZDQ2GJC_JZ_starttime,
			ZDQ2GJC_JZ_code, ZDQ2GJC_JZ_code_length, ZDQ2GJC_GJC_arrive_time);
		adjust_time = ZDQ2GJC_real_starttime - ZDQ2GJC_starttime;
		if (adjust_time > 0)
			continue;

		unfinished = false;
	}

	//��Ӳ������뼰��ռ�ô���
	//ȡ������
	add_code.add_JZ_move_code(QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code);
	add_code.add_FYP_move_code(QB_FYP_starttime, QB_FYP_code_length, QB_FYP_code);
	//���Լ�1����
	add_code.add_SJ_code(add_reagent1_real_starttime, add_reagent1_code_length, add_reagent1_code);
	add_code.add_FYP_move_code(FYP_add_reagent1_starttime, add_reagent1_FYP_code_length, add_reagent1_FYP_code);
	//����������
	add_code.add_sample_code(add_sample_real_starttime, add_sample_code_length, add_sample_code);
	add_code.add_FYP_move_code(FYP_add_sample_starttime, add_sample_FYP_code_length, add_sample_FYP_code);
	//����1����
	add_code.add_mix_code(add_mix1_real_starttime, add_mix1_code_length, add_mix1_code);
	add_code.add_FYP_move_code(FYP_add_mix1_starttime, add_mix1_FYP_code_length, add_mix1_FYP_code);
	//�����̵��ŷ������
	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime1, FYP2CFL_JZ_code_length1, FYP2CFL_JZ_code1);
	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime1, FYP2CFL_FYP_code_length1, FYP2CFL_FYP_code1);
	add_code.add_FYP_hole_occupy(QB_FYP_use_holeNO, FYP_putcup_time, FYP_out_time1);//�����̿׵�һ��ռ��
	//�ŷ��뵽�����̴���
	add_code.add_JZ_move_code(CFL2FYP_JZ_starttime, CFL2FYP_JZ_code_length, CFL2FYP_JZ_code);
	add_code.add_FYP_move_code(CFL2FYP_FYP_starttime, CFL2FYP_FYP_code_length, CFL2FYP_FYP_code);
	add_code.add_CFL_hole_occupy(CFL_hole_NO1, FYP2CFL_CFL_arrive_time1, CFL2FYP_starttime);//�ŷ���׵�һ��ռ��
	//���Լ�4����
	add_code.add_SJ_code(add_reagent4_real_starttime, add_reagent4_code_length, add_reagent4_code);
	add_code.add_FYP_move_code(FYP_add_reagent4_starttime, add_reagent4_FYP_code_length, add_reagent4_FYP_code);
	//����2����
	add_code.add_mix_code(add_mix2_real_starttime, add_mix2_code_length, add_mix2_code);
	add_code.add_FYP_move_code(FYP_add_mix2_starttime, add_mix2_FYP_code_length, add_mix2_FYP_code);
	//�����̵��ŷ���ڶ��δ���
	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime2, FYP2CFL_JZ_code_length2, FYP2CFL_JZ_code2);
	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime2, FYP2CFL_FYP_code_length2, FYP2CFL_FYP_code2);
	add_code.add_FYP_hole_occupy(CFL2FYP_FYP_holeNO, CFL2FYP_FYP_arrive_time, FYP_out_time2);//�����̿׵ڶ���ռ��
	//�ŷ��뵽��������
	add_code.add_JZ_move_code(CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code_length, CFL2ZDQ_JZ_code);
	add_code.add_CFL_hole_occupy(CFL_hole_NO2, FYP2CFL_CFL_arrive_time2, CFL2ZDQ_starttime);//�ŷ���׵ڶ���ռ��
	//�������������
	add_code.add_JZ_move_code(ZDQ2GJC_JZ_starttime, ZDQ2GJC_JZ_code_length, ZDQ2GJC_JZ_code);
	add_code.add_ZDQ_hole_occupy(CFL2ZDQ_hole_NO, CFL2ZDQ_ZDQ_arrive_time, ZDQ2GJC_real_starttime);//������ռ��
	//���������ӹ���
	int GJC_code_length = 0;
	int GJC_code[3][50] = { 0 };
	plan.gjc.createcode(36, mission_NO, GJC_code_length, GJC_code);
	int GJC_starttime = ZDQ2GJC_GJC_arrive_time;
	add_code.add_GJC_code(GJC_starttime - 1, GJC_code_length, GJC_code);
	add_code.add_GJC_hole_occupy(GJC_starttime - 1, GJC_starttime + 43);//�����ռ��
	//������
	add_code.add_ZDQ_motor_code();
	//�ŷ���ת��
	add_code.add_CFL_move_code(GJC_starttime + 1200, cfl_CFLcyclesteptime);
	totaltime = GJC_starttime + 1200;


	//��Ӵŷ���ע����Һ�������
	int length = 0;
	int zhushe1_time = 0;
	int paiye1_time = 0;
	int zhushe2_time = 0;
	int paiye2_time = 0;
	int diwu_time = 0;
	int CFLcode1[8][30] = { 0 };
	int CFLcode2[8][30] = { 0 };
	int CFLcode3[8][30] = { 0 };
	int CFLcode4[8][30] = { 0 };
	int CFLcode5[8][30] = { 0 };
	plan.cfl.CFLzhushe1codegenerate(CFLcode1, length);
	plan.cfl.CFLpaiye1codegenerate(CFLcode2, length);
	plan.cfl.CFLzhushe2codegenerate(CFLcode3, length);
	plan.cfl.CFLpaiye2codegenerate(CFLcode4, length);
	plan.cfl.CFLdiwucodegenerate(CFLcode5, length);
	//��һȦ
	zhushe1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 2) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 5) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 6) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 9) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//�ڶ�Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 2 + 12) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 5 + 12) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 6 + 12) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 9 + 12) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//����Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 2) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 5) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 6) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 9) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//����Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 2 + 12) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 5 + 12) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 6 + 12) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 9 + 12) * 17 + 1;
	diwu_time = (FYP2CFL_CFL_arrive_time2 / 17 + 10 + 12) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	add_code.add_CFL_operation_code(diwu_time, length, CFLcode5);

}

//ȡ�����Լ�1���������Լ�2������1����һ��FYP2CFL��CFL2FYP���Լ�4������2���ڶ���FYP2CFL����
void PRO::HCV(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R2_Location_NO, int R4_Location_NO, int qb_starttime, int FY_time1, int FY_time2)
{
	//���Ʊ���
	bool unfinished = true;
	int adjust_time = 0;

	//ȡ����ر���
	int BJ_is_empty = 0;
	int BJ_need_changerow = 0;
	int BJ_changerow_time = 0;
	int BJ_cupNO = 0;
	int QB_JZ_starttime = 0;
	int QB_JZ_code_length = 0;
	int QB_JZ_code[3][100] = { 0 };
	int QB_time = 0;
	int FYP_putcup_time = 0;
	int QB_FYP_starttime = 0;
	int QB_FYP_use_holeNO = 0;
	int QB_FYP_code[50] = { 0 };
	int QB_FYP_code_length = 0;
	int QB_finished_time = 0;
	int BJ_NO = 0;

	//���Լ�1��ر���
	int add_reagent1_starttime = 0;
	int add_reagent1_real_starttime = 0;
	int FYP_add_reagent1_time = 0;
	int FYP_add_reagent1_starttime = 0;
	int addSJ1_FYP_occupytime = 0;
	int add_reagent1_code[8][100] = { 0 };
	int add_reagent1_code_length = 0;
	int add_reagent1_FYP_code[50] = { 0 };
	int add_reagent1_FYP_code_length = 0;

	//��������ر���
	int sample_starttime = 0;
	int add_sample_real_starttime = 0;
	int FYP_add_sample_time = 0;
	int FYP_add_sample_starttime = 0;
	int add_sample_FYP_occupytime = 0;
	int add_sample_code[8][100] = { 0 };
	int add_sample_code_length = 0;
	int add_sample_FYP_code[50] = { 0 };
	int add_sample_FYP_code_length = 0;

	//���Լ�2��ر���
	int add_reagent2_starttime = 0;
	int add_reagent2_real_starttime = 0;
	int FYP_add_reagent2_time = 0;
	int FYP_add_reagent2_starttime = 0;
	int addSJ2_FYP_occupytime = 0;
	int add_reagent2_code[8][100] = { 0 };
	int add_reagent2_code_length = 0;
	int add_reagent2_FYP_code[50] = { 0 };
	int add_reagent2_FYP_code_length = 0;

	//����1��ر���
	int mix1_starttime = 0;
	int add_mix1_real_starttime = 0;
	int FYP_add_mix1_time = 0;
	int FYP_add_mix1_starttime = 0;
	int add_mix1_FYP_occupytime = 0;
	int add_mix1_code[8][100] = { 0 };
	int add_mix1_code_length = 0;
	int add_mix1_FYP_code[50] = { 0 };
	int add_mix1_FYP_code_length = 0;

	//��һ�ν��ŷ�����ر���
	int FYP_out_time1 = 0;
	int FYP2CFL_real_starttime1 = 0;
	int FYP2CFL_JZ_starttime1 = 0;
	int FYP2CFL_JZ_code1[3][100]={ 0 };
	int FYP2CFL_JZ_code_length1 = 0;
	int FYP2CFL_FYP_starttime1 = 0;
	int FYP2CFL_FYP_code1[50] = { 0 };
	int FYP2CFL_FYP_code_length1 = 0;
	int CFL_hole_NO1 = 0;
	int FYP2CFL_CFL_arrive_time1 = 0;

	//�ŷ��뵽��������ر���
	int CFL2FYP_starttime = 0;
	int CFL2FYP_real_starttime = 0;
	int CFL2FYP_JZ_starttime = 0;
	int CFL2FYP_JZ_code[3][100] = { 0 };
	int CFL2FYP_JZ_code_length = 0;
	int CFL2FYP_FYP_arrive_time = 0;
	int CFL2FYP_FYP_holeNO = 0;
	int CFL2FYP_FYP_starttime = 0;
	int CFL2FYP_FYP_code[50] = { 0 };
	int CFL2FYP_FYP_code_length = 0;

	//���Լ�4��ر���
	int add_reagent4_starttime = 0;
	int add_reagent4_real_starttime = 0;
	int FYP_add_reagent4_time = 0;
	int FYP_add_reagent4_starttime = 0;
	int addSJ4_FYP_occupytime = 0;
	int add_reagent4_code[8][100] = { 0 };
	int add_reagent4_code_length = 0;
	int add_reagent4_FYP_code[50] = { 0 };
	int add_reagent4_FYP_code_length = 0;

	//����2��ر���
	int mix2_starttime = 0;
	int add_mix2_real_starttime = 0;
	int FYP_add_mix2_time = 0;
	int FYP_add_mix2_starttime = 0;
	int add_mix2_FYP_occupytime = 0;
	int add_mix2_code[8][100] = { 0 };
	int add_mix2_code_length = 0;
	int add_mix2_FYP_code[50] = { 0 };
	int add_mix2_FYP_code_length = 0;

	//���ŷ�����ر���
	int FYP_out_time2 = 0;
	int FYP2CFL_real_starttime2 = 0;
	int FYP2CFL_JZ_starttime2 = 0;
	int FYP2CFL_JZ_code2[3][100]={ 0 };
	int FYP2CFL_JZ_code_length2 = 0;
	int FYP2CFL_FYP_starttime2 = 0;
	int FYP2CFL_FYP_code2[50] = { 0 };
	int FYP2CFL_FYP_code_length2 = 0;
	int CFL_hole_NO2 = 0;
	int FYP2CFL_CFL_arrive_time2 = 0;

	//�ŷ����������ر���
	int CFL2ZDQ_starttime = 0;
	int CFL2ZDQ_real_starttime = 0;
	int CFL2ZDQ_JZ_starttime = 0;
	int CFL2ZDQ_JZ_code[3][100] = { 0 };
	int CFL2ZDQ_JZ_code_length = 0;
	int CFL2ZDQ_ZDQ_arrive_time = 0;
	int CFL2ZDQ_hole_NO = 0;

	//������������ر���
	int ZDQ2GJC_starttime = 0;
	int ZDQ2GJC_real_starttime = 0;
	int ZDQ2GJC_JZ_starttime = 0;
	int ZDQ2GJC_JZ_code[3][100] = { 0 };
	int ZDQ2GJC_JZ_code_length = 0;
	int ZDQ2GJC_GJC_arrive_time = 0;

	plan.qb(qb_starttime, BJ_is_empty, BJ_need_changerow, BJ_changerow_time, BJ_cupNO, QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code,
		QB_time, FYP_putcup_time, QB_FYP_starttime, QB_FYP_use_holeNO, QB_FYP_code, QB_FYP_code_length, QB_finished_time,BJ_NO);
	plan.set_BJ_state(GBJ_Content);
	//������ز���
	if (BJ_NO == 0)
	{
		//���뻻����������
		int code[10] = { 0 };
		int CodeLength1;
		CodeLength1 = plan.bj.BJmovnextrow(code);
		int time = QB_JZ_starttime + jz_downtime + jz_opentime + jz_uptime + jz_movetime;
		for (int j = 0; j < CodeLength1; j++)
			xy[8][j + time] = code[j];
	}
	add_reagent1_starttime = connect.reagent_after_qb(QB_finished_time);

	while (unfinished)
	{
		add_reagent1_starttime += adjust_time;

		plan.add_reagent(10, add_reagent1_starttime, QB_FYP_use_holeNO, R1_location_NO, Reagent_Bin_NO, add_reagent1_real_starttime,
			FYP_add_reagent1_time, FYP_add_reagent1_starttime, addSJ1_FYP_occupytime, add_reagent1_code, add_reagent1_code_length,
			add_reagent1_FYP_code, add_reagent1_FYP_code_length);
		adjust_time = add_reagent1_real_starttime - add_reagent1_starttime;
		if (adjust_time > 0)
			continue;

		sample_starttime = connect.sample_after_reagent(add_reagent1_real_starttime, add_reagent1_code_length);
		plan.add_sample(10, sample_starttime, QB_FYP_use_holeNO, SampleNO, add_sample_real_starttime, FYP_add_sample_time,
			FYP_add_sample_starttime, add_sample_FYP_occupytime, add_sample_code, add_sample_code_length, add_sample_FYP_code,
			add_sample_FYP_code_length);
		adjust_time = add_sample_real_starttime - sample_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent2_starttime = connect.reagent_after_sample(add_sample_real_starttime, add_sample_code_length);
		plan.add_reagent(10, add_reagent2_starttime, QB_FYP_use_holeNO, R2_Location_NO, Reagent_Bin_NO, add_reagent2_real_starttime,
			FYP_add_reagent2_time, FYP_add_reagent2_starttime, addSJ2_FYP_occupytime, add_reagent2_code, add_reagent2_code_length,
			add_reagent2_FYP_code, add_reagent2_FYP_code_length);
		adjust_time = add_reagent2_real_starttime - add_reagent2_starttime;
		if (adjust_time > 0)
			continue;

		mix1_starttime = connect.mix_after_reagent(add_reagent2_real_starttime, add_reagent2_code_length);
		plan.mix(mix1_starttime, QB_FYP_use_holeNO, SampleNO, add_mix1_real_starttime, FYP_add_mix1_time,
			FYP_add_mix1_starttime, add_mix1_FYP_occupytime, add_mix1_code, add_mix1_code_length, add_mix1_FYP_code,
			add_mix1_FYP_code_length);
		adjust_time = add_mix1_real_starttime - mix1_starttime;
		if (adjust_time > 0)
			continue;

		FYP_out_time1 = connect.CFL_after_mix(FYP_add_mix1_starttime, add_mix1_FYP_code_length, FY_time1);
		plan.FYP2CFL(FYP_out_time1, QB_FYP_use_holeNO, FYP2CFL_real_starttime1, FYP2CFL_JZ_starttime1, FYP2CFL_JZ_code1, FYP2CFL_JZ_code_length1,
			FYP2CFL_FYP_starttime1, FYP2CFL_FYP_code1, FYP2CFL_FYP_code_length1, CFL_hole_NO1, FYP2CFL_CFL_arrive_time1);
		adjust_time = FYP2CFL_real_starttime1 - FYP_out_time1;
		if (adjust_time > 0)
			continue;

		CFL2FYP_starttime = connect.FYP_after_CFL(FYP2CFL_CFL_arrive_time1);
		plan.CFL2FYP(CFL2FYP_starttime, CFL2FYP_real_starttime, CFL2FYP_JZ_starttime, CFL2FYP_JZ_code, CFL2FYP_JZ_code_length,
			CFL2FYP_FYP_arrive_time, CFL2FYP_FYP_holeNO, CFL2FYP_FYP_starttime, CFL2FYP_FYP_code, CFL2FYP_FYP_code_length);
		adjust_time = CFL2FYP_real_starttime - CFL2FYP_starttime;
		if (adjust_time > 13)
			continue;

		add_reagent4_starttime = connect.reagent_after_FYP(CFL2FYP_FYP_starttime, CFL2FYP_FYP_code_length);
		plan.add_reagent(10, add_reagent4_starttime, CFL2FYP_FYP_holeNO, R4_Location_NO, Reagent_Bin_NO, add_reagent4_real_starttime, FYP_add_reagent4_time,
			FYP_add_reagent4_starttime, addSJ4_FYP_occupytime, add_reagent4_code, add_reagent4_code_length, add_reagent4_FYP_code, add_reagent4_FYP_code_length);
		adjust_time = add_reagent4_real_starttime - add_reagent4_starttime;
		if (adjust_time > 0)
			continue;

		mix2_starttime = connect.mix_after_reagent(add_reagent4_real_starttime, add_reagent4_code_length);
		plan.mix(mix2_starttime, CFL2FYP_FYP_holeNO, SampleNO, add_mix2_real_starttime, FYP_add_mix2_time,
			FYP_add_mix2_starttime, add_mix2_FYP_occupytime, add_mix2_code, add_mix2_code_length, add_mix2_FYP_code,
			add_mix2_FYP_code_length);
		adjust_time = add_mix2_real_starttime - mix2_starttime;
		if (adjust_time > 0)
			continue;

		FYP_out_time2 = connect.CFL_after_mix(FYP_add_mix2_starttime, add_mix2_FYP_code_length, FY_time2);
		plan.FYP2CFL(FYP_out_time2, CFL2FYP_FYP_holeNO, FYP2CFL_real_starttime2, FYP2CFL_JZ_starttime2, FYP2CFL_JZ_code2, FYP2CFL_JZ_code_length2,
			FYP2CFL_FYP_starttime2, FYP2CFL_FYP_code2, FYP2CFL_FYP_code_length2, CFL_hole_NO2, FYP2CFL_CFL_arrive_time2);
		adjust_time = FYP2CFL_real_starttime2 - FYP_out_time2;
		if (adjust_time > 0)
			continue;

		CFL2ZDQ_starttime = connect.ZDQ_after_CFL(FYP2CFL_CFL_arrive_time2);
		plan.CFL2ZDQ(CFL2ZDQ_starttime, CFL2ZDQ_real_starttime, CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code,
			CFL2ZDQ_JZ_code_length, CFL2ZDQ_ZDQ_arrive_time, CFL2ZDQ_hole_NO);
		adjust_time = CFL2ZDQ_real_starttime - CFL2ZDQ_starttime;
		if (adjust_time > 13)
			continue;

		ZDQ2GJC_starttime = connect.GJC_after_ZDG(CFL2ZDQ_ZDQ_arrive_time);
		plan.ZDQ2GJC(ZDQ2GJC_starttime, ZDQ2GJC_real_starttime, CFL2ZDQ_hole_NO, ZDQ2GJC_JZ_starttime,
			ZDQ2GJC_JZ_code, ZDQ2GJC_JZ_code_length, ZDQ2GJC_GJC_arrive_time);
		adjust_time = ZDQ2GJC_real_starttime - ZDQ2GJC_starttime;
		if (adjust_time > 0)
			continue;

		unfinished = false;
	}

	//��Ӳ������뼰��ռ�ô���
	//ȡ������
	add_code.add_JZ_move_code(QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code);
	add_code.add_FYP_move_code(QB_FYP_starttime, QB_FYP_code_length, QB_FYP_code);
	//���Լ�1����
	add_code.add_SJ_code(add_reagent1_real_starttime, add_reagent1_code_length, add_reagent1_code);
	add_code.add_FYP_move_code(FYP_add_reagent1_starttime, add_reagent1_FYP_code_length, add_reagent1_FYP_code);
	//����������
	add_code.add_sample_code(add_sample_real_starttime, add_sample_code_length, add_sample_code);
	add_code.add_FYP_move_code(FYP_add_sample_starttime, add_sample_FYP_code_length, add_sample_FYP_code);
	//���Լ�2����
	add_code.add_SJ_code(add_reagent2_real_starttime, add_reagent2_code_length, add_reagent2_code);
	add_code.add_FYP_move_code(FYP_add_reagent2_starttime, add_reagent2_FYP_code_length, add_reagent2_FYP_code);
	//����1����
	add_code.add_mix_code(add_mix1_real_starttime, add_mix1_code_length, add_mix1_code);
	add_code.add_FYP_move_code(FYP_add_mix1_starttime, add_mix1_FYP_code_length, add_mix1_FYP_code);
	//�����̵��ŷ������
	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime1, FYP2CFL_JZ_code_length1, FYP2CFL_JZ_code1);
	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime1, FYP2CFL_FYP_code_length1, FYP2CFL_FYP_code1);
	add_code.add_FYP_hole_occupy(QB_FYP_use_holeNO, FYP_putcup_time, FYP_out_time1);//�����̿׵�һ��ռ��
	//�ŷ��뵽�����̴���
	add_code.add_JZ_move_code(CFL2FYP_JZ_starttime, CFL2FYP_JZ_code_length, CFL2FYP_JZ_code);
	add_code.add_FYP_move_code(CFL2FYP_FYP_starttime, CFL2FYP_FYP_code_length, CFL2FYP_FYP_code);
	add_code.add_CFL_hole_occupy(CFL_hole_NO1, FYP2CFL_CFL_arrive_time1, CFL2FYP_starttime);//�ŷ���׵�һ��ռ��
	//���Լ�4����
	add_code.add_SJ_code(add_reagent4_real_starttime, add_reagent4_code_length, add_reagent4_code);
	add_code.add_FYP_move_code(FYP_add_reagent4_starttime, add_reagent4_FYP_code_length, add_reagent4_FYP_code);
	//����2����
	add_code.add_mix_code(add_mix2_real_starttime, add_mix2_code_length, add_mix2_code);
	add_code.add_FYP_move_code(FYP_add_mix2_starttime, add_mix2_FYP_code_length, add_mix2_FYP_code);
	//�����̵��ŷ���ڶ��δ���
	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime2, FYP2CFL_JZ_code_length2, FYP2CFL_JZ_code2);
	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime2, FYP2CFL_FYP_code_length2, FYP2CFL_FYP_code2);
	add_code.add_FYP_hole_occupy(CFL2FYP_FYP_holeNO, CFL2FYP_FYP_arrive_time, FYP_out_time2);//�����̿׵ڶ���ռ��
	//�ŷ��뵽��������
	add_code.add_JZ_move_code(CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code_length, CFL2ZDQ_JZ_code);
	add_code.add_CFL_hole_occupy(CFL_hole_NO2, FYP2CFL_CFL_arrive_time2, CFL2ZDQ_starttime);//�ŷ���׵ڶ���ռ��
	//�������������
	add_code.add_JZ_move_code(ZDQ2GJC_JZ_starttime, ZDQ2GJC_JZ_code_length, ZDQ2GJC_JZ_code);
	add_code.add_ZDQ_hole_occupy(CFL2ZDQ_hole_NO, CFL2ZDQ_ZDQ_arrive_time, ZDQ2GJC_real_starttime);//������ռ��
	//���������ӹ���
	int GJC_code_length = 0;
	int GJC_code[3][50] = { 0 };
	plan.gjc.createcode(36, mission_NO, GJC_code_length, GJC_code);
	int GJC_starttime = ZDQ2GJC_GJC_arrive_time;
	add_code.add_GJC_code(GJC_starttime - 1, GJC_code_length, GJC_code);
	add_code.add_GJC_hole_occupy(GJC_starttime - 1, GJC_starttime + 43);//�����ռ��
	//������
	add_code.add_ZDQ_motor_code();
	//�ŷ���ת��
	add_code.add_CFL_move_code(GJC_starttime + 1200, cfl_CFLcyclesteptime);
	
	totaltime = GJC_starttime + 1200;

	//��Ӵŷ���ע����Һ�������
	int length = 0;
	int zhushe1_time = 0;
	int paiye1_time = 0;
	int zhushe2_time = 0;
	int paiye2_time = 0;
	int diwu_time = 0;
	int CFLcode1[8][30] = { 0 };
	int CFLcode2[8][30] = { 0 };
	int CFLcode3[8][30] = { 0 };
	int CFLcode4[8][30] = { 0 };
	int CFLcode5[8][30] = { 0 };
	plan.cfl.CFLzhushe1codegenerate(CFLcode1, length);
	plan.cfl.CFLpaiye1codegenerate(CFLcode2, length);
	plan.cfl.CFLzhushe2codegenerate(CFLcode3, length);
	plan.cfl.CFLpaiye2codegenerate(CFLcode4, length);
	plan.cfl.CFLdiwucodegenerate(CFLcode5, length);
	//��һȦ
	zhushe1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 2) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 5) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 6) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 9) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//�ڶ�Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 2 + 12) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 5 + 12) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 6 + 12) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 9 + 12) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//����Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 2) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 5) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 6) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 9) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//����Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 2 + 12) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 5 + 12) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 6 + 12) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 9 + 12) * 17 + 1;
	diwu_time = (FYP2CFL_CFL_arrive_time2 / 17 + 10 + 12) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	add_code.add_CFL_operation_code(diwu_time, length, CFLcode5);
}

//�Լ�4���������������Լ�1����������ϴ���ӵ���𵴡����
void PRO::HBsAb(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_Location_NO, int R4_Location_NO, int qb_starttime, int FY_time1, int FY_time2)
{
	//���Ʊ���
	bool unfinished = true;
	int adjust_time = 0;

	//ȡ����ر���
	int BJ_is_empty = 0;
	int BJ_need_changerow = 0;
	int BJ_changerow_time = 0;
	int BJ_cupNO = 0;
	int QB_JZ_starttime = 0;
	int QB_JZ_code_length = 0;
	int QB_JZ_code[3][100] = { 0 };
	int QB_time = 0;
	int FYP_putcup_time = 0;
	int QB_FYP_starttime = 0;
	int QB_FYP_use_holeNO = 0;
	int QB_FYP_code[50] = { 0 };
	int QB_FYP_code_length = 0;
	int QB_finished_time = 0;
	int BJ_NO = 0;

	//���Լ�4��ر���
	int add_reagent4_starttime = 0;
	int add_reagent4_real_starttime = 0;
	int FYP_add_reagent4_time = 0;
	int FYP_add_reagent4_starttime = 0;
	int addSJ4_FYP_occupytime = 0;
	int add_reagent4_code[8][100] = { 0 };
	int add_reagent4_code_length = 0;
	int add_reagent4_FYP_code[50] = { 0 };
	int add_reagent4_FYP_code_length = 0;

	//��������ر���
	int sample_starttime = 0;
	int add_sample_real_starttime = 0;
	int FYP_add_sample_time = 0;
	int FYP_add_sample_starttime = 0;
	int add_sample_FYP_occupytime = 0;
	int add_sample_code[8][100] = { 0 };
	int add_sample_code_length = 0;
	int add_sample_FYP_code[50] = { 0 };
	int add_sample_FYP_code_length = 0;

	//����1��ر���
	int mix1_starttime = 0;
	int add_mix1_real_starttime = 0;
	int FYP_add_mix1_time = 0;
	int FYP_add_mix1_starttime = 0;
	int add_mix1_FYP_occupytime = 0;
	int add_mix1_code[8][100] = { 0 };
	int add_mix1_code_length = 0;
	int add_mix1_FYP_code[50] = { 0 };
	int add_mix1_FYP_code_length = 0;

	//���Լ�1��ر���
	int add_reagent1_starttime = 0;
	int add_reagent1_real_starttime = 0;
	int FYP_add_reagent1_time = 0;
	int FYP_add_reagent1_starttime = 0;
	int addSJ1_FYP_occupytime = 0;
	int add_reagent1_code[8][100] = { 0 };
	int add_reagent1_code_length = 0;
	int add_reagent1_FYP_code[50] = { 0 };
	int add_reagent1_FYP_code_length = 0;

	//������ر���
	int mix2_starttime = 0;
	int add_mix2_real_starttime = 0;
	int FYP_add_mix2_time = 0;
	int FYP_add_mix2_starttime = 0;
	int add_mix2_FYP_occupytime = 0;
	int add_mix2_code[8][100] = { 0 };
	int add_mix2_code_length = 0;
	int add_mix2_FYP_code[50] = { 0 };
	int add_mix2_FYP_code_length = 0;

	//���ŷ�����ر���
	int FYP_out_time = 0;
	int FYP2CFL_real_starttime = 0;
	int FYP2CFL_JZ_starttime = 0;
	int FYP2CFL_JZ_code[3][100]={ 0 };
	int FYP2CFL_JZ_code_length = 0;
	int FYP2CFL_FYP_starttime = 0;
	int FYP2CFL_FYP_code[50] = { 0 };
	int FYP2CFL_FYP_code_length = 0;
	int CFL_hole_NO = 0;
	int FYP2CFL_CFL_arrive_time = 0;

	//�ŷ����������ر���
	int CFL2ZDQ_starttime = 0;
	int CFL2ZDQ_real_starttime = 0;
	int CFL2ZDQ_JZ_starttime = 0;
	int CFL2ZDQ_JZ_code[3][100] = { 0 };
	int CFL2ZDQ_JZ_code_length = 0;
	int CFL2ZDQ_ZDQ_arrive_time = 0;
	int CFL2ZDQ_hole_NO = 0;

	//������������ر���
	int ZDQ2GJC_starttime = 0;
	int ZDQ2GJC_real_starttime = 0;
	int ZDQ2GJC_JZ_starttime = 0;
	int ZDQ2GJC_JZ_code[3][100] = { 0 };
	int ZDQ2GJC_JZ_code_length = 0;
	int ZDQ2GJC_GJC_arrive_time = 0;

	plan.qb(qb_starttime, BJ_is_empty, BJ_need_changerow, BJ_changerow_time, BJ_cupNO, QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code,
		QB_time, FYP_putcup_time, QB_FYP_starttime, QB_FYP_use_holeNO, QB_FYP_code, QB_FYP_code_length, QB_finished_time,BJ_NO);
	plan.set_BJ_state(GBJ_Content);
	//������ز���
	if (BJ_NO == 0)
	{
		//���뻻����������
		int code[10] = { 0 };
		int CodeLength1;
		CodeLength1 = plan.bj.BJmovnextrow(code);
		int time = QB_JZ_starttime + jz_downtime + jz_opentime + jz_uptime + jz_movetime;
		for (int j = 0; j < CodeLength1; j++)
			xy[8][j + time] = code[j];
	}
	add_reagent4_starttime = connect.reagent_after_qb(QB_finished_time);

	while (unfinished)
	{
		add_reagent4_starttime += adjust_time;

		plan.add_reagent(20, add_reagent4_starttime, QB_FYP_use_holeNO, R4_Location_NO, Reagent_Bin_NO, add_reagent4_real_starttime,
			FYP_add_reagent4_time, FYP_add_reagent4_starttime, addSJ4_FYP_occupytime, add_reagent4_code, add_reagent4_code_length,
			add_reagent4_FYP_code, add_reagent4_FYP_code_length);
		adjust_time = add_reagent4_real_starttime - add_reagent4_starttime;
		if (adjust_time > 0)
			continue;

		sample_starttime = connect.sample_after_reagent(add_reagent4_real_starttime, add_reagent4_code_length);
		plan.add_sample(10, sample_starttime, QB_FYP_use_holeNO, SampleNO, add_sample_real_starttime, FYP_add_sample_time,
			FYP_add_sample_starttime, add_sample_FYP_occupytime, add_sample_code, add_sample_code_length, add_sample_FYP_code,
			add_sample_FYP_code_length);
		adjust_time = add_sample_real_starttime - sample_starttime;
		if (adjust_time > 0)
			continue;

		mix1_starttime = connect.mix_after_sample(add_sample_real_starttime, add_sample_code_length);
		plan.mix(mix1_starttime, QB_FYP_use_holeNO, SampleNO, add_mix1_real_starttime, FYP_add_mix1_time,
			FYP_add_mix1_starttime, add_mix1_FYP_occupytime, add_mix1_code, add_mix1_code_length, add_mix1_FYP_code,
			add_mix1_FYP_code_length);
		adjust_time = add_mix1_real_starttime - mix1_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent1_starttime = connect.reagent_after_mix(FYP_add_mix1_starttime, add_mix1_FYP_code_length, FY_time1);
		plan.add_reagent(10, add_reagent1_starttime, QB_FYP_use_holeNO, R1_Location_NO, Reagent_Bin_NO, add_reagent1_real_starttime, FYP_add_reagent1_time,
			FYP_add_reagent1_starttime, addSJ1_FYP_occupytime, add_reagent1_code, add_reagent1_code_length, add_reagent1_FYP_code, add_reagent1_FYP_code_length);
		adjust_time = add_reagent1_real_starttime - add_reagent1_starttime;
		if (adjust_time > 0)
			continue;

		mix2_starttime = connect.mix_after_reagent(add_reagent1_real_starttime, add_reagent1_code_length);
		plan.mix(mix2_starttime, QB_FYP_use_holeNO, SampleNO, add_mix2_real_starttime, FYP_add_mix2_time,
			FYP_add_mix2_starttime, add_mix2_FYP_occupytime, add_mix2_code, add_mix2_code_length, add_mix2_FYP_code,
			add_mix2_FYP_code_length);
		adjust_time = add_mix2_real_starttime - mix2_starttime;
		if (adjust_time > 0)
			continue;

		FYP_out_time = connect.CFL_after_mix(FYP_add_mix2_starttime, add_mix2_FYP_code_length, FY_time2);
		plan.FYP2CFL(FYP_out_time, QB_FYP_use_holeNO, FYP2CFL_real_starttime, FYP2CFL_JZ_starttime, FYP2CFL_JZ_code, FYP2CFL_JZ_code_length,
			FYP2CFL_FYP_starttime, FYP2CFL_FYP_code, FYP2CFL_FYP_code_length, CFL_hole_NO, FYP2CFL_CFL_arrive_time);
		adjust_time = FYP2CFL_real_starttime - FYP_out_time;
		if (adjust_time > 0)
			continue;

		CFL2ZDQ_starttime = connect.ZDQ_after_CFL(FYP2CFL_CFL_arrive_time);
		plan.CFL2ZDQ(CFL2ZDQ_starttime, CFL2ZDQ_real_starttime, CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code,
			CFL2ZDQ_JZ_code_length, CFL2ZDQ_ZDQ_arrive_time, CFL2ZDQ_hole_NO);
		adjust_time = CFL2ZDQ_real_starttime - CFL2ZDQ_starttime;
		if (adjust_time > 13)
			continue;

		ZDQ2GJC_starttime = connect.GJC_after_ZDG(CFL2ZDQ_ZDQ_arrive_time);//������������148s
		plan.ZDQ2GJC(ZDQ2GJC_starttime, ZDQ2GJC_real_starttime, CFL2ZDQ_hole_NO, ZDQ2GJC_JZ_starttime,
			ZDQ2GJC_JZ_code, ZDQ2GJC_JZ_code_length, ZDQ2GJC_GJC_arrive_time);
		adjust_time = ZDQ2GJC_real_starttime - ZDQ2GJC_starttime;
		if (adjust_time > 0)
			continue;
		unfinished = false;
	}

	//��Ӳ�������
	//ȡ������
	add_code.add_JZ_move_code(QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code);
	add_code.add_FYP_move_code(QB_FYP_starttime, QB_FYP_code_length, QB_FYP_code);
	//�Լ�4����
	add_code.add_SJ_code(add_reagent4_real_starttime, add_reagent4_code_length, add_reagent4_code);
	add_code.add_FYP_move_code(FYP_add_reagent4_starttime, add_reagent4_FYP_code_length, add_reagent4_FYP_code);
	//��������
	add_code.add_sample_code(add_sample_real_starttime, add_sample_code_length, add_sample_code);
	add_code.add_FYP_move_code(FYP_add_sample_starttime, add_sample_FYP_code_length, add_sample_FYP_code);
	//�ӽ���1����
	add_code.add_mix_code(add_mix1_real_starttime, add_mix1_code_length, add_mix1_code);
	add_code.add_FYP_move_code(FYP_add_mix1_starttime, add_mix1_FYP_code_length, add_mix1_FYP_code);
	//�Լ�1����
	add_code.add_SJ_code(add_reagent1_real_starttime, add_reagent1_code_length, add_reagent1_code);
	add_code.add_FYP_move_code(FYP_add_reagent1_starttime, add_reagent1_FYP_code_length, add_reagent1_FYP_code);
	//�ӽ���2����
	add_code.add_mix_code(add_mix2_real_starttime, add_mix2_code_length, add_mix2_code);
	add_code.add_FYP_move_code(FYP_add_mix2_starttime, add_mix2_FYP_code_length, add_mix2_FYP_code);
	//�����̵��ŷ������
	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime, FYP2CFL_JZ_code_length, FYP2CFL_JZ_code);
	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime, FYP2CFL_FYP_code_length, FYP2CFL_FYP_code);
	add_code.add_FYP_hole_occupy(QB_FYP_use_holeNO, FYP_putcup_time, FYP_out_time);//�����̿�ռ��
	//�ŷ��뵽��������
	add_code.add_JZ_move_code(CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code_length, CFL2ZDQ_JZ_code);
	add_code.add_CFL_hole_occupy(CFL_hole_NO, FYP2CFL_CFL_arrive_time, CFL2ZDQ_real_starttime);//�ŷ����ռ��
	//�������������
	add_code.add_JZ_move_code(ZDQ2GJC_JZ_starttime, ZDQ2GJC_JZ_code_length, ZDQ2GJC_JZ_code);
	add_code.add_ZDQ_hole_occupy(CFL2ZDQ_hole_NO, CFL2ZDQ_ZDQ_arrive_time, ZDQ2GJC_starttime);//������ռ��
	//������̴���
	int GJC_code_length = 0;
	int GJC_code[3][50] = { 0 };
	plan.gjc.createcode(36, mission_NO, GJC_code_length, GJC_code);
	int GJC_starttime = ZDQ2GJC_GJC_arrive_time;
	add_code.add_GJC_code(GJC_starttime - 1, GJC_code_length, GJC_code);
	add_code.add_GJC_hole_occupy(GJC_starttime - 1, GJC_starttime + 43);//�����ռ��
	//������
	add_code.add_ZDQ_motor_code();
	//�ŷ���ת��
	add_code.add_CFL_move_code(GJC_starttime + 1200, cfl_CFLcyclesteptime);
	
	totaltime = GJC_starttime + 1200;

	//��Ӵŷ���ע����Һ�������
	int length = 0;
	int zhushe1_time = 0;
	int paiye1_time = 0;
	int zhushe2_time = 0;
	int paiye2_time = 0;
	int diwu_time = 0;
	int CFLcode1[8][30] = { 0 };
	int CFLcode2[8][30] = { 0 };
	int CFLcode3[8][30] = { 0 };
	int CFLcode4[8][30] = { 0 };
	int CFLcode5[8][30] = { 0 };
	plan.cfl.CFLzhushe1codegenerate(CFLcode1, length);
	plan.cfl.CFLpaiye1codegenerate(CFLcode2, length);
	plan.cfl.CFLzhushe2codegenerate(CFLcode3, length);
	plan.cfl.CFLpaiye2codegenerate(CFLcode4, length);
	plan.cfl.CFLdiwucodegenerate(CFLcode5, length);
	//��һȦ
	zhushe1_time = (FYP2CFL_CFL_arrive_time / 17 + 2) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time / 17 + 5) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time / 17 + 6) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time / 17 + 9) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//�ڶ�Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time / 17 + 2 + 12) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time / 17 + 5 + 12) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time / 17 + 6 + 12) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time / 17 + 9 + 12) * 17 + 1;
	diwu_time = (FYP2CFL_CFL_arrive_time / 17 + 10 + 12) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	add_code.add_CFL_operation_code(diwu_time, length, CFLcode5);
}

//�Լ�3������������1������������ϴ�����Լ�2������2������������ϴ�����Լ�1������3����������ϴ���ӵ���𵴡����
void PRO::HBcAb(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_Location_NO, int R2_Location_NO, int R3_Location_NO, int qb_starttime, int FY_time1, int FY_time2, int FY_time3)
{
	//���Ʊ���
	bool unfinished = true;
	int adjust_time = 0;

	//ȡ����ر���
	int BJ_is_empty = 0;
	int BJ_need_changerow = 0;
	int BJ_changerow_time = 0;
	int BJ_cupNO = 0;
	int QB_JZ_starttime = 0;
	int QB_JZ_code_length = 0;
	int QB_JZ_code[3][100] = { 0 };
	int QB_time = 0;
	int FYP_putcup_time = 0;
	int QB_FYP_starttime = 0;
	int QB_FYP_use_holeNO = 0;
	int QB_FYP_code[50] = { 0 };
	int QB_FYP_code_length = 0;
	int QB_finished_time = 0;
	int BJ_NO = 0;

	//���Լ�3��ر���
	int add_reagent3_starttime = 0;
	int add_reagent3_real_starttime = 0;
	int FYP_add_reagent3_time = 0;
	int FYP_add_reagent3_starttime = 0;
	int addSJ3_FYP_occupytime = 0;
	int add_reagent3_code[8][100] = { 0 };
	int add_reagent3_code_length = 0;
	int add_reagent3_FYP_code[50] = { 0 };
	int add_reagent3_FYP_code_length = 0;

	//��������ر���
	int sample_starttime = 0;
	int add_sample_real_starttime = 0;
	int FYP_add_sample_time = 0;
	int FYP_add_sample_starttime = 0;
	int add_sample_FYP_occupytime = 0;
	int add_sample_code[8][100] = { 0 };
	int add_sample_code_length = 0;
	int add_sample_FYP_code[50] = { 0 };
	int add_sample_FYP_code_length = 0;

	//����1��ر���
	int mix1_starttime = 0;
	int add_mix1_real_starttime = 0;
	int FYP_add_mix1_time = 0;
	int FYP_add_mix1_starttime = 0;
	int add_mix1_FYP_occupytime = 0;
	int add_mix1_code[8][100] = { 0 };
	int add_mix1_code_length = 0;
	int add_mix1_FYP_code[50] = { 0 };
	int add_mix1_FYP_code_length = 0;

	//���Լ�2��ر���
	int add_reagent2_starttime = 0;
	int add_reagent2_real_starttime = 0;
	int FYP_add_reagent2_time = 0;
	int FYP_add_reagent2_starttime = 0;
	int addSJ2_FYP_occupytime = 0;
	int add_reagent2_code[8][100] = { 0 };
	int add_reagent2_code_length = 0;
	int add_reagent2_FYP_code[50] = { 0 };
	int add_reagent2_FYP_code_length = 0;

	//������ر���
	int mix2_starttime = 0;
	int add_mix2_real_starttime = 0;
	int FYP_add_mix2_time = 0;
	int FYP_add_mix2_starttime = 0;
	int add_mix2_FYP_occupytime = 0;
	int add_mix2_code[8][100] = { 0 };
	int add_mix2_code_length = 0;
	int add_mix2_FYP_code[50] = { 0 };
	int add_mix2_FYP_code_length = 0;

	//���Լ�1��ر���
	int add_reagent1_starttime = 0;
	int add_reagent1_real_starttime = 0;
	int FYP_add_reagent1_time = 0;
	int FYP_add_reagent1_starttime = 0;
	int addSJ1_FYP_occupytime = 0;
	int add_reagent1_code[8][100] = { 0 };
	int add_reagent1_code_length = 0;
	int add_reagent1_FYP_code[50] = { 0 };
	int add_reagent1_FYP_code_length = 0;

	//����3��ر���
	int mix3_starttime = 0;
	int add_mix3_real_starttime = 0;
	int FYP_add_mix3_time = 0;
	int FYP_add_mix3_starttime = 0;
	int add_mix3_FYP_occupytime = 0;
	int add_mix3_code[8][100] = { 0 };
	int add_mix3_code_length = 0;
	int add_mix3_FYP_code[50] = { 0 };
	int add_mix3_FYP_code_length = 0;

	//���ŷ�����ر���
	int FYP_out_time = 0;
	int FYP2CFL_real_starttime = 0;
	int FYP2CFL_JZ_starttime = 0;
	int FYP2CFL_JZ_code[3][100]={ 0 };
	int FYP2CFL_JZ_code_length = 0;
	int FYP2CFL_FYP_starttime = 0;
	int FYP2CFL_FYP_code[50] = { 0 };
	int FYP2CFL_FYP_code_length = 0;
	int CFL_hole_NO = 0;
	int FYP2CFL_CFL_arrive_time = 0;

	//�ŷ����������ر���
	int CFL2ZDQ_starttime = 0;
	int CFL2ZDQ_real_starttime = 0;
	int CFL2ZDQ_JZ_starttime = 0;
	int CFL2ZDQ_JZ_code[3][100] = { 0 };
	int CFL2ZDQ_JZ_code_length = 0;
	int CFL2ZDQ_ZDQ_arrive_time = 0;
	int CFL2ZDQ_hole_NO = 0;

	//������������ر���
	int ZDQ2GJC_starttime = 0;
	int ZDQ2GJC_real_starttime = 0;
	int ZDQ2GJC_JZ_starttime = 0;
	int ZDQ2GJC_JZ_code[3][100] = { 0 };
	int ZDQ2GJC_JZ_code_length = 0;
	int ZDQ2GJC_GJC_arrive_time = 0;

	plan.qb(qb_starttime, BJ_is_empty, BJ_need_changerow, BJ_changerow_time, BJ_cupNO, QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code,
		QB_time, FYP_putcup_time, QB_FYP_starttime, QB_FYP_use_holeNO, QB_FYP_code, QB_FYP_code_length, QB_finished_time,BJ_NO);
	plan.set_BJ_state(GBJ_Content);
	//������ز���
	if (BJ_NO == 0)
	{
		//���뻻����������
		int code[10] = { 0 };
		int CodeLength1;
		CodeLength1 = plan.bj.BJmovnextrow(code);
		int time = QB_JZ_starttime + jz_downtime + jz_opentime + jz_uptime + jz_movetime;
		for (int j = 0; j < CodeLength1; j++)
			xy[8][j + time] = code[j];
	}
	add_reagent3_starttime = connect.reagent_after_qb(QB_finished_time);

	while (unfinished)
	{
		add_reagent3_starttime += adjust_time;

		plan.add_reagent(10, add_reagent3_starttime, QB_FYP_use_holeNO, R1_Location_NO, Reagent_Bin_NO, add_reagent3_real_starttime,
			FYP_add_reagent3_time, FYP_add_reagent3_starttime, addSJ3_FYP_occupytime, add_reagent3_code, add_reagent3_code_length,
			add_reagent3_FYP_code, add_reagent3_FYP_code_length);
		adjust_time = add_reagent3_real_starttime - add_reagent3_starttime;
		if (adjust_time > 0)
			continue;

		sample_starttime = connect.sample_after_reagent(add_reagent3_real_starttime, add_reagent3_code_length);
		plan.add_sample(10, sample_starttime, QB_FYP_use_holeNO, SampleNO, add_sample_real_starttime, FYP_add_sample_time,
			FYP_add_sample_starttime, add_sample_FYP_occupytime, add_sample_code, add_sample_code_length, add_sample_FYP_code,
			add_sample_FYP_code_length);
		adjust_time = add_sample_real_starttime - sample_starttime;
		if (adjust_time > 0)
			continue;

		mix1_starttime = connect.mix_after_sample(add_sample_real_starttime, add_sample_code_length);
		plan.mix(mix1_starttime, QB_FYP_use_holeNO, SampleNO, add_mix1_real_starttime, FYP_add_mix1_time,
			FYP_add_mix1_starttime, add_mix1_FYP_occupytime, add_mix1_code, add_mix1_code_length, add_mix1_FYP_code,
			add_mix1_FYP_code_length);
		adjust_time = add_mix1_real_starttime - mix1_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent2_starttime = connect.reagent_after_mix(FYP_add_mix1_starttime, add_mix1_FYP_code_length, FY_time1);
		plan.add_reagent(20, add_reagent2_starttime, QB_FYP_use_holeNO, R2_Location_NO, Reagent_Bin_NO, add_reagent2_real_starttime, FYP_add_reagent2_time,
			FYP_add_reagent2_starttime, addSJ2_FYP_occupytime, add_reagent2_code, add_reagent2_code_length, add_reagent2_FYP_code, add_reagent2_FYP_code_length);
		adjust_time = add_reagent2_real_starttime - add_reagent2_starttime;
		if (adjust_time > 0)
			continue;

		mix2_starttime = connect.mix_after_reagent(add_reagent2_real_starttime, add_reagent2_code_length);
		plan.mix(mix2_starttime, QB_FYP_use_holeNO, SampleNO, add_mix2_real_starttime, FYP_add_mix2_time,
			FYP_add_mix2_starttime, add_mix2_FYP_occupytime, add_mix2_code, add_mix2_code_length, add_mix2_FYP_code,
			add_mix2_FYP_code_length);
		adjust_time = add_mix2_real_starttime - mix2_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent1_starttime = connect.reagent_after_mix(FYP_add_mix2_starttime, add_mix2_FYP_code_length, FY_time2);
		plan.add_reagent(10, add_reagent1_starttime, QB_FYP_use_holeNO, R1_Location_NO, Reagent_Bin_NO, add_reagent1_real_starttime, FYP_add_reagent1_time,
			FYP_add_reagent1_starttime, addSJ1_FYP_occupytime, add_reagent1_code, add_reagent1_code_length, add_reagent1_FYP_code, add_reagent1_FYP_code_length);
		adjust_time = add_reagent1_real_starttime - add_reagent1_starttime;
		if (adjust_time > 0)
			continue;

		mix3_starttime = connect.mix_after_reagent(add_reagent1_real_starttime, add_reagent1_code_length);
		plan.mix(mix3_starttime, QB_FYP_use_holeNO, SampleNO, add_mix3_real_starttime, FYP_add_mix3_time,
			FYP_add_mix3_starttime, add_mix3_FYP_occupytime, add_mix3_code, add_mix3_code_length, add_mix3_FYP_code,
			add_mix3_FYP_code_length);
		adjust_time = add_mix3_real_starttime - mix3_starttime;
		if (adjust_time > 0)
			continue;

		FYP_out_time = connect.CFL_after_mix(FYP_add_mix3_starttime, add_mix3_FYP_code_length, FY_time3);
		plan.FYP2CFL(FYP_out_time, QB_FYP_use_holeNO, FYP2CFL_real_starttime, FYP2CFL_JZ_starttime, FYP2CFL_JZ_code, FYP2CFL_JZ_code_length,
			FYP2CFL_FYP_starttime, FYP2CFL_FYP_code, FYP2CFL_FYP_code_length, CFL_hole_NO, FYP2CFL_CFL_arrive_time);
		adjust_time = FYP2CFL_real_starttime - FYP_out_time;
		if (adjust_time > 0)
			continue;

		CFL2ZDQ_starttime = connect.ZDQ_after_CFL(FYP2CFL_CFL_arrive_time);
		plan.CFL2ZDQ(CFL2ZDQ_starttime, CFL2ZDQ_real_starttime, CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code,
			CFL2ZDQ_JZ_code_length, CFL2ZDQ_ZDQ_arrive_time, CFL2ZDQ_hole_NO);
		adjust_time = CFL2ZDQ_real_starttime - CFL2ZDQ_starttime;
		if (adjust_time > 13)
			continue;

		ZDQ2GJC_starttime = connect.GJC_after_ZDG(CFL2ZDQ_ZDQ_arrive_time);//������������148s
		plan.ZDQ2GJC(ZDQ2GJC_starttime, ZDQ2GJC_real_starttime, CFL2ZDQ_hole_NO, ZDQ2GJC_JZ_starttime,
			ZDQ2GJC_JZ_code, ZDQ2GJC_JZ_code_length, ZDQ2GJC_GJC_arrive_time);
		adjust_time = ZDQ2GJC_real_starttime - ZDQ2GJC_starttime;
		if (adjust_time > 0)
			continue;
		unfinished = false;
	}

	//��Ӳ�������
	//ȡ������
	add_code.add_JZ_move_code(QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code);
	add_code.add_FYP_move_code(QB_FYP_starttime, QB_FYP_code_length, QB_FYP_code);
	//�Լ�3����
	add_code.add_SJ_code(add_reagent3_real_starttime, add_reagent3_code_length, add_reagent3_code);
	add_code.add_FYP_move_code(FYP_add_reagent3_starttime, add_reagent3_FYP_code_length, add_reagent3_FYP_code);
	//��������
	add_code.add_sample_code(add_sample_real_starttime, add_sample_code_length, add_sample_code);
	add_code.add_FYP_move_code(FYP_add_sample_starttime, add_sample_FYP_code_length, add_sample_FYP_code);
	//�ӽ���1����
	add_code.add_mix_code(add_mix1_real_starttime, add_mix1_code_length, add_mix1_code);
	add_code.add_FYP_move_code(FYP_add_mix1_starttime, add_mix1_FYP_code_length, add_mix1_FYP_code);
	//�Լ�2����
	add_code.add_SJ_code(add_reagent2_real_starttime, add_reagent2_code_length, add_reagent2_code);
	add_code.add_FYP_move_code(FYP_add_reagent2_starttime, add_reagent2_FYP_code_length, add_reagent2_FYP_code);
	//�ӽ���2����
	add_code.add_mix_code(add_mix2_real_starttime, add_mix2_code_length, add_mix2_code);
	add_code.add_FYP_move_code(FYP_add_mix2_starttime, add_mix2_FYP_code_length, add_mix2_FYP_code);
	//�Լ�1����
	add_code.add_SJ_code(add_reagent1_real_starttime, add_reagent1_code_length, add_reagent1_code);
	add_code.add_FYP_move_code(FYP_add_reagent1_starttime, add_reagent1_FYP_code_length, add_reagent1_FYP_code);
	//�ӽ���3����
	add_code.add_mix_code(add_mix3_real_starttime, add_mix3_code_length, add_mix3_code);
	add_code.add_FYP_move_code(FYP_add_mix3_starttime, add_mix3_FYP_code_length, add_mix3_FYP_code);
	//�����̵��ŷ������
	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime, FYP2CFL_JZ_code_length, FYP2CFL_JZ_code);
	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime, FYP2CFL_FYP_code_length, FYP2CFL_FYP_code);
	add_code.add_FYP_hole_occupy(QB_FYP_use_holeNO, FYP_putcup_time, FYP_out_time);//�����̿�ռ��
	//�ŷ��뵽��������
	add_code.add_JZ_move_code(CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code_length, CFL2ZDQ_JZ_code);
	add_code.add_CFL_hole_occupy(CFL_hole_NO, FYP2CFL_CFL_arrive_time, CFL2ZDQ_real_starttime);//�ŷ����ռ��
	//�������������
	add_code.add_JZ_move_code(ZDQ2GJC_JZ_starttime, ZDQ2GJC_JZ_code_length, ZDQ2GJC_JZ_code);
	add_code.add_ZDQ_hole_occupy(CFL2ZDQ_hole_NO, CFL2ZDQ_ZDQ_arrive_time, ZDQ2GJC_starttime);//������ռ��
	//������̴���
	int GJC_code_length = 0;
	int GJC_code[3][50] = { 0 };
	plan.gjc.createcode(36, mission_NO, GJC_code_length, GJC_code);
	int GJC_starttime = ZDQ2GJC_GJC_arrive_time;
	add_code.add_GJC_code(GJC_starttime - 1, GJC_code_length, GJC_code);
	add_code.add_GJC_hole_occupy(GJC_starttime - 1, GJC_starttime + 43);//�����ռ��
	//������
	add_code.add_ZDQ_motor_code();
	//�ŷ���ת��
	add_code.add_CFL_move_code(GJC_starttime + 1200, cfl_CFLcyclesteptime);
	
	totaltime = GJC_starttime + 1200;

	//��Ӵŷ���ע����Һ�������
	int length = 0;
	int zhushe1_time = 0;
	int paiye1_time = 0;
	int zhushe2_time = 0;
	int paiye2_time = 0;
	int diwu_time = 0;
	int CFLcode1[8][30] = { 0 };
	int CFLcode2[8][30] = { 0 };
	int CFLcode3[8][30] = { 0 };
	int CFLcode4[8][30] = { 0 };
	int CFLcode5[8][30] = { 0 };
	plan.cfl.CFLzhushe1codegenerate(CFLcode1, length);
	plan.cfl.CFLpaiye1codegenerate(CFLcode2, length);
	plan.cfl.CFLzhushe2codegenerate(CFLcode3, length);
	plan.cfl.CFLpaiye2codegenerate(CFLcode4, length);
	plan.cfl.CFLdiwucodegenerate(CFLcode5, length);
	//��һȦ
	zhushe1_time = (FYP2CFL_CFL_arrive_time / 17 + 2) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time / 17 + 5) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time / 17 + 6) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time / 17 + 9) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//�ڶ�Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time / 17 + 2 + 12) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time / 17 + 5 + 12) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time / 17 + 6 + 12) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time / 17 + 9 + 12) * 17 + 1;
	diwu_time = (FYP2CFL_CFL_arrive_time / 17 + 10 + 12) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	add_code.add_CFL_operation_code(diwu_time, length, CFLcode5);
}

//�Լ�3�����������衢����������ϴ�����Լ�1�����衢�ٷ�������ϴ���Լ�2����������ϴ���ӵ���𵴡����
void PRO::HBeAb(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_Location_NO, int R2_Location_NO, int R3_Location_NO, int qb_starttime, int FY_time1, int FY_time2, int FY_time3)
{
	//���Ʊ���
	bool unfinished = true;
	int adjust_time = 0;

	//ȡ����ر���
	int BJ_is_empty = 0;
	int BJ_need_changerow = 0;
	int BJ_changerow_time = 0;
	int BJ_cupNO = 0;
	int QB_JZ_starttime = 0;
	int QB_JZ_code_length = 0;
	int QB_JZ_code[3][100] = { 0 };
	int QB_time = 0;
	int FYP_putcup_time = 0;
	int QB_FYP_starttime = 0;
	int QB_FYP_use_holeNO = 0;
	int QB_FYP_code[50] = { 0 };
	int QB_FYP_code_length = 0;
	int QB_finished_time = 0;
	int BJ_NO = 0;

	//���Լ�3��ر���
	int add_reagent3_starttime = 0;
	int add_reagent3_real_starttime = 0;
	int FYP_add_reagent3_time = 0;
	int FYP_add_reagent3_starttime = 0;
	int addSJ3_FYP_occupytime = 0;
	int add_reagent3_code[8][100] = { 0 };
	int add_reagent3_code_length = 0;
	int add_reagent3_FYP_code[50] = { 0 };
	int add_reagent3_FYP_code_length = 0;

	//��������ر���
	int sample_starttime = 0;
	int add_sample_real_starttime = 0;
	int FYP_add_sample_time = 0;
	int FYP_add_sample_starttime = 0;
	int add_sample_FYP_occupytime = 0;
	int add_sample_code[8][100] = { 0 };
	int add_sample_code_length = 0;
	int add_sample_FYP_code[50] = { 0 };
	int add_sample_FYP_code_length = 0;

	//����1��ر���
	int mix1_starttime = 0;
	int add_mix1_real_starttime = 0;
	int FYP_add_mix1_time = 0;
	int FYP_add_mix1_starttime = 0;
	int add_mix1_FYP_occupytime = 0;
	int add_mix1_code[8][100] = { 0 };
	int add_mix1_code_length = 0;
	int add_mix1_FYP_code[50] = { 0 };
	int add_mix1_FYP_code_length = 0;

	//���Լ�1��ر���
	int add_reagent1_starttime = 0;
	int add_reagent1_real_starttime = 0;
	int FYP_add_reagent1_time = 0;
	int FYP_add_reagent1_starttime = 0;
	int addSJ1_FYP_occupytime = 0;
	int add_reagent1_code[8][100] = { 0 };
	int add_reagent1_code_length = 0;
	int add_reagent1_FYP_code[50] = { 0 };
	int add_reagent1_FYP_code_length = 0;

	//����2��ر���
	int mix2_starttime = 0;
	int add_mix2_real_starttime = 0;
	int FYP_add_mix2_time = 0;
	int FYP_add_mix2_starttime = 0;
	int add_mix2_FYP_occupytime = 0;
	int add_mix2_code[8][100] = { 0 };
	int add_mix2_code_length = 0;
	int add_mix2_FYP_code[50] = { 0 };
	int add_mix2_FYP_code_length = 0;

	//��һ�ν��ŷ�����ر���
	int FYP_out_time1 = 0;
	int FYP2CFL_real_starttime1 = 0;
	int FYP2CFL_JZ_starttime1 = 0;
	int FYP2CFL_JZ_code1[3][100]={ 0 };
	int FYP2CFL_JZ_code_length1 = 0;
	int FYP2CFL_FYP_starttime1 = 0;
	int FYP2CFL_FYP_code1[50] = { 0 };
	int FYP2CFL_FYP_code_length1 = 0;
	int CFL_hole_NO1 = 0;
	int FYP2CFL_CFL_arrive_time1 = 0;

	//�ŷ��뵽��������ر���
	int CFL2FYP_starttime = 0;
	int CFL2FYP_real_starttime = 0;
	int CFL2FYP_JZ_starttime = 0;
	int CFL2FYP_JZ_code[3][100] = { 0 };
	int CFL2FYP_JZ_code_length = 0;
	int CFL2FYP_FYP_arrive_time = 0;
	int CFL2FYP_FYP_holeNO = 0;
	int CFL2FYP_FYP_starttime = 0;
	int CFL2FYP_FYP_code[50] = { 0 };
	int CFL2FYP_FYP_code_length = 0;

	//���Լ�2��ر���
	int add_reagent2_starttime = 0;
	int add_reagent2_real_starttime = 0;
	int FYP_add_reagent2_time = 0;
	int FYP_add_reagent2_starttime = 0;
	int addSJ2_FYP_occupytime = 0;
	int add_reagent2_code[8][100] = { 0 };
	int add_reagent2_code_length = 0;
	int add_reagent2_FYP_code[50] = { 0 };
	int add_reagent2_FYP_code_length = 0;

	//����3��ر���
	int mix3_starttime = 0;
	int add_mix3_real_starttime = 0;
	int FYP_add_mix3_time = 0;
	int FYP_add_mix3_starttime = 0;
	int add_mix3_FYP_occupytime = 0;
	int add_mix3_code[8][100] = { 0 };
	int add_mix3_code_length = 0;
	int add_mix3_FYP_code[50] = { 0 };
	int add_mix3_FYP_code_length = 0;

	//���ŷ�����ر���
	int FYP_out_time2 = 0;
	int FYP2CFL_real_starttime2 = 0;
	int FYP2CFL_JZ_starttime2 = 0;
	int FYP2CFL_JZ_code2[3][100]={ 0 };
	int FYP2CFL_JZ_code_length2 = 0;
	int FYP2CFL_FYP_starttime2 = 0;
	int FYP2CFL_FYP_code2[50] = { 0 };
	int FYP2CFL_FYP_code_length2 = 0;
	int CFL_hole_NO2 = 0;
	int FYP2CFL_CFL_arrive_time2 = 0;

	//�ŷ����������ر���
	int CFL2ZDQ_starttime = 0;
	int CFL2ZDQ_real_starttime = 0;
	int CFL2ZDQ_JZ_starttime = 0;
	int CFL2ZDQ_JZ_code[3][100] = { 0 };
	int CFL2ZDQ_JZ_code_length = 0;
	int CFL2ZDQ_ZDQ_arrive_time = 0;
	int CFL2ZDQ_hole_NO = 0;

	//������������ر���
	int ZDQ2GJC_starttime = 0;
	int ZDQ2GJC_real_starttime = 0;
	int ZDQ2GJC_JZ_starttime = 0;
	int ZDQ2GJC_JZ_code[3][100] = { 0 };
	int ZDQ2GJC_JZ_code_length = 0;
	int ZDQ2GJC_GJC_arrive_time = 0;

	plan.qb(qb_starttime, BJ_is_empty, BJ_need_changerow, BJ_changerow_time, BJ_cupNO, QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code,
		QB_time, FYP_putcup_time, QB_FYP_starttime, QB_FYP_use_holeNO, QB_FYP_code, QB_FYP_code_length, QB_finished_time,BJ_NO);
	plan.set_BJ_state(GBJ_Content);
	//������ز���
	if (BJ_NO == 0)
	{
		//���뻻����������
		int code[10] = { 0 };
		int CodeLength1;
		CodeLength1 = plan.bj.BJmovnextrow(code);
		int time = QB_JZ_starttime + jz_downtime + jz_opentime + jz_uptime + jz_movetime;
		for (int j = 0; j < CodeLength1; j++)
			xy[8][j + time] = code[j];
	}
	add_reagent3_starttime = connect.reagent_after_qb(QB_finished_time);

	while (unfinished)
	{
		add_reagent3_starttime += adjust_time;

		plan.add_reagent(10, add_reagent3_starttime, QB_FYP_use_holeNO, R3_Location_NO, Reagent_Bin_NO, add_reagent3_real_starttime,
			FYP_add_reagent3_time, FYP_add_reagent3_starttime, addSJ3_FYP_occupytime, add_reagent3_code, add_reagent3_code_length,
			add_reagent3_FYP_code, add_reagent3_FYP_code_length);
		adjust_time = add_reagent3_real_starttime - add_reagent3_starttime;
		if (adjust_time > 0)
			continue;

		sample_starttime = connect.sample_after_reagent(add_reagent3_real_starttime, add_reagent3_code_length);
		plan.add_sample(10, sample_starttime, QB_FYP_use_holeNO, SampleNO, add_sample_real_starttime, FYP_add_sample_time,
			FYP_add_sample_starttime, add_sample_FYP_occupytime, add_sample_code, add_sample_code_length, add_sample_FYP_code,
			add_sample_FYP_code_length);
		adjust_time = add_sample_real_starttime - sample_starttime;
		if (adjust_time > 0)
			continue;

		mix1_starttime = connect.mix_after_sample(add_sample_real_starttime, add_sample_code_length);
		plan.mix(mix1_starttime, QB_FYP_use_holeNO, SampleNO, add_mix1_real_starttime, FYP_add_mix1_time,
			FYP_add_mix1_starttime, add_mix1_FYP_occupytime, add_mix1_code, add_mix1_code_length, add_mix1_FYP_code,
			add_mix1_FYP_code_length);
		adjust_time = add_mix1_real_starttime - mix1_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent1_starttime = connect.reagent_after_mix(FYP_add_mix1_starttime, add_mix1_FYP_code_length, FY_time1);
		plan.add_reagent(10, add_reagent1_starttime, QB_FYP_use_holeNO, R1_Location_NO, Reagent_Bin_NO, add_reagent1_real_starttime,
			FYP_add_reagent1_time, FYP_add_reagent1_starttime, addSJ1_FYP_occupytime, add_reagent1_code, add_reagent1_code_length,
			add_reagent1_FYP_code, add_reagent1_FYP_code_length);
		adjust_time = add_reagent1_real_starttime - add_reagent1_starttime;
		if (adjust_time > 0)
			continue;

		mix2_starttime = connect.mix_after_reagent(add_reagent1_real_starttime, add_reagent1_code_length);
		plan.mix(mix2_starttime, QB_FYP_use_holeNO, SampleNO, add_mix2_real_starttime, FYP_add_mix2_time,
			FYP_add_mix2_starttime, add_mix2_FYP_occupytime, add_mix2_code, add_mix2_code_length, add_mix2_FYP_code,
			add_mix2_FYP_code_length);
		adjust_time = add_mix2_real_starttime - mix2_starttime;
		if (adjust_time > 0)
			continue;

		FYP_out_time1 = connect.CFL_after_mix(FYP_add_mix2_starttime, add_mix2_FYP_code_length, FY_time2);
		plan.FYP2CFL(FYP_out_time1, QB_FYP_use_holeNO, FYP2CFL_real_starttime1, FYP2CFL_JZ_starttime1, FYP2CFL_JZ_code1, FYP2CFL_JZ_code_length1,
			FYP2CFL_FYP_starttime1, FYP2CFL_FYP_code1, FYP2CFL_FYP_code_length1, CFL_hole_NO1, FYP2CFL_CFL_arrive_time1);
		adjust_time = FYP2CFL_real_starttime1 - FYP_out_time1;
		if (adjust_time > 0)
			continue;

		CFL2FYP_starttime = connect.FYP_after_CFL(FYP2CFL_CFL_arrive_time1);
		plan.CFL2FYP(CFL2FYP_starttime, CFL2FYP_real_starttime, CFL2FYP_JZ_starttime, CFL2FYP_JZ_code, CFL2FYP_JZ_code_length,
			CFL2FYP_FYP_arrive_time, CFL2FYP_FYP_holeNO, CFL2FYP_FYP_starttime, CFL2FYP_FYP_code, CFL2FYP_FYP_code_length);
		adjust_time = CFL2FYP_real_starttime - CFL2FYP_starttime;
		if (adjust_time > 13)
			continue;

		add_reagent2_starttime = connect.reagent_after_FYP(CFL2FYP_FYP_starttime, CFL2FYP_FYP_code_length);
		plan.add_reagent(20, add_reagent2_starttime, CFL2FYP_FYP_holeNO, R2_Location_NO, Reagent_Bin_NO, add_reagent2_real_starttime, FYP_add_reagent2_time,
			FYP_add_reagent2_starttime, addSJ2_FYP_occupytime, add_reagent2_code, add_reagent2_code_length, add_reagent2_FYP_code, add_reagent2_FYP_code_length);
		adjust_time = add_reagent2_real_starttime - add_reagent2_starttime;
		if (adjust_time > 0)
			continue;

		mix3_starttime = connect.mix_after_reagent(add_reagent2_real_starttime, add_reagent2_code_length);
		plan.mix(mix3_starttime, CFL2FYP_FYP_holeNO, SampleNO, add_mix3_real_starttime, FYP_add_mix3_time,
			FYP_add_mix3_starttime, add_mix3_FYP_occupytime, add_mix3_code, add_mix3_code_length, add_mix3_FYP_code,
			add_mix3_FYP_code_length);
		adjust_time = add_mix3_real_starttime - mix3_starttime;
		if (adjust_time > 0)
			continue;

		FYP_out_time2 = connect.CFL_after_mix(FYP_add_mix3_starttime, add_mix3_FYP_code_length, FY_time3);
		plan.FYP2CFL(FYP_out_time2, CFL2FYP_FYP_holeNO, FYP2CFL_real_starttime2, FYP2CFL_JZ_starttime2, FYP2CFL_JZ_code2, FYP2CFL_JZ_code_length2,
			FYP2CFL_FYP_starttime2, FYP2CFL_FYP_code2, FYP2CFL_FYP_code_length2, CFL_hole_NO2, FYP2CFL_CFL_arrive_time2);
		adjust_time = FYP2CFL_real_starttime2 - FYP_out_time2;
		if (adjust_time > 0)
			continue;

		CFL2ZDQ_starttime = connect.ZDQ_after_CFL(FYP2CFL_CFL_arrive_time2);
		plan.CFL2ZDQ(CFL2ZDQ_starttime, CFL2ZDQ_real_starttime, CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code,
			CFL2ZDQ_JZ_code_length, CFL2ZDQ_ZDQ_arrive_time, CFL2ZDQ_hole_NO);
		adjust_time = CFL2ZDQ_real_starttime - CFL2ZDQ_starttime;
		if (adjust_time > 13)
			continue;

		ZDQ2GJC_starttime = connect.GJC_after_ZDG(CFL2ZDQ_ZDQ_arrive_time);
		plan.ZDQ2GJC(ZDQ2GJC_starttime, ZDQ2GJC_real_starttime, CFL2ZDQ_hole_NO, ZDQ2GJC_JZ_starttime,
			ZDQ2GJC_JZ_code, ZDQ2GJC_JZ_code_length, ZDQ2GJC_GJC_arrive_time);
		adjust_time = ZDQ2GJC_real_starttime - ZDQ2GJC_starttime;
		if (adjust_time > 0)
			continue;

		unfinished = false;
	}

	//��Ӳ������뼰��ռ�ô���
	//ȡ������
	add_code.add_JZ_move_code(QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code);
	add_code.add_FYP_move_code(QB_FYP_starttime, QB_FYP_code_length, QB_FYP_code);
	//���Լ�3����
	add_code.add_SJ_code(add_reagent3_real_starttime, add_reagent3_code_length, add_reagent3_code);
	add_code.add_FYP_move_code(FYP_add_reagent3_starttime, add_reagent3_FYP_code_length, add_reagent3_FYP_code);
	//����������
	add_code.add_sample_code(add_sample_real_starttime, add_sample_code_length, add_sample_code);
	add_code.add_FYP_move_code(FYP_add_sample_starttime, add_sample_FYP_code_length, add_sample_FYP_code);
	//����1����
	add_code.add_mix_code(add_mix1_real_starttime, add_mix1_code_length, add_mix1_code);
	add_code.add_FYP_move_code(FYP_add_mix1_starttime, add_mix1_FYP_code_length, add_mix1_FYP_code);
	//���Լ�1����
	add_code.add_SJ_code(add_reagent1_real_starttime, add_reagent1_code_length, add_reagent1_code);
	add_code.add_FYP_move_code(FYP_add_reagent1_starttime, add_reagent1_FYP_code_length, add_reagent1_FYP_code);
	//����2����
	add_code.add_mix_code(add_mix2_real_starttime, add_mix2_code_length, add_mix2_code);
	add_code.add_FYP_move_code(FYP_add_mix2_starttime, add_mix2_FYP_code_length, add_mix2_FYP_code);
	//�����̵��ŷ������
	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime1, FYP2CFL_JZ_code_length1, FYP2CFL_JZ_code1);
	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime1, FYP2CFL_FYP_code_length1, FYP2CFL_FYP_code1);
	add_code.add_FYP_hole_occupy(QB_FYP_use_holeNO, FYP_putcup_time, FYP_out_time1);//�����̿׵�һ��ռ��
	//�ŷ��뵽�����̴���
	add_code.add_JZ_move_code(CFL2FYP_JZ_starttime, CFL2FYP_JZ_code_length, CFL2FYP_JZ_code);
	add_code.add_FYP_move_code(CFL2FYP_FYP_starttime, CFL2FYP_FYP_code_length, CFL2FYP_FYP_code);
	add_code.add_CFL_hole_occupy(CFL_hole_NO1, FYP2CFL_CFL_arrive_time1, CFL2FYP_starttime);//�ŷ���׵�һ��ռ��
	//���Լ�2����
	add_code.add_SJ_code(add_reagent2_real_starttime, add_reagent2_code_length, add_reagent2_code);
	add_code.add_FYP_move_code(FYP_add_reagent2_starttime, add_reagent2_FYP_code_length, add_reagent2_FYP_code);
	//����3����
	add_code.add_mix_code(add_mix3_real_starttime, add_mix3_code_length, add_mix3_code);
	add_code.add_FYP_move_code(FYP_add_mix3_starttime, add_mix3_FYP_code_length, add_mix3_FYP_code);
	//�����̵��ŷ���ڶ��δ���
	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime2, FYP2CFL_JZ_code_length2, FYP2CFL_JZ_code2);
	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime2, FYP2CFL_FYP_code_length2, FYP2CFL_FYP_code2);
	add_code.add_FYP_hole_occupy(CFL2FYP_FYP_holeNO, CFL2FYP_FYP_arrive_time, FYP_out_time2);//�����̿׵ڶ���ռ��
	//�ŷ��뵽��������
	add_code.add_JZ_move_code(CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code_length, CFL2ZDQ_JZ_code);
	add_code.add_CFL_hole_occupy(CFL_hole_NO2, FYP2CFL_CFL_arrive_time2, CFL2ZDQ_starttime);//�ŷ���׵ڶ���ռ��
	//�������������
	add_code.add_JZ_move_code(ZDQ2GJC_JZ_starttime, ZDQ2GJC_JZ_code_length, ZDQ2GJC_JZ_code);
	add_code.add_ZDQ_hole_occupy(CFL2ZDQ_hole_NO, CFL2ZDQ_ZDQ_arrive_time, ZDQ2GJC_starttime);//������ռ��
	//���������ӹ���
	int GJC_code_length = 0;
	int GJC_code[3][50] = { 0 };
	plan.gjc.createcode(36, mission_NO, GJC_code_length, GJC_code);
	int GJC_starttime = ZDQ2GJC_GJC_arrive_time;
	add_code.add_GJC_code(GJC_starttime - 1, GJC_code_length, GJC_code);
	add_code.add_GJC_hole_occupy(GJC_starttime - 1, GJC_starttime + 43);//�����ռ��
	//������
	add_code.add_ZDQ_motor_code();
	//�ŷ���ת��
	add_code.add_CFL_move_code(GJC_starttime + 1200, cfl_CFLcyclesteptime);
	
	totaltime = GJC_starttime + 1200;

	//��Ӵŷ���ע����Һ�������
	int length = 0;
	int zhushe1_time = 0;
	int paiye1_time = 0;
	int zhushe2_time = 0;
	int paiye2_time = 0;
	int diwu_time = 0;
	int CFLcode1[8][30] = { 0 };
	int CFLcode2[8][30] = { 0 };
	int CFLcode3[8][30] = { 0 };
	int CFLcode4[8][30] = { 0 };
	int CFLcode5[8][30] = { 0 };
	plan.cfl.CFLzhushe1codegenerate(CFLcode1, length);
	plan.cfl.CFLpaiye1codegenerate(CFLcode2, length);
	plan.cfl.CFLzhushe2codegenerate(CFLcode3, length);
	plan.cfl.CFLpaiye2codegenerate(CFLcode4, length);
	plan.cfl.CFLdiwucodegenerate(CFLcode5, length);
	//��һȦ
	zhushe1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 2) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 5) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 6) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 9) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//�ڶ�Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 2 + 12) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 5 + 12) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 6 + 12) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 9 + 12) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//����Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 2) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 5) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 6) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 9) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//����Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 2 + 12) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 5 + 12) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 6 + 12) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 9 + 12) * 17 + 1;
	diwu_time = (FYP2CFL_CFL_arrive_time2 / 17 + 10 + 12) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	add_code.add_CFL_operation_code(diwu_time, length, CFLcode5);

}

//�������Լ�4���Լ�5������1���������Լ�3������2���������Լ�2���Լ�1������3����������ϴ���ӵ���𵴡����
void PRO::VD(int mission_NO, int SampleNO, int Reagent_Bin_NO, int Second_Reagent_Bin_NO, int R1_Location_NO, int R2_Location_NO, int R3_Location_NO, int R4_Location_NO, int R5_Location_NO, int qb_starttime, int FY_time1, int FY_time2, int FY_time3)
{
	//���Ʊ���
	bool unfinished = true;
	int adjust_time = 0;

	//ȡ����ر���
	int BJ_is_empty = 0;
	int BJ_need_changerow = 0;
	int BJ_changerow_time = 0;
	int BJ_cupNO = 0;
	int QB_JZ_starttime = 0;
	int QB_JZ_code_length = 0;
	int QB_JZ_code[3][100] = { 0 };
	int QB_time = 0;
	int FYP_putcup_time = 0;
	int QB_FYP_starttime = 0;
	int QB_FYP_use_holeNO = 0;
	int QB_FYP_code[50] = { 0 };
	int QB_FYP_code_length = 0;
	int QB_finished_time = 0;
	int BJ_NO = 0;

	//��������ر���
	int sample_starttime = 0;
	int add_sample_real_starttime = 0;
	int FYP_add_sample_time = 0;
	int FYP_add_sample_starttime = 0;
	int add_sample_FYP_occupytime = 0;
	int add_sample_code[8][100] = { 0 };
	int add_sample_code_length = 0;
	int add_sample_FYP_code[50] = { 0 };
	int add_sample_FYP_code_length = 0;

	//���Լ�4��ر���
	int add_reagent4_starttime = 0;
	int add_reagent4_real_starttime = 0;
	int FYP_add_reagent4_time = 0;
	int FYP_add_reagent4_starttime = 0;
	int addSJ4_FYP_occupytime = 0;
	int add_reagent4_code[8][100] = { 0 };
	int add_reagent4_code_length = 0;
	int add_reagent4_FYP_code[50] = { 0 };
	int add_reagent4_FYP_code_length = 0;

	//���Լ�5��ر���
	int add_reagent5_starttime = 0;
	int add_reagent5_real_starttime = 0;
	int FYP_add_reagent5_time = 0;
	int FYP_add_reagent5_starttime = 0;
	int addSJ5_FYP_occupytime = 0;
	int add_reagent5_code[8][100] = { 0 };
	int add_reagent5_code_length = 0;
	int add_reagent5_FYP_code[50] = { 0 };
	int add_reagent5_FYP_code_length = 0;

	//����1��ر���
	int mix1_starttime = 0;
	int add_mix1_real_starttime = 0;
	int FYP_add_mix1_time = 0;
	int FYP_add_mix1_starttime = 0;
	int add_mix1_FYP_occupytime = 0;
	int add_mix1_code[8][100] = { 0 };
	int add_mix1_code_length = 0;
	int add_mix1_FYP_code[50] = { 0 };
	int add_mix1_FYP_code_length = 0;

	//���Լ�3��ر���
	int add_reagent3_starttime = 0;
	int add_reagent3_real_starttime = 0;
	int FYP_add_reagent3_time = 0;
	int FYP_add_reagent3_starttime = 0;
	int addSJ3_FYP_occupytime = 0;
	int add_reagent3_code[8][100] = { 0 };
	int add_reagent3_code_length = 0;
	int add_reagent3_FYP_code[50] = { 0 };
	int add_reagent3_FYP_code_length = 0;

	//������ر���
	int mix2_starttime = 0;
	int add_mix2_real_starttime = 0;
	int FYP_add_mix2_time = 0;
	int FYP_add_mix2_starttime = 0;
	int add_mix2_FYP_occupytime = 0;
	int add_mix2_code[8][100] = { 0 };
	int add_mix2_code_length = 0;
	int add_mix2_FYP_code[50] = { 0 };
	int add_mix2_FYP_code_length = 0;

	//���Լ�2��ر���
	int add_reagent2_starttime = 0;
	int add_reagent2_real_starttime = 0;
	int FYP_add_reagent2_time = 0;
	int FYP_add_reagent2_starttime = 0;
	int addSJ2_FYP_occupytime = 0;
	int add_reagent2_code[8][100] = { 0 };
	int add_reagent2_code_length = 0;
	int add_reagent2_FYP_code[50] = { 0 };
	int add_reagent2_FYP_code_length = 0;

	//���Լ�1��ر���
	int add_reagent1_starttime = 0;
	int add_reagent1_real_starttime = 0;
	int FYP_add_reagent1_time = 0;
	int FYP_add_reagent1_starttime = 0;
	int addSJ1_FYP_occupytime = 0;
	int add_reagent1_code[8][100] = { 0 };
	int add_reagent1_code_length = 0;
	int add_reagent1_FYP_code[50] = { 0 };
	int add_reagent1_FYP_code_length = 0;

	//����3��ر���
	int mix3_starttime = 0;
	int add_mix3_real_starttime = 0;
	int FYP_add_mix3_time = 0;
	int FYP_add_mix3_starttime = 0;
	int add_mix3_FYP_occupytime = 0;
	int add_mix3_code[8][100] = { 0 };
	int add_mix3_code_length = 0;
	int add_mix3_FYP_code[50] = { 0 };
	int add_mix3_FYP_code_length = 0;

	//���ŷ�����ر���
	int FYP_out_time = 0;
	int FYP2CFL_real_starttime = 0;
	int FYP2CFL_JZ_starttime = 0;
	int FYP2CFL_JZ_code[3][100]={ 0 };
	int FYP2CFL_JZ_code_length = 0;
	int FYP2CFL_FYP_starttime = 0;
	int FYP2CFL_FYP_code[50] = { 0 };
	int FYP2CFL_FYP_code_length = 0;
	int CFL_hole_NO = 0;
	int FYP2CFL_CFL_arrive_time = 0;

	//�ŷ����������ر���
	int CFL2ZDQ_starttime = 0;
	int CFL2ZDQ_real_starttime = 0;
	int CFL2ZDQ_JZ_starttime = 0;
	int CFL2ZDQ_JZ_code[3][100] = { 0 };
	int CFL2ZDQ_JZ_code_length = 0;
	int CFL2ZDQ_ZDQ_arrive_time = 0;
	int CFL2ZDQ_hole_NO = 0;

	//������������ر���
	int ZDQ2GJC_starttime = 0;
	int ZDQ2GJC_real_starttime = 0;
	int ZDQ2GJC_JZ_starttime = 0;
	int ZDQ2GJC_JZ_code[3][100] = { 0 };
	int ZDQ2GJC_JZ_code_length = 0;
	int ZDQ2GJC_GJC_arrive_time = 0;

	plan.qb(qb_starttime, BJ_is_empty, BJ_need_changerow, BJ_changerow_time, BJ_cupNO, QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code,
		QB_time, FYP_putcup_time, QB_FYP_starttime, QB_FYP_use_holeNO, QB_FYP_code, QB_FYP_code_length, QB_finished_time,BJ_NO);
	plan.set_BJ_state(GBJ_Content);
	//������ز���
	if (BJ_NO == 0)
	{
		//���뻻����������
		int code[10] = { 0 };
		int CodeLength1;
		CodeLength1 = plan.bj.BJmovnextrow(code);
		int time = QB_JZ_starttime + jz_downtime + jz_opentime + jz_uptime + jz_movetime;
		for (int j = 0; j < CodeLength1; j++)
			xy[8][j + time] = code[j];
	}
	sample_starttime = connect.sample_after_qb(QB_finished_time);

	while (unfinished)
	{
		sample_starttime += adjust_time;

		plan.add_sample(6, sample_starttime, QB_FYP_use_holeNO, SampleNO, add_sample_real_starttime, FYP_add_sample_time,
			FYP_add_sample_starttime, add_sample_FYP_occupytime, add_sample_code, add_sample_code_length, add_sample_FYP_code,
			add_sample_FYP_code_length);
		adjust_time = add_sample_real_starttime - sample_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent4_starttime = connect.reagent_after_sample(add_sample_real_starttime, add_sample_code_length);
		plan.add_reagent(10, add_reagent4_starttime, QB_FYP_use_holeNO, R4_Location_NO, Reagent_Bin_NO, add_reagent4_real_starttime,
			FYP_add_reagent4_time, FYP_add_reagent4_starttime, addSJ4_FYP_occupytime, add_reagent4_code, add_reagent4_code_length,
			add_reagent4_FYP_code, add_reagent4_FYP_code_length);
		adjust_time = add_reagent4_real_starttime - add_reagent4_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent5_starttime = connect.reagent_after_reagent(add_reagent4_real_starttime, add_reagent4_code_length);
		plan.add_reagent(10, add_reagent5_starttime, QB_FYP_use_holeNO, R5_Location_NO, Second_Reagent_Bin_NO, add_reagent5_real_starttime,
			FYP_add_reagent5_time, FYP_add_reagent5_starttime, addSJ5_FYP_occupytime, add_reagent5_code, add_reagent5_code_length,
			add_reagent5_FYP_code, add_reagent5_FYP_code_length);
		adjust_time = add_reagent5_real_starttime - add_reagent5_starttime;
		if (adjust_time > 0)
			continue;

		mix1_starttime = connect.mix_after_reagent(add_reagent5_real_starttime, add_reagent5_code_length);
		plan.mix(mix1_starttime, QB_FYP_use_holeNO, SampleNO, add_mix1_real_starttime, FYP_add_mix1_time,
			FYP_add_mix1_starttime, add_mix1_FYP_occupytime, add_mix1_code, add_mix1_code_length, add_mix1_FYP_code,
			add_mix1_FYP_code_length);
		adjust_time = add_mix1_real_starttime - mix1_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent3_starttime = connect.reagent_after_mix(FYP_add_mix1_starttime, add_mix1_FYP_code_length, FY_time1);
		plan.add_reagent(10, add_reagent3_starttime, QB_FYP_use_holeNO, R3_Location_NO, Reagent_Bin_NO, add_reagent3_real_starttime,
			FYP_add_reagent3_time, FYP_add_reagent3_starttime, addSJ3_FYP_occupytime, add_reagent3_code, add_reagent3_code_length,
			add_reagent3_FYP_code, add_reagent3_FYP_code_length);
		adjust_time = add_reagent3_real_starttime - add_reagent3_starttime;
		if (adjust_time > 0)
			continue;

		mix2_starttime = connect.mix_after_reagent(add_reagent3_real_starttime, add_reagent3_code_length);
		plan.mix(mix2_starttime, QB_FYP_use_holeNO, SampleNO, add_mix2_real_starttime, FYP_add_mix2_time,
			FYP_add_mix2_starttime, add_mix2_FYP_occupytime, add_mix2_code, add_mix2_code_length, add_mix2_FYP_code,
			add_mix2_FYP_code_length);
		adjust_time = add_mix2_real_starttime - mix2_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent2_starttime = connect.reagent_after_mix(FYP_add_mix2_starttime, add_mix2_FYP_code_length, FY_time2);
		plan.add_reagent(6, add_reagent2_starttime, QB_FYP_use_holeNO, R2_Location_NO, Reagent_Bin_NO, add_reagent2_real_starttime, FYP_add_reagent2_time,
			FYP_add_reagent2_starttime, addSJ2_FYP_occupytime, add_reagent2_code, add_reagent2_code_length, add_reagent2_FYP_code, add_reagent2_FYP_code_length);
		adjust_time = add_reagent2_real_starttime - add_reagent2_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent1_starttime = connect.reagent_after_reagent(add_reagent2_real_starttime, add_reagent2_code_length);
		plan.add_reagent(3, add_reagent1_starttime, QB_FYP_use_holeNO, R1_Location_NO, Reagent_Bin_NO, add_reagent1_real_starttime, FYP_add_reagent1_time,
			FYP_add_reagent1_starttime, addSJ1_FYP_occupytime, add_reagent1_code, add_reagent1_code_length, add_reagent1_FYP_code, add_reagent1_FYP_code_length);
		adjust_time = add_reagent1_real_starttime - add_reagent1_starttime;
		if (adjust_time > 0)
			continue;

		mix3_starttime = connect.mix_after_reagent(add_reagent1_real_starttime, add_reagent1_code_length);
		plan.mix(mix3_starttime, QB_FYP_use_holeNO, SampleNO, add_mix3_real_starttime, FYP_add_mix3_time,
			FYP_add_mix3_starttime, add_mix3_FYP_occupytime, add_mix3_code, add_mix3_code_length, add_mix3_FYP_code,
			add_mix3_FYP_code_length);
		adjust_time = add_mix3_real_starttime - mix3_starttime;
		if (adjust_time > 0)
			continue;

		FYP_out_time = connect.CFL_after_mix(FYP_add_mix3_starttime, add_mix3_FYP_code_length, FY_time3);
		plan.FYP2CFL(FYP_out_time, QB_FYP_use_holeNO, FYP2CFL_real_starttime, FYP2CFL_JZ_starttime, FYP2CFL_JZ_code, FYP2CFL_JZ_code_length,
			FYP2CFL_FYP_starttime, FYP2CFL_FYP_code, FYP2CFL_FYP_code_length, CFL_hole_NO, FYP2CFL_CFL_arrive_time);
		adjust_time = FYP2CFL_real_starttime - FYP_out_time;
		if (adjust_time > 0)
			continue;

		CFL2ZDQ_starttime = connect.ZDQ_after_CFL(FYP2CFL_CFL_arrive_time);
		plan.CFL2ZDQ(CFL2ZDQ_starttime, CFL2ZDQ_real_starttime, CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code,
			CFL2ZDQ_JZ_code_length, CFL2ZDQ_ZDQ_arrive_time, CFL2ZDQ_hole_NO);
		adjust_time = CFL2ZDQ_real_starttime - CFL2ZDQ_starttime;
		if (adjust_time > 13)
			continue;

		ZDQ2GJC_starttime = connect.GJC_after_ZDG(CFL2ZDQ_ZDQ_arrive_time);//������������148s
		plan.ZDQ2GJC(ZDQ2GJC_starttime, ZDQ2GJC_real_starttime, CFL2ZDQ_hole_NO, ZDQ2GJC_JZ_starttime,
			ZDQ2GJC_JZ_code, ZDQ2GJC_JZ_code_length, ZDQ2GJC_GJC_arrive_time);
		adjust_time = ZDQ2GJC_real_starttime - ZDQ2GJC_starttime;
		if (adjust_time > 0)
			continue;
		unfinished = false;
	}

	//��Ӳ�������
	//ȡ������
	add_code.add_JZ_move_code(QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code);
	add_code.add_FYP_move_code(QB_FYP_starttime, QB_FYP_code_length, QB_FYP_code);
	//��������
	add_code.add_sample_code(add_sample_real_starttime, add_sample_code_length, add_sample_code);
	add_code.add_FYP_move_code(FYP_add_sample_starttime, add_sample_FYP_code_length, add_sample_FYP_code);
	//�Լ�4����
	add_code.add_SJ_code(add_reagent4_real_starttime, add_reagent4_code_length, add_reagent4_code);
	add_code.add_FYP_move_code(FYP_add_reagent4_starttime, add_reagent4_FYP_code_length, add_reagent4_FYP_code);
	//�Լ�5����
	add_code.add_SJ_code(add_reagent5_real_starttime, add_reagent5_code_length, add_reagent5_code);
	add_code.add_FYP_move_code(FYP_add_reagent5_starttime, add_reagent5_FYP_code_length, add_reagent5_FYP_code);
	//�ӽ���1����
	add_code.add_mix_code(add_mix1_real_starttime, add_mix1_code_length, add_mix1_code);
	add_code.add_FYP_move_code(FYP_add_mix1_starttime, add_mix1_FYP_code_length, add_mix1_FYP_code);
	//�Լ�3����
	add_code.add_SJ_code(add_reagent3_real_starttime, add_reagent3_code_length, add_reagent3_code);
	add_code.add_FYP_move_code(FYP_add_reagent3_starttime, add_reagent3_FYP_code_length, add_reagent3_FYP_code);
	//�ӽ���2����
	add_code.add_mix_code(add_mix2_real_starttime, add_mix2_code_length, add_mix2_code);
	add_code.add_FYP_move_code(FYP_add_mix2_starttime, add_mix2_FYP_code_length, add_mix2_FYP_code);
	//�Լ�2����
	add_code.add_SJ_code(add_reagent2_real_starttime, add_reagent2_code_length, add_reagent2_code);
	add_code.add_FYP_move_code(FYP_add_reagent2_starttime, add_reagent2_FYP_code_length, add_reagent2_FYP_code);
	//�Լ�1����
	add_code.add_SJ_code(add_reagent1_real_starttime, add_reagent1_code_length, add_reagent1_code);
	add_code.add_FYP_move_code(FYP_add_reagent1_starttime, add_reagent1_FYP_code_length, add_reagent1_FYP_code);
	//�ӽ���3����
	add_code.add_mix_code(add_mix3_real_starttime, add_mix3_code_length, add_mix3_code);
	add_code.add_FYP_move_code(FYP_add_mix3_starttime, add_mix3_FYP_code_length, add_mix3_FYP_code);
	//�����̵��ŷ������
	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime, FYP2CFL_JZ_code_length, FYP2CFL_JZ_code);
	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime, FYP2CFL_FYP_code_length, FYP2CFL_FYP_code);
	add_code.add_FYP_hole_occupy(QB_FYP_use_holeNO, FYP_putcup_time, FYP_out_time);//�����̿�ռ��
	//�ŷ��뵽��������
	add_code.add_JZ_move_code(CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code_length, CFL2ZDQ_JZ_code);
	add_code.add_CFL_hole_occupy(CFL_hole_NO, FYP2CFL_CFL_arrive_time, CFL2ZDQ_real_starttime);//�ŷ����ռ��
	//�������������
	add_code.add_JZ_move_code(ZDQ2GJC_JZ_starttime, ZDQ2GJC_JZ_code_length, ZDQ2GJC_JZ_code);
	add_code.add_ZDQ_hole_occupy(CFL2ZDQ_hole_NO, CFL2ZDQ_ZDQ_arrive_time, ZDQ2GJC_starttime);//������ռ��
	//������̴���
	int GJC_code_length = 0;
	int GJC_code[3][50] = { 0 };
	plan.gjc.createcode(36, mission_NO, GJC_code_length, GJC_code);
	int GJC_starttime = ZDQ2GJC_GJC_arrive_time;
	add_code.add_GJC_code(GJC_starttime - 1, GJC_code_length, GJC_code);
	add_code.add_GJC_hole_occupy(GJC_starttime - 1, GJC_starttime + 43);//�����ռ��
	//������
	add_code.add_ZDQ_motor_code();
	//�ŷ���ת��
	add_code.add_CFL_move_code(GJC_starttime + 1200, cfl_CFLcyclesteptime);
	
	totaltime = GJC_starttime + 1200;

	//��Ӵŷ���ע����Һ�������
	int length = 0;
	int zhushe1_time = 0;
	int paiye1_time = 0;
	int zhushe2_time = 0;
	int paiye2_time = 0;
	int diwu_time = 0;
	int CFLcode1[8][30] = { 0 };
	int CFLcode2[8][30] = { 0 };
	int CFLcode3[8][30] = { 0 };
	int CFLcode4[8][30] = { 0 };
	int CFLcode5[8][30] = { 0 };
	plan.cfl.CFLzhushe1codegenerate(CFLcode1, length);
	plan.cfl.CFLpaiye1codegenerate(CFLcode2, length);
	plan.cfl.CFLzhushe2codegenerate(CFLcode3, length);
	plan.cfl.CFLpaiye2codegenerate(CFLcode4, length);
	plan.cfl.CFLdiwucodegenerate(CFLcode5, length);
	//��һȦ
	zhushe1_time = (FYP2CFL_CFL_arrive_time / 17 + 2) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time / 17 + 5) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time / 17 + 6) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time / 17 + 9) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//�ڶ�Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time / 17 + 2 + 12) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time / 17 + 5 + 12) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time / 17 + 6 + 12) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time / 17 + 9 + 12) * 17 + 1;
	diwu_time = (FYP2CFL_CFL_arrive_time / 17 + 10 + 12) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	add_code.add_CFL_operation_code(diwu_time, length, CFLcode5);
}

//ȡ�����Լ�1������������1����һ��FYP2CFL��CFL2FYP���Լ�2���Լ�4������2���ڶ���FYP2CFL����
void PRO::HIV(int mission_NO, int SampleNO, int Reagent_Bin_NO, int R1_location_NO, int R2_Location_NO, int R4_Location_NO, int qb_starttime, int FY_time1, int FY_time2)
{
	//���Ʊ���
	bool unfinished = true;
	int adjust_time = 0;

	//ȡ����ر���
	int BJ_is_empty = 0;
	int BJ_need_changerow = 0;
	int BJ_changerow_time = 0;
	int BJ_cupNO = 0;
	int QB_JZ_starttime = 0;
	int QB_JZ_code_length = 0;
	int QB_JZ_code[3][100] = { 0 };
	int QB_time = 0;
	int FYP_putcup_time = 0;
	int QB_FYP_starttime = 0;
	int QB_FYP_use_holeNO = 0;
	int QB_FYP_code[50] = { 0 };
	int QB_FYP_code_length = 0;
	int QB_finished_time = 0;
	int BJ_NO = 0;

	//���Լ�1��ر���
	int add_reagent1_starttime = 0;
	int add_reagent1_real_starttime = 0;
	int FYP_add_reagent1_time = 0;
	int FYP_add_reagent1_starttime = 0;
	int addSJ1_FYP_occupytime = 0;
	int add_reagent1_code[8][100] = { 0 };
	int add_reagent1_code_length = 0;
	int add_reagent1_FYP_code[50] = { 0 };
	int add_reagent1_FYP_code_length = 0;

	//��������ر���
	int sample_starttime = 0;
	int add_sample_real_starttime = 0;
	int FYP_add_sample_time = 0;
	int FYP_add_sample_starttime = 0;
	int add_sample_FYP_occupytime = 0;
	int add_sample_code[8][100] = { 0 };
	int add_sample_code_length = 0;
	int add_sample_FYP_code[50] = { 0 };
	int add_sample_FYP_code_length = 0;

	//����1��ر���
	int mix1_starttime = 0;
	int add_mix1_real_starttime = 0;
	int FYP_add_mix1_time = 0;
	int FYP_add_mix1_starttime = 0;
	int add_mix1_FYP_occupytime = 0;
	int add_mix1_code[8][100] = { 0 };
	int add_mix1_code_length = 0;
	int add_mix1_FYP_code[50] = { 0 };
	int add_mix1_FYP_code_length = 0;

	//��һ�ν��ŷ�����ر���
	int FYP_out_time1 = 0;
	int FYP2CFL_real_starttime1 = 0;
	int FYP2CFL_JZ_starttime1 = 0;
	int FYP2CFL_JZ_code1[3][100]={ 0 };
	int FYP2CFL_JZ_code_length1 = 0;
	int FYP2CFL_FYP_starttime1 = 0;
	int FYP2CFL_FYP_code1[50] = { 0 };
	int FYP2CFL_FYP_code_length1 = 0;
	int CFL_hole_NO1 = 0;
	int FYP2CFL_CFL_arrive_time1 = 0;

	//�ŷ��뵽��������ر���
	int CFL2FYP_starttime = 0;
	int CFL2FYP_real_starttime = 0;
	int CFL2FYP_JZ_starttime = 0;
	int CFL2FYP_JZ_code[3][100] = { 0 };
	int CFL2FYP_JZ_code_length = 0;
	int CFL2FYP_FYP_arrive_time = 0;
	int CFL2FYP_FYP_holeNO = 0;
	int CFL2FYP_FYP_starttime = 0;
	int CFL2FYP_FYP_code[50] = { 0 };
	int CFL2FYP_FYP_code_length = 0;

	//���Լ�2��ر���
	int add_reagent2_starttime = 0;
	int add_reagent2_real_starttime = 0;
	int FYP_add_reagent2_time = 0;
	int FYP_add_reagent2_starttime = 0;
	int addSJ2_FYP_occupytime = 0;
	int add_reagent2_code[8][100] = { 0 };
	int add_reagent2_code_length = 0;
	int add_reagent2_FYP_code[50] = { 0 };
	int add_reagent2_FYP_code_length = 0;

	//���Լ�4��ر���
	int add_reagent4_starttime = 0;
	int add_reagent4_real_starttime = 0;
	int FYP_add_reagent4_time = 0;
	int FYP_add_reagent4_starttime = 0;
	int addSJ4_FYP_occupytime = 0;
	int add_reagent4_code[8][100] = { 0 };
	int add_reagent4_code_length = 0;
	int add_reagent4_FYP_code[50] = { 0 };
	int add_reagent4_FYP_code_length = 0;

	//����2��ر���
	int mix2_starttime = 0;
	int add_mix2_real_starttime = 0;
	int FYP_add_mix2_time = 0;
	int FYP_add_mix2_starttime = 0;
	int add_mix2_FYP_occupytime = 0;
	int add_mix2_code[8][100] = { 0 };
	int add_mix2_code_length = 0;
	int add_mix2_FYP_code[50] = { 0 };
	int add_mix2_FYP_code_length = 0;

	//���ŷ�����ر���
	int FYP_out_time2 = 0;
	int FYP2CFL_real_starttime2 = 0;
	int FYP2CFL_JZ_starttime2 = 0;
	int FYP2CFL_JZ_code2[3][100]={ 0 };
	int FYP2CFL_JZ_code_length2 = 0;
	int FYP2CFL_FYP_starttime2 = 0;
	int FYP2CFL_FYP_code2[50] = { 0 };
	int FYP2CFL_FYP_code_length2 = 0;
	int CFL_hole_NO2 = 0;
	int FYP2CFL_CFL_arrive_time2 = 0;

	//�ŷ����������ر���
	int CFL2ZDQ_starttime = 0;
	int CFL2ZDQ_real_starttime = 0;
	int CFL2ZDQ_JZ_starttime = 0;
	int CFL2ZDQ_JZ_code[3][100] = { 0 };
	int CFL2ZDQ_JZ_code_length = 0;
	int CFL2ZDQ_ZDQ_arrive_time = 0;
	int CFL2ZDQ_hole_NO = 0;

	//������������ر���
	int ZDQ2GJC_starttime = 0;
	int ZDQ2GJC_real_starttime = 0;
	int ZDQ2GJC_JZ_starttime = 0;
	int ZDQ2GJC_JZ_code[3][100] = { 0 };
	int ZDQ2GJC_JZ_code_length = 0;
	int ZDQ2GJC_GJC_arrive_time = 0;

	plan.qb(qb_starttime, BJ_is_empty, BJ_need_changerow, BJ_changerow_time, BJ_cupNO, QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code,
		QB_time, FYP_putcup_time, QB_FYP_starttime, QB_FYP_use_holeNO, QB_FYP_code, QB_FYP_code_length, QB_finished_time,BJ_NO);
	plan.set_BJ_state(GBJ_Content);
	//������ز���
	if (BJ_NO == 0)
	{
		//���뻻����������
		int code[10] = { 0 };
		int CodeLength1;
		CodeLength1 = plan.bj.BJmovnextrow(code);
		int time = QB_JZ_starttime + jz_downtime + jz_opentime + jz_uptime + jz_movetime;
		for (int j = 0; j < CodeLength1; j++)
			xy[8][j + time] = code[j];
	}
	add_reagent1_starttime = connect.reagent_after_qb(QB_finished_time);

	while (unfinished)
	{
		add_reagent1_starttime += adjust_time;

		plan.add_reagent(10, add_reagent1_starttime, QB_FYP_use_holeNO, R1_location_NO, Reagent_Bin_NO, add_reagent1_real_starttime,
			FYP_add_reagent1_time, FYP_add_reagent1_starttime, addSJ1_FYP_occupytime, add_reagent1_code, add_reagent1_code_length,
			add_reagent1_FYP_code, add_reagent1_FYP_code_length);
		adjust_time = add_reagent1_real_starttime - add_reagent1_starttime;
		if (adjust_time > 0)
			continue;

		sample_starttime = connect.sample_after_reagent(add_reagent1_real_starttime, add_reagent1_code_length);
		plan.add_sample(10, sample_starttime, QB_FYP_use_holeNO, SampleNO, add_sample_real_starttime, FYP_add_sample_time,
			FYP_add_sample_starttime, add_sample_FYP_occupytime, add_sample_code, add_sample_code_length, add_sample_FYP_code,
			add_sample_FYP_code_length);
		adjust_time = add_sample_real_starttime - sample_starttime;
		if (adjust_time > 0)
			continue;

		mix1_starttime = connect.mix_after_sample(add_sample_real_starttime, add_sample_code_length);
		plan.mix(mix1_starttime, QB_FYP_use_holeNO, SampleNO, add_mix1_real_starttime, FYP_add_mix1_time,
			FYP_add_mix1_starttime, add_mix1_FYP_occupytime, add_mix1_code, add_mix1_code_length, add_mix1_FYP_code,
			add_mix1_FYP_code_length);
		adjust_time = add_mix1_real_starttime - mix1_starttime;
		if (adjust_time > 0)
			continue;

		FYP_out_time1 = connect.CFL_after_mix(FYP_add_mix1_starttime, add_mix1_FYP_code_length, FY_time1);
		plan.FYP2CFL(FYP_out_time1, QB_FYP_use_holeNO, FYP2CFL_real_starttime1, FYP2CFL_JZ_starttime1, FYP2CFL_JZ_code1, FYP2CFL_JZ_code_length1,
			FYP2CFL_FYP_starttime1, FYP2CFL_FYP_code1, FYP2CFL_FYP_code_length1, CFL_hole_NO1, FYP2CFL_CFL_arrive_time1);
		adjust_time = FYP2CFL_real_starttime1 - FYP_out_time1;
		if (adjust_time > 0)
			continue;

		CFL2FYP_starttime = connect.FYP_after_CFL(FYP2CFL_CFL_arrive_time1);
		plan.CFL2FYP(CFL2FYP_starttime, CFL2FYP_real_starttime, CFL2FYP_JZ_starttime, CFL2FYP_JZ_code, CFL2FYP_JZ_code_length,
			CFL2FYP_FYP_arrive_time, CFL2FYP_FYP_holeNO, CFL2FYP_FYP_starttime, CFL2FYP_FYP_code, CFL2FYP_FYP_code_length);
		adjust_time = CFL2FYP_real_starttime - CFL2FYP_starttime;
		if (adjust_time > 13)
			continue;

		add_reagent2_starttime = connect.reagent_after_FYP(CFL2FYP_FYP_starttime, CFL2FYP_FYP_code_length);
		plan.add_reagent(10, add_reagent2_starttime, CFL2FYP_FYP_holeNO, R2_Location_NO, Reagent_Bin_NO, add_reagent2_real_starttime, FYP_add_reagent2_time,
			FYP_add_reagent2_starttime, addSJ2_FYP_occupytime, add_reagent2_code, add_reagent2_code_length, add_reagent2_FYP_code, add_reagent2_FYP_code_length);
		adjust_time = add_reagent2_real_starttime - add_reagent2_starttime;
		if (adjust_time > 0)
			continue;

		add_reagent4_starttime = connect.reagent_after_reagent(add_reagent2_real_starttime, add_reagent2_code_length);
		plan.add_reagent(10, add_reagent4_starttime, CFL2FYP_FYP_holeNO, R4_Location_NO, Reagent_Bin_NO, add_reagent4_real_starttime, FYP_add_reagent4_time,
			FYP_add_reagent4_starttime, addSJ4_FYP_occupytime, add_reagent4_code, add_reagent4_code_length, add_reagent4_FYP_code, add_reagent4_FYP_code_length);
		adjust_time = add_reagent4_real_starttime - add_reagent4_starttime;
		if (adjust_time > 0)
			continue;

		mix2_starttime = connect.mix_after_reagent(add_reagent4_real_starttime, add_reagent4_code_length);
		plan.mix(mix2_starttime, CFL2FYP_FYP_holeNO, SampleNO, add_mix2_real_starttime, FYP_add_mix2_time,
			FYP_add_mix2_starttime, add_mix2_FYP_occupytime, add_mix2_code, add_mix2_code_length, add_mix2_FYP_code,
			add_mix2_FYP_code_length);
		adjust_time = add_mix2_real_starttime - mix2_starttime;
		if (adjust_time > 0)
			continue;

		FYP_out_time2 = connect.CFL_after_mix(FYP_add_mix2_starttime, add_mix2_FYP_code_length, FY_time2);
		plan.FYP2CFL(FYP_out_time2, CFL2FYP_FYP_holeNO, FYP2CFL_real_starttime2, FYP2CFL_JZ_starttime2, FYP2CFL_JZ_code2, FYP2CFL_JZ_code_length2,
			FYP2CFL_FYP_starttime2, FYP2CFL_FYP_code2, FYP2CFL_FYP_code_length2, CFL_hole_NO2, FYP2CFL_CFL_arrive_time2);
		adjust_time = FYP2CFL_real_starttime2 - FYP_out_time2;
		if (adjust_time > 0)
			continue;

		CFL2ZDQ_starttime = connect.ZDQ_after_CFL(FYP2CFL_CFL_arrive_time2);
		plan.CFL2ZDQ(CFL2ZDQ_starttime, CFL2ZDQ_real_starttime, CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code,
			CFL2ZDQ_JZ_code_length, CFL2ZDQ_ZDQ_arrive_time, CFL2ZDQ_hole_NO);
		adjust_time = CFL2ZDQ_real_starttime - CFL2ZDQ_starttime;
		if (adjust_time > 13)
			continue;

		ZDQ2GJC_starttime = connect.GJC_after_ZDG(CFL2ZDQ_ZDQ_arrive_time);
		plan.ZDQ2GJC(ZDQ2GJC_starttime, ZDQ2GJC_real_starttime, CFL2ZDQ_hole_NO, ZDQ2GJC_JZ_starttime,
			ZDQ2GJC_JZ_code, ZDQ2GJC_JZ_code_length, ZDQ2GJC_GJC_arrive_time);
		adjust_time = ZDQ2GJC_real_starttime - ZDQ2GJC_starttime;
		if (adjust_time > 0)
			continue;

		unfinished = false;
	}

	//��Ӳ������뼰��ռ�ô���
	//ȡ������
	add_code.add_JZ_move_code(QB_JZ_starttime, QB_JZ_code_length, QB_JZ_code);
	add_code.add_FYP_move_code(QB_FYP_starttime, QB_FYP_code_length, QB_FYP_code);
	//���Լ�1����
	add_code.add_SJ_code(add_reagent1_real_starttime, add_reagent1_code_length, add_reagent1_code);
	add_code.add_FYP_move_code(FYP_add_reagent1_starttime, add_reagent1_FYP_code_length, add_reagent1_FYP_code);
	//����������
	add_code.add_sample_code(add_sample_real_starttime, add_sample_code_length, add_sample_code);
	add_code.add_FYP_move_code(FYP_add_sample_starttime, add_sample_FYP_code_length, add_sample_FYP_code);
	//����1����
	add_code.add_mix_code(add_mix1_real_starttime, add_mix1_code_length, add_mix1_code);
	add_code.add_FYP_move_code(FYP_add_mix1_starttime, add_mix1_FYP_code_length, add_mix1_FYP_code);
	//�����̵��ŷ������
	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime1, FYP2CFL_JZ_code_length1, FYP2CFL_JZ_code1);
	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime1, FYP2CFL_FYP_code_length1, FYP2CFL_FYP_code1);
	add_code.add_FYP_hole_occupy(QB_FYP_use_holeNO, FYP_putcup_time, FYP_out_time1);//�����̿׵�һ��ռ��
																					//�ŷ��뵽�����̴���
	add_code.add_JZ_move_code(CFL2FYP_JZ_starttime, CFL2FYP_JZ_code_length, CFL2FYP_JZ_code);
	add_code.add_FYP_move_code(CFL2FYP_FYP_starttime, CFL2FYP_FYP_code_length, CFL2FYP_FYP_code);
	add_code.add_CFL_hole_occupy(CFL_hole_NO1, FYP2CFL_CFL_arrive_time1, CFL2FYP_starttime);//�ŷ���׵�һ��ռ��
	//���Լ�2����
	add_code.add_SJ_code(add_reagent2_real_starttime, add_reagent2_code_length, add_reagent2_code);
	add_code.add_FYP_move_code(FYP_add_reagent2_starttime, add_reagent2_FYP_code_length, add_reagent2_FYP_code);
	//���Լ�4����
	add_code.add_SJ_code(add_reagent4_real_starttime, add_reagent4_code_length, add_reagent4_code);
	add_code.add_FYP_move_code(FYP_add_reagent4_starttime, add_reagent4_FYP_code_length, add_reagent4_FYP_code);
	//����2����
	add_code.add_mix_code(add_mix2_real_starttime, add_mix2_code_length, add_mix2_code);
	add_code.add_FYP_move_code(FYP_add_mix2_starttime, add_mix2_FYP_code_length, add_mix2_FYP_code);
	//�����̵��ŷ���ڶ��δ���
	add_code.add_JZ_move_code(FYP2CFL_JZ_starttime2, FYP2CFL_JZ_code_length2, FYP2CFL_JZ_code2);
	add_code.add_FYP_move_code(FYP2CFL_FYP_starttime2, FYP2CFL_FYP_code_length2, FYP2CFL_FYP_code2);
	add_code.add_FYP_hole_occupy(CFL2FYP_FYP_holeNO, CFL2FYP_FYP_arrive_time, FYP_out_time2);//�����̿׵ڶ���ռ��
																							 //�ŷ��뵽��������
	add_code.add_JZ_move_code(CFL2ZDQ_JZ_starttime, CFL2ZDQ_JZ_code_length, CFL2ZDQ_JZ_code);
	add_code.add_CFL_hole_occupy(CFL_hole_NO2, FYP2CFL_CFL_arrive_time2, CFL2ZDQ_starttime);//�ŷ���׵ڶ���ռ��
																							//�������������
	add_code.add_JZ_move_code(ZDQ2GJC_JZ_starttime, ZDQ2GJC_JZ_code_length, ZDQ2GJC_JZ_code);
	add_code.add_ZDQ_hole_occupy(CFL2ZDQ_hole_NO, CFL2ZDQ_ZDQ_arrive_time, ZDQ2GJC_real_starttime);//������ռ��
																							  //���������ӹ���
	int GJC_code_length = 0;
	int GJC_code[3][50] = { 0 };
	plan.gjc.createcode(36, mission_NO, GJC_code_length, GJC_code);
	int GJC_starttime = ZDQ2GJC_GJC_arrive_time;
	add_code.add_GJC_code(GJC_starttime - 1, GJC_code_length, GJC_code);
	add_code.add_GJC_hole_occupy(GJC_starttime - 1, GJC_starttime + 43);//�����ռ��
																		//������
	add_code.add_ZDQ_motor_code();
	//�ŷ���ת��
	add_code.add_CFL_move_code(GJC_starttime + 1200, cfl_CFLcyclesteptime);
	
	totaltime = GJC_starttime + 1200;

	//��Ӵŷ���ע����Һ�������
	int length = 0;
	int zhushe1_time = 0;
	int paiye1_time = 0;
	int zhushe2_time = 0;
	int paiye2_time = 0;
	int diwu_time = 0;
	int CFLcode1[8][30] = { 0 };
	int CFLcode2[8][30] = { 0 };
	int CFLcode3[8][30] = { 0 };
	int CFLcode4[8][30] = { 0 };
	int CFLcode5[8][30] = { 0 };
	plan.cfl.CFLzhushe1codegenerate(CFLcode1, length);
	plan.cfl.CFLpaiye1codegenerate(CFLcode2, length);
	plan.cfl.CFLzhushe2codegenerate(CFLcode3, length);
	plan.cfl.CFLpaiye2codegenerate(CFLcode4, length);
	plan.cfl.CFLdiwucodegenerate(CFLcode5, length);
	//��һȦ
	zhushe1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 2) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 5) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 6) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 9) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//�ڶ�Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 2 + 12) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time1 / 17 + 5 + 12) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 6 + 12) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time1 / 17 + 9 + 12) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//����Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 2) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 5) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 6) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 9) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	//����Ȧ
	zhushe1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 2 + 12) * 17 + 1;
	paiye1_time = (FYP2CFL_CFL_arrive_time2 / 17 + 5 + 12) * 17 + 1;
	zhushe2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 6 + 12) * 17 + 1;
	paiye2_time = (FYP2CFL_CFL_arrive_time2 / 17 + 9 + 12) * 17 + 1;
	diwu_time = (FYP2CFL_CFL_arrive_time2 / 17 + 10 + 12) * 17 + 1;
	add_code.add_CFL_operation_code(zhushe1_time, length, CFLcode1);
	add_code.add_CFL_operation_code(paiye1_time, length, CFLcode2);
	add_code.add_CFL_operation_code(zhushe2_time, length, CFLcode3);
	add_code.add_CFL_operation_code(paiye2_time, length, CFLcode4);
	add_code.add_CFL_operation_code(diwu_time, length, CFLcode5);
}

