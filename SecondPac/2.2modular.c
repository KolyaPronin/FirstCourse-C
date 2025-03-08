#include "modular.h"

int MOD;

int pnorm(int x) {
    int res = x % MOD;
    if (res >= 0)
        return res;
    else return res + MOD;
}

int padd(int x, int y) { // all correct

    return (pnorm(x) + pnorm(y)) % MOD;
}

int psub(int x, int y) {   // all correct too
    return (pnorm(x) - pnorm(y) + MOD) % MOD;
}
int pmul(int x, int y) {

    long long  res = ((long long)x * (long long)y) % MOD; //?
    if (res >= 0) {
        return res ;
    }
    else {
        return res + MOD;
    }

}

long long NOD(long long a, long long b, long long* x, long long* y)
{
	if (a == 0)
	{
		*x = 0;
		*y = 1;
		return b;
	}

	long long x1, y1;
	long long gcd = NOD(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

long long inv(long long b, long long m)
{
	long long x, y;
	long long g = NOD(b, m, &x, &y);
	if (g != 1)
	{
		return -1;
	}

	return (x % m + m) % m;
}

 // Результатом выполнения функции pdiv будет частное от деления x на y по модулю.
int pdiv(int x, int y) {
	int inv_b = inv(y, MOD);
	return pmul(x, inv_b);
}



// gcc -c C:\Users\kolya\source\repos\Project2\2Pac\main.c
// gcc -c C:\Users\kolya\source\repos\Project2\2Pac\modular.c
//gcc -o myprogram main.o modular.o

