#define MAX 100

/// Defining the data structure hold by the list
typedef struct alunos {
    int matricula;
    char name[30];
    float note1, note2, note3;
} Alunos;

/// Naming our List
typedef struct lista Lista;

/// Method to create the list
Lista* createList();

/// Method to free the list from the memory
void destroyList(Lista* li);

/// Method to return the size of the list
int listSize(Lista* li);

/// Methods to check if the list is full or empty
int isListFull(Lista* li);

int isListEmpty(Lista* li);

/// Method to insert a value at some index of the List
int insertValue(Lista* li, int index, Alunos aluno);

/// Method to remove a value at some index of the list
int removeValue(Lista* li, int index);

/// Method that returns by reference the struct Alunos found in the list
int findValueByIndex(Lista* li, int index, Alunos *aluno);
