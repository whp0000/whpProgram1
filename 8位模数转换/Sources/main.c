/*---------------------------------------------------------*/
/************************************************************
����Ƽ�MC9S12XS128�������ӿ�����
E-mail: 2008f.d@163.com
�Ա��꣺http://fxfreefly.taobao.com
************************************************************/
/*---------------------------------------------------------*/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

#define  BUS_CLOCK		   32000000	   //����Ƶ��,�ı�����Ƶ��ֱ���ڴ˴��޸�
#define  OSC_CLOCK		   16000000	   //����Ƶ��
#define LEDCPU PORTK_PK4
#define LEDCPU_dir DDRK_DDRK4
unsigned char AD_in1,AD_in0;


/*************************************************************/
/*                      ��ʼ�����໷                         */
/*************************************************************/
void INIT_PLL(void) 
{
    CLKSEL &= 0x7f;       //����OSCCLK��Ϊϵͳʱ��
    PLLCTL &= 0x8F;       //��ֹ���໷
 
    //PLLCLK=2��OSCCLK��(SYNDIV+1)/(REFDIV+1), fbus=PLLCLK/2
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
    PLLCTL |=0x70;  //ʹ�����໷
    asm NOP;
    asm NOP;
    while(!(CRGFLG&0x08)); //PLLCLK����
    CLKSEL |= 0x80;        //����PLLCLKΪϵͳʱ��
}

/*************************************************************/
/*                      ��ʼ��ADģ��                         */
/*************************************************************/
void INIT_AD(void) 
{
 ATD0CTL2 = 0x40;  //����A/Dģ��,��������,��ֹ�ж�
 ATD0CTL1_SRES=0;  //ѡ��8λģ��ת��
 ATD0CTL3 = 0x88;   //ÿ��ֻת��һ��ͨ��
 ATD0CTL4 = 0x07;   //ADģ��ʱ��Ƶ��Ϊ2MHz
}

/*************************************************************/
/*                        ��ADת��                         */
/*************************************************************/
unsigned char AD_capture(unsigned char chanel) 
{
 unsigned char AD_data;
 switch(chanel)
 { 
  case 0:
    ATD0CTL5 = 0x00;    //ת��AD00
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 1:
    ATD0CTL5 = 0x01;    //ת��AD01
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;
  
  case 2:
    ATD0CTL5 = 0x02;    //ת��AD02
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;
 
  case 3:
    ATD0CTL5 = 0x03;    //ת��AD03
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 4:
    ATD0CTL5 = 0x04;    //ת��AD04
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 5:
    ATD0CTL5 = 0x05;    //ת��AD05
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 6:
    ATD0CTL5 = 0x06;    //ת��AD06
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 7:
    ATD0CTL5 = 0x07;    //ת��AD07
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 8:
    ATD0CTL5 = 0x08;    //ת��AD08
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 9:
    ATD0CTL5 = 0x09;    //ת��AD09
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 10:
    ATD0CTL5 = 0x0a;    //ת��AD10
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 11:
    ATD0CTL5 = 0x0b;    //ת��AD11
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 12:
    ATD0CTL5 = 0x0c;    //ת��AD12
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 13:
    ATD0CTL5 = 0x0d;    //ת��AD13
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 14:
    ATD0CTL5 = 0x0e;    //ת��AD14
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;

  case 15:
    ATD0CTL5 = 0x0f;    //ת��AD15
    while(!ATD0STAT0_SCF);
    AD_data = ATD0DR0L;
    break;
  
 }
 return(AD_data);
}

/*************************************************************/
/*                           ������                          */
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
