#include "func_lib.h"

int main()
{
	struct Enigma enigma = {0}; // Inicjalizacja wartosci struktury
	const char Txt[] = "S";
	char* encryptedTxt;

	initEnigma(&enigma);
	encryptedTxt = encrypt(&enigma, Txt);
	free(encryptedTxt);
	return 0;
}