#ifndef  _ROTORS_H
#define _ROTORS_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


#define CHAR_NUM 26
#define ROTORCOUNT 3
#define PAIR 2

typedef unsigned char uint1;

struct Enigma
{
	uint1 RotorOrder[ROTORCOUNT];
	uint1 reflector;

	char RotorPermutation[ROTORCOUNT][CHAR_NUM];
	char RotorTransmission[ROTORCOUNT];
	char Key[ROTORCOUNT + 1];
	char PlugBoard[(CHAR_NUM) / (PAIR)][PAIR];
	char ReflectorPermutation[CHAR_NUM];
	
};

void initEnigma(struct Enigma* machine);
int loadData(struct Enigma* machine);

#endif // ! _ROTORS_H

