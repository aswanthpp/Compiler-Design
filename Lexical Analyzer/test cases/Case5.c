// test case to check control and looping statements

#include<stdio.h>
void main()
{
	int a=1,b=2,c=10;
	
	if(a>b){
		printf("\nInside if");
	}
	else{
		printf("\nInside else");	
	}
	
	if(b>a){
		if(b<c){
			printf("\nNested if ");
		}
	}
	for(int i=1;i<=10;i++){
		printf("\nIteration %d",i);
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<20;j++){
		 	printf("\nNested loop ");
		 }
	}
	
}	
