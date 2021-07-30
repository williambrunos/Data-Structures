#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"

struct arvb {
	int info;
	ArvB* esq;
	ArvB* dir;
};

ArvB* arvb_cria_vazia(void) {
	return NULL;
}

int arvb_vazia(ArvB *a) {
	return (a == NULL);
} 

/* Busca um elemento em uma �rvore bin�ria de busca de forma recursiva*/
ArvB* arvb_busca(ArvB *a, int c){
	if(arvb_vazia(a))
		return NULL;
	else if(a->info < c)
		return arvb_busca(a->dir,c);
	else if(a->info > c)
		return arvb_busca(a->esq,c);
	else //(a->info == c)
		return a;
}

/* Impress�o dos elementos de uma �rvore bin�ria de busca na forma sim�trica -> SAE | Ra�z | SAD */
void arvb_imprime(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_imprime(a->esq);
		printf("%d ",a->info);
		arvb_imprime(a->dir);
	}
}

/* Insere um elemento 'c'(int) como uma folha em uma �rvore bin�ria de busca */
ArvB* arvb_insere(ArvB *a, int c){
	if(arvb_vazia(a)){
		a = (ArvB*)malloc(sizeof(ArvB));
		a->info = c;
		a->esq = NULL;
		a->dir = NULL;
	}else if(a->info > c)
		a->esq = arvb_insere(a->esq,c);
	else if (a->info < c)
		a->dir = arvb_insere(a->dir,c);
	else
		printf("\nElemento Ja Pertence a Arvore");
	return a;
}

/* 
	Remove um elemento de uma �rvore bin�ria de busca de forma recursiva: 
	Se o elemento for maior do que o da ra�z da �rvore(sub) em quest�o, procuramos na SAD
	Procuramos na SAE caso 'c' seja menor que o elemeneto ra�z
	
	Quando encontrar, verifique se o elemento � esquerda � nulo:
	se for, libere o espa�o da ra�z
	se o da direita for nulo, libere o espa�o da mesma forma
	
	Se possuir duas sub �rvores, trocar seu valor com o do elemento mais a direita da sub�rvore
	esquerda. Continua a busca recursiva para eliminar esse valor 'c'
*/
ArvB* arvb_remove(ArvB *a, int c){
	if(!arvb_vazia(a)){
		if(a->info > c)
			a->esq = arvb_remove(a->esq,c);
		else if (a->info < c)
			a->dir = arvb_remove(a->dir,c);
		else{
			ArvB* t;
			if (a->esq == NULL){
				t = a; a = a->dir;
				free(t);
			}else if (a->dir == NULL){
				t = a; a = a->esq;
				free(t);
			}else{
				t = a->esq;
				while(t->dir!=NULL)
					t = t->dir;
				a->info = t->info; t->info = c;
				a->esq = arvb_remove(a->esq,c);
			}
		}
	}
	return a;
}

/* Fun��o que calcula o n�mero de divisores inteiros positivos de um n�mero */
int num_divisores(int num) {
	int qtd = 0, i;
	for(i = 1; i <= num; i++) {
		if(num % i == 0) {
			qtd++;
		}
	}
	return qtd;
}

/* Fun��o resursiva em ordem sim�trica -> Se utiliza da fun��o 'num_divisores' */
int folhas_ndivp(ArvB* a, int n) {
	int qtd = 0;
	
	if(!arvb_vazia(a)) {
		qtd += folhas_ndivp(a->esq, n);
		
		if(num_divisores(a->info) == n) {
			qtd++;
		}
		
		qtd += folhas_ndivp(a->dir, n);
	}
	
	return qtd;
}

int dois_filhos(ArvB* a) {
	int qtd = 0;
	if(!arvb_vazia(a)) {
		qtd += dois_filhos(a->esq);
		
		if((a->esq != NULL) && (a->dir != NULL)) {
			qtd++;
		}
		
		qtd += dois_filhos(a->dir);
	}
	
	return qtd;
}

int arvb_altura(ArvB *a) {
	if(arvb_vazia(a))
		return -1;
	else{
	int hSAE = arvb_altura(a->esq);
	int hSAD = arvb_altura(a->dir);
	
	if(hSAE > hSAD)
		return 1+hSAE;
	else
		return 1+hSAD;
	}
}

int nos_igual_altura(ArvB* a) {
	int qtd = 0;
	if(!arvb_vazia(a)) {
		qtd += nos_igual_altura(a->esq);
		
		if(arvb_altura(a->esq) == arvb_altura(a->dir)) {
			qtd++;
		}
		
		qtd += nos_igual_altura(a->dir);
	}
		
	return qtd;
}

int arv_iguais(ArvB* a, ArvB* b) {
	if(arvb_vazia(a) && arvb_vazia(b)) {
		return 1;
	} else {
		if(a->info == b->info && arv_iguais(a->esq, b->esq) && arv_iguais(a->dir, b->dir)) {
			return 1;
		}
	}
	
	return 0;	
}

void imprime_nivel_atual(ArvB* a, int i) {
	if(arvb_vazia(a)) {
		return;
	} 
	
	if (i == 1) {
		printf("%d ", a->info);
	} else if (i > 1) { 
		imprime_nivel_atual(a->esq, i - 1);
		imprime_nivel_atual(a->dir, i - 1);
	}
}

void impressao_arv_niveis(ArvB* a) {
	int h = arvb_altura(a) + 1;
	int i;
	
	for(i = 1; i <= h; i++) {
		imprime_nivel_atual(a, i);
		printf("\n");
	}
}

void arvb_libera(ArvB *a) {
	if (!arvb_vazia(a)) {
		arvb_libera(a->esq);
		arvb_libera(a->dir);
		free(a);
	}
}
