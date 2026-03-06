//Program to implement the circular queue operations
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Employee{
	int id;
	char name[20];
	double salary;
}employee;
typedef struct Queue{
	int capacity;
	int front;
	int rear;
	employee *employees;
}queue;
queue *createQueue(int size){
	queue *temp = (queue*)malloc(sizeof(queue));
	temp->capacity = size;
	temp->rear = -1;
	temp->front =-1;
	temp->employees = (employee*)malloc(sizeof(employee)*size);
	return temp;
}
bool isEmpty(queue* q){
	return q->front == -1 && q->rear == -1;
}

bool isFull(queue *q){
	return q->front == 0 && q->rear+1 == q->capacity ||(q->rear+1==q->front);
}
bool enqueue(queue *q, employee e){
	if (isFull(q))
		return false;
	if (q->front==-1)
		q->front = 0;
//	q->rear++;
//	q->employees[q->rear] = e;
	q->employees[++q->rear] = e;
	return true;
}
employee* dequeue(queue *q){
	if (isEmpty(q))
		return NULL;
	employee *e = &q->employees[q->front];
	if(q->front == q->rear){
		q->front = q->rear = -1;
	}
	else{
		q->front = q->front+1 % q->capacity;
	}
	return e;
}
employee* front(queue *q){
	if (isEmpty(q))
		return NULL;
	return &q->employees[q->front];
}

int queueSize(queue *q){
	if (isEmpty(q))
		return 0;
	return (q->rear - q->front + q->capacity)%q->capacity+1;
}
employee getEmployee(){
	employee e;
	printf("\nEmployee ID : ");
	scanf("%d", &e.id);
	printf("Employee Name : ");
	scanf("\n%[^\n]s", e.name);
	printf("Employee Salary : ");
	scanf("%lf", &e.salary);
	return e;	
}
void printEmployee(employee e){
	printf("\nEmployee ID : %d\n", e.id);
	printf("Employee Name : %s\n", e.name);
	printf("Employee Salary : %.2lf\n", e.salary);		
}

void printMenu(){
	printf("\nCircular Queue demo applicaiton\n");
	printf("*******************************\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Display front\n");
	printf("4. Queue Size\n");
	printf("5. Exit\n");
	printf("Enter your choice : ");
}

int main(){
	queue *myQueue = NULL;
	int size;
	scanf("%d", &size);
	myQueue = createQueue(size);
	while(true){
		printMenu();
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 1:
				if (!isEmpty(myQueue) && enqueue(myQueue, getEmployee()))
					printf("Enqueued...\n");
				else
					printf("Queue is full!\n");
				break;
			case 2:{
				employee *e = dequeue(myQueue);
				if (e)
					printEmployee(*e);
				else
					printf("Queue is empty...\n");
				break;
			}
			case 3:{
				employee *e = front(myQueue);
				if (e)
					printEmployee(*e);
				else
					printf("Queue is empty...\n");
				break;
			}
			case 4:
				printf("Queue Size : %d\n", queueSize(myQueue));
				break;
			default:
				printf("Thank you so much for being very cooperative in the class\n");
				exit(0)			;
		}
	}
	
	return 0;
}
