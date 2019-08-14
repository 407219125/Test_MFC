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


	//生成磁分离盘转动的代码,比如013288000132880001328800
	/*void iniCFLcycle(int(&xy)[70][10000]);*/

	//通过查找表格CFLcontent[12][10000]确定当前时刻cfl盘上试管的状态，并返回12号位的状态
	int computeCFLNR(int(&xy)[70][100000], int time);

	//向磁分离盘添加一个试管
	//void cflcontentzj(int(&xy)[70][10000], int time);

	//注射器1操作
	//zdianji下降,同时zhushefa1与zhushefa2关闭，cflbeng吸液，zhushefa1打开，cflbeng排液，zdianji复位(6s),同时zhushefa1关闭
	void CFLzhushe1codegenerate(int(&CFLcode)[8][30],int & length);

	//注射器2操作
	//zdianji下降，同时zhushefa1与zhushefa2关闭，cflbeng吸液，zhushefa2打开，cflbeng排液，zdianji复位(6s)，同时zhushefa2关闭
	void CFLzhushe2codegenerate(int(&CFLcode)[8][30], int & length);

	//排液器1操作
	//zdianji下降，rudongbeng1打开，rudongbeng1关闭，zdianji复位(6s)
	void CFLpaiye1codegenerate(int(&CFLcode)[8][30], int & length);

	//排液器2操作
	//zdianji下降，rudongbeng2打开，rudongbeng2关闭，zdianji复位(6s)
	void CFLpaiye2codegenerate(int(&CFLcode)[8][30], int & length);

	//加底物操作代码
	//zdianji下降，同时diwufa关闭，diwubeng吸液，diwufa打开，diwubeng排液，zdianji复位(6s)，同时diwufa关闭
	void CFLdiwucodegenerate(int(&CFLcode)[8][30], int & length);
};

