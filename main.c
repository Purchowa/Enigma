#include "func_lib.h"

int main()
{
	struct Enigma enigma = {0}; // Inicjalizacja wartosci struktury
	char* Txt = NULL;
	char* EncryptedTxt = NULL;
	char choice, input;

	printf("Symulator Enigmy\n");

	do
	{
		printf("Wybierz skad chcesz wczytac tekst do zaszyfrowania: 1. Klawiatura, 2. Plik: \n");
		choice = fgetc(stdin);
		while ((input = fgetc(stdin)) != '\n'); // Czyszczenie stdin
		Txt = loadTxt(&enigma, choice);
	} while (!Txt || checkTxt(Txt));

	if (initEnigma(&enigma))
	{
		printf("Failed loading data to Enigma\n");
		return 1;
	}
	printf("Twoj tekst: %s\n", Txt);

	EncryptedTxt = code(&enigma, Txt);
	printf("Tekst zaszyfrowany: %s\n", EncryptedTxt);

	printf("Zaszyfrowany tekst zapisany do pliku out.txt\n");
	saveTxt(EncryptedTxt);

	free(EncryptedTxt);
	free(Txt);
	return 0;
}