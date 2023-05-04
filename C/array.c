#include <stdio.h>

int main(){
   int LA[3], i;
   printf("Array Before Insertion:\n");
   for(i = 0; i < 3; i++)
      printf("LA[%d] = %d \n", i, LA[i]);
   printf("Inserting Elements.. ");
   printf("The array elements after insertion :\n"); // prints array values
   for(i = 0; i < 3; i++) {
      LA[i] = i + 2;
      printf("LA[%d] = %d \n", i, LA[i]);
   }
   return 0;
}