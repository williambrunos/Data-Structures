#include "ponto.h"

/// Gives a nickname to the circulo struct
typedef struct circulo Circulo;

/// Creates a pointer that references the Circulo Struct
Circulo* circ_cria(float r, float x, float y);

/// Free the heap memory that was used by the struct circulo
void circ_libera(Circulo** ptr);

/// Returns by reference the values of the radius, x and y positions of the center
void circ_acessa(Circulo* circ, float* r, float* x, float* y);

/// Attributes radius, x and y vaues to these fields in some circle struct
void circ_atribui(Circulo* circ, float r, float x, float y);

/// Returns the distance between the center of the circle and some point
float circ_distancia(Circulo* circ, Ponto* ponto);

/// Returns the area of some circle
float circ_area(Circulo* circ);

/// Returns 1 if some point is inside the circle or 0 if it's not
int circ_interno(Circulo* circ, Ponto* ponto);
