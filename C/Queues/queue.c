#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node {
	int data;
	Node* next;
};

struct queue {
	Node* begin;
	Node* end;
};

Queue* create_queue() {
	Queue* q = (Queue*) malloc(sizeof(Queue));
	if(q == NULL) {
		printf("\nInsuficient memory!\n");
		exit(1);
	}else {
		q->begin = NULL;
		q->end = NULL;
		
		return q;
	}
}

int is_empty(Queue* q) {
	return ((q->begin == NULL) && (q->end == NULL));
}

Queue* push(Queue* q, int value) {
	Node* node = (Node*) malloc(sizeof(Node));
	Node* node_end = q->end;
	
	if(node == NULL) {
		printf("\nInsuficient memory to allocate more nodes!\n");
	}else {
		node->data = value;
	
		if((q->begin == NULL) && (q->end == NULL)) {
			q->begin = node;
			node->next = q->end;
			q->end = node;
		}else {
			node->next = node_end->next;
			node_end->next = node;
			q->end = node;
		}
	}
	
	return q;
}

Queue* pop(Queue* q) {
	if((q->begin == NULL) && (q->end == NULL)) {
		printf("\nQueue is already empty!\n");
	}else {
		Node* node = q->begin;
		q->begin = node->next;
		free(node);
	}
	
	return q;
}

void print(Queue* q) {
	if(!is_empty(q)) {
		Node* node = q->begin;
		int i = 1;
		while(node != NULL) {
			printf("\n|Node %d: %d |\n", i, node->data);
			node = node->next;
			i++;
		}
	}else {
		printf("\nThe queue is empty!\n");
	}
}

void free_queue(Queue* q) {
	if((q->begin == NULL) && (q->end == NULL)) {
		free(q);
	}else {
		Node* node_before = q->begin;
		Node* node_after = node_before->next;
		
		while(node_after != NULL) {
			free(node_before);
			node_before = node_after;
			node_after = node_after->next;
		}
		
		free(q);
	}
}
