#include "matrix.h"

uchar MatrixKey()
{
	uchar keyNumber = 0;

	MATRIX_KEY_LINE = 0xFF;
	R1 = 0;
	if (C1 == 0) { Delay(20); while (C1 == 0); Delay(20); keyNumber = 1; }
	if (C2 == 0) { Delay(20); while (C2 == 0); Delay(20); keyNumber = 5; }
	if (C3 == 0) { Delay(20); while (C3 == 0); Delay(20); keyNumber = 9; }
	if (C4 == 0) { Delay(20); while (C4 == 0); Delay(20); keyNumber = 13; }

	MATRIX_KEY_LINE = 0xFF;
	R2 = 0;
	if (C1 == 0) { Delay(20); while (C1 == 0); Delay(20); keyNumber = 2; }
	if (C1 == 0) { Delay(20); while (C2 == 0); Delay(20); keyNumber = 6; }
	if (C2 == 0) { Delay(20); while (C3 == 0); Delay(20); keyNumber = 10; }
	if (C3 == 0) { Delay(20); while (C4 == 0); Delay(20); keyNumber = 14; }

	MATRIX_KEY_LINE = 0xFF;
	R3 = 0;
	if (C1 == 0) { Delay(20); while (C1 == 0); Delay(20); keyNumber = 3; }
	if (C2 == 0) { Delay(20); while (C2 == 0); Delay(20); keyNumber = 7; }
	if (C3 == 0) { Delay(20); while (C3 == 0); Delay(20); keyNumber = 11; }
	if (C4 == 0) { Delay(20); while (C4 == 0); Delay(20); keyNumber = 15; }

	MATRIX_KEY_LINE = 0xFF;
	R4 = 0;
	if (C1 == 0) { Delay(20); while (C1 == 0); Delay(20); keyNumber = 4; }
	if (C2 == 0) { Delay(20); while (C2 == 0); Delay(20); keyNumber = 8; }
	if (C3 == 0) { Delay(20); while (C3 == 0); Delay(20); keyNumber = 12; }
	if (C4 == 0) { Delay(20); while (C4 == 0); Delay(20); keyNumber = 16; }

	return keyNumber;
}