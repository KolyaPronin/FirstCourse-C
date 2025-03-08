#ifndef MODULAR_H
#define MODULAR_H	

extern int MOD; // Объявление глобальной переменной

int pnorm(int x); // Прототипы функций
int padd(int x, int y);
int psub(int x, int y);
int pmul(int x, int y);
int pdiv(int x, int y);
long long inv(long long b, long long m);
long long NOD(long long a, long long b, long long* x, long long* y);

#endif /* MODULAR_H */
