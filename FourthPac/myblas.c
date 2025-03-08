////это myblas_func
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//void cblas_dgemm(
//    int Order, int TransA,
//    int TransB, const int M, const int N,
//    const int K, const double alpha, const double* A,
//    const int lda, const double* B, const int ldb,
//    const double beta, double* C, const int ldc) {
//
//    // По условиям задачи, этот код должен работать только для операции A * A
//
//    for (int i = 0; i < M; ++i)
//    {
//        double* c = C + i * N;
//        for (int j = 0; j < N; ++j)
//            c[j] = 0;
//        for (int k = 0; k < K; ++k)
//        {
//            const double* b = B + k * N;
//            double a = A[i * K + k];
//            for (int j = 0; j < N; ++j)
//                c[j] += a * b[j];
//        }
//    }
//}