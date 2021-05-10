#include "StaticList.h"
#include <stdlib.h>

struct lista {
    int qtd;
    Alunos data[MAX];
};

Lista* createList() {
    Lista* li = (Lista*) malloc(sizeof(Lista));

    if(li != NULL) {
        li->qtd = 0;
    }

    return li;
}

int listSize(Lista* li) {
    if(li != NULL) {
        return li->qtd;
    }else {
        return -1; /// Error code
    }
}

int isListFull(Lista* li) {
    if(li != NULL) {
        return (li->qtd == MAX);
    }else {
        return -1;
    }
}

int isListEmpty(Lista* li) {
    if(li != NULL) {
        return (li->qtd == 0);
    }else {
        return -1;
    }
}

void destroyList(Lista* li) {
    free(li);
}

int insertValue(Lista* li, int index, Alunos aluno) {
    int qtd = li->qtd;
    /// Verifying if the list is full
    if(isListFull(li) || li == NULL || index < 0 || index > qtd) {
        return -1;
    } else {
        /// Verifying if we want to insert the value on the end
        /// of the list
        if(li->qtd == index) {
            li->data[index] = aluno;
            li->qtd++;
            return 1;
        }else {
            /// Algorithm to insert the value on the middle of the list and
            /// sorting it again
            int i;
            for(i = qtd-1; i <= index; i--) {
                li->data[i+1] = li->data[i];
            }

            li->data[index] = aluno;
            li->qtd++;
            return 1;
        }
    }
}

int removeValue(Lista* li, int index) {
    int qtd = li->qtd;
    if(isListEmpty(li) || li == NULL || index < 0 || index > qtd) {
        return -1;
    }else {
        /// If the value is at the end of the list, we dont need to sort it
        if(index == qtd - 1) {
            li->qtd--;
            return 1;
        } else {
            /// If the element isn't in the end of the list, we need to sort
            int i;
            for(i = index; i < qtd - 1; i++) {
                li->data[i] = li->data[i+1];
            }

            li->qtd--;
            return 1;
        }
    }
}

/// In this function, we copy the value hold at some point of the list in a
/// variable recieved as parameter, by reference
int findValueByIndex(Lista* li, int index, Alunos *aluno) {
    int qtd = li->qtd;
    if(li == NULL || index <= 0 || index > qtd) {
        return -1;
    } else if (index == 1) {
        *aluno = li->data[0];
        return 1;
    } else {
        *aluno = li->data[index - 1];
        return 1;
    }
}
