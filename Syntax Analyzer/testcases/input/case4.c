//Testcase to check function decleration and parameter passing

#include<stdio.h>
int main(){
	
	int a[]={1,2,3,4};
	function1();
	int c=function2(3,4);
	int s=function3(a,4);
	int e=function3(); //should display error


}
void function1(){
	printf("\nHello World");
}
int function2(int a,int b){
	a=a+b;
	return a;
}
int function3(int a[],int b){
	int s=0;
	for(int i=0;i<b;i++){
		s+=a[i];
	}
	return s;
}