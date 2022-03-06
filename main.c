#include "func_lib.h"

int main()
{
	struct Enigma enigma = {0}; // Inicjalizacja wartosci struktury
	char* Txt = NULL;
	char* EncryptedTxt = NULL;
	char choice, strClr, exitChar;

	printf("Symulator Enigmy\n");
	do
	{
		do
		{
			printf("Wybierz skad chcesz wczytac tekst do zaszyfrowania: 1. Klawiatura, 2. Plik: \n");
			choice = fgetc(stdin);
			while ((strClr = fgetc(stdin)) != '\n'); // Czyszczenie stdin
			Txt = loadTxt(&enigma, choice);
		} while (!Txt || checkTxt(Txt, strlen(Txt)));

		printf("Twoj tekst: ");
		colorTxt(Txt, 0x0C);

		if (initEnigma(&enigma))
		{
			printf("Failed loading data to Enigma\n");
			return 1;
		}

		EncryptedTxt = code(&enigma, Txt);
		printf("Tekst zaszyfrowany: ");
		colorTxt(EncryptedTxt, 0x0A);

		printf("Zaszyfrowany tekst zapisany do pliku ");
		colorTxt("out.txt", 0x06);
		saveTxt(EncryptedTxt);

		free(EncryptedTxt);
		free(Txt);
		printf("Koniec programu wprowadz ");
		colorTxt("e", 0x0E);

		exitChar = fgetc(stdin);
		if (exitChar != '\n')
			while ((strClr = fgetc(stdin)) != '\n');
		system("cls");
		enigma = (struct Enigma){0}; // Zerowanie ze wzgledu na mozliwe zmiany w konfiguracji. Szczegolnie plugboard
	} while (exitChar != 'e' && exitChar != 'E');

	return 0;
}