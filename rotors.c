#include "rotors.h"

void initEnigma(struct Enigma* machine)
{
	if (loadData(machine))
		return;
	printf("%d\n", machine->reflector);
}

int loadData(struct Enigma* machine)
{
	FILE* file;
	file = fopen("config.txt", "r");
	if (file == NULL)
	{
		perror("Blad - config.txt : "); // Drukuje komunikat o bledzie na stderr z errno
		return 1;
	}

	/*fgets(machine->Key, ROTORCOUNT, file);
	fgets(machine->RotorOrder, ROTORCOUNT, file);*/
	fscanf(file, "%s", machine->Key);
	fscanf(file, "%s", machine->RotorOrder);
	machine->reflector = fgetc(file);

	fclose(file);
	return 0;
}
