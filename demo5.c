#include<stdio.h>

typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, int len) {
   int i;
   for(i = 0; i<len; i++) {
      printf(" %.2x", start[i]);
   }
   printf("\n");
}

int fun1(unsigned word) {
   return (int)((word << 24) >> 24);
}

int fun2(unsigned word) {
   return ((int) word << 24) >> 24;
}

float sum_elements(float a[], unsigned length) {
    int i;
    float result = 0;

    for(i = 0; i <= length - 1; i++) {
       printf("i=%d\n", i);
       printf("a[%d]=%f\n", i, a[i]);
       result += a[i];
    }
    return result;
}
int main() {
   unsigned int n = 0x87654321;
   int fun1r = fun1(n);
   int fun2r = fun2(n);
   show_bytes((byte_pointer) &fun1r, sizeof(unsigned int));
   show_bytes((byte_pointer) &fun2r, sizeof(unsigned int));

   float a[2] = {1.0, 2.0};
   printf("a length=%lu\n", sizeof(a)/sizeof(a[0]));
   sum_elements(a, 50);
   return 0;
}
