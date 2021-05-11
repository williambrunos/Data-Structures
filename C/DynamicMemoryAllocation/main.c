#include <stdio.h>
#include <stdlib.h>

/*

 - Prototype of malloc: (void*) malloc(ungsined int numberOfBytes);
 - args: number of bytes for being sequencially allocated
 - void* means that it returns a generic pointer for the structure allocated
 - returns NULL in case of error in the allocation

 - Prototype of calloc: (void*) calloc(ungsined int numberOfSpaces, ungsined int sizeOfVariable);
 - The return works at the same way that the malloc function
 - malloc VS calloc => malloc allocates the memory with every space with a memory garbage. Otherwise,
 calloc function allocates the memory and attributes for every space the value of 0.
 
 - Prototype of realloc: (void*) realloc(void* pointer, ungsined int newSpaceMemory);
 - args: pointer is the variable which we want to store the new space memory(size in bytes represent
 by the int variable)
 - We use this function when we want to modify the size of the array dynamically allocated in memory
 
 - obs: all these functions are going to return NULL if the computer doesn't have sufficient memory to
 allocate the array
 
*/

int** createDynamicMatrix(int rows, int collumns) {
	int** matrix;
	matrix = (int**) calloc(rows, sizeof(int*));
	
	int i;
	for(i = 0; i < rows; i++) {
		matrix[i] = (int*) calloc(collumns, sizeof(int));
	}
	
	return matrix;
}

typedef struct ponto {
	int x, y, z;
} Ponto;

int main() {
	int arraySize;
	
	printf("int size: %d \n", sizeof(int));
	printf("float size: %d \n", sizeof(float));
	printf("char size: %d \n", sizeof(char));
	printf("double size: %d \n", sizeof(double));
	printf("Ponto size: %d \n", sizeof(Ponto));
	
	/* ==================== USING MALLOC ==================== */
	
	do {
		printf("Digite do tamanho do array unidimensional: ");
		scanf("%d", &arraySize);
		
		if(arraySize <= 0) {
			printf("Digite um número maior do que zero. \n");
		}
	}while(arraySize <= 0);
	
	int *array = (int*) malloc(sizeof(int) * arraySize);
	
	if(array == NULL) {
		printf("Erro, sem memória sufificente!\n");
		exit(1);
	}
	
	int i;
	for(i = 0; i < arraySize; i++) {
		printf("array[%d] = ", i);
		scanf("%d", &array[i]);
		printf("\n");
	}
	
	for(i = 0; i < arraySize; i++) {
		printf("array[%d] = %d \n", i, array[i]);
	}
	
	/// Free the memory allocated for the array
	// free(array);
	
	/* ==================== USING CALLOC ==================== */
	
	do{
		printf("Digite o tamanho do array: ");
		scanf("%d", &arraySize);
		
		if(arraySize <= 0){
			printf("Digite um número maior do que 0 \n");
		}
	}while(arraySize <= 0);
		
	array = (int*) calloc(arraySize, sizeof(int));
	
	for(i = 0; i < arraySize; i++) {
		printf("array[%d] = %d \n", i, array[i]);
	}
	
	/// free(array); => We dont't need to free the pointer and allocate it again...
	
	/* ==================== USING REALLOC =================== */
	
	do{
		printf("Digite o tamanho do array(redimensionado): ");
		scanf("%d", &arraySize);
		
		if(arraySize <= 0){
			printf("Digite um número maior do que 0 \n");
		}
	}while(arraySize <= 0);
	
	array = (int*) realloc(array, arraySize * sizeof(int));
	
	for(i = 0; i < arraySize; i++) {
		printf("array[%d] = ", i);
		scanf("%d", &array[i]);
		printf("\n");
	}
	
	for(i = 0; i < arraySize; i++) {
		printf("array[%d] = %d \n", i, array[i]);
	}
	
	/* ================= ALLOCATING A MATRIX ================ */
	
	printf("\n\n MATRIX ALLOCATED USING CALLOC \n\n");
	
	int** matrix = createDynamicMatrix(5, 5);
	
	int j;
	for(i = 0; i < 5; i++) {
		for(j = 0; j < 5; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	
	for(i = 0; i < 5; i++) {
		free(matrix[i]);
	}
	
	free(matrix);
	free(array);
	system("pause");
	return 0;
}
