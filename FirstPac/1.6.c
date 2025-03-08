//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
// 
// //Алгоритм заключается в последовательном нахождении 
// //остатка от деления одного числа на другое и замены
// //чисел друг на друга до тех пор, пока остаток не станет равен 0.
// //При этом наибольший общий делитель будет равен последнему ненулевому остатку.
//int inverse_number(int x, int n) {
//	int a = 1, b = 0, m = n, t;
//	while (n != 0) {
//		int q = x / n;
//		t = a;
//		a = b;
//		b = t - q * b;
//		t = x;
//		x = n;
//		n = t - q * n;
//	}
//	if (x == 1) {
//		if (a < 0) {
//			a = (a % m + m) % m;
//		}
//		return a; // Обратное число
//	}
//	return -1; // Обратного числа не существует
//}
//
//unsigned long long* array_factorial(int n) { // массив факториалов
//
//	unsigned long long M = 1000000007;
//
//	unsigned long long* array = (unsigned long long*)malloc(sizeof(unsigned long long) * (n + 1));
//
//	array[0] = 1;
//	for (int i = 1; i <= n; i++) {
//		array[i] = (array[i - 1] * i) % M;
//	}
//	return array;
//	free(array);
//}
//
//unsigned long long factorial(int n, unsigned long long* factorialaz) { // возвращает факториал
//	return factorialaz[n];
//}
//
// // C(n, k) = n! / (k! * (n - k)!)
//unsigned long long binom_koefficient(int n, int k, unsigned long long* factorialaz) { // C(n, k) = n! / (k! * (n - k)!)
//
//	unsigned long long M = 1000000007;
//
//	unsigned long long chislitel = factorial(n, factorialaz);
//	unsigned long long znamenatel = (factorial(k, factorialaz) * factorial(n - k, factorialaz)) % M;
//	unsigned long long inverse_znamenatel = inverse_number(znamenatel, M); // нужен для того чтобы избежать вычисления больших чисел
//	unsigned long long res = (chislitel * inverse_znamenatel) % M;
//
//	return res;
//
//}	
//
//int main() {
//	int T;
//	scanf("%d", &T);
//
//	unsigned long long* factorialaz = array_factorial(1000001);
//
//	for (int i = 0; i < T; i++) {
//		int n, k;
//
//		scanf("%d%d", &n, &k);
//		unsigned long long result = binom_koefficient(n, k, factorialaz);
//
//		printf("%llu\n", result);
//	}
//	free(factorialaz);
//}