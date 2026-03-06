//Program to implement linear search algorithm

#include <stdio.h>
#include<string.h>
#include <stdlib.h>
int binarySearch(int n, char names[n][20], char str[]){
	int lower = 0, upper = n-1;
	while(lower<=upper){
		int middle = (lower+upper)/2;
		int diff = strcmp(names[middle],str);
		if (!diff)
			return middle;
		else if (diff>0)
			upper = middle -1;
		else
			lower = middle+1;
	}
	return -1;
}
int compare (const void* x, const void *y){
	return strcmp( (char*)x, (char*)y);
}

int main(){
	char nameList[][20] = {"Anirudh","Nagesh", "Vijay", "Banu", "Balaji", "Guna", "Samy", "Dumpala Teja"};
	char searchName[20];	
	int n = sizeof(nameList)/sizeof(nameList[0]);
	scanf("%s", searchName);
	qsort(nameList, n, sizeof(nameList[0]), compare);
	if (binarySearch(n,nameList, searchName)!=-1)
		printf("Found");
	else
		printf("Not Found");
	return 0;
}