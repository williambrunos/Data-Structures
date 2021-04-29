#include <stdio.h>
#include <stdlib.h>

int main() {
  int normalVariable = 12;
  int *pointer;

  pointer = &normalVariable;
  printf("Variable = %d\n", normalVariable);
  printf("Pointer = %d\n", *pointer);
  printf("Address hold by the pointer = %d\n", pointer);
  *pointer = 14;

  printf("Variable = %d\n", normalVariable);
  printf("Pointer = %d\n", *pointer);
  printf("Address hold by the pointer = %d\n", pointer);

  free(pointer);
  return 0;
}