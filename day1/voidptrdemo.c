//Program to demonstrate void*
#include <stdio.h>

int main(){
	int x = 112;
	float f = 67.8;
	double d = 345.46;
	char c = 'A';
	void* ptr;
	ptr = &x;
	printf("%d\n", *(int*)ptr);
	ptr = &c;
	printf("%c\n", *(char*)ptr);
	ptr = &f;
	printf("%g\n", *(float*)ptr);
	ptr = &d;
	printf("%g\n", *(double*)ptr);	
	return 0;
}