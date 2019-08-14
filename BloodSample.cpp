

#include "stdafx.h"
#include "BloodSample.h"
#include "GlobalVariableState.h"

#define YBZ_ReSet 55
#define YBZ_Down_Wash_Liquid 02
#define YBZ_Down_Spit_Sample 03
#define YBZ_Down_Absorb_Sample 04
#define Wash_Place 55
#define BloodSample_Place 02
#define Reaction_Place 03
#define CXP_1 55
#define P01_Power_On 01
#define P01_Power_Off 02
#define V01_Power_On 01
#define V01_Power_Off 55
#define V02_Power_On 01
#define V02_Power_Off 55
#define V04_Power_On 01
#define V04_Power_Off 55
BloodSamole::BloodSamole() :YBG_Move_Time(GYBG_Move_Time), YBG_UpDown_Time(GYBG_UpDown_Time), Pump_In_Out_Time(GPump_In_Out_Time), YBP_Rotary_Movement_Time(GYBP_Rotary_Movement_Time),
P01_Wash_Inside_Time(GP01_Wash_Inside_Time), P01_Wash_Outside_Time(GP01_Wash_Outside_Time), Code_Row(GCode_Row)
{
}

BloodSamole::~BloodSamole()
{
}


//索引值“0”代表第5行;样本杆动作
//索引值“1”代表第6行;样本针动作
//索引值“2”代表第16行;SGMA
//索引值“3”代表第4行;样本盘动作
//索引值“4”代表第21行;P01清洗泵
//索引值“5”代表第38行;V01三通阀
//索引值“6”代表第24行;V02三通阀
//索引值“7”代表第32行;V04三通阀
int BloodSamole::PutSampleToFYPCode(int project, int SampleNO, int(&code)[8][100], int& CodeLength)
{
	switch (project)
	{
	case 1:
		GAbsorb_sample_ul = 5;
		break;
	case 2:
		GAbsorb_sample_ul = 10;
		break;
	case 3:
		GAbsorb_sample_ul = 15;
		break;
	case 4:
		GAbsorb_sample_ul = 20;
		break;
	case 5:
		GAbsorb_sample_ul = 25;
		break;
	case 6:
		GAbsorb_sample_ul = 30;
		break;
	case 7:
		GAbsorb_sample_ul = 35;
		break;
	case 8:
		GAbsorb_sample_ul = 40;
		break;
	case 9:
		GAbsorb_sample_ul = 45;
		break;
	case 10:
		GAbsorb_sample_ul = 50;
		break;
	case 11:
		GAbsorb_sample_ul = 55;
		break;
	case 12:
		GAbsorb_sample_ul = 60;
		break;
	case 13:
		GAbsorb_sample_ul = 65;
		break;
	case 14:
		GAbsorb_sample_ul = 70;
		break;
	case 15:
		GAbsorb_sample_ul = 75;
		break;
	case 16:
		GAbsorb_sample_ul = 80;
		break;
	case 17:
		GAbsorb_sample_ul = 85;
		break;
	case 18:
		GAbsorb_sample_ul = 90;
		break;
	case 19:
		GAbsorb_sample_ul = 95;
		break;
	case 20:
		GAbsorb_sample_ul = 100;
		break;
	case 21:
		GAbsorb_sample_ul = 105;
		break;
	case 22:
		GAbsorb_sample_ul = 110;
		break;
	case 23:
		GAbsorb_sample_ul = 115;
		break;
	case 24:
		GAbsorb_sample_ul = 120;
		break;
	case 25:
		GAbsorb_sample_ul = 125;
		break;
	default:
		break;
	}
	
	//***************样本杆动作,代表第5行
    CodeLength = 0;
	Code_Row = 0;
	//等待样本针缩回
	code[Code_Row][CodeLength] = 77;
	CodeLength++;
	for (int i = 0; i < YBG_UpDown_Time; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;
	//开始动作,先是将样本杆移动到样本位上
	for (int i = 0; i < YBG_Move_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[Code_Row][CodeLength] = BloodSample_Place;
		else
			code[Code_Row][CodeLength] = 77;
	}
	//检验是否超时
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//等待样本针进行下降样本动作,需要YBG_UpDown_Time+Pump_In_Out_Time时间
	for (int i = 0; i < 2 * YBG_UpDown_Time + Pump_In_Out_Time - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}
	
	//移动到孵育盘位
	for (int i = 0; i < YBG_Move_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[Code_Row][CodeLength] = Reaction_Place;
		else
			code[Code_Row][CodeLength] = 77;
	}

	//检验是否超时
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//将针内的样本注射到试管内
	for (int i = 0; i < 2 * YBG_UpDown_Time + Pump_In_Out_Time - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//移动回清洗位
	for (int i = 0; i < YBG_Move_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[Code_Row][CodeLength] = Wash_Place;
		else
			code[Code_Row][CodeLength] = 77;
	}

	//检验是否超时
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//等待针头清洗完毕,针头两次吸吐操作及清洗外壁关阀
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + GYBG_UpDown_Time + 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 00;
	}

	//***********样本针动作,代表第4行
	//先初始化样本针位置
	Code_Row++;
	CodeLength = 0;
	for (int i = 0; i < YBG_UpDown_Time; i++)
	{
		if (i==0)
			code[Code_Row][CodeLength] = YBZ_ReSet;
		else
			code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	//检验是否超时
	code[Code_Row][CodeLength] = 88;

	//等待样本杆转动到样本盘位置
	for (int i = 0; i < YBG_Move_Time ; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//针头下降
	for (int i = 0; i < YBG_UpDown_Time; i++)
	{
		CodeLength++;
		if (i==0)
			code[Code_Row][CodeLength] = YBZ_Down_Absorb_Sample;
		else
			code[Code_Row][CodeLength] = 77;
		
	}
	//检验是否超时
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//等待泵动作
	for (int i = 0; i < Pump_In_Out_Time - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//针头缩回
	for (int i = 0; i < YBG_UpDown_Time; i++)
	{
		CodeLength++;
		if (i==0)
			code[Code_Row][CodeLength] = YBZ_ReSet;
		else
			code[Code_Row][CodeLength] = 77;
	}

	//检验是否超时
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//等待样本杆转移到孵育盘位
	for (int i = 0; i < YBG_Move_Time-1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}
	
	//针头下降
	for (int i = 0; i < YBG_UpDown_Time; i++)
	{
		CodeLength++;
		if (i==0)
			code[Code_Row][CodeLength] = YBZ_Down_Spit_Sample;
		else
			code[Code_Row][CodeLength] = 77;
	}
	//检验是否超时
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//等待泵动作
	for (int i = 0; i < Pump_In_Out_Time - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//针头缩回
	for (int i = 0; i < YBG_UpDown_Time; i++)
	{
		CodeLength++;
		if (i==0)
			code[Code_Row][CodeLength] = YBZ_ReSet;
		else
			code[Code_Row][CodeLength] = 77;
	}
	//检验是否超时
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//等待样本杆转回清洗位
	for (int i = 0; i < YBG_Move_Time-1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}
	
	//针头下降进行清洗
	for (int i = 0; i < YBG_UpDown_Time; i++)
	{
		CodeLength++;
		if (i==0)
			code[Code_Row][CodeLength] = YBZ_Down_Wash_Liquid;
		else
			code[Code_Row][CodeLength] = 77;
	}
	//检验是否超时
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//等待两次吸吐操作与清洗外壁关阀
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 2; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//************泵动作,代表第17行
	CodeLength = 0;
	Code_Row++;
	code[Code_Row][CodeLength] = 01;
	CodeLength++;
	//等待样本针缩回
	for (int i = 0; i < YBG_UpDown_Time; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;
	//等待样本杆转动到样本盘以及针头下降
	for (int i = 0; i < YBG_Move_Time + YBG_UpDown_Time; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}
	
	//泵吸操作
	for (int i = 0; i < Pump_In_Out_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[Code_Row][CodeLength] = GAbsorb_sample_ul + 1;
		else
			code[Code_Row][CodeLength] = 77;
	}
	//检验是否超时
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//等待样本杆转动到孵育盘位以及针头下降
	for (int i = 0; i < YBG_Move_Time + 2 * YBG_UpDown_Time - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//泵吐操作
	for (int i = 0; i < Pump_In_Out_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[Code_Row][CodeLength] = GSGMA_Reset;
		else
			code[Code_Row][CodeLength] = 77;
	}

	//检验是否超时
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//等待样本杆转回清洗位以及针头下降
	for (int i = 0; i < YBG_Move_Time + YBG_UpDown_Time; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}
	
	//等待清洗内壁完毕操作
	for (int i = 0; i < 2; i++)
	{
		for (int m = 0; m < GP01_Open_WashInside_Time; m++)
		{
			CodeLength++;
			if (m == 0)
				code[Code_Row][CodeLength] = 77;
			else
				code[Code_Row][CodeLength] = 77;
		}
	}
	CodeLength++;
	code[Code_Row][CodeLength] = 77;
	//等待外壁清洗完毕关阀
	for (int i = 0; i < GP01_Open_WashOutside_Time + 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}


	//*********样本盘动作,代表第6行
	CodeLength = 0;
	Code_Row++;
	//等待样本针缩回
	for (int i = 0; i < YBG_UpDown_Time + 1; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;
	//样本盘转动到6号位
	for (int i = 0; i < YBP_Rotary_Movement_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[Code_Row][CodeLength] = SampleNO - 1 + 128;
		else
			code[Code_Row][CodeLength] = 77;
	}
	//检验是否超时
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//等待泵吸以及针头缩回
	for (int i = 0; i < Pump_In_Out_Time + YBG_UpDown_Time+1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}
	
	//样本盘复位
	for (int i = 0; i < YBP_Rotary_Movement_Time; i++)
	{
		CodeLength++;
		if (i==0)
			code[Code_Row][CodeLength] = CXP_1;
		else
			code[Code_Row][CodeLength] = 77;
	}
	//检验是否超时
	CodeLength++;
	code[Code_Row][CodeLength] = 88;
	
	//***********P01清洗泵动作,代表第21行
	//等待前序动作完成,先判断搅拌次数
	CodeLength = 0;
	Code_Row++;
	
	for (int i = 0; i < 6 * YBG_UpDown_Time + 3 * YBG_Move_Time + 2 * Pump_In_Out_Time + 1; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//P01上电,清洗内壁与外壁
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < GP01_Open_WashInside_Time; j++)
		{
			if (j == 0)
			{
				CodeLength++;
				code[Code_Row][CodeLength] = GP01_Wash_Inside_Time;
			}
			else
			{
				CodeLength++;
				code[Code_Row][CodeLength] = 77;
			}
		}
	}
	CodeLength++;
	code[Code_Row][CodeLength] = 77;
	for (int i = 0; i < GP01_Open_WashOutside_Time; i++)
	{
		if (i==0)
		{
			CodeLength++;
			code[Code_Row][CodeLength] = GP01_Wash_Outside_Time;
		}
		else
		{
			CodeLength++;
			code[Code_Row][CodeLength] = 77;
		}
	}

	CodeLength++;
	code[Code_Row][CodeLength] = 77;

	//***********V01三通阀动作,代表第27行
	//V01三通阀首先等待前序动作,与P01清洗泵相同
	CodeLength = 0;
	Code_Row++;

	for (int i = 0; i < 6 * YBG_UpDown_Time + 3 * YBG_Move_Time + 2 * Pump_In_Out_Time; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//先给V01上电信号
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 2; i++)
	{
		if (i == 0)
		{
			CodeLength++;
			code[Code_Row][CodeLength] = V01_Power_On;
		}
		else
		{
			CodeLength++;
			code[Code_Row][CodeLength] = 77;
		}
		
	}
	
	//关闭V01
	CodeLength++;
	code[Code_Row][CodeLength] = V01_Power_Off;

	//*************V02三通阀动作,代表第20行
	//V02三通阀首先等待前序动作,与P01清洗泵相同
	CodeLength = 0;
	Code_Row++;

	for (int i = 0; i < 6 * YBG_UpDown_Time + 3 * YBG_Move_Time + 2 * Pump_In_Out_Time; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;
	//先给V02上电信号,用以打开内壁清洗路

	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + 1; i++)
	{
		if (i == 0)
		{
			CodeLength++;
			code[Code_Row][CodeLength] = V02_Power_On;
		}
		else
		{
			CodeLength++;
			code[Code_Row][CodeLength] = 77;
		}
	}

	for (int i = 0; i < GP01_Open_WashOutside_Time + 2; i++)
	{
		if (i == 0)
		{
			CodeLength++;
			code[Code_Row][CodeLength] = V02_Power_Off;
		}
		else
		{
			CodeLength++;
			code[Code_Row][CodeLength] = 77;
		}
		
	}

	//*******V04样本废液阀动作,代表第31行
	//首先关闭V04
	CodeLength = 0;
	Code_Row++;
	
	//等待后续动作
	for (int i = 0; i < 6 * YBG_UpDown_Time + 3 * YBG_Move_Time + 2 * Pump_In_Out_Time; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//打开V04排废
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 2; i++)
	{
		if (i == 0)
		{
			CodeLength++;
			code[Code_Row][CodeLength] = V04_Power_On;
		}
		else
		{
			CodeLength++;
			code[Code_Row][CodeLength] = 77;
		}
	}

	//关闭V04
	CodeLength++;
	code[Code_Row][CodeLength] = V04_Power_Off;

	CodeLength++;
	return CodeLength;
}

int BloodSamole::MixCode(int(&code)[8][100], int& CodeLength)
{
	//***********样本杆动作
	MixCode_Row = 0;
	CodeLength = 0;
	//等待样本针升起
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		code[MixCode_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;
	//样本杆转动到孵育盘位
	for (int i = 0; i < GYBG_Move_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[MixCode_Row][CodeLength] = Reaction_Place;
		else
			code[MixCode_Row][CodeLength] = 77;
	}

	CodeLength++;
	code[MixCode_Row][CodeLength] = 88;

	//等待混匀操作结束
	for (int i = 0; i < 2 * GPump_In_Out_Time + 2 * GYBG_UpDown_Time + 6 * (GPump_In_Out_Time + 1); i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 77;
	}

	//移动回清洗位
	for (int i = 0; i < GYBG_Move_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[MixCode_Row][CodeLength] = Wash_Place;
		else
			code[MixCode_Row][CodeLength] = 77;
	}
	CodeLength++;
	code[MixCode_Row][CodeLength] = 88;

	//等待针清洗完成
	for (int i = 0; i < 2*GP01_Open_WashInside_Time+GP01_Open_WashOutside_Time+GYBG_UpDown_Time+1; i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 00;
	}

	//********样本针动作
	CodeLength = 0;
	MixCode_Row = 1;
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		if (i==0)
			code[MixCode_Row][CodeLength] = YBZ_ReSet;
		else
			code[MixCode_Row][CodeLength] = 77;
		CodeLength++;
	}
	code[MixCode_Row][CodeLength] = 88;

	//等待样本杆转动到孵育盘位
	for (int i = 0; i < GYBG_Move_Time-1; i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 77;
	}

	//针下降
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[MixCode_Row][CodeLength] = YBZ_Down_Spit_Sample;
		else
			code[MixCode_Row][CodeLength] = 77;
	}
	CodeLength++;
	code[MixCode_Row][CodeLength] = 88;

	//等待混匀操作
	for (int i = 0; i < 2 * GPump_In_Out_Time + 6 * (GPump_In_Out_Time + 1); i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 77;
	}

	//针抬起
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[MixCode_Row][CodeLength] = YBZ_ReSet;
		else
			code[MixCode_Row][CodeLength] = 77;
	}
	CodeLength++;
	code[MixCode_Row][CodeLength] = 88;
	//等待样本杆转回清洗位
	for (int i = 0; i < GYBG_Move_Time-1; i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 77;
	}

	//针下降
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		CodeLength++;
		if (i==0)
			code[MixCode_Row][CodeLength] = YBZ_Down_Wash_Liquid;
		else
			code[MixCode_Row][CodeLength] = 77;
	}

	CodeLength++;
	code[MixCode_Row][CodeLength] = 88;

	//等待针清洗完成
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 2; i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 77;
	}

	//********SGMA泵动作
	CodeLength = 0;
	MixCode_Row = 2;
	code[MixCode_Row][CodeLength] = 54;
	CodeLength++;
	//等待针抬起,杆转动到孵育盘,针下降
	for (int i = 0; i < 2 * GYBG_UpDown_Time + GYBG_Move_Time - 1; i++)
	{
		code[MixCode_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//三次吸吐
	for (int m = 0; m < 3; m++)
	{
		//泵吸操作
		for (int i = 0; i < GPump_In_Out_Time; i++)
		{
			CodeLength++;
			if (i == 0)
				code[MixCode_Row][CodeLength] = 10;
			else
				code[MixCode_Row][CodeLength] = 77;
		}
		CodeLength++;
		code[MixCode_Row][CodeLength] = 88;

		//泵吐操作
		for (int j = 0; j < GPump_In_Out_Time; j++)
		{
			CodeLength++;
			if (j == 0)
				code[MixCode_Row][CodeLength] = 54;
			else
				code[MixCode_Row][CodeLength] = 77;
		}
		CodeLength++;
		code[MixCode_Row][CodeLength] = 88;
	}

	//泵吸操作
	for (int i = 0; i < GPump_In_Out_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[MixCode_Row][CodeLength] = 10;
		else
			code[MixCode_Row][CodeLength] = 77;
	}
	CodeLength++;
	code[MixCode_Row][CodeLength] = 88;

	//泵吐操作
	for (int j = 0; j < GPump_In_Out_Time; j++)
	{
		CodeLength++;
		if (j == 0)
			code[MixCode_Row][CodeLength] = 55;
		else
			code[MixCode_Row][CodeLength] = 77;
	}
	CodeLength++;
	code[MixCode_Row][CodeLength] = 88;

	//**********P01泵动作
	MixCode_Row = 4;
	CodeLength = 0;
	//等待前序动作
	for (int i = 0; i < 2 * GYBG_Move_Time + 4 * GYBG_UpDown_Time + 2 * (GPump_In_Out_Time + 1) - 1 + 6*(GPump_In_Out_Time + 1); i++)
	{
		code[MixCode_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//清洗内壁8s
	for (int i = 0; i < GP01_Open_WashInside_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[MixCode_Row][CodeLength] = GP01_Wash_Inside_Time;
		else
			code[MixCode_Row][CodeLength] = 77;
	}

	for (int i = 0; i < GP01_Open_WashInside_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[MixCode_Row][CodeLength] = GP01_Wash_Inside_Time;
		else
			code[MixCode_Row][CodeLength] = 77;
	}
	CodeLength++;
	code[MixCode_Row][CodeLength] = 77;
	//清洗内壁4s
	for (int i = 0; i < GP01_Open_WashOutside_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[MixCode_Row][CodeLength] = GP01_Wash_Outside_Time;
		else
			code[MixCode_Row][CodeLength] = 77;
	}

	//等待关阀
	CodeLength++;
	code[MixCode_Row][CodeLength] = 77;

	//***********V01阀动作
	MixCode_Row = 5;
	CodeLength = 0;
	//等待前序动作
	for (int i = 0; i < 2 * GYBG_Move_Time + 4 * GYBG_UpDown_Time + 2 * (GPump_In_Out_Time + 1) - 2 + 6 * (GPump_In_Out_Time + 1); i++)
	{
		code[MixCode_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//V01打开
	CodeLength++;
	code[MixCode_Row][CodeLength] = V01_Power_On;

	//等待清洗结束
	for (int i = 0; i < 2*GP01_Open_WashInside_Time+GP01_Open_WashOutside_Time+1; i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 77;
	}

	//V01关闭
	CodeLength++;
	code[MixCode_Row][CodeLength] = V01_Power_Off;

	//**************V02阀动作
	MixCode_Row = 6;
	CodeLength = 0;
	//等待前序动作
	for (int i = 0; i < 2 * GYBG_Move_Time + 4 * GYBG_UpDown_Time + 2 * (GPump_In_Out_Time + 1) - 2 + 6 * (GPump_In_Out_Time + 1); i++)
	{
		code[MixCode_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//V02打开
	CodeLength++;
	code[MixCode_Row][CodeLength] = V02_Power_On;

	//等待清洗内壁结束
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time; i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 77;
	}

	//V02关闭
	CodeLength++;
	code[MixCode_Row][CodeLength] = V02_Power_Off;

	//等待清洗外壁结束
	for (int i = 0; i < GP01_Open_WashOutside_Time; i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 77;
	}

	CodeLength++;
	code[MixCode_Row][CodeLength] = 77;

	//***********V04阀动作
	MixCode_Row = 7;
	CodeLength = 0;
	//等待前序动作
	for (int i = 0; i < 2 * GYBG_Move_Time + 4 * GYBG_UpDown_Time + 2 * (GPump_In_Out_Time + 1) - 2 + 6 * (GPump_In_Out_Time + 1); i++)
	{
		code[MixCode_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//V04打开
	CodeLength++;
	code[MixCode_Row][CodeLength] = V04_Power_On;

	//等待清洗结束
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time+1; i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 77;
	}

	//V04关闭
	CodeLength++;
	code[MixCode_Row][CodeLength] = V04_Power_Off;

	//************样本盘动作
	MixCode_Row = 3;
	for (int i = 0; i < CodeLength; i++)
		code[MixCode_Row][i] = 77;
	return ++CodeLength;
}

int BloodSamole::GetSampleFromCupCode(int project, int(&code)[8][100], int& CodeLength)
{
	switch (project)
	{
	case 1:
		GAbsorb_sample_ul = 5;
		break;
	case 2:
		GAbsorb_sample_ul = 10;
		break;
	case 3:
		GAbsorb_sample_ul = 15;
		break;
	case 4:
		GAbsorb_sample_ul = 20;
		break;
	case 5:
		GAbsorb_sample_ul = 25;
		break;
	case 6:
		GAbsorb_sample_ul = 30;
		break;
	case 7:
		GAbsorb_sample_ul = 35;
		break;
	case 8:
		GAbsorb_sample_ul = 40;
		break;
	case 9:
		GAbsorb_sample_ul = 45;
		break;
	case 10:
		GAbsorb_sample_ul = 50;
		break;
	case 11:
		GAbsorb_sample_ul = 55;
		break;
	case 12:
		GAbsorb_sample_ul = 60;
		break;
	case 13:
		GAbsorb_sample_ul = 65;
		break;
	case 14:
		GAbsorb_sample_ul = 70;
		break;
	case 15:
		GAbsorb_sample_ul = 75;
		break;
	case 16:
		GAbsorb_sample_ul = 80;
		break;
	case 17:
		GAbsorb_sample_ul = 85;
		break;
	case 18:
		GAbsorb_sample_ul = 90;
		break;
	case 19:
		GAbsorb_sample_ul = 95;
		break;
	case 20:
		GAbsorb_sample_ul = 100;
		break;
	default:
		break;
	}

	//**********样本杆动作
	CodeLength = 0;
	Code_Row = 0;
	//等待样本针抬起
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//样本杆去孵育盘位
	for (int i = 0; i < GYBG_Move_Time; i++)
	{
		CodeLength++;
		if (i==0)
			code[Code_Row][CodeLength] = Reaction_Place;
		else
			code[Code_Row][CodeLength] = 77;
	}
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//等待从一个试管到另一个试管的吸吐样本操作
	for (int i = 0; i < 4 * GYBG_UpDown_Time + 2 * GPump_In_Out_Time + 3 * FYP_ActionTime; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//移动回清洗位
	for (int i = 0; i < GYBG_Move_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[Code_Row][CodeLength] = Wash_Place;
		else
			code[Code_Row][CodeLength] = 77;
	}
	CodeLength++;
	code[Code_Row][CodeLength] = 88;



	//***********样本针操作
	CodeLength = 0;
	Code_Row = 1;
	//样本针抬起
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		code[Code_Row][CodeLength] = YBZ_ReSet;
		CodeLength++;
	}
	code[Code_Row][CodeLength] = 88;

	//等待样本针转到孵育盘位
	for (int i = 0; i < GYBG_Move_Time - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//针下降吸样本
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		CodeLength++;
		if (i==0)
			code[Code_Row][CodeLength] = YBZ_Down_Absorb_Sample;
		else
			code[Code_Row][CodeLength] = 77;
	}
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//等待泵吸操作
	for (int i = 0; i < GPump_In_Out_Time-1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//针抬起
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[Code_Row][CodeLength] = YBZ_ReSet;
		else
			code[Code_Row][CodeLength] = 77;
	}
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//等待孵育盘换试管
	for (int i = 0; i < 3 * FYP_ActionTime - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//针下降吐样本
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[Code_Row][CodeLength] = YBZ_Down_Absorb_Sample;
		else
			code[Code_Row][CodeLength] = 77;
	}
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//等待泵吐
	for (int i = 0; i < GPump_In_Out_Time - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//针抬起
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[Code_Row][CodeLength] = YBZ_ReSet;
		else
			code[Code_Row][CodeLength] = 77;
	}
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//等待样本杆转动回清洗位
	for (int i = 0; i < GYBG_Move_Time - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//针下降
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		CodeLength++;
		if (i==0)
			code[Code_Row][CodeLength] = YBZ_Down_Wash_Liquid;
		else
			code[Code_Row][CodeLength] = 77;
	}
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//等待清洗完成
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//SGMA泵动作
	Code_Row = 2;
	CodeLength = 0;
	code[Code_Row][CodeLength] = 1;
	//等待针抬起,杆转动,针下降
	for (int i = 0; i < 2 * GYBG_UpDown_Time + GYBG_Move_Time - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//泵吸操作
	for (int i = 0; i < GPump_In_Out_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[Code_Row][CodeLength] = GAbsorb_sample_ul + 1;
		else
			code[Code_Row][CodeLength] = 77;
	}
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//等待针抬起,孵育盘换杯,针下降
	for (int i = 0; i < 2 * GYBG_UpDown_Time + 3 * FYP_ActionTime - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//泵吐操作
	for (int i = 0; i < GPump_In_Out_Time; i++)
	{
		CodeLength++;
		if (i==0)
			code[Code_Row][CodeLength] = 55;
		else
			code[Code_Row][CodeLength] = 77;
	}
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	
	//**********样本盘动作
	//无动作


	//*********P01清洗泵动作
	//等待前序动作完成
	Code_Row = 4;
	CodeLength = 0;
	for (int i = 0; i < 6 * GYBG_UpDown_Time + 2 * GYBG_Move_Time + 2 * GPump_In_Out_Time + 3 * FYP_ActionTime; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//清洗内壁
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + 1; i++)
	{
		CodeLength++;
		if (i==0||i==4)
			code[Code_Row][CodeLength] = GP01_Wash_Inside_Time;
		else
			code[Code_Row][CodeLength] = 77;
	}

	//清洗外壁
	for (int i = 0; i < GP01_Open_WashOutside_Time + 1; i++)
	{
		CodeLength++;
		if (i==0)
			code[Code_Row][CodeLength] = GP01_Wash_Outside_Time;
		else
			code[Code_Row][CodeLength] = 77;
	}


	//*********V01公共阀
	Code_Row = 5;
	CodeLength = 0;
	//等待前序动作完成
	for (int i = 0; i < 6 * GYBG_UpDown_Time + 2 * GYBG_Move_Time + 2 * GPump_In_Out_Time + 3 * FYP_ActionTime - 1; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	
	//开阀
	code[Code_Row][CodeLength] = V01_Power_On;

	//等待清洗完成
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//关阀
	CodeLength++;
	code[Code_Row][CodeLength] = V01_Power_Off;


	//**********V02阀动作
	Code_Row = 6;
	CodeLength = 0;
	//等待前序动作
	for (int i = 0; i < 6 * GYBG_UpDown_Time + 2 * GYBG_Move_Time + 2 * GPump_In_Out_Time + 3 * FYP_ActionTime - 1; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}

	//开阀
	code[Code_Row][CodeLength] = V02_Power_On;

	//等待内壁清洗完成
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//关阀
	CodeLength++;
	code[Code_Row][CodeLength] = V02_Power_Off;

	//等待外壁清洗完成
	for (int i = 0; i < GP01_Open_WashOutside_Time + 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}


	//*********V04阀动作
	Code_Row = 7;
	CodeLength = 0;
	//等待前序动作完成
	for (int i = 0; i < 6 * GYBG_UpDown_Time + 2 * GYBG_Move_Time + 2 * GPump_In_Out_Time + 3 * FYP_ActionTime - 1; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}

	//开阀
	code[Code_Row][CodeLength] = V04_Power_On;

	//等待清洗完成
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//关阀
	CodeLength++;
	code[Code_Row][CodeLength] = V04_Power_Off;

	CodeLength = CodeLength + 1;
	return 0;
}

int BloodSamole::GetSampleFromFYPCode(int sample_volum, int(&code)[8][100], int& code_length)
{
	switch (sample_volum)
	{
	case 1:
		GAbsorb_sample_ul = 5;
		break;
	case 2:
		GAbsorb_sample_ul = 10;
		break;
	case 3:
		GAbsorb_sample_ul = 15;
		break;
	case 4:
		GAbsorb_sample_ul = 20;
		break;
	case 5:
		GAbsorb_sample_ul = 25;
		break;
	case 6:
		GAbsorb_sample_ul = 30;
		break;
	case 7:
		GAbsorb_sample_ul = 35;
		break;
	case 8:
		GAbsorb_sample_ul = 40;
		break;
	case 9:
		GAbsorb_sample_ul = 45;
		break;
	case 10:
		GAbsorb_sample_ul = 50;
		break;
	case 11:
		GAbsorb_sample_ul = 55;
		break;
	case 12:
		GAbsorb_sample_ul = 60;
		break;
	case 13:
		GAbsorb_sample_ul = 65;
		break;
	case 14:
		GAbsorb_sample_ul = 70;
		break;
	case 15:
		GAbsorb_sample_ul = 75;
		break;
	case 16:
		GAbsorb_sample_ul = 80;
		break;
	case 17:
		GAbsorb_sample_ul = 85;
		break;
	case 18:
		GAbsorb_sample_ul = 90;
		break;
	case 19:
		GAbsorb_sample_ul = 95;
		break;
	case 20:
		GAbsorb_sample_ul = 100;
		break;
	default:
		break;
	}

	//************8样本杆动作
	code_length = 0;
	Code_Row = 0;
	//等待样本针抬起
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		code[Code_Row][code_length] = 77;
		code_length++;
	}
	code_length--;

	//样本杆去孵育盘位
	for (int i = 0; i < GYBG_Move_Time; i++)
	{
		code_length++;
		if (i == 0)
			code[Code_Row][code_length] = Reaction_Place;
		else
			code[Code_Row][code_length] = 77;
	}
	code_length++;
	code[Code_Row][code_length] = 88;

	//等待针下降,泵吸,针抬起
	for (int i = 0; i < 2 * GYBG_UpDown_Time + GYBG_Move_Time; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}


	//*********样本针动作
	code_length = 0;
	Code_Row = 1;
	//样本针抬起
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		code[Code_Row][code_length] = YBZ_ReSet;
		code_length++;
	}
	code[Code_Row][code_length] = 88;

	//等待样本针转到孵育盘位
	for (int i = 0; i < GYBG_Move_Time - 1; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}

	//针下降吸样本
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		code_length++;
		if (i == 0)
			code[Code_Row][code_length] = YBZ_Down_Spit_Sample;
		else
			code[Code_Row][code_length] = 77;
	}
	code_length++;
	code[Code_Row][code_length] = 88;

	//等待泵吸操作
	for (int i = 0; i < GPump_In_Out_Time - 1; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}

	//针抬起
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		code_length++;
		if (i == 0)
			code[Code_Row][code_length] = YBZ_ReSet;
		else
			code[Code_Row][code_length] = 77;
	}
	code_length++;
	code[Code_Row][code_length] = 88;

	//SGMA泵动作
	Code_Row = 2;
	code_length = 0;
	code[Code_Row][code_length] = 1;
	//等待针抬起,杆转动,针下降
	for (int i = 0; i < 2 * GYBG_UpDown_Time + GYBG_Move_Time - 1; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}

	//泵吸操作
	for (int i = 0; i < GPump_In_Out_Time; i++)
	{
		code_length++;
		if (i == 0)
			code[Code_Row][code_length] = GAbsorb_sample_ul + 1;
		else
			code[Code_Row][code_length] = 77;
	}
	code_length++;
	code[Code_Row][code_length] = 88;

	//等待针抬起
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}

	code_length = code_length + 1;
	return 0;
}

int BloodSamole::GetSampleFromFYP_back_Code(int(&code)[8][100], int& code_length)
{
	//**********样本杆动作
	Code_Row = 0;
	code_length = 0;
	//等待针下降,泵吐,针抬起
	for (int i = 0; i < 2 * GYBG_UpDown_Time + GYBG_Move_Time; i++)
	{
		code[Code_Row][code_length] = 77;
		code_length++;
	}
	code_length--;

	//转动到清洗位
	for (int i = 0; i < GYBG_Move_Time; i++)
	{
		code_length++;
		if (i==0)
			code[Code_Row][code_length] = Wash_Place;
		else
			code[Code_Row][code_length] = 77;
	}
	code_length++;
	code[Code_Row][code_length] = 88;


	//********样本针动作
	code_length = 0;
	Code_Row = 1;
	//针下降
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		if (i==0)
			code[Code_Row][code_length] = YBZ_Down_Spit_Sample;
		else
			code[Code_Row][code_length] = 77;
		code_length++;
	}
	code[Code_Row][code_length] = 88;

	//等待泵吐
	for (int i = 0; i < GPump_In_Out_Time - 1; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}

	//针抬起
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		if (i == 0)
			code[Code_Row][code_length] = YBZ_ReSet;
		else
			code[Code_Row][code_length] = 77;
		code_length++;
	}
	code_length++;
	code[Code_Row][code_length] = 88;

	//等待样本杆转回清洗位
	for (int i = 0; i < GYBG_Move_Time - 1; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}

	//针下降
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		code_length++;
		if (i==0)
			code[Code_Row][code_length] = YBZ_Down_Wash_Liquid;
		else
			code[Code_Row][code_length] = 77;
	}
	code_length++;
	code[Code_Row][code_length] = 88;

	//等待清洗完成
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 1; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}

	
	//*********SGMA泵动作
	Code_Row = 2;
	code_length = 0;
	//等待针下降
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		code[Code_Row][code_length] = 77;
		code_length++;
	}
	code_length--;

	//泵吐
	for (int i = 0; i < GPump_In_Out_Time; i++)
	{
		code_length++;
		if (i==0)
			code[Code_Row][code_length] = 55;
		else
			code[Code_Row][code_length] = 77;
	}
	code_length++;
	code[Code_Row][code_length] = 88;


	//*******P01泵动作
	Code_Row = 4;
	code_length = 0;
	//等待前序动作完成
	for (int i = 0; i < 3 * GYBG_UpDown_Time + GPump_In_Out_Time + GYBG_Move_Time; i++)
	{
		code[Code_Row][code_length] = 77;
		code_length++;
	}
	code_length--;

	//清洗内壁
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + 1; i++)
	{
		code_length++;
		if (i==0||i==4)
			code[Code_Row][code_length] = GP01_Wash_Inside_Time;
		else
			code[Code_Row][code_length] = 77;
	}

	//清洗外壁
	for (int i = 0; i < GP01_Open_WashOutside_Time + 1; i++)
	{
		code_length++;
		if (i == 0)
			code[Code_Row][code_length] = GP01_Wash_Outside_Time;
		else
			code[Code_Row][code_length] = 77;
	}


	//*********V01阀动作
	Code_Row = 5;
	code_length = 0;
	//等待前序动作完成
	for (int i = 0; i < 3 * GYBG_UpDown_Time + GPump_In_Out_Time + GYBG_Move_Time - 1; i++)
	{
		code[Code_Row][code_length] = 77;
		code_length++;
	}
	
	//开阀
	code[Code_Row][code_length] = V01_Power_On;

	//等待清洗完成
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 1; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}
	//关阀
	code_length++;
	code[Code_Row][code_length] = V01_Power_Off;


	//**********V02阀动作
	Code_Row = 6;
	code_length = 0;
	//等待前序动作完成
	for (int i = 0; i < 3 * GYBG_UpDown_Time + GPump_In_Out_Time + GYBG_Move_Time - 1; i++)
	{
		code[Code_Row][code_length] = 77;
		code_length++;
	}

	//开阀
	code[Code_Row][code_length] = V02_Power_On;

	//等待清洗内壁完成
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}

	//关阀换向
	code_length++;
	code[Code_Row][code_length] = V02_Power_Off;

	//等待清洗外壁完成
	for (int i = 0; i < GP01_Open_WashOutside_Time + 1; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}


	//************V04阀动作
	Code_Row = 7;
	code_length = 0;
	//等待前序动作完成
	for (int i = 0; i < 3 * GYBG_UpDown_Time + GPump_In_Out_Time + GYBG_Move_Time - 1; i++)
	{
		code[Code_Row][code_length] = 77;
		code_length++;
	}

	//开阀
	code[Code_Row][code_length] = V04_Power_On;

	//等待清洗完成
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 1; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}

	//关阀
	code_length++;
	code[Code_Row][code_length] = V04_Power_Off;

	code_length = code_length + 1;
	return 0;
}