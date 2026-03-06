//Program to implement linear search algorithm

#include <stdio.h>
#include<string.h>
int linearSearch(int n, char names[n][20], char str[]){
	for (int i = 0;i<n; i++ ){
		if (!strcmp(names[i],str))
			return i;			
	}
	return -1;
}

int main(){
	char nameList[][20] = {"Anirudh","Nagesh", "Vijay", "Banu", "Balaji", "Guna", "Samy", "Dumpala Teja"};
	char searchName[20];
	int n = sizeof(nameList)/sizeof(nameList[0]);
	scanf("%s", searchName);
	if (linearSearch(n,nameList, searchName)!=-1)
		printf("Found");
	else
		printf("Not Found");
	return 0;
}