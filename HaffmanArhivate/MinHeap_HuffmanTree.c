#include "all_functions.h"


// Создаем новый узел кучи
MinHeapNode* newNode(unsigned char data, unsigned freq) {
    MinHeapNode* temp = (MinHeapNode*)malloc(sizeof(MinHeapNode)); // память для новго узла
    temp->left = temp->right = NULL; // левый и правый брат с null
    temp->data = data; // символ
    temp->freq = freq; // частта
    return temp; 
}

// Создаем кучу с заданной емкостью
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap; // возвращает указатель на созданную кучу
}

// Меняем местами два узла кучи
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Приводим кучу в правильное состояние
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) // Сравнивает частоты левого и правого потомков с частотой текущего узла и обновляет smallest.
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) { // Если smallest изменился, меняет местами узлы и рекурсивно вызывает minHeapify.
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Проверяем, что в куче остался один элемент
int isSizeOne(MinHeap* minHeap) { // Указатель на минимальную кучу.
    return (minHeap->size == 1); 
}

// Извлекаем минимальный элемент из кучи
MinHeapNode* extractMin(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap->array[0]; // Сохраняет корень кучи (минимальный элемент).
    minHeap->array[0] = minHeap->array[minHeap->size - 1]; // Перемещает последний элемент кучи на место корня.
    --minHeap->size; // Уменьшает размер кучи.
    minHeapify(minHeap, 0); // Восстанавливает свойство кучи, вызвав minHeapify.
    return temp;
}


// Вставляем новый узел в кучу
void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    ++minHeap->size; // размер кучи +1
    int i = minHeap->size - 1; // Инициализируем переменную i индексом последнего элемента кучи
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) { //  Сравниваем частоту вствляемого узла с частотой родительского узла
        minHeap->array[i] = minHeap->array[(i - 1) / 2]; // Если частота нового узла меньше, чем у родителя, перемещаем родительский узел вниз по куче на позицию i
        i = (i - 1) / 2; //  Обновляем индекс i до родительского узла (i - 1) / 2
    }
    minHeap->array[i] = minHeapNode; // Помещаем новый узел на свое место
}

// Строим кучу
void buildMinHeap(MinHeap* minHeap) {
    int n = minHeap->size - 1; // n как индекс последнег элемента в куче
    int i;
    for (i = (n - 1) / 2; i >= 0; --i) // начиная от последнего родительского элемента идем наверх и поддерживаем свойство куче
        minHeapify(minHeap, i);
}

// Проверяем, что узел является листом
int isLeaf(MinHeapNode* root) {
    return !(root->left) && !(root->right);// Функция возвращает 1  если  root не имеет ни левого, ни правого дочерних узлов
}

// Создаем и строим минимальную кучу
MinHeap* createAndBuildMinHeap(unsigned char data[], int freq[], int size) {
    MinHeap* minHeap = createMinHeap(size); // пустая куча
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]); // узлами заполняем
    minHeap->size = size; // Размер кучи устанавливается равным количеству элементов в массиве data
    buildMinHeap(minHeap);// строим кучу с условием минимальной кучи
    return minHeap;
}

// Строим дерево Хаффмана
MinHeapNode* buildHuffmanTree(unsigned char data[], int freq[], int size) {
    MinHeapNode* left, * right, * top;
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size); // создается и строится минимальная куча из символов и их частот

    while (!isSizeOne(minHeap)) { //  пока в куче не останется только один элемент
        left = extractMin(minHeap); // извлекаются два узла с минимальной частотой,
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);//  создается новый узел с суммой их частот, и этот новый узел вставляется обратно в кучу.
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}




// Сохраняем коды символов
void storeCodes(MinHeapNode* root, int arr[], int top, char** codes) { // Эта функция рекурсивно проходит по дереву Хаффмана, начиная с корня.
    // При каждом проходе она сохраняет путь до листов, где каждая ветвь соответствует биту (0 - влево, 1 - вправо).
    if (root->left) {
        arr[top] = 0;
        storeCodes(root->left, arr, top + 1, codes);
    }

    if (root->right) {
        arr[top] = 1;
        storeCodes(root->right, arr, top + 1, codes);
    }
    // когда доходит до узла без детей, функция сохраняет путь в коде для этого символа, используя массив arr. После этого код символа записывается в массив codes.
    if (isLeaf(root)) {
        codes[root->data] = (char*)malloc(top * sizeof(char));
        for (int i = 0; i < top; ++i) {
            codes[root->data][i] = arr[i] + '0'; // делаем из цифры символ
        }
        codes[root->data][top] = '\0';
    }
}

// Генерируем коды Хаффмана для символов
void HuffmanCodes(unsigned char data[], int freq[], int size, char** codes) {
    MinHeapNode* root = buildHuffmanTree(data, freq, size); //  построение дерева Хаффмана
    int arr[MAX_TREE_HT], top = 0;
    storeCodes(root, arr, top, codes); // сохраним коды символов
}










//////
//////              A[i] <= A[2 * i + 1]  // Левый дочерний узел
//////              A[i] <= A[2 * i + 2]  // Правый дочерний узел



