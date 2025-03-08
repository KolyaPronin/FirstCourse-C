#include "all_functions.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {   // Проверяем, что количество аргументов равно 3
        fprintf(stderr, "Usage: %s <input_filename> <output_filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* inputFilename = argv[1];
    const char* outputFilename = argv[2];

    unsigned char* buffer = NULL;
    int freq[MAX_TREE_HT] = { 0 };
    long size = 0;

    calculateFrequencies(inputFilename, &buffer, freq, &size); // Вычисляем частоты символов в исходном файле

    // Создаем массив данных и массив частот для символов, которые встречаются в файле
    unsigned char data[MAX_TREE_HT];
    int freqNonZero[MAX_TREE_HT];
    int j = 0;
    for (int i = 0; i < MAX_TREE_HT; ++i) {
        if (freq[i] > 0) {
            data[j] = i;
            freqNonZero[j] = freq[i];
            j++;
        }
    }
    // Генерируем коды Хаффмана для символов
    char* codes[MAX_TREE_HT] = { 0 };
    HuffmanCodes(data, freqNonZero, j, codes);


    // Записываем сжатые данные в выходной файл
    writeEncodedDataToFile(outputFilename, buffer, size, codes);

    // Процесс декодирования
    struct MinHeapNode* root = buildHuffmanTree(data, freqNonZero, j);
    decodeFile(outputFilename, "decoded_output", root);

    // Освобождаем память
    free(buffer);
    for (int i = 0; i < MAX_TREE_HT; ++i) {
        if (codes[i])
            free(codes[i]);
    }

    return 0;
}

// gcc -o compress main.c gistogramm.c MinHeap_HuffmanTree.c decompress.c compress.c
// compress input.bmp output.txt
// compress input.txt output.txt






