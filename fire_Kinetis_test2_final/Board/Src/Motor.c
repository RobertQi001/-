/********************************S-D�������**********************************
*
*����   �� ɳ���Ѿ�
*�ļ��� �� Motor.c
*����   �� �����������
*ʱ��   �� 2015/11/2
*
****************************************************************************/

#include  "Motor.h"
#include "extern.h"
#define base B-size
//#define base B


motor_status motor;
//void l_f();
//void l_b();
//void r_f();
//void r_b();
void left_move();
void right_move();
/*************************************************************************
                     ɳ���Ѿ�
�������ƣ�motor_init()
��ڲ�������
���ڲ�������
�޸�ʱ�䣺2015/11/2
����˵�������������ʼ��
����˵�����ο�let_it_goԴ����
************************************************************************/
 
//void Motor_init(void)
//{
//        ftm_pwm_init(GO_FTM,GO_CH,MOTOR_FRE,0);    
//        ftm_pwm_init(BACK_FTM,BACK_CH,MOTOR_FRE,0);     
//}

/*************************************************************************
                     ɳ���Ѿ�
�������ƣ� void speed_control(void)
��ڲ�������
���ڲ�������
�޸�ʱ�䣺2015/11/2
����˵����
����˵�����ο�let_it_goԴ���� ʹ��ɽ��V5.3��
************************************************************************/
 
void direction_control(float p,float i)
{    
//         l_f(20);//w1
//         r_f(-10);//w2
//         l_b(20);//w3
//         r_b(-10);//w4
         motor.line_p=p;
         motor.line_i=i;
         motor.line_last_error = motor.line_current_error ;        //����ÿ�εĲ�ֵ
         motor.line_current_error = error;   //ƫ�ǰ��ֵ
         
         motor.line_duty_output = (int16)(motor.line_i*motor.line_current_error+motor.line_p*(motor.line_current_error-motor.line_last_error));      
         if(motor.line_duty_output>30)
         {
            motor.line_duty_output=30;
         }
         if(motor.line_duty_output<-30)
         {
            motor.line_duty_output=-30;
         }
         if(motor.line_duty_output>=0)
         {
            l_f(base+motor.line_duty_output);
            l_b(base+motor.line_duty_output);
            r_f(base);
            r_b(base);
         }
         else
         {
            l_f(base);
            l_b(base);
            r_f(base-motor.line_duty_output);
            r_b(base-motor.line_duty_output);
         }
         
         
//         if((motor.line_duty_output<10&&motor.line_duty_output>0)||(motor.line_duty_output>-10&&motor.line_duty_output<0))
//         {
//            go(25);
//         }
//         else
//         {
//          if(motor.line_duty_output>30)
//         {
//            motor.line_duty_output=30;
//         }
//         if(motor.line_duty_output<-30)
//         {
//            motor.line_duty_output=-30;
//         }
//                  LED_PrintValueF(0,5,motor.line_duty_output,4);
//     
////        if(motor.speed_duty_output>=990)
////            motor.speed_duty_output = 990;
////        if(motor.speed_duty_output<=-990)
////              motor.speed_duty_output = -990; 
//        
////        if(motor.speed < 150 )
////        {
////            ftm_pwm_duty(GO_FTM,GO_CH,0);
////            ftm_pwm_duty(BACK_FTM,BACK_CH,0); 
////        }
////        else
////        {  
//            if(motor.line_duty_output>=0)    
//            {
//                l_f(motor.line_duty_output+base);//w1
//                r_f(0);//w2
//                l_b(0);//w3
//                r_b(motor.line_duty_output+base);//w4
////                  right_move(motor.line_duty_output);
//                //vx=R/4(w1+w2+w3+w4)
//                //vy=R/4(-w1+w2+w3-w4)
//                //wz=R/4(L+l)*(-w1+w2-w3+w4)
//         
//         
//                //v1w=vx-vy-(L+l)wz
//                //v2w=vx+vy+(L+l)wz
//                //v3w=vx+vy-(L+l)wz
//                //v4w=vx-vy+(L+l)wz    
//            }
//            else
//            {        
//                l_f(0);//w1
//                r_f(-motor.line_duty_output+base);//w2
//                l_b(-motor.line_duty_output+base);//w3
//                r_b(0);//w4    
////              left_move(-motor.line_duty_output);
//            }   
        }



