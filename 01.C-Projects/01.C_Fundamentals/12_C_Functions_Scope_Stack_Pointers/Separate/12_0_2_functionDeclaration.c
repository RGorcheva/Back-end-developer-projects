/*
Напишете декларации (без дефиниция) на следните функции:
● Функция print_int_arr, която принтира стойностите на елементите на масив от цели
числа
● Функция set_all_int_arr_elements, която променя всички елементи на масив на подадена
стойност
● Функция copy_int_arr, която копира стойностите на елементите на един масив от int в
елементите на друг
● Функция print_str, която принтира C string.
● Функция print_char_arr, която принтира масив от char
● Функция swap_int, която обръща стойностите на 2 int променливи
*/

void print_int_array(const int* begin, const size_t sizeArr);
void set_all_int_array_elements(int* begin, int sizeArr, int n);
void copy_int_array(const int* begin1, const int sizeArr1, int* begin2, int sizeArr2);
void print_str(const char* begin);
void print_char_array(const char* begin, const int sizeArr);
void swap_int(int* a, int* b);