#ifndef NIXIE_H
#define NIXIE_H

#include "system.h"

sbit NIXIE_DIO = P3^5;			//串行数据输入
sbit NIXIE_RCLK = P3^6;			//时钟脉冲信号——上升沿有效
sbit NIXIE_SCLK = P3^7;			//打入信号————上升沿有效

extern uchar Led[8];					//用于LED的8位显示缓存

void LedOut(uchar x);
void Led4Display();

#endif