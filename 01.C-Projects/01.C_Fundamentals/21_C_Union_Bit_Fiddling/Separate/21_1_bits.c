/*
*Нека направим малка помощна библиотека за high-level побитови манипулации с 8-битови положителни числа 
(например u8.h, bits.h, ..). Ползвайте имена по ваш избор за задачите за библиотеката.

Библиотеката трябва да ползва unsigned char за типа на числата и за позициите на отделните битове, _Bool за стойността на бит.
Използвайте typedef за да не се налага да променяме кода на функциите на библиотеката ако решим да ползваме други типове.
Можем и да ползваме conditional compilation макроси за да потвърдим, че компилираме за архитектура с 8-битов байт по следния
начин:
#include <limits.h>
#if (CHAR_BIT != 8)
#error Error CHAR_BIT is not 8!
#else
typedef unsigned char u8;
typedef u8 u8bitpos; // used for specifying bit positions
typedef _Bool u8bit; // value of a bit
#endif
*/

