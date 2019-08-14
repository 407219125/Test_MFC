#include "stdafx.h"
#include "ADD_CODE.h"
#include "GlobalVariableState.h"


ADD_CODE::ADD_CODE()
{
}


ADD_CODE::~ADD_CODE()
{
}



int ADD_CODE::add_BJ_move_code(int starttime, int code_length, int code[10])
{
	int time = starttime + jz_downtime + jz_opentime + jz_uptime + jz_movetime;
	for (int j = 0; j < code_length; j++)
		xy[8][j + time] = code[j];
	return 0;
}

int ADD_CODE::add_SJ_code(int starttime, int code_length, int code[8][100])
{
	int time = code_length - (2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 3);
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < code_length; i++)
		{
			if (j == 0)
				xy[2][i + starttime] = code[j][i];
			else if (j == 1)
				xy[3][i + starttime] = code[j][i];
			else if (j == 2)
				xy[18][i + starttime] = code[j][i];
			else if (j == 3)
				xy[1][i + starttime] = code[j][i];
			else if (j == 4)
			{
				if (i + time < code_length)
					xy[21][i + starttime + time] = code[j][i + time];
				else
					break;
			}
			else if (j == 5)
			{
				if (i + time < code_length)
					xy[27][i + starttime + time] = code[j][i + time];
				else
					break;
			}
			else if (j == 6)
				xy[30][i + starttime] = code[j][i];
			else if (j == 7)
				xy[32][i + starttime] = code[j][i];
		}
	}
	return 0;
}

int ADD_CODE::add_sample_code(int starttime, int code_length, int code[8][100])
{
	int time = code_length - (2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 3);
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < code_length; i++)
		{
			if (j == 0)
				xy[5][i + starttime] = code[j][i];
			else if (j == 1)
				xy[4][i + starttime] = code[j][i];
			else if (j == 2)
				xy[17][i + starttime] = code[j][i];
			else if (j == 3)
				xy[6][i + starttime] = code[j][i];
			else if (j == 4)
			{
				if (i + time < code_length)
					xy[21][i + starttime + time] = code[j][i + time];
				else
					break;
			}
			else if (j == 5)
			{
				if (i + time < code_length)
					xy[27][i + starttime + time] = code[j][i + time];
				else
					break;
			}
			else if (j == 6)
				xy[20][i + starttime] = code[j][i];
			else if (j == 7)
				xy[31][i + starttime] = code[j][i];
		}
	}
	return 0;
}

int ADD_CODE::add_sample_from_fyp_code(int starttime, int code_length, int code[8][100])
{
	int time = code_length - (2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 3);
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < code_length; i++)
		{
			if (j == 0)
				xy[5][i + starttime] = code[j][i];
			else if (j == 1)
				xy[4][i + starttime] = code[j][i];
			else if (j == 2)
				xy[17][i + starttime] = code[j][i];
			else if (j == 3)
				xy[6][i + starttime] = code[j][i];
			else if (j == 4)
			{
				if (i + time < code_length)
					xy[21][i + starttime + time] = code[j][i + time];
				else
					break;
			}
			else if (j == 5)
			{
				if (i + time < code_length)
					xy[27][i + starttime + time] = code[j][i + time];
				else
					break;
			}
			else if (j == 6)
				xy[20][i + starttime] = code[j][i];
			else if (j == 7)
				xy[31][i + starttime] = code[j][i];
		}
	}
	return 0;
}

int ADD_CODE::add_mix_code(int starttime, int code_length, int code[8][100])
{
	int time = code_length - (2 * GP01_Open_WashInside_Time + GP01_Open_WashOutside_Time + 3);
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < code_length; i++)
		{
			if (j == 0)
				xy[5][i + starttime] = code[j][i];
			else if (j == 1)
				xy[4][i + starttime] = code[j][i];
			else if (j == 2)
				xy[17][i + starttime] = code[j][i];
			else if (j == 3)
				xy[6][i + starttime] = code[j][i];
			else if (j == 4)
			{
				if (i + time < code_length)
					xy[21][i + starttime + time] = code[j][i + time];
				else
					break;
			}
			else if (j == 5)
			{
				if (i + time < code_length)
					xy[27][i + starttime + time] = code[j][i + time];
				else
					break;
			}
			else if (j == 6)
				xy[20][i + starttime] = code[j][i];
			else if (j == 7)
				xy[31][i + starttime] = code[j][i];
		}
	}
	return 0;
}

