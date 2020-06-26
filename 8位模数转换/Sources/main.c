/*---------------------------------------------------------*/
/************************************************************
飞翔科技MC9S12XS128汽车电子开发板
E-mail: 2008f.d@163.com
淘宝店：http://fxfreefly.taobao.com
************************************************************/
/*---------------------------------------------------------*/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

#define  BUS_CLOCK		   32000000	   //总线频率,改变总线频率直接在此处修改
#define  OSC_CLOCK		   16000000	   //晶振频率
#define LEDCPU PORTK_PK4
#define LEDCPU_dir DDRK_DDRK4
unsigned char AD_in1,AD_in0;


/*************************************************************/
/*                      初始化锁相环                         */
/*************************************************************/
void INIT_PLL(void) 
{
    CLKSEL &= 0x7f;       //设置OSCCLK作为系统时钟
    PLLCTL &= 0x8F;       //禁止锁相环
 
    //PLLCLK=2×OSCCLK×(SYNDIV+1)/(REFDIV+1), fbus=PLLCLK/2
    #if(BUS_CLOCK == 120000000) 
        SYNR = 0xcd;
    #elif(BUS_CLOCK == 104000000) 
      SYNR = 0xcc;
    #elif(BUS_CLOCK == 96000000) 
      SYNR = 0xcb;
    #elif(BUS_CLOCK == 88000000) 
      SYNR = 0xca;
    #elif(BUS_CLOCK == 80000000) 
      SYNR = 0xc9;
    #elif(BUS_CLOCK == 72000000) 
      SYNR = 0xc8;
    #elif(BUS_CLOCK == 64000000) 
      SYNR = 0xc7;
    #elif(BUS_CLOCK == 56000000) 
      SYNR = 0xc6;
    #elif(BUS_CLOCK == 48000000) 
      SYNR = 0xc5;
    #elif(BUS_CLOCK == 40000000) 
      SYNR = 0x44;
    #elif(BUS_CLOCK == 32000000)
      SYNR = 0x43;     
    #elif(BUS_CLOCK == 24000000)
      SYNR = 0x42;
    #elif(BUS_CLOCK == 16000000)
      SYNR = 0x01;
   #endif 

    REFDV = 0x81;
    PLLCTL |=0x70;  //使能锁相环
    asm NOP;
    asm NOP;
    while(!(CRGFLG&0x08)); //PLLCLK锁定
    CLKSEL |= 0x80;        //设置PLLCLK为系统时钟
}

/*************************************************************/
/*                      初始化AD模块                         */
/*************************************************************/
void INIT_AD(void) 
{
 ATD0CTL2 = 0x40;  //启动A/D模块,快速清零,禁止中断
 ATD0CTL1_SRES=0;  //选用8位模数转换
 ATD0CTL3 = 0x88;   //每次只转换一个通道
 ATD0CTL4 = 0x07;   //AD模块时钟频率为2MHz
}

/*************************************************************/
/*                        起动AD转换                         */
/*************************************************************/
unsigned char AD_capture(unsigned char chanel) 
{
 unsigned char AD_data;
 switch(chanel)
 { 
  case 0:
    ATD0CTL5 = 0x00;    //转换AD00
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 1:
    ATD0CTL5 = 0x01;    //转换AD01
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;
  
  case 2:
    ATD0CTL5 = 0x02;    //转换AD02
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;
 
  case 3:
    ATD0CTL5 = 0x03;    //转换AD03
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 4:
    ATD0CTL5 = 0x04;    //转换AD04
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 5:
    ATD0CTL5 = 0x05;    //转换AD05
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 6:
    ATD0CTL5 = 0x06;    //转换AD06
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 7:
    ATD0CTL5 = 0x07;    //转换AD07
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 8:
    ATD0CTL5 = 0x08;    //转换AD08
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 9:
    ATD0CTL5 = 0x09;    //转换AD09
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 10:
    ATD0CTL5 = 0x0a;    //转换AD10
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 11:
    ATD0CTL5 = 0x0b;    //转换AD11
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 12:
    ATD0CTL5 = 0x0c;    //转换AD12
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 13:
    ATD0CTL5 = 0x0d;    //转换AD13
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 14:
    ATD0CTL5 = 0x0e;    //转换AD14
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 15:
    ATD0CTL5 = 0x0f;    //转换AD15
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;
  
 }
 return(AD_data);
}

/*************************************************************/
/*                           主函数                          */
/*************************************************************/
void main(void) {
	DisableInterrupts;
  INIT_PLL();
  INIT_AD();
  LEDCPU_dir=1;
	EnableInterrupts;


  
  
  for(;;) 
  {
      AD_in1= AD_capture(1);
      AD_in0=AD_capture(0);
      if(AD_in1 > AD_in0)
        LEDCPU = 0;
      else
        LEDCPU = 1;
  
  } 
}
