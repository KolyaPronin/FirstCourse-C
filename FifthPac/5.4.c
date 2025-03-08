//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
// // вершины + ребра
//
//
//typedef struct node {
//    int data;
//    struct node* next;
//} Node;
//
//Node* init(int vert) {
//    Node* new_node = (Node*)malloc(sizeof(Node));
//    new_node->data = vert;
//    new_node->next = NULL;
//    return new_node;
//}
//
//int DFS(int v, Node** graph, int* visited, int* values, int* counter) {
//    visited[v] = 1; // в процессе посещения
//    Node* temp = graph[v];
//
//    while (temp != NULL) {
//        if (visited[temp->data] == 0) {
//            // если вершина не посещена, продолжаем обход
//            int result = DFS(temp->data, graph, visited, values, counter);
//            if (!result) {
//                return 0; // нашли цикл во время обхода
//            }
//        }
//        else if (visited[temp->data] == 1) {
//            // нашли обратное ребро - значит цикл!
//            return 0;
//        }
//        temp = temp->next;
//    }
//
//    visited[v] = 2; // завершили обработку вершины, помечаем как "полностью обработанную"
//    values[v] = (*counter)--; // присваиваем значения обратно переходящих ребер
//    return 1; // возвращаем значение 1
//}
//
//int main() {
//    int n, m, i, u, v;
//    scanf("%d %d", &n, &m);
//
//    Node** graph = (Node**)malloc((n + 1) * sizeof(Node*));
//    for (i = 0; i <= n; i++) {
//        graph[i] = NULL;
//    }
//
//    int* visited = (int*)calloc(n + 1, sizeof(int));
//    int* values = (int*)malloc((n + 1) * sizeof(int));
//
//    for (i = 1; i <= n; i++) {
//        values[i] = -1;
//    }
//
//    for (i = 0; i < m; i++) {
//        scanf("%d %d", &u, &v);
//        Node* node = init(v);
//        node->next = graph[u];
//        graph[u] = node;
//    }
//
//    int counter = n; // Изменяем начальное значение счетчика
//
//    for (i = n; i >= 0; i--) {
//        if (visited[i] == 0) {
//            if (!DFS(i, graph, visited, values, &counter)) {
//                printf("NO\n");
//
//                for (i = 0; i <= n; i++) {
//                    Node* temp = graph[i];
//                    while (temp != NULL) {
//                        Node* prev = temp;
//                        temp = temp->next;
//                        free(prev);
//                    }
//                }
//                free(graph);
//                free(visited);
//                free(values);
//                return 0;
//            }
//        }
//    }
//	
//    printf("YES\n");
//    for (i = 1; i <= n; i++) {
//        printf("%d ", values[i]);
//    }
//    printf("\n");
//
//    for (i = 0; i <= n; i++) {
//        Node* temp = graph[i];
//        while (temp != NULL) {
//            Node* prev = temp;
//            temp = temp->next;
//            free(prev);
//        }
//    }
//    free(graph);
//    free(visited);
//    free(values);
//
//    return 0;
//}