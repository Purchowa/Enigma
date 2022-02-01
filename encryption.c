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
		eni->Key[i]++;
		eni->Key[i] -= 'A';
		eni->Key[i] %= CHAR_NUM;
		eni->Key[i] += 'A';
	} while (eni->Key[i] == eni->RotorTrans[i] && i++ < (ROTORCOUNT - 1)); // TODO: Sprawdzic i jak inkrementuje
	
	printTab(ROTORCOUNT, eni->Key);

}

