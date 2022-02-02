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
	for (int i = 0; Txt[i] != '\0'; i++)
	{
		incKey(eni);
		
		// encryptedTxt[i] = encryptChar(eni, &Txt[i]);
	}


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

char plugboardSwap(struct Enigma* eni, const char* c)
{
	/*
		Return switched char if not found -> returns original char 
	*/
	for (int i = 0; i < CHAR_NUM / PAIR; i++)
	{
		if (eni->Plugboard[i][0] == *c)
			return eni->Plugboard[i][1];

		if (eni->Plugboard[i][1] == *c)
			return eni->Plugboard[i][0];
	}
	return *c;
}