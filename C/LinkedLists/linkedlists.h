// Header for functions prototypes

// Typedefining out linked list
typedef struct linkedlist Linkedlist;

// Create the linked list
Linkedlist* create_list();

// Checks if the list is empty
int is_empty(Linkedlist* list);

// Insert a element at the beggining of the list
Linkedlist* unshift(Linkedlist* list, int value);

// Search for a element in a list
Linkedlist* search(Linkedlist* list, int value);

// Print all the elements of an list
void print_list(Linkedlist* list);

// Removes an element of the list by it value
Linkedlist* remove_element_by_value(Linkedlist* list, int value);

// Remove an element of the list by it 'index'
int remove_element_by_index(Linkedlist* list, int index);

// Free the linked list from RAM memory
void free_list(Linkedlist* list);
