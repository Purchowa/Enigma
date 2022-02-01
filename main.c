#include "func_lib.h"

int main()
{
	struct Enigma enigma = {0}; // Inicjalizacja wartosci struktury
	const char Txt[] = "S";
	char* encryptedTxt;

	initEnigma(&enigma);
	//encryptedTxt = code(&enigma, Txt);
	//free(encryptedTxt);

	char test = 'Y';
	test++;
	test -= 'A';
	test %= CHAR_NUM;
	test += 'A';

	printf("%c\n", test);
	return 0;
}