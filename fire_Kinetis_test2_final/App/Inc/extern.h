#ifndef __EXTERN_H__
#define __EXTERN_H__

#include "include.h"

/************************************ͼ����*************************************/
extern uint8 img_handle[CAMERA_H][CAMERA_W];           //����ӥ������ͷ��һ�ֽ�8�����أ������Ҫ��ѹΪ 1�ֽ�1�����أ����㴦��
//extern int16 start_points[CAMERA_H];                   //ÿ�б�Ե��ȡ/ɨ�ߵ��������
//extern int16 L_Line[CAMERA_H];                         //����
//extern int16 R_Line[CAMERA_H];                         //����
//extern int16 M_Line[CAMERA_H];                         //����
extern int16 Mline[120];
extern int16 Sig_MidLine;
extern int16 Sig_Midrow;
extern int16 size;
extern int16 error;
extern uint8 last_start_point;                         //��һ��ͼ�����һ�е�ɨ�����
extern int B;


//ӥ��OV7725
extern uint8 img_buff[CAMERA_SIZE];                    //����洢����ͼ�������
extern uint8 img_buff2[CAMERA_SIZE];                   //����洢����ͼ�������

extern uint8 img_switch_flag;                          //ͼ���ַ�л���־

//�����MT9V032
extern uint8 image[CAMERA_H][CAMERA_W];

#endif