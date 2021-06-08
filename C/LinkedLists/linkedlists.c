#include <stdio.h>
#include <stdlib.h>
#include "linkedlists.h"

struct linkedlist {
	int data;
	Linkedlist* next;
};

Linkedlist* create_list() {
	return NULL;
}

int is_empty(Linkedlist* list) {
	if(list == NULL) return 1;
	else return 0;
}

// Returns the updated list with the new value at the beggining
Linkedlist* unshift(Linkedlist* list, int value) {
	Linkedlist* node = (Linkedlist*) malloc(sizeof(Linkedlist));
	node->data = value;
	node->next = list;
	return node;
}

Linkedlist* insert_ordered(Linkedlist* list, int value) {
	Linkedlist* lNew = (Linkedlist*) malloc(sizeof(Linkedlist));
	lNew->data = value;
	if(list == NULL){
		lNew->next = NULL;
		return lNew;
	}else if(list->data>=value){
		lNew->next = list;
		return lNew;
	}else{
		Linkedlist* lAnt = list;
		Linkedlist* lProx = list->next;
		while(lProx != NULL && lProx -> data<value){
			lAnt = lProx;
			lProx = lProx->next;
		}
		lAnt->next = lNew;
		lNew->next = lProx;
		return list;
	}
}

// Searchs for a value into a linked list and returns the position of it at the list
Linkedlist* search(Linkedlist *list, int value) {
	int counter = 1;
	Linkedlist* node = list;
	
	while(node != NULL) {
		if(node->data == value) {
			return node;
		}
		counter++;
		node = node->next;
	}
	
	return NULL;
}

void print_list(Linkedlist* list) {
	Linkedlist* node = list;
	int counter = 1;
	while(node != NULL) {
		printf("\n====NODE %d====\n", counter);
		printf("| data: %d \n", node->data);
		counter++;
		node = node->next;
	}
}

/*
 In this function, we create two auxiliar nodes, one before beggining with the first element of
 the list, and the another one beggining with the second. If the value which we want to find is
 at the first position of the list, we free that space of memory and returns the node_after pointer
 (holds the rest of the list excluding th first element). If it isn't at the first element, we
 search in all the linked list, always making the node before points to the node after after checking
 and, finally, when finding the node with the element, making the pointer next of node before points
 to the next node of node after and freeing the node after. We return the updated list.
*/
Linkedlist* remove_element_by_value(Linkedlist* list, int value) {
	if(list != NULL) {
		Linkedlist* node_after = list->next;
		if(list->data == value) {
			free(list);
			return node_after;
		}else {
			Linkedlist* node_before = list;
			while(node_after != NULL) {
				if(node_after->data == value) {
					node_before->next = node_after->next;
					free(node_after);
					break;
				}else {
					node_before = node_after;
					node_after = node_after;
				}
			}
		}
	}
	return list;
}

void free_list(Linkedlist* list) {
	Linkedlist* node_after;
	while(list != NULL) {
		node_after = list->next;
		free(list);
		list = node_after;
	}
}
