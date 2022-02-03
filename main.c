#include "func_lib.h"

int main()
{
	struct Enigma enigma = {0}; // Inicjalizacja wartosci struktury
	char* Txt = NULL;
	char* encryptedTxt = NULL;
	char choice;
	printf("Symulator Enigmy\n");
	printf("Wybierz skad chcesz wczytac tekst do zaszyfrowania: 1. Klawiatura, 2. Plik: \n");
	scanf("%c", &choice);

	if (initEnigma(&enigma) || !(Txt = loadTxt(&enigma, choice)))
	{
		printf("Failed loading data to Enigma\n");
		return 1;
	}
	printf("Twoj tekst: %s\n", Txt);
	encryptedTxt = code(&enigma, Txt);
	printf("Tekst zaszyfrowany: %s\n", encryptedTxt);

	free(encryptedTxt);
	free(Txt);
	return 0;
}