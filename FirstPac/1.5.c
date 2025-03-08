//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int algoritm_evklida(int a, int b) {
//	while (a != 0 && b != 0) {
//		if (a > b)
//			a = a % b;
//		else
//			b = b % a;
//	}
//	printf("%d\n", a + b);
//}
//
//int main() {
//	int Test_count;
//	scanf("%d", &Test_count);
//	for (int i = 0; i < Test_count; i++) {
//		int a, b;
//		scanf("%d%d", &a, &b);
//		algoritm_evklida(a, b);
//	}
//
//}
//
////
////
//////// если a и b имеют общий делитель d,то d также является делителем для разницы a - b.
//////// Следовательно, если мы последовательно вычисляем остатки от деления, мы в конечном итоге 
//////// получим пару чисел, одно из которых равно 0, а второе равно НОД исходных чисел a и b.
////
////
