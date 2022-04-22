#include "lcd12864.h"

void Lcd12864WriteCmd(uchar cmd) // д����
{
	LCD12864_RS = 0;//ѡ������
	LCD12864_RW = 0;//ѡ��д
	LCD12864_E = 0;
	LCD12864_DATAPORT = cmd;//׼������
	Delay(1);
	LCD12864_E = 1;//ʹ�ܽ�E��������д��
	Delay(1);
	LCD12864_E = 0;//ʹ�ܽ�E���������д��
}

void Lcd12864WriteData(uchar dat) // д����
{
	LCD12864_RS = 1;//ѡ������
	LCD12864_RW = 0;//ѡ��д
	LCD12864_E = 0;
	LCD12864_DATAPORT = dat;//׼������
	Delay(1);
	LCD12864_E = 1;//ʹ�ܽ�E��������д��
	Delay(1);
	LCD12864_E = 0;//ʹ�ܽ�E���������д��
}

void Lcd12864Init() // ��ʼ��
{
	LCD12864_PSB = 1;//ѡ��8λ��4λ���ڷ�ʽ
	Lcd12864WriteCmd(0x30);//��������8λ������ָ�����
	Lcd12864WriteCmd(0x0c);//������ʾ�أ��α���ʾ�أ��α�������ʾ
	Lcd12864WriteCmd(0x06);//д�������ݺ������ƣ���ʾ�����ƶ�
	Lcd12864WriteCmd(0x01);//����	
}

void Lcd12864Clear() // ����
{
	Lcd12864WriteCmd(0x01);
}

void Lcd12864ShowString(uchar x, uchar y, uchar* str) // ��ʾ�ַ���
{
	if (y <= 0) y = 0;
	if (y > 3) y = 3;
	x &= 0x0f;	//����x,y���ܴ�����ʾ��Χ

	switch (y)
	{
	case 0: x |= 0x80; break;//��1�е�ַ+x��ƫ��
	case 1: x |= 0x90; break;//��2�е�ַ+x��ƫ��
	case 2: x |= 0x88; break;//��3�е�ַ+x��ƫ��
	case 3: x |= 0x98; break;//��4�е�ַ+x��ƫ��
	}
	Lcd12864WriteCmd(x);
	while (*str != '\0')
	{
		Lcd12864WriteData(*str);
		++str;
	}
}