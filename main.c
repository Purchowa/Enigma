#include "rotors.h"

int main()
{
	struct Enigma enigma = {0}; // Inicjalizacja wartosci struktury
	const char Code[] = "S";

	initEnigma(&enigma);

	return 0;
}