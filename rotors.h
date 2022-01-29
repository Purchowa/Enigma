#ifndef  _ROTORS_H
#define _ROTORS_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


#define CHAR_NUM 26
#define ROTORCOUNT 3
#define PAIR 2
#define I(c) ((c)-'A')

typedef unsigned char uint1;

struct Enigma
{
	uint1 RotorOrder[ROTORCOUNT];
	uint1 ref;

	char RotorPerm[ROTORCOUNT][CHAR_NUM];
	char RotorTrans[ROTORCOUNT];
	char Key[ROTORCOUNT];
	char PlugBoard[(CHAR_NUM) / (PAIR)][PAIR];
	char RefPerm[CHAR_NUM];
	
};

void initEnigma(struct Enigma* eni);
int loadData(struct Enigma* eni);
int loadRotorConfig(struct Enigma* eni);
int loadPlugBoardConfig(struct Enigma* eni);

#endif // ! _ROTORS_H

