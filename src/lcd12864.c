#include "lcd12864.h"

void Lcd12864WriteCmd(uchar cmd) // 写命令
{
	LCD12864_RS = 0;//选择命令
	LCD12864_RW = 0;//选择写
	LCD12864_E = 0;
	LCD12864_DATAPORT = cmd;//准备命令
	Delay(1);
	LCD12864_E = 1;//使能脚E先上升沿写入
	Delay(1);
	LCD12864_E = 0;//使能脚E后负跳变完成写入
}

void Lcd12864WriteData(uchar dat) // 写数据
{
	LCD12864_RS = 1;//选择数据
	LCD12864_RW = 0;//选择写
	LCD12864_E = 0;
	LCD12864_DATAPORT = dat;//准备数据
	Delay(1);
	LCD12864_E = 1;//使能脚E先上升沿写入
	Delay(1);
	LCD12864_E = 0;//使能脚E后负跳变完成写入
}

void Lcd12864Init() // 初始化
{
	LCD12864_PSB = 1;//选择8位或4位并口方式
	Lcd12864WriteCmd(0x30);//数据总线8位，基本指令操作
	Lcd12864WriteCmd(0x0c);//整体显示关，游标显示关，游标正常显示
	Lcd12864WriteCmd(0x06);//写入新数据后光标右移，显示屏不移动
	Lcd12864WriteCmd(0x01);//清屏	
}

void Lcd12864Clear() // 清屏
{
	Lcd12864WriteCmd(0x01);
}

void Lcd12864ShowString(uchar x, uchar y, uchar* str) // 显示字符串
{
	if (y <= 0) y = 0;
	if (y > 3) y = 3;
	x &= 0x0f;	//限制x,y不能大于显示范围

	switch (y)
	{
	case 0: x |= 0x80; break;//第1行地址+x的偏移
	case 1: x |= 0x90; break;//第2行地址+x的偏移
	case 2: x |= 0x88; break;//第3行地址+x的偏移
	case 3: x |= 0x98; break;//第4行地址+x的偏移
	}
	Lcd12864WriteCmd(x);
	while (*str != '\0')
	{
		Lcd12864WriteData(*str);
		++str;
	}
}