//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//   // вершины * вершины + ребра
//typedef struct {
//    int to;
//    int next;
//} Edge;
//
//int* head, idx;
//Edge* edge;
//
//void add_edge(int u, int v) { // добавляет ребро в граф. 
//    edge[++idx].next = head[u];
//    edge[idx].to = v;
//    head[u] = idx;
//}
//
//int* stack, * onStack, * visited, stackSize;
//int* cycle, cycleSize;
//
//void add_cycle(int v) {		// Когда обнаруживается цикл, эта функция добавляет все вершины цикла в массив cycle 
//    cycle[cycleSize++] = v;  // и переставляет элементы, чтобы цикл начинался и заканчивался одной и той же вершиной.
//    int cur = stack[stackSize - 1];
//    while (cur != v) {
//        cycle[cycleSize++] = cur;
//        cur = stack[--stackSize - 1];
//    }
//    for (int i = 0; i < cycleSize / 2; ++i) {
//        int temp = cycle[i];
//        cycle[i] = cycle[cycleSize - 1 - i];
//        cycle[cycleSize - 1 - i] = temp;
//    }
//}
//
//int DFS(int v) { // ищем цикл, если нашли то вызываем функцию add_cycle
//    onStack[v] = visited[v] = 1;
//    stack[stackSize++] = v;
//    for (int i = head[v]; i; i = edge[i].next) {
//        int u = edge[i].to;
//        if (visited[u] && onStack[u]) {
//            add_cycle(u);
//            return 1;
//        }
//        else if (!visited[u]) {
//            if (DFS(u)) return 1;
//        }
//    }
//    --stackSize;
//    onStack[v] = 0;
//    return 0;
//}
//
//int main() {
//    int n, m;
//    scanf("%d %d", &n, &m);
//
//    head = (int*)calloc(n + 1, sizeof(int));
//    edge = (Edge*)malloc((m + 1) * sizeof(Edge));
//    stack = (int*)malloc((n + 1) * sizeof(int));
//    onStack = (int*)calloc(n + 1, sizeof(int));
//    visited = (int*)calloc(n + 1, sizeof(int));
//    cycle = (int*)malloc((n + 1) * sizeof(int));
//
//    int u, v;
//    for (int i = 0; i < m; ++i) {
//        scanf("%d %d", &u, &v);
//        add_edge(u, v);
//    }
//
//    for (int i = 1; i <= n; ++i) {
//        if (!visited[i] && DFS(i)) {
//            printf("%d\n", cycleSize);
//            for (int j = 0; j < cycleSize; ++j)
//                printf("%d ", cycle[j]);
//            printf("\n");
//            return 0;
//        }
//    }
//    printf("-1\n");
//
//    free(head);
//    free(edge);
//    free(stack);
//    free(onStack);
//    free(visited);
//    free(cycle);
//
//    return 0;
//}