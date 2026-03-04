//Program to implement circular linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;

node* createNode(int data){
	node* temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}
node* addFirst(node* tail, int value){
	node* newNode = createNode(value);
	if (!tail){
		//tail is empty
		newNode->next = newNode;
		return newNode;
	}
	// tail is not empty
	newNode->next = tail->next;
	tail->next = newNode;
	return tail;
}
node* deleteFirst(node* tail){
	if (tail){
		if (tail->next == tail){
			free(tail);
			return NULL;
		}
		node* temp = tail->next;
		tail->next = temp->next;
		free(temp);
	}
	return tail;
}
node* addLast(node* tail, int value){
	node* newNode = createNode(value);
	if (!tail){
		//tail is empty
		newNode->next = newNode;
		return newNode;
	}
	// tail is not empty
	newNode->next = tail->next;
	tail->next = newNode;
	tail =newNode;
	return tail;
}
void printList(node* tail){
	if (tail){
		printf("\n[");
		for (node* temp = tail->next;temp!=tail; temp = temp->next)
			printf("%d,", temp->data);
		printf("%d]", tail->data);
	}
	else
		printf("\n[]");
}
int main(){
	node* tail = NULL;
	tail = addFirst(tail, 10);
	tail = addFirst(tail, 20);
	tail = addLast(tail, 30);
	printList(tail);
	tail = deleteFirst(tail);
	printList(tail);
	return 0;
}