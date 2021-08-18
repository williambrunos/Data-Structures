#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main() {
	Ponto* ponto_1;
	float x, y;
	printf("=====PONTO 1=====\n");
	printf("X: ");
	scanf("%f", &x);
	printf("Y: ");
	scanf("%f", &y);
	
	ponto_1 = pto_cria(x, y);
	
	Ponto* ponto_2;
	printf("=====PONTO 2=====\n");
	printf("X: ");
	scanf("%f", &x);
	printf("Y: ");
	scanf("%f", &y);
	
	ponto_2 = pto_cria(x, y);
	
	pto_acessa(ponto_1, &x, &y);
	printf("\nDADOS PONTO 1\n");
	printf("X: %.2f ; Y: %.2f \n", x, y);
	
	pto_acessa(ponto_2, &x, &y);
	printf("\nDADOS PONTO 2\n");
	printf("X: %.2f ; Y: %.2f \n", x, y);
	
	float distance = pto_distancia(ponto_1, ponto_2);
	printf("\nDistance between the points: %.2f \n", distance);
	
	pto_libera(ponto_1);
	pto_libera(ponto_2);
	return 0;
}
