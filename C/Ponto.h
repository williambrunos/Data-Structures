/// Declaração da Struct
typedef struct ponto Ponto;

/// Método para criação de um objeto da estrutura Ponto
Ponto* pt_cria(float x, float y);

/// Método que libera o objeto Ponto
void pt_libera(Ponto *p);

/// Método que acessa e recebe por referência var x e y
void pt_acessa(Ponto *p, float *x, float *y);

/// Método que atribui valores x e y ao ponto
void pt_atribui(Ponto *p, float x, float y);

/// Método que calcula distância entre dois objetos Pontos
float distancia(Ponto *p1, Ponto *p2);
