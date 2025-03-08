#include "modular.h"
#include <assert.h>

int main() {
    MOD = 13; // Устанавливаем глобальный модуль
    int a = 45;
    a = pnorm(a);
    assert(a == 6);

    int b = -45;
    b = pnorm(b);
    assert(b == 7);

    int c = 0;
    c = padd(a, b);
    assert(c == 0);

    int x = pmul(padd(7, psub(2, 3)), 5);
    assert(x == 4);

    int y = pdiv(7, x);
    assert(pmul(x, y) == 7);

    MOD = 2;
    assert(pnorm(5) == 1);
    assert(pnorm(-5) == 1);

    MOD = 5;
    int f1 = 4;
    int f2 = 2;
    assert(padd(f1, f2) == 1);
    assert(psub(f2, f1) == 3);

    MOD = 1000003;
    int n1 = 1000001;
    int n2 = 1000002;
    assert(pmul(n1, n2) == 2);

    MOD = 999999937;
    int g1 = 1;
    int g2 = 15;
    assert(pdiv(g2, g1) == 15);
    return 0;
}
