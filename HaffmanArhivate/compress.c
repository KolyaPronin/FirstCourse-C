#include "all_functions.h"


// Кодируем данные и записываем их в файл
void encodeData(unsigned char* buffer, long size, char** codes, FILE* output) {
    unsigned char byte = 0;
    int bit_count = 0;
    // идет по каждому байту в buffer и заменяет каждый байт его кодом Хаффмана, используя массив codes
    for (long i = 0; i < size; ++i) {
        char* code = codes[buffer[i]];
        int code_length = strlen(code);

        for (int j = 0; j < code_length; ++j) {
            byte = byte << 1; // Сдвигаем на один бит влево
            if (code[j] == '1') { 
                byte = byte | 0x01; // Устанавливаем крайний правый бит в 1, если текущий бит в коде равен '1'
            }
            bit_count++;

            if (bit_count == 8) { // Если байт заполнен
                fputc(byte, output); // Записываем байт в файл
                byte = 0; // Обнуляем байт
                bit_count = 0; // Обнуляем счетчик битов
            }
        }
    }

    // Записываем оставшиеся биты, если есть
    if (bit_count > 0) {
        byte = byte << (8 - bit_count); // Добавляем нули справа до заполнения байта
        fputc(byte, output); // Записываем байт в файл
    }
}

void writeEncodedDataToFile(const char* filename, unsigned char* buffer, long size, char** codes) {
    FILE* output = fopen(filename, "wb");

    encodeData(buffer, size, codes, output);
    fclose(output);
}




