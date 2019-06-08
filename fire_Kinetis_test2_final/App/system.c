/********************************ϵͳ��ʼ��**********************************
*
*����   �� ɳ���Ѿ�
*�ļ��� �� System.c
*����   �� ϵͳ��ʼ��
*ʱ��   �� 2015/11/9
˵��    ��ʹ��ɽ��V5.3��20
*
****************************************************************************/
#include "system.h"
#include "include.h"
#include "extern.h"

void System_init(void)
{  
  /******************��ģ���ʼ��**************************/
  OLED_init();
  Tft_init();                                             //��ʾ����ʼ��
//  LCD_Clear(BLUE);                                        //����
  camera_init(image);                                     //����ͷ��ʼ��
  key_init (KEY_U);
  key_init (KEY_D);
  key_init (KEY_L);
  key_init (KEY_R);
  gpio_init(PTB21,GPI,0);
  gpio_init(PTB22,GPI,0);
  gpio_init(PTB23,GPI,0);
  gpio_init(PTB20,GPI,0);

    
  /****************�жϷ���������************************/
  set_vector_handler(PORTC_VECTORn ,PORTC_IRQHandler);    //����PORTC���жϷ�����Ϊ PORTC_IRQHandler
  set_vector_handler(DMA0_VECTORn ,DMA0_IRQHandler);      //����DMA0���жϷ�����Ϊ DMA0_IRQHandler
}