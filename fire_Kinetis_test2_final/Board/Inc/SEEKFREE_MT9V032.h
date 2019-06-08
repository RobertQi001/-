/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2016,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：179029047
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 * 
 * @file       		SEEKFREE_MT9V032.h
 * @brief      		总钻风(灰度摄像头)函数库
 * @company	   		成都逐飞科技有限公司
 * @author     		Go For It(1325536866)
 * @version    		v1.0
 * @Software 		IAR 7.2 or MDK 5.17
 * @Target core		MK60DN512VLL10
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2016-02-25
 * @note	
					MT9V032接线定义：
					------------------------------------ 
						模块管脚            单片机管脚
						SDA(51的RX)         C17
						SCL(51的TX)         C16
						场中断              C6
						行中断				未使用，因此不接
						像素中断            C18           
						数据口              C8-C15 
					------------------------------------ 
	
					默认分辨率是            188*70
					默认FPS                 50帧
 ********************************************************************************************************************/



#ifndef _MT9V032_h
#define _MT9V032_h

#include "include.h"

#if (USE_CAMERA == CAMERA_MT9V032)
//配置摄像头顶层接口
#define camera_init(imgaddr)    mt9v032_init(imgaddr)
//#define camera_get_img()        ov7725_eagle_get_img()
#define camera_vsync()          mt9v032_vsync()
//#define camera_href()           //ov7725_eagle_href()
#define camera_dma()            mt9v032_dma()
//
////配置 摄像头 参数
#define CAMERA_DMA_CH        MT9V032_DMA_CH         //定义摄像头的DMA采集通道
#define CAMERA_W             MT9V032_W              //定义摄像头图像宽度
#define CAMERA_H             MT9V032_H              //定义摄像头图像高度
#define CAMERA_SIZE          MT9V032_SIZE           //图像占用空间大小
#define CAMERA_DMA_NUM       MT9V032_DMA_NUM        //DMA采集次数
#endif

//摄像头命令枚举
typedef enum
{
    INIT_032 = 0,           //摄像头初始化命令
    AUTO_EXP,               //自动曝光命令
    EXP_TIME,               //曝光时间命令
    FPS,                    //摄像头帧率命令
    SET_COL,                //图像列命令
    SET_ROW,                //图像行命令
    LR_OFFSET,              //图像左右偏移命令
    UD_OFFSET,              //图像上下偏移命令
    GAIN,                   //图像偏移命令
    CONFIG_FINISH,          //非命令位，主要用来占位计数
    
    SET_EXP_TIME = 0XF0,    //单独设置曝光时间命令
    GET_STATUS,             //获取摄像头配置命令
    GET_VERSION,            //固件版本号命令
    
    SET_ADDR = 0XFE,        //寄存器地址命令
    SET_DATA                //寄存器数据命令
}CMD;

//配置摄像头 属性
#define MT9V032_DMA_CH              DMA_CH0                              //定义摄像头的DMA采集通道
#define MT9V032_W                   160                                 //图像宽度   范围1-752     K60采集不允许超过188
#define MT9V032_H                   120                                 //图像高度	范围1-480
#define MT9V032_SIZE                (MT9V032_H * MT9V032_W / 8)         //图像占用空间大小
#define MT9V032_DMA_NUM             (MT9V032_SIZE )                      //DMA采集次数

/*
**变更总钻风摄像头引脚时，在此修改完引脚后到MK60_it.h中修改好摄像头对应的PORT中断及场中断位，
**并修改好51和K0通信用的UART中断函数即可（中断函数在摄像头初始化函数中设置）
*/
//配置摄像头 引脚
#define MT9V032_COF_UART            UART5                               //配置摄像头所使用到的串口     
#define MT9V032_PCLK                PTC0//                            	//摄像头像素时钟
#define MT9V032_VSYNC               PTC7//                            	//摄像头场同步信号
#define MT9V032_VSYNC_CHANNEL       7                                   //MT9V032_VSYNC对应引脚的引脚号 PTC6   -->     6
#define MT9V032_INTERRUPT_NUNBERS   PORTC_IRQn                          //中断编号
#define MT9V032_INTERRUPT_ISFR      PORTC_ISFR                          //中断标志位
#define MT9V032_DATAPORT            PTC_B1_IN	                        //DMA数据口，BO表示B0-B7,B1表示B8-B15，以此类推

extern uint8 mt9v032_finish_flag;  //一场图像采集完成标志位

void   mt9v032_cof_uart_interrupt(void);
void   mt9v032_vsync(void);
void   mt9v032_init(uint8 imgaddr[MT9V032_H][MT9V032_W]);
void   seekfree_sendimg_032(void);
void   mt9v032_dma(void);

#endif

