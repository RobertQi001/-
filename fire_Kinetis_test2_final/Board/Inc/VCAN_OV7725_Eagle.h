/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       VCAN_OV7725_Eagle.h
 * @brief      ӥ��ov7725��������
 * @author     ɽ��Ƽ�
 * @version    v5.0
 * @date       2013-09-07
 */

#ifndef _VCAN_OV7725_EAGLE_H_
#define _VCAN_OV7725_EAGLE_H_

#include "VCAN_OV7725_REG.h"

#if (USE_CAMERA == CAMERA_OV7725_EAGLE)
//��������ͷ������
#define CAMERA_USE_HREF     0               //�Ƿ�ʹ�� ���ж� (0 Ϊ ��ʹ�ã�1Ϊʹ��)
#define CAMERA_COLOR        0               //����ͷ�����ɫ �� 0 Ϊ �ڰ׶�ֵ��ͼ�� ��1 Ϊ �Ҷ� ͼ�� ��2 Ϊ RGB565 ͼ��
#define CAMERA_POWER        0               //����ͷ ��Դѡ�� 0 Ϊ 3.3V ,1 Ϊ 5V

//��������ͷ����ӿ�
#define camera_init(imgaddr)    ov7725_eagle_init(imgaddr)
#define camera_get_img()        ov7725_eagle_get_img()

#define camera_vsync()          ov7725_eagle_vsync()
#define camera_href()           //ov7725_eagle_href()
#define camera_dma()            ov7725_eagle_dma()

//���� ����ͷ ����
#define CAMERA_DMA_CH       OV7725_EAGLE_DMA_CH         //��������ͷ��DMA�ɼ�ͨ��
#define CAMERA_W            OV7725_EAGLE_W              //��������ͷͼ����
#define CAMERA_H            OV7725_EAGLE_H              //��������ͷͼ��߶�

#define CAMERA_SIZE         OV7725_EAGLE_SIZE           //ͼ��ռ�ÿռ��С
#define CAMERA_DMA_NUM      OV7725_EAGLE_DMA_NUM        //DMA�ɼ�����

#endif //#if ( USE_CAMERA == CAMERA_OV7725_EAGLE )

//��������ͷ ����
#define OV7725_EAGLE_DMA_CH       DMA_CH0                               //��������ͷ��DMA�ɼ�ͨ��
#define OV7725_EAGLE_W            160                                   //��������ͷͼ����
#define OV7725_EAGLE_H            120                                   //��������ͷͼ��߶�
#define OV7725_EAGLE_SIZE         (OV7725_EAGLE_W * OV7725_EAGLE_H/8 )  //ͼ��ռ�ÿռ��С
#define OV7725_EAGLE_DMA_NUM      (OV7725_EAGLE_SIZE )                  //DMA�ɼ�����

/*
**���ӥ������ͷ����ʱ���ڴ��޸������ź�MK60_it.h���޸ĺ�����ͷ��Ӧ��PORT�жϼ����ж�λ����
*/
//��������ͷ ����
#define OV7725_EAGLE_PLCK                PTB9                           //����ͷ����ʱ��
#define OV7725_EAGLE_PLCK_CHANNEL        9
#define OV7725_EAGLE_VSYNC               PTB8                           //����ͷ��ͬ���ź�
#define OV7725_EAGLE_VSYNC_CHANNEL       8                              //OV7725_EAGLE_VSYNC��Ӧ���ŵ����ź� PTB8   -->     8
#define OV7725_EAGLE_INTERRUPT_NUNBERS   PORTB_IRQn                     //�жϱ��
#define OV7725_EAGLE_INTERRUPT_ISFR      PORTB_ISFR                     //�жϱ�־λ
#define OV7725_EAGLE_DATAPORT            PTB_B0_IN	                //DMA���ݿڣ�BO��ʾB0-B7,B1��ʾB8-B15���Դ�����
#define OV7725_EAGLE_SCCB_SCL            PTB21
#define OV7725_EAGLE_SCCB_SDA            PTB20


extern  uint8   ov7725_eagle_init(uint8 *imgaddr);
extern  void    ov7725_eagle_get_img(void);

extern  void    ov7725_eagle_vsync(void);
extern  void    ov7725_eagle_dma(void);


#endif  //_VCAN_OV7725_EAGLE_H_


