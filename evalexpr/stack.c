#include "stack.h"

int MAXSIZE = 1024;       
int stack[MAXSIZE];  
int top = -1;            

int isempty()
{

   if(top == -1)
	return 1;
   else
	return 0;
}
   
int isfull()
{

   if(top == MAXSIZE)
	return 1;
   else
	return 0;
}

int     peek()
{
   return stack[top];
}

int pop()
{
   int data;
	
   if(!isempty()) {
	data = stack[top];
	top = top - 1;   
	return data;
   }
}

int push(int data)
{
   if(!isfull()) {
	top = top + 1;   
	stack[top] = data;
   }
}

int   initialize()
{
	int i;

	i = 0;
	while (i < MAXSIZE)
	{
		stack[i] = 0;
		i++;
	}
}