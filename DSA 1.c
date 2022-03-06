#include <stdio.h>
#define MAX 50
struct stack{
    int tos;
    int elem[MAX];
}s;
int empty(){
    if(s.tos==-1)
     return 1;
     else
      return 0;
}
int full(){
    if(s.tos==MAX-1)
      return 1;
      else
       return 0;
}
void push(int x)
{
    if(full())
     printf("The stack is full");
    else
     s.elem[++s.tos]=x;
}
int pop(){
    if(empty())
     return -2;
    else
     return s.elem[s.tos--];
}
void show(){
    int i;
    if(empty())
    printf("the stack is empty");
    else
    {
        for(i=0;i<=s.tos;i++){
            printf("%d\t",s.elem[i]);
        }
    }
}
int main(){
    s.tos=-1;
    int ch,x;
    printf("\nMenu\n1.Push\n2.Pop\n3.show\n4.end\n");
    do{
       printf("\nenter the choice:\n");
       scanf("%d",&ch);
       switch(ch){
          case 1:printf("Enter value to be pushed\n");
          scanf("%d",&x);
          push(x);
          break;
          case 2:x=pop();
           if(x==-2)
           printf("stack is empty");
           else
           printf("%d is removed\n",x);
           break;
           case 3:show();
           break;
           case 4: exit(0);
          }
       }while(ch!=4);
       return 0;
      
}

