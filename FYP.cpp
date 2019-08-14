#include "stdafx.h"
#include "FYP.h"
#include "GlobalVariableState.h"


/*
Ҫ���Ұ��Ź��������ٵ��Ǹ���λ
opposit_time:startusetime���ܹ�ʹ�ÿ�λʱ��Ĳ�ֵ
startusetime:��ʼʹ�õ�ʱ��
emptyholeNO:�����̿���λ�õı��
xy:�ܵ�ʱ��滮��
*/
int FYP::getemptyholeNO(int& opposit_time, int startusetime, int(&xy)[70][100000])
{
	int num[10] = { 0 };          //��¼���п�λΪ�յ����ʱ��
	for(int i=0;i<10;i++)
	{
		num[i] = 99999;
	} 
	
	int temp = 99999;              //�м�λ�ã���¼��ǰ��С��ʱ��
	int min_hole;                 //��¼��ǰ��Сʱ��Ŀ�λ���
	for (int i = 36; i < 46; i++)  //Ѱ�����п�λȫ0λ��,����¼ȫ��λ�õĿ�ʼʱ�䡣 36Ϊ��λ��ʼ�� 45��ʾ��λ���ܱ��е�λ��
	{
		for (int j = 99999; j >= startusetime; j--)
		{
			if (xy[i][j] != 0 || j == startusetime)
			{
				num[i - 36] = j; //j�����ǲ�Ϊ���ʱ�̣���ôj+1���ǵ�һ��Ϊ0��ʱ��
				break; 
			}
		}
	}
	//����ѭ��10����λ���ҳ������������٣�����ʼʱ������Ŀ�λ
	for (int i = 0; i < 10; i++)
	{
		if (num[i] < temp)
		{
			temp = num[i];
			min_hole = i + 1;  //��¼��ǰ��С�Ŀ�λ��
		}
	}
	opposit_time = temp - startusetime;
	return min_hole;
}

/*
needholeNO:�Է����̵�����в����Ŀ�λ
ischangecupposition:��Ҫ�������ֲ�����1ȡ�źĲĲ�����2���Լ���Ѫ������
statytime:���в���������ʱ��
length:���ɵĲ���������鳤��
code:������Ҫ����������
��������ת������ܱ�����ռ��12��λ��
*/
void FYP::createcode(int needholeNO, int ischangecupposition, int StayTime, int& length, int(&code)[50])
{
	int num = 0; //���ڼ�¼����������ĳ���
	if (ischangecupposition == QuYang)  //ȡ������
	{
		code[num] = PianYi + needholeNO - 1;  num += 1;
		
		code[num] = Flag;      num += 1;
		//������ת����1�ſ�λ���ѵ�ʱ�䡣������ FYPActionTime = 2s����
		for (int i = 0; i < FYPActionTime; i++)
		{
			code[num] = ZhanWei;
			num += 1;
		}

		//��������1�ſ�λͣ����ʱ��
		for (int i = 0; i < StayTime; i++)
		{
			code[num] = ZhanWei;
			num += 1;
		}
		code[num] = Reset;  num += 1;
		code[num] = Flag;   num += 1;
		length = num;

	}
	else if (ischangecupposition == JiaShiJi)  //���Լ�����
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

		//������ת����5�ſ�λ���ѵ�ʱ��
		for (int i = 0; i < FYPActionTime; i++)
		{
			code[num] = ZhanWei;
			num += 1;
		}

		//��������5�ſ�λͣ����ʱ��
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

