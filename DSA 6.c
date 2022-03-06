#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define n 20
typedef struct stack
{
    int a[n];
    int top;
}stack;

void push(stack *s,int ele)
{
    s-> top++;
    s-> a[s->top] = ele;
}

int pop(stack *s)
{
    int x;
    x=s->a[s->top];
    s->top--;
    return x;
}

int main()
{
    stack s;
    s.top=-1;
    char postfix [20],x;
    int i,a,b,c;
    printf("\nEnter postfix expression");
    gets(postfix);
    for(i=0;i<strlen(postfix);i++)
    {
        x=postfix[i];
        if(isdigit(x))
        {
            push(&s,(int)x-'0');
        }
        else
        {
            a=pop(&s);
            b=pop(&s);
            if(x=='+')
                c=b+a;
            else if(x=='-')
                c=b-a;
            else if(x=='*')
                c=b*a;
            else
                c=b/a;
            push(&s,c);
        }
    }
    printf("\nResult=%d",pop(&s));
    return 0;
}


