//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//// x_x
//long long NOD(long long a, long long b, long long* x, long long* y)
//{
//	if (a == 0)
//	{
//		*x = 0;
//		*y = 1;
//		return b;
//	}
//
//	long long x1, y1;
//	long long gcd = NOD(b % a, a, &x1, &y1);
//
//	*x = y1 - (b / a) * x1;
//	*y = x1;
//
//	return gcd;
//}
//
//long long inv(long long b, long long m)
//{
//	long long x, y;
//	long long g = NOD(b, m, &x, &y);
//	if (g != 1)
//	{
//		return -1;
//	}
//
//	return (x % m + m) % m;
//}
//
//
//long long mod(long long a, long long b)
//{
//	return a % b;
//}
//
// 
//long long made_in_china_make_accidentally(int count, int* mod_arr, int* residue_arr) {
//	long long multy_modul = 1;
//	for (int i = 0; i < count; i++)
//		multy_modul *= mod_arr[i]; // произведение всех делителей 1 шаг
//
//	long long res = 0;
//
//	for (int i = 0; i < count; i++) {
//		long long and_ = (multy_modul / mod_arr[i]);// 2 шаг делим произведение делителей на m1
//		res = mod(res + and_ * mod(residue_arr[i] * inv(mod(and_, mod_arr[i]), mod_arr[i]), mod_arr[i]), multy_modul);
//	}
//	return res % multy_modul;
//}
//
//int main() {
//
//	int count_modul;
//	scanf("%d", &count_modul);
//
//	int* modul_array = (int*)malloc(sizeof(int)* count_modul); // модули
//	for (int i = 0; i < count_modul; i++) {
//		scanf("%d", &modul_array[i]);
//	}
//	int* residue_array = (int*)malloc(sizeof(int) * count_modul); // остатки от делени€
//	for (int i = 0; i < count_modul; i++) {
//		scanf("%d", &residue_array[i]);
//	}
//	 
//
//	printf("%lld", made_in_china_make_accidentally(count_modul, modul_array, residue_array));
//	free(modul_array);
//	free(residue_array);
//}



/*¬ычисление нового значени€ переменной res с помощью формулы, котора€ состоит из нескольких шагов :
   -ƒеление значени€ and_ на mod_arr[i].
   - ¬ычисление обратного элемента дл€ полученного значени€(функци€ inv).
	- ”множение этого обратного элемента на residue_arr[i].
	- ¬з€тие остатка от делени€ этого произведени€ на mod_arr[i].
	- ѕрибавление этого значени€ к текущему значению res.
	- ¬з€тие остатка от делени€ полученной суммы на multy_modul.
	*/