#include <stdio.h>
#include <stdlib.h>
#include "linkedlists.h"

int main() {
	Linkedlist* linked_list;
	linked_list = create_list();
	linked_list = unshift(linked_list, 4);
	linked_list = unshift(linked_list, 5);
	linked_list = remove_element_by_value(linked_list, 5);
	print_list(linked_list);	
	free_list(linked_list);
	return 0;
}
