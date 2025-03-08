//#include <stdio.h>
//
//double Function(double x);
//
//double Proizvodnaya(double x, double step) {
//    if (x + step < 0.0 || x + step > 1.0) { // если выходит за границы
//        return (Function(x) - Function(x - step)) / step; // то вычисляется приближенное значение производной справа
//    }
//    else if (x - step < 0.0 || x - step > 1.0) { //если выходит за границы
//        return (Function(x + step) - Function(x)) / step; // // то вычисляется приближенное значение производной слева
//    }
//    else {
//        return (Function(x + step) - Function(x - step)) / (2 * step); // иначе центральное
//    }
//}
//
//int main() {
//    
//    FILE* inputFile = fopen("input.txt", "r");
//    FILE* outputFile = fopen("output.txt", "w");
//    int M;
//    fscanf(inputFile, "%d", &M);
//    double x;
//    for (int i = 0; i < M; i++) {
//        fscanf(inputFile, "%lf", &x);
//        double proizvod = Proizvodnaya(x, 0.0000003);
//        fprintf(outputFile, "%lf\n", proizvod);
//    }
//    fclose(inputFile);
//    fclose(outputFile);
//    return 0;
//}
//определение производной в точке x выражается как предел,
//  к которому стремится отношение приращения функции к приращению аргумента, 
// когда последнее стремится к нулю