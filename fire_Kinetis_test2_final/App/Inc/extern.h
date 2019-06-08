#ifndef __EXTERN_H__
#define __EXTERN_H__

#include "include.h"

/************************************图像处理*************************************/
extern uint8 img_handle[CAMERA_H][CAMERA_W];           //由于鹰眼摄像头是一字节8个像素，因而需要解压为 1字节1个像素，方便处理
//extern int16 start_points[CAMERA_H];                   //每行边缘提取/扫线的起点数组
//extern int16 L_Line[CAMERA_H];                         //左线
//extern int16 R_Line[CAMERA_H];                         //右线
//extern int16 M_Line[CAMERA_H];                         //中线
extern int16 Mline[120];
extern int16 Sig_MidLine;
extern int16 Sig_Midrow;
extern int16 size;
extern int16 error;
extern uint8 last_start_point;                         //上一场图像最低一行的扫线起点
extern int B;


//鹰眼OV7725
extern uint8 img_buff[CAMERA_SIZE];                    //定义存储接收图像的数组
extern uint8 img_buff2[CAMERA_SIZE];                   //定义存储接收图像的数组

extern uint8 img_switch_flag;                          //图像地址切换标志

//总钻风MT9V032
extern uint8 image[CAMERA_H][CAMERA_W];

#endif