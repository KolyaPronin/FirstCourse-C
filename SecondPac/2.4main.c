////main.c
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdint.h>
//
//void Init(const int* arr, int n);
//int Query(int l, int64_t sum);
//int n;
//
//
//int main() {
//	FILE* inputFile = fopen("input.txt", "r");
//	FILE* outputFile = fopen("output.txt", "w");
//	//int n;
//	int m;
//	fscanf(inputFile,"%d%d", &n, &m);
//
//	int arr[100001] = {0};
//	for (int i = 0; i < n; i++) {
//		fscanf(inputFile, "%d", &arr[i]);
//	}
//	
//	Init(arr, n);
//
//	
//	for (int i = 0; i < m; i++) {
//		int l;
//		long long s;
//		fscanf(inputFile, "%d%lld", &l, &s);
//		int res = Query(l, s);
//		fprintf(outputFile, "%d\n", res);
//	}
//	fclose(inputFile);
//	fclose(outputFile);
//
//}
//
