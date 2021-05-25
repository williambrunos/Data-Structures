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

  int *newPointer = (void*) 0x5DC;
  printf("Address hold by the pointer: %d\n", newPointer);

  // newPointer++; // Sum +4 because the type int weights 4bytes
  // printf("Address hold by the pointer: %d\n", newPointer);

  // The sum made in the pointer respects the type of the data pointed by the pointer
  int *p = (void*) 0x4CD; // 1229
  char *c = (void*) 0x4CD; // 1229
  printf("p = %d | c = %d \n", p, c);
  p++;
  c++;
  printf("p = %d | c = %d \n", p, c);

  free(pointer);
  free(newPointer);
  free(p);
  free(c);
  return 0;
}