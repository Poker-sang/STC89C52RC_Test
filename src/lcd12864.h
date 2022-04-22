#ifndef LCD12864_H
#define LCD12864_H

#include "system.h"

sbit LCD12864_RS	= P4^0;		// ��������ѡ��
sbit LCD12864_RW	= P4^1;		// ��дѡ��
sbit LCD12864_E		= P4^2;		// ʹ���ź�
sbit LCD12864_PSB	= P4^3;		// 8λ��4����/����ѡ��
#define LCD12864_DATAPORT P2	// LCD12864���ݶ˿ڶ���

void Lcd12864Init();			// ��ʼ��
void Lcd12864Clear();			// ����
void Lcd12864ShowString(uchar x, uchar y, uchar*str);
								// ��ʾ�ַ���
#endif
