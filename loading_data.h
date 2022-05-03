#ifndef _LOADING_DATA_H
#define _LOADING_DATA_H

#include "func_lib.h"

#define BUF_SIZE 256

int loadData(struct Enigma* eni);
char* loadTxt(struct Enigma* eni, const uint1 choice);
void saveTxt(const char EncTxt[]);
int checkTxt(const char Input[], const int SIZE);

#endif