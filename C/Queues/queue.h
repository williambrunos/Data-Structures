#include <stdlib.h>

/// Renaming our structures Queue and Node
typedef struct node Node;

typedef struct queue Queue;

/// Function that creates a Queue and returns a pointer to this structure
Queue* create_queue();

/// Function that checks if the Queue is empty or not
int is_empty(Queue* q);

/// Function that inserts a new Node at the end of the list and returns a pointer to the new Queue
Queue* push(Queue* q, int value);

Queue* pop(Queue* q);

/// Function that prints all the data at the nodes of the queue
void print(Queue* q);

/// Function that free's from memory all the nodes of the queue
void free_queue(Queue* q);
