#ifndef __DEFINE_H__
#define __DEFINE_H__

#include "include.h"

/************************************ͼ����*************************************/
uint8 img_handle[CAMERA_H][CAMERA_W];           //����ӥ������ͷ��һ�ֽ�8�����أ������Ҫ��ѹΪ 1�ֽ�1�����أ����㴦��
//int16 start_points[CAMERA_H];                   //ÿ�б�Ե��ȡ/ɨ�ߵ��������
//int16 L_Line[CAMERA_H];                         //����
//int16 R_Line[CAMERA_H];                         //����
//int16 M_Line[CAMERA_H];                         //����
//uint8 last_start_point = 0;                     //��һ��ͼ�����һ�е�ɨ�����
int16 Mline[120];
int16 Sig_MidLine;
int16 Sig_Midrow;
int16 size;
int16 error;
//int base=5;







//ӥ��OV7725
uint8 img_buff[CAMERA_SIZE];                    //����洢����ͼ�������
uint8 img_buff2[CAMERA_SIZE];                   //����洢����ͼ�������

uint8 img_switch_flag = 0;                      //ͼ���ַ�л���־

//�����MT9V032
uint8   image[CAMERA_H][CAMERA_W];              //ͼ������


#endif