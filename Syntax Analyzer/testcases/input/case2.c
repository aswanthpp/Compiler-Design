// Testcase to check control statements 

#include<stdio.h>
int main(){
	int a=10,b=50,c=10;
	if(a>b){
		printf("\na is greater than b");
	}
	else{
		printf("\n a is smaller than b");
	}
	else{
		printf("\nUnbalanced Else");
	}

	if(a>b && b<c){
		if(a!=c){
			printf("\nHello world");
		}
	    else{
	    	printf("\nComputer Science");
	    }
	 }



}