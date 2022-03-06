#include <stdio.h>
#include <ctype.h>
#define MAX 50
struct stack
{
   int tos;
   char elem[MAX];
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
void push(char ch)
{
   if(full())
      printf("\nstack is full");
   else
      s.elem[++s.tos]=ch;
}
char pop()
{
   if(empty())
      return '-1';
   else
      return s.elem[s.tos--];
}
int main()
{
    char str[50],ch;
    printf("Enter the string :");
    gets(str);
    for(int i;str[i]!='\0';i++)
    {
        push(str[i]);
    }
    for(int i=0;!empty();i++)
    {
      str[i]=pop();
    }
    printf("reverse of string is:%s",str);
    return 0;
}

