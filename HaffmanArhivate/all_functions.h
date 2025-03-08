#ifndef HUFFMAN_H
#define HUFFMAN_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "min_heap.h"
#define MAX_TREE_HT 256


void calculateFrequencies(const char* filename, unsigned char** buffer, int* freq, long* size);
void encodeData(unsigned char* buffer, long size, char** codes, FILE* output);
void writeEncodedDataToFile(const char* filename, unsigned char* buffer, long size, char** codes);
void decodeData(MinHeapNode* root, FILE* input, FILE* output);
void decodeFile(const char* encodedFilename, const char* outputFilename, MinHeapNode* root);

#endif 

