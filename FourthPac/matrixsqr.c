////это matrixsqr
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include "cblas.h"
//#define MyCblasRowMajor 101
//#define MyCblasNoTrans 111
//
//void myblas_func(
//    int Order, int TransA,
//    int TransB, const int M, const int N,
//    const int K, const double alpha, const double* A,
//    const int lda, const double* B, const int ldb,
//    const double beta, double* C, const int ldc);
//
//void MatrixSqr(int n, const double* A, double* R) {
//    for (int i = 0; i < n * n; ++i) {
//        R[i] = 0.0;
//    }
//    cblas_dgemm(MyCblasRowMajor, MyCblasNoTrans, MyCblasNoTrans,
//        n, n, n, 1.0, A, n, A, n, 0.0, R, n);
//}
// //gcc -c matrixsqr.c -o matrixsqr.o
////gcc - c main.c - o main.o
// //gcc - pthread - o checked_solution matrixsqr.o main.o - Wl, -rpath = .libopenblas.so
