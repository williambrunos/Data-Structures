#include <stdio.h>
#include <stdlib.h>

int main() {
  int x = 10;
  int *intPtr = &x;
  int **intPtrPtr = &intPtr;
  int ***intPtrPtrPtr = &intPtrPtr;

  printf("intPtrPtrPtr = %d \n", intPtrPtrPtr); // &intPtrPtr
  printf("*intPtrPtrPtr = %d \n", *intPtrPtrPtr); // &intPtr
  printf("**intPtrPtrPtr = %d \n", **intPtrPtrPtr); // &x
  printf("***intPtrPtrPtr = %d \n", ***intPtrPtrPtr); // x

  free(intPtr);
  free(intPtrPtr);
  free(intPtrPtrPtr);
  return 0;
}