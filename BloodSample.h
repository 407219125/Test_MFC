

#pragma once
class BloodSamole
{
public:
	BloodSamole();
	~BloodSamole();
	int YBG_Move_Time ;            //������ת��ʱ��
	int YBG_UpDown_Time ;          //������Zʱ��
	int Pump_In_Out_Time ;         //������ʱ��
	int YBP_Rotary_Movement_Time ; //������ת��ʱ��
	int Code_Row;                  //��������
	int MixCode_Row;       //��ʿ�����뿪
	int P01_Wash_Inside_Time ;     //P01����ϴ�ڱ�ʱ��
	int P01_Wash_Outside_Time ;    //P01����ϴ���ʱ��
	int PutSampleToFYPCode(int project, int SampleNO, int(&code)[8][100], int& CodeLength);
	int MixCode(int(&code)[8][100], int& CodeLength);
	int GetSampleFromCupCode(int project, int(&code)[8][100], int& CodeLength);
	int GetSampleFromFYPCode(int sample_volum, int(&code)[8][100], int& code_length);
	int GetSampleFromFYP_back_Code(int(&code)[8][100], int& code_length);
private:

};

