#include <stdio.h>
#include <malloc.h>
struct node{
	int data;
	struct node *ptr;
};
typedef struct node node;
node *first, *last;
void ins_beg(){
	node *new_node;
	int item;
	printf("\nInsert element:\n");
	scanf("%d", &item);
	new_node=(node*)malloc(sizeof(node));
	new_node->data=item;
	new_node->ptr=first;
	last->ptr=new_node;
	first=new_node;
}
void ins_end(){
	node *new_node;
	int item;
	printf("\nInsert element:\n");
	scanf("%d", &item);
	if(first==NULL){
		first=(node*)malloc(sizeof(node));
		first->data=item;
		first->ptr=first;
	    last=first;
	}else{
		new_node=(node*)malloc(sizeof(node));
		new_node->data=item;
		new_node->ptr=first;
		last->ptr=new_node;
		last=new_node;
	}
}
void display(){
	node *temp;
	temp=first;
	do{
		printf("%d\t",temp->data);
		temp=temp->ptr;
	}while(temp!=first);
}
void del_beg(){
	node *temp;
	if(first==NULL){
		printf("empty list");
	}else if(first==last){
		free(first);
		free(last);
		first=last=NULL;
	}else{
		temp=first;
		first=first->ptr;
		last->ptr=first;
		free(temp);
	}
}
void del_end(){
	node *temp1;
	temp1=first;
	while(temp1->ptr!=last){
		temp1=temp1->ptr;
	}
	temp1->ptr=first;
	free(last);
	last=temp1;
}
int main(){
	int choice, flag=1;
	first= (node*)malloc(sizeof(node));
	first->data=10;
	first->ptr=first;
	last=first;
	printf ("%d",first->data);
	while (flag){
		printf("\nUser choice: ");
	    scanf("%d", &choice);
		switch (choice){
			case 1:
				ins_beg();
				break;
			case 2:
				ins_end();
				break;
			case 3:
				display();
				break;
			case 4:
				del_beg();
				break;
			case 5:
				del_end();
				break;
			default:
				printf("\nInvalid");
				break;
		}
		printf("\nDo you want to continue? 1/0\n");
		scanf ("%d", &flag);
	}
	return 0;
}

