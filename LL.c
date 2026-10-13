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
void ins_end(){
	node *new_node, *temp;
	int item;
	printf("\nInsert element:\n");
	scanf("%d", &item);
	if(head==NULL){
		head=(node*)malloc(sizeof(node));
		head->data=item;
		head->ptr=NULL;
	}else{
		temp=head;
		while(temp->ptr!=NULL){
			temp=temp->ptr;
		}
		new_node=(node*)malloc(sizeof(node));
		new_node->data=item;
		new_node->ptr=NULL;
		temp->ptr=new_node;
	}
}
void ins_any(){
	node *new_node, *temp;
	int item,k,pos;
	printf("\nEnter position: ");
	scanf("%d",&pos);
	printf("\nInsert element:\n");
	scanf("%d", &item);
	temp=head;
	for(k=1;k<pos-1;k++){
		temp=temp->ptr;
		if(temp==NULL){
			printf("\nNodes in the list are less than count\n");
		}
	}
	new_node=(node*)malloc(sizeof(node));
	new_node->data=item;
	new_node->ptr=temp->ptr;
	temp->ptr=new_node;
}
void count(){
	node *temp;
	int c=0;
	temp=head;
	while(temp!=NULL){
		c=c+1;
		temp=temp->ptr;
	}
	printf("\nNo. of nodes= %d",c);
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
				ins_end();
				break;
			case 3:
				ins_any();
				break;
			case 4:
				display();
				break;
			case 5:
				count();
				break;
			case 6:
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
