/* 

  1) Um ponteiro pode ser usado para dizer a uma função onde ela deve depositar o
  resultado de seus cálculos. Escreva uma função hm que converta minutos em horas-e-minutos. A função recebe um inteiro mnts e os endereços de duas 
  variáveis inteiras, digamos h e m, e atribui valores a essas variáveis de
  modo que m seja menor que 60 e que 60*h + m seja igual a mnts.
  Escreva também uma função main que use a função hm.

  2) Escreva uma função mm que receba um vetor inteiro v[0..n-1] e os endereços 
  de duas variáveis inteiras, digamos min e max, e deposite nessas variáveis o 
  valor de um elemento mínimo e o valor de um elemento máximo do vetor. Escreva 
  também uma função main que use a função mm.

*/

#include <stdio.h>
#include <stdlib.h>

void mm(int *array, int *min, int *max, int size) {
  int i;
  for(i = 0; i < size; i++) {
    if(array[i] < *min) {
      *min = array[i];
    } else if (array[i] > *max) {
      *max = array[i];
    }
  }

  free(array);
  free(min);
  free(max);
}

void hm(int *mnts, int *h, int *m) {
  *h = *mnts / 60;
  *m = *mnts % 60;

  free(mnts);
  free(h);
  free(m);
}

int main() {
  // Exercise 1
  int mnts = 184, hours, minutes;
  hm(&mnts, &hours, &minutes);
  printf("Hours = %d \n", hours);
  printf("Minutes = %d \n", minutes);

  // Exercise 2
  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int min = 0, max = 0;
  mm(array, &min, &max, 10);
  printf("Min = %d \n", min);
  printf("Max = %d \n", max);

  // Exercise 3
  char *a, *b;
  a = "abacate";
  b = "uva";

  if( *a < *b) {
    printf("%s vem antes de %s \n", a, b);
  }else {
    printf("%s vem antes de %s \n", b, a);
  }

  return 0;
}