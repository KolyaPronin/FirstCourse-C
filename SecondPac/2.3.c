//#include <stdio.h>
//
//int main() {
//#if defined(__GNUC__) && !defined(__llvm__) && !defined(__INTEL_COMPILER)
//    printf("Compiler: GCC\n");
//#elif defined(__clang__)
//    printf("Compiler: clang\n");
//#elif defined(__TINYC__)
//    printf("Compiler: TCC\n");
//#endif
//
//#if defined(__x86_64__) || defined(__ppc64__)
//    printf("Bitness: 64\n");
//#else
//    printf("Bitness: 32\n");
//#endif
//
//#ifdef NDEBUG // проверка включены ли  выключены ли assert
//    printf("Asserts: disabled\n");
//#else
//    printf("Asserts: enabled\n");
//#endif
//	
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
