//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
////КСС
// // вершины + ребра
//
//#define MAX_N 100001
//
//int N, M;
//int stack[MAX_N], st_top = 0;
//int visited[MAX_N], component[MAX_N];
//int components_count = 0;
//
//// Структура для списка смежности
//typedef struct Node {
//    int vertex;
//    struct Node* next;
//} Node;
//
//Node* graph[MAX_N], * transposed_graph[MAX_N];
//
//// Добавление ребра в граф
//void add_edge(Node* graph[], int from, int to) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    newNode->vertex = to;
//    newNode->next = graph[from];
//    graph[from] = newNode;
//}
//
//// ДФС для оригинального графа
//void dfs(int v) {
//    visited[v] = 1;
//    for (Node* node = graph[v]; node != NULL; node = node->next) {
//        if (!visited[node->vertex])
//            dfs(node->vertex);
//    }
//    stack[st_top++] = v; // Запоминаем порядок выхода из рекурсии  dfs
//}
//
//// Обратный ДФС для транспонированного графа
//void dfs_2(int v) { 
//    visited[v] = 1;
//    component[v] = components_count;
//    for (Node* node = transposed_graph[v]; node != NULL; node = node->next) {
//        if (!visited[node->vertex])
//            dfs_2(node->vertex);
//    }
//}
//// берется вершина из верхушки стека, и если она не посещена, 
//// начинается новый обход в глубину. Каждый такой обход находит 
//// все вершины в сильно связной компоненте и помечает их как принадлежащие одной компоненте.
// 
//void memory_free() {
//    for (int i = 0; i <= N; ++i) {
//        Node* node = graph[i];
//        while (node != NULL) {
//            Node* temp = node;
//            node = node->next;
//            free(temp);
//        }
//        graph[i] = NULL;
//        node = transposed_graph[i];
//        while (node != NULL) {
//            Node* temp = node;
//            node = node->next;
//            free(temp);
//        }
//        transposed_graph[i] = NULL;
//    }
//}
//
//int main() {
//    scanf("%d %d", &N, &M);
//    int from, to;
//    // Чтение графа
//    for (int i = 0; i < M; ++i) {
//        scanf("%d %d", &from, &to);
//        add_edge(graph, from, to);
//        add_edge(transposed_graph, to, from); // Добавление в транспонированный граф
//    }
//
//    // Начальный ДФС для вычисления порядка выхода
//    for (int i = 1; i <= N; ++i)
//        if (!visited[i]) dfs(i);
//
//    // Очищаем массив посещений для обратного ДФС
//    for (int i = 1; i <= N; ++i) visited[i] = 0;
//
//    // Обратный ДФС
//    for (int i = st_top - 1; i >= 0; --i)
//        if (!visited[stack[i]]) {
//            ++components_count;
//            dfs_2(stack[i]);
//        }
//
//    // Вывод количества компонент и принадлежность вершин к ним
//    printf("%d\n", components_count);
//    for (int i = 1; i <= N; i++) {
//        printf("%d ", component[i]);
//    }
//    printf("\n");
//
//    memory_free();
//    return 0;
//}
//
//1. Первый проход ДФС по исходному графу: начинаем обход из какой-то вершины и пытаемся дойти до всех возможных вершин.
//  По мере завершения обработки каждой вершины в первом проходе ДФС, вершины помещаются в стек. Это означает, что вершина,
//  которая была обработана позже, окажется выше в стеке (таким образом, вершины, которые не имеют исходящих ребер или имеют исходящие ребра 
// только в уже посещенные вершины, располагаются выше в стеке).

//2. Обработка транспонированного графа : транспонированный граф содержит те же вершины, что и исходный граф,
// 
//  но все направления ребер в нем обратные.Теперь, начиная с верхнего элемента стека(последняя посещенная вершина из первого прохода ДФС), 
// выполняется второй проход ДФС, но уже на транспонированном графе.

// Если при втором проходе мы сможем посетить некую вершину, не посещенную в первом проходе, то это означает, 
// что мы нашли путь по обратным ребрам(поскольку теперь ребра направлены в обратную сторону).
// Это указывает на наличие сильной связи между вершиной на вершине стека и вершиной, которую мы посетили во втором проходе.
// Все вершины, посещенные во время одного второго прохода ДФС до первого повторного посещения, образуют сильную связную компоненту.
//
//
//
//
