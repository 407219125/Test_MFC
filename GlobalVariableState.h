
extern int xy[70][100000];
extern int totaltime;

extern int GBJ_Move_Next_Row_Time;            //杯架换行时间
extern int GBJ_Restoration_Time;              //杯架复位时间
extern int GBJ_To_Output_Place_Time;          //杯架移动到换杯架位时间
extern int GBJ_Content[9][7];                 //杯架数组
extern int GBJ_Current_Row;                   //当前行
extern int GBJ_Rows;                          //杯架行数
extern int GBJ_cols;                          //杯架列数
extern int GCurrent_Cup_position_Row;         //当前杯子所在行
extern int GCurrent_Cup_position_Col;         //当前杯子所在列
extern int GRemian_Cup_Numbers;               //剩余杯子数量

extern int GSJG_Move_Time;                   //试剂杆转动时间
extern int GSJG_UpDown_Time;                 //试剂针Z时间
extern int GPump_In_Out_Time;                //SGMB泵打开吸样本时间
extern int GSJP_Rotary_Movement_Time;        //试剂盘转动时间
extern int GP01_Wash_Inside_Time;            //P01清洗内壁时间
extern int GP01_Wash_Outside_Time;           //P01清洗外壁时间
extern int GAttenuation_Time;                //稀释等待时间
extern int GReagent_Code_Row;                //代码行数
extern int GSJG_Rotary_Angle;                //试剂杆转动角度
extern int GSJP_Rotary_Place;                //试剂盘转动位置
extern int GP01_Open_WashInside_Time;       //P01泵打开清洗内壁时间
extern int GP01_Open_WashOutside_Time;      //P01泵打开清洗外壁时间
extern int GSGMB_Open_Absorb_Time;           //SGMB泵打开吸试剂
extern int GSGMB_Reset;                      //SGMB泵复位
extern int GAbsorb_reagent_ul;               //吸试剂量

extern int GYBG_Move_Time;                  //样本杆转动时间
extern int GYBG_UpDown_Time;                //样本针Z时间
extern int GYBP_Rotary_Movement_Time;       //样本盘转动时间
extern int GCode_Row;                       //代码行数
extern int GSGMA_Open_Absorb_Time;          //SGMA泵打开吸样本
extern int GSGMA_Reset;                      //SGMA泵复位
extern int GAbsorb_sample_ul;               //吸样本量

//夹爪
extern int jz_movetime;//夹爪左右移动时间

extern int jz_opentime;//夹爪打开时间，已从2s改为1s
extern int jz_closetime;//夹爪关闭时间,已从2s改为1s

extern int jz_uptime;//夹爪上升时间
extern int jz_downtime;//夹爪下降时间


//磁分离
extern int cfl_CFLcyclesteptime;//磁分离转动一格周期时间
extern int cfl_CFLcycletime;//磁分离转动的时间

extern int cfl_zdianji_downtime;;//磁分离z电机下降时间
extern int cfl_zdianji_uptime;;//磁分离z电机上升（复位）时间

extern int cfl_zhushebeng_xiyetime;//磁分离注射泵的的吸液时间
extern int cfl_zhushebeng_paiyetime;//磁分离注射泵的排液时间
extern int cfl_zhushefa_opentime;//注射阀打开时间
extern int cfl_zhushefa_closetime;//注射阀关闭时间

extern int cfl_rudongbeng_opentime;//蠕动泵打开时间
extern int cfl_rudongbeng_closetime;//蠕动泵关闭时间

extern int cfl_diwubeng_xiyetime;//底物泵吸液时间
extern int cfl_diwubeng_paiyetime;//底物泵排液时间
extern int cfl_diwufa_opentime;//底物阀打开时间
extern int cfl_diwufa_closetime;//底物阀关闭时间

extern int DDW_StayTime; //等待位电机关闭持续的时间

extern int FYP_ActionTime;  //孵育盘转动对应位置花费的时间
extern int GJC_WorkTime;   //光检测需要的时间
extern int GJC_StayTime;    //各项动作之间的等待时间

//串口通讯
extern int g_i;
extern long long g_average;
extern long long g[10];