#pragma once

extern int xy[70][100000] = { 0 };
extern int totaltime = 0;

extern int GBJ_Move_Next_Row_Time = 2;            //���ܻ���ʱ��
extern int GBJ_Restoration_Time = 2;              //���ܸ�λʱ��
extern int GBJ_To_Output_Place_Time = 2;          //�����ƶ���������λʱ��
extern int GBJ_Content[9][7] = { 0 };             //��������
extern int GBJ_Current_Row = 0;                   //��ǰ��
extern int GBJ_Rows = 9;                          //��������
extern int GBJ_cols = 7;                          //��������
extern int GCurrent_Cup_position_Row = 0;         //��ǰ����������
extern int GCurrent_Cup_position_Col = 6;         //��ǰ����������
extern int GRemian_Cup_Numbers = 63;              //ʣ�౭������
                                          
extern int GSJG_Move_Time = 2;                   //�Լ���ת��ʱ��
extern int GSJG_UpDown_Time = 1;                 //�Լ���Zʱ��
extern int GPump_In_Out_Time = 2;                //������ʱ��
extern int GSJP_Rotary_Movement_Time = 3;        //�Լ���ת��ʱ��
extern int GP01_Wash_Inside_Time = 20;            //P01��ϴ�ڱ�ʱ��
extern int GP01_Wash_Outside_Time = 20;           //P01��ϴ���ʱ��
extern int GAttenuation_Time = 0;                //ϡ�͵ȴ�ʱ��
extern int GReagent_Code_Row = 0;                //��������
extern int GSJG_Rotary_Angle = 0;                //�Լ���ת���Ƕ�
extern int GSJP_Rotary_Place = 0;                //�Լ���ת��λ��
extern int GP01_Open_WashInside_Time = 4;       //P01�ô���ϴ�ڱ�ʱ��
extern int GP01_Open_WashOutside_Time = 4;      //P01�ô���ϴ���ʱ��
extern int GSGMB_Open_Absorb_Time = 01;           //SGMB�ô����Լ�
extern int GSGMB_Reset = 55;                      //SGMB�ø�λ
extern int GAbsorb_reagent_ul = 0;                  //���Լ���

extern int GYBG_Move_Time = 2;                  //������ת��ʱ��
extern int GYBG_UpDown_Time = 1;                //������Zʱ��
extern int GYBP_Rotary_Movement_Time = 3;       //������ת��ʱ��
extern int GCode_Row = 0;                       
extern int GSGMA_Open_Absorb_Time = 01;          //SGMA�ô�������
extern int GSGMA_Reset = 55;                      //SGMA�ø�λ
extern int GAbsorb_sample_ul = 0;               //��������
//��צ
extern int jz_movetime = 2;//��צ�����ƶ�ʱ��

extern int jz_opentime = 1;//��צ��ʱ�䣬�Ѵ�2s��Ϊ1s
extern int jz_closetime = 1;//��צ�ر�ʱ��,�Ѵ�2s��Ϊ1s

extern int jz_uptime = 1;//��צ����ʱ��
extern int jz_downtime = 1;//��צ�½�ʱ��


//�ŷ���
extern int cfl_CFLcyclesteptime = 17;//�ŷ���ת��һ������ʱ��
extern int cfl_CFLcycletime = 1;//�ŷ���ת����ʱ��

extern int cfl_zdianji_downtime = 2;//�ŷ���z����½�ʱ��
extern int cfl_zdianji_uptime = 2;//�ŷ���z�����������λ��ʱ��

extern int cfl_zhushebeng_xiyetime = 1;//�ŷ���ע��õĵ���Һʱ��
extern int cfl_zhushebeng_paiyetime = 2;//�ŷ���ע��õ���Һʱ��
extern int cfl_zhushefa_opentime = 1;//ע�䷧��ʱ��
extern int cfl_zhushefa_closetime = 1;//ע�䷧�ر�ʱ��

extern int cfl_rudongbeng_opentime = 2;//�䶯�ô�ʱ��
extern int cfl_rudongbeng_closetime = 1;//�䶯�ùر�ʱ��

extern int cfl_diwubeng_xiyetime = 1;//�������Һʱ��
extern int cfl_diwubeng_paiyetime = 2;//�������Һʱ��
extern int cfl_diwufa_opentime = 1;//���﷧��ʱ��
extern int cfl_diwufa_closetime = 1;//���﷧�ر�ʱ��



extern int DDW_StayTime = 4; //�ȴ�λ����رճ�����ʱ��

extern int FYP_ActionTime = 2;  //������ת����Ӧλ�û��ѵ�ʱ��
extern int GJC_WorkTime = 36;   //������Ҫ��ʱ��
extern int GJC_StayTime = 2;    //�����֮��ĵȴ�ʱ��

//����ͨѶ
extern int g_i = 0;
extern long long g_average = 0;
extern long long g[10] = { 0 };