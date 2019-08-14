#include "stdafx.h"
#include"JZ.h"
#include "GlobalVariableState.h"

//�ֱ��ʾռλ����־�͸�λ�ź�
const int zhanweifu = 77;
const int biaozhifu = 88;
const int fuweifu = 55;

//��������
//1		 2		3	   4	  5		 6		7		8		9		10		11		12		  13
//����1������2������3������4������5������6������7�����飬�����̣��ȴ�λ1���ȴ�λ2���ȴ�λ3���ŷ���

//��צ������ͬ��ָ���ͬ��λ��,���������ֱ��ʾ0��λ��Ҳ�ǳ�ʼλ��~12��λ��ָ���ź�
const int xdianjiposition[13] = { 55,2,3,4,5,6,7,8,9,10,11,12,13 };

//��צ��ͬ��λ���½���һ����2~6�ֱ��ʾ���ֲ�ͬ����λ�õ��½�ָ���źţ��������ø�λ55��ʾ,
const int zdianjidecline[13] = { 2,2,2,2,2,2,2,3,4,5,5,5,6 };
const int jiazhua_upward = fuweifu;

//��צץȡָ��Ϊ��λָ��55,�ſ�ָ��Ϊ02
const int jiazhua_close = 3;
const int jiazhua_open = 2;

//��צ��ʼλ��Ҳ�Ǹ�λλ�ã���1�ű�λ���ص���ָ��Ϊ55
const int init_position = 1;

//�����������λ�õ�������0����xdianji,1����zdianji��2����xuanzhuandianji
enum jiazhua_yundong { jiazhua_xdianji = 0, jiazhua_zdianji = 1, jiazhua_xuanzhuandianji = 2 };

JZ::JZ() :movetime(jz_movetime), opentime(jz_opentime), closetime(jz_closetime), uptime(jz_uptime), downtime(jz_downtime)
{

}

//JZ::JZ() :movetime(2), opentime(1), closetime(1), uptime(1), downtime(1)
//{
//
//}
JZ::~JZ()
{
}


