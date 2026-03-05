//Program to demonstrate the stack
#include <stdio.h>
#include <stdlib.h>
typedef enum Boolean {false, true} boolean;
//typedef enum Boolean { true=1, false=0} boolean;
typedef struct Book{
	int id;
	char title[30];
	double price;
}book;
typedef struct Stack{
	int capacity;
	int size;
	book *books;
}stack;
stack* createStack(int max){
	stack* temp = (stack*)malloc(sizeof(stack));
	temp->capacity = max;
	temp->size = -1;
	temp->books = (book *)malloc(sizeof(book)*max);
	return temp;
}
boolean isFull(stack *st){
//	if (st->size+1 == st->capacity )
//		return true;
//	return false;
	return st->size+1 == st->capacity;
}
boolean isEmpty(stack *st){
	return st->size == -1;
}
boolean push(stack *st, book b){
	if (isFull(st))
		return false;
//	st->size++;
//	st->books[st->size] = b;
	st->books[++st->size] = b;
	return true;
}

book* pop(stack *st){
	if (isEmpty(st))
		return NULL;
	return &st->books[(st->size)--];
}

book* peek(stack *st){
	if (isEmpty(st))
		return NULL;
	return &st->books[st->size];
}
int stackSize(stack *st){
	return st->size +1;
}
void printMenu(){
	printf("\nStack operations demo\n");
	printf("*********************\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Peek\n");
	printf("4. Stack Size\n");
	printf("5. Exit\n");
	printf("Enter your choice : ");
}
book getBook(){
	book b;
	printf("Book Id: ");
	scanf("%d", &b.id);
	printf("Book Title : ");
	scanf("\n%[^\n]s", b.title);
	printf("Book Price : ");
	scanf("%lf", &b.price);
	return b;
}
void printBook(book b){
	printf("\nBook Id : %d\n", b.id);
	printf("Book Title : %s\n", b.title);
	printf("Book Price : %.2lf", b.price);
}

int main(){
	stack *myStack = NULL;
	int size;
	scanf("%d", &size);
	myStack = createStack(size);
	while(true){
		printMenu();
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 1:
				if (!isFull(myStack) && push(myStack, getBook()))
					printf("Pushed....\n");
				else
					printf("Stack overflow....\n");
				break;
			case 2:{
				book *b = pop(myStack);
				if (b){ // b is not empty
					printBook(*b);
				}
				else
					printf("Stack underflow....\n");
				break;
			}
			case 3:{
				book *b = peek(myStack);
				if (b){ // b is not empty
					printBook(*b);
				}
				else
					printf("Stack underflow....\n");
				break;
			}
			case 4:
				printf("Stack Size : %d\n", stackSize(myStack));
				break;
			default:
				printf("Thank you so much for being very very silent in the class...\n");
				exit(0);				
		}
	}
	
	return 0;
}