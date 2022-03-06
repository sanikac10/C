#include<stdio.h>

#define MAX 50

struct stack{

    int tos1,tos2;

    int elem[MAX];

}s;

int empty1(){

    if (s.tos1==-1)

    return 1;

    else

    return 0;

}

int empty2(){

    if (s.tos2==MAX)

    return 1;

    else

    return 0;

}

int full(){

    if (s.tos2==s.tos1+1)

    return 1;

    else

    return 0;

}

void push1(int x){

    if (full())

    printf("stack1 is full");

    else

    s.elem[++s.tos1]=x;

}

void push2(int x){

    if(full())

    printf("stack2 is full");

    else

    s.elem[--s.tos2]=x;

}

int pop1(){

    if(empty1())

     return -1;

    else

     return s.elem[s.tos1--];

}

int pop2(){

    if(empty2())

    return -1;

    else

    return s.elem[s.tos2++];

}

void show1(){

    int i;

    if (empty1())

    printf("The stack1 is empty");

    else{

        for(i=0;i<=s.tos1;i++)

        printf("%d\t",s.elem[i]);

    }

}

void show2(){

    int i;

    if(empty2())

    printf("The stack2 is empty");

    else{

        for(i=MAX-1;i>=s.tos2;i--)

            printf("%d\t",s.elem[i]);

    }

}

int main(){

    s.tos1=-1;

    s.tos2=MAX;

    int ch,x;

    printf("\nMENU\n1.Push onto stack1\t2.Pop from stack1\t3.show stack1\n");

    printf("4.push onto stack2\t5.pop from stack2\t6.show stack 2\n7.exit");

    do{

        printf("\nenter your choice: ");

        scanf("%d",&ch);

        switch(ch){

            case 1:printf("\nenter the value to be pushed onto stack1");

            scanf("%d",&x);

            push1(x);

            break;

            case 2:x=pop1();

            if(x==-1)

            printf("stack is empty");

            else

            printf("\n%d is removed from stack 1",x);

            break;

            case 3:show1();

            break;

            case 4:printf("enter the value to be pushed onto stack2\n");

            scanf("%d",&x);

            push2(x);

            break;

            case 5:x=pop2();

            if(x==-1)

            printf("stack2 is empty\n");

            else

            printf("\n%d is removed from stack 2",x);

            break;

            case 6:show2();

            break;

            case 7:exit(0);

        }

    }while(ch!=7);

 return 0;

} 
