//header files
#include<stdio.h>
#include<stdlib.h>

#define SIZE 20

//structure creation
struct stack
{
    int  top;
    char a[SIZE];
};


//push function
void fnpush(struct stack *s,char str)
{
    if(s->top==SIZE-1) {
        printf("Stack Overflow.\n"); }
    else {
        s->a[++s->top]=str; }
}

//pop function
char fnpop(struct stack *s)
{
        char ch;
    if(s->top==-1) {
        printf("Stack Underflow.\n");
        return -1; }
    else {
        ch=s->a[s->top--];
        return ch; }
}

//is_empty_stack function
int empty(struct stack *s)
{
    if(s->top==-1) {
        return -1; }
    else {
        return 0; }
}

//condition checking function
int check(struct stack *s,char str[])
{
    int i,j;
    for(i=0;str[i]!='C';i++)
        {
            if(str[i]=='A'||str[i]=='B') {
                fnpush(s,str[i]); }
            else {
                return 0; }
        }
    for(j=i+1;str[j]!='\0';j++)
    {
        if(str[j]==fnpop(s)) {
            continue; }
        else {
            return 0; }
    }
    if(empty(s)) {
        return 1; }
    else {
        return 0; }
}

//driver code
int main()
{
        int x;
        struct stack s;
        char str[20];
        s.top = -1;

   printf("Enter the string: ");
   scanf("%s",str);

        x = check(&s,str);

    if(x==1) {
        printf("It is of the form xCy\n" ); }
    else {
        printf("It is not of the form xCy\n"); }
return 0;
}
