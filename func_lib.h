#ifndef  _FUNC_LIB_H
#define _FUNC_LIB_H

#define _CRT_SECURE_NO_WARNINGS // fopen gives error without it

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef unsigned char uint1;
typedef signed char sint1;

#include "rotor_config.h"
#include "encryption.h"
#include "loading_data.h"

void printTab(const int R, const char Tab[]);
void colorTxt(const char Txt[], uint1 colorHex);

#endif // ! _FUNC_LIB_H

