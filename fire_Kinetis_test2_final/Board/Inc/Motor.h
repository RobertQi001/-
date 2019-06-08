/********************************电机驱动**********************************
*
*作者   ： 沙艺已觉
*文件名 ： Motor.h
*描述   ： 电机驱动头文件
*时间   ： 2015/11/2
说明    ：参考let_it_go 源代码  使用山外V5.3库
*
****************************************************************************/
#ifndef   _MOTOR_H_
#define   _MOTOR_H_

#include "include.h"


typedef struct motor_status
{
    int16 line;                           //当前信标行
    int16 speed_set;                       //设定速度
    int16 last_line_set;                  //上次偏差
    float line_p;                         //P参数
    float line_i;                         //i参数
    int16  line_current_error;             //当前偏差
    int16  line_last_error;                //上次偏差 
    int16  line_duty_output;              //输出占空比
    int16  speed_filter_error[5];          //滤波数组   
}motor_status;


extern motor_status motor;

#define MOTOR_FTM   FTM0
#define MOTOR1_PWM  FTM_CH4
#define MOTOR2_PWM  FTM_CH5
#define MOTOR3_PWM  FTM_CH6
#define MOTOR4_PWM  FTM_CH7
#define MOTOR5_PWM  FTM_CH0
#define MOTOR6_PWM  FTM_CH1
#define MOTOR7_PWM  FTM_CH2
#define MOTOR8_PWM  FTM_CH3


/**************************************************************************
功能：    初始化引脚定义
说明:     直接在这里改IO就可以了 
时间：    2015/11/2
*************************************************************************/
//电机前进的FTM通道
//#define         GO_FTM     FTM0
//#define         GO_CH      FTM_CH7
////电机后退的FTM通道
//#define         BACK_FTM      FTM0
//#define         BACK_CH       FTM_CH6
//
////电机驱动频率
//#define         MOTOR_FRE       10000
//
////电机驱动初始化的占空比   
//#define INIT_DUTY   0


//void Motor_init(void) ;      //电机驱动初始化
//void speed_control();        //速度控制













#endif