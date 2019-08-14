

#pragma once
class BJ
{
public:
	BJ();
	~BJ();
	int iniBJ();
	int ComputeCurrentCupPosition();    //计算当前杯子位置
	int GetCup();                       //取杯
	int BJmovnextrow(int(&Code)[10]);   //杯架换行
	int BJ_Move_Next_Row_Time;          //杯架换行时间

	int BJRestoration(int(&Code)[10]);  //杯架复位
	int BJ_Restoration_Time;            //杯架复位时间

	int BJToOutputPlace(int(&Code)[10]);//杯架去换杯架位
	int BJ_To_Output_Place_Time;        //杯架移动到换杯架位时间
	int BJ_Content[9][7];               //杯架数组
	int BJ_Current_Row;
	int BJ_Rows;
	int BJ_cols;
	int Current_Cup_position_Row;
	int Current_Cup_position_Col;
	int Remian_Cup_Numbers;


private:
	

};

