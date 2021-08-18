#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "algoritmos.h"

int main()
{
	clock_t t;
    long length;
    int power = 2;
    srand(time(NULL));
    
    /* BUBBLE SORT */
    printf(" ===== BUBBLE SORT ====\n\n");
    // Armazenando valores no vetor de forma crescente -> melhor caso
    
    printf(" ==== Crescente ==== \n");
	
	/*
	O bloco do...while executa a aloca��o do vetor de tamanho "length", calcula e mostra o seu tempo de ordena��o
	para cada algoritmo. Ao final, a vari�vel "power" � incrementada em 1 para que length assuma a pr�xima pot�ncia
	de 10 requisitada.
	*/
	do {
	   	length = pow(10, power);
	   	long *v = (long*) malloc(sizeof(long) * length);
	    
	    int i;
	    for(i = 0; i < length; i++) {
	    	v[i] = i;
		}
			
		t = clock(); //armazena tempo
		bubble_sort(v, length);
		t = clock() - t; //tempo final - tempo inicial
			
		printf("Tempo de execucao: %lf para %ld \n", ((double)t)/((CLOCKS_PER_SEC/1000)), length); //convers�o para double
		
		free(v);
		v = NULL;
			
		power++;
	} while(power <= 5);

	// Armazenando valores de forma descrescente -> pior caso
	printf(" ==== Decrescente ==== \n");
	
	do {
	    length = pow(10, power);
	    long *v = (long*) malloc(sizeof(long) * length);
	    
		int i;
		for(i = 0; i < length; i++) {
		    v[i] = length - i;
		}
			
		t = clock(); //armazena tempo
		bubble_sort(v, length);
		t = clock() - t; //tempo final - tempo inicial
			
		printf("Tempo de execucao: %lf para %ld \n", ((double)t)/((CLOCKS_PER_SEC/1000)), length); //convers�o para double
		
		free(v);
		v = NULL;
			
		power++;
	} while(power <= 5);
	
	// Armazenando de forma aleat�ria -> caso m�dio
	printf(" ==== Aleatorio ==== \n");
	
	do {
	    length = pow(10, power);
	    long *v = (long*) malloc(sizeof(long) * length);
	    
		int i;
		for(i = 0; i < length; i++) {
		    v[i] = rand() % length;
		}
			
		t = clock(); //armazena tempo
		bubble_sort(v, length);
		t = clock() - t; //tempo final - tempo inicial
			
		printf("Tempo de execucao: %lf para %ld \n", ((double)t)/((CLOCKS_PER_SEC/1000)), length); //convers�o para double
		
		free(v);
		v = NULL;
			
		power++;
	} while(power <= 5);
	
	/* BUBBLE SORT COM FLAG */
	printf("\n\n ==== BUBBLE SORT COM FLAG ==== \n\n");
	
	printf("\n ==== CRESCENTE ==== \n");
	
	
	do {
	    length = pow(10, power);
	    long *v = (long*) malloc(sizeof(long) * length);
	    
		int i;
		for(i = 0; i < length; i++) {
		    v[i] = i;
		}
			
		t = clock(); //armazena tempo
		bubble_sort_with_flag(v, length);
		t = clock() - t; //tempo final - tempo inicial
			
		printf("Tempo de execucao: %lf para %ld \n", ((double)t)/((CLOCKS_PER_SEC/1000)), length); //convers�o para double
		
		free(v);
		v = NULL;
			
		power++;
	} while(power <= 6);
	
	//printf("\n ==== DECRESCENTE ==== \n");
	
	do {
	    length = pow(10, power);
	    long *v = (long*) malloc(sizeof(long) * length);
	    
		int i;
		for(i = 0; i < length; i++) {
		    v[i] = length - i;
		}
			
		t = clock(); //armazena tempo
		bubble_sort_with_flag(v, length);
		t = clock() - t; //tempo final - tempo inicial
			
		printf("Tempo de execucao: %lf para %ld \n", ((double)t)/((CLOCKS_PER_SEC/1000)), length); //convers�o para double
		
		free(v);
		v = NULL;
			
		power++;
	} while(power <= 6);*/
	
	// printf("\n ==== ALEAT�RIA ==== \n");
	do {
	    length = pow(10, power);
	    long *v = (long*) malloc(sizeof(long) * length);
	    
		int i;
		for(i = 0; i < length; i++) {
		    v[i] = rand() % length;
		}
			
		t = clock(); //armazena tempo
		bubble_sort_with_flag(v, length);
		t = clock() - t; //tempo final - tempo inicial
			
		printf("Tempo de execucao: %lf para %ld \n", ((double)t)/((CLOCKS_PER_SEC/1000)), length); //convers�o para double
		
		free(v);
		v = NULL;
			
		power++;
	} while(power <= 6);

	
	/* INSERTION SORT */
	printf("\n\n ==== INSERTION SORT ==== \n\n");
	// Ordenando de forma crescente
	printf(" ==== Crescente ==== \n");
	
	do {
	   	length = pow(10, power);
	    long *v = (long*) malloc(sizeof(long) * length);
	    
		int i;
		for(i = 0; i < length; i++) {
		    v[i] = i;
		}
			
		t = clock(); //armazena tempo
		insertion_sort(v, length);
		t = clock() - t; //tempo final - tempo inicial
			
		printf("Tempo de execucao: %lf para %ld \n", ((double)t)/((CLOCKS_PER_SEC/1000)), length); //convers�o para double

		free(v);
		v = NULL;
			
		power++;
	} while(power <= 6);

	
	/* Ordenando de forma decrescente */
	printf(" ==== Decrescente ==== \n");

	do {
	    length = pow(10, power);
	    long *v = (long*) malloc(sizeof(long) * length);
	    
		int i;
		for(i = 0; i < length; i++) {
		   	v[i] = length - i;
		}
			
		t = clock(); //armazena tempo
		insertion_sort(v, length);
		t = clock() - t; //tempo final - tempo inicial
			
		printf("Tempo de execucao: %lf para %ld \n", ((double)t)/((CLOCKS_PER_SEC/1000)), length); //convers�o para double

		free(v);
		v = NULL;
			
		power++;
	} while(power <= 6);

	
	/* Ordenando de forma aleat�ria */
	
	printf(" ==== Aleat�ria ==== \n");

	do {
	    length = pow(10, power);
	    long *v = (long*) malloc(sizeof(long) * length);
	    
		int i;
		for(i = 0; i < length; i++) {
		    v[i] = rand() % length;
		}
			
		t = clock(); //armazena tempo
		insertion_sort(v, length);
		t = clock() - t; //tempo final - tempo inicial
			
		printf("Tempo de execucao: %lf para %ld \n", ((double)t)/((CLOCKS_PER_SEC/1000)), length); //convers�o para double

		free(v);
		v = NULL;
			
		power++;
	} while(power <= 6);
	
	/* QUICKSORT */
	
	printf("\n\n ==== QUICK SORT ==== \n\n");
	/* Ordendando de forma crescente */
	printf(" ==== Crescente ==== \n");
	
	
	do {
	   	length = pow(10, power);
	   	
	    long *v = (long*) malloc(sizeof(long) * length);
	    
		int i;
		for(i = 0; i < length; i++) {
		    v[i] = i;
		}

		t = clock(); //armazena tempo
		quick_sort(v, length);
		t = clock() - t; //tempo final - tempo inicial
			
		printf("Tempo de execucao: %lf para %ld \n", ((double)t)/((CLOCKS_PER_SEC/1000)), length); //convers�o para double
		
		free(v);
		v = NULL;
		
		power++;
	} while(power <= 6);

	printf("\n ==== Decrescente ==== \n");
	
	do {
	   	length = pow(10, power);
	   	
	    long *v = (long*) malloc(sizeof(long) * length);
	    
		int i;
		for(i = 0; i < length; i++) {
		    v[i] = length - i;
		}

		t = clock(); //armazena tempo
		quick_sort(v, length);
		t = clock() - t; //tempo final - tempo inicial
			
		printf("Tempo de execucao: %lf para %ld \n", ((double)t)/((CLOCKS_PER_SEC/1000)), length); //convers�o para double
		
		free(v);
		v = NULL;
		
		power++;
	} while(power <= 6);

	
	printf("\n ==== Aleat�ria ==== \n");
	
	do {
	   	length = pow(10, power);
	   	
	    long *v = (long*) malloc(sizeof(long) * length);
	    
		int i;
		for(i = 0; i < length; i++) {
		    v[i] = rand() % length;
		}

		t = clock(); //armazena tempo
		quick_sort(v, length);
		t = clock() - t; //tempo final - tempo inicial
			
		printf("Tempo de execucao: %lf para %ld \n", ((double)t)/((CLOCKS_PER_SEC/1000)), length); //convers�o para double
		
		free(v);
		v = NULL;
		
		power++;
	} while(power <= 6);

	printf("\n\n ==== MERGE SORT ==== \n\n");
	
	printf(" ==== CRESCENTE ==== \n");
	
	
	do {
	   	length = pow(10, power);
	   	
	    long *v = (long*) malloc(sizeof(long) * length);
	    
		int i;
		for(i = 0; i < length; i++) {
		    v[i] = i;
		}

		t = clock(); //armazena tempo
		mergeSort(v, length);
		t = clock() - t; //tempo final - tempo inicial
			
		printf("Tempo de execucao: %lf para %ld \n", ((double)t)/((CLOCKS_PER_SEC/1000)), length); //convers�o para double
		
		free(v);
		v = NULL;
		
		power++;
	} while(power <= 6);

	
	printf("\n ==== DECRESCENTE ==== \n");
	
	do {
	   	length = pow(10, power);
	   	
	    long *v = (long*) malloc(sizeof(long) * length);
	    
		int i;
		for(i = 0; i < length; i++) {
		    v[i] = length - i;
		}

		t = clock(); //armazena tempo
		mergeSort(v, length);
		t = clock() - t; //tempo final - tempo inicial
			
		printf("Tempo de execucao: %lf para %ld \n", ((double)t)/((CLOCKS_PER_SEC/1000)), length); //convers�o para double
		
		free(v);
		v = NULL;
		
		power++;
	} while(power <= 6);

	printf("\n ==== ALEATORIA ==== \n");
	
	do {
	   	length = pow(10, power);
	   	
	    long *v = (long*) malloc(sizeof(long) * length);
	    
		int i;
		for(i = 0; i < length; i++) {
		    v[i] = rand() % length;
		}

		t = clock(); //armazena tempo
		mergeSort(v, length);
		t = clock() - t; //tempo final - tempo inicial
			
		printf("Tempo de execucao: %lf para %ld \n", ((double)t)/((CLOCKS_PER_SEC/1000)), length); //convers�o para double
		
		free(v);
		v = NULL;
		
		power++;
	} while(power <= 6);
	
	
	printf("\n\n ==== HEAP SORT ==== \n\n");
	printf("\n ==== CRESCENTE ==== \n");
	
	do {
	   	length = pow(10, power);
	   	
	    long *v = (long*) malloc(sizeof(long) * length);
	    
		int i;
		for(i = 0; i < length; i++) {
		    v[i] = i;
		}

		t = clock(); //armazena tempo
		heapsort(length, v);
		t = clock() - t; //tempo final - tempo inicial
			
		printf("Tempo de execucao: %lf para %ld \n", ((double)t)/((CLOCKS_PER_SEC/1000)), length); //convers�o para double
		
		free(v);
		v = NULL;
		
		power++;
	} while(power <= 6);
	
	printf("\n ==== DECRESCENTE ==== \n");
	
	do {
	   	length = pow(10, power);
	   	
	    long *v = (long*) malloc(sizeof(long) * length);
	    
		int i;
		for(i = 0; i < length; i++) {
		    v[i] = length - i;
		}

		t = clock(); //armazena tempo
		heapsort(length, v);
		t = clock() - t; //tempo final - tempo inicial
			
		printf("Tempo de execucao: %lf para %ld \n", ((double)t)/((CLOCKS_PER_SEC/1000)), length); //convers�o para double
		
		free(v);
		v = NULL;
		
		power++;
	} while(power <= 6);
	
	printf("\n ==== ALEAT�RIA ==== \n");
	do {
	   	length = pow(10, power);
	   	
	    long *v = (long*) malloc(sizeof(long) * length);
	    
		int i;
		for(i = 0; i < length; i++) {
		    v[i] = rand() % length;
		}

		t = clock(); //armazena tempo
		heapsort(length, v);
		t = clock() - t; //tempo final - tempo inicial
			
		printf("Tempo de execucao: %lf para %ld \n", ((double)t)/((CLOCKS_PER_SEC/1000)), length); //convers�o para double
		
		free(v);
		v = NULL;
		
		power++;
	} while(power <= 6);
	return 0;
}

