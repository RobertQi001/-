/********************************系统初始化**********************************
*
*作者   ： 沙艺已觉
*文件名 ： System.c
*描述   ： 系统初始化
*时间   ： 2015/11/9
说明    ：使用山外V5.3库20
*
****************************************************************************/
#include "system.h"
#include "include.h"
#include "extern.h"

void System_init(void)
{  
  /******************各模块初始化**************************/
  OLED_init();
  Tft_init();                                             //显示屏初始化
//  LCD_Clear(BLUE);                                        //清屏
  camera_init(image);                                     //摄像头初始化
  key_init (KEY_U);
  key_init (KEY_D);
  key_init (KEY_L);
  key_init (KEY_R);
  gpio_init(PTB21,GPI,0);
  gpio_init(PTB22,GPI,0);
  gpio_init(PTB23,GPI,0);
  gpio_init(PTB20,GPI,0);

    
  /****************中断服务函数配置************************/
  set_vector_handler(PORTC_VECTORn ,PORTC_IRQHandler);    //设置PORTC的中断服务函数为 PORTC_IRQHandler
  set_vector_handler(DMA0_VECTORn ,DMA0_IRQHandler);      //设置DMA0的中断服务函数为 DMA0_IRQHandler
}