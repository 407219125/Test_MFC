#include "stdafx.h"
#include "CFL.h"
#include "GlobalVariableState.h"


//����ռλ����־���͸�λ��
const int zhanweifu = 77;
const int biaozhifu = 88;
const int fuweifu = 55;

//�ŷ�����תָ��˳תһ��Ϊ193
const int xuanzhuan = 193;

//z����½�ָ�����Ϊ��λ��55
const int zdianjifall = 2;

//ע�䷧����ر�ָ��
const int zhushefaclose = fuweifu;
const int zhushefaopen = 1;

//ע�����Һ400ul����ָ��10������Һָ��
const int zhushebengxiye = 10;
const int zhushebengpaiye = fuweifu;

//�䶯�ô���ر�,0��ʾ�رգ�1��ʾ��2s,2-50��ʾ���ã�*100ms��ʱ��
const int rudongbengopen = 50;
const int rudongbengclose = fuweifu;

//���﷧����ر�
const int diwufaopen = 1;
const int diwufaclose = fuweifu;

//�������Һ200ul(��ָ��11)����Һ
const int diwubengxiye = 11;
const int diwubengpaiye = fuweifu;


//������13���д���ŷ�����ת���1�ŵ��������13�У�������ת�źţ�01����ת��һ��λ��
//const int cifenli_xuanzhuandiji = 13;

//������0�����Ǵŷ���z����������14�У���02�����£�55�Ǹ�λ�����ϣ�
//������1������˫���ŷ���עҺSGMC�ã�����16�У���01������55����(Ҳ�Ǹ�λλ��)
//������2�����ǵ����SGMD�ã�����19�У���01������55����(Ҳ�Ǹ�λλ��)
//������3�����Ǵŷ�����Һ�䶯��4(�ɵ���)P07������22�У���01�����2s,(2~50)�ֱ�����*100ms��ʱ�䣬55����ر�
//������4�����Ǵŷ�����Һ�䶯��5(�ɵ���)P08������23�У���01�����2s,(2~50)�ֱ�����*100ms��ʱ�䣬55����ر�
//������5������˫���ŷ���עҺ��v07������24�У���01����򿪣�55����ر�
//������6������˫���ŷ���עҺ��v08������25�У���01����򿪣�55����ر�
//������7�����ǵ��﷧V10������26�У���01����򿪣�55����ر�

enum cifenli_rowcode {
	zdianji = 0, zhushebeng = 1, diwubeng = 2, rudongbeng1 = 3,
	rudongbeng2 = 4, zhushefa1 = 5, zhushefa2 = 6, diwufa = 7
};

CFL::CFL():CFLcyclesteptime(cfl_CFLcyclesteptime), CFLcycletime(cfl_CFLcycletime), zdianji_downtime(cfl_zdianji_downtime), zdianji_uptime(cfl_zdianji_uptime), zhushebeng_xiyetime(cfl_zhushebeng_xiyetime),
zhushebeng_paiyetime(cfl_zhushebeng_paiyetime), zhushefa_opentime(cfl_zhushefa_opentime), zhushefa_closetime(cfl_zhushefa_closetime), rudongbeng_opentime(cfl_rudongbeng_opentime), rudongbeng_closetime(cfl_rudongbeng_closetime),
diwubeng_xiyetime(cfl_diwubeng_xiyetime), diwubeng_paiyetime(cfl_diwubeng_paiyetime), diwufa_opentime(cfl_diwufa_opentime), diwufa_closetime(cfl_diwufa_closetime)
{
}
CFL::~CFL()
{
}

