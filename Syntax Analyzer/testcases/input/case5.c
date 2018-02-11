//Testcase to check printf and scanf errors
#include<stdio.h>
int main(){
	int a=10;

	printf("\nHello world");
	printf("%d",a);
	printf("hello",);
	printf("%d");

	scanf("%d",&a);
	scanf("%d",a);
	scanf("%d",);
	
}
