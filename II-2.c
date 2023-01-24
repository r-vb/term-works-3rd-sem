//header file(s)
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define SIZE 40

//fn. prototypes.
int pop();
void push(int);

char postfix[SIZE];
int stack[SIZE], top = -1;

//driver code
int main()
{
	    int i, a, b, result, expr;
	    char ch;
	for(i=0; i<SIZE; i++)
	{
		stack[i] = -1;
	}
	printf("\nEnter a postfix expression to evaluate: ");
	scanf("%s",postfix);
	for(i=0; postfix[i] != '\0'; i++)
	{
		ch = postfix[i];
		if(isdigit(ch))
		{
			push(ch-'0');
		}
		else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			b = pop();
			a = pop();
			
			switch(ch)
			{
				case '+': result = a+b;
					  break;
				case '-': result = a-b;
					  break;
				case '*': result = a*b;
					  break;
				case '/': result = a/b;
					  break;
				case '%':result = a%b;
					  break;
			}
			push(result);
		}		
	}
	expr = pop();
	printf("\nThe postfix evaluation is: %d\n",expr);
	return 0;
}

//push function
void push(int n)
{
	if (top < SIZE -1)
	{
		stack[++top] = n;
	}
	else
	{
		printf("Stack Overflow!\n");
		exit(-1);
	}
}

//pop function
int pop()
{	
	int n;
	if (top > -1)
	{
		n = stack[top];
		stack[top--] = -1;
		return n;
	}
	else
	{
		printf("Stack Underflow!\n");
		exit(-1);
	}
}	