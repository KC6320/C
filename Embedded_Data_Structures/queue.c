/*
    Circular queue implementation and operations using array
*/
#include <stdlib.h>
#include <stdio.h>


struct Queue
{
	int size;
	int front;
	int rear;
	int *q;
};

void display(struct Queue q)
{
	int i = q.front +1 ;

	do
	{
		printf("%d ", q.q[i]);
		i = (i+1)%q.size;
	}while(i != (q.rear+1)% q.size);
}

int is_empty(struct Queue q)
{
	if (q.rear == q.front)
	{
		return 1;
	}

	return 0;
}

int is_full(struct Queue q)
{
	if ((q.rear+1)%q.size == q.front)
	{
		return 1;
	}

	return 0;
}

void enqueue(struct Queue * q, int val)
{
	if (is_full(*q))
	{
		printf("%s\n","Queue is full");
	}
	else
	{
		q->rear = (q->rear +1) % q->size;
		q->q[q->rear] = val;
	}
}

int dequeue(struct Queue * q)
{
	if (is_empty(*q))
	{
		printf("%s\n","Queue is empty");
	}
	else
	{
		q->front = (q->front +1) % q->size;
		return q->q[q->front];
	}

	return -1;
}

int main()
{
	struct Queue queue;
	queue.size = 5;
	queue.front = 0;  //index
	queue.rear = 0;	  //index
	queue.q = (int *)malloc(queue.size*sizeof(int));

	dequeue(&queue);
	enqueue(&queue, 1);
	enqueue(&queue, 2);
	enqueue(&queue, 3);
	enqueue(&queue, 4);
	enqueue(&queue, 5);
	display(queue);
	dequeue(&queue);
	dequeue(&queue);
	dequeue(&queue);
	dequeue(&queue);
	dequeue(&queue);
	return 0;
}