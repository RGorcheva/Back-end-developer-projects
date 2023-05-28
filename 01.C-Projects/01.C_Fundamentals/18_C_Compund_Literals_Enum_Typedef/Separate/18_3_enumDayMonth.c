/*
Дефинирайте enum константи за ден в седмицата и месец в годината (например: enum
weekday, enum month, E_Weekday, E_Month, ..).
Дефинирайте алтернативно име на типовете с typedef, така че да не се налага да
ползваме ключовата дума enum при дефиниция на променливи от типовете.
*/

typedef enum weekday{
	Sun,
	Mon, 
	Tu, 
	Wed, 
	Th, 
	Fr, 
	Sat
} E_weekday;

typedef enum month{
	Jan,
	Feb,
	Mar,
	Apr,
	May,
	Jun,
	Jul,
	Aug, 
	Sep,
	Oct,
	Nov,
	Dec
} E_month;