//Program to implement doubly linked list
#include <stdio.h>
#include <stdlib.h>
//defining the node
typedef struct Node{
	struct Node *prev;
	char value;
	struct Node *next;
}node;

node* createNode(char data){
	node* temp = (node*)malloc(sizeof(node));
	temp->value = data;
	temp->next = temp->prev = NULL;
	return temp;
}
node* addFirst(node* root, char data){
	node* newNode = createNode(data);
	if (!root) //root is null
		return newNode;
	//root is not empty		
	newNode->next = root;
	root->prev = newNode;
	root = newNode;
	return root;
}
node* addLast(node* root, char data) {
	node* newNode = createNode(data);
	if (!root) //root is null
		return newNode;
	//root is having elements
	node* temp;
	for (temp = root; temp->next; temp = temp->next);
	temp->next = newNode;
	newNode->prev = temp;
	return root;
}
node* addAt(node* root, char data, int position){
	if (position ==0 || position == 1)	{
		return addFirst(root,data);
	}
	//We are checking the following conditions
	//1. The position should be > 1
	//2. The list should not be empty
	//3. The list should contain atleast two elements
	if (position>1 && root && root->next){
		node* temp=root;
		for (int i = 2; temp->next && i<position; i++)
			temp = temp->next;
		if (temp->next){
			node* newNode = createNode(data);
			newNode->next = temp->next;
			temp->next->prev = newNode;
			temp->next = newNode;
			newNode->prev = temp;
		}
	}
	return root;
}
node* deleteFirst(node* root){
	if (root){
		if (!root->next){ //root is having only one node
			free(root)		;
			return NULL;
		}
		//root is having more then one node 
		node* temp = root;
		root = temp->next;
		root->prev = NULL;
		free(temp);
	}
	return root;
}

node* deleteLast(node* root){
	if (root){//root is not empty
		if (!root->next){ //root is having only one node
			free(root);
			return NULL;
		}
		//root is having more than one node
		node* temp;
		for (temp = root; temp->next->next; temp= temp->next);
		free(temp->next);
		temp->next = NULL;
	}
	return root;
}
//deleteAt(node* list, int position){
//	
//}
void printList(node* root){
	if (root){
		//list is not empty
		printf("\nForward Traversal : [");
		node* temp;
		for (temp = root; temp->next; temp = temp->next){
			printf("'%c',", temp->value);
		}
		printf("\'%c\']", temp->value);
		printf("\nBackward Traversal : [");
		for (; temp->prev; temp = temp->prev){
			printf("'%c',", temp->value);
		}
		printf("\'%c\']", temp->value);		
	}
	else
		printf("\n[]");
}
void printMenu(){
	printf("\nDoubly Linked List Operations Demo\n");
	printf("***************************\n");
	printf("1.Add First\n");
	printf("2. Add Last\n");
	printf("3. Insert At\n");
	printf("4. Delete First\n");
	printf("5. Delete Last\n");
	printf("6. Delete At\n");
	printf("7. Display List\n");
	printf("8. Exit\n");
	printf("Enter your choice : ");
}
int main(){
	node *head = NULL;
	while(1){
		printMenu();
		int choice;
		scanf("%d", &choice);
		char data;		
		int position;
		switch(choice){
			case 1: //add first
				scanf("\n%c", &data);
				head = addFirst(head, data);
				break;
			case 2: //add last
				scanf("\n%c", &data);
				head = addLast(head, data);
				break;				
			case 3: // add at
				scanf("\n%c %d", &data, &position);
				head = addAt(head, data, position);
				break;
			case 4: // delete first
				head = deleteFirst(head);
				break;
			case 5: // delete last
				head = deleteLast(head);
				break;
			case 6: /// delete at
				break;
			case 7: //print list
				printList(head);
				break;
			default:
				printf("Thank you so much for being very very interactive in the class!..");
				exit(0);
		}
	}
	return 0;
}