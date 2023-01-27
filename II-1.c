#include<stdio.h>
#include<stdlib.h>

#define SIZE 20

struct stack
{
    int  top;
    char a[SIZE];
};

void fnpush(struct stack *s,char str)
{
    if(s->top==SIZE-1)
    {
        printf("Stack Overflow.\n");
    }
    else
    {
        s->a[++s->top]=str;
    }
}

char fnpop(struct stack *s)
{
        char ch;
    if(s->top==-1)
    {
        printf("Stack Underflow.\n");
        return -1;
    }
    else
    {
        ch=s->a[s->top--];
        return ch;
    }
}

int empty(struct stack *s)
{
    if(s->top==-1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int check(struct stack *s,char str[])
{
    int i,j;
    for(i=0;str[i]!='C';i++)
        {
            if(str[i]=='A'||str[i]=='B')
            {
                fnpush(s,str[i]);
            }
            else
            {
                return 0;
            }
        }
    for(j=i+1;str[j]!='\0';j++)
    {
        if(str[j]==fnpop(s))
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    if(empty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
        int x;
        struct stack s;
        char str[20];
        s.top = -1;

   printf("Enter the string: ");
   scanf("%s",str);

        x = check(&s,str);

    if(x==1)
    {
        printf("It is of the form xCy\n" );
    }
    else
    {
        printf("It is not of the form xCy\n");
    }
return 0;
}