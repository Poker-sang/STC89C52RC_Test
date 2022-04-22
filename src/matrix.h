#ifndef MATRIXKEY_H
#define MATRIXKEY_H

#include "system.h"

#define MATRIX_KEY_LINE P1

sbit C4 = MATRIX_KEY_LINE^0;
sbit C3 = MATRIX_KEY_LINE^1;
sbit C2 = MATRIX_KEY_LINE^2;
sbit C1 = MATRIX_KEY_LINE^3;
sbit R1 = MATRIX_KEY_LINE^4;
sbit R2 = MATRIX_KEY_LINE^5;
sbit R3 = MATRIX_KEY_LINE^6;
sbit R4 = MATRIX_KEY_LINE^7;

uchar MatrixKey();
	
#endif