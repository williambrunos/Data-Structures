#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StaticList.h"

int main()
{
    Lista* lista = createList();

    int sizeOfTheList = listSize(lista);

    if(sizeOfTheList != -1) {
        printf("List Size: %d \n", listSize(lista));
    }else{
        printf("The List might have not been created correctly!\n");
    }

    int isFull = isListFull(lista);
    int isEmpty = isListEmpty(lista);

    if(isFull == 1) {
        printf("The list is full!\n");
    } else if(isFull == -1) {
        printf("The List might have not been created correctly!\n");
    }

    if(isEmpty == 1) {
        printf("The list is empty!\n");
    }else if(isEmpty == -1) {
        printf("The List might have not been created correctly!\n");
    }

    Alunos aluno[2];
    int i;
    aluno[0].matricula = 100;
    strcpy(aluno[0].name, "William");
    aluno[0].note1 = 2.3;
    aluno[0].note2 = 9.2;
    aluno[0].note3 = 8.7;

    aluno[1].matricula = 200;
    strcpy(aluno[1].name, "Danilo");
    aluno[1].note1 = 8;
    aluno[1].note2 = 6.7;
    aluno[1].note3 = 9.6;

    for(i = 0; i < 2; i++) {
        int token = insertValue(lista, i, aluno[i]);
        if(token != 1) printf("Erro ao adicionar elemento\n");
    }

    Alunos alunos;
    findValueByIndex(lista, 1, &alunos);

    printf("%s \n", alunos.name);
    printf("%d \n", alunos.matricula);
    printf("%.2f \n", alunos.note1);
    printf("%.2f \n", alunos.note2);
    printf("%.2f \n", alunos.note3);


    findValueByIndex(lista, 2, &alunos);

    printf("%s \n", alunos.name);
    printf("%d \n", alunos.matricula);
    printf("%.2f \n", alunos.note1);
    printf("%.2f \n", alunos.note2);
    printf("%.2f \n", alunos.note3);

    destroyList(lista);
    return 0;
}