//�ӳ�ʼλ�ÿ�ʼ��from��to�����ص���ʼλ��
//fromstart,fromend,tostart,toend�ֱ𷵻�צ�����²����ϻ�ȥ��ʱ�䣬������¼�������±��ӵ�ʱ��
//��������ֵΪ����ʱ������Ч�ĳ���
//int(&jiazhuacode)[3][100]
//������0�����Ǽб�X����������9�У�,55��ʾһ�ű��ӵ�λ�ã�2~13�ֱ��ʾ��2�ű����ŷ���λ�õ�12��λ�ã�
//������1�����Ǽ�צz����������10�У���11~15�ֱ��ʾ�����ͬ�½�λ�õĲ�������������2��ʾ
//������2�����Ǽ�צ��ת�б����������11�У���01����պϣ�02�����ſ�
//jiazhua��init����fromλ�ã���צ�ſ�,��צ��ȥ����צץȡ����צ��ȥ����צ��fromλ�ý���toλ�ã���צ��ȥ����צ�ſ�����צ��ȥ����צ��toλ���ƶ���initλ��
int JZ::jiazhua_createcode(int from, int to, int(&jiazhuacode)[3][100], int &fromstart, int &fromend, int &tostart, int &toend)
{
	/*assert((from >= 1) && (from <= 13));
	assert((to >= 1) && (to <= 13));
	assert(from != to);
	assert(opentime <= movetime);*/

	int cnt = 0;
	//jiazhua��init����fromλ��
	//jiazhua_position = from;
	for (int i = 0; i < movetime; i++)
	{
		if (i == 0)
		{
			jiazhuacode[jiazhua_xdianji][cnt] = xdianjiposition[from-1];
			jiazhuacode[jiazhua_zdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_xuanzhuandianji][cnt] = zhanweifu;
			cnt++;
		}
		else {
			jiazhuacode[jiazhua_xdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_zdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_xuanzhuandianji][cnt] = zhanweifu;
			cnt++;
		}
	}

	//��צ��ȥ
	fromstart = cnt;
	for (int i = 0; i < downtime; i++)
	{
		if (i == 0)
		{
			jiazhuacode[jiazhua_xdianji][cnt] = biaozhifu;
			jiazhuacode[jiazhua_zdianji][cnt] = zdianjidecline[from-1];
			jiazhuacode[jiazhua_xuanzhuandianji][cnt] = zhanweifu;
			cnt++;
		}
		else
		{
			jiazhuacode[jiazhua_xdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_zdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_xuanzhuandianji][cnt] = zhanweifu;
			cnt++;
		}
	}

	//��צץȡ
	for (int i = 0; i < closetime; i++)
	{
		if (i == 0)
		{
			jiazhuacode[jiazhua_xdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_zdianji][cnt] = biaozhifu;
			jiazhuacode[jiazhua_xuanzhuandianji][cnt] = jiazhua_close;
			cnt++;
		}
		else
		{
			jiazhuacode[jiazhua_xdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_zdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_xuanzhuandianji][cnt] = zhanweifu;
			cnt++;
		}
	}

	//��צ��ȥ
	for (int i = 0; i < uptime; i++)
	{
		if (i == 0)
		{
			jiazhuacode[jiazhua_xdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_zdianji][cnt] = jiazhua_upward;
			jiazhuacode[jiazhua_xuanzhuandianji][cnt] = biaozhifu;
			cnt++;
		}
		else {
			jiazhuacode[jiazhua_xdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_zdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_xuanzhuandianji][cnt] = zhanweifu;
			cnt++;
		}
	}
	fromend = cnt;

	//��צ��fromλ�ý���toλ��
	for (int i = 0; i < movetime; i++)
	{
		if (i == 0)
		{
			jiazhuacode[jiazhua_xdianji][cnt] = xdianjiposition[to-1];
			jiazhuacode[jiazhua_zdianji][cnt] = biaozhifu;
			jiazhuacode[jiazhua_xuanzhuandianji][cnt] = zhanweifu;
			cnt++;
		}
		else {
			jiazhuacode[jiazhua_xdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_zdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_xuanzhuandianji][cnt] = zhanweifu;
			cnt++;
		}
	}

	//��צ��ȥ
	tostart = cnt;
	for (int i = 0; i < downtime; i++)
	{
		if (i == 0)
		{
			jiazhuacode[jiazhua_xdianji][cnt] = biaozhifu;
			jiazhuacode[jiazhua_zdianji][cnt] = zdianjidecline[to-1];
			jiazhuacode[jiazhua_xuanzhuandianji][cnt] = zhanweifu;
			cnt++;
		}
		else {
			jiazhuacode[jiazhua_xdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_zdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_xuanzhuandianji][cnt] = zhanweifu;
			cnt++;
		}
	}

	//��צ�ſ�
	for (int i = 0; i < opentime; i++)
	{
		if (i == 0)
		{
			jiazhuacode[jiazhua_xdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_zdianji][cnt] = biaozhifu;
			jiazhuacode[jiazhua_xuanzhuandianji][cnt] = jiazhua_open;
			cnt++;
		}
		else {
			jiazhuacode[jiazhua_xdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_zdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_xuanzhuandianji][cnt] = zhanweifu;
			cnt++;
		}
	}

	//��צ��ȥ
	for (int i = 0; i < uptime; i++)
	{
		if (i == 0)
		{
			jiazhuacode[jiazhua_xdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_zdianji][cnt] = jiazhua_upward;
			jiazhuacode[jiazhua_xuanzhuandianji][cnt] = biaozhifu;
			cnt++;
		}
		else {
			jiazhuacode[jiazhua_xdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_zdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_xuanzhuandianji][cnt] = zhanweifu;
			cnt++;
		}
	}
	toend = cnt;


	//��צ��toλ���ƶ���initλ
	for (int i = 0; i < movetime; i++)
	{
		if (i == 0)
		{
			jiazhuacode[jiazhua_xdianji][cnt] = fuweifu;
			jiazhuacode[jiazhua_zdianji][cnt] = biaozhifu;
			jiazhuacode[jiazhua_xuanzhuandianji][cnt] = zhanweifu;
			cnt++;
		}
		else {
			jiazhuacode[jiazhua_xdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_zdianji][cnt] = zhanweifu;
			jiazhuacode[jiazhua_xuanzhuandianji][cnt] = zhanweifu;
			cnt++;
		}
	}

	jiazhuacode[jiazhua_xdianji][cnt] = biaozhifu;
	jiazhuacode[jiazhua_zdianji][cnt] = zhanweifu;
	jiazhuacode[jiazhua_xuanzhuandianji][cnt] = zhanweifu;
	cnt++;

	//��Ӽ�צ��ʼ�򿪵Ĵ���
	for (int t = 0; t <= closetime; t++)
	{
		if (t == 0)
		{
			jiazhuacode[jiazhua_xuanzhuandianji][t] = jiazhua_open;
		}
		else if (t == closetime)
		{
			jiazhuacode[jiazhua_xuanzhuandianji][t] = biaozhifu;
		}
		else
		{
			jiazhuacode[jiazhua_xuanzhuandianji][t] = zhanweifu;
		}


	}

	return cnt;
}