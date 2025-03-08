////sum.c
//#include <stdint.h>
//
//int64_t prefixSum[100001];
//
//
//void Init(const int* arr, int n) {
//
//	
//	prefixSum[0] = 0;
//	for (int i = 0; i < n; i++) {
//		prefixSum[i+1] = prefixSum[i] + arr[i];
//	}
//}
//
//int64_t Sum(int l, int r) {
//	// 1 найти с помощью массива префиксных сумм от 0 до r  и  от 0 до l  и вычести из  1 второй
//	return  (prefixSum[r] - prefixSum[l]);
//}
//
//
