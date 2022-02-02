#ifndef  _ROTOR_CONFIG_H
#define _ROTOR_CONFIG_H

#define _CRT_SECURE_NO_WARNINGS
#include "func_lib.h"

#define CHAR_NUM 26
#define ROTOR_COUNT 3 // Taka sama dlugosc klucza
#define PAIR 2

struct Enigma
{
	uint1 RotorOrder[ROTOR_COUNT];
	uint1 reflectorNum;

	char RotorPerm[ROTOR_COUNT][CHAR_NUM];
	char RotorTrans[ROTOR_COUNT];
	char Key[ROTOR_COUNT];
	char Plugboard[(CHAR_NUM) / (PAIR)][PAIR];
	char RefPerm[CHAR_NUM];
	
};

void initEnigma(struct Enigma* eni);
int loadData(struct Enigma* eni);
int loadRotorConfig(struct Enigma* eni);
int loadPlugBoardConfig(struct Enigma* eni);
int loadReflectorConfig(struct Enigma* eni);

#endif // ! _ROTOR_CONFIG_H

