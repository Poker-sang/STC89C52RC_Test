#include "distance.h"

uint Time = 0;
long S = 0;

bit Flag = 0;
uchar DisBuff[4] = { 0,0,0,0 };
uchar code Num[] = { "0123456789 :.-" };

bit GetDistance()
{
	unsigned int i, j;
	Time = TH0 * 256 + TL0;
	TH0 = 0;
	TL0 = 0;
	S = Time * 1.87 / 100;		//算出来是CM	  11。0592M晶振
	if (Flag == 1)				//超出测量
	{
		Flag = 0;
		return 0;
	}
	else
	{
		DisBuff[1] = S % 1000 / 100;
		DisBuff[2] = S % 1000 % 100 / 10;
		DisBuff[3] = S % 1000 % 10 % 10;
		return 1;
	};
}

void Zd0() interrupt 1 		 //T0中断用来计数器溢出,超过测距范围
{
	flag = 1;							 //中断溢出标志
}

void  StartModule() 		         //T1中断用来扫描数码管和计800MS启动模块
{
	DISTANCE_TRIG = 1;			                 //800MS  启动一次模块
	_nop_();	_nop_();	_nop_();	_nop_();	_nop_();
	_nop_();	_nop_();	_nop_();	_nop_();	_nop_();
	_nop_();	_nop_();	_nop_();	_nop_();	_nop_();
	_nop_();	_nop_();	_nop_();	_nop_();	_nop_();
	_nop_();
	DISTANCE_TRIG = 0;
}