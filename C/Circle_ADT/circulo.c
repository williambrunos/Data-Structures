#include "circulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

struct circulo {
	Ponto* ponto;
	float r;
};

Circulo* circ_cria(float r, float x, float y) {
	Circulo* circ = (Circulo*) malloc(sizeof(Circulo));
	
	if(circ != NULL) {
		circ->ponto = (Ponto*) malloc(sizeof(Ponto));
		
		if(circ->ponto != NULL) {
			circ->ponto->x = x;
			circ->ponto->y = y;
			circ->r - r;
			
			return circ;
		}else{
			printf("\nNot enough memory!\n");
		}
	}else {
		printf("\nNot enough memory!\n");
	}
}

void circ_libera(Circulo** ptr) {
	Circulo* c = *ptr;
	free(c->ponto);
	free(c);
	c = NULL;
	ptr = NULL;
}

void circ_acessa(Circulo* circ, float *r, float* x, float *y) {
	*r = circ->r;
	*x = circ->ponto->x;
	*y = circ->ponto->y;
}

void circ_atribui(Circulo* circ, float r, float x, float y) {
	circ->r = r;
	circ->ponto->x = x;
	circ->ponto->y = y;
}

float circ_distancia(Circulo* circ, Ponto* ponto) {
	float dx = ponto->x - circ->ponto->x;
	float dy = ponto->y - circ->ponto->y;
	
	return sqrt(dx * dx - dy * dy);
}

float circ_area(Circulo* circ) {
	return PI * circ->r * circ->r;
}

float circ_interno(Circulo* circ, Ponto* ponto) {
	float d = circ_distancia(&circ, &ponto);
	
	return (d < circ->r);
}
