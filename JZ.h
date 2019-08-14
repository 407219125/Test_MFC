#pragma once
class JZ
{
public:
	JZ();
	~JZ();
	int movetime;//夹爪左右移动时间

	int opentime;//夹爪打开时间，已从2s改为1s
	int closetime;//夹爪关闭时间,已从2s改为1s

	int uptime;//夹爪上升时间
	int downtime;//夹爪下降时间

	int jiazhua_createcode(int from, int to, int(&jiazhuacode)[3][100], int &fromstart, int &fromend, int &tostart, int &toend);

};

