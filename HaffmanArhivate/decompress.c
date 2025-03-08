#include "all_functions.h"

void decodeData(struct MinHeapNode* root, FILE* input, FILE* output) {
    struct MinHeapNode* curr = root;
    int c;
    unsigned char byte;
    int bit_count;

    // Декодируем данные из файла
    while ((c = fgetc(input)) != EOF) { // Считывает байты из файла input
        byte = (unsigned char)c;
        bit_count = 8;

        // Обрабатываем каждый бит в байте
        while (bit_count--) {
            // перемещается по дереву влево, если бит равен 0, и вправо, если бит равен 1.
            if (byte & 0x80) { // если старший  бит в byte установлен в 1, результат будет отличен от нуля 
                curr = curr->right;
            }
            else { // если 0 то else
                curr = curr->left;
            }
            byte = byte << 1; // чтобы последовательно обрабатывать каждый бит в байте

            // Если достигли листа, записываем символ в выходной файл
            if (isLeaf(curr)) {
                fputc(curr->data, output);
                curr = root;
            }
        }
    }
}

void decodeFile(const char* encodedFilename, const char* outputFilename, struct MinHeapNode* root) {
    FILE* input = fopen(encodedFilename, "rb");
    FILE* output = fopen(outputFilename, "wb");

    // Декодируем данные
    decodeData(root, input, output);

    fclose(input);
    fclose(output);
}

