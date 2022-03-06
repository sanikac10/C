#include<stdio.h>
#define MAX 50
#include<stdlib.h>
struct pqueue
{
   int rear,front;
   int elem[MAX];
}pq;

 

int empty()
{
   if(pq.rear<pq.front)
      return 1;
   else
      return 0;
}

 

int full()
{
   if(pq.rear==MAX-1)
      return 1;
   else
      return 0;
}

 

void insert(int x)
{
   if(full())
      printf("\npriority queue is full");
   else
      pq.elem[++pq.rear]=x;
}

 

int removesAsc()
{
    int min,p;
   if(empty())
      return -1;
   else{
      min=pq.elem[0];
      p=0;
      for(int i=1;i<=pq.rear;i++)
      {
        if(pq.elem[i]<min)
        {
            min=pq.elem[i];
            p=i;
        }
      }
      for(int i=p+1;i<=pq.rear;i++)
      {
          pq.elem[i-1]=pq.elem[i];
      }
      pq.rear--;
      return min;
   }
}
int removesDesc()
{
    int max,p;
   if(empty())
      return -1;
   else{
      max=pq.elem[0];
      p=0;
      for(int i=1;i<=pq.rear;i++)
      {
        if(pq.elem[i]>max)
        {
            max=pq.elem[i];
            p=i;
        }
      }
      for(int i=p+1;i<=pq.rear;i++)
      {
          pq.elem[i-1]=pq.elem[i];
      }
      pq.rear--;
      return max;
   }
}

 

void show()
{
   int i;
   if(empty())
      printf("\npriority queue is empty");
   else
   {
      for(i=0;i<=pq.rear;i++)
           printf("%d\t",pq.elem[i]);
   }
}

 

int main()
{
   int ch,x;
   pq.rear=-1;
   pq.front=0;
   do
   {
     printf("Menu\n1.insert\n2.removeAsc\n3.removeDesc\n4.show\n5.exit");
     printf("\nEnter your choice:");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1:printf("Enter value to insert");
              scanf("%d",&x);
              insert(x);
              break;
       case 2:x=removesAsc();
              if(x==-1)
                 printf("\npriority queue is empty");
              else
                 printf("\n%d is removed",x);
              break;
        case 3:x=removesDesc();
              if(x==-1)
                 printf("\npriority queue is empty");
              else
                 printf("\n%d is removed",x);
              break;
       case 4:show();
              break;
       case 5:exit(0);
      }
     }while(ch!=5);
return 0;
}
