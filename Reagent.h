#pragma once
class Reagent
{
public:
	Reagent();
	~Reagent();
	int SJG_Move_Time ;               //�Լ���ת��ʱ��
	int SJG_UpDown_Time;              //�Լ���Zʱ��
	int Pump_In_Out_Time;             //������ʱ��
	int SJP_Rotary_Movement_Time;     //�Լ���ת��ʱ��
	int Reagent_Code_Row;             //��������
	int SJG_Rotary_Angle;             //�Լ���ת���Ƕ�
	int SJP_Rotary_Place;             //�Լ���ת��λ��
	int SJG_Attenuation_Angle;        //�Լ���ϡ�ͽǶ�
	int P01_Wash_Inside_Time ;        //P01��ϴ�ڱ�ʱ��
	int P01_Wash_Outside_Time ;       //P01��ϴ���ʱ��
	int PutReagentToFYPcode(int project, int Reagent_Bin_NO, int Reagent_Location_NO, int(&code)[8][100], int &codelength);
};

