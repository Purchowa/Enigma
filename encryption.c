#include "encryption.h"

char* code(struct Enigma* eni, const char Txt[])
{
	// Returns pointer to  encrypted char[]
	char* encryptedTxt = calloc(strlen(Txt)+1, sizeof(*Txt));
	if (encryptedTxt == NULL)
	{
		printf("Error: got null from calloc\n");
		free(encryptedTxt);
		return NULL;
	}

	// Main Loop for encrypting char by char
	int i;
	for (i = 0; Txt[i] != '\0'; i++)
	{
		incKey(eni);
		encryptedTxt[i] = encryptChar(eni, &Txt[i]);
	}
	encryptedTxt[i] = '\0';

	return encryptedTxt;
}

void incKey(struct Enigma* eni)
{
	/*
		Jesli klucz bedzie taki sam jak punkt przeniesienie na poczatku to po nacisnieciu trzeba
		przeniesc nastepny itd.
	*/
	int i = 0;
	do
	{
		++eni->Key[i];
		eni->Key[i] = LoopAlph(eni->Key[i]);
	} while (eni->Key[i] == eni->RotorTrans[i] && i++ < (ROTOR_COUNT - 1));
}

char encryptChar(struct Enigma* eni, const char* c)
{
	char tmpC = *c;
	
	tmpC = plugboardSwap(eni, &tmpC);
	
	tmpC -= CHAR_BEGIN; // tmpC -> [0; 25]
	// Enter rotors
	for (int i = 0; i < ROTOR_COUNT; i++)
	{
		tmpC = eni->RotorPerm[i][LoopAlph(tmpC + eni->Key[i])];
		tmpC = LoopAlph(I(tmpC) + KeyPositive(eni->Key[i] * (-1)));
		// Wracanie do pozycji poczatkowej alfabetu, zeby odczytac znak bezposrednio 
		// przy uzyciu klucza i kolejnego bebna
	}

	// Char gets reflected
	tmpC = I(eni->RefPerm[tmpC]);

	// Going back into rotors
	int n = 0;
	for (int i = ROTOR_COUNT - 1; i >= 0; i--, n = 0)
	{
		tmpC = LoopAlph(tmpC + eni->Key[i]) + CHAR_BEGIN;
		while (tmpC != eni->RotorPerm[i][n]) n++; // Szukanie pozycji w wirniku, na ktorej jest odczytywany znak
		tmpC = LoopAlph(n + KeyPositive(eni->Key[i] * (-1)));
	}
	tmpC += CHAR_BEGIN;

	tmpC = plugboardSwap(eni, &tmpC);

	return tmpC;
}

char plugboardSwap(struct Enigma* eni, const char* c)
{
	/*
		Return switched char. If not found -> returns original char 
	*/
	for (int i = 0; i < (CHAR_NUM / PAIR); i++)
	{
		if (eni->Plugboard[i][0] == *c)
			return eni->Plugboard[i][1];

		if (eni->Plugboard[i][1] == *c)
			return eni->Plugboard[i][0];
	}
	return *c;
}
