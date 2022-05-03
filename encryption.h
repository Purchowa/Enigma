#ifndef  _ENCRYPTION_H
#define _ENCRYPTION_H

#include "func_lib.h"

#define I(c) ((c) - (CHAR_BEGIN))
#define LoopAlph(c) ((c) % (CHAR_NUM))
#define KeyPositive(k) ((k) + CHAR_NUM)

char* code(struct Enigma* eni, const char Txt[]);

#endif // ! _ENCRYPTION_H

