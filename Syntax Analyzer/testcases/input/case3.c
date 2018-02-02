// Testcase to check  looping statements 
#include<stdio.h>
int main(){

	int l=10,a=0;
	for(int i=0;i<l;i++){
		printf("\nHello World");
	}
	for(;a<l;a++){
		printf("\nComputer Science");
	}
	for(a<l;a++){
		printf("\nInvalid Syntax");
	}

	for(;;a++){
		printf("\nNIT K surathkal")
	}

	for(a=10;a<20;){
		printf("\nCompiler Design");
	}
}