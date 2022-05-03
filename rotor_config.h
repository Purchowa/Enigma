#ifndef  _ROTOR_CONFIG_H
#define _ROTOR_CONFIG_H

#include "func_lib.h"

#define CHAR_BEGIN 'A'
#define CHAR_END 'Z'
#define CHAR_NUM ((CHAR_END) - (CHAR_BEGIN) + 1) // 26
#define ROTOR_COUNT 3 // Key has same length
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

int initEnigma(struct Enigma* eni);

#endif // ! _ROTOR_CONFIG_H

