#include <stdio.h>
#define max 3
int queue[3];
int front=-1;
int rear=-1;
void insert(){
	int i, item;
	if (rear==max-1){
		printf ("Queue is full");
	}else{
		printf("Enter item: ");
		scanf ("%d", &item);
		rear=rear+1;
		queue[rear]=item;
		if (front==-1){
			front=0;
		}
	}
}
void delete(){
	int item;
	if (front==-1){
		printf ("Stack is empty");
	}else{
		item=queue[front];
		if(front==rear){
			front=rear=-1;
		}else{
			front=front+1;
		}
		printf ("Item popped: %d",item);
	}
}
void display(){
	int i;
	if (front==-1){
		printf("\nQueue is empty");
	}else{
		printf("\nThe elements are:\n");
		for(i=front;i<=rear;i++){
			printf("%d ", queue[i]);
		}
	}
}
int main(){
	int choice, flag=1;
	while (flag){
		printf("User choice: ");
	    scanf("%d", &choice);
		switch (choice){
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				flag=0;
				break;
			default:
				printf("Invalid");
				break;
		}
		printf("\nDo you want to continue? 1/0\n");
		scanf ("%d", &flag);
	}
	return 0;
}
