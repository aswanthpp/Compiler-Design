// Testcase to check scope of a variable

#include <stdio.h>
void main()
{
    int a = 10, b = 5;

    {
        printf("Enter a variable");
        int b;
        scanf("%d",&b);
    }
}