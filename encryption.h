#ifndef  _ENCRYPTION_H
#define _ENCRYPTION_H

#include "func_lib.h"

#define I(c) ((c)-'A')

char* code(struct Enigma* eni, const char Txt[]);
void incKey(struct Enigma* eni);
void shiftRotor();
char encryptChar(struct Enigma* eni, const char* c);




#endif // ! _ENCRYPTION_H

