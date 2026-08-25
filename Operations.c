#include <stdio.h>
int main(){
	int n, num, flag=1,sqrt=0,cube=0;
	printf ("1- Enter for odd even check \n2- Enter for positive, negative or zero check \n3- Calculates square of the number \n4- Calculates cube of the number");
	while (flag){
		printf ("\nEnter user choice: ");
		scanf("%d", &n);
		printf ("Enter number: ");
	    scanf ("%d", &num);
		switch(n){
			case 1:
				if(num%2==0){
					printf("\n%d is even", num);
				}else {
					printf("\n%d is odd", num);
				}
				break;
			case 2:
				if(num>0){
					printf("\n%d is positive", num);
				}else if (num<0) {
					printf("\n%d is negative", num);
				}else{
					printf("\n%d is zero", num);
				}
				break;
			case 3:
				sqrt=num*num;
				printf("\nSquare= %d",sqrt);
				break;
			case 4:
				cube=num*num*num;
				printf("\nCube= %d",cube);
				break;
			default:
				printf ("\nInvalid");
				break;
			}
	    printf ("\nDo you want to continue? 1/0\n");
	    scanf ("%d", &flag);
		}
	}
