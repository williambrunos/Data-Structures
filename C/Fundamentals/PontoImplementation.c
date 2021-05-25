#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"

int main() {
    Ponto *p, *q;
    p = pt_cria(10, 20);
    q = pt_cria(30, 40);

    float d = distancia(p, q);
    printf("Distance = %.2f \n", d);

    pt_libera(p);
    pt_libera(q);
    system("pause");
    return 0;
}
