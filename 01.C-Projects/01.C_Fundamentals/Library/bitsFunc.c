#include "bitsFunc.h"

u8bit u8_get_bit(u8 num, u8bitpos pos)
	//връща стойността на бит от число num на дадена позиция pos*
{
	u8 mask = 0b01 << pos;
	num &= mask;
	return (num == mask) ? 1 : 0;
}
u8 u8_set_bit_on(u8 num, u8bitpos pos)
	//променя стойността на бит от число num на дадена позиция pos на 1
{
	u8 mask = 0b01 << pos;
	return num | mask;
}
u8 u8_set_bit(u8 num, u8bitpos pos, u8bit val)
//която връща стойността на число, образувано от числото num с променен бит на позиция pos.Стойността на бита се подава от val.
{
	if (val)
	{
		return  u8_set_bit_on(num, pos);
	}
	else
	{
		return u8_set_bit_off(num, pos);
	}
}
u8 u8_set_bit_off(u8 num, u8bitpos pos)
//променя стойността на бит от число num на дадена позиция pos на 0
{
	u8 mask = 0b01 << pos;
	mask = ~mask;
	return num & mask;
}

void u8_print_bits(FILE* f, u8 num)
////принтира битовете на число num на подадения й файлов поток
{
	u8  mask;
	for (mask = 1 << 7; mask > 0; mask = mask >> 1)
		(num & mask) ? fprintf(stdout, "1") : fprintf(stdout, "0");
}
u8 u8_scan_bits(FILE* f)
//парсва число на побитов принцип от следващите осем символа в подадения й файлов поток
{
	u8 num = 0b00000000;
	for (unsigned i = 0; i < 8; i++)
	{
		char ch = getc(f);
		int n = 0;
		if (ch == '0')
		{
			n = 0;
		}
		else if (ch == '1')
		{
			n = 1;
		}
		num = u8_set_bit(num, 7 - i, n);
	}
	return num;
}

u8 u8_toggle_bit(u8 num, u8bitpos pos)
//променя стойността на бит от число num на дадена позиция pos на обратната й
{
	u8 mask = 0b01 << pos;
	return num ^ mask;
}
u8 u8_toggle_bits(u8 num)
//променя всичките битове от число num на обратните, така че да са равни на обратните им стойности
{
	return ~num;
}
u8 u8_reverse_bits(u8 num)
//обръща стойностите на битовете на число num в обратен ред
{
	for (u8 i = 0; i < BYTE / 2; i++)
	{
		u8 maskFront = 0b01 << (BYTE - i - 1);
		u8 maskBack = 0b01 << i;
		u8 maskReverseFront = num & maskFront;
		u8 maskReverseBack = num & maskBack;
		if (maskReverseFront)
		{
			num = u8_set_bit_on(num, i);
		}
		else
		{
			num = u8_set_bit_off(num, i);
		}
		if (maskReverseBack)
		{
			num = u8_set_bit_on(num, BYTE - i - 1);
		}
		else
		{
			num = u8_set_bit_off(num, BYTE - i - 1);
		}
	}
	return num;
}