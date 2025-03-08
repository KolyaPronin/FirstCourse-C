//#include "integerset.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//// Бинарный поиск в массиве
//int BinarySearch(const int* array, unsigned long long size, int number) {
//    unsigned long long low = 0, high = size, mid;
//    while (low < high) {
//        mid = low + (high - low) / 2;
//        if (array[mid] == number) return mid;
//        else if (array[mid] < number) low = mid + 1;
//        else high = mid;
//    }
//    return -1;
//}
//
//// Сравнение для qsort
//int CompareInts(const void* a, const void* b) {
//    int arg1 = *(const int*)a;
//    int arg2 = *(const int*)b;
//
//    return (arg1 > arg2) - (arg1 < arg2);
//}
//
//IntegerSet* CreateSet(const int* numbers, unsigned long long size) {
//    if (size > 0 && numbers == NULL) return NULL;
//
//    IntegerSet* set = (IntegerSet*)malloc(sizeof(IntegerSet));
//    if (!set) return NULL;
//
//    set->data = malloc(size * sizeof(int));
//    if (!set->data) {
//        free(set);
//        return NULL;
//    }
//
//    memcpy(set->data, numbers, size * sizeof(int));
//    qsort(set->data, size, sizeof(int), CompareInts);
//
//    // Проверка на дубликаты после сортировки
//    for (unsigned long long i = 1; i < size; i++) {
//        if (set->data[i] == set->data[i - 1]) {
//            free(set->data);
//            free(set);
//            return NULL;
//        }
//    }
//
//    set->size = size;
//    return set;
//}
//
//void DeleteSet(IntegerSet* set) {
//    if (set) {
//        free(set->data);
//        free(set);
//    }
//}
//
//int IsInSet(const IntegerSet* set, int number) {
//    if (set == NULL || set->size == 0) return 0;
//    int index = BinarySearch(set->data, set->size, number);
//    return (index != -1) ? 1 : 0;
//}
