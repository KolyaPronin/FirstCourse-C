//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//
//unsigned long long** Paskal_triangle(int n, int M) { // количество строк в треугольнике  и модуль
//    unsigned long long** paskal_triangle = (unsigned long long**)malloc(sizeof(unsigned long long*) * (n + 1));   // выделяем память под  массив указателей, каждый указатель указывает на строку в треугольнике
//    for (int i = 0; i <= n; ++i) {    // по строкам треугольника                                                          
//        paskal_triangle[i] = (unsigned long long*)malloc((i + 1) * sizeof(unsigned long long));  // выделяется память под массив хранящий значени биномальных коэфицентов строки
//        paskal_triangle[i][0] = paskal_triangle[i][i] = 1;//     все крайние элементы равны 1
//        for (int j = 1; j < i; ++j)
//            paskal_triangle[i][j] = (paskal_triangle[i - 1][j - 1] + paskal_triangle[i - 1][j]) % M;
//    }
//    return paskal_triangle ;
//}
//
//unsigned long long binomCoefficient(int n, int k, unsigned long long** paskal_triangle) {
//    if (k < 0 || k > n)
//        return 0;
//    return paskal_triangle[n][k];      // возращает кофицент из треугольника согласно заданным параметрам
//}
//
//void free_triangle(unsigned long long** triangle, int n) { // освобождаем память 
//    for (int i = 0; i <= n; ++i) {
//        free(triangle[i]);   
//    }
//    free(triangle);
//}
//
//int main() {
//    FILE* input_file = fopen("input.txt", "r");
//    FILE* output_file = fopen("output.txt", "w");
//
//    int M, T;
//    fscanf(input_file, "%d", &M);
//    fscanf(input_file, "%d", &T);
//
//    // Генерируем треугольник Паскаля 
//    unsigned long long** pascalTriangle = Paskal_triangle(2001,M); // генерируем 1 раз, но зато здоровенный
//
//    for (int i = 0; i < T; ++i) {
//        int n, k;
//        fscanf(input_file, "%d", &n);
//        fscanf(input_file, "%d", &k);
//
//        // Вычисляем биномиальный коэффициент
//        fprintf(output_file, "%llu\n", (unsigned long long)binomCoefficient(n, k, pascalTriangle) );
//    }
//
//    fclose(input_file);
//    fclose(output_file);
//
//    // Освобождаем память, выделенную для треугольника Паскаля
//    free_triangle(pascalTriangle, 2001);
//
//    return 0;
//}
//
//
//
//     //               1
//					//1   1 
//     //            1  2  1
//     //           1 3  3  1 
//     //          1 4  6  4 1
//     //         1 5 10 10 5 1
//     //        1 6 15 20 15 6 1
//     //       1 7 21 35 35 21 7 1
//
//
//
//
//
//
