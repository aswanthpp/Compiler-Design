#include<stdio.h>

void main()
{
 	int a[10],i,j;

 	while(i<10)
 	{
 		scanf("%d",&a[i]);
 	}

	for(i=0;i<10;i++)
 	{
 		for(j=0;j<9-i;j++)
 		{
 			if(a[j]>a[j+1])
 			{
 				swap(&a[j],&a[j+1]);
 			}
 		}
 	}
}

void swap(int *a,int *b)
{
 	*a=*a+*b;
 	*b=*a-*b;
 	*a=*a-*b;
}
