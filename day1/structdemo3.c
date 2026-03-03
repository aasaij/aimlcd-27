#include <stdio.h>
#include <string.h>
typedef struct Employee{
	int rollno; // 4
	char name[21]; //30
	double salary; // 8
}emp;

//typedef struct Employee emp;

int main(){
	emp *ptr;
//	e.rollno = 1001;
//	strcpy(e.name,  "Mohit");
//	e.salary = 2000000;
	ptr->rollno = 1001;
	strcpy(ptr->name,  "Mohit");
	(*ptr).salary = 2000000;

//	printf("%d %d", sizeof(e), sizeof(ptr));
	printf("Employee ID   : %d\n",ptr->rollno);
	printf("Employee Name : %s\n",(*ptr).name);
	printf("Employee Name : %.2lf\n",ptr->salary);
	
	return 0;
}

//DMA
//	malloc()
//			void* malloc(size_t numBytes);
//	callloc()
//	realloc()
//	free()
