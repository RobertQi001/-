/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       MK60_it.c
 * @brief      ɽ��K60 ƽ̨�жϷ�����
 * @author     ɽ��Ƽ�
 * @version    v5.0
 * @date       2013-06-26
 */

#include "include.h"
#include "extern.h"

/*!
 *  @brief      PORTA�жϷ�����
 *  @since      v5.0
 */
void PORTC_IRQHandler()
{
    uint8  n = 0;    //���ź�
    uint32 flag = PORTC_ISFR;
    PORTC_ISFR  = ~0;                                   //���жϱ�־λ

    n = 7;                                              //���ж�
    if(flag & (1 << n))                                 //PTA29�����ж�
    {
        camera_vsync();
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      UART3�ж�ִ�к���
//  @return     void   
//  @since      v1.0
//  Sample usage:               ��UART3�����жϹ����ҷ����жϵ�ʱ����Զ�ִ�иú���
//-------------------------------------------------------------------------------------------------------------------
void uart5_handler(void)
{
  UARTn_e uratn = UART5;
  if(UART_S1_REG(UARTN[uratn]) & UART_S1_RDRF_MASK)                                     //�������ݼĴ�����
  {
    //�û���Ҫ�����������
    mt9v032_cof_uart_interrupt();
  }
  if(UART_S1_REG(UARTN[uratn]) & UART_S1_TDRE_MASK )  //�������ݼĴ�����
  {
    //�û���Ҫ����������
  }
}

/*!
 *  @brief      DMA0�жϷ�����
 *  @since      v5.0
 */
void DMA0_IRQHandler()
{
    camera_dma();
}

