#include "rotor_config.h"

static void prepareData(struct Enigma* eni)
{
	/*
		Preparing data so values must be at range:
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

int initEnigma(struct Enigma* eni)
{
	if (loadData(eni))
		return 1;

	prepareData(eni);
	return 0;
}

