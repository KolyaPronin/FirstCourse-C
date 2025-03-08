//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
// // строки * столбцы
//
//// Определение структуры узла связного списка
//typedef struct Node {
//    int x, y, dist;
//    struct Node* next;
//} Node;
//
//// Определение структуры очереди с указателями на начало и конец
//typedef struct {
//    Node* head, * tail;
//} Queue;
//
//
//void initQueue(Queue* q) {
//    q->head = q->tail = NULL;
//}
//
//int isEmpty(const Queue* q) {
//    return q->head == NULL;
//}
//
//// Функция для добавления элементов в очередь
//void enqueue(Queue* q, int x, int y, int dist) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//
//    newNode->x = x;
//    newNode->y = y;
//    newNode->dist = dist;
//    newNode->next = NULL;
//
//    if (isEmpty(q)) { // если очередь пуста то новый узел становится началом и концом очереди
//        q->head = q->tail = newNode;
//    }
//    else {
//        q->tail->next = newNode;
//        q->tail = newNode;
//    }
//}
//
//// Функция для удаления элементов из очереди
//Node dequeue(Queue* q) {
//    if (isEmpty(q)) exit(-1); // Очередь пуста
//
//    Node* temp = q->head;
//    Node result = *temp;
//    q->head = q->head->next;
//
//    if (q->head == NULL) {
//        q->tail = NULL;
//    }
//    free(temp);
//
//    return result;
//}
//
//void freeQueue(Queue* q) {
//    while (!isEmpty(q)) {
//        dequeue(q);
//    }
//}
//
//// Функция проверяет, можно ли перейти на клетку (x, y)
//int canMove(char** lab, int x, int y, int M, int N, int** visited) {
//    return x >= 0 && x < M && y >= 0 && y < N && lab[x][y] != 'X' && !visited[x][y];
//}
//
//// Функция BFS, использующая связный список для очереди
//int bfs(char** lab, int M, int N, int startX, int startY, int endX, int endY) {
//    // Инициализация посещенных клеток
//    int** visited = (int**)malloc(M * sizeof(int*));
//    for (int i = 0; i < M; ++i) {
//        visited[i] = (int*)calloc(N, sizeof(int));
//    }
//
//    Queue q;
//    initQueue(&q);
//    enqueue(&q, startX, startY, 0);
//    visited[startX][startY] = 1;
//
//    int dX[4] = { -1, 1, 0, 0 }; // Смещение по X для движения по направлениям
//    int dY[4] = { 0, 0, -1, 1 }; // Смещение по Y
//
//    while (!isEmpty(&q)) {
//        Node current = dequeue(&q);
//        if (current.x == endX && current.y == endY) { // если current конечная точка, то заканчиваем
//            // Освободим память
//            for (int i = 0; i < M; ++i) free(visited[i]);
//            free(visited);
//            freeQueue(&q);
//            return current.dist;
//        }
//
//        for (int i = 0; i < 4; ++i) {
//            int nextX = current.x + dX[i];
//            int nextY = current.y + dY[i];
//
//            if (canMove(lab, nextX, nextY, M, N, visited)) {
//                visited[nextX][nextY] = 1;    // если не стена и не посещена ранее то добавляем в очередь с увеличенным расстоянием
//                enqueue(&q, nextX, nextY, current.dist + 1);
//            }
//        }
//    }
//
//    // Освободим память
//    for (int i = 0; i < M; ++i) free(visited[i]);
//    free(visited);
//    freeQueue(&q);
//    return -1; // Путь не найден
//}
//
//// Основная функция считывает лабиринт и выводит результат
//int main() {
//    FILE* input = fopen("input.txt", "r");
//    FILE* output = fopen("output.txt", "w");
//
//    int M, N;
//    fscanf(input, "%d %d", &M, &N);
//
//    char** lab = (char**)malloc(M * sizeof(char*));
//    int startX, startY, endX, endY;
//
//    for (int i = 0; i < M; ++i) {
//        lab[i] = (char*)malloc(N + 1);
//        fscanf(input, "%s", lab[i]);
//        for (int j = 0; j < N; ++j) {
//            if (lab[i][j] == 'S') {
//                startX = i;
//                startY = j;
//            }
//            else if (lab[i][j] == 'F') {
//                endX = i;
//                endY = j;
//            }
//        }
//    }
//
//    int shortestPath = bfs(lab, M, N, startX, startY, endX, endY);
//    fprintf(output, "%d\n", shortestPath);
//
//    // Освобождение памяти
//    for (int i = 0; i < M; ++i) free(lab[i]);
//    free(lab);
//
//    fclose(input);
//    fclose(output);
//    return 0;
//}
//			