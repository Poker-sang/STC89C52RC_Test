#ifndef SYSTEM_H
#define SYSTEM_H

#include <REGX52.H>
#include <intrins.h>

sfr P4 = 0xE8;

typedef unsigned char uchar;
typedef unsigned int uint;

void Delay(uchar ms); // —”≥Ÿ ms ∫¡√Î @12.000MHz

#endif
