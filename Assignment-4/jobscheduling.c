
#include<stdio.h>
#include<stdlib.h>

struct queue{
	int arr[5];
	int size;
	int f,r;
};

void enqueue(struct queue *Q, int element)
{
	if(Q->f==-1 && Q->r==-1)
	{
		Q->f=0;
		Q->r=0;
		Q->arr[Q->r]=element;
	}
	else if((Q->r+1)%Q->size==Q->f)
	{
		printf("Queue is overflow..");
	}
	else
	{
		Q->r=(Q->r+1)%Q->size;
		Q->arr[Q->r]=element;
	}
}


void dequeue(struct queue *Q)
{
	if((Q->f==-1) && (Q->r==-1))
	{
		printf("\nfill");
	}
	else if(Q->f==Q->r)
	{
		printf("\ndequeued element is %d", Q->arr[Q->f]);
		Q->f=-1;
		Q->r=-1;
	}
	else
	{
		printf("\ndequeued element is %d", Q->arr[Q->f]);
		Q->f=(Q->f+1)%Q->size;
	}
}


void display(struct queue *Q)
{
	int i=Q->f+1;
	if(Q->f==-1 && Q->r==-1)
	{
		printf("\n Queue is empty..");
	}
	else
	{
		printf("\nJob in a Queue are :");
		while(i!=Q->r)
		{
			printf("%d ", Q->arr[i]);
			i=(i+1)%Q->size;
		}
	}
}

int main(){
	struct queue *Q=(struct queue *) malloc(sizeof(struct queue));
	printf("\n");
	printf("\n");
	Q->size = 5;
	printf("Inserting : ");
	enqueue(Q,1);
	enqueue(Q,2);
	enqueue(Q,3);
	enqueue(Q,4);
	enqueue(Q,5);
	enqueue(Q,6);
	display(Q);
	display(Q);
	return 0;
}
