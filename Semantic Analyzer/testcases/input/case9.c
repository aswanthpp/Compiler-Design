//testcase 2 for parse tree

//dangling else error
#include<stdio.h>
#define x 3
int main(int argc,int *argv[])
{
int a=4;
if(a<10)
printf("10");
else
{
if(a<12)
printf("11");
else
printf("All");
else
printf("error");}
}
