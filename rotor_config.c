#include "rotor_config.h"

int initEnigma(struct Enigma* eni)
{
	if (loadData(eni))
		return 1;

	prepareData(eni);
	return 0;
}

void prepareData(struct Enigma* eni)
{
	/*
		Preparing data so that:
			eni->Key -> [0; 25]
			eni->RotorTrans -> [0; 25]
	*/
	for (int i = 0; i < ROTOR_COUNT; i++)
	{
		eni->Key[i] -= CHAR_BEGIN;
		eni->RotorTrans[i] -= CHAR_BEGIN;
	}
	return;
}
