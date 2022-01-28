#include "rotors.h"

void initEnigma(struct Enigma* machine)
{
	strcpy(machine->Key, "GLF");
	machine->RotorOrder[0] = '2';
	machine->RotorOrder[1] = '1';
	machine->RotorOrder[2] = '3';

	if (loadData(machine))
		return;
	printf("%c\n", machine->RotorTransmission[0]);
	printf("%s\n", machine->RotorPermutation[0]);
}

int loadData(struct Enigma* machine)
{
	// Returns true if failed.
	FILE* fp;
	char PathRotor[] = "rotor_mech/rotor0.txt";
	size_t rtnF;

	PathRotor[sizeof(PathRotor) - 6] = machine->RotorOrder[0];
	fp = fopen(PathRotor, "r");
	if (fp == NULL)
	{
		perror(PathRotor); // Drukuje komunikat o bledzie na stderr z errno
		return 1;
	}

	rtnF = fread(machine->RotorPermutation[0], sizeof(machine->RotorPermutation[0][0]), CHAR_NUM, fp);
	rtnF = fread(&machine->RotorTransmission[0], sizeof(machine->RotorPermutation[1][0]), 1, fp);

	printf("%d\n", rtnF);
	fclose(fp);
	fp = NULL;
	return 0;
}
