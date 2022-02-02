#include "rotor_config.h"

void initEnigma(struct Enigma* eni)
{
	eni->Key[0] = 'G';
	eni->Key[1] = 'L';
	eni->Key[2] = 'F';

	eni->RotorOrder[0] = '2';
	eni->RotorOrder[1] = '1';
	eni->RotorOrder[2] = '3';

	eni->reflectorNum = '1';

	if (loadData(eni))
	{
		printf("error\n");
		return;
	}
	
}

int loadData(struct Enigma* eni)
{
	// Feature - zabezpieczenie przed dublowaniem sie na Plugboard wtyczek
	// Feature - zabezpiecznie przed wczytaniem z pliku czegos innego niz ['A', 'Z']
	return loadRotorConfig(eni) | loadPlugBoardConfig(eni) | loadReflectorConfig(eni);
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

int loadPlugBoardConfig(struct Enigma* eni)
{
	FILE* fp;
	const char pathPlg[] = "plugboard/plugboard.txt";
	size_t rtnF;
	char nChar;
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

	} while(rtnF == PAIR);

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