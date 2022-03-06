#include <stdio.h>
#include <stdlib.h>
#define MAX 50
struct stack
{
    int tos;
    int elem[MAX];
}s;
int empty()
{
    if(s.tos==-1)
        return 1;
    else
        return 0;
}
int full()
{
    if(s.tos==MAX-1)
        return 1;
    else
        return 0;
}
void push(int x)
{
    if(full())
        printf("\nStack is Full\n\aTry popping some elements out of the stack using choice 2)pop .\n");
    else
        s.elem[++s.tos]=x;
}

int pop()
{
    if(empty())
        return -1;
    else
        return s.elem[s.tos--];
}
int main()
{
    int x,r;
    s.tos=-1;
    printf("Enter the number: ");
    scanf("%d",&x);

    while(x!=0)
    {
        r=x%2;
        push(r);
        x/=2;
    }
    printf("\n\n");
    while(!empty())
    {
        printf("%d",pop());

    }
}
