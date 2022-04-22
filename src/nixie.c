#include "nixie.h"

uchar code Led0F[] =			// LED字模表
{// 0	 1	  2	   3	4	 5	  6	   7	8	 9	  A	   B	C    D	  E    F    -
	0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x8C,0xBF,0xC6,0xA1,0x86,0xFF,0xBF
};

uchar Led[8] = { 0, 0, 0, 0 };

void LedOut(uchar x)			// LED单字节串行移位函数
{
	uchar i;
	for (i = 8; i >= 1; i--)
	{
		if (x & 0x80)
			NIXIE_DIO = 1;
		else NIXIE_DIO = 0;
		x <<= 1;
		NIXIE_SCLK = 0;
		NIXIE_SCLK = 1;
	}
}

void Led4Display()				// LED显示
{
	uchar code* ledTable;          // 查表指针
	uchar i;
	//显示第1位
	ledTable = Led0F + Led[0];
	i = *ledTable;

	LedOut(i);
	LedOut(0x01);

	NIXIE_RCLK = 0;
	NIXIE_RCLK = 1;
	//显示第2位
	ledTable = Led0F + Led[1];
	i = *ledTable;

	LedOut(i);
	LedOut(0x02);

	NIXIE_RCLK = 0;
	NIXIE_RCLK = 1;
	//显示第3位
	ledTable = Led0F + Led[2];
	i = *ledTable;

	LedOut(i);
	LedOut(0x04);

	NIXIE_RCLK = 0;
	NIXIE_RCLK = 1;
	//显示第4位
	ledTable = Led0F + Led[3];
	i = *ledTable;

	LedOut(i);
	LedOut(0x08);

	NIXIE_RCLK = 0;
	NIXIE_RCLK = 1;
}