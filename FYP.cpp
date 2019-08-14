#include "stdafx.h"
#include "FYP.h"
#include "GlobalVariableState.h"


/*
要查找安排工作量最少的那个孔位
opposit_time:startusetime至能够使用孔位时间的差值
startusetime:开始使用的时间
emptyholeNO:孵育盘空闲位置的编号
xy:总的时间规划表
*/
int FYP::getemptyholeNO(int& opposit_time, int startusetime, int(&xy)[70][100000])
{
	int num[10] = { 0 };          //记录所有孔位为空的最初时间
	for(int i=0;i<10;i++)
	{
		num[i] = 99999;
	} 
	
	int temp = 99999;              //中间位置，记录当前最小的时间
	int min_hole;                 //记录当前最小时间的孔位编号
	for (int i = 36; i < 46; i++)  //寻找所有孔位全0位置,并记录全零位置的开始时间。 36为孔位起始， 45表示孔位在总表中的位置
	{
		for (int j = 99999; j >= startusetime; j--)
		{
			if (xy[i][j] != 0 || j == startusetime)
			{
				num[i - 36] = j; //j正好是不为零的时刻，那么j+1就是第一个为0的时刻
				break; 
			}
		}
	}
	//遍历循环10个孔位，找出安排任务最少，即开始时间最早的孔位
	for (int i = 0; i < 10; i++)
	{
		if (num[i] < temp)
		{
			temp = num[i];
			min_hole = i + 1;  //记录当前最小的空位号
		}
	}
	opposit_time = temp - startusetime;
	return min_hole;
}

/*
needholeNO:对孵育盘电机进行操作的孔位
ischangecupposition:需要进行哪种操作：1取放耗材操作；2加试剂、血样操作
statytime:进行操作的滞留时间
length:生成的操作码的数组长度
code:给定需要操作的数组
孵育盘旋转电机在总表里面占第12行位置
*/
void FYP::createcode(int needholeNO, int ischangecupposition, int StayTime, int& length, int(&code)[50])
{
	int num = 0; //用于记录用了数组多大的长度
	if (ischangecupposition == QuYang)  //取样操作
	{
		code[num] = PianYi + needholeNO - 1;  num += 1;
		
		code[num] = Flag;      num += 1;
		//孵育盘转动到1号孔位花费的时间。经测试 FYPActionTime = 2s正好
		for (int i = 0; i < FYPActionTime; i++)
		{
			code[num] = ZhanWei;
			num += 1;
		}

		//孵育盘在1号孔位停留的时间
		for (int i = 0; i < StayTime; i++)
		{
			code[num] = ZhanWei;
			num += 1;
		}
		code[num] = Reset;  num += 1;
		code[num] = Flag;   num += 1;
		length = num;

	}
	else if (ischangecupposition == JiaShiJi)  //加试剂操作
	{
		if (needholeNO < 7)
		{
			code[num] = PianYi + needholeNO + 3;
			num += 1;
		}
		else
		{
			code[num] = PianYi + needholeNO - 7;
			num += 1;
		}
		code[num] = Flag;  num += 1;

		//孵育盘转动到5号孔位花费的时间
		for (int i = 0; i < FYPActionTime; i++)
		{
			code[num] = ZhanWei;
			num += 1;
		}

		//孵育盘在5号孔位停留的时间
		for (int i = 0; i < StayTime; i++)
		{
			code[num] = ZhanWei;
			num += 1;
		}
		code[num] = Reset;  num += 1;
		code[num] = Flag;   num += 1;
		length = num;
	}
}

