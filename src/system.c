#include "system.h"

void Delay(uchar ms) // �ӳ� ms ���� @12.000MHz
{
	uchar i = 0, j = 0;
	for (i = 0; i < ms; i++)
		for (j = 0; j < 123; j++);

}