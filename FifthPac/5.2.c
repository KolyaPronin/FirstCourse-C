//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
// // ребра + вершины
//typedef struct node {
//	int data;
//	struct node* next;
//}node;
//
//typedef struct {
//	node* head;
//} List;
//
//List smejnosti_spissok[200000];
//int shortest_paths[200000];
//
//int queue[200000];
//int head = 0, tail = 0;
//
//void enqueue(int v) {
//	queue[tail++] = v;
//}
//int dequeue() {
//	return queue[head++];
//}
//int is_empty() {
//	return head == tail;
//}
//void add(int from, int to) {
//	node* new_node = (node*)malloc(sizeof(node));
//	new_node->data = to;
//	new_node->next = smejnosti_spissok[from].head;
//	smejnosti_spissok[from].head = new_node;
//}
//
//void BFS(List* adjacencyList, int start_vertex, int* shortest_paths, int V) {
//	for (int i = 0; i < V; ++i) {
//		shortest_paths[i] = -1;
//	}
//	shortest_paths[start_vertex] = 0;
//	enqueue(start_vertex);
//
//	while (!is_empty()) {
//		int current_vertex = dequeue();   // Пока очередь не пуста, из нее извлекается вершина (current_vertex), 
//		for (node* i = adjacencyList[current_vertex].head; i != NULL; i = i->next) { // и для каждой смежной вершины-соседа выполняются следующие действия:
//			int neighbour = i->data;											
//			if (shortest_paths[neighbour] == -1) {							   // Если для смежной вершины расстояние еще не найдено == -1,
//				shortest_paths[neighbour] = shortest_paths[current_vertex] + 1;	//то для нее устанавливается расстояние,на единицу большее,чем расстояние для текущей вершины.
//				enqueue(neighbour);											   // Смежная вершина добавляется в очередь для последующего обхода.
//			}
//		}
//	}					
//}
//
//
//int main() {
//
//	int N, M;
//	scanf("%d%d", &N, &M);
//
//	for (int i = 0; i < N; ++i) {
//		smejnosti_spissok[i].head = NULL;
//	}
//
//
//	for (int i = 0; i < M; i++) {
//		int u, v;
//		scanf("%d%d", &u, &v);
//		add(u - 1, v - 1); // Отнимаем 1 т.к. индексация с 1
//	}
//
//
//	BFS(smejnosti_spissok, 0, shortest_paths, N);
//
//
//	for (int i = 0; i < N; i++) {
//		if (i > 0)
//			printf("%d\n", shortest_paths[i]);
//		else
//			printf("0\n");
//	}
//	for (int i = 0; i < N; ++i) {
//		node* it = smejnosti_spissok[i].head;
//		while (it != NULL) {
//			node* to_free = it;
//			it = it->next;
//			free(to_free);
//		}
//	}
//
//	return 0;
//
//
//}