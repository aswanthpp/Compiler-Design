// Testcase to check type mismatch
#include<stdio.h>
int main()
{
	int l=10,a=0,i;
	for(i=0;i<l;i++)
	{
		printf("\nHello World");
	}
	
	float l=5.0;
	l = l + 3.14;
	printf("%d",l);	
}
