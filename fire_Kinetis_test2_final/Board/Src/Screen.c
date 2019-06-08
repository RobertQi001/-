#include "include.h"
#include "extern.h" 

void CenterShow();

void ScreenShow(void)
{
  LCD_img();
   CenterShow();//œ‘ æ÷–œﬂ
   //LeftShow();  //œ‘ æ◊Û±ﬂ‘µ£®∫Ï£©
//   RightShow(); //œ‘ æ”“±ﬂ‘µ£®ª∆£©
}

void LCD_img(void)
{
  int i,j;
  uint16 color = 0;
  uint16 temp = 0;
  
  Address_set(0,0,OV7725_EAGLE_W-1,OV7725_EAGLE_H-1);
  for(i=0;i<CAMERA_H;i++)
  {
    for(j=0;j<CAMERA_W;j++)
    {
      //∂˛÷µªØÕºœÒ
      if(img_handle[i][j] ==255)
      {
        LCD_Write_Data2(WHITE);
      }
      else
      {
        LCD_Write_Data2(BLACK);
      }
//      
      //ª“∂»ÕºœÒ
//      temp = image[i][j];
//////      temp = img_handle[i][j];
//      color=(0x001f&((temp)>>3))<<11;
//      color=color|(((0x003f)&((temp)>>2))<<5);
//      color=color|(0x001f&((temp)>>3));
//      LCD_Write_Data2(color);
    }
  }
  
}

///***************÷–œﬂœ‘ æ*********************/
void CenterShow(void)
{
  uint8 i;
  uint16 H;
  uint16 W;
  for(i=0;i<119;i++)
  {
    if((Sig_MidLine>=0)&&(Sig_MidLine<=159))
    {
      W=(uint16)(Sig_MidLine);
      H=i;
      LCD_Fill(W,H,W,H,BLUE);
    }
//     else
//      W=(uint16)(79);
//      H=i;
//      LCD_Fill(W,H,W,H,RED);
  }
//  for(i=0;i<160;i++)
//  {
//      W=i;
//      H=(uint16)(120-90);
//      LCD_Fill(W,H,W,H,RED);
//  }
//  for(i=0;i<160;i++)
//  {
//      W=i;
//      H=(uint16)(120-80);
//      LCD_Fill(W,H,W,H,RED);
//  }
}

/****************◊Û±ﬂ‘µœ‘ æ*********************/
//void LeftShow(void)
//{
//  uint8 i;
//  uint16 H;
//  uint16 W;
//  for(i = 0; i < CAMERA_H - 1; i++)
//  {
//    if(((L_Line[i] + 1) >= 0) && ((L_Line[i] + 1) <= CAMERA_W - 1))
//    {
//      W = (uint16)(L_Line[i] + 1);
//      H = i;
//      LCD_Fill(W,H,W,H,RED);
//    }
//  }
//}

/****************”“±ﬂ‘µœ‘ æ*********************/
//void RightShow(void)
//{
//  uint8 i;
//  uint16 H;
//  uint16 W;
//  for(i = 0; i < CAMERA_H - 1; i++)
//  {
//    if(((R_Line[i] - 1) >= 0) && ((R_Line[i] - 1) <= CAMERA_W - 1))
//    {
//      W = (uint16)(R_Line[i] - 1);
//      H = i;
//      LCD_Fill(W,H,W,H,YELLOW);
//    }
//  }
//}