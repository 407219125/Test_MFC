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

	const int StayTime;  //�����֮��ĵȴ�ʱ��
	const int ZhanWei;   //ռλ�� 77
	const int Flag;      //�ɹ���־λ 88
	const int Reset;     //��ʾ��һ��λ�� 55
	const int Second;    //�ڶ���λ�� 2
	const int Third;     //������λ�� 3

};

