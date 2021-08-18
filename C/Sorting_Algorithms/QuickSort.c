#include <stdio.h>
#include <stdlib.h>

/*
  The function quickSort has O(nlog(n)) time complexity, and doesn't create more
  variables or structures in memory, only change the reference for then.
*/
void quickSort(int length, int* v) {
  if (length > 1) {
    int a = 1, b = length - 1, x = v[0];
    
	while(1) {
		while(a < length && v[a] <= x) a++;
	    while(v[b] > x) b--;
	
	    if(a < b) {
	      int tmp = v[a];
	      v[a] = v[b];
	      v[b] = tmp;
	      a++; b--;
	    } else {
	      break;
	    }
	}
	
    v[0] = v[b];
    v[b] = x;
    
    quickSort(b, v);
    quickSort(length-a, &v[a]);
  }
}

int main() {
  int *v, length;

  do{
    printf("Type the size of your array: ");
    scanf("%d", &length);

    if(length <= 0) {
      printf("Please, type a valid number ( > 0 )\n");
    }
  }while(length <= 0);

  v = (int*) malloc(sizeof(int) * length);

  int i;
  for(i = 0; i < length; i++) {
    printf("%dº value of the array: ", i);
    scanf("%d", &v[i]);
  }

  quickSort(length, v);

  printf("\nSorted Algorithm\n");
  for(i = 0; i < length; i++) {
    printf("%d ", v[i]);
  }
  
  free(v);
  system("PAUSE");
  return 0;
}