#include "encryption.h"

char* code(struct Enigma* eni, const char Txt[])
{
	// Returns pointer to  encrypted char[]
	char* encryptedTxt = calloc(strlen(Txt)+1, sizoeof(*Txt));
	if (encryptedTxt)
	{
		printf("Error: got null from calloc\n");
		free(encryptedTxt);
		return NULL;
	}

	for (int i = 0; Txt[i] != '\0'; i++)
	{
		incKey(eni);

		encryptedTxt[i] = encryptChar(eni, &Txt[i]);
	}


	return encryptedTxt;
}

void incKey(struct Enigma* eni)
{
	eni->Key[0]++;


}

