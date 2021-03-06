#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <string.h>

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if(q->size >= MAX_QUEUE_SIZE)
		return ;
	else{
		// if(q->proc[q->size] == NULL){
		// 	q->proc[q->size]=(struct pcb_t *) malloc(sizeof(struct pcb_t));
		// }
		// // *(q->proc[q->size]) = *proc;
		// memcpy((q->proc[q->size]), proc, sizeof(struct pcb_t));
		q->proc[q->size] = proc;
		q->size ++;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if(q->size == 0) return NULL;
	unsigned int highest_priority = q->proc[0]->priority;
	int highest_priority_index=0;
	for (int i = 0; i < q->size; ++i)
	{
		unsigned int priority_i=q->proc[i]->priority;
		if(priority_i > highest_priority){
			highest_priority=priority_i;
			highest_priority_index= i;
		}
	}
	struct pcb_t * pcb_highest_priority = NULL;
	pcb_highest_priority= (q->proc[highest_priority_index]);
	q->size --;
	for (int i = highest_priority_index; i < MAX_QUEUE_SIZE - 1; i++)
	{
		(q->proc[i]) = (q->proc [i+1]);
	}
	q->proc[MAX_QUEUE_SIZE - 1]=NULL;
	return pcb_highest_priority;
}
