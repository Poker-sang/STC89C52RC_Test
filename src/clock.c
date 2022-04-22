#include "clock.h"

uchar DisTimeBuf[16] = { 0 };
uchar TimeBuf[8] = { 0x20,0x22,0x04,0x22,0x23,0x59,0x55,0x05 };//初始时间2022年4月22号23点59分55秒 星期5

void Ds1302Init()			//DS1302初始化函数
{
	DS1302_RST = 0;			//RST脚置低
	DS1302_CLK = 0;			//SCK脚置低
}

void Ds1302WriteByte(uchar addr, uchar d)	//向DS1302写入一字节数据
{
	uchar i;
	DS1302_RST = 1;		//启动DS1302总线	
	//写入目标地址：addr
	addr = addr & 0xFE;	//最低位置零，寄存器0位为0时写，为1时读
	for (i = 0; i < 8; i++) {
		if (addr & 0x01) {
			DS1302_DAT = 1;
		}
		else {
			DS1302_DAT = 0;
		}
		DS1302_CLK = 1;      //产生时钟
		DS1302_CLK = 0;
		addr >>= 1;
	}
	//写入数据：d
	for (i = 0; i < 8; i++) {
		if (d & 0x01) {
			DS1302_DAT = 1;
		}
		else {
			DS1302_DAT = 0;
		}
		DS1302_CLK = 1;    //产生时钟
		DS1302_CLK = 0;
		d >>= 1;
	}
	DS1302_RST = 0;		//停止DS1302总线
}


uchar Ds1302ReadByte(uchar addr)	//从DS1302读出一字节数据
{
	uchar i, temp;
	temp = 0;
	DS1302_RST = 1;					//启动DS1302总线
	//写入目标地址：addr
	addr = addr | 0x01;    //最低位置高，寄存器0位为0时写，为1时读
	for (i = 0; i < 8; ++i) {
		if (addr & 0x01) {
			DS1302_DAT = 1;
		}
		else {
			DS1302_DAT = 0;
		}
		DS1302_CLK = 1;
		DS1302_CLK = 0;
		addr >>= 1;
	}
	//输出数据：temp
	for (i = 0; i < 8; ++i)
	{
		temp >>= 1;
		if (DS1302_DAT) {
			temp |= 0x80;
		}
		else {
			temp &= 0x7F;
		}
		DS1302_CLK = 1;
		DS1302_CLK = 0;
	}
	DS1302_RST = 0;					//停止DS1302总线
	return temp;
}

void Ds1302WriteTime() //向DS302写入时钟数据
{
	Ds1302WriteByte(DS1302ControlAdd, 0x00);			//关闭写保护 
	Ds1302WriteByte(DS1302SecAdd, 0x80);				//暂停时钟 
	//DS1302WriteByte(DS1302ChargerAdd, 0xa9);	    //涓流充电 
	Ds1302WriteByte(DS1302YearAdd, TimeBuf[1]);		//年 
	Ds1302WriteByte(DS1302MonthAdd, TimeBuf[2]);	//月 
	Ds1302WriteByte(DS1302DateAdd, TimeBuf[3]);		//日 
	Ds1302WriteByte(DS1302HrAdd, TimeBuf[4]);		//时 
	Ds1302WriteByte(DS1302MinAdd, TimeBuf[5]);		//分
	Ds1302WriteByte(DS1302SecAdd, TimeBuf[6]);		//秒
	Ds1302WriteByte(DS1302DayAdd, TimeBuf[7]);		//周 
	Ds1302WriteByte(DS1302ControlAdd, 0x80);			//打开写保护     
}

void Ds1302ReadTime()   //从DS302读出时钟数据
{
	TimeBuf[1] = Ds1302ReadByte(DS1302YearAdd);	//年 
	TimeBuf[2] = Ds1302ReadByte(DS1302MonthAdd);	//月 
	TimeBuf[3] = Ds1302ReadByte(DS1302DateAdd);		//日 
	TimeBuf[4] = Ds1302ReadByte(DS1302HrAdd);		//时 
	TimeBuf[5] = Ds1302ReadByte(DS1302MinAdd);		//分 
	TimeBuf[6] = Ds1302ReadByte(DS1302SecAdd) & 0x7f;//秒，屏蔽秒的第7位，避免超出59
	TimeBuf[7] = Ds1302ReadByte(DS1302DayAdd);	//周 	
}

void Timer2() interrupt 5	 //定时器中断函数，2是5号中断
{
	static uchar t;
	TF2 = 0;
	++t;
	if (t == 4)               //间隔200ms(50ms*4)读取一次时间
	{
		t = 0;
		DS1302_read_time();  //读取时间
		dis_time_buf[0] = (time_buf[0] >> 4) + '0'; //年   
		dis_time_buf[1] = (time_buf[0] & 0x0f) + '0';

		dis_time_buf[2] = (time_buf[1] >> 4) + '0';
		dis_time_buf[3] = (time_buf[1] & 0x0f) + '0';

		dis_time_buf[4] = (time_buf[2] >> 4) + '0'; //月  
		dis_time_buf[5] = (time_buf[2] & 0x0f) + '0';

		dis_time_buf[6] = (time_buf[3] >> 4) + '0'; //日   
		dis_time_buf[7] = (time_buf[3] & 0x0f) + '0';

		dis_time_buf[14] = (time_buf[7] & 0x07) + '0'; //星期
		
		dis_time_buf[8] = (time_buf[4] >> 4) + '0'; //时   
		dis_time_buf[9] = (time_buf[4] & 0x0f) + '0';

		dis_time_buf[10] = (time_buf[5] >> 4) + '0'; //分   
		dis_time_buf[11] = (time_buf[5] & 0x0f) + '0';

		dis_time_buf[12] = (time_buf[6] >> 4) + '0'; //秒   
		dis_time_buf[13] = (time_buf[6] & 0x0f) + '0';
	}
}

void InitTimer2()//定时器2初始化
{
	RCAP2H = 0x3c;//赋T2初始值0x3cb0，溢出20次为1秒,每次溢出时间为50ms
	RCAP2L = 0xb0;
	TR2 = 1;	     //启动定时器2
	ET2 = 1;		 //打开定时器2中断
	EA = 1;		 //打开总中断
}
