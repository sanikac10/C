#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define max 50
struct stack
{
    int tos;
    float element[max];
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
    if(s.tos==max-1)
        return 1;
    else
        return 0;
}
void push(float x)
{
    if(full())
        printf("The stack is full\n");
    else
        s.element[++s.tos]=x;
}
float pop()
{
    if(empty())
        return -1;
    else
        return s.element[s.tos--];
}
int main()
{
    s.tos=-1;
    int length=0;
    char cs[50],temp;
    float val,x,op1,op2;
    printf("Enter the prefix expression:-\n");
    scanf("%s",cs);
    for(int i=0;cs[i]!='\0';i++)
    {
        length++;
    }
    for(int i=0;i<length/2;i++)
    {
        temp=cs[i];
        cs[i]=cs[length-1-i];
        cs[length-1-i]=temp;
    }
    printf("\nThe reverse is %s \n",cs);
    for(int i=0;cs[i]!='\0';i++)
    {
        if(cs[i]>='0'&&cs[i]<='9')
        {
            x=cs[i]-48;
            push(x);
        }
        else
        {
            if(cs[i]=='+'||cs[i]=='-'||cs[i]=='*'||cs[i]=='/'||cs[i]=='$')
            {
              op1=pop();
              op2=pop();
              switch(cs[i])
              {
                  case '+':val=op1+op2;
                           push(val);
                           break;
                  case '-':val=op1-op2;
                           push(val);
                           break;
                  case '*':val=op1*op2;
                           push(val);
                           break;
                  case '/':val=op1/op2;
                           push(val);
                           break;
                  case '$':val=pow(op1,op2);
                           push(val);
                           break;
                  default :printf("Invalid input");
              }
            }
        }
    }
    val=pop();
    printf("\nAnswer of the given prefix expression is %f",val);
    return 0;
}

