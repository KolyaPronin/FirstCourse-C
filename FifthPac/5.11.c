//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_VERTICES 100001
//
//typedef struct Node {
//    int vertex;
//    struct Node* next;
//} Node;
//
//Node* graph[MAX_VERTICES];
//int visited[MAX_VERTICES], first_visit[MAX_VERTICES], min_visit_time[MAX_VERTICES]; // хранят времена первого посещения и минимального времени посещения.
//int is_articulation_point[MAX_VERTICES]; // указывает, является ли вершина точкой сочленения.
//int timer;
//
//// Функция для добавления ребра в граф
//void addEdge(int start, int end) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    newNode->vertex = end;
//    newNode->next = graph[start];
//    graph[start] = newNode;
//}
//
//// Обход в глубину с нахождением точек сочленения
//void DFS(int v, int p) {
//    visited[v] = 1;
//    first_visit[v] = min_visit_time[v] = timer++;
//    int children = 0;
//    for (Node* node = graph[v]; node != NULL; node = node->next) {
//        int to = node->vertex;
//        if (to == p)  continue;
//        if (visited[to]) {
//            if (min_visit_time[v] > first_visit[to]) {  Проверяет, не проходила ли посещённая уже вершина через текущую, в таком случае обновляется min_visit_time.
//                min_visit_time[v] = first_visit[to];
//            }
//        }
//        else { // Осуществляет рекурсивный обход для непосещённых вершин и после возврата из рекурсии проверяет,
//            DFS(to, v); //  можно ли обновить min_visit_time, и является ли текущая вершина точкой сочленения.
//            if (min_visit_time[v] > min_visit_time[to]) {
//                min_visit_time[v] = min_visit_time[to];
//            }
//            if (min_visit_time[to] >= first_visit[v] && p != -1)
//                is_articulation_point[v] = 1;
//            children++;
//        }
//    }
//    if (p == -1 && children > 1) //**
//        is_articulation_point[v] = 1;
//}
//
//int main() {
//    int n, m;
//    scanf("%d %d", &n, &m);
//    for (int i = 0; i < m; i++) {
//        int u, v;
//        scanf("%d %d", &u, &v);
//        addEdge(u, v);
//        addEdge(v, u); // Неориентированный граф, добавляем обе стороны
//    }
//
//    timer = 0;
//    for (int i = 1; i <= n; i++)
//        visited[i] = first_visit[i] = min_visit_time[i] = is_articulation_point[i] = 0;
//
//    for (int i = 1; i <= n; i++)
//        if (!visited[i])
//            DFS(i, -1);
//
//    int count = 0;
//    for (int i = 1; i <= n; i++)
//        count += is_articulation_point[i];
//
//    printf("%d\n", count); // количество точек сочленения
//    for (int i = 1; i <= n; i++)
//        if (is_articulation_point[i])
//            printf("%d ", i); // Выводим номера вершин
//
//    return 0;
//}
//									// **
//									// Точки сочленения: это вершины, удаление которых увеличивает количество связных компонент графа.
//									// Алгоритм помечает вершину как точку сочленения, если выполняется одно из следующих условий:
//									// Для корневой вершины : если у нее более одного ребенка в DFS дереве.
//									//  Для некорневой вершины : если существует прилегающая вершина to, такая что min_visit_time[to] >= first_visit[v].