//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//int main() {
//
//    FILE* input_file = fopen("input.txt", "r");
//    FILE* output_file = fopen("output.txt", "w");
//    
//
//    char str[100];
//    int j = 0;
//    while (1) {
//        if (fscanf(input_file, "%c", &str[j]) == EOF || str[j] == '\n') {
//            break;
//        }
//        j++;
//    }
//    str[j] = '\0'; // Добавляем завершающий нуль-символ
//
//    j = 0;
//    while (str[j] != '\0') {
//        if (str[j] == '"') {
//            fprintf(output_file, "[");
//            int k = j + 1; // пропустили [
//            while (str[k] != '"' && str[k] != '\0') {
//                fprintf(output_file, "%c", str[k]);
//                k++;
//            }
//            fprintf(output_file, "]\n");
//            j = k + 1; // пропустили ] 
//        }
//        else if (str[j] == ' ') { // пропустили пробелы
//            j++;
//        }
//        else {   // аналогично если без кавычек
//            fprintf(output_file, "[");
//            while (str[j] != ' ' && str[j] != '\0') {
//                fprintf(output_file, "%c", str[j]);
//                j++;
//            }
//            fprintf(output_file, "]\n");
//        }
//    }
//
//    fclose(input_file);
//    fclose(output_file);
//
//    return 0;
//}
//
//
//
