#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto {
	float x;
	float y;
};

Ponto* pto_cria(float x, float y) {
	Ponto* ponto = (Ponto*) malloc(sizeof(Ponto));
	
	if(ponto != NULL) {
		ponto->x = x;
		ponto->y = y;
		
		return ponto;
	}else {
		printf("\nNot enough ram memory!\n");
		exit(1);
	}
}

void pto_libera(Ponto* ptr) {
	free(ptr);
	ptr = NULL;
}

void pto_acessa(Ponto* ponto, float* x, float* y) {
	*x = ponto->x;
	*y = ponto->y;
}

void pto_atribui(Ponto* ponto, float x, float y) {
	ponto->x = x;
	ponto->y = y;
}

float pto_distancia(Ponto* p1, Ponto* p2) {
	float dx = p2->x - p1->x;
	float dy = p2->y - p1->y;
	
	return sqrt(pow(dx, 2) + pow(dy, 2));
}
