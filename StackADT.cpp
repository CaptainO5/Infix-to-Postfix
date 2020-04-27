#include"Stack.h"

stack::stack() {
	top = NULL;
}

bool stack :: isEmpty() {
	if(top == NULL)
		return true;
	else
		return false;
}

int stack :: push(char data) {
	struct node * newNode = (struct node *) malloc (sizeof(struct node));
	if(!newNode)
		return 1;
		
	newNode -> data = data;
	newNode -> next = top;
	top = newNode;
		
	return 0;	
}

int stack :: pop(char * data) {
	if(isEmpty())
		return 1;
		
	struct node * temp = top;
	* data = top -> data;
	top = top -> next;
	free(temp);
	return 0;
}

int stack :: peek(char * data) {
	if(isEmpty())
		return 1;
	* data = top -> data;
	return 0;
}
