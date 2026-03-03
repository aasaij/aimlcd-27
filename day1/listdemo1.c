#include <stdio.h>
#include <string.h>
typedef struct Employee{
	int rollno; // 4
	char name[21]; //30
	double salary; // 8
}emp;

int main(){
	emp *ptr;
	ptr = (emp *)malloc(sizeof(emp));
	ptr->rollno = 1001;
	strcpy(ptr->name,  "Mohit");
	(*ptr).salary = 2000000;
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
