#pragma once
class CFL
{
public:
	CFL();
	~CFL();

	int CFLcyclesteptime;
	int CFLcycletime;

	int zdianji_downtime;
	int zdianji_uptime;

	int zhushebeng_xiyetime;
	int zhushebeng_paiyetime;
	int zhushefa_opentime;
	int zhushefa_closetime;

	int rudongbeng_opentime;
	int rudongbeng_closetime;

	int diwubeng_xiyetime;
	int diwubeng_paiyetime;
	int diwufa_opentime;
	int diwufa_closetime;


	//���ɴŷ�����ת���Ĵ���,����013288000132880001328800
	/*void iniCFLcycle(int(&xy)[70][10000]);*/

	//ͨ�����ұ��CFLcontent[12][10000]ȷ����ǰʱ��cfl�����Թܵ�״̬��������12��λ��״̬
	int computeCFLNR(int(&xy)[70][100000], int time);

	//��ŷ��������һ���Թ�
	//void cflcontentzj(int(&xy)[70][10000], int time);

	//ע����1����
	//zdianji�½�,ͬʱzhushefa1��zhushefa2�رգ�cflbeng��Һ��zhushefa1�򿪣�cflbeng��Һ��zdianji��λ(6s),ͬʱzhushefa1�ر�
	void CFLzhushe1codegenerate(int(&CFLcode)[8][30],int & length);

	//ע����2����
	//zdianji�½���ͬʱzhushefa1��zhushefa2�رգ�cflbeng��Һ��zhushefa2�򿪣�cflbeng��Һ��zdianji��λ(6s)��ͬʱzhushefa2�ر�
	void CFLzhushe2codegenerate(int(&CFLcode)[8][30], int & length);

	//��Һ��1����
	//zdianji�½���rudongbeng1�򿪣�rudongbeng1�رգ�zdianji��λ(6s)
	void CFLpaiye1codegenerate(int(&CFLcode)[8][30], int & length);

	//��Һ��2����
	//zdianji�½���rudongbeng2�򿪣�rudongbeng2�رգ�zdianji��λ(6s)
	void CFLpaiye2codegenerate(int(&CFLcode)[8][30], int & length);

	//�ӵ����������
	//zdianji�½���ͬʱdiwufa�رգ�diwubeng��Һ��diwufa�򿪣�diwubeng��Һ��zdianji��λ(6s)��ͬʱdiwufa�ر�
	void CFLdiwucodegenerate(int(&CFLcode)[8][30], int & length);
};

