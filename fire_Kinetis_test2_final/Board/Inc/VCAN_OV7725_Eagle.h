/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       VCAN_OV7725_Eagle.h
 * @brief      鹰眼ov7725驱动代码
 * @author     山外科技
 * @version    v5.0
 * @date       2013-09-07
 */

#ifndef _VCAN_OV7725_EAGLE_H_
#define _VCAN_OV7725_EAGLE_H_

#include "VCAN_OV7725_REG.h"

#if (USE_CAMERA == CAMERA_OV7725_EAGLE)
//配置摄像头的特性
#define CAMERA_USE_HREF     0               //是否使用 行中断 (0 为 不使用，1为使用)
#define CAMERA_COLOR        0               //摄像头输出颜色 ， 0 为 黑白二值化图像 ，1 为 灰度 图像 ，2 为 RGB565 图像
#define CAMERA_POWER        0               //摄像头 电源选择， 0 为 3.3V ,1 为 5V

//配置摄像头顶层接口
#define camera_init(imgaddr)    ov7725_eagle_init(imgaddr)
#define camera_get_img()        ov7725_eagle_get_img()

#define camera_vsync()          ov7725_eagle_vsync()
#define camera_href()           //ov7725_eagle_href()
#define camera_dma()            ov7725_eagle_dma()

//配置 摄像头 参数
#define CAMERA_DMA_CH       OV7725_EAGLE_DMA_CH         //定义摄像头的DMA采集通道
#define CAMERA_W            OV7725_EAGLE_W              //定义摄像头图像宽度
#define CAMERA_H            OV7725_EAGLE_H              //定义摄像头图像高度

#define CAMERA_SIZE         OV7725_EAGLE_SIZE           //图像占用空间大小
#define CAMERA_DMA_NUM      OV7725_EAGLE_DMA_NUM        //DMA采集次数

#endif //#if ( USE_CAMERA == CAMERA_OV7725_EAGLE )

//配置摄像头 属性
#define OV7725_EAGLE_DMA_CH       DMA_CH0                               //定义摄像头的DMA采集通道
#define OV7725_EAGLE_W            160                                   //定义摄像头图像宽度
#define OV7725_EAGLE_H            120                                   //定义摄像头图像高度
#define OV7725_EAGLE_SIZE         (OV7725_EAGLE_W * OV7725_EAGLE_H/8 )  //图像占用空间大小
#define OV7725_EAGLE_DMA_NUM      (OV7725_EAGLE_SIZE )                  //DMA采集次数

/*
**变更鹰眼摄像头引脚时，在此修改完引脚后到MK60_it.h中修改好摄像头对应的PORT中断及场中断位即可
*/
//配置摄像头 引脚
#define OV7725_EAGLE_PLCK                PTB9                           //摄像头像素时钟
#define OV7725_EAGLE_PLCK_CHANNEL        9
#define OV7725_EAGLE_VSYNC               PTB8                           //摄像头场同步信号
#define OV7725_EAGLE_VSYNC_CHANNEL       8                              //OV7725_EAGLE_VSYNC对应引脚的引脚号 PTB8   -->     8
#define OV7725_EAGLE_INTERRUPT_NUNBERS   PORTB_IRQn                     //中断编号
#define OV7725_EAGLE_INTERRUPT_ISFR      PORTB_ISFR                     //中断标志位
#define OV7725_EAGLE_DATAPORT            PTB_B0_IN	                //DMA数据口，BO表示B0-B7,B1表示B8-B15，以此类推
#define OV7725_EAGLE_SCCB_SCL            PTB21
#define OV7725_EAGLE_SCCB_SDA            PTB20


extern  uint8   ov7725_eagle_init(uint8 *imgaddr);
extern  void    ov7725_eagle_get_img(void);

extern  void    ov7725_eagle_vsync(void);
extern  void    ov7725_eagle_dma(void);


#endif  //_VCAN_OV7725_EAGLE_H_


