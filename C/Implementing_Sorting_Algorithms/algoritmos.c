#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"

/* *v é o ponteiro para o array exterior e 'n' é o tamanho do vetor */
void bubble_sort(long *v, int n) {
	int i, j, temp;
	for(i=n-1; i>0; i--) {
		for(j=0; j<i; j++)
			if(v[j] > v[j+1]) {
				temp = v[j]; // Troca
				v[j] = v[j+1];
				v[j+1] = temp;
		}
	}
}

void bubble_sort_with_flag(long *v, int n) {
	int i, j;
	long temp, troca;
	for(i=n-1; i>0; i--){
		troca = 0;
		for(j=0; j<i; j++)
			if(v[j]> v[j+1]){
				temp = v[j]; // Troca
				v[j] = v[j+1];
				v[j+1] = temp;
				troca = 1;
			}
		if(troca==0)
			return;
	}
}

void insertion_sort(long *v, int n) {
	int k, j;
	long aux;

	for (k = 1; k <= n - 1; k++){
    	aux = v[k];
    	j = k - 1;
    	while (j >= 0 && aux < v[j]) {
        	v[j+1] = v[j];
        	j--;
      	}

      v[j+1] = aux;
   }
}

void quick_sort(long *v, long n) {
	if (n > 1) {
    	long a = 1, b = n - 1;
		long x = v[0];
    
		while(1) {
			while(a < n && v[a] <= x) a++;
	    	while(v[b] > x) b--;
	
	    	if(a < b) {
	      		long tmp = v[a];
	      		v[a] = v[b];
	      		v[b] = tmp;
	      		a++; b--;
	    	} else {
	      		break;
	    	}
		}
	
    	v[0] = v[b];
    	v[b] = x;
    
    	quick_sort(v, b);
    	quick_sort(&v[a], n-a);
	}
}

void mergeSort(long *v, long n) {
	mergeSort_ordena(v, 0, n-1);
}

void mergeSort_ordena(long *v, long esq, long dir) {
	if (esq == dir)
		return;
	long meio = (esq + dir) / 2;
	
	mergeSort_ordena(v, esq, meio);
	mergeSort_ordena(v, meio+1, dir);
	
	mergeSort_intercala(v, esq, meio, dir);
	return;
}

void mergeSort_intercala(long *v, long esq, long meio, long dir){
	int i, j, k;
	long a_tam = meio-esq+1;
	long b_tam = dir-meio;
	
	long *a = (long*) malloc(sizeof(long) * a_tam);
	long *b = (long*) malloc(sizeof(long) * b_tam);
	
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

void cresce_heap(int e, int d, long *vetor){
	int i,j,naoachou,x;
	i=e;
	j=2*i;
	naoachou=1;
	x=vetor[i-1];
	while((j<=d)&&(naoachou==1)){
		if(j,d)
			if(vetor[j-1]<vetor[j]) j++;
		if(x<vetor[j-1]){
			vetor[i-1]=vetor[j-1];
			i=j;
			j=2*i;
		}else
			naoachou=0;
	}
	vetor[i-1]=x;
}

void heapsort(int n, long *v){
	int e, d, x,i;
	d= n;
	e=(d/2);
	while(e>0){
		cresce_heap(e,d,v);
		e--;
	}
	while(d>=1){
		x= v[0];
		v[0]=v[d-1];
		v[d-1]=x;
		d--;
		cresce_heap(1,d,v);
	}
}

