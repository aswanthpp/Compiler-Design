// Testcase to check array dimensions

#include <stdio.h>
int main()
{
    int i, arr1[100], arr2[100];
    for(i=0;i<100;i++)
    {
        scanf("%d",&arr1[i]);
        arr2[i] = arr1[i] * 2;
    }

    for(i=0;i<100;i++)
    {
        printf("%d",arr2[i]);
    }
}
