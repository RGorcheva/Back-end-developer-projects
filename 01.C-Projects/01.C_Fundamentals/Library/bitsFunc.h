#ifndef BITSFUNC_H
#define BITSFUNC_H

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define BYTE 8

#if (CHAR_BIT != 8)
#error Error CHAR_BIT is not 8!
#else
typedef unsigned char u8;
typedef u8 u8bitpos; // used for specifying bit positions
typedef bool u8bit; // value of a bit
#endif

u8bit u8_get_bit(u8 num, u8bitpos pos);  //връща стойността на бит от число num на дадена позиция pos*
u8 u8_set_bit_on(u8 num, u8bitpos pos);  //променя стойността на бит от число num на дадена позиция pos на 1
u8 u8_set_bit_off(u8 num, u8bitpos pos); //променя стойността на бит от число num на дадена позиция pos на 0
u8 u8_set_bit(u8 num, u8bitpos pos, u8bit val); //връща стойността на число, образувано от числото num с 
//променен бит на позиция pos.Стойността на бита се подава от val.

void u8_print_bits(FILE* f, u8 num);     //принтира битовете на число num на подадения й файлов поток
u8 u8_scan_bits(FILE* f); ////парсва число на побитов принцип от следващите осем символа в подадения й файлов поток

u8 u8_toggle_bit(u8 num, u8bitpos pos);  //променя стойността на бит от число num на дадена позиция pos на обратната й
u8 u8_toggle_bits(u8 num); //променя всичките битове от число num на обратните, така че да са равни на обратните им стойности
u8 u8_reverse_bits(u8 num); //обръща стойностите на битовете на число num в обратен ред


#endif