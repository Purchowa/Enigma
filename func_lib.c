#include "func_lib.h"

void printTab(const int R, const char Tab[])
{
	for (int i = 0; i < R; i++)
		printf("%4c", Tab[i]);
	printf("\n");
	return;
}

void colorTxt(const char Txt[], uint1 colorHex)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, colorHex);
	printf("%s", Txt);
	SetConsoleTextAttribute(h, 0x0F); // Reset color to white
}
