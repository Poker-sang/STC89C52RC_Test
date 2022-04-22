sbit Motor_IN1 = P0^2;
sbit Motor_IN2 = P0^3;

uchar Counter, Compare;	//计数值和比较值，用于输出PWM
uchar Speed;

void Timer0Init(void)		//100微秒@12.000MHz
{
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0x50;		//设置定时初始值
	TH0 = 0xFB;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
}
void main()
{
	Timer0Init();
	while (1)
	{
		Delay(1000);
		Speed++;
		Speed %= 4;
		if (Speed == 0) { Compare = 0; }	//设置比较值，改变PWM占空比
		if (Speed == 1) { Compare = 50; }
		if (Speed == 2) { Compare = 75; }
		if (Speed == 3) { Compare = 100; }
	}
}

void Timer0_Routine() interrupt 1
{
	TL0 = 0x9C;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	++Counter;
	Counter %= 100;	//计数值变化范围限制在0~99
	if (Counter < Compare)	//计数值小于比较值
	{
		Motor = 1;		//输出1
	}
	else				//计数值大于比较值
	{
		Motor = 0;		//输出0
	}
}
