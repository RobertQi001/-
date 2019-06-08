/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       MK60_it.c
 * @brief      山外K60 平台中断服务函数
 * @author     山外科技
 * @version    v5.0
 * @date       2013-06-26
 */

#include "include.h"
#include "extern.h"

/*!
 *  @brief      PORTA中断服务函数
 *  @since      v5.0
 */
void PORTC_IRQHandler()
{
    uint8  n = 0;    //引脚号
    uint32 flag = PORTC_ISFR;
    PORTC_ISFR  = ~0;                                   //清中断标志位

    n = 7;                                              //场中断
    if(flag & (1 << n))                                 //PTA29触发中断
    {
        camera_vsync();
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      UART3中断执行函数
//  @return     void   
//  @since      v1.0
//  Sample usage:               当UART3启用中断功能且发生中断的时候会自动执行该函数
//-------------------------------------------------------------------------------------------------------------------
void uart5_handler(void)
{
  UARTn_e uratn = UART5;
  if(UART_S1_REG(UARTN[uratn]) & UART_S1_RDRF_MASK)                                     //接收数据寄存器满
  {
    //用户需要处理接收数据
    mt9v032_cof_uart_interrupt();
  }
  if(UART_S1_REG(UARTN[uratn]) & UART_S1_TDRE_MASK )  //发送数据寄存器空
  {
    //用户需要处理发送数据
  }
}

/*!
 *  @brief      DMA0中断服务函数
 *  @since      v5.0
 */
void DMA0_IRQHandler()
{
    camera_dma();
}

