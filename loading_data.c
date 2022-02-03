#include "loading_data.h"


int loadData(struct Enigma* eni)
{
	return loadUserInput(eni) | loadRotorConfig(eni) | loadPlugboardConfig(eni) | loadReflectorConfig(eni);
}

int loadRotorConfig(struct Enigma* eni)
{
	// Returns true if failed.
	FILE* fp;
	char PathRotor[] = "rotor_mech/rotor0.txt";
	size_t rtnF;

	for (int i = 0; i < ROTOR_COUNT; i++)
	{
		PathRotor[sizeof(PathRotor) - 6] = eni->RotorOrder[i];

		fp = fopen(PathRotor, "r");
		if (fp == NULL)
		{
			perror(PathRotor); // Drukuje komunikat o bledzie na stderr z errno
			return 1;
		}

		rtnF = fread(eni->RotorPerm[i], sizeof(eni->RotorPerm[0][0]), CHAR_NUM, fp);
		if (rtnF != CHAR_NUM)
		{
			printf("Error %s: expected %d but got %llu bytes after reading.\n", PathRotor, CHAR_NUM, rtnF);
			return 1;
		}

		rtnF = fread(&eni->RotorTrans[i], sizeof(eni->RotorTrans[0]), sizeof(eni->RotorTrans[0]), fp);
		if (rtnF != sizeof(eni->RotorTrans[0]))
		{
			printf("Error %s: expected %llu but got %llu bytes after reading.\n", PathRotor, sizeof(eni->RotorTrans[0]), rtnF);
			return 1;
		}
		fclose(fp);
		fp = NULL;
	}
	return 0;
}

int loadPlugboardConfig(struct Enigma* eni)
{
	FILE* fp;
	const char pathPlg[] = "plugboard/plugboard.txt";
	size_t rtnF;
	char nChar; // var for reading NULL
	fp = fopen(pathPlg, "r");

	if (fp == NULL)
	{
		perror(pathPlg);
		return 1;
	}

	int i = 0;
	do
	{
		rtnF = fread(eni->Plugboard[i++], sizeof(eni->Plugboard[0][0]), PAIR, fp);
		fread(&nChar, sizeof(char), 1, fp); // reading '\n' character

	} while (rtnF == PAIR);

	if (!feof(fp)) // Jesli po odczytaniu nie zostal osiagniety koniec pliku to cos jest nie tak
	{
		printf("Error reading : %s\n", pathPlg);
		return 1;
	}

	fclose(fp);
	fp = NULL;
	return 0;
}

int loadReflectorConfig(struct Enigma* eni)
{
	FILE* fp;
	size_t rtnF;
	char PathRef[] = "rotor_mech/reflector0.txt";

	PathRef[sizeof(PathRef) - 6] = eni->reflectorNum;

	fp = fopen(PathRef, "r");
	if (fp == NULL)
	{
		perror(PathRef);
		return 1;
	}

	rtnF = fread(eni->RefPerm, sizeof(eni->RefPerm[0]), CHAR_NUM, fp);
	if (rtnF != CHAR_NUM)
	{
		printf("Error %s: expected %d but got %llu bytes after reading.\n", PathRef, CHAR_NUM, rtnF);
		return 1;
	}
	fclose(fp);
	fp = NULL;

	return 0;
}

int loadUserInput(struct Enigma* eni)
{
	FILE* fp;
	const char pathCfg[] = "config/config.txt";
	size_t rtnF;
	char nChar;
	fp = fopen(pathCfg, "r");

	if (fp == NULL)
	{
		perror(pathCfg);
		return 1;
	}

	// Reading key
	rtnF = fread(eni->Key, sizeof(eni->Key[0]), ROTOR_COUNT, fp);
	fread(&nChar, sizeof(char), 1, fp);

	// Reading rotor order
	rtnF = fread(eni->RotorOrder, sizeof(eni->RotorOrder[0]), ROTOR_COUNT, fp);
	fread(&nChar, sizeof(char), 1, fp);

	// Reading reflector number
	rtnF = fread(&eni->reflectorNum, sizeof(eni->reflectorNum), 1, fp);
	fread(&nChar, sizeof(char), 1, fp);

	if (!feof(fp)) // Jesli po odczytaniu nie zostal osiagniety koniec pliku to cos jest nie tak
	{
		printf("Error reading : %s\n", pathCfg);
		fclose(fp);
		return 1;
	}

	fclose(fp);
	fp = NULL;
	return 0;
}

char* loadTxt(struct Enigma* eni, const char choice)
{
	FILE* fp;
	char Buffer[BUF_SIZE] = { 0 }, *Txt;
	const char path[] = "io/in.txt";

	switch (choice)
	{
		case '1':
		{
			printf("Wprowadz tekst do zakodowania z klawiatury: ");
			scanf("%s", Buffer);
			break;
		}
		case '2':
		{
			printf("Wczytywanie tekstu z pliku: in.txt\n");
			fp = fopen(path, "r");
			if (fp == NULL)
			{
				perror(path);
				return 1;
			}

			if (fgets(Buffer, BUF_SIZE, fp) == NULL)
				return 1;
			fclose(fp);
			fp = NULL;
			break;
		}
		default:
		{
			printf("Zla opcja\n");
			return 1;
		}
	}


	unsigned int txtSiz = strlen(Buffer) + 1;
	Txt = calloc(txtSiz, sizeof(Buffer[0]));
	if (Txt == NULL)
		return 1;

	memcpy(Txt, Buffer, txtSiz);
	Txt = _strupr(Txt);

	return Txt;
}

void saveTxt(const char EncTxt[])
{

}
