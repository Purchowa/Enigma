#ifndef  _ENCRYPTION_H
#define _ENCRYPTION_H

#include "func_lib.h"

#define I(c) ((c)-'A')
#define LOOP_ALPH(c) ((((c) - 'A') % (CHAR_NUM)) + 'A')

char* code(struct Enigma* eni, const char Txt[]);
void incKey(struct Enigma* eni);
void shiftRotor(struct Enigma* eni);
char encryptChar(struct Enigma* eni, const char* c);




#endif // ! _ENCRYPTION_H

