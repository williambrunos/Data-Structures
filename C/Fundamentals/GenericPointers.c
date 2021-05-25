#include <stdio.h>
#include <stdlib.h>

int main() {
    void *pointer;
    int p1 = 10;
    float p2 = 10.6;
    char p3 = 'd';
    /// pointer -> p1
    pointer = &p1;
    printf("pointer = %p ; *pointer = %d ;\n", pointer, *(int*)pointer);

    /// pointer -> p2
    pointer = &p2;
    printf("pointer = %p ; *pointer = %.2f ;\n", pointer, *(float*)pointer);

    /// pointer -> p3
    pointer = &p3;
    printf("pointer = %p ; *pointer = %c ; \n", pointer, *(char*)pointer);

    pointer = NULL;
    system("pause");
    return 0;
}
