/********************************�������**********************************
*
*����   �� ɳ���Ѿ�
*�ļ��� �� Motor.h
*����   �� �������ͷ�ļ�
*ʱ��   �� 2015/11/2
˵��    ���ο�let_it_go Դ����  ʹ��ɽ��V5.3��
*
****************************************************************************/
#ifndef   _MOTOR_H_
#define   _MOTOR_H_

#include "include.h"


typedef struct motor_status
{
    int16 line;                           //��ǰ�ű���
    int16 speed_set;                       //�趨�ٶ�
    int16 last_line_set;                  //�ϴ�ƫ��
    float line_p;                         //P����
    float line_i;                         //i����
    int16  line_current_error;             //��ǰƫ��
    int16  line_last_error;                //�ϴ�ƫ�� 
    int16  line_duty_output;              //���ռ�ձ�
    int16  speed_filter_error[5];          //�˲�����   
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
���ܣ�    ��ʼ�����Ŷ���
˵��:     ֱ���������IO�Ϳ����� 
ʱ�䣺    2015/11/2
*************************************************************************/
//���ǰ����FTMͨ��
//#define         GO_FTM     FTM0
//#define         GO_CH      FTM_CH7
////������˵�FTMͨ��
//#define         BACK_FTM      FTM0
//#define         BACK_CH       FTM_CH6
//
////�������Ƶ��
//#define         MOTOR_FRE       10000
//
////���������ʼ����ռ�ձ�   
//#define INIT_DUTY   0


//void Motor_init(void) ;      //���������ʼ��
//void speed_control();        //�ٶȿ���













#endif