//���ɴŷ�����ת���Ĵ������013288000132880001328800
//������13���д���ŷ�����ת���1�ŵ��������13�У�������ת�źţ�193����˳ת��һ��λ��
//void CFL::iniCFLcycle(int(&xy)[70][10000])
//{
//	int cnt = 0;
//	while (cnt < 10000 - CFLcyclesteptime)
//	{
//		for (int t = 0; t < 12; t++)//һȦת12��
//		{
//			if (t == 0)
//			{
//				for (int i = 0; i < CFLcycletime; i++)
//				{
//					if (i == 0)
//					{
//						xy[cifenli_xuanzhuandiji][cnt] = fuweifu;
//						cnt++;
//					}
//					else
//					{
//						xy[cifenli_xuanzhuandiji][cnt] = zhanweifu;
//						cnt++;
//					}
//				}
//			}
//			else
//			{
//				for (int i = 0; i < CFLcycletime; i++)
//				{
//					if (i == 0)
//					{
//						xy[cifenli_xuanzhuandiji][cnt] = xuanzhuan;
//						cnt++;
//					}
//					else
//					{
//						xy[cifenli_xuanzhuandiji][cnt] = zhanweifu;
//						cnt++;
//					}
//				}
//			}
//			for (int i = 0; i < CFLcyclesteptime - CFLcycletime; i++)
//			{
//				if (i == 0)
//				{
//					xy[cifenli_xuanzhuandiji][cnt] = biaozhifu;
//					cnt++;
//				}
//				else
//				{
//					//xy[cifenli_xuanzhuandiji][cnt] = zhanweifu;
//					cnt++;
//				}
//			}
//		}
//	}
//}



//ͨ�����ұ��xy[70][100000]�е�50~61��ȷ����ǰʱ��cfl����12��λ��״̬
//����0��ʾ��ռ��û�п�λ������1~12��ʾ��ǰ12�ſ�λ��ǰ�Ŀ׺�
int CFL::computeCFLNR(int(&xy)[70][100000], int time)
{
	int t = time / CFLcyclesteptime;//�����ܹ��ڵڼ������ڣ�t*CFLcyclesteptime to (t+24)*CFLcyclesteptime-1ΪҪ�ı��ֵ
	int n = t % 12;//�ж�[11-n]λ��
	for (int i = t * CFLcyclesteptime; i < (t + 25)*CFLcyclesteptime; i++)
	{
		if (xy[50 + n][i] != 0)
			return 0;//��ռ�ã�����0��ʾû��λ
	}
	return (12 - n);//û�б�ռ�ã�����12�ſ�λ�Ŀ׺�
}



//��ŷ��������һ���Թܣ��ӵ�ǰ�����𣬵���25�����ڣ���Ҫ��ռ��
//void CFL::cflcontentzj(int(&xy)[70][10000], int time)
//{
//	int t = time / CFLcyclesteptime;//�����ܹ��ڵڼ������ڣ�t*CFLcyclesteptime to (t+24)*CFLcyclesteptimeΪҪ�ı��ֵ
//	int n = t % 12;//[11-n]ΪҪ����е�����
//	for (int i = t * CFLcyclesteptime; i < (t + 25)*CFLcyclesteptime; i++)//ռ25������
//		xy[61 - n][i] = zhanweifu;
//}



