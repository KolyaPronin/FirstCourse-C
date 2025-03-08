//#define _CRT_SECURE_NO_WARNINGS
//#pragma comment ( linker , "/STACK:50000000")
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h> 
//
//int position = 0;
//
//char* reading_token(char* text, char* token){
//
//    for (;text[position] == ' ';) // если пробел, то пропускаем
//        position++;
//
//    if (text[position] == 0){   // если конец строки, то прекращаем обрабатывать токены :)
//         
//        strcpy(token, "");  
//        return token;
//    }
//
//    // какой это токен?
//    if (text[position] == '+' || text[position] == '-' || text[position] == '*' || text[position] == '/' || text[position] == '(' || text[position] == ')'){
//
//        token[0] = text[position++]; // если символ один из шести то он копируется в токен и возвращается
//        token[1] = 0;
//        return token;
//    }
//
//    int left = position; 
//    for (;text[position] >= '0' && text[position] <= '9';) // но если символ является цифорой, то копируются все цыфоры
//        position++;
//    memcpy(token, text + left, position - left);
//    token[position - left] = 0;
//    return token;
//}
//
//char* watch_on_token(char* text, char* token){ // просматривает токен не изменяя текущего положения
//
//    int current_position = position; // запомним нашу позицию
//    reading_token(text, token); // посмотрим на следущую
//    position = current_position; // вернемся обратно
//    return token;
//} // **
//
//double Parse_Expression(char* text, char* token);
//
//double Parse_Primary_Expression(char* text, char* token) //которая разбирает первичное выражение 
//{ // это может быть число или выражение в скобках
//    if (watch_on_token(text, token)[0] == '-') { // унарный минус
//    
//     reading_token(text, token);
//     double res = Parse_Primary_Expression(text, token);
//     return -res;
//
//    }
//
//    else if (watch_on_token(text, token)[0] == '(') {            //выражение в скобках
//
//        reading_token(text, token);                              // первая скобка
//        double res = Parse_Expression(text, token);              // разбираем выражение с помощью рекурсии
//        reading_token(text, token);                              // вторая скобка
//        return res;
//    }
//    else
//        return atoi(reading_token(text, token));                 //целое число
//}
//
//
//double Parse_Term(char* text, char* token){ // разбирает на множители и делители
//
//    double res = Parse_Primary_Expression(text, token); // Получение первичного выражения 
//    for (; watch_on_token(text, token)[0] == '*' || watch_on_token(text, token)[0] == '/';) { // обрабатываем все знаки * и /
//
//        char operation = reading_token(text, token)[0];
//        double add = Parse_Primary_Expression(text, token);
//                                                         // для каждого * или / читается следущий элемент из строки и выполняется операция
//        (operation == '*') ? (res *= add) : (res /= add);
//
//    }
//    return res;
//}
//
//double Parse_Expression(char* text, char* token) { //разбирает арифметическое выражение
//    double res = Parse_Term(text, token);
//    for (; watch_on_token(text, token)[0] == '+' || watch_on_token(text, token)[0] == '-';) { //обрабатываем все знаки + и -
//        char operation = reading_token(text, token)[0];
//        double add = Parse_Term(text, token);
//                                                          // для каждого + или - читается следущий элемент из строки и выполняется операция
//        (operation == '+') ? (res += add) : (res -= add);
//
//    }
//    return res;
//}
//
//
//int main(){
//
//    FILE* inputFile = fopen("input.txt", "r");
//	FILE* outputFile = fopen("output.txt", "w");
//
//    char* text = (char*)malloc(1500000 * sizeof(char));
//    char token[5];
//    position = 0;
//
//    int i = 0;
//    for(;fscanf(inputFile,"%c", &text[i]) > 0;)
//        i++;
//    
//
//    double res = Parse_Expression(text, token);
//    fprintf(outputFile,"%0.20lf", res);
//
//    free(text);
//    fclose(inputFile);
//    fclose(outputFile);
//    return 0;
//}
//
//
//
////** watch_on_token используется для проверки следующего токена, чтобы определить,
////  начинается ли текущее выражение с унарного минуса или открывающей скобки.
////  Это необходимо для правильной интерпретации выражений и определения, какой путь
////  выполнения программы следует выбрать.