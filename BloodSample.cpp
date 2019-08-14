

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


//����ֵ��0�������5��;�����˶���
//����ֵ��1�������6��;�����붯��
//����ֵ��2�������16��;SGMA
//����ֵ��3�������4��;�����̶���
//����ֵ��4�������21��;P01��ϴ��
//����ֵ��5�������38��;V01��ͨ��
//����ֵ��6�������24��;V02��ͨ��
//����ֵ��7�������32��;V04��ͨ��
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
	
	//***************�����˶���,�����5��
    CodeLength = 0;
	Code_Row = 0;
	//�ȴ�����������
	code[Code_Row][CodeLength] = 77;
	CodeLength++;
	for (int i = 0; i < YBG_UpDown_Time; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;
	//��ʼ����,���ǽ��������ƶ�������λ��
	for (int i = 0; i < YBG_Move_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[Code_Row][CodeLength] = BloodSample_Place;
		else
			code[Code_Row][CodeLength] = 77;
	}
	//�����Ƿ�ʱ
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//�ȴ�����������½���������,��ҪYBG_UpDown_Time+Pump_In_Out_Timeʱ��
	for (int i = 0; i < 2 * YBG_UpDown_Time + Pump_In_Out_Time - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}
	
	//�ƶ���������λ
	for (int i = 0; i < YBG_Move_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[Code_Row][CodeLength] = Reaction_Place;
		else
			code[Code_Row][CodeLength] = 77;
	}

	//�����Ƿ�ʱ
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//�����ڵ�����ע�䵽�Թ���
	for (int i = 0; i < 2 * YBG_UpDown_Time + Pump_In_Out_Time - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//�ƶ�����ϴλ
	for (int i = 0; i < YBG_Move_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[Code_Row][CodeLength] = Wash_Place;
		else
			code[Code_Row][CodeLength] = 77;
	}

	//�����Ƿ�ʱ
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//�ȴ���ͷ��ϴ���,��ͷ�������²�������ϴ��ڹط�
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + GYBG_UpDown_Time + 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 00;
	}

	//***********�����붯��,�����4��
	//�ȳ�ʼ��������λ��
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
	//�����Ƿ�ʱ
	code[Code_Row][CodeLength] = 88;

	//�ȴ�������ת����������λ��
	for (int i = 0; i < YBG_Move_Time ; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//��ͷ�½�
	for (int i = 0; i < YBG_UpDown_Time; i++)
	{
		CodeLength++;
		if (i==0)
			code[Code_Row][CodeLength] = YBZ_Down_Absorb_Sample;
		else
			code[Code_Row][CodeLength] = 77;
		
	}
	//�����Ƿ�ʱ
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//�ȴ��ö���
	for (int i = 0; i < Pump_In_Out_Time - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//��ͷ����
	for (int i = 0; i < YBG_UpDown_Time; i++)
	{
		CodeLength++;
		if (i==0)
			code[Code_Row][CodeLength] = YBZ_ReSet;
		else
			code[Code_Row][CodeLength] = 77;
	}

	//�����Ƿ�ʱ
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//�ȴ�������ת�Ƶ�������λ
	for (int i = 0; i < YBG_Move_Time-1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}
	
	//��ͷ�½�
	for (int i = 0; i < YBG_UpDown_Time; i++)
	{
		CodeLength++;
		if (i==0)
			code[Code_Row][CodeLength] = YBZ_Down_Spit_Sample;
		else
			code[Code_Row][CodeLength] = 77;
	}
	//�����Ƿ�ʱ
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//�ȴ��ö���
	for (int i = 0; i < Pump_In_Out_Time - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//��ͷ����
	for (int i = 0; i < YBG_UpDown_Time; i++)
	{
		CodeLength++;
		if (i==0)
			code[Code_Row][CodeLength] = YBZ_ReSet;
		else
			code[Code_Row][CodeLength] = 77;
	}
	//�����Ƿ�ʱ
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//�ȴ�������ת����ϴλ
	for (int i = 0; i < YBG_Move_Time-1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}
	
	//��ͷ�½�������ϴ
	for (int i = 0; i < YBG_UpDown_Time; i++)
	{
		CodeLength++;
		if (i==0)
			code[Code_Row][CodeLength] = YBZ_Down_Wash_Liquid;
		else
			code[Code_Row][CodeLength] = 77;
	}
	//�����Ƿ�ʱ
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//�ȴ��������²�������ϴ��ڹط�
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 2; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//************�ö���,�����17��
	CodeLength = 0;
	Code_Row++;
	code[Code_Row][CodeLength] = 01;
	CodeLength++;
	//�ȴ�����������
	for (int i = 0; i < YBG_UpDown_Time; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;
	//�ȴ�������ת�����������Լ���ͷ�½�
	for (int i = 0; i < YBG_Move_Time + YBG_UpDown_Time; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}
	
	//��������
	for (int i = 0; i < Pump_In_Out_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[Code_Row][CodeLength] = GAbsorb_sample_ul + 1;
		else
			code[Code_Row][CodeLength] = 77;
	}
	//�����Ƿ�ʱ
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//�ȴ�������ת����������λ�Լ���ͷ�½�
	for (int i = 0; i < YBG_Move_Time + 2 * YBG_UpDown_Time - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//���²���
	for (int i = 0; i < Pump_In_Out_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[Code_Row][CodeLength] = GSGMA_Reset;
		else
			code[Code_Row][CodeLength] = 77;
	}

	//�����Ƿ�ʱ
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//�ȴ�������ת����ϴλ�Լ���ͷ�½�
	for (int i = 0; i < YBG_Move_Time + YBG_UpDown_Time; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}
	
	//�ȴ���ϴ�ڱ���ϲ���
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
	//�ȴ������ϴ��Ϲط�
	for (int i = 0; i < GP01_Open_WashOutside_Time + 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}


	//*********�����̶���,�����6��
	CodeLength = 0;
	Code_Row++;
	//�ȴ�����������
	for (int i = 0; i < YBG_UpDown_Time + 1; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;
	//������ת����6��λ
	for (int i = 0; i < YBP_Rotary_Movement_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[Code_Row][CodeLength] = SampleNO - 1 + 128;
		else
			code[Code_Row][CodeLength] = 77;
	}
	//�����Ƿ�ʱ
	CodeLength++;
	code[Code_Row][CodeLength] = 88;

	//�ȴ������Լ���ͷ����
	for (int i = 0; i < Pump_In_Out_Time + YBG_UpDown_Time+1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}
	
	//�����̸�λ
	for (int i = 0; i < YBP_Rotary_Movement_Time; i++)
	{
		CodeLength++;
		if (i==0)
			code[Code_Row][CodeLength] = CXP_1;
		else
			code[Code_Row][CodeLength] = 77;
	}
	//�����Ƿ�ʱ
	CodeLength++;
	code[Code_Row][CodeLength] = 88;
	
	//***********P01��ϴ�ö���,�����21��
	//�ȴ�ǰ�������,���жϽ������
	CodeLength = 0;
	Code_Row++;
	
	for (int i = 0; i < 6 * YBG_UpDown_Time + 3 * YBG_Move_Time + 2 * Pump_In_Out_Time + 1; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//P01�ϵ�,��ϴ�ڱ������
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

	//***********V01��ͨ������,�����27��
	//V01��ͨ�����ȵȴ�ǰ����,��P01��ϴ����ͬ
	CodeLength = 0;
	Code_Row++;

	for (int i = 0; i < 6 * YBG_UpDown_Time + 3 * YBG_Move_Time + 2 * Pump_In_Out_Time; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//�ȸ�V01�ϵ��ź�
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
	
	//�ر�V01
	CodeLength++;
	code[Code_Row][CodeLength] = V01_Power_Off;

	//*************V02��ͨ������,�����20��
	//V02��ͨ�����ȵȴ�ǰ����,��P01��ϴ����ͬ
	CodeLength = 0;
	Code_Row++;

	for (int i = 0; i < 6 * YBG_UpDown_Time + 3 * YBG_Move_Time + 2 * Pump_In_Out_Time; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;
	//�ȸ�V02�ϵ��ź�,���Դ��ڱ���ϴ·

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

	//*******V04������Һ������,�����31��
	//���ȹر�V04
	CodeLength = 0;
	Code_Row++;
	
	//�ȴ���������
	for (int i = 0; i < 6 * YBG_UpDown_Time + 3 * YBG_Move_Time + 2 * Pump_In_Out_Time; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//��V04�ŷ�
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

	//�ر�V04
	CodeLength++;
	code[Code_Row][CodeLength] = V04_Power_Off;

	CodeLength++;
	return CodeLength;
}

int BloodSamole::MixCode(int(&code)[8][100], int& CodeLength)
{
	//***********�����˶���
	MixCode_Row = 0;
	CodeLength = 0;
	//�ȴ�����������
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		code[MixCode_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;
	//������ת����������λ
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

	//�ȴ����Ȳ�������
	for (int i = 0; i < 2 * GPump_In_Out_Time + 2 * GYBG_UpDown_Time + 6 * (GPump_In_Out_Time + 1); i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 77;
	}

	//�ƶ�����ϴλ
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

	//�ȴ�����ϴ���
	for (int i = 0; i < 2*GP01_Open_WashInside_Time+GP01_Open_WashOutside_Time+GYBG_UpDown_Time+1; i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 00;
	}

	//********�����붯��
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

	//�ȴ�������ת����������λ
	for (int i = 0; i < GYBG_Move_Time-1; i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 77;
	}

	//���½�
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

	//�ȴ����Ȳ���
	for (int i = 0; i < 2 * GPump_In_Out_Time + 6 * (GPump_In_Out_Time + 1); i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 77;
	}

	//��̧��
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
	//�ȴ�������ת����ϴλ
	for (int i = 0; i < GYBG_Move_Time-1; i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 77;
	}

	//���½�
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

	//�ȴ�����ϴ���
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 2; i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 77;
	}

	//********SGMA�ö���
	CodeLength = 0;
	MixCode_Row = 2;
	code[MixCode_Row][CodeLength] = 54;
	CodeLength++;
	//�ȴ���̧��,��ת����������,���½�
	for (int i = 0; i < 2 * GYBG_UpDown_Time + GYBG_Move_Time - 1; i++)
	{
		code[MixCode_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//��������
	for (int m = 0; m < 3; m++)
	{
		//��������
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

		//���²���
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

	//��������
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

	//���²���
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

	//**********P01�ö���
	MixCode_Row = 4;
	CodeLength = 0;
	//�ȴ�ǰ����
	for (int i = 0; i < 2 * GYBG_Move_Time + 4 * GYBG_UpDown_Time + 2 * (GPump_In_Out_Time + 1) - 1 + 6*(GPump_In_Out_Time + 1); i++)
	{
		code[MixCode_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//��ϴ�ڱ�8s
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
	//��ϴ�ڱ�4s
	for (int i = 0; i < GP01_Open_WashOutside_Time; i++)
	{
		CodeLength++;
		if (i == 0)
			code[MixCode_Row][CodeLength] = GP01_Wash_Outside_Time;
		else
			code[MixCode_Row][CodeLength] = 77;
	}

	//�ȴ��ط�
	CodeLength++;
	code[MixCode_Row][CodeLength] = 77;

	//***********V01������
	MixCode_Row = 5;
	CodeLength = 0;
	//�ȴ�ǰ����
	for (int i = 0; i < 2 * GYBG_Move_Time + 4 * GYBG_UpDown_Time + 2 * (GPump_In_Out_Time + 1) - 2 + 6 * (GPump_In_Out_Time + 1); i++)
	{
		code[MixCode_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//V01��
	CodeLength++;
	code[MixCode_Row][CodeLength] = V01_Power_On;

	//�ȴ���ϴ����
	for (int i = 0; i < 2*GP01_Open_WashInside_Time+GP01_Open_WashOutside_Time+1; i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 77;
	}

	//V01�ر�
	CodeLength++;
	code[MixCode_Row][CodeLength] = V01_Power_Off;

	//**************V02������
	MixCode_Row = 6;
	CodeLength = 0;
	//�ȴ�ǰ����
	for (int i = 0; i < 2 * GYBG_Move_Time + 4 * GYBG_UpDown_Time + 2 * (GPump_In_Out_Time + 1) - 2 + 6 * (GPump_In_Out_Time + 1); i++)
	{
		code[MixCode_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//V02��
	CodeLength++;
	code[MixCode_Row][CodeLength] = V02_Power_On;

	//�ȴ���ϴ�ڱڽ���
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time; i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 77;
	}

	//V02�ر�
	CodeLength++;
	code[MixCode_Row][CodeLength] = V02_Power_Off;

	//�ȴ���ϴ��ڽ���
	for (int i = 0; i < GP01_Open_WashOutside_Time; i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 77;
	}

	CodeLength++;
	code[MixCode_Row][CodeLength] = 77;

	//***********V04������
	MixCode_Row = 7;
	CodeLength = 0;
	//�ȴ�ǰ����
	for (int i = 0; i < 2 * GYBG_Move_Time + 4 * GYBG_UpDown_Time + 2 * (GPump_In_Out_Time + 1) - 2 + 6 * (GPump_In_Out_Time + 1); i++)
	{
		code[MixCode_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//V04��
	CodeLength++;
	code[MixCode_Row][CodeLength] = V04_Power_On;

	//�ȴ���ϴ����
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time+1; i++)
	{
		CodeLength++;
		code[MixCode_Row][CodeLength] = 77;
	}

	//V04�ر�
	CodeLength++;
	code[MixCode_Row][CodeLength] = V04_Power_Off;

	//************�����̶���
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

	//**********�����˶���
	CodeLength = 0;
	Code_Row = 0;
	//�ȴ�������̧��
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//������ȥ������λ
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

	//�ȴ���һ���Թܵ���һ���Թܵ�������������
	for (int i = 0; i < 4 * GYBG_UpDown_Time + 2 * GPump_In_Out_Time + 3 * FYP_ActionTime; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//�ƶ�����ϴλ
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



	//***********���������
	CodeLength = 0;
	Code_Row = 1;
	//������̧��
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		code[Code_Row][CodeLength] = YBZ_ReSet;
		CodeLength++;
	}
	code[Code_Row][CodeLength] = 88;

	//�ȴ�������ת��������λ
	for (int i = 0; i < GYBG_Move_Time - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//���½�������
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

	//�ȴ���������
	for (int i = 0; i < GPump_In_Out_Time-1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//��̧��
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

	//�ȴ������̻��Թ�
	for (int i = 0; i < 3 * FYP_ActionTime - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//���½�������
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

	//�ȴ�����
	for (int i = 0; i < GPump_In_Out_Time - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//��̧��
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

	//�ȴ�������ת������ϴλ
	for (int i = 0; i < GYBG_Move_Time - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//���½�
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

	//�ȴ���ϴ���
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//SGMA�ö���
	Code_Row = 2;
	CodeLength = 0;
	code[Code_Row][CodeLength] = 1;
	//�ȴ���̧��,��ת��,���½�
	for (int i = 0; i < 2 * GYBG_UpDown_Time + GYBG_Move_Time - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//��������
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

	//�ȴ���̧��,�����̻���,���½�
	for (int i = 0; i < 2 * GYBG_UpDown_Time + 3 * FYP_ActionTime - 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//���²���
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

	
	//**********�����̶���
	//�޶���


	//*********P01��ϴ�ö���
	//�ȴ�ǰ�������
	Code_Row = 4;
	CodeLength = 0;
	for (int i = 0; i < 6 * GYBG_UpDown_Time + 2 * GYBG_Move_Time + 2 * GPump_In_Out_Time + 3 * FYP_ActionTime; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	CodeLength--;

	//��ϴ�ڱ�
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + 1; i++)
	{
		CodeLength++;
		if (i==0||i==4)
			code[Code_Row][CodeLength] = GP01_Wash_Inside_Time;
		else
			code[Code_Row][CodeLength] = 77;
	}

	//��ϴ���
	for (int i = 0; i < GP01_Open_WashOutside_Time + 1; i++)
	{
		CodeLength++;
		if (i==0)
			code[Code_Row][CodeLength] = GP01_Wash_Outside_Time;
		else
			code[Code_Row][CodeLength] = 77;
	}


	//*********V01������
	Code_Row = 5;
	CodeLength = 0;
	//�ȴ�ǰ�������
	for (int i = 0; i < 6 * GYBG_UpDown_Time + 2 * GYBG_Move_Time + 2 * GPump_In_Out_Time + 3 * FYP_ActionTime - 1; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}
	
	//����
	code[Code_Row][CodeLength] = V01_Power_On;

	//�ȴ���ϴ���
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//�ط�
	CodeLength++;
	code[Code_Row][CodeLength] = V01_Power_Off;


	//**********V02������
	Code_Row = 6;
	CodeLength = 0;
	//�ȴ�ǰ����
	for (int i = 0; i < 6 * GYBG_UpDown_Time + 2 * GYBG_Move_Time + 2 * GPump_In_Out_Time + 3 * FYP_ActionTime - 1; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}

	//����
	code[Code_Row][CodeLength] = V02_Power_On;

	//�ȴ��ڱ���ϴ���
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//�ط�
	CodeLength++;
	code[Code_Row][CodeLength] = V02_Power_Off;

	//�ȴ������ϴ���
	for (int i = 0; i < GP01_Open_WashOutside_Time + 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}


	//*********V04������
	Code_Row = 7;
	CodeLength = 0;
	//�ȴ�ǰ�������
	for (int i = 0; i < 6 * GYBG_UpDown_Time + 2 * GYBG_Move_Time + 2 * GPump_In_Out_Time + 3 * FYP_ActionTime - 1; i++)
	{
		code[Code_Row][CodeLength] = 77;
		CodeLength++;
	}

	//����
	code[Code_Row][CodeLength] = V04_Power_On;

	//�ȴ���ϴ���
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 1; i++)
	{
		CodeLength++;
		code[Code_Row][CodeLength] = 77;
	}

	//�ط�
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

	//************8�����˶���
	code_length = 0;
	Code_Row = 0;
	//�ȴ�������̧��
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		code[Code_Row][code_length] = 77;
		code_length++;
	}
	code_length--;

	//������ȥ������λ
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

	//�ȴ����½�,����,��̧��
	for (int i = 0; i < 2 * GYBG_UpDown_Time + GYBG_Move_Time; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}


	//*********�����붯��
	code_length = 0;
	Code_Row = 1;
	//������̧��
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		code[Code_Row][code_length] = YBZ_ReSet;
		code_length++;
	}
	code[Code_Row][code_length] = 88;

	//�ȴ�������ת��������λ
	for (int i = 0; i < GYBG_Move_Time - 1; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}

	//���½�������
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

	//�ȴ���������
	for (int i = 0; i < GPump_In_Out_Time - 1; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}

	//��̧��
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

	//SGMA�ö���
	Code_Row = 2;
	code_length = 0;
	code[Code_Row][code_length] = 1;
	//�ȴ���̧��,��ת��,���½�
	for (int i = 0; i < 2 * GYBG_UpDown_Time + GYBG_Move_Time - 1; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}

	//��������
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

	//�ȴ���̧��
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
	//**********�����˶���
	Code_Row = 0;
	code_length = 0;
	//�ȴ����½�,����,��̧��
	for (int i = 0; i < 2 * GYBG_UpDown_Time + GYBG_Move_Time; i++)
	{
		code[Code_Row][code_length] = 77;
		code_length++;
	}
	code_length--;

	//ת������ϴλ
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


	//********�����붯��
	code_length = 0;
	Code_Row = 1;
	//���½�
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		if (i==0)
			code[Code_Row][code_length] = YBZ_Down_Spit_Sample;
		else
			code[Code_Row][code_length] = 77;
		code_length++;
	}
	code[Code_Row][code_length] = 88;

	//�ȴ�����
	for (int i = 0; i < GPump_In_Out_Time - 1; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}

	//��̧��
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

	//�ȴ�������ת����ϴλ
	for (int i = 0; i < GYBG_Move_Time - 1; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}

	//���½�
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

	//�ȴ���ϴ���
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 1; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}

	
	//*********SGMA�ö���
	Code_Row = 2;
	code_length = 0;
	//�ȴ����½�
	for (int i = 0; i < GYBG_UpDown_Time; i++)
	{
		code[Code_Row][code_length] = 77;
		code_length++;
	}
	code_length--;

	//����
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


	//*******P01�ö���
	Code_Row = 4;
	code_length = 0;
	//�ȴ�ǰ�������
	for (int i = 0; i < 3 * GYBG_UpDown_Time + GPump_In_Out_Time + GYBG_Move_Time; i++)
	{
		code[Code_Row][code_length] = 77;
		code_length++;
	}
	code_length--;

	//��ϴ�ڱ�
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + 1; i++)
	{
		code_length++;
		if (i==0||i==4)
			code[Code_Row][code_length] = GP01_Wash_Inside_Time;
		else
			code[Code_Row][code_length] = 77;
	}

	//��ϴ���
	for (int i = 0; i < GP01_Open_WashOutside_Time + 1; i++)
	{
		code_length++;
		if (i == 0)
			code[Code_Row][code_length] = GP01_Wash_Outside_Time;
		else
			code[Code_Row][code_length] = 77;
	}


	//*********V01������
	Code_Row = 5;
	code_length = 0;
	//�ȴ�ǰ�������
	for (int i = 0; i < 3 * GYBG_UpDown_Time + GPump_In_Out_Time + GYBG_Move_Time - 1; i++)
	{
		code[Code_Row][code_length] = 77;
		code_length++;
	}
	
	//����
	code[Code_Row][code_length] = V01_Power_On;

	//�ȴ���ϴ���
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 1; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}
	//�ط�
	code_length++;
	code[Code_Row][code_length] = V01_Power_Off;


	//**********V02������
	Code_Row = 6;
	code_length = 0;
	//�ȴ�ǰ�������
	for (int i = 0; i < 3 * GYBG_UpDown_Time + GPump_In_Out_Time + GYBG_Move_Time - 1; i++)
	{
		code[Code_Row][code_length] = 77;
		code_length++;
	}

	//����
	code[Code_Row][code_length] = V02_Power_On;

	//�ȴ���ϴ�ڱ����
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}

	//�ط�����
	code_length++;
	code[Code_Row][code_length] = V02_Power_Off;

	//�ȴ���ϴ������
	for (int i = 0; i < GP01_Open_WashOutside_Time + 1; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}


	//************V04������
	Code_Row = 7;
	code_length = 0;
	//�ȴ�ǰ�������
	for (int i = 0; i < 3 * GYBG_UpDown_Time + GPump_In_Out_Time + GYBG_Move_Time - 1; i++)
	{
		code[Code_Row][code_length] = 77;
		code_length++;
	}

	//����
	code[Code_Row][code_length] = V04_Power_On;

	//�ȴ���ϴ���
	for (int i = 0; i < 2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 1; i++)
	{
		code_length++;
		code[Code_Row][code_length] = 77;
	}

	//�ط�
	code_length++;
	code[Code_Row][code_length] = V04_Power_Off;

	code_length = code_length + 1;
	return 0;
}