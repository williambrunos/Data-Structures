/// Defining a type for the struct ponto
typedef struct ponto Ponto;

/// Returns a pointer to the ponto struct in heap memory
Ponto* pto_cria(float x, float y);

/// Free the heap memory used by some ponto struct to recicle
void pto_libera(Ponto* ptr);

/// Returns by reference the x and y values at some struct ponto
void pto_acessa(Ponto* ponto, float* x, float* y);

/// Attributes x and y value for some ponto struct
void pto_atribui(Ponto *ponto, float x, float y);

/// Returns the distance between two different structs ponto
float pto_distancia(Ponto* p1, Ponto *p2);