//ע����1����
//zdianji�½�,ͬʱzhushefa1��zhushefa2�رգ�cflbeng��Һ��zhushefa1�򿪣�cflbeng��Һ��zdianji��λ(7s),ͬʱzhushefa1�ر�
void CFL::CFLzhushe1codegenerate(int(&CFLcode)[8][30], int & length)
{
	int i = 0;
	int cnt = 0;
	//zdianji�½�
	for (i = 0; i < zdianji_downtime; i++)
	{
		if (i == 0)
		{
			CFLcode[zdianji][cnt] = zdianjifall;
			cnt++;
		}
		else
		{
			CFLcode[zdianji][cnt] = zhanweifu;
			cnt++;
		}
	}

	//ͬʱzhushefa1��zhushefa2�ر�
	CFLcode[zhushefa1][0] = zhushefaclose;
	CFLcode[zhushefa2][0] = zhushefaclose;
	CFLcode[zhushefa1][1] = biaozhifu;
	CFLcode[zhushefa2][1] = biaozhifu;

	//cflbeng��Һ
	for (i = 0; i < zhushebeng_xiyetime; i++)
	{
		if (i == 0)
		{
			CFLcode[zdianji][cnt] = biaozhifu;
			CFLcode[zhushebeng][cnt] = zhushebengxiye;
			cnt++;
		}
		else {
			CFLcode[zhushebeng][cnt] = zhanweifu;
			cnt++;
		}
	}

	//zhushefa1��
	for (i = 0; i < zhushefa_opentime; i++)
	{
		if (i == 0)
		{
			CFLcode[zhushebeng][cnt] = biaozhifu;
			CFLcode[zhushefa1][cnt] = zhushefaopen;
			cnt++;
		}
		else {
			CFLcode[zhushefa1][cnt] = zhanweifu;
			cnt++;
		}
	}

	//cflbeng��Һ
	for (i = 0; i < zhushebeng_paiyetime; i++)
	{
		if (i == 0)
		{
			CFLcode[zhushebeng][cnt] = zhushebengpaiye;
			CFLcode[zhushefa1][cnt] = biaozhifu;
			cnt++;
		}
		else {
			CFLcode[zhushebeng][cnt] = zhanweifu;
			cnt++;
		}
	}

	//zdianji��λ��7s��
	for (i = 0; i < zdianji_uptime; i++)
	{
		if (i == 0)
		{
			CFLcode[zhushebeng][cnt] = biaozhifu;
			CFLcode[zdianji][cnt] = fuweifu;
			cnt++;
		}
		else {
			CFLcode[zdianji][cnt] = zhanweifu;
			cnt++;
		}
	}
	CFLcode[zdianji][cnt] = biaozhifu;
	cnt++;
	length = cnt;

	//ͬʱzhushefa1�ر�
	for (i = 7; i < 7 + zhushefa_closetime; i++)
	{
		if (i == 7)
		{
			CFLcode[zhushefa1][i] = zhushefaclose;
		}
		else {
			CFLcode[zhushefa1][i] = zhanweifu;
		}
	}
	CFLcode[zhushefa1][i] = biaozhifu;
}




//ע����2����
//zdianji�½���ͬʱzhushefa1��zhushefa2�رգ�cflbeng��Һ��zhushefa2�򿪣�cflbeng��Һ��zdianji��λ(7s)��ͬʱzhushefa2�ر�
void CFL::CFLzhushe2codegenerate(int(&CFLcode)[8][30], int & length)
{
	int i = 0;
	int cnt = 0;
	//zdianji�½�
	for (i = 0; i < zdianji_downtime; i++)
	{
		if (i == 0)
		{
			CFLcode[zdianji][cnt] = zdianjifall;
			cnt++;
		}
		else
		{
			CFLcode[zdianji][cnt] = zhanweifu;
			cnt++;
		}
	}

	//ͬʱzhushefa1��zhushefa2�ر�
	CFLcode[zhushefa1][0] = zhushefaclose;
	CFLcode[zhushefa2][0] = zhushefaclose;
	CFLcode[zhushefa1][1] = biaozhifu;
	CFLcode[zhushefa2][1] = biaozhifu;

	//cflbeng��Һ
	for (i = 0; i < zhushebeng_xiyetime; i++)
	{
		if (i == 0)
		{
			CFLcode[zdianji][cnt] = biaozhifu;
			CFLcode[zhushebeng][cnt] = zhushebengxiye;
			cnt++;
		}
		else {
			CFLcode[zhushebeng][cnt] = zhanweifu;
			cnt++;
		}
	}

	//zhushefa2��
	for (i = 0; i < zhushefa_opentime; i++)
	{
		if (i == 0)
		{
			CFLcode[zhushebeng][cnt] = biaozhifu;
			CFLcode[zhushefa2][cnt] = zhushefaopen;
			cnt++;
		}
		else {
			CFLcode[zhushefa2][cnt] = zhanweifu;
			cnt++;
		}
	}

	//cflbeng��Һ
	for (i = 0; i < zhushebeng_paiyetime; i++)
	{
		if (i == 0)
		{
			CFLcode[zhushebeng][cnt] = zhushebengpaiye;
			CFLcode[zhushefa2][cnt] = biaozhifu;
			cnt++;
		}
		else {
			CFLcode[zhushebeng][cnt] = zhanweifu;
			cnt++;
		}
	}

	//zdianji��λ��7s��
	for (i = 0; i < zdianji_uptime; i++)
	{
		if (i == 0)
		{
			CFLcode[zhushebeng][cnt] = biaozhifu;
			CFLcode[zdianji][cnt] = fuweifu;
			cnt++;
		}
		else {
			CFLcode[zdianji][cnt] = zhanweifu;
			cnt++;
		}
	}
	CFLcode[zdianji][cnt] = biaozhifu;
	cnt++;
	length = cnt;

	//ͬʱzhushefa1�ر�
	for (i = 7; i < 7 + zhushefa_closetime; i++)
	{
		if (i == 7)
		{
			CFLcode[zhushefa2][i] = zhushefaclose;
		}
		else {
			CFLcode[zhushefa2][i] = zhanweifu;
		}
	}
	CFLcode[zhushefa2][i] = biaozhifu;
}



