//#define _CRT_SECURE_NO_WARNINGS
//#include "sol.h"
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Node {   // структура под вершины 
//    Edge* edges;        
//    int edgeCount;
//} Node;
//
//Node* graphNodes;  // массив под вершины где каждая вершина Node
//int verticesCount; // количество вершин
//
//void init() {
//    verticesCount = getVerticesCount();
//    graphNodes = (Node*)malloc(sizeof(Node) * verticesCount);
//
//    // Инициализация списка инцидентности для каждой вершины
//    for (int i = 0; i < verticesCount; i++) {
//        graphNodes[i].edges = NULL;
//        graphNodes[i].edgeCount = 0;
//    }
//
//    Edge e;
//    while (readEdge(&e)) {
//        // Добавление ребра к начальной вершине
//        graphNodes[e.from].edges = (Edge*)realloc(graphNodes[e.from].edges, (graphNodes[e.from].edgeCount + 1) * sizeof(Edge));
//        graphNodes[e.from].edges[graphNodes[e.from].edgeCount++] = e;
//
//        if (e.from != e.to) {
//            // Добавление ребра к конечной вершине, если это не петля
//            graphNodes[e.to].edges = (Edge*)realloc(graphNodes[e.to].edges, (graphNodes[e.to].edgeCount + 1) * sizeof(Edge));
//            Edge reversed = { e.to, e.from, e.weight }; // Поскольку граф неориентированный
//            graphNodes[e.to].edges[graphNodes[e.to].edgeCount++] = reversed;
//        }
//        else {
//            // если не п//етля добавляется дважды
//            graphNodes[e.from].edges = (Edge*)realloc(graphNodes[e.from].edges, (graphNodes[e.from].edgeCount + 1) * sizeof(Edge));
//            graphNodes[e.from].edges[graphNodes[e.from].edgeCount++] = e;
//        }
//    }
//}
//
//void destroy() {
//    for (int i = 0; i < verticesCount; i++) {
//        free(graphNodes[i].edges);
//    }
//    free(graphNodes);
//}
//
//int getEdgesCount(int iVertex) { // количество ребер для определенной вершины
//    if (iVertex >= 0 && iVertex < verticesCount) {
//        return graphNodes[iVertex].edgeCount;
//    }
//    return 0;
//}
//
//Edge getIncidentEdge(int iVertex, int iIndex) { // возвращает ребро, инцидентное выбранной вершине по заданному индексу.
//    if (iVertex >= 0 && iVertex < verticesCount && iIndex >= 0 && iIndex < graphNodes[iVertex].edgeCount) {
//        return graphNodes[iVertex].edges[iIndex];
//    }
//    Edge empty = { 0 };
//    return empty;
//}
//
//
//
//
// // gcc -c -fpic core.c     
// // gcc - shared - o core.so core.o
