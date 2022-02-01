#include "func_lib.h"

void printTab(const int R, const char Tab[])
{
	for (int i = 0; i < R; i++)
		printf("%4c", Tab[i]);
	printf("\n");
	return;
}