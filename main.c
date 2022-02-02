#include "func_lib.h"

int main()
{
	struct Enigma enigma = {0}; // Inicjalizacja wartosci struktury
	const char Txt[] = "S";
	char* encryptedTxt;

	initEnigma(&enigma);
	encryptedTxt = code(&enigma, Txt);
	free(encryptedTxt);

	printf("%c\n", LOOP_ALPH('Z' + 10));
	return 0;
}