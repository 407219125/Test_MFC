

#pragma once
class BJ
{
public:
	BJ();
	~BJ();
	int iniBJ();
	int ComputeCurrentCupPosition();    //���㵱ǰ����λ��
	int GetCup();                       //ȡ��
	int BJmovnextrow(int(&Code)[10]);   //���ܻ���
	int BJ_Move_Next_Row_Time;          //���ܻ���ʱ��

	int BJRestoration(int(&Code)[10]);  //���ܸ�λ
	int BJ_Restoration_Time;            //���ܸ�λʱ��

	int BJToOutputPlace(int(&Code)[10]);//����ȥ������λ
	int BJ_To_Output_Place_Time;        //�����ƶ���������λʱ��
	int BJ_Content[9][7];               //��������
	int BJ_Current_Row;
	int BJ_Rows;
	int BJ_cols;
	int Current_Cup_position_Row;
	int Current_Cup_position_Col;
	int Remian_Cup_Numbers;


private:
	

};

