#include "stdafx.h"
#include "DDW.h"
#include "GlobalVariableState.h"


//�ȴ�λ�ܹ�������������λ, ���ǲ��ҿ��п�λ�Ĳ���
//Ѱ��ȫ0λ��, 46Ϊ��λ��ʼ�� 48��ʾ��λ���ܱ��е�λ��
/*
opposit_time:startusetime���ܹ�ʹ�ÿ�λʱ��Ĳ�ֵ
startusetime:��ʼʹ��ʱ��
xy:�ܱ�
return: ���ؿ��п�λ�ı��1��2��3��0��ʾû�п��п�λ
*/
int DDW::GetemptyholeNO(int& opposit_time, int startusetime, int(&xy)[70][100000])
{
	int sum = 0;                     //���ڲ��ң����Բ��λ�ġ�
	int num_1[3] = { 0 };            //��¼ȫ0���п�λΪ�յ����ʱ��
	int num_2[3] = { 99999, 99999, 99999 };   //��¼�������п�λΪ�յ����ʱ��
	int temp_1 = 99999;               //�м�λ�ã���¼ȫ0��ǰ��С��ʱ��
	int temp_2 = 99999;               //�м�λ�ã���¼���뵱ǰ��С��ʱ��
	int min_hole_1;                  //��¼ȫ0��ǰ��Сʱ��Ŀ�λ���
	int min_hole_2;                  //��¼���뵱ǰ��Сʱ��Ŀ�λ���
	for (int i = 46; i < 49; i++)    //Ѱ�����п�λȫ0λ��,����¼ȫ��λ�õĿ�ʼʱ�䡣 46Ϊ��λ��ʼ�� 48��ʾ��λ���ܱ��е�λ��
	{
		for (int j = 99999; j >= startusetime; j--)
		{
			if (xy[i][j] != 0 || j==startusetime)
			{
				num_1[i - 46] = j; //j�����ǲ�Ϊ���ʱ�̣���ôj+1���ǵ�һ��Ϊ0��ʱ��
				break;
			}
		}
	}
	//����ѭ��3����λ���ҳ������������٣�����ʼʱ������Ŀ�λ
	for (int i = 0; i < 3; i++)
	{
		if (num_1[i] < temp_1)
		{
			temp_1 = num_1[i];
			min_hole_1 = i + 1;  //��¼��ǰ��С�Ŀ�λ��
		}
	}


	//����Ѱ�Ҳ������Сʱ��
	for (int i = 46; i < 49; i++)  //Ѱ�����п�λȫ0λ��,����¼ȫ��λ�õĿ�ʼʱ�䡣 46Ϊ��λ��ʼ�� 48��ʾ��λ���ܱ��е�λ��
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


	//����ѭ��3����λ���ҳ������������٣�����ʼʱ������Ŀ�λ
	for (int i = 0; i < 3; i++)
	{
		if (num_2[i] < temp_2)
		{
			temp_2 = num_2[i];
			min_hole_2 = i + 1;  //��¼��ǰ��С�Ŀ�λ��
		}
	}

	//�ж�ʹ��ȫ0��λ�ã�����ʹ�ò�׵ķ�ʽ
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
�˷��������ڵȴ�λȡ���źĲĶ��𵴵�����п��ơ�ȡ�źĲ�ʱ����Ҫ�رյ������ֹ�Լ�צ���и���
WorkTime:�ȴ�λ����𶯹���ʱ��
length: ���ɵ������г���
code:���ɵ�������
return:��
*/
void DDW::CreatCode(int WorkTime, int& length, int(&code)[200])
{
	int num = 0;
	code[num] = Reset;  num += 1;//�رյ��  
	//code[num] = Flag; num += 1; //��־λ
	//�ػ�������ȴ�StayTimʱ��
	for (int i = 0; i < StayTime; i++)
	{
		code[num] = ZhanWeiFu;
		num += 1;
	}
	//�����������ʼ��
	code[num] = Start;  num += 1;
	//code[num] = Flag;   num += 1;

	for (int i = 0; i < WorkTime; i++)
	{
		code[num] = ZhanWeiFu;
		num += 1;
	}
	
	length = num; 
}


