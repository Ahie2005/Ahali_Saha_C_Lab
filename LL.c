#include <stdio.h>
#include <malloc.h>
struct node{
	int data;
	struct node *ptr;
};
typedef struct node node;
node *head;
void ins_beg(){
	node *new_node;
	int item;
	printf("\nInsert element:\n");
	scanf("%d", &item);
	new_node=(node*)malloc(sizeof(node));
	new_node->data=item;
	new_node->ptr=head;
	head=new_node;
}
void display(){
	node *temp;
	temp=head;
	while (temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->ptr;
	}
}
int main(){
	int choice, flag=1;
	head= (node*)malloc(sizeof(node));
	head->data=10;
	head->ptr=NULL;
	while (flag){
		printf("\nUser choice: ");
	    scanf("%d", &choice);
		switch (choice){
			case 1:
				ins_beg();
				break;
			case 2:
				display();
				break;
			case 3:
				flag=0;
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
