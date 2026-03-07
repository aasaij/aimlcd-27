#include <stdio.h>
#include <string.h>

void selectionSort(int n, char names[n][20]){
	for(int i = 0; i<n; i++)
	{
		int index = i;
		for(int j=i+1;j<n;j++)
		{
			if(strcmp(names[index],names[j])>0)
			{
				index = j;
			}
		}
		if(index != i)
		{
			char temp[20];
			strcpy(temp,names[i]);
			strcpy(names[i],names[index]);
			strcpy(names[index],temp);
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
	selectionSort(size, names);
	printArray(size, names);
	return 0;
}