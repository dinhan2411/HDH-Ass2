#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if(q->size >= 10)
		return ;
	else{
		q->proc[q->size]=proc;
		q->size ++;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	unsigned int highest_prioprity = -1;
	int highest_prioprity_index=0;
	for (int i = 0; i < q->size; ++i)
	{
		unsigned int prioprity_i=q->proc[i]->prioprity;
		if(prioprity_i > highest_prioprity){
			highest_prioprity=prioprity_i;
			highest_prioprity_index= i;
		}
	}
	struct pcb_t * pcb_highest_prioprity = q->proc[highest_prioprity_index];
	q->size --;
	for (int i = highest_prioprity_index; i < q->size; ++i)
	{
		q->proc[i] = q->proc [i+1];
	}
	return pcb_highest_prioprity;
}

