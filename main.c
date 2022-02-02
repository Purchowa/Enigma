#include "func_lib.h"

int main()
{
	struct Enigma enigma = {0}; // Inicjalizacja wartosci struktury
	const char Txt[] = "H";
	char* encryptedTxt;

	initEnigma(&enigma);
	encryptedTxt = code(&enigma, Txt);
	//printf("%s\n", encryptedTxt);
	free(encryptedTxt);

	return 0;
}