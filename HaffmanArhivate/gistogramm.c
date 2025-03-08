#include "all_functions.h"

void calculateFrequencies(const char* filename, unsigned char** buffer, int* freq, long* size) {
    FILE* file = fopen(filename, "rb");

    // ѕолучаем размер файла
    fseek(file, 0, SEEK_END); // ѕеремещаем указатель позиции чтени€/записи в конец файла.
    *size = ftell(file); //  текущ€€ позици€ указател€ = размер файла в байтах.
    rewind(file); // указатель обратно в начало файла

    // „итаем данные файла в буфер
    *buffer = (unsigned char*)malloc((*size) * sizeof(unsigned char));
    fread(*buffer, sizeof(unsigned char), *size, file);

    // —читаем частоты символов
    for (long i = 0; i < *size; ++i) { // ÷икл, который проходит по каждому байту в буфере
        freq[(*buffer)[i]]++;
    }

    fclose(file);
}























