//Program to implement insertion sort algorithm
#include <stdio.h>
void insertionSort(int a[], int n){
	for (int i = 1;i<n; i++){
		int key = a[i];
		int j = i-1;
		while(j>=0 && key < a[j]){
			a[j+1] = a[j];
			j--;
		}
		a[j+1]=key;
	}
}
void printArray(int a[], int n){
	printf("\n[");
	for (int i =0; i<n-1; i++)
		printf("%d,", a[i]);
	printf("%d]", a[n-1]);
}

int main(){
	int arr[] = {9, 4, 7,3,3,4,23,1};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	insertionSort(arr, arrSize);
	printArray(arr, arrSize);
	return 0;	
}