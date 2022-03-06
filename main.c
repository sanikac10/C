#include <stdio.h>

#define MAX 50

struct queue{

    int f;

    int r;

    int elem[MAX];

}s;

 

int empty(){

    if(s.r<s.f)

     return 1;

    else

     return 0;

}

 

int full(){

    if(s.r==MAX-1)

    return 1;

    else

     return 0;

}

 

void insert(int x){

    if(full())

     printf("the queue is full");

    else

     s.elem[++s.r]=x;

}

 

int removal(){

    if(empty())

     return -1;

    else

     return s.elem[s.f++];

}

 

void show(){

    int i;

    if(empty())

     printf("the queue is empty\n");

    else{

        for(i=s.f;i<=s.r;i++)

        printf("%d\t",s.elem[i]);

    }

}

int main(){

    s.f=0;

    s.r=-1;

    int ch,x;

    printf("\nMenu\n1.Insert\n2.Remove\n3.show\n4.end\n");

    do{

       printf("\nenter the choice:\n");

       scanf("%d",&ch);

       switch(ch){

          case 1:printf("Enter value to be insertedd\n");

          scanf("%d",&x);

          insert(x);

          break;

          case 2:x=removal();

           if(x==-1)

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
