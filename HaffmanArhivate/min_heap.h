#ifndef MINHEAP_H
#define MINHEAP_H

typedef struct MinHeapNode {
    unsigned char data;
    unsigned freq;
    struct MinHeapNode* left, * right;
}MinHeapNode;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
}MinHeap;



MinHeapNode* newNode(unsigned char data, unsigned freq);
MinHeap* createMinHeap(unsigned capacity);
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b);
void minHeapify(MinHeap* minHeap, int idx);
int isSizeOne(MinHeap* minHeap);
MinHeapNode* extractMin(MinHeap* minHeap);
void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode);
void buildMinHeap(MinHeap* minHeap);
int isLeaf(MinHeapNode* root);
MinHeap* createAndBuildMinHeap(unsigned char data[], int freq[], int size);
MinHeapNode* buildHuffmanTree(unsigned char data[], int freq[], int size);
void storeCodes(MinHeapNode* root, int arr[], int top, char** codes);
void HuffmanCodes(unsigned char data[], int freq[], int size, char** codes);


#endif 