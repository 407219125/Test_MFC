#pragma once
#include "GlobalVariableState.h"
class DDW
{
public:
	int GetemptyholeNO(int& opposit_time, int startusetime, int(&xy)[70][100000]);
	void CreatCode(int WorkTime, int &length, int(&code)[200]);
	
	DDW():StayTime(DDW_StayTime),Start(1), Reset(55), ZhanWeiFu(77), Flag(88), DDWWorkTime(148){}
private:
	const int StayTime;  //等待位电机关闭持续时间
	const int Start ;	 //启动电机命令 1
	const int Reset ;    //关闭电机命令 55
	const int ZhanWeiFu; //占位符，等待 77
	const int Flag;		 //命令成功标志位 88
	const int DDWWorkTime; //等待位工作时间，设为148s'

};

