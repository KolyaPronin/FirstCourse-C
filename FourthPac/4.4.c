//	#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct State {
//    char* regs[256];
//} State;
//State state;
//void echo_0(State* state) {
//    (void)state; // state не используется
//    printf("ECHO:\n");
//}
//
//void echo_1(State* state, char* arg0) {
//    (void)state; // state не используется
//    printf("ECHO: %s\n", arg0);
//}
//
//void echo_2(State* state, char* arg0, char* arg1) {
//    (void)state; // state не используется
//    printf("ECHO: %s|%s\n", arg0, arg1);
//}
//
//void echo_3(State* state, char* arg0, char* arg1, char* arg2) {
//    (void)state; // state не используется
//    printf("ECHO: %s|%s|%s\n", arg0, arg1, arg2);
//}
//
//void print_1(State* state, char* idx) {
//    int i = atoi(idx);
//    if (i < 0 || i >= 256 || state->regs[i] == NULL) {
//        printf("[ERROR] Invalid index or NULL register.\n");
//        return;
//    }
//    // Здесь выводим просто значение без индекса и равно
//    printf("%s\n", state->regs[i]);
//}
//
//void printregs_0(State* state) { // Печатает все ненулевые регистры и их значения, сортированные по номеру регистра.
//    for (int i = 0; i < 256; ++i) {
//        if (state->regs[i] != NULL) {
//            printf("%d = %s\n", i, state->regs[i]);
//        }
//    }
//}
//
//void store_2(State* state, char* idx, char* what) {    // Сохраняет копию строки what в регистр с индексом, преобразованным из строки idx. 
//    int i = atoi(idx);								//	При этом освобождает память предыдущего значения,
//    if (i < 0 || i >= 256) {                         //  если таковое было, и выделяет новую память под строку what.
//        printf("[ERROR] Invalid index.\n");
//        return;
//    }
//    free(state->regs[i]);
//    size_t len = strlen(what) + 1;
//    state->regs[i] = (char*)malloc(len);
//    if (state->regs[i] == NULL) {
//        printf("[ERROR] Out of memory.\n");
//        return;
//    }
//    memcpy(state->regs[i], what, len);
//}
//
//void copy_2(State* state, char* dst, char* src) { //Копирует содержимое регистра с индексом src в регистр с индексом dst. 
//    int d = atoi(dst);                           // Если регистры различаются, удаляется старое значение регистра dst,
//    int s = atoi(src);                          // и в него копируется новое значение из регистра src.
//    if (s < 0 || s >= 256 || d < 0 || d >= 256 || state->regs[s] == NULL) {
//        printf("[ERROR] Invalid indices or NULL source register.\n");
//        return;
//    }
//    if (d != s) {
//        free(state->regs[d]);
//        size_t len = strlen(state->regs[s]) + 1;
//        state->regs[d] = (char*)malloc(len);
//        if (state->regs[d] == NULL) {
//            state->regs[d] = NULL;
//            printf("[ERROR] Out of memory.\n");
//            return;
//        }
//        memcpy(state->regs[d], state->regs[s], len);
//    }
//}
//
//
//
//void clear_1(State* state, char* idx) { // Присваивает NULL регистру с индексом, полученным из строки idx, 
//                                         // что обозначает очистку данного регистра.
//    int i = atoi(idx);
//    if (i < 0 || i >= 256) {
//        printf("[ERROR] Invalid index.\n");
//        return;
//    }
//    free(state->regs[i]);
//    state->regs[i] = NULL;
//}
//
//int main() {
//    echo_2(&state, " hello", " world");
//    echo_0(&state);
//    echo_1(&state, "the_only_argument");
//    echo_3(&state, "a", "b", "c");
//    store_2(&state, "13", "thirteen");
//    store_2(&state, "10", "ten");
//    store_2(&state, "15", "fifteen");
//    store_2(&state, "20", "twelve");
//    echo_1(&state, "==state==");
//    printregs_0(&state);
//    echo_1(&state, "==copying==");
//    print_1(&state, "13");
//    print_1(&state, "15");
//    copy_2(&state, "13", "15");
//    print_1(&state, "13");
//    print_1(&state, "15");
//    echo_1(&state, "==clear==");
//    clear_1(&state, "10");
//    clear_1(&state, "15");
//    store_2(&state, "13", "thirteen_v2");
//    printregs_0(&state);
//}
