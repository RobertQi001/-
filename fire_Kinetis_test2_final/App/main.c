/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       main.c
 * @brief      ɽ��K60 ƽ̨������
 * @author     ɽ��Ƽ�
 * @version    v5.3
 * @date       2015-04-07
 */

#include "include.h"
#include "extern.h"    
#include "system.h"
#define MOTOR_HZ    10000//(20*1000)


void Get_line(int);
void go();
void left_roll();
void right_roll();
void l_f();
void l_b();
void r_f();
void r_b();
void direction_control(float,float);
int B=30;
int T=50;

void  main(void)
{
  int lost_flag=0;
//  int stop=0;
  int last_size; 
  int last_sig_midline;
  int last_sig_midrow;
//  int final_sig_midline;
  double reference_line;
  float p=6.6,i=0.36;  
  System_init();
  ftm_pwm_init(MOTOR_FTM, MOTOR1_PWM,MOTOR_HZ,0);      //��ʼ�� ��� PWM
  ftm_pwm_init(MOTOR_FTM, MOTOR2_PWM,MOTOR_HZ,0);      //��ʼ�� ��� PWM
  ftm_pwm_init(MOTOR_FTM, MOTOR3_PWM,MOTOR_HZ,0);      //��ʼ�� ��� PWM
  ftm_pwm_init(MOTOR_FTM, MOTOR4_PWM,MOTOR_HZ,0);      //��ʼ�� ��� PWM
  ftm_pwm_init(MOTOR_FTM, MOTOR5_PWM,MOTOR_HZ,0);      //��ʼ�� ��� PWM
  ftm_pwm_init(MOTOR_FTM, MOTOR6_PWM,MOTOR_HZ,0);      //��ʼ�� ��� PWM
  ftm_pwm_init(MOTOR_FTM, MOTOR7_PWM,MOTOR_HZ,0);      //��ʼ�� ��� PWM
  ftm_pwm_init(MOTOR_FTM, MOTOR8_PWM,MOTOR_HZ,0);      //��ʼ�� ��� PWM
    
  uint8 ptb22_data = gpio_get(PTB22);
  uint8 ptb23_data = gpio_get(PTB23);
  uint8 ptb20_data = gpio_get(PTB20);
  uint8 ptb21_data = gpio_get(PTB21);
  
  while(1)
  {

//          seekfree_sendimg_032();
//          if(key_check(KEY_U) ==  KEY_DOWN)
//            p+=0.1;
//          if(key_check(KEY_D) ==  KEY_DOWN)
//            p-=0.1;
//          if(key_check(KEY_L) ==  KEY_DOWN)
//            i+=0.01;
//          if(key_check(KEY_R) ==  KEY_DOWN)
//            i-=0.01;
//          LED_P6x8Str(0,6,"p");
//          LED_PrintValueF(10,6,p,1);
//          LED_P6x8Str(40,6,"i");
//          LED_PrintValueF(50,6,i,2);
//          
          if(key_check(KEY_U) ==  KEY_DOWN)
            T+=10;
          if(key_check(KEY_D) ==  KEY_DOWN)
            T-=10;
          LED_P6x8Str(0,6,"T");
          LED_PrintValueF(10,6,T,1);
       
         
//          if(ptb22_data == 1)
//          {
//            B=35;
//          }
//          if(ptb23_data==1)
//          {
//            B=30;
//          }
//          if(ptb20_data==0)
//          {
//            B=25;
//          }

//          LED_P6x8Str(0,5,"B");
//          LED_P6x8int(10,5,B);

//         l_f(20);//w1
//         r_f(-10);//w2
//         l_b(20);//w3
//         r_b(-10);//w4
//
//         //vx=R/4(w1+w2+w3+w4)
//         //vy=R/4(-w1+w2+w3-w4)
//         //wz=R/4(L+l)*(-w1+w2-w3+w4)
//         
//         
//         //v1w=vx-vy-(L+l)wz
//         //v2w=vx+vy+(L+l)wz
//         //v3w=vx+vy-(L+l)wz
//         //v4w=vx-vy+(L+l)wz
    /*****************************�����MT9V032****************************************/
    if(mt9v032_finish_flag)
    {
//                seekfree_sendimg_032();

      mt9v032_finish_flag = 0;
         Get_line(T);

          if(ptb21_data==1)
          {
            ScreenShow();
          }


         if(Sig_MidLine==1)
           lost_flag++;
         if(Sig_MidLine!=1)
           lost_flag=0;
//          if((Sig_MidLine-last_sig_midline)<2 ||(Sig_MidLine-last_sig_midline)>-2 && Sig_MidLine!=1)
//             stop++;
//           else
//              stop=0;
//              if(stop>9)
//              {
//                l_f(-20);
//                l_b(20);
//                r_f(20);
//                r_b(-20);
//                break;
//              }
//           if(Sig_Midrow>50)
//         {
//           go(15);
//           DELAY_MS(10);
//           final_sig_midline=Sig_MidLine;
//         }
         if((lost_flag>0)&&(lost_flag<10))
         {
           size=last_size;
           Sig_MidLine=last_sig_midline;
           Sig_Midrow=last_sig_midrow;
         
          if(Sig_MidLine>=80)
          reference_line=-0.02728*Sig_Midrow*Sig_Midrow+3.046*Sig_Midrow+72.96;           //�������
          else
          reference_line=0.02728*Sig_Midrow*Sig_Midrow-3.046*Sig_Midrow+87.04;
          error=Sig_MidLine-(int16)reference_line;                       //ƫ��
          direction_control(p,i);
         }
         
//         LED_P6x8Str(0,4,"size");
//         LED_P6x8int(30,4,size);
//         if(size>45)
//           left_f();
//         if (size>24)
//         {
//           go(15); 
//           DELAY_MS(500);
//         }
         if(Sig_Midrow>50)
         {
           go(15);
           DELAY_MS(10);
//           final_sig_midline=Sig_MidLine;
         }
           if(lost_flag>9)
         {
//           DELAY_MS(50);
//           if(Sig_MidLine>80)
//           if(final_sig_midline>80)
//           {
           l_b(20);
           r_b(-20);
//            left_roll(15);  
//           }
//            if(final_sig_midline<80)
//            {
//              l_b(-20);
//              r_b(20);
//            }
//           if(Sig_MidLine<80)
//             right_roll(25);
//           drift(25);
           
//           left_roll(15);
//           r_f(0);
//           r_b(0);
         }
         
//         }
//          LED_P6x8Str(0,0,"ref_line");
//          LED_PrintValueF(50,0,reference_line,4);
//          LED_P6x8Str(0,1,"Sig_MidLine");
//          LED_P6x8int(70,1,Sig_MidLine);
//          LED_P6x8Str(0,2,"error");
//          LED_PrintValueF(50,2,error,4);
//          LED_P6x8Str(0,3,"Sig_Midrow");
//          LED_P6x8int(70,3,Sig_Midrow);
          last_sig_midline=Sig_MidLine;
          last_sig_midrow=Sig_Midrow;
          last_size=size;
    
    }
    
    /**********************************************************************************/
  }
}
void go(int duty){
  
        ftm_pwm_duty(MOTOR_FTM, MOTOR1_PWM,duty);
        ftm_pwm_duty(MOTOR_FTM, MOTOR2_PWM,0);
        ftm_pwm_duty(MOTOR_FTM, MOTOR3_PWM,duty);
        ftm_pwm_duty(MOTOR_FTM, MOTOR4_PWM,0);
        ftm_pwm_duty(MOTOR_FTM, MOTOR5_PWM,duty);
        ftm_pwm_duty(MOTOR_FTM, MOTOR6_PWM,0);
        ftm_pwm_duty(MOTOR_FTM, MOTOR7_PWM,duty);
        ftm_pwm_duty(MOTOR_FTM, MOTOR8_PWM,0);
        
}
//void go_slow(){
//        ftm_pwm_duty(MOTOR_FTM, MOTOR1_PWM,10);
//        ftm_pwm_duty(MOTOR_FTM, MOTOR2_PWM,0);
//        ftm_pwm_duty(MOTOR_FTM, MOTOR3_PWM,10);
//        ftm_pwm_duty(MOTOR_FTM, MOTOR4_PWM,0);
//        ftm_pwm_duty(MOTOR_FTM, MOTOR5_PWM,10);
//        ftm_pwm_duty(MOTOR_FTM, MOTOR6_PWM,0);
//        ftm_pwm_duty(MOTOR_FTM, MOTOR7_PWM,10);
//        ftm_pwm_duty(MOTOR_FTM, MOTOR8_PWM,0);
//        
//}
//void back(int duty){
//        ftm_pwm_duty(MOTOR_FTM, MOTOR1_PWM,0);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
//        ftm_pwm_duty(MOTOR_FTM, MOTOR2_PWM,duty);//��ǰ����ת
//        ftm_pwm_duty(MOTOR_FTM, MOTOR3_PWM,0);//��ǰ�ַ�ת
//        ftm_pwm_duty(MOTOR_FTM, MOTOR4_PWM,duty);//��ǰ����ת
//        ftm_pwm_duty(MOTOR_FTM, MOTOR5_PWM,0);//�Һ�����ת
//        ftm_pwm_duty(MOTOR_FTM, MOTOR6_PWM,duty);//�Һ��ַ�ת
//        ftm_pwm_duty(MOTOR_FTM, MOTOR7_PWM,0);//�������ת
//        ftm_pwm_duty(MOTOR_FTM, MOTOR8_PWM,duty);//����ַ�ת
//        
//}
void left_roll(int duty){
        ftm_pwm_duty(MOTOR_FTM, MOTOR1_PWM,0);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
        ftm_pwm_duty(MOTOR_FTM, MOTOR2_PWM,duty);//��ǰ����ת
        ftm_pwm_duty(MOTOR_FTM, MOTOR3_PWM,duty);//��ǰ�ַ�ת
        ftm_pwm_duty(MOTOR_FTM, MOTOR4_PWM,0);//��ǰ����ת
        ftm_pwm_duty(MOTOR_FTM, MOTOR6_PWM,duty);//�Һ�����ת
        ftm_pwm_duty(MOTOR_FTM, MOTOR5_PWM,0);//�Һ��ַ�ת
        ftm_pwm_duty(MOTOR_FTM, MOTOR8_PWM,0);//�������ת
        ftm_pwm_duty(MOTOR_FTM, MOTOR7_PWM,duty);//����ַ�ת
        
}
void right_roll(int duty){
        ftm_pwm_duty(MOTOR_FTM, MOTOR1_PWM,duty);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
        ftm_pwm_duty(MOTOR_FTM, MOTOR2_PWM,0);//��ǰ����ת
        ftm_pwm_duty(MOTOR_FTM, MOTOR3_PWM,0);//��ǰ�ַ�ת
        ftm_pwm_duty(MOTOR_FTM, MOTOR4_PWM,duty);//��ǰ����ת
        ftm_pwm_duty(MOTOR_FTM, MOTOR6_PWM,0);//�Һ�����ת
        ftm_pwm_duty(MOTOR_FTM, MOTOR5_PWM,duty);//�Һ��ַ�ת
        ftm_pwm_duty(MOTOR_FTM, MOTOR8_PWM,duty);//�������ת
        ftm_pwm_duty(MOTOR_FTM, MOTOR7_PWM,0);//����ַ�ת
        
}
//void left_f(){
//        ftm_pwm_duty(MOTOR_FTM, MOTOR1_PWM,0);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
//        ftm_pwm_duty(MOTOR_FTM, MOTOR2_PWM,0);//��ǰ����ת
//        ftm_pwm_duty(MOTOR_FTM, MOTOR3_PWM,20);//��ǰ�ַ�ת
//        ftm_pwm_duty(MOTOR_FTM, MOTOR4_PWM,0);//��ǰ����ת
//        ftm_pwm_duty(MOTOR_FTM, MOTOR5_PWM,0);//�Һ�����ת
//        ftm_pwm_duty(MOTOR_FTM, MOTOR6_PWM,0);//�Һ��ַ�ת
//        ftm_pwm_duty(MOTOR_FTM, MOTOR7_PWM,20);//�������ת
//        ftm_pwm_duty(MOTOR_FTM, MOTOR8_PWM,0);//����ַ�ת
//}
//void drift(int duty){
//        ftm_pwm_duty(MOTOR_FTM, MOTOR1_PWM,0);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
//        ftm_pwm_duty(MOTOR_FTM, MOTOR2_PWM,0);//��ǰ����ת
//        ftm_pwm_duty(MOTOR_FTM, MOTOR3_PWM,duty);//��ǰ�ַ�ת
//        ftm_pwm_duty(MOTOR_FTM, MOTOR4_PWM,0);//��ǰ����ת
//        ftm_pwm_duty(MOTOR_FTM, MOTOR5_PWM,duty);//�Һ�����ת
//        ftm_pwm_duty(MOTOR_FTM, MOTOR6_PWM,0);//�Һ��ַ�ת
//        ftm_pwm_duty(MOTOR_FTM, MOTOR7_PWM,0);//�������ת
//        ftm_pwm_duty(MOTOR_FTM, MOTOR8_PWM,duty);//����ַ�ת
//}
void l_f(int duty)
{
  if(duty>=0)
  {
      ftm_pwm_duty(MOTOR_FTM, MOTOR1_PWM,duty);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
      ftm_pwm_duty(MOTOR_FTM, MOTOR2_PWM,0);//��ǰ����ת
  }
  else
  {
    ftm_pwm_duty(MOTOR_FTM, MOTOR1_PWM,0);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
    ftm_pwm_duty(MOTOR_FTM, MOTOR2_PWM,-duty);//��ǰ����ת
  }
}
void l_b(int duty)
{
  if(duty>=0)
  {
      ftm_pwm_duty(MOTOR_FTM, MOTOR8_PWM,duty);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
      ftm_pwm_duty(MOTOR_FTM, MOTOR7_PWM,0);//��ǰ����ת
  }
  else
  {
    ftm_pwm_duty(MOTOR_FTM, MOTOR8_PWM,0);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
    ftm_pwm_duty(MOTOR_FTM, MOTOR7_PWM,-duty);//��ǰ����ת
  }
}
void r_f(int duty)
{
  if(duty>=0)
  {
      ftm_pwm_duty(MOTOR_FTM, MOTOR3_PWM,duty);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
      ftm_pwm_duty(MOTOR_FTM, MOTOR4_PWM,0);//��ǰ����ת
  }
  else
  {
    ftm_pwm_duty(MOTOR_FTM, MOTOR3_PWM,0);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
    ftm_pwm_duty(MOTOR_FTM, MOTOR4_PWM,-duty);//��ǰ����ת
  }
}
void r_b(int duty)
{
  if(duty>=0)
  {
      ftm_pwm_duty(MOTOR_FTM, MOTOR6_PWM,duty);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
      ftm_pwm_duty(MOTOR_FTM, MOTOR5_PWM,0);//��ǰ����ת
  }
  else
  {
    ftm_pwm_duty(MOTOR_FTM, MOTOR6_PWM,0);//��ǰ�ַ�ת//��ɫ��������ռ�ձȣ�����д50����
    ftm_pwm_duty(MOTOR_FTM, MOTOR5_PWM,-duty);//��ǰ����ת
  }
}
/*****************************ӥ��OV7725*******************************************/
//    //��ȡͼ��
//    camera_get_img();                                    //����ͷ��ȡͼ��
//    //��ѹͼ��       
////    if(img_switch_flag == 0)
////      img_extract(img_handle,img_buffer2,CAMERA_SIZE);
////    else if(img_switch_flag == 1)
////      img_extract(img_handle,img_buffer,CAMERA_SIZE);    
//    //��ͼ���͵���λ��
//    if(img_switch_flag == 0)
//      vcan_sendimg(img_buff, CAMERA_SIZE);                  
//    else
//      vcan_sendimg(img_buff2, CAMERA_SIZE);  
//    while(ov7725_eagle_img_flag != IMG_FINISH)          //�ȴ�ͼ��ɼ����
//    {
//      if(ov7725_eagle_img_flag == IMG_FAIL)             //����ͼ��ɼ����������¿�ʼ�ɼ�
//      {
//        ov7725_eagle_img_flag = IMG_START;              //��ʼ�ɼ�ͼ��
//        OV7725_EAGLE_INTERRUPT_ISFR = ~0;               //д1���жϱ�־λ(����ģ���Ȼ�ص���һ���жϾ����ϴ����ж�)
//        enable_irq(OV7725_EAGLE_INTERRUPT_NUNBERS);     //����PTA���ж�
//      }
//    }
/**********************************************************************************/