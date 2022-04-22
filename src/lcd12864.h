#ifndef LCD12864_H
#define LCD12864_H

#include "system.h"

sbit LCD12864_RS	= P4^0;		// 数据命令选择
sbit LCD12864_RW	= P4^1;		// 读写选择
sbit LCD12864_E		= P4^2;		// 使能信号
sbit LCD12864_PSB	= P4^3;		// 8位或4并口/串口选择
#define LCD12864_DATAPORT P2	// LCD12864数据端口定义

void Lcd12864Init();			// 初始化
void Lcd12864Clear();			// 清屏
void Lcd12864ShowString(uchar x, uchar y, uchar*str);
								// 显示字符串
#endif
