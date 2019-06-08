#include "common.h"
#include "VCAN_camera.h"
#include "define.h"

#define GrayScale 256
#define height 120
#define width 160


void otsuThreshold(int);

//压缩二值化图像解压（空间 换 时间 解压）
//srclen 是二值化图像的占用空间大小
//【鹰眼解压】鹰眼图像解压，转为 二维数组 - 智能车资料区 - 山外论坛 http://vcan123.com/forum.php?mod=viewthread&tid=17&ctid=6
//解压的时候，里面有个数组，配置黑、白对应的值是多少。
void img_extract(void *dst, void *src, uint32_t srclen)
{
    uint8_t colour[2] = {255, 0}; //0 和 1 分别对应的颜色
    uint8_t * mdst = dst;
    uint8_t * msrc = src;
    //注：山外的摄像头 0 表示 白色，1表示 黑色
    uint8_t tmpsrc;
    while(srclen --)
    {
        tmpsrc = *msrc++;
        *mdst++ = colour[ (tmpsrc >> 7 ) & 0x01 ];
        *mdst++ = colour[ (tmpsrc >> 6 ) & 0x01 ];
        *mdst++ = colour[ (tmpsrc >> 5 ) & 0x01 ];
        *mdst++ = colour[ (tmpsrc >> 4 ) & 0x01 ];
        *mdst++ = colour[ (tmpsrc >> 3 ) & 0x01 ];
        *mdst++ = colour[ (tmpsrc >> 2 ) & 0x01 ];
        *mdst++ = colour[ (tmpsrc >> 1 ) & 0x01 ];
        *mdst++ = colour[ (tmpsrc >> 0 ) & 0x01 ];
    }
}


    






//int16 Sig_MidLine;
//int16 Sig_Midrow;

void Get_line(int T)
{
    int T1=T;
    otsuThreshold(T1);
    int prospect_see=0;
    int flag=1;
    int mr=0;
    int ll[120]={0},rl[120]={0};
    int max=0;
    int c[120]={0};
    int x=0;
    int flag1=0;
    uint16 row,j;
    for(row=0;flag!=0;row++){
        for(j=0;j<160;j++){
            flag=0;
            if(img_handle[row][j]==255)
            {flag=1;break;}
        }
    }
    prospect_see=row-1;
    
    for(row=prospect_see;row<120;row++){
        for(j=0;j<159;j++){
            if(img_handle[row][j]==0&&img_handle[row][j+1]==255)
            {ll[row]=j;break;}
        }
        
        for(j=1;j<160;j++){
            if(img_handle[row][j-1]==255&&img_handle[row][j]==0)
            {rl[row]=j;break;}
            if(rl[row]<ll[row])
                rl[row]=159;
        }
        
        c[row]=rl[row]-ll[row];
        if(c[row]!=0&&c[row-1]==0)
            flag1++;
        if(c[row]==0&&c[row-1]!=0)
            flag1++;
        if(flag1==2)
        {
            x=row;
            break;
        }
    }
    for(row=prospect_see;row<=x;row++){
        if(c[row]>max){
            max=c[row];
            mr=row;
        }
    }
    
    Sig_MidLine=(ll[mr]+1+rl[mr]+1)/2;
    size=c[mr];
    Sig_Midrow=mr;

//    for(i=0;i<120;i++){
//        Mline[i]=(ll[mr]+1+rl[mr]+1)/2;
//    }



}
void otsuThreshold(int T)
{
      int nopiex[GrayScale]={0};
      int sum = 0,csum=0;
      int n = 0, n2 = 0, n1 = 0;
      double  deltMax = 0, deltTam = 0;
      int Threshold = 0;
      double pt1 = 0, pt2 = 0;
      uint16 H,W;
      uint16 i,j,k;
      int T2=T;
  
       

    for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			nopiex[*(*(img_handle + i) + j)] ++;  //计图中处在灰度0-255各值的像素的个数并存入数组

	}
	for (k = 0; k < GrayScale; k++)
	{
		sum += k*nopiex[k];   //sum=灰度值*该灰度像素的个数的累加
		n += nopiex[k];   //n=该灰度像素的个数的累加
        if(k==T2)//记录灰度值=50时的sum和n
        {
            n1=n;        
            csum =sum;
        }
	}
	for (k = T2; k < GrayScale-80; k++)//灰度值在50-176时
	{
		n1 += nopiex[k];//n1=到当前灰度值k为止一共有多少个像素点
		n2 = n - n1;//n2=总像素点个数-n1
		if (n1 == 0)
			continue;
		if (n2 == 0)
			break;       
		csum += k*nopiex[k];
		pt1 = 1.0*csum / n1;
		pt2 = 1.0*(sum - csum) / n2;
		deltTam = (double)(n1*n2*(pt1 - pt2)*(pt1 - pt2));
		if (deltTam > deltMax)
		{
			deltMax = deltTam;
			Threshold = k;
		}
	}  

        for(H = 0; H < CAMERA_H; H++)
        {                  //处理行
            for(W = 0; W < CAMERA_W; W++)
            {              //处理列
                if(image[H][W] <= Threshold)
                    img_handle[H][W] = 0;
                else
                    img_handle[H][W] = 255;
            }
        }
}