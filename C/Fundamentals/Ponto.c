#include <stdlib.h>
#include <math.h>
#include "Ponto.h"

struct ponto {
    float x;
    float y;
};

Ponto* pt_cria(float x, float y) {
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));

    if(p != NULL) {
        p->x = x;
        p->y = y;
    }

    return p;
}

void pt_libera(Ponto *p) {
    free(p);
}

void pt_acessa(Ponto *p, float *x, float *y) {
    *x = p->x;
    *y = p->y;
}

void pt_atribui(Ponto *p, float x, float y) {
    p->x = x;
    p->y = y;
}

float distancia(Ponto *p1, Ponto *p2) {
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    return sqrt(dx * dx + dy * dy);
}
