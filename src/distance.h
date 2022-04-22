#ifndef DISTANCE_H
#define DISTANCE_H

#include "system.h"

sbit DISTANCE_ECHO = P3^0;
sbit DISTANCE_TRIG = P3^1;

long GetDistance();
void StartModule();
void Zd0();

extern uchar DisBuff[4];

/*	TMOD = 0x01;		   //设T0为方式1，GATE=1
	TH0 = 0;
	TL0 = 0;
	TR0 = 1;
	while (1)
	{
		StartModule();
		//计算
		while (!RX);		//当RX为零时等待
		TR0 = 1;			//开启计数
		while (RX);			//当RX为1计数并等待
		TR0 = 0;			//关闭计数
		if (GetDistance());	//返回1，成功，查看DisBuff
		Delay(80);		//80MS
	}
 */

#endif