//��Һ��1����
//zdianji�½���rudongbeng1�򿪣�rudongbeng1�رգ�zdianji��λ(6s)
void CFL::CFLpaiye1codegenerate(int(&CFLcode)[8][30], int & length)
{
	int i = 0;
	int cnt = 0;
	//zdianji�½�
	for (i = 0; i < zdianji_downtime; i++)
	{
		if (i == 0)
		{
			CFLcode[zdianji][cnt] = zdianjifall;
			cnt++;
		}
		else
		{
			CFLcode[zdianji][cnt] = zhanweifu;
			cnt++;
		}
	}
	//rudongbeng1��
	for (i=0; i < rudongbeng_opentime; i++)
	{
		if (i == 0)
		{
			CFLcode[rudongbeng1][cnt] = rudongbengopen;
			CFLcode[zdianji][cnt] = biaozhifu;
			cnt++;
		}
		else {
			CFLcode[rudongbeng1][cnt] = zhanweifu;
			cnt++;
		}
	}

	//rudongbeng1�ر�
	for (i = 0; i < rudongbeng_closetime; i++)
	{
		if (i == 0)
		{
			CFLcode[rudongbeng1][cnt] = rudongbengclose;
			cnt++;
		}
		else {
			CFLcode[rudongbeng1][cnt] = zhanweifu;
			cnt++;
		}
	}
	CFLcode[rudongbeng1][cnt] = biaozhifu;

	//zdianji��λ��7s��
	for (i = 6; i < 6 + zdianji_uptime; i++)
	{
		if (i == 6)
		{
			CFLcode[zdianji][i] = fuweifu;
		}
		else {
			CFLcode[zdianji][i] = zhanweifu;
		}
	}
	CFLcode[zdianji][i] = biaozhifu;
	i++;
	length = i;
}

