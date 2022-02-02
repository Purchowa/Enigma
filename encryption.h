#ifndef  _ENCRYPTION_H
#define _ENCRYPTION_H

#include "func_lib.h"

#define I(c) ((c)-'A')
#define LoopAlph(c) ((((c) - 'A') % (CHAR_NUM)) + 'A')
#define RotorPermSH(rotor, i, key) (eni->RotorPerm[(rotor)][((i) + I(key)) % (CHAR_NUM)])

char* code(struct Enigma* eni, const char Txt[]);
void incKey(struct Enigma* eni);
char encryptChar(struct Enigma* eni, const char* c);
char plugboardSwap(struct Enigma* eni, const char* c);




#endif // ! _ENCRYPTION_H

