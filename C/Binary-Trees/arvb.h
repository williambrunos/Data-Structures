typedef struct arvb ArvB;

/* Função que cria uma árvore Binária de Busca Vazia.*/
ArvB* arvb_cria_vazia(void);

/*Testa se uma árvore Binária é vazia.*/
int arvb_vazia(ArvB *a);

/* Função que busca a sub-árvore que contêm um inteiro.*/
ArvB* arvb_busca(ArvB *a, int c);

/* Função que imprime os elementos de uma árvore.*/
void arvb_imprime(ArvB *a);

/* Função que insere um inteiro em uma árvore.*/
ArvB* arvb_insere(ArvB *a, int c);

/* Função que remove um inteiro em uma árvore.*/
ArvB* arvb_remove(ArvB *a, int c);

/*  Função que retorna a quantidade de nós da árvore com 'n' divisores inteiros positivos */
int folhas_ndivp(ArvB* a, int n);

/*  Função que retorna a quantidade de nós da árvore com 2 filhos (not null) */
int dois_filhos(ArvB* a);

/*  Função que calcula a quantidade de nós com SAE's e SAD's com mesma altura */
int nos_igual_altura(ArvB* a);

/*  Função que retorna 1 se duas árvores forem iguais e 0 caso contrário */
int arv_iguais(ArvB* a, ArvB* b);

/* Funçãoo que printa no console os elementos por nível de uma �rvore*/
void impressao_arv_niveis(ArvB* a);

/*Libera o espaço alocado para uma árvore.*/
void arvb_libera(ArvB *a);
