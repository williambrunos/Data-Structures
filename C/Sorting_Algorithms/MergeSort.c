#include <stdio.h>
#include <stdlib.h>

// Parte de intercalação, de junção dos valores dos subarrays de forma ordenada em v
void mergeSort_intercala(int *v, int esq, int meio, int dir){
	int i, j, k;
	int a_tam = meio-esq+1;
	int b_tam = dir-meio;
	
	int *a = (int*) malloc(sizeof(int) * a_tam);
	int *b = (int*) malloc(sizeof(int) * b_tam);
	
	for (i = 0; i < a_tam; i++) a[i] = v[i+esq];
	for (i = 0; i < b_tam; i++) b[i] = v[i+meio+1];
	
	for (i = 0, j = 0, k = esq; k <= dir; k++) {
		if (i == a_tam) v[k] = b[j++];
		else if (j == b_tam) v[k] = a[i++];
		else if (a[i] < b[j]) v[k] = a[i++];
		else v[k] = b[j++];
	}
	free(a); free(b);
}

// Separação recursiva do array v pela metade
void mergeSort_ordena(int *v, int esq, int dir) {
	if (esq == dir)
		return;
		
	int meio = (esq + dir) / 2;
	
	mergeSort_ordena(v, esq, meio);
	mergeSort_ordena(v, meio+1, dir);
	mergeSort_intercala(v, esq, meio, dir);
	
	return;
}

// Primeira chamada da função merge sort
void mergeSort(int *v, int n) {
	mergeSort_ordena(v, 0, n-1);
}

int main(int argc, char *argv[]) {
	int v[5] = {2, 5, 3, 1, 4};
	mergeSort(v, 5);
	
	int i;
	for(i = 0; i < 5; i++) {
		printf("v[%d] = %d\n", i, v[i]);
	}
	
	return 0;
}