int ADD_CODE::add_JZ_move_code(int starttime, int code_length, int code[3][100])
{
	for (int i = 0; i < 3; i++)
	{
		int time = starttime;
		switch (i)
		{
		case 0:
			for (int j = 0; j < code_length; j++)
			{
				xy[9][time] = code[i][j];
				time++;
			}
			break;
		case 1:
			for (int j = 0; j < code_length; j++)
			{
				xy[10][time] = code[i][j];
				time++;
			}
			break;
		case 2:
			for (int j = 0; j < code_length; j++)
			{
				xy[11][time] = code[i][j];
				time++;
			}
			break;
		default:
			break;
		}
	}
	return 0;
}

int ADD_CODE::add_CFL_move_code(int endtime, int step_time)
{
	int cnt = 0;
	while (cnt < endtime&&cnt < 100000 - step_time)
	{
		for (int t = 0; t < 12; t++)//一圈转12次
		{
			if (t == 0)
			{
				for (int i = 0; i < cfl_CFLcycletime; i++)
				{
					if (i == 0)
					{
						xy[13][cnt] = 55;
						cnt++;
					}
					else
					{
						xy[13][cnt] = 77;
						cnt++;
					}
				}
			}
			else
			{
				for (int i = 0; i < cfl_CFLcycletime; i++)
				{
					if (i == 0)
					{
						xy[13][cnt] = 193;
						cnt++;
					}
					else
					{
						xy[13][cnt] = 77;
						cnt++;
					}
				}
			}
			for (int i = 0; i < step_time - cfl_CFLcycletime; i++)
			{
				if (i == 0)
				{
					xy[13][cnt] = 88;
					cnt++;
				}
				else
				{
					//xy[13][cnt] = 77;
					cnt++;
				}
			}
			if (cnt > endtime)
				break;
		}
	}
	return 0;
}

int ADD_CODE::add_CFL_operation_code(int starttime, int code_length, int code[8][30])
{
	for (int i = 0; i < 8; i++)
	{
		int time = starttime;
		switch (i)
		{
		case 0:
			for (int j = 0; j < code_length; j++)
			{
				if (xy[14][time] == 0)
				{
					xy[14][time] = code[i][j];
				}
				time++;
			}
			break;
		case 1:
			for (int j = 0; j < code_length; j++)
			{
				if (xy[16][time] == 0)
				{
					xy[16][time] = code[i][j];
				}
				time++;
			}
			break;
		case 2:
			for (int j = 0; j < code_length; j++)
			{
				if (xy[19][time] == 0)
				{
					xy[19][time] = code[i][j];
				}
				time++;
			}
			break;
		case 3:
			for (int j = 0; j < code_length; j++)
			{
				if (xy[22][time] == 0)
				{
					xy[22][time] = code[i][j];
				}
				time++;
			}
			break;
		case 4:
			for (int j = 0; j < code_length; j++)
			{
				if (xy[23][time] == 0)
				{
					xy[23][time] = code[i][j];
				}
				time++;
			}
			break;
		case 5:
			for (int j = 0; j < code_length; j++)
			{
				if (xy[24][time] == 0)
				{
					xy[24][time] = code[i][j];
				}
				time++;
			}
			break;
		case 6:
			for (int j = 0; j < code_length; j++)
			{
				if (xy[25][time] == 0)
				{
					xy[25][time] = code[i][j];
				}
				time++;
			}
			break;
		case 7:
			for (int j = 0; j < code_length; j++)
			{
				if (xy[26][time] == 0)
				{
					xy[26][time] = code[i][j];
				}
				time++;
			}
			break;
		default:
			break;
		}
	}
	return 0;
}

int ADD_CODE::add_CFL_hole_occupy(int hole_NO, int starttime, int finishedtime)
{
	for (int i = starttime; i < finishedtime; i++)
		xy[62 - hole_NO][i] = 77;
	return 0;
}


int ADD_CODE::add_FYP_move_code(int starttime, int code_length, int code[50])
{
	//孵育盘旋转电机在总表里面12行
	for (int i = starttime; i < starttime + code_length; i++)
	{
		xy[12][i] = code[i - starttime];
	}
	return 0;
}

int ADD_CODE::add_FYP_hole_occupy(int hole_NO, int starttime, int finishedtime)
{
	//孵育盘孔位在总表里面占36 — 45行。这里用占位符 77 占位
	for (int i = starttime; i < finishedtime; i++)
	{
		xy[hole_NO + 35][i] = 77;
	}
	return 0;
}

int ADD_CODE::add_ZDQ_operation_code(int starttime, int code_length, int code[50])
{
	//振荡器电机在总表里面是 15 行
	for (int i = starttime; i < starttime + code_length; i++)
	{
		xy[15][i] = code[i - starttime];
	}
	return 0;
}

int ADD_CODE::add_ZDQ_hole_occupy(int hole_NO, int starttime, int finishedtime)
{
	//振荡器孔位在总表里面占46 — 48行。这里用占位符 77 占位
	for (int i = starttime; i < finishedtime; i++)
	{
		xy[hole_NO + 45][i] = 77;
	}
	return 0;
}

int ADD_CODE::add_GJC_db_code(int starttime, int code_length, int code[50])
{
	for (int i = starttime; i < starttime + code_length; i++)
	{
		xy[7][i] = code[i - starttime];
	}
	return 0;
}

int ADD_CODE::add_GJC_code(int starttime, int code_length, int code[3][50])
{
	//这个是启动光检测,测光Y方向电机在总表里面是 第7行，对应code[0][50]
	//开始光检测指令在总表里面是 第33行,对应code[1][50]
	for (int i = starttime; i < starttime + code_length; i++)
	{
		xy[7][i] = code[0][i - starttime];
		xy[33][i] = code[1][i - starttime];
	}

	xy[34][starttime] = code[2][0];
	//添加任务号的代码如下。光检测任务号在总表里面第34行。
	//从34行第一个数开始查，如果为0，那么就在此处插入任务号。
	//for (int i = 0; i < 10000; i++)
	//{
	//	if (xy[34][i] == 0)
	//	{
	//		xy[34][i] = code[2][0];   //将任务号赋给xy表对应位置，任务号在code第三行第一列
	//		break;
	//	}
	//}

	return 0;
}

int ADD_CODE::add_GJC_hole_occupy(int starttime, int finishedtime)
{
	//光检测孔号在总表里面为第49行.这里用占位符 77 占位
	for (int i = starttime; i < finishedtime; i++)
	{
		xy[49][i] = 77;
	}

	return 0;
}

void ADD_CODE::add_ZDQ_motor_code()
{
	//生成控制指令
	int motor_code[10] = { 0 };                   //存储指令代码
	int length = 0;                               //指令代码的长度

	motor_code[length] = 55;	   length += 1;   //55电机停止运转。1是电机开始运转
	for (int j = 0; j < 3; j++)                   //停止震动3s
	{
		motor_code[length] = 77;   length += 1;   //77是占位符
	}
	motor_code[length] = 1;		   length += 1;	  //1是电机开始运转




												  //等待位电机插入代码，等待位电机在总表里面第15行。
												  //要在总表里面查询等待位取放杯子的所有时刻。凡是有取放的时刻，等待位电机都要停止运动3s。
	int push_pop_time[500] = { 0 };   //500的数组足够存储所有的取放杯时刻
	int num = 0;
	//46——49是振荡器在总表里面的孔号
	for (int i = 46; i < 49; i++)
	{
		for (int j = 0; j < 99999; j++)
		{
			if (xy[i][j] == 0 && xy[i][j + 1] != 0)
			{
				push_pop_time[num] = j;
				num += 1;
			}
			if (xy[i][j] != 0 && xy[i][j + 1] == 0)
			{
				push_pop_time[num] = j;
				num += 1;
			}
		}
	}

	//对获取的取放杯时刻进行排序，防止出现指令错误覆盖
	//std::sort(push_pop_time, push_pop_time + num);

	//15行是振荡器电机在总表里面 的位置
	for (int i = 0; i < num; i++)
	{
		int start_time = push_pop_time[i];
		for (int j = start_time; j < length + start_time; j++)
		{
			xy[15][j] = motor_code[j - start_time];
		}
	}

}