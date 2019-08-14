
#include "stdafx.h"
#include "BJ.h"
#include "iostream"
#include <string>
#include <fstream>
#include "GlobalVariableState.h"

using namespace std;

BJ::BJ() :BJ_Move_Next_Row_Time(GBJ_Move_Next_Row_Time), BJ_Restoration_Time(GBJ_Restoration_Time), BJ_To_Output_Place_Time(GBJ_To_Output_Place_Time),
BJ_Rows(GBJ_Rows), BJ_cols(GBJ_cols), BJ_Current_Row(GBJ_Current_Row), Current_Cup_position_Row(GCurrent_Cup_position_Row),
Current_Cup_position_Col(GCurrent_Cup_position_Col), Remian_Cup_Numbers(GRemian_Cup_Numbers)
{
}


BJ::~BJ()
{
}



int BJ::iniBJ()
{
	for (int i = 0; i<9; i++)
	{
		for (int j = 0; j<7; j++)
		{
			BJ_Content[i][j] = 1;
		}
	}
	BJ_Current_Row = 0;
	BJ_Rows = 9;
	BJ_cols = 7;
	GCurrent_Cup_position_Row = 0;
	GCurrent_Cup_position_Col = 6;
	GRemian_Cup_Numbers = 63;
	return 0;
}

//取杯函数
int BJ::GetCup()
{
	//先获取当前杯子位置
	int Get_Cup_Position = ComputeCurrentCupPosition();
	if (Get_Cup_Position != -1)
	{
		//取杯
		BJ_Content[Current_Cup_position_Row][Current_Cup_position_Col] = 0;

		//更新当前杯架状态
		if (Current_Cup_position_Row <= 8 && Current_Cup_position_Col > 0)
		{
			Current_Cup_position_Col--;
			GRemian_Cup_Numbers--;
		}
		else if (Current_Cup_position_Row < 8 && Current_Cup_position_Col == 0)
		{

			Current_Cup_position_Row++;
			Current_Cup_position_Col = 6;
			GRemian_Cup_Numbers--;   //需要换行
		}
		else
		{
			GCurrent_Cup_position_Row = 0;
			GCurrent_Cup_position_Col = 6;
			GRemian_Cup_Numbers = 63;   //需要换杯架
		}
		return 1;
	}
	else
		return 0;  //出错,没换杯架
}


//获取当前杯子位置
int BJ::ComputeCurrentCupPosition()
{
	for (int i = 0; i < GBJ_Rows; i++)
	{
		for (int j = GBJ_cols - 1; j >= 0; j--)
		{
			if (GBJ_Content[i][j]==1)
			{
				GCurrent_Cup_position_Row = i;
				GCurrent_Cup_position_Col = j;
				return j;
			}
			if (GBJ_Content[GBJ_Rows-1][0]==0)
			{
				return -1;
			}
		}

	}
	return 0;
}


//杯架换行,代表第7行
int BJ::BJmovnextrow(int(&Code)[10])
{
	int CodeLength;
	CodeLength = 0;
	Code[CodeLength] = 129;

	for (int i = 0; i < BJ_Move_Next_Row_Time-1; i++)
	{
		CodeLength++;
		Code[CodeLength] = 77;
	}

	CodeLength++;
	Code[CodeLength] = 88;
	CodeLength++;
	return CodeLength;
}


//杯架复位,代表第7行
int BJ::BJRestoration(int(&Code)[10])
{
	int CodeLength;
	CodeLength = 0;
	Code[CodeLength] = 55;

	for (int i = 0; i < BJ_Restoration_Time - 1; i++)
	{
		CodeLength++;
		Code[CodeLength] = 77;
	}

	CodeLength++;
	Code[CodeLength] = 88;

	CodeLength++;
	return CodeLength;
}


//杯架去换杯位,代表第7行
int BJ::BJToOutputPlace(int(&Code)[10])
{
	int CodeLength;
	CodeLength = 0;
	Code[CodeLength] = 197;

	for (int i = 0; i < BJ_To_Output_Place_Time - 1; i++)
	{
		CodeLength++;
		Code[CodeLength] = 77;
	}

	CodeLength++;
	Code[CodeLength] = 88;

	CodeLength++;
	return CodeLength;
}