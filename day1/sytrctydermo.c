#include <stdio.h>
#include <string.h>
struct Employee{
	int rollno; // 4
	char name[21]; //30
	double salary; // 8
};

int main(){
	struct Employee e;
	struct Employee *ptr;
//	e.rollno = 1001;
//	strcpy(e.name,  "Mohit");
//	e.salary = 2000000;
	printf("%d %d", sizeof(e), sizeof(ptr));
	return 0;
}