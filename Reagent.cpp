#include "stdafx.h"
#include "Reagent.h"
#include "GlobalVariableState.h"

#define SJZ_ReSet 55                  
#define SJZ_Down_Wash_Liquid 02
#define SJZ_Down_Absorb_Reagent 03
#define SJZ_Down_Spit_Reagent 04
#define Wash_Place 55
#define SJP_Ini_Place 55
#define Reaction_Place 06
#define Attenuation_Place 07
#define P01_Power_On 01
#define P01_Power_Off 02
#define V01_Power_On 01
#define V01_Power_Off 55
#define V03_Power_On 01
#define V03_Power_Off 55
#define V05_Power_On 01
#define V05_Power_Off 55
Reagent::Reagent() :SJG_Move_Time(GSJG_Move_Time), SJG_UpDown_Time(GSJG_UpDown_Time), Pump_In_Out_Time(GPump_In_Out_Time), 
SJP_Rotary_Movement_Time(GSJP_Rotary_Movement_Time), P01_Wash_Inside_Time(GP01_Wash_Inside_Time), 
P01_Wash_Outside_Time(GP01_Wash_Outside_Time), Reagent_Code_Row(GReagent_Code_Row), SJG_Rotary_Angle(GSJG_Rotary_Angle),
SJP_Rotary_Place(GSJP_Rotary_Place)
{
}


Reagent::~Reagent()
{
}

