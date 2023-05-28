/*
Използвайте typedef за да дефинирате алтернативни имена на следните типове:
● Функция, която не приема параметри и връща double
● Функция, която приема два double параметъра и не връща нищо
● Функция, която приема един int параметър и връща указател към функция, която не приема параметри и връща int
● Функция, която взима три указателя към три различни типа функции - същите типове като на по-горните три типа функции (за
които вече имаме алтернативни имена)
*/

typedef double typef1(void);
double (*pf1)(void);
typedef void typef2(double a, double b);
void (*pf2)(double, double);
typedef int (*pf3)(void);
typedef pf3 typef4(int a);
pf3 (*pf4)(int);
typedef void typef5(typef1* pf1, typef2* pf2, typef4* pf4);


