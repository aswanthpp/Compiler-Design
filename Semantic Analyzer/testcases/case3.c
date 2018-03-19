// Testcase to check type mismatch
#include<stdio.h>
int main()
{
	int l=10,a=0,i;
	float l=5.0;
	for(i=0;i<l;i++)
	{
		printf("\nHello World");
	}
	
	
	l = l + 3.14;
	printf("%d",l);	
}
