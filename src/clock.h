#ifndef CLOCK_H
#define CLOCK_H

#include "system.h"

sbit DS1302_RST = P3^0;
sbit DS1302_DAT = P3^1;
sbit DS1302_CLK = P3^2;

sbit DS1302SecAdd = 0x80;		//秒数据地址
sbit DS1302MinAdd = 0x82;		//分数据地址
sbit DS1302HrAdd = 0x84;		//时数据地址
sbit DS1302DateAdd = 0x86;		//日数据地址
sbit DS1302MonthAdd = 0x88;		//月数据地址
sbit DS1302DayAdd = 0x8a;		//星期数据地址
sbit DS1302YearAdd = 0x8c;		//年数据地址
sbit DS1302ControlAdd = 0x8e;	//控制数据地址
sbit DS1302ChargerAdd = 0x90;
sbit DS1302ClkburstAdd = 0xbe;

extern uchar DisTimeBuf[16];

void Ds1302Init();
void Ds1302WriteByte(uchar addr, uchar d);
uchar Ds1302ReadByte(uchar addr);
void Ds1302WriteTime();
void Ds1302ReadTime();
void Timer2();
void InitTimer2();

/* Delay(50);//等待系统稳定
	Lcd12864Init();   //LCD初始化
	Lcd12864Clear();  //清屏   
	DS1302_init();  //DS1302初始化
	Delay(10);
	DS1302_write_time(); //写入初始值
	Init_timer2(); //定时器2初始化 
	while (1)
	{
		dis_time_buf[15] =
		'\0';
		Lcd12864ShowString(0, 0, dis_time_buf);
	}
 */

#endif