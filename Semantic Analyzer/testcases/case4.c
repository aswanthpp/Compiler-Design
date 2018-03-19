//Testcase to check scope of variables
#include<stdio.h>	
int func(){
	int a;
}
int main()
{	
	int a;
	{
		int a;
	}
	func();
}


