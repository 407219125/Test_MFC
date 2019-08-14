#pragma once
class Reagent
{
public:
	Reagent();
	~Reagent();
	int SJG_Move_Time ;               //试剂杆转动时间
	int SJG_UpDown_Time;              //试剂针Z时间
	int Pump_In_Out_Time;             //泵吸吐时间
	int SJP_Rotary_Movement_Time;     //试剂盘转动时间
	int Reagent_Code_Row;             //代码行数
	int SJG_Rotary_Angle;             //试剂杆转动角度
	int SJP_Rotary_Place;             //试剂盘转动位置
	int SJG_Attenuation_Angle;        //试剂杆稀释角度
	int P01_Wash_Inside_Time ;        //P01清洗内壁时间
	int P01_Wash_Outside_Time ;       //P01清洗外壁时间
	int PutReagentToFYPcode(int project, int Reagent_Bin_NO, int Reagent_Location_NO, int(&code)[8][100], int &codelength);
};

