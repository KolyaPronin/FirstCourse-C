//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//  // куб
//
//void floyd_warshall(int N, int** dist, int** next) {
//	for (int i = 0; i < N; ++i) {
//		for (int j = 0; j < N; ++j) {
//			next[i][j] = j; // Инициализируем предыдущую вершину как j
//		}
//	}
//
//	for (int k = 0; k < N; ++k) {
//		for (int i = 0; i < N; ++i) {
//			for (int j = 0; j < N; ++j) {
//				if (dist[i][j] > dist[i][k] + dist[k][j]) { // если маршрут через k короче 
//					dist[i][j] = dist[i][k] + dist[k][j];
//					next[i][j] = next[i][k]; // Обновляем предыдущую вершину для j
//				}
//			}
//		}
//	}
//}
//int main() {
//
//
//	int N, M, P, K;
//	scanf("%d %d %d %d", &N, &M, &P, &K);
//
//
//	int** distance = (int**)malloc(N * sizeof(int*));
//	for (int i = 0; i < N; ++i) {
//		distance[i] = (int*)malloc(N * sizeof(int));
//		for (int j = 0; j < N; ++j) {
//			distance[i][j] = (i == j) ? 0 : 1e9; // Используем INF = 1e9 для обозначения бесконечности
//		}
//	}
//
//	for (int i = 0; i < M; i++) {
//		int point_1, point_2, time; // дороги дороги 
//		scanf("%d%d%d", &point_1, &point_2, &time);
//		distance[point_1 - 1][point_2 - 1] = time;
//		distance[point_2 - 1][point_1 - 1] = time;
//	}
//
//	int** next = (int**)malloc(N * sizeof(int*));
//	for (int i = 0; i < N; ++i) {
//		next[i] = (int*)malloc(N * sizeof(int));  // матрица next хранит кратчайшие пути.
//	}
//
//	floyd_warshall(N, distance, next);
//	int count;
//	for (int i = 0; i < P; i++) { 
//		int from, to;
//		scanf("%d %d", &from, &to);
//
//		// Сначала посчитаем количество вершин в пути
//		int cur = from - 1;
//		count = 1; // Сбрасываем счетчик перед каждым запросом
//		while (cur != to - 1) {
//			cur = next[cur][to - 1];
//			count++;
//		}
//
//		// Теперь печатаем время и количество вершин
//		printf("%d %d ", distance[from - 1][to - 1], count);
//
//		// Затем печатаем сами вершины
//		cur = from - 1;
//		printf("%d ", from); // Сначала пункт отправления
//		while (cur != to - 1) {
//			printf("%d ", next[cur][to - 1] + 1);
//			cur = next[cur][to - 1];
//		}
//		printf("\n"); 
//	}
//	for (int i = 0; i < K; i++) { // просто время  +вайб
//		int from, to;
//		scanf("%d %d", &from, &to);
//		printf("%d\n", distance[from - 1][to - 1]);
//	}
//
//
//	for (int i = 0; i < N; i++) {
//		free(distance[i]);
//	}
//
//
//	return 0;
//}