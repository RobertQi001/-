#ifndef __DEFINE_H__
#define __DEFINE_H__

#include "include.h"

/************************************图像处理*************************************/
uint8 img_handle[CAMERA_H][CAMERA_W];           //由于鹰眼摄像头是一字节8个像素，因而需要解压为 1字节1个像素，方便处理
//int16 start_points[CAMERA_H];                   //每行边缘提取/扫线的起点数组
//int16 L_Line[CAMERA_H];                         //左线
//int16 R_Line[CAMERA_H];                         //右线
//int16 M_Line[CAMERA_H];                         //中线
//uint8 last_start_point = 0;                     //上一场图像最低一行的扫线起点
int16 Mline[120];
int16 Sig_MidLine;
int16 Sig_Midrow;
int16 size;
int16 error;
//int base=5;







//鹰眼OV7725
uint8 img_buff[CAMERA_SIZE];                    //定义存储接收图像的数组
uint8 img_buff2[CAMERA_SIZE];                   //定义存储接收图像的数组

uint8 img_switch_flag = 0;                      //图像地址切换标志

//总钻风MT9V032
uint8   image[CAMERA_H][CAMERA_W];              //图像数组


#endif