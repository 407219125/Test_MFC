#pragma once
#include "GlobalVariableState.h"
class FYP
{
public:
	int getemptyholeNO(int &opposit_time, int startusetime, int(&xy)[70][100000]);
	void createcode(int needholeNO, int ischangecupposition, int StayTime, int& length, int(&code)[50]);
	FYP():FYPActionTime(FYP_ActionTime), QuYang(1), JiaShiJi(2), ZhanWei(77), Reset(55), Flag(88), PianYi(128) {}


private:
	const int FYPActionTime;//孵育盘转动对应位置花费的时间
	const int QuYang;       //取放耗材的操作 1
	const int JiaShiJi;     //加试剂、加血样的操作 2
	const int ZhanWei;      //占位符 77
	const int Reset;        //复位指令 55
	const int Flag;         //标志位 88
	const int PianYi;       //跟下位机通信，需要的二进制偏移量 128
};

