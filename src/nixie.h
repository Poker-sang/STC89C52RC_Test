#ifndef NIXIE_H
#define NIXIE_H

#include "system.h"

sbit NIXIE_DIO = P3^5;			//������������
sbit NIXIE_RCLK = P3^6;			//ʱ�������źš�����������Ч
sbit NIXIE_SCLK = P3^7;			//�����źš���������������Ч

extern uchar Led[8];					//����LED��8λ��ʾ����

void LedOut(uchar x);
void Led4Display();

#endif