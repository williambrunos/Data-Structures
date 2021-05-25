#include <stdio.h>
#include <stdlib.h>

int main() {
  int array[5] = {1, 2, 3, 4, 5};
  int *pointer = array;
  int i;

  printf("Seen the data with the array: \n\n");
  for(i = 0; i < 5; i++) {
    printf("array[%d] = %d \n", i, array[i]);
  }

  printf("\nSeen the data with the pointer and *: \n\n");
  for(i = 0; i < 5; i++) {
    printf("array[%d] = %d \n", i, pointer[i]);
  }

  /// pointer -> address of the initial value from the array -> other values are
  /// get by arithmetic with pointers.
  printf("\nSeen the data with the initial address: \n\n");
  for(i = 0; i < 5; i++) {
    printf("array[%d] = %d \n", i, *(pointer+i));
  }

  return 0;
}