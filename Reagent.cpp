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

//����ֵ��0�������2��;�Լ��˶���
//����ֵ��1�������3��;�Լ��붯��
//����ֵ��2�������17��;SGMB
//����ֵ��3�������1��;�Լ�����ת
//����ֵ��4�������25��;P01��ϴ��
//����ֵ��5�������38��;V01��ͨ��
//����ֵ��6�������31��;V03��ͨ��
//����ֵ��7�������33��;V05��ͨ��
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

	//***************�Լ��˶���,�����2��
	codelength = 0;
	Reagent_Code_Row = 0;
	//�ȴ��Լ�������
	code[Reagent_Code_Row][codelength] = 77;
	codelength++;
	for (int i = 0; i < SJG_UpDown_Time; i++)
	{
		code[Reagent_Code_Row][codelength] = 77;
		codelength++;
	}
	codelength--;
	//��ʼ����,���ǽ��Լ����ƶ����Լ�λ��
	for (int i = 0; i < SJG_Move_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = SJG_Rotary_Angle;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}
	//�����Ƿ�ʱ
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//�ȴ��Լ�������½����Լ�����,��ҪSJG_UpDown_Time+Pump_In_Out_Timeʱ��
	for (int i = 0; i < 2 * SJG_UpDown_Time + Pump_In_Out_Time - 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//�ƶ���������λ
	for (int i = 0; i < SJG_Move_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = Reaction_Place;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}

	//�����Ƿ�ʱ
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//�����ڵ��Լ�ע�䵽�Թ���
	for (int i = 0; i < 2 * SJG_UpDown_Time + Pump_In_Out_Time - 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}
	
	//�ƶ�����ϴλ
	for (int i = 0; i < SJG_Move_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = Wash_Place;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}

	//�����Ƿ�ʱ
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//�ȴ���ͷ��ϴ���,��ͷ�������²���
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + GSJG_UpDown_Time + 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 00;
	}

	//***********�Լ��붯��,�����3��
	//�ȳ�ʼ���Լ���λ��
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
	//�����Ƿ�ʱ

	code[Reagent_Code_Row][codelength] = 88;

	//�ȴ��Լ���ת�����Լ���λ��
	for (int i = 0; i < SJG_Move_Time; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//��ͷ�½�
	for (int i = 0; i < SJG_UpDown_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = SJZ_Down_Absorb_Reagent;
		else
			code[Reagent_Code_Row][codelength] = 77;

	}
	//�����Ƿ�ʱ
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//�ȴ��ö���
	for (int i = 0; i < Pump_In_Out_Time - 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//��ͷ����
	for (int i = 0; i < SJG_UpDown_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = SJZ_ReSet;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}

	//�����Ƿ�ʱ
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//�ȴ��Լ���ת�Ƶ�������λ
	for (int i = 0; i < SJG_Move_Time - 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//��ͷ�½�
	for (int i = 0; i < SJG_UpDown_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = SJZ_Down_Spit_Reagent;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}
	//�����Ƿ�ʱ
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//�ȴ��ö���
	for (int i = 0; i < Pump_In_Out_Time - 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}
	

	//��ͷ����
	for (int i = 0; i < SJG_UpDown_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = SJZ_ReSet;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}
	//�����Ƿ�ʱ
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//�ȴ��Լ���ת���Լ�λ
	for (int i = 0; i < SJG_Move_Time - 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//��ͷ�½�������ϴ
	for (int i = 0; i < SJG_UpDown_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = SJZ_Down_Wash_Liquid;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}
	//�����Ƿ�ʱ
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//�ȴ��������²���
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//************�ö���,�����18��
	codelength = 0;
	Reagent_Code_Row++;
	code[Reagent_Code_Row][codelength] = 01;
	codelength++;
	//�ȴ��Լ�������
	for (int i = 0; i < SJG_UpDown_Time; i++)
	{
		code[Reagent_Code_Row][codelength] = 77;
		codelength++;
	}
	codelength--;
	//�ȴ��Լ���ת�����Լ����Լ���ͷ�½�
	for (int i = 0; i < SJG_Move_Time + SJG_UpDown_Time; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//��������
	for (int i = 0; i < Pump_In_Out_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = GAbsorb_reagent_ul + 1;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}
	//�����Ƿ�ʱ
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//�ȴ��Լ���ת����������λ�Լ���ͷ�½�
	for (int i = 0; i < SJG_Move_Time + 2 * SJG_UpDown_Time - 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//����
	for (int i = 0; i < Pump_In_Out_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = GSGMA_Reset;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}

	//�����Ƿ�ʱ
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;
	

	//�ȴ��Լ���ת����ϴλ�Լ���ͷ�½�
	for (int i = 0; i < SJG_Move_Time + SJG_UpDown_Time; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//�ȴ��ڱ���ϴ��ϲ���
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
	//�ȴ������ϴ��Ϲط�
	for (int i = 0; i < GP01_Open_WashOutside_Time + 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//*********�Լ��̶���,�����1��
	codelength = 0;
	Reagent_Code_Row++;
	//�ȴ��Լ�������
	for (int i = 0; i < SJG_UpDown_Time + 1; i++)
	{
		code[Reagent_Code_Row][codelength] = 77;
		codelength++;
		
	}
	codelength--;
	//�Լ���ת������Ӧλ��
	for (int i = 0; i < SJP_Rotary_Movement_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = SJP_Rotary_Place;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}
	//�����Ƿ�ʱ
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	//�ȴ������Լ���ͷ����
	for (int i = 0; i < Pump_In_Out_Time + SJG_UpDown_Time + 1; i++)
	{
		codelength++;
		code[Reagent_Code_Row][codelength] = 77;
	}

	//�Լ��̸�λ
	for (int i = 0; i < SJP_Rotary_Movement_Time; i++)
	{
		codelength++;
		if (i == 0)
			code[Reagent_Code_Row][codelength] = SJP_Ini_Place;
		else
			code[Reagent_Code_Row][codelength] = 77;
	}
	//�����Ƿ�ʱ
	codelength++;
	code[Reagent_Code_Row][codelength] = 88;

	codelength++;
	code[Reagent_Code_Row][codelength] = 21;//����ת180�����

	codelength++;
	code[Reagent_Code_Row][codelength] = 77;

	codelength++;
	code[Reagent_Code_Row][codelength] = 55;

	//***********P01��ϴ�ö���,�����21��
	//�ȴ�ǰ�������,���жϽ������
	codelength = 0;
	Reagent_Code_Row++;
	
	for (int i = 0; i < 6 * SJG_UpDown_Time + 3 * SJG_Move_Time + 2 * Pump_In_Out_Time + 1; i++)
	{
		
		code[Reagent_Code_Row][codelength] = 77;
		codelength++;
	}
	codelength--;

	//P01�ϵ�,��ϴ�ڱ������
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

	//***********V01��ͨ������,�����27��
	//V01��ͨ�����ȵȴ�ǰ����,��P01��ϴ����ͬ
	codelength = 0;
	Reagent_Code_Row++;
	
	for (int i = 0; i < 6 * SJG_UpDown_Time + 3 * SJG_Move_Time + 2 * Pump_In_Out_Time; i++)
	{
		code[Reagent_Code_Row][codelength] = 77;
		codelength++;
	}
	codelength--;

	//�ȸ�V01�ϵ��ź�
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

	//�ر�V01
	codelength++;
	code[Reagent_Code_Row][codelength] = V01_Power_On;

	//*************V03��ͨ������,�����30��
	//V03��ͨ�����ȵȴ�ǰ����,��P01��ϴ����ͬ
	codelength = 0;
	Reagent_Code_Row++;
	
	for (int i = 0; i < 6 * SJG_UpDown_Time + 3 * SJG_Move_Time + 2 * Pump_In_Out_Time; i++)
	{
		code[Reagent_Code_Row][codelength] = 77;
		codelength++;
	}
	codelength--;
	//�ȸ�V03�ϵ��ź�,���Դ��ڱ���ϴ·
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

	//*******V05������Һ������,�����31��
	//���ȹر�V05
	codelength = 0;
	Reagent_Code_Row++;
	
	//�ȴ���������
	for (int i = 0; i < 3 * SJG_Move_Time + 6 * SJG_UpDown_Time + 2 * Pump_In_Out_Time; i++)
	{
		code[Reagent_Code_Row][codelength] = 77;
		codelength++;
	}
	codelength--;
	//��V05
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

	//�ر�V05
	codelength++;
	code[Reagent_Code_Row][codelength] = V05_Power_Off;

	codelength++;
	return codelength;
}
