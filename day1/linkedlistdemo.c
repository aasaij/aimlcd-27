//Program to implement singly linked list
#include <stdio.h>
#include <stdlib.h>
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

int main(){
//	node* x = createNode("Karutha Machan");
//	node* y = createNode("Thalapathy Kacheri");
//	node* z  = createNode("Alapara");
//	x->nextSong = y;
//	y->songName = z;
	node* x = createNode("Karutha Machan");
	x->nextSong = createNode("Thalapathy Kacheri");
	x->nextSong->nextSong  = createNode("Alapara");

	return 0;
}