#include "stdafx.h"
#include "CFL.h"
#include "GlobalVariableState.h"


//声明占位、标志、和复位符
const int zhanweifu = 77;
const int biaozhifu = 88;
const int fuweifu = 55;

//磁分离旋转指令顺转一步为193
const int xuanzhuan = 193;

//z电机下降指令，上升为复位符55
const int zdianjifall = 2;

//注射阀打开与关闭指令
const int zhushefaclose = fuweifu;
const int zhushefaopen = 1;

//注射泵吸液400ul（用指令10）与排液指令
const int zhushebengxiye = 10;
const int zhushebengpaiye = fuweifu;

//蠕动泵打开与关闭,0表示关闭，1表示开2s,2-50表示开泵（*100ms）时间
const int rudongbengopen = 50;
const int rudongbengclose = fuweifu;

//底物阀打开与关闭
const int diwufaopen = 1;
const int diwufaclose = fuweifu;

//底物泵吸液200ul(用指令11)与排液
const int diwubengxiye = 11;
const int diwubengpaiye = fuweifu;


//索引【13】行代表磁分离旋转电机1号电机（表中13行）周期旋转信号，01代表转动一个位置
//const int cifenli_xuanzhuandiji = 13;

//索引【0】行是磁分离z向电机（表中14行），02是向下，55是复位（向上）
//索引【1】行是双联磁分离注液SGMC泵（表中16行），01是吸，55是推(也是复位位置)
//索引【2】行是底物泵SGMD泵（表中19行），01是吸，55是推(也是复位位置)
//索引【3】行是磁分离排液蠕动泵4(可调速)P07（表中22行），01代表打开2s,(2~50)分别代表打开*100ms的时间，55代表关闭
//索引【4】行是磁分离排液蠕动泵5(可调速)P08（表中23行），01代表打开2s,(2~50)分别代表打开*100ms的时间，55代表关闭
//索引【5】行是双联磁分离注液阀v07（表中24行），01代表打开，55代表关闭
//索引【6】行是双联磁分离注液阀v08（表中25行），01代表打开，55代表关闭
//索引【7】行是底物阀V10（表中26行），01代表打开，55代表关闭

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

//生成磁分离盘转动的代码比如013288000132880001328800
//索引【13】行代表磁分离旋转电机1号电机（表中13行）周期旋转信号，193代表顺转动一个位置
//void CFL::iniCFLcycle(int(&xy)[70][10000])
//{
//	int cnt = 0;
//	while (cnt < 10000 - CFLcyclesteptime)
//	{
//		for (int t = 0; t < 12; t++)//一圈转12次
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



//通过查找表格xy[70][100000]中第50~61行确定当前时刻cfl盘上12号位的状态
//返回0表示被占用没有空位，返回1~12表示当前12号孔位当前的孔号
int CFL::computeCFLNR(int(&xy)[70][100000], int time)
{
	int t = time / CFLcyclesteptime;//计算总共在第几个周期，t*CFLcyclesteptime to (t+24)*CFLcyclesteptime-1为要改变的值
	int n = t % 12;//判断[11-n]位置
	for (int i = t * CFLcyclesteptime; i < (t + 25)*CFLcyclesteptime; i++)
	{
		if (xy[50 + n][i] != 0)
			return 0;//被占用，返回0表示没空位
	}
	return (12 - n);//没有被占用，返回12号孔位的孔号
}



//向磁分离盘添加一个试管，从当前周期起，到第25个周期，都要被占用
//void CFL::cflcontentzj(int(&xy)[70][10000], int time)
//{
//	int t = time / CFLcyclesteptime;//计算总共在第几个周期，t*CFLcyclesteptime to (t+24)*CFLcyclesteptime为要改变的值
//	int n = t % 12;//[11-n]为要添加行的索引
//	for (int i = t * CFLcyclesteptime; i < (t + 25)*CFLcyclesteptime; i++)//占25个周期
//		xy[61 - n][i] = zhanweifu;
//}



//注射器1操作
//zdianji下降,同时zhushefa1与zhushefa2关闭，cflbeng吸液，zhushefa1打开，cflbeng排液，zdianji复位(7s),同时zhushefa1关闭
void CFL::CFLzhushe1codegenerate(int(&CFLcode)[8][30], int & length)
{
	int i = 0;
	int cnt = 0;
	//zdianji下降
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

	//同时zhushefa1与zhushefa2关闭
	CFLcode[zhushefa1][0] = zhushefaclose;
	CFLcode[zhushefa2][0] = zhushefaclose;
	CFLcode[zhushefa1][1] = biaozhifu;
	CFLcode[zhushefa2][1] = biaozhifu;

	//cflbeng吸液
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

	//zhushefa1打开
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

	//cflbeng排液
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

	//zdianji复位（7s）
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

	//同时zhushefa1关闭
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




//注射器2操作
//zdianji下降，同时zhushefa1与zhushefa2关闭，cflbeng吸液，zhushefa2打开，cflbeng排液，zdianji复位(7s)，同时zhushefa2关闭
void CFL::CFLzhushe2codegenerate(int(&CFLcode)[8][30], int & length)
{
	int i = 0;
	int cnt = 0;
	//zdianji下降
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

	//同时zhushefa1与zhushefa2关闭
	CFLcode[zhushefa1][0] = zhushefaclose;
	CFLcode[zhushefa2][0] = zhushefaclose;
	CFLcode[zhushefa1][1] = biaozhifu;
	CFLcode[zhushefa2][1] = biaozhifu;

	//cflbeng吸液
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

	//zhushefa2打开
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

	//cflbeng排液
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

	//zdianji复位（7s）
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

	//同时zhushefa1关闭
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



//排液器1操作
//zdianji下降，rudongbeng1打开，rudongbeng1关闭，zdianji复位(6s)
void CFL::CFLpaiye1codegenerate(int(&CFLcode)[8][30], int & length)
{
	int i = 0;
	int cnt = 0;
	//zdianji下降
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
	//rudongbeng1打开
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

	//rudongbeng1关闭
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

	//zdianji复位（7s）
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

//排液器2操作
//zdianji下降，rudongbeng2打开，rudongbeng2关闭，zdianji复位(7s)
void CFL::CFLpaiye2codegenerate(int(&CFLcode)[8][30], int & length)
{
	int i = 0;
	int cnt = 0;
	//zdianji下降
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
	//rudongbeng2打开
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

	//rudongbeng1关闭
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

	//zdianji复位（7s）
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


//加底物操作代码
//zdianji下降，同时diwufa关闭，diwubeng吸液，diwufa打开，diwubeng排液，zdianji复位(7s)，同时diwufa关闭
void CFL::CFLdiwucodegenerate(int(&CFLcode)[8][30], int & length)
{
	int i = 0;
	int cnt = 0;
	//zdianji下降
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

	//同时diwufa关闭
	CFLcode[diwufa][0] = diwufaclose;
	CFLcode[diwufa][1] = biaozhifu;

	//diwubeng吸液
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

	//diwufafa打开
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

	//diwubeng排液
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

	//zdianji复位（7s）
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

	//同时diwufa关闭
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