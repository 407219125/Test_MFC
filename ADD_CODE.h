#pragma once
class ADD_CODE
{
public:
	ADD_CODE();
	~ADD_CODE();
	int add_BJ_move_code(int starttime, int code_length, int code[10]);
	int add_SJ_code(int starttime, int code_length, int code[8][100]);
	int add_sample_code(int starttime, int code_length, int code[8][100]);
	int add_sample_from_fyp_code(int starttime, int code_length, int code[8][100]);
	int add_mix_code(int starttime, int code_length, int code[8][100]);

	int add_CFL_move_code(int endtime, int step_time);
	int add_CFL_operation_code(int starttime, int code_length, int code[8][30]);
	int add_CFL_hole_occupy(int hole_NO, int starttime, int finishedtime);
	int add_JZ_move_code(int starttime, int code_length, int code[3][100]);

	int add_FYP_move_code(int starttime, int code_length, int code[50]);
	int add_FYP_hole_occupy(int hole_NO, int starttime, int finishedtime);
	int add_ZDQ_operation_code(int starttime, int code_length, int code[50]);
	int add_GJC_db_code(int starttime, int code_length, int code[50]);
	int add_ZDQ_hole_occupy(int hole_NO, int starttime, int finishedtime);
	int add_GJC_code(int starttime, int code_length, int code[3][50]);
	int add_GJC_hole_occupy(int starttime, int finishedtime);
	void add_ZDQ_motor_code();

};

