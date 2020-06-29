#include<stdio.h>
#include<stdlib.h>

//callback
//
void populate_array(int *array, size_t arraySize, int (*getNextValue)(void)) {
   for(size_t i = 0; i < arraySize; i++) {
      array[i] = getNextValue();
   }
}

int getNextRandomValue(void) {
    return random();
}


int main(void) {
   int myArray[10] = {0};
//   populate_array(myArray, 10, getNextRandomValue);
   for(int i = 0; i < 10; i++) {
      printf("%d ", myArray[i]);
   }
   printf("\n");
   return 0;
}
