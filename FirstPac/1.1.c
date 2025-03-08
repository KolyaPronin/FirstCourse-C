//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//int main(int argc,char** argv) {
//
//	if (argc == 1) {
//		fprintf(stderr, "No parameters specified.\n");
//		return 13;
//	}
//
//	if (argc == 4) {  // если без модуля
//		if (strcmp(argv[1], "add") == 0) {
//			int result = atoi(argv[2]) + atoi(argv[3]);
//			printf("%d\n", result);
//		}
//		else if (strcmp(argv[1], "sub") == 0) {
//			int result = atoi(argv[2]) - atoi(argv[3]);
//			printf("%d\n", result);
//		}
//		else if (strcmp(argv[1], "mul") == 0) {
//			long long result = (long long)atoi(argv[2]) * atoi(argv[3]);
//			printf("%lld\n", result);
//
//		}
//	}
//
//	else if (argc == 6) { // если с модулем
//		if (strcmp(argv[1], "-m") == 0) {  // если он в начале 
//			if (strcmp(argv[3], "add") == 0) {
//				int result = (atoi(argv[4]) + atoi(argv[5])) % atoi(argv[2]);
//				while (result < 0) {
//					result += atoi(argv[2]);
//				}    
//				printf("%d\n", result);
//			}
//			else if (strcmp(argv[3], "sub") == 0) {
//				int result = (atoi(argv[4]) - atoi(argv[5])) % atoi(argv[2]);
//				while (result < 0) {
//					result += atoi(argv[2]);
//				}
//				printf("%d\n", result);
//			}
//			else if (strcmp(argv[3], "mul") == 0) {
//				long long result = (((long long)atoi(argv[4]) * atoi(argv[5])) % atoi(argv[2]) + atoi(argv[2])) % atoi(argv[2]);
//				
//				printf("%lld\n", result);
//
//			}
//		}
//
//		else {  // если он в конце 
//			if (strcmp(argv[1], "add") == 0) {
//				int result = (atoi(argv[2]) + atoi(argv[3])) % atoi(argv[5]);
//				while (result < 0) {
//					result += atoi(argv[5]);
//				}
//				printf("%d\n", result);
//			}
//			else if (strcmp(argv[1], "sub") == 0) {
//				int result = (atoi(argv[2]) - atoi(argv[3])) % atoi(argv[5]);	
//				while (result < 0) {
//					result += atoi(argv[5]);
//				}
//				printf("%d\n", result);
//			}
//			else if (strcmp(argv[1], "mul") == 0) {
//				long long result = (((long long)atoi(argv[2]) * atoi(argv[3])) % atoi(argv[5]) + atoi(argv[5])) % atoi(argv[5]);
//				printf("%lld\n", result);
//
//			}
//		}
//	}
//	   
//	
//	
//	return 0;
//
//}
////
////
//// 
//// // //  gcc C:\Users\kolya\source\repos\Project2\1pac\1.1.c -o app
////// //   app
////// //   app mul 1000000000 17345
////// //   app sub 135 1793846 -m 100 
