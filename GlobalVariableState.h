
extern int xy[70][100000];
extern int totaltime;

extern int GBJ_Move_Next_Row_Time;            //���ܻ���ʱ��
extern int GBJ_Restoration_Time;              //���ܸ�λʱ��
extern int GBJ_To_Output_Place_Time;          //�����ƶ���������λʱ��
extern int GBJ_Content[9][7];                 //��������
extern int GBJ_Current_Row;                   //��ǰ��
extern int GBJ_Rows;                          //��������
extern int GBJ_cols;                          //��������
extern int GCurrent_Cup_position_Row;         //��ǰ����������
extern int GCurrent_Cup_position_Col;         //��ǰ����������
extern int GRemian_Cup_Numbers;               //ʣ�౭������

extern int GSJG_Move_Time;                   //�Լ���ת��ʱ��
extern int GSJG_UpDown_Time;                 //�Լ���Zʱ��
extern int GPump_In_Out_Time;                //SGMB�ô�������ʱ��
extern int GSJP_Rotary_Movement_Time;        //�Լ���ת��ʱ��
extern int GP01_Wash_Inside_Time;            //P01��ϴ�ڱ�ʱ��
extern int GP01_Wash_Outside_Time;           //P01��ϴ���ʱ��
extern int GAttenuation_Time;                //ϡ�͵ȴ�ʱ��
extern int GReagent_Code_Row;                //��������
extern int GSJG_Rotary_Angle;                //�Լ���ת���Ƕ�
extern int GSJP_Rotary_Place;                //�Լ���ת��λ��
extern int GP01_Open_WashInside_Time;       //P01�ô���ϴ�ڱ�ʱ��
extern int GP01_Open_WashOutside_Time;      //P01�ô���ϴ���ʱ��
extern int GSGMB_Open_Absorb_Time;           //SGMB�ô����Լ�
extern int GSGMB_Reset;                      //SGMB�ø�λ
extern int GAbsorb_reagent_ul;               //���Լ���

extern int GYBG_Move_Time;                  //������ת��ʱ��
extern int GYBG_UpDown_Time;                //������Zʱ��
extern int GYBP_Rotary_Movement_Time;       //������ת��ʱ��
extern int GCode_Row;                       //��������
extern int GSGMA_Open_Absorb_Time;          //SGMA�ô�������
extern int GSGMA_Reset;                      //SGMA�ø�λ
extern int GAbsorb_sample_ul;               //��������

//��צ
extern int jz_movetime;//��צ�����ƶ�ʱ��

extern int jz_opentime;//��צ��ʱ�䣬�Ѵ�2s��Ϊ1s
extern int jz_closetime;//��צ�ر�ʱ��,�Ѵ�2s��Ϊ1s

extern int jz_uptime;//��צ����ʱ��
extern int jz_downtime;//��צ�½�ʱ��


//�ŷ���
extern int cfl_CFLcyclesteptime;//�ŷ���ת��һ������ʱ��
extern int cfl_CFLcycletime;//�ŷ���ת����ʱ��

extern int cfl_zdianji_downtime;;//�ŷ���z����½�ʱ��
extern int cfl_zdianji_uptime;;//�ŷ���z�����������λ��ʱ��

extern int cfl_zhushebeng_xiyetime;//�ŷ���ע��õĵ���Һʱ��
extern int cfl_zhushebeng_paiyetime;//�ŷ���ע��õ���Һʱ��
extern int cfl_zhushefa_opentime;//ע�䷧��ʱ��
extern int cfl_zhushefa_closetime;//ע�䷧�ر�ʱ��

extern int cfl_rudongbeng_opentime;//�䶯�ô�ʱ��
extern int cfl_rudongbeng_closetime;//�䶯�ùر�ʱ��

extern int cfl_diwubeng_xiyetime;//�������Һʱ��
extern int cfl_diwubeng_paiyetime;//�������Һʱ��
extern int cfl_diwufa_opentime;//���﷧��ʱ��
extern int cfl_diwufa_closetime;//���﷧�ر�ʱ��

extern int DDW_StayTime; //�ȴ�λ����رճ�����ʱ��

extern int FYP_ActionTime;  //������ת����Ӧλ�û��ѵ�ʱ��
extern int GJC_WorkTime;   //������Ҫ��ʱ��
extern int GJC_StayTime;    //�����֮��ĵȴ�ʱ��

//����ͨѶ
extern int g_i;
extern long long g_average;
extern long long g[10];