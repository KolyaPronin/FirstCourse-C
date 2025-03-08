//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//// ну чистая чепуха!
//
//double Proizvodnya(double c1, double c2, double c3, double t, double l) {
//    return c1 + 2 * c2 * (t - l) + 3 * c3 * (t - l) * (t - l);
//}
//
//
//int main() {
//
//    int N;
//    scanf("%d", &N);
//
//    // чтение спанов
//    double total_length = 0;
//    double h = 0;
//    for (int i = 0; i < N; i++) {
//        double l, r;
//        scanf("%lf %lf", &l, &r); // границы спанов
//        // читаем коэфиценты c0 c1 c2 c3 координатных функций x y z 
//        double x_c0, x_c1, x_c2, x_c3; // коэфиценты для функции x(t)
//        double y_c0, y_c1, y_c2, y_c3; // коэфиценты для функции y(t)
//        double z_c0, z_c1, z_c2, z_c3; // коэфиценты для функции z(t)
//
//
//        scanf("%lf %lf %lf %lf", &x_c0, &x_c1, &x_c2, &x_c3);
//
//
//        scanf("%lf %lf %lf %lf", &y_c0, &y_c1, &y_c2, &y_c3);
//
//
//        scanf("%lf %lf %lf %lf", &z_c0, &z_c1, &z_c2, &z_c3);
//        int n = 1000; // количество точек для численного интегрирования
//        double length = 0.0;
//        int flag = 0;
//
//        h = (r - l) / n;
//        for (int j = 0; j <= n; j++) {
//
//            double t1 = l + j * h;
//
//
//            double x1 = Proizvodnya(x_c1, x_c2, x_c3, t1, l);
//
//            double y1 = Proizvodnya(y_c1, y_c2, y_c3, t1, l);
//
//            double z1 = Proizvodnya(z_c1, z_c2, z_c3, t1, l);
//
//            if (j == 0) {
//                length += (sqrt(x1 * x1 + y1 * y1 + z1 * z1));
//                continue;
//            }
//
//            else if (j == n) {
//                length += (sqrt(x1 * x1 + y1 * y1 + z1 * z1));
//                break;
//            }
//
//            else if (flag == 1) {
//                length += 2 * sqrt(x1 * x1 + y1 * y1 + z1 * z1);
//                flag--;
//            }
//            else {
//                length += 4 * sqrt(x1 * x1 + y1 * y1 + z1 * z1);
//                flag++;
//            }
//
//        }
//
//        total_length += length * (h / 3);
//    }
//    printf("%.15lf\n", total_length);
//}
// // да есть же
// // Коля голова O_o 