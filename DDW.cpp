#include "stdafx.h"
#include "DDW.h"
#include "GlobalVariableState.h"


//等待位总共有三个振荡器孔位, 这是查找空闲孔位的操作
//寻找全0位置, 46为孔位起始， 48表示孔位在总表中的位置
/*
opposit_time:startusetime至能够使用孔位时间的差值
startusetime:开始使用时间
xy:总表
return: 返回空闲孔位的编号1、2、3。0表示没有空闲孔位
*/
int DDW::GetemptyholeNO(int& opposit_time, int startusetime, int(&xy)[70][100000])
{
	int sum = 0;                     //用于查找，可以插孔位的。
	int num_1[3] = { 0 };            //记录全0所有孔位为空的最初时间
	int num_2[3] = { 99999, 99999, 99999 };   //记录插入所有孔位为空的最初时间
	int temp_1 = 99999;               //中间位置，记录全0当前最小的时间
	int temp_2 = 99999;               //中间位置，记录插入当前最小的时间
	int min_hole_1;                  //记录全0当前最小时间的孔位编号
	int min_hole_2;                  //记录插入当前最小时间的孔位编号
	for (int i = 46; i < 49; i++)    //寻找所有孔位全0位置,并记录全零位置的开始时间。 46为孔位起始， 48表示孔位在总表中的位置
	{
		for (int j = 99999; j >= startusetime; j--)
		{
			if (xy[i][j] != 0 || j==startusetime)
			{
				num_1[i - 46] = j; //j正好是不为零的时刻，那么j+1就是第一个为0的时刻
				break;
			}
		}
	}
	//遍历循环3个孔位，找出安排任务最少，即开始时间最早的孔位
	for (int i = 0; i < 3; i++)
	{
		if (num_1[i] < temp_1)
		{
			temp_1 = num_1[i];
			min_hole_1 = i + 1;  //记录当前最小的空位号
		}
	}


	//这里寻找插入的最小时间
	for (int i = 46; i < 49; i++)  //寻找所有孔位全0位置,并记录全零位置的开始时间。 46为孔位起始， 48表示孔位在总表中的位置
	{
		for (int j = startusetime; j <= temp_1; j++)
		{
			if (xy[i][j] == 0 && xy[i][j+DDWWorkTime] == 0)
			{
				for (int a = j; a <= j + DDWWorkTime; a++)
				{
					sum += xy[i][a];
				}
				if (sum != 0) sum = 0;
				else
				{
					num_2[i - 46] = j;
					break;
				}
			}
		}
	}


	//遍历循环3个孔位，找出安排任务最少，即开始时间最早的孔位
	for (int i = 0; i < 3; i++)
	{
		if (num_2[i] < temp_2)
		{
			temp_2 = num_2[i];
			min_hole_2 = i + 1;  //记录当前最小的空位号
		}
	}

	//判断使用全0的位置，还是使用插孔的方式
	if (temp_1 < temp_2)
	{
		opposit_time = temp_1 - startusetime;
		return min_hole_1;
	}
	else
	{
		opposit_time = temp_2 - startusetime;
		return min_hole_2;
	}
}


/*
此方法用于在等待位取、放耗材对震荡电机进行控制。取放耗材时，需要关闭电机，防止对夹爪进行干扰
WorkTime:等待位电机震动工作时间
length: 生成的命令行长度
code:生成的命令行
return:无
*/
void DDW::CreatCode(int WorkTime, int& length, int(&code)[200])
{
	int num = 0;
	code[num] = Reset;  num += 1;//关闭电机  
	//code[num] = Flag; num += 1; //标志位
	//关机电机，等待StayTim时间
	for (int i = 0; i < StayTime; i++)
	{
		code[num] = ZhanWeiFu;
		num += 1;
	}
	//开启电机，开始震动
	code[num] = Start;  num += 1;
	//code[num] = Flag;   num += 1;

	for (int i = 0; i < WorkTime; i++)
	{
		code[num] = ZhanWeiFu;
		num += 1;
	}
	
	length = num; 
}