//��Һ��2����
//zdianji�½���rudongbeng2�򿪣�rudongbeng2�رգ�zdianji��λ(7s)
void CFL::CFLpaiye2codegenerate(int(&CFLcode)[8][30], int & length)
{
	int i = 0;
	int cnt = 0;
	//zdianji�½�
	for (i = 0; i < zdianji_downtime; i++)
	{
		if (i == 0)
		{
			CFLcode[zdianji][cnt] = zdianjifall;
			cnt++;
		}
		else
		{
			CFLcode[zdianji][cnt] = zhanweifu;
			cnt++;
		}
	}
	//rudongbeng2��
	for (i = 0; i < rudongbeng_opentime; i++)
	{
		if (i == 0)
		{
			CFLcode[rudongbeng2][cnt] = rudongbengopen;
			CFLcode[zdianji][cnt] = biaozhifu;
			cnt++;
		}
		else {
			CFLcode[rudongbeng2][cnt] = zhanweifu;
			cnt++;
		}
	}

	//rudongbeng1�ر�
	for (i = 0; i < rudongbeng_closetime; i++)
	{
		if (i == 0)
		{
			CFLcode[rudongbeng2][cnt] = rudongbengclose;
			cnt++;
		}
		else {
			CFLcode[rudongbeng2][cnt] = zhanweifu;
			cnt++;
		}
	}
	CFLcode[rudongbeng2][cnt] = biaozhifu;

	//zdianji��λ��7s��
	for (i = 6; i < 6 + zdianji_uptime; i++)
	{
		if (i == 6)
		{
			CFLcode[zdianji][i] = fuweifu;
		}
		else {
			CFLcode[zdianji][i] = zhanweifu;
		}
	}
	CFLcode[zdianji][i] = biaozhifu;
	i++;
	length = i;
}


//�ӵ����������
//zdianji�½���ͬʱdiwufa�رգ�diwubeng��Һ��diwufa�򿪣�diwubeng��Һ��zdianji��λ(7s)��ͬʱdiwufa�ر�
void CFL::CFLdiwucodegenerate(int(&CFLcode)[8][30], int & length)
{
	int i = 0;
	int cnt = 0;
	//zdianji�½�
	for (i = 0; i < zdianji_downtime; i++)
	{
		if (i == 0)
		{
			CFLcode[zdianji][cnt] = zdianjifall;
			cnt++;
		}
		else
		{
			CFLcode[zdianji][cnt] = zhanweifu;
			cnt++;
		}
	}

	//ͬʱdiwufa�ر�
	CFLcode[diwufa][0] = diwufaclose;
	CFLcode[diwufa][1] = biaozhifu;

	//diwubeng��Һ
	for (i = 0; i < diwubeng_xiyetime; i++)
	{
		if (i == 0)
		{
			CFLcode[zdianji][cnt] = biaozhifu;
			CFLcode[diwubeng][cnt] = diwubengxiye;
			cnt++;
		}
		else {
			CFLcode[diwubeng][cnt] = zhanweifu;
			cnt++;
		}
	}

	//diwufafa��
	for (i = 0; i < diwufa_opentime; i++)
	{
		if (i == 0)
		{
			CFLcode[diwubeng][cnt] = biaozhifu;
			CFLcode[diwufa][cnt] = diwufaopen;
			cnt++;
		}
		else {
			CFLcode[diwufa][cnt] = zhanweifu;
			cnt++;
		}
	}

	//diwubeng��Һ
	for (i = 0; i < diwubeng_paiyetime; i++)
	{
		if (i == 0)
		{
			CFLcode[diwubeng][cnt] = diwubengpaiye;
			CFLcode[diwufa][cnt] = biaozhifu;
			cnt++;
		}
		else {
			CFLcode[diwubeng][cnt] = zhanweifu;
			cnt++;
		}
	}

	//zdianji��λ��7s��
	for (i = 0; i < zdianji_uptime; i++)
	{
		if (i == 0)
		{
			CFLcode[diwubeng][cnt] = biaozhifu;
			CFLcode[zdianji][cnt] = fuweifu;
			cnt++;
		}
		else {
			CFLcode[zdianji][cnt] = zhanweifu;
			cnt++;
		}
	}
	CFLcode[zdianji][cnt] = biaozhifu;
	cnt++;
	length = cnt;

	//ͬʱdiwufa�ر�
	for (i = 7; i < 7 + diwufa_closetime; i++)
	{
		if (i == 7)
		{
			CFLcode[diwufa][i] = diwufaclose;
		}
		else {
			CFLcode[diwufa][i] = zhanweifu;
		}
	}
	CFLcode[diwufa][i] = biaozhifu;
}