//void l_f(int duty)
//{
//  if(duty>=0)
//  {
//      ftm_pwm_duty(MOTOR_FTM, MOTOR1_PWM,duty);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
//      ftm_pwm_duty(MOTOR_FTM, MOTOR2_PWM,0);//��ǰ����ת
//  }
//  else
//  {
//    ftm_pwm_duty(MOTOR_FTM, MOTOR1_PWM,0);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
//    ftm_pwm_duty(MOTOR_FTM, MOTOR2_PWM,-duty);//��ǰ����ת
//  }
//}
//void l_b(int duty)
//{
//  if(duty>=0)
//  {
//      ftm_pwm_duty(MOTOR_FTM, MOTOR7_PWM,duty);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
//      ftm_pwm_duty(MOTOR_FTM, MOTOR8_PWM,0);//��ǰ����ת
//  }
//  else
//  {
//    ftm_pwm_duty(MOTOR_FTM, MOTOR7_PWM,0);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
//    ftm_pwm_duty(MOTOR_FTM, MOTOR8_PWM,-duty);//��ǰ����ת
//  }
//}
//void r_f(int duty)
//{
//  if(duty>=0)
//  {
//      ftm_pwm_duty(MOTOR_FTM, MOTOR3_PWM,duty);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
//      ftm_pwm_duty(MOTOR_FTM, MOTOR4_PWM,0);//��ǰ����ת
//  }
//  else
//  {
//    ftm_pwm_duty(MOTOR_FTM, MOTOR3_PWM,0);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
//    ftm_pwm_duty(MOTOR_FTM, MOTOR4_PWM,-duty);//��ǰ����ת
//  }
//}
//void r_b(int duty)
//{
//  if(duty>=0)
//  {
//      ftm_pwm_duty(MOTOR_FTM, MOTOR5_PWM,duty);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
//      ftm_pwm_duty(MOTOR_FTM, MOTOR6_PWM,0);//��ǰ����ת
//  }
//  else
//  {
//    ftm_pwm_duty(MOTOR_FTM, MOTOR5_PWM,0);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
//    ftm_pwm_duty(MOTOR_FTM, MOTOR6_PWM,-duty);//��ǰ����ת
//  }
//}
void left_move(int duty){
  
        ftm_pwm_duty(MOTOR_FTM, MOTOR1_PWM,0);
        ftm_pwm_duty(MOTOR_FTM, MOTOR2_PWM,duty);
        ftm_pwm_duty(MOTOR_FTM, MOTOR3_PWM,0);
        ftm_pwm_duty(MOTOR_FTM, MOTOR4_PWM,duty);
        ftm_pwm_duty(MOTOR_FTM, MOTOR5_PWM,0);
        ftm_pwm_duty(MOTOR_FTM, MOTOR6_PWM,duty);
        ftm_pwm_duty(MOTOR_FTM, MOTOR7_PWM,duty);
        ftm_pwm_duty(MOTOR_FTM, MOTOR8_PWM,0);
        
}
void right_move(int duty){
  
        ftm_pwm_duty(MOTOR_FTM, MOTOR1_PWM,duty);
        ftm_pwm_duty(MOTOR_FTM, MOTOR2_PWM,0);
        ftm_pwm_duty(MOTOR_FTM, MOTOR3_PWM,duty);
        ftm_pwm_duty(MOTOR_FTM, MOTOR4_PWM,0);
        ftm_pwm_duty(MOTOR_FTM, MOTOR5_PWM,duty);
        ftm_pwm_duty(MOTOR_FTM, MOTOR6_PWM,0);
        ftm_pwm_duty(MOTOR_FTM, MOTOR7_PWM,0);
        ftm_pwm_duty(MOTOR_FTM, MOTOR8_PWM,duty);
        
}
void speed(float vx,float vy,float wz,float V[4])
{
  float J[4][3]={
                1,-1,-0.18,
                1,1,0.18,
                1,1,-0.18,
                1,-1,0.18};
  float v[3]={vx,vy,wz};
  int i,j;
  for(i=0;i<4;i++)
  {
      for(j=0;j<3;j++)
      {
          V[i]+=v[j]*J[i][j];
      }
  }
}
//uint8 Robust(int16 speed)
//{
//  if(motor.speed > speed)
//  {
//      ftm_pwm_duty(GO_FTM,GO_CH,0);
//      ftm_pwm_duty(BACK_FTM,BACK_CH,1000);   
//  }
//  else 
//    return 0;
//}
