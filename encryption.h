#ifndef  _ENCRYPTION_H
#define _ENCRYPTION_H

#include "func_lib.h"

#define I(c) ((c)-'A')
#define LoopAlph(c) ((((c) - 'A') % (CHAR_NUM)) + 'A')
#define RotorPermSH(i, j, key) (eni->RotorPerm[(i)][((j) + I(key)) % (CHAR_NUM)])

char* code(struct Enigma* eni, const char Txt[]);
void incKey(struct Enigma* eni);
void shiftRotors(struct Enigma* eni);
char encryptChar(struct Enigma* eni, const char* c);




#endif // ! _ENCRYPTION_H

