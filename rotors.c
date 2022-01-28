#include "rotors.h"

void initEnigma(struct Enigma* machine)
{
	strcpy(machine->Key, "GLF");
	machine->RotorOrder[0] = '2';
	machine->RotorOrder[1] = '1';
	machine->RotorOrder[2] = '3';

	if (loadData(machine))
		return;
	
}

int loadData(struct Enigma* machine)
{
	// Returns true if failed.
	FILE* fp;
	char PathRotor[] = "rotor_mech/rotor0.txt";
	size_t rtnF;

	for (int i = 0; i < ROTORCOUNT; i++)
	{
		PathRotor[sizeof(PathRotor) - 6] = machine->RotorOrder[i];

		fp = fopen(PathRotor, "r");
		if (fp == NULL)
		{
			perror(PathRotor); // Drukuje komunikat o bledzie na stderr z errno
			return 1;
		}

		rtnF = fread(machine->RotorPerm[i], sizeof(machine->RotorPerm[0][0]), CHAR_NUM, fp);
		if (rtnF != CHAR_NUM)
		{
			printf("Error %s: expected %d but got %llu bytes after reading.\n", PathRotor, CHAR_NUM, rtnF);
			return 1;
		}
		
		rtnF = fread(&machine->RotorTrans[i], sizeof(machine->RotorTrans[0]), sizeof(machine->RotorTrans[0]), fp);
		if (rtnF != sizeof(machine->RotorTrans[0]))
		{
			printf("Error %s: expected %llu but got %llu bytes after reading.\n", PathRotor, sizeof(machine->RotorTrans[0]), rtnF);
			return 1;
		}
		fclose(fp);
		fp = NULL;
	}
	return 0;
}
