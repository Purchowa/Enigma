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
	// Mozna na poczatku: *c - 'A' bo i tak operuje na czyms takim caly czas

#define KEY_SIZE ((ROTOR_COUNT) + 2) // + 2 for empty keys
	char Keys[KEY_SIZE] = { 0 };
	char tmpC = *c;

	for (int i = 1; i < KEY_SIZE - 1; i++)
		Keys[i] = I(eni->Key[i-1]);

	
	tmpC = plugboardSwap(eni, &tmpC);

	// Enter rotors
	for (int i = 0; i < ROTOR_COUNT; i++)
		tmpC = permShift(eni->RotorPerm[i], I(tmpC), Keys[i + 1] - Keys[i]);

	// Char gets reflected
	tmpC = reflectChar(eni, c);

	// Going back into rotors
	for (int i = KEY_SIZE - 1; i >= 0; i--)
		//tmpC = permShift(eni->RotorPerm[i], I(tmpC), eni->Key[i]);

	tmpC = plugboardSwap(eni, &tmpC);

#undef KEY_SIZE
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

char reflectChar(struct Enigma* eni, const char* c)
{
	return eni->RefPerm[I(*c)];;
}

char permShift(const char Perm[], const sint1 i, sint1 key)
{
	if (key < 0)
		key += CHAR_NUM;
	return Perm[(i + key) % CHAR_NUM];
}
