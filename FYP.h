#pragma once
#include "GlobalVariableState.h"
class FYP
{
public:
	int getemptyholeNO(int &opposit_time, int startusetime, int(&xy)[70][100000]);
	void createcode(int needholeNO, int ischangecupposition, int StayTime, int& length, int(&code)[50]);
	FYP():FYPActionTime(FYP_ActionTime), QuYang(1), JiaShiJi(2), ZhanWei(77), Reset(55), Flag(88), PianYi(128) {}


private:
	const int FYPActionTime;//������ת����Ӧλ�û��ѵ�ʱ��
	const int QuYang;       //ȡ�źĲĵĲ��� 1
	const int JiaShiJi;     //���Լ�����Ѫ���Ĳ��� 2
	const int ZhanWei;      //ռλ�� 77
	const int Reset;        //��λָ�� 55
	const int Flag;         //��־λ 88
	const int PianYi;       //����λ��ͨ�ţ���Ҫ�Ķ�����ƫ���� 128
};

