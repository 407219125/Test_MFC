#include "stdafx.h"
#include "GJC.h"
#include "GlobalVariableState.h"

/*
�����ǰ6s����ֵ��Ȼ��ӵ�7s~��36s�ɹ�
�ŷ����������λ�ã���һ��λ�üн�λ01���ڶ���λ��Ϊ����λ02��������λ��Ϊ����λ03
WorkTime:���⹤��ʱ��,�β������work_time�Ѿ�û���ˣ�����Ϊ�˱�֤�ӿڲ��䣬�ͱ�����
mission_NO: ���й�������
length��ʹ���������󳤶�
code[2][50]��������������ƶ�����Լ���ؿ��صĿ�������
code[0][50]:��һ�У���0����ʾ�����ƶ�����Ŀ�������
code[1][50]:�ڶ��У���1����ʾ���ǹ�ؿ��صĿ�������ӵ��ֹͣ�˶���,��7�뿪����ؿ��ط���2������10s�������3�رչ���
code[2][50]:�����У���2����ʾ��������ţ��������һ����
���ɵ�ָ�����43,
*/
void GJC::createcode(int work_time, int mission_NO, int &length, int(&code)[3][50])
{
	int Work_time = 36;          //���⹤��ʱ��
	int GJC_open_time;           //���⿪�ؿ�ʼ��ʱ��
	//�������˶�����Ŀ�������
	int num = 0;					    //���ڼ�¼ʹ����code����ĳ���
	code[0][num] = Second;  num += 1;   //�ȴӵ�һλ���ƶ����ڶ�λ��
	//code[0][num] = Flag;    num += 1;

	//��Ҫ�ȴ���ʱ��
	for (int i = 0; i < StayTime; i++)
	{
		code[0][num] = ZhanWei;
		num += 1;
	}

	code[0][num] = Reset;  num += 1;   //�ӵڶ�λ���ƶ�����һλ��
	//code[0][num] = Flag;   num += 1;

	//�����ʾ�ƶ�����Ѿ���λ��������Կ�ʼ�����ʱ��
	GJC_open_time = num;

	//��ʼ���й������
	for (int i = 0; i < Work_time; i++)
	{
		code[0][num] = ZhanWei;
		num += 1;
	}

	code[0][num] = Third; num += 1;  //������Ҫ�����λ��
	code[0][num] = ZhanWei;  num += 1;


	code[0][num] = Reset; num += 1;  //�ص���ʼλ��
	//code[0][num] = Flag;  num += 1;
	length = num;                    //���ش���ĳ���


	//�����ǹ�ؿ��صĿ�������
	//��7����ΪҪ�ڵ��ֹͣ�˶�7���ʼ���й���
	for (int i = 0; i < num; i++)
	{
		if (i == GJC_open_time + 6)
		{
			for (int j = 0; j < 10; j++)
			{

				code[1][i] = 2;		//2��λ�ǿ�������λ��
				i += 1;
			}
			//code[1][i] = mission_NO;
			i -= 1;
		}
		else if (i == num - 1) code[1][i] = 3;   //3��λ�ǹرչ����λ��
		else code[1][i] = ZhanWei;

	}




	//����������ŵ�����
	code[2][0] = mission_NO;

}

/*
&opposit_time:     startusetime���ܹ�ʹ�ÿ�λʱ�̲�೤ʱ��
startusetime:      �����λ�����ʲôʱ�̿�ʼ��
(&xy)[70][10000]   ����xy�ܱ���в���
*/
void GJC::getemptyholeNO(int& opposit_time, int startusetime, int(&xy)[70][10000])
{
	int StayTime = 40;        //����ʱ�����Ϸű�ʱ�䣬�����ڿ������40s
	int temp_1 = 9999;
	int temp_2 = 9999;
	int sum = 0;
	//�������ܱ������49��
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
	//�������˶�����Ŀ�������
	int num = 0;					    //���ڼ�¼ʹ����code����ĳ���
	code[num] = 2;  num += 1;   //�ȴӵ�һλ���ƶ����ڶ�λ��

								//��Ҫ�ȴ���ʱ��3s
	for (int i = 0; i < 3; i++)
	{
		code[num] = 77;
		num += 1;
	}

	code[num] = 3;  num += 1;   //�ӵڶ�λ���ƶ�����3λ�ö���
								//��Ҫ�ȴ�������ʱ��2s
	for (int i = 0; i < 2; i++)
	{
		code[num] = 77;
		num += 1;
	}

	code[num] = 55; num += 1;  //������Ҫ�����λ��
	length = num;                    //���ش���ĳ���

}

