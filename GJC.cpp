#include "stdafx.h"
#include "GJC.h"
#include "GlobalVariableState.h"

/*
进入后前6s不测值，然后从第7s~第36s采光
伺服电机有三个位置，第一个位置夹紧位01，第二个位置为放入位02，第三个位置为丢弃位03
WorkTime:光检测工作时间,形参里面的work_time已经没用了，但是为了保证接口不变，就保留了
mission_NO: 进行光检测的类别
length：使用了数组多大长度
code[2][50]：用于输出光检测移动电机以及光控开关的控制命令
code[0][50]:第一行，即0，表示的是移动电机的控制命令
code[1][50]:第二行，即1，表示的是光控开关的控制命令。从电机停止运动后,第7秒开启光控开关发送2，持续10s，最后发送3关闭光检测
code[2][50]:第三行，即2，表示的是任务号，是数组第一个数
生成的指令长度是43,
*/
void GJC::createcode(int work_time, int mission_NO, int &length, int(&code)[3][50])
{
	int Work_time = 36;          //光检测工作时间
	int GJC_open_time;           //光检测开关开始的时刻
	//下面是运动电机的控制命令
	int num = 0;					    //用于记录使用了code数组的长度
	code[0][num] = Second;  num += 1;   //先从第一位置移动到第二位置
	//code[0][num] = Flag;    num += 1;

	//需要等待的时间
	for (int i = 0; i < StayTime; i++)
	{
		code[0][num] = ZhanWei;
		num += 1;
	}

	code[0][num] = Reset;  num += 1;   //从第二位置移动到第一位置
	//code[0][num] = Flag;   num += 1;

	//这里表示移动电机已经复位，到达可以开始光检测的时刻
	GJC_open_time = num;

	//开始进行光检测过程
	for (int i = 0; i < Work_time; i++)
	{
		code[0][num] = ZhanWei;
		num += 1;
	}

	code[0][num] = Third; num += 1;  //丢杯需要到达的位置
	code[0][num] = ZhanWei;  num += 1;


	code[0][num] = Reset; num += 1;  //回到初始位置
	//code[0][num] = Flag;  num += 1;
	length = num;                    //返回代码的长度


	//下面是光控开关的控制命令
	//加7是因为要在电机停止运动7秒后开始进行光检测
	for (int i = 0; i < num; i++)
	{
		if (i == GJC_open_time + 6)
		{
			for (int j = 0; j < 10; j++)
			{

				code[1][i] = 2;		//2号位是开启光检测位置
				i += 1;
			}
			//code[1][i] = mission_NO;
			i -= 1;
		}
		else if (i == num - 1) code[1][i] = 3;   //3号位是关闭光检测的位置
		else code[1][i] = ZhanWei;

	}




	//下面是任务号的命令
	code[2][0] = mission_NO;

}

/*
&opposit_time:     startusetime至能够使用孔位时刻差多长时间
startusetime:      这个孔位打算从什么时刻开始用
(&xy)[70][10000]   引用xy总表进行查找
*/
void GJC::getemptyholeNO(int& opposit_time, int startusetime, int(&xy)[70][10000])
{
	int StayTime = 40;        //光检测时，加上放杯时间，杯子在孔里差不多待40s
	int temp_1 = 9999;
	int temp_2 = 9999;
	int sum = 0;
	//光检测在总表里面第49行
	for (int j = 9999; j >= startusetime; j--)
	{
		if (xy[49][j] != 0 || j == startusetime)
		{
			temp_1 = j;
		}
	}

	for (int i = startusetime; i <= temp_1; i++)
	{
		if (xy[49][i] == 0 && xy[49][i + StayTime] == 0)
		{
			for (int j = i; j < i + StayTime; j++)
			{
				sum += xy[49][j];
			}
			if (sum == 0)
			{
				temp_2 = i;
				break;
			}
			else sum = 0;
		}
	}
	if (temp_2 < temp_1)
	{
		opposit_time = temp_2 - startusetime;
	}
	else
	{
		opposit_time = temp_1 - startusetime;
	}

}

void GJC::db_createcode(int &length, int(&code)[50])
{
	//下面是运动电机的控制命令
	int num = 0;					    //用于记录使用了code数组的长度
	code[num] = 2;  num += 1;   //先从第一位置移动到第二位置

								//需要等待的时间3s
	for (int i = 0; i < 3; i++)
	{
		code[num] = 77;
		num += 1;
	}

	code[num] = 3;  num += 1;   //从第二位置移动到第3位置丢杯
								//需要等待丢杯的时间2s
	for (int i = 0; i < 2; i++)
	{
		code[num] = 77;
		num += 1;
	}

	code[num] = 55; num += 1;  //丢杯需要到达的位置
	length = num;                    //返回代码的长度

}

