#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

void add(struct node* head, int data){
    struct node* newNode =(struct node*) malloc(sizeof(struct node));
    newNode->data  = data;
    newNode->next = NULL;
	
    while(head->next != NULL)
       head = head->next;
    head->next = newNode;
}

void insert(struct node *header,int data)
{
	struct node *temp,*ptr;
	temp = (struct node*) malloc(sizeof(struct node));

	temp->next = header->next;
	header->next = temp;
	temp->data = data;
}

void delete(struct node *header, int key)
{

	struct node *ptr = header->next,*temp;
	temp = header->next;

	if(temp->data == key) {
		header->next = header->next->next;
		return;
	}
	while(ptr!=NULL){
		if(ptr->data == key){
			temp->next=ptr->next;
			free(ptr);
		}
		else{
			temp = ptr;
			ptr = ptr->next;

		}

	}
}

void display(struct node *header)
{
	struct node  *ptr = header->next;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int search(struct node *header, int key)
{
	struct node  *ptr = header->next;
	while(ptr!=NULL){
		if(ptr->data == key){
			return ptr->data;
		}
		ptr = ptr->next;
	}
	return -1;
}

int length(struct node *header)
{
	struct node  *ptr = header->next;
	int count=0;
	while(ptr!=NULL){
		count++;
		ptr = ptr->next;
	}
	return count;
}


