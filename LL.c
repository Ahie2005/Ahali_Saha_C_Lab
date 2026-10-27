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
void del_beg(){
	node *temp;
	if(head==NULL){
		printf("empty list");
	}else{
		temp=head;
		head=head->ptr;
		free(temp);
	}
}
void del_end(){
	node *temp1, *temp2;
	temp2=head;
	while(temp2->ptr!=NULL){
		temp1=temp2;
		temp2=temp2->ptr;
	}
	free(temp2);
	if(temp1!=NULL){
		temp1->ptr=NULL;
	}else{
		head=NULL;
	}
}
void del_any(){
	node *temp1, *temp2;
	int item;
	printf("Enter item to be deleted: ");
	scanf("%d",&item);
	temp2=head;
	temp1=temp2;
	while (temp2!=NULL){
		if(temp2->data==item){
			temp1->ptr=temp2->ptr;
			free(temp2);
			break;
		}
	temp1=temp2;
	temp2=temp2->ptr;
	}
}
void reverse_print(){
	node *p,*q;
	p=NULL;
	while(p!=head){
		q=head;
		while(q->ptr!=p){
			q=q->ptr;
		}
	printf("%d\t",q->data);
	p=q;
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
				del_beg();
				break;
			case 7:
				del_end();
				break;
			case 8:
				del_any();
				break;
			case 9:
				reverse_print();
				break;
			case 10:
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
