#pragma once
class JZ
{
public:
	JZ();
	~JZ();
	int movetime;//��צ�����ƶ�ʱ��

	int opentime;//��צ��ʱ�䣬�Ѵ�2s��Ϊ1s
	int closetime;//��צ�ر�ʱ��,�Ѵ�2s��Ϊ1s

	int uptime;//��צ����ʱ��
	int downtime;//��צ�½�ʱ��

	int jiazhua_createcode(int from, int to, int(&jiazhuacode)[3][100], int &fromstart, int &fromend, int &tostart, int &toend);

};