//索引值“0”代表第2行;试剂杆动作
//索引值“1”代表第3行;试剂针动作
//索引值“2”代表第17行;SGMB
//索引值“3”代表第1行;试剂盘旋转
//索引值“4”代表第25行;P01清洗泵
//索引值“5”代表第38行;V01三通阀
//索引值“6”代表第31行;V03三通阀
//索引值“7”代表第33行;V05三通阀
int Reagent::PutReagentToFYPcode(int project, int Reagent_Bin_NO, int Reagent_Location_NO, int(&code)[8][100], int &codelength)
{
	switch (project)
	{
	case 1:
		GAbsorb_reagent_ul = 5;
		break;
	case 2:
		GAbsorb_reagent_ul = 10;
		break;
	case 3:
		GAbsorb_reagent_ul = 15;
		break;
	case 4:
		GAbsorb_reagent_ul = 20;
		break;
	case 5:
		GAbsorb_reagent_ul = 25;
		break;
	case 6:
		GAbsorb_reagent_ul = 30;
		break;
	case 7:
		GAbsorb_reagent_ul = 35;
		break;
	case 8:
		GAbsorb_reagent_ul = 40;
		break;
	case 9:
		GAbsorb_reagent_ul = 45;
		break;
	case 10:
		GAbsorb_reagent_ul = 50;
		break;
	case 11:
		GAbsorb_reagent_ul = 55;
		break;
	case 12:
		GAbsorb_reagent_ul = 60;
		break;
	case 13:
		GAbsorb_reagent_ul = 65;
		break;
	case 14:
		GAbsorb_reagent_ul = 70;
		break;
	case 15:
		GAbsorb_reagent_ul = 75;
		break;
	case 16:
		GAbsorb_reagent_ul = 80;
		break;
	case 17:
		GAbsorb_reagent_ul = 85;
		break;
	case 18:
		GAbsorb_reagent_ul = 90;
		break;
	case 19:
		GAbsorb_reagent_ul = 95;
		break;
	case 20:
		GAbsorb_reagent_ul = 100;
		break;
	case 21:
		GAbsorb_reagent_ul = 105;
		break;
	case 22:
		GAbsorb_reagent_ul = 110;
		break;
	case 23:
		GAbsorb_reagent_ul = 115;
		break;
	case 24:
		GAbsorb_reagent_ul = 120;
		break;
	case 25:
		GAbsorb_reagent_ul = 125;
		break;
	case 26:
		GAbsorb_reagent_ul = 130;
		break;
	case 27:
		GAbsorb_reagent_ul = 135;
		break;
	case 28:
		GAbsorb_reagent_ul = 140;
		break;
	case 29:
		GAbsorb_reagent_ul = 145;
		break;
	case 30:
		GAbsorb_reagent_ul = 150;
		break;
	case 31:
		GAbsorb_reagent_ul = 155;
		break;
	case 32:
		GAbsorb_reagent_ul = 160;
		break;
	case 33:
		GAbsorb_reagent_ul = 165;
		break;
	case 34:
		GAbsorb_reagent_ul = 170;
		break;
	case 35:
		GAbsorb_reagent_ul = 175;
		break;
	case 36:
		GAbsorb_reagent_ul = 180;
		break;
	case 37:
		GAbsorb_reagent_ul = 185;
		break;
	case 38:
		GAbsorb_reagent_ul = 190;
		break;
	case 39:
		GAbsorb_reagent_ul = 195;
		break;
	case 40:
		GAbsorb_reagent_ul = 200;
		break;
	default:
		break;
	}

	switch (Reagent_Location_NO)
	{
		case 0:
			SJG_Rotary_Angle = 02;
			if (Reagent_Bin_NO - 1 == 0)
				SJP_Rotary_Place = 55;
			else if (Reagent_Bin_NO - 1 == 1)
				SJP_Rotary_Place = 5;
			else if (Reagent_Bin_NO - 1 == 2)
				SJP_Rotary_Place = 9;
			else if (Reagent_Bin_NO - 1 == 3)
				SJP_Rotary_Place = 13;
			else if (Reagent_Bin_NO - 1 == 4)
				SJP_Rotary_Place = 17;
			else if (Reagent_Bin_NO - 1 == 5)
				SJP_Rotary_Place = 21;
			else if (Reagent_Bin_NO - 1 == 6)
				SJP_Rotary_Place = 25;
			else if (Reagent_Bin_NO - 1 == 7)
				SJP_Rotary_Place = 29;
			else if (Reagent_Bin_NO - 1 == 8)
				SJP_Rotary_Place = 33;
			else
				SJP_Rotary_Place = 37;
			break;
		case 1:
			SJG_Rotary_Angle = 03;
			if (Reagent_Bin_NO - 1 == 0)
				SJP_Rotary_Place = 2;
			else if (Reagent_Bin_NO - 1 == 1)
				SJP_Rotary_Place = 6;
			else if (Reagent_Bin_NO - 1 == 2)
				SJP_Rotary_Place = 10;
			else if (Reagent_Bin_NO - 1 == 3)
				SJP_Rotary_Place = 14;
			else if (Reagent_Bin_NO - 1 == 4)
				SJP_Rotary_Place = 18;
			else if (Reagent_Bin_NO - 1 == 5)
				SJP_Rotary_Place = 22;
			else if (Reagent_Bin_NO - 1 == 6)
				SJP_Rotary_Place = 26;
			else if (Reagent_Bin_NO - 1 == 7)
				SJP_Rotary_Place = 30;
			else if (Reagent_Bin_NO - 1 == 8)
				SJP_Rotary_Place = 34;
			else
				SJP_Rotary_Place = 38;
			break;
		case 2:
			SJG_Rotary_Angle = 04;
			if (Reagent_Bin_NO - 1 == 0)
				SJP_Rotary_Place = 3;
			else if (Reagent_Bin_NO - 1 == 1)
				SJP_Rotary_Place = 7;
			else if (Reagent_Bin_NO - 1 == 2)
				SJP_Rotary_Place = 11;
			else if (Reagent_Bin_NO - 1 == 3)
				SJP_Rotary_Place = 15;
			else if (Reagent_Bin_NO - 1 == 4)
				SJP_Rotary_Place = 19;
			else if (Reagent_Bin_NO - 1 == 5)
				SJP_Rotary_Place = 23;
			else if (Reagent_Bin_NO - 1 == 6)
				SJP_Rotary_Place = 27;
			else if (Reagent_Bin_NO - 1 == 7)
				SJP_Rotary_Place = 31;
			else if (Reagent_Bin_NO - 1 == 8)
				SJP_Rotary_Place = 35;
			else
				SJP_Rotary_Place = 39;
			break;
		case 3:
			SJG_Rotary_Angle = 05;
			if (Reagent_Bin_NO - 1 == 0)
				SJP_Rotary_Place = 4;
			else if (Reagent_Bin_NO - 1 == 1)
				SJP_Rotary_Place = 8;
			else if (Reagent_Bin_NO - 1 == 2)
				SJP_Rotary_Place = 12;
			else if (Reagent_Bin_NO - 1 == 3)
				SJP_Rotary_Place = 16;
			else if (Reagent_Bin_NO - 1 == 4)
				SJP_Rotary_Place = 20;
			else if (Reagent_Bin_NO - 1 == 5)
				SJP_Rotary_Place = 24;
			else if (Reagent_Bin_NO - 1 == 6)
				SJP_Rotary_Place = 28;
			else if (Reagent_Bin_NO - 1 == 7)
				SJP_Rotary_Place = 32;
			else if (Reagent_Bin_NO - 1 == 8)
				SJP_Rotary_Place = 36;
			else
				SJP_Rotary_Place = 40;
			break;
	default:
		break;
	}
	if (Reagent_Location_NO == -1 && Reagent_Bin_NO == -1)
	{
		SJG_Rotary_Angle = Attenuation_Place;
		GAbsorb_reagent_ul = 11;
	}

	//***************试剂杆动作,代表第2行
	codelength = 0;
	Reagent_Code_Row = 0;
	//等待试剂针缩回
	code[Reagent_Code_Row][codelength] = 77;
	codelength++;
	for (int i = 0; i < SJG_UpDown_Time; i++)
	{
		code[Reagent_Code_Row][codelength] = 77;
		codelength++;
	}
	codelength--;
	//开始动作,先是将试剂杆移动到试剂位上
	for (int i = 0; i < SJG_Move_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = SJG_Rotary_Angle;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}
	//检验是否超时
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//等待试剂针进行下降吸试剂动作,需要SJG_UpDown_Time+Pump_In_Out_Time时间
	for (int i = 0; i < 2 * SJG_UpDown_Time + Pump_In_Out_Time - 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//移动到孵育盘位
	for (int i = 0; i < SJG_Move_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = Reaction_Place;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}

	//检验是否超时
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//将针内的试剂注射到试管内
	for (int i = 0; i < 2 * SJG_UpDown_Time + Pump_In_Out_Time - 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}
	
	//移动回清洗位
	for (int i = 0; i < SJG_Move_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = Wash_Place;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}

	//检验是否超时
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//等待针头清洗完毕,针头两次吸吐操作
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + GSJG_UpDown_Time + 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 00;
	}

	//***********试剂针动作,代表第3行
	//先初始化试剂针位置
	Reagent_Code_Row++;
	codelength = 0;
	for (int i = 0; i < SJG_UpDown_Time; i++)
	{
		if (i == 0)
			code[Reagent_Code_Row][codelength] = SJZ_ReSet;
		else
			code[Reagent_Code_Row][codelength] = 77;
		codelength++;
	}
	//检验是否超时

	code[Reagent_Code_Row][codelength] = 88;

	//等待试剂杆转动到试剂盘位置
	for (int i = 0; i < SJG_Move_Time; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//针头下降
	for (int i = 0; i < SJG_UpDown_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = SJZ_Down_Absorb_Reagent;
		else
			code[Reagent_Code_Row][codelength] = 77;

	}
	//检验是否超时
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//等待泵动作
	for (int i = 0; i < Pump_In_Out_Time - 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//针头缩回
	for (int i = 0; i < SJG_UpDown_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = SJZ_ReSet;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}

	//检验是否超时
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//等待试剂杆转移到孵育盘位
	for (int i = 0; i < SJG_Move_Time - 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//针头下降
	for (int i = 0; i < SJG_UpDown_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = SJZ_Down_Spit_Reagent;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}
	//检验是否超时
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//等待泵动作
	for (int i = 0; i < Pump_In_Out_Time - 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}
	

	//针头缩回
	for (int i = 0; i < SJG_UpDown_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = SJZ_ReSet;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}
	//检验是否超时
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//等待试剂杆转回试剂位
	for (int i = 0; i < SJG_Move_Time - 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//针头下降进行清洗
	for (int i = 0; i < SJG_UpDown_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = SJZ_Down_Wash_Liquid;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}
	//检验是否超时
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//等待两次吸吐操作
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//************泵动作,代表第18行
	codelength = 0;
	Reagent_Code_Row++;
	code[Reagent_Code_Row][codelength] = 01;
	codelength++;
	//等待试剂针缩回
	for (int i = 0; i < SJG_UpDown_Time; i++)
	{
		code[Reagent_Code_Row][codelength] = 77;
		codelength++;
	}
	codelength--;
	//等待试剂杆转动到试剂盘以及针头下降
	for (int i = 0; i < SJG_Move_Time + SJG_UpDown_Time; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//泵吸操作
	for (int i = 0; i < Pump_In_Out_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = GAbsorb_reagent_ul + 1;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}
	//检验是否超时
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//等待试剂杆转动到孵育盘位以及针头下降
	for (int i = 0; i < SJG_Move_Time + 2 * SJG_UpDown_Time - 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//泵吐
	for (int i = 0; i < Pump_In_Out_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = GSGMA_Reset;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}

	//检验是否超时
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;
	

	//等待试剂杆转回清洗位以及针头下降
	for (int i = 0; i < SJG_Move_Time + SJG_UpDown_Time; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//等待内壁清洗完毕操作
	for (int i = 0; i < 2; i++)
	{
		for (int m = 0; m < GP01_Open_WashInside_Time; m++)
		{
			codelength++;
			if (m == 0)
				code[Reagent_Code_Row][codelength] = 77;
			else
				code[Reagent_Code_Row][codelength] = 77;
		}
	}
	codelength++;
	code[Reagent_Code_Row][codelength] = 77;
	//等待外壁清洗完毕关阀
	for (int i = 0; i < GP01_Open_WashOutside_Time + 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//*********试剂盘动作,代表第1行
	codelength = 0;
	Reagent_Code_Row++;
	//等待试剂针缩回
	for (int i = 0; i < SJG_UpDown_Time + 1; i++)
	{
		code[Reagent_Code_Row][codelength] = 77;
		codelength++;
		
	}
	codelength--;
	//试剂盘转动到相应位置
	for (int i = 0; i < SJP_Rotary_Movement_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = SJP_Rotary_Place;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}
	//检验是否超时
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//等待泵吸以及针头缩回
	for (int i = 0; i < Pump_In_Out_Time + SJG_UpDown_Time + 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//试剂盘复位
	for (int i = 0; i < SJP_Rotary_Movement_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = SJP_Ini_Place;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}
	//检验是否超时
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	codelength++;
	code[Reagent_Code_Row][codelength] = 21;//正反转180°混匀

	codelength++;
	code[Reagent_Code_Row][codelength] = 77;

	codelength++;
	code[Reagent_Code_Row][codelength] = 55;

	//***********P01清洗泵动作,代表第21行
	//等待前序动作完成,先判断搅拌次数
	codelength = 0;
	Reagent_Code_Row++;
	
	for (int i = 0; i < 6 * SJG_UpDown_Time + 3 * SJG_Move_Time + 2 * Pump_In_Out_Time + 1; i++)
	{
		
		code[Reagent_Code_Row][codelength] = 77;
		codelength++;
	}
	codelength--;

	//P01上电,清洗内壁与外壁
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < GP01_Open_WashInside_Time; j++)
		{
			if (j == 0)
			{
				codelength++;
				code[Reagent_Code_Row][codelength] = GP01_Wash_Inside_Time;
			}
			else
			{
				codelength++;
				code[Reagent_Code_Row][codelength] = 77;
			}
		}
	}
	codelength++;
	code[Reagent_Code_Row][codelength] = 77;
	for (int i = 0; i < GP01_Open_WashOutside_Time; i++)
	{
		if (i == 0)
		{
			codelength++;
			code[Reagent_Code_Row][codelength] = GP01_Wash_Outside_Time;
		}
		else
		{
			codelength++;
			code[Reagent_Code_Row][codelength] = 77;
		}
	}

	codelength++;
	code[Reagent_Code_Row][codelength] = 77;

	//***********V01三通阀动作,代表第27行
	//V01三通阀首先等待前序动作,与P01清洗泵相同
	codelength = 0;
	Reagent_Code_Row++;
	
	for (int i = 0; i < 6 * SJG_UpDown_Time + 3 * SJG_Move_Time + 2 * Pump_In_Out_Time; i++)
	{
		code[Reagent_Code_Row][codelength] = 77;
		codelength++;
	}
	codelength--;

	//先给V01断电信号
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time+2; i++)
	{
		if (i == 0)
		{
			codelength++;
			code[Reagent_Code_Row][codelength] = V01_Power_Off;
		}
		else
		{
			codelength++;
			code[Reagent_Code_Row][codelength] = 77;
		}

	}

	//关闭V01
	codelength++;
	code[Reagent_Code_Row][codelength] = V01_Power_On;

	//*************V03三通阀动作,代表第30行
	//V03三通阀首先等待前序动作,与P01清洗泵相同
	codelength = 0;
	Reagent_Code_Row++;
	
	for (int i = 0; i < 6 * SJG_UpDown_Time + 3 * SJG_Move_Time + 2 * Pump_In_Out_Time; i++)
	{
		code[Reagent_Code_Row][codelength] = 77;
		codelength++;
	}
	codelength--;
	//先给V03上电信号,用以打开内壁清洗路
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time+1; i++)
	{
		if (i == 0)
		{
			codelength++;
			code[Reagent_Code_Row][codelength] = V03_Power_On;
		}
		else
		{
			codelength++;
			code[Reagent_Code_Row][codelength] = 77;
		}
		
	}

	for (int i = 0; i < GP01_Open_WashOutside_Time + 2; i++)
	{
		if (i == 0)
		{
			codelength++;
			code[Reagent_Code_Row][codelength] = V03_Power_Off;
		}
		else
		{
			codelength++;
			code[Reagent_Code_Row][codelength] = 77;
		}
		
	}

	//*******V05样本废液阀动作,代表第31行
	//首先关闭V05
	codelength = 0;
	Reagent_Code_Row++;
	
	//等待后续动作
	for (int i = 0; i < 3 * SJG_Move_Time + 6 * SJG_UpDown_Time + 2 * Pump_In_Out_Time; i++)
	{
		code[Reagent_Code_Row][codelength] = 77;
		codelength++;
	}
	codelength--;
	//打开V05
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time+2; i++)
	{
		if (i == 0)
		{
			codelength++;
			code[Reagent_Code_Row][codelength] = V05_Power_On;
		}
		else
		{
			codelength++;
			code[Reagent_Code_Row][codelength] = 77;
		}
	}

	//关闭V05
	codelength++;
	code[Reagent_Code_Row][codelength] = V05_Power_Off;

	codelength++;
	return codelength;
}
