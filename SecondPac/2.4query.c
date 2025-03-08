////query.c
//#include <stdint.h>
//
//extern int n;
//int64_t Sum(int l, int r);
//
//
//
//void Init(const int* arr, int n);
//int64_t Sum(int l, int r);
//
//
//int Query(int l, int64_t sum) {
//    int L = l;
//    int R = n;
//    int m = 0;
//    while (L < R) {
//        m = L + (R - L) / 2;
//        if (Sum(l, m + 1) <= sum) {
//            L = m + 1;
//        }
//        else {
//            R = m;
//        }
//    }
//    return L;
//
//}