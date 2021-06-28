#include<stdio.h>
#include "header.h"
int add(int a,int b)
{
	return a+b;
}
int main()
{
int (*fun_pointer)(int,int);
fun_pointer=&add;
printf("%d\n",(*fun_pointer)(10,20));
printf("%d\n",mul(10,20));
printf("%d\n",div(20,10));
div(20,10);
	return 0;
}
