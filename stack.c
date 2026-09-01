#include <stdio.h>
#define max 3
int stack[3];
int top=-1;
void push(){
	int i, item;
	if (top==max-1){
		printf("Stack is full");
	}else{
		printf ("Enter item: ");
		scanf ("%d", &item);
		top=top+1;
		stack[top]=item;
		}
	}
void pop(){
	int item;
	if (top==-1){
		printf ("Stack is empty");
	}else{
		item=stack[top];
		top=top-1;
		printf ("Item popped: %d",item);
	}
}
void display(){
	int i;
	if(top==-1){
		printf("Stack is empty");
	}else{
		printf ("The status of stack now:\n");
		for(i=top;i>=0;i--){
			printf ("%d ",stack[i]);
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
				push();
				break;
			case 2:
				pop();
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
