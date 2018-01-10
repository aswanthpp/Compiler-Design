// test case to check scanf and printf errors

#include<stdio.h>
void main()
{
		int a=10;
		printf("\nHello World");
		printf(");
		printf(" value %d",a);
		printf(" value ",);
		
		scanf(" enter value %d",&a);
		scanf(" enter value %d",a);
		scanf(" enter value",);
		scabf(" enter );
}
