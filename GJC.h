#pragma once
#include "GlobalVariableState.h"
class GJC
{
public:
	void getemptyholeNO(int& opposit_time, int startusetime, int(&xy)[70][10000]);
	void createcode(int work_time, int mission_NO, int& length, int(&code)[3][50]);
	void db_createcode(int &length, int(&code)[50]);
	GJC():ZhanWei(77), Flag(88), Reset(55), Second(2), Third(3), StayTime(GJC_StayTime) {}
private:

	const int StayTime;  //各项动作之间的等待时间
	const int ZhanWei;   //占位符 77
	const int Flag;      //成功标志位 88
	const int Reset;     //表示第一个位置 55
	const int Second;    //第二个位置 2
	const int Third;     //第三个位置 3

};

