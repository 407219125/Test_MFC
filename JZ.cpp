#include "stdafx.h"
#include"JZ.h"
#include "GlobalVariableState.h"

//分别表示占位、标志和复位信号
const int zhanweifu = 77;
const int biaozhifu = 88;
const int fuweifu = 55;

//从右至左
//1		 2		3	   4	  5		 6		7		8		9		10		11		12		  13
//杯子1，杯子2，杯子3，杯子4，杯子5，杯子6，杯子7，光检查，孵育盘，等待位1，等待位2，等待位3，磁分离

//夹爪发出不同的指令到不同的位置,下面的数组分别表示0号位（也是初始位）~12号位的指令信号
const int xdianjiposition[13] = { 55,2,3,4,5,6,7,8,9,10,11,12,13 };

//夹爪不同的位置下降不一样，2~6分别表示五种不同类型位置的下降指令信号，上升都用复位55表示,
const int zdianjidecline[13] = { 2,2,2,2,2,2,2,3,4,5,5,5,6 };
const int jiazhua_upward = fuweifu;

//夹爪抓取指令为复位指令55,放开指令为02
const int jiazhua_close = 3;
const int jiazhua_open = 2;

//夹爪初始位，也是复位位置，与1号杯位置重叠，指令为55
const int init_position = 1;

//声明三个电机位置的索引，0代表xdianji,1代表zdianji，2代表xuanzhuandianji
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


//从初始位置开始过from至to，最后回到初始位置
//fromstart,fromend,tostart,toend分别返回爪子向下并向上回去的时间，用来记录拿起或放下杯子的时间
//函数返回值为整个时序表的有效的长度
//int(&jiazhuacode)[3][100]
//索引【0】行是夹杯X向电机（表中9行）,55表示一号杯子的位置，2~13分别表示从2号杯到磁分离位置的12个位置，
//索引【1】行是夹爪z向电机（表中10行），11~15分别表示五个不同下降位置的步数，上升都用2表示
//索引【2】行是夹爪旋转夹杯电机（表中11行），01代表闭合，02代表张开
//jiazhua从init进入from位置，夹爪放开,夹爪下去，夹爪抓取，夹爪上去，夹爪从from位置进入to位置，夹爪下去，夹爪放开，夹爪上去，夹爪从to位置移动至init位置
int JZ::jiazhua_createcode(int from, int to, int(&jiazhuacode)[3][100], int &fromstart, int &fromend, int &tostart, int &toend)
{
	/*assert((from >= 1) && (from <= 13));
	assert((to >= 1) && (to <= 13));
	assert(from != to);
	assert(opentime <= movetime);*/

	int cnt = 0;
	//jiazhua从init进入from位置
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

	//夹爪下去
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

	//夹爪抓取
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

	//夹爪上去
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

	//夹爪从from位置进入to位置
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

	//夹爪下去
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

	//夹爪放开
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

	//夹爪上去
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


	//夹爪从to位置移动至init位
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

	//添加夹爪初始打开的代码
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