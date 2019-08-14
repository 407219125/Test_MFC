

#pragma once
class BloodSamole
{
public:
	BloodSamole();
	~BloodSamole();
	int YBG_Move_Time ;            //样本杆转动时间
	int YBG_UpDown_Time ;          //样本针Z时间
	int Pump_In_Out_Time ;         //泵吸吐时间
	int YBP_Rotary_Movement_Time ; //样本盘转动时间
	int Code_Row;                  //代码行数
	int MixCode_Row;       //打发士大夫会离开
	int P01_Wash_Inside_Time ;     //P01泵清洗内壁时间
	int P01_Wash_Outside_Time ;    //P01泵清洗外壁时间
	int PutSampleToFYPCode(int project, int SampleNO, int(&code)[8][100], int& CodeLength);
	int MixCode(int(&code)[8][100], int& CodeLength);
	int GetSampleFromCupCode(int project, int(&code)[8][100], int& CodeLength);
	int GetSampleFromFYPCode(int sample_volum, int(&code)[8][100], int& code_length);
	int GetSampleFromFYP_back_Code(int(&code)[8][100], int& code_length);
private:

};

