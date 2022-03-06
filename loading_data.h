#ifndef _LOADING_DATA_H
#define _LOADING_DATA_H

#include "func_lib.h"

#define BUF_SIZE 256

int loadData(struct Enigma* eni);
int loadRotorConfig(struct Enigma* eni);
int loadPlugboardConfig(struct Enigma* eni);
int loadReflectorConfig(struct Enigma* eni);
int loadUserInput(struct Enigma* eni);
char* loadTxt(struct Enigma* eni, const char choice);
void saveTxt(const char EncTxt[]);
int checkTxt(const char Txt[], const int R);
int checkDuplicate(const char Input[], const int SIZE);

#endif