#include "func_lib.h"

int main()
{
	struct Enigma enigma = {0}; // Initializing all values to zero
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
			while ((strClr = fgetc(stdin)) != '\n'); // Clearing stdin
			Txt = loadTxt(&enigma, choice);
		} while (!Txt || checkTxt(Txt, strlen(Txt)));

		printf("Twoj tekst: ");
		colorTxt(Txt, 0x0C);
		putchar('\n');

		if (initEnigma(&enigma))
		{
			printf("Failed loading data to Enigma\n");
			return 1;
		}

		EncryptedTxt = code(&enigma, Txt);
		printf("Tekst zaszyfrowany: ");
		colorTxt(EncryptedTxt, 0x0A);
		putchar('\n');

		printf("Zaszyfrowany tekst zapisany do pliku ");
		colorTxt("out.txt\n", 0x06);
		saveTxt(EncryptedTxt);

		free(EncryptedTxt);
		free(Txt);
		printf("Koniec programu wprowadz ");
		colorTxt("e", 0x0E);
		printf(" aby zakonczyc\n");

		exitChar = fgetc(stdin);
		if (exitChar != '\n')
			while ((strClr = fgetc(stdin)) != '\n');
		system("cls");
		enigma = (struct Enigma){0}; // Reseting old data to zeros beacuse of posible changes in config files.
	} while (exitChar != 'e' && exitChar != 'E');

	return 0;
}