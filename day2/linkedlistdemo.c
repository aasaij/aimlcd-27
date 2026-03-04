//Program to implement singly linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//defining the node
typedef struct Node{
	char songName[30];
	struct Node *nextSong;
}node;

node* createNode(char song[]){
	node* temp = (node*)malloc(sizeof(node));
	strcpy(temp->songName, song);
	temp->nextSong = NULL;
	return temp;
}
node* addFirst(node* list, char song[]){
	node* newNode = createNode(song);
	newNode->nextSong = list;
	list= newNode;
	return list;
}
node* addLast(node* list, char song[]){
	node* newNode = createNode(song);
	if (list){
		//list is not empty
		node* temp;
		for (temp = list;temp->nextSong;temp=temp->nextSong);
		temp->nextSong = newNode;
		return list;
	}
	else{
		return newNode;
	}
}
node* addAt(node* list, char song[], int position){
	if (position ==0 || position == 1)	{
		return addFirst(list,song);
	}
	//We are checking the following conditions
	//1. The position should be > 1
	//2. The list should not be empty
	//3. The list should contain atleast two elements
	if (position>1 && list && list->nextSong){
		node* temp=list;
		for (int i = 2; temp->nextSong && i<position; i++)
			temp = temp->nextSong;
		if (temp->nextSong){
			node* newNode = createNode(song);
			newNode->nextSong = temp->nextSong;
			temp->nextSong = newNode;
		}
	}
	return list;
}
node* deleteFirst(node* list){
	if (list){
		//list is not empty
		node* temp = list;
		list=temp->nextSong;
		free(temp);
	}
	return list;
}
node* deleteLast(node* list){
	if (list){
		//list is not empty
		if (!list->nextSong){
			//list contains only one element
			free(list);
			return NULL;
		}
		node* temp;
		for (temp = list; temp->nextSong->nextSong; temp= temp->nextSong);
		free(temp->nextSong);
		temp->nextSong = NULL;
	}
	return list;
}
//deleteAt(node* list, int position){
//	
//}
void printList(node* list){
	if (list){
		//list is not empty
		printf("\n[");
		node* temp;
		for (temp = list; temp->nextSong; temp = temp->nextSong){
			printf("\"%s\",", temp->songName);
		}
			printf("\"%s\"]", temp->songName);
	}
	else
		printf("\n[]");
}
void printReverse(node* list){
	if (list){
		printReverse(list->nextSong);
		printf("\"%s\" ", list->songName);
	}
}
void printMenu(){
	printf("\nLinked List Operations Demo\n");
	printf("***************************\n");
	printf("1.Add First\n");
	printf("2. Add Last\n");
	printf("3. Insert At\n");
	printf("4. Delete First\n");
	printf("5. Delete Last\n");
	printf("6. Delete At\n");
	printf("7. Display List\n");
	printf("8. Reverse the List\n");
	printf("9. Exit\n");
	printf("Enter your choice : ");
}
int main(){
	node *playList = NULL;
	while(1){
		printMenu();
		int choice;
		scanf("%d", &choice);
		char songName[30];		
		int position;
		switch(choice){
			case 1: //add first
				scanf("%s", songName);
				playList = addFirst(playList, songName);
				break;
			case 2: //add last
				scanf("%s", songName);
				playList = addLast(playList, songName);
				break;				
			case 3: // add at
				scanf("%s %d", songName, &position)		;
				playList = addAt(playList, songName, position);
				break;
			case 4: // delete first
				playList = deleteFirst(playList);
				break;
			case 5: // delete last
				playList = deleteLast(playList);
				break;
			case 6: /// delete at
				break;
			case 7: //print list
				printList(playList);
				break;
			case 8: //reverse list
				printReverse(playList);
				break;
			default:
				printf("Thank you so much for being very very interactive in the class!..");
				return 0; //exit(0);
		}
	}
	return 0;
}