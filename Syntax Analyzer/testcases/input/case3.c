// Testcase to check  looping statements 
#include<stdio.h>
int main(){

	int l=10,a=0,i;
	for(i=0;i<l;i++){
		printf("\nHello World");
	}
	for(;a<l;a++){
		printf("\nComputer Science");
	}
	for(a<l;a++){
		printf("\nInvalid Syntax");
	}

	for(;;a++){
		printf("\nNo Comparison Statement : Error");
	}

	for(a=10;a<20;){
		printf("\nInfinite Loop");
	}
}
