#pragma once
#include "GlobalVariableState.h"
class DDW
{
public:
	int GetemptyholeNO(int& opposit_time, int startusetime, int(&xy)[70][100000]);
	void CreatCode(int WorkTime, int &length, int(&code)[200]);
	
	DDW():StayTime(DDW_StayTime),Start(1), Reset(55), ZhanWeiFu(77), Flag(88), DDWWorkTime(148){}
private:
	const int StayTime;  //�ȴ�λ����رճ���ʱ��
	const int Start ;	 //����������� 1
	const int Reset ;    //�رյ������ 55
	const int ZhanWeiFu; //ռλ�����ȴ� 77
	const int Flag;		 //����ɹ���־λ 88
	const int DDWWorkTime; //�ȴ�λ����ʱ�䣬��Ϊ148s'

};

