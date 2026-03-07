//Program to implement bubble sort algorithm
#include <stdio.h>
#include <string.h>
void bubbleSort(int n, char names[n][20]){
	for (int i =1; i<=n-1;i++){
		for (int j =0; j<n-i;j++){
			if (strcmp(names[j], names[j+1])>0){
				char temp[20];
				strcpy(temp,names[j]);
				strcpy(names[j],names[j+1]);
				strcpy(names[j+1], temp);
			}
		}		
	}
}
void printArray(int n, char names[n][20]){
	printf("\n[");
	for (int i =0; i<n-1; i++)
		printf("\"%s\",", names[i]);
	printf("\"%s\"]", names[n-1]);		
}

int main(){
	char names[][20] = {"Banu","banu","Aasai","Cheran", "Balaji", "Rajesh", "Ramesh", "Vijay", "Dhanesh", "Jahnavi", "Yamini"};
	int size = sizeof(names)/sizeof(names[0]);
	bubbleSort(size, names);
	printArray(size, names);
	return 0;
}