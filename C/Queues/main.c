#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
	Queue* q = create_queue();
	
	if(q == NULL) {
		printf("Oh no...\n");
	}else {
		printf("Oh yeahh...\n");
		
		if(is_empty(q)) {
			printf("\nQueue is empty!\n");
		}else {
			printf("\nQueue is not empty!\n");
		}
		
		int i;
		for(i = 0; i <= 10; i++) {
			q = push(q, i);
		}
		
		q = pop(q);
		q = pop(q);
		q = pop(q);
		
		print(q);
		
		if(is_empty(q)) {
			printf("\nQueue is empty!\n");
		}else {
			printf("\nQueue is not empty!\n");
		}
		
		free_queue(q);	
	}
	return 0;
}
