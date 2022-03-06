#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next,*prev;
}node;
typedef struct
{node *last,*start;
}LL;
void insertBeginning(LL *l,int ele)
{
    node *newrec;
    newrec=(node*)malloc(sizeof(node));
    newrec->data=ele;
    newrec->next=NULL;
    newrec->prev=NULL;

    //if first node to add i.e list is empty
    if(l->start==NULL)
    {
    l->start=newrec;
    l->last=newrec;
   }
   else
   {
       newrec->next=l->start;
       l->start->prev=newrec;
       l->start=newrec;
   }
}
void insertEnd(LL *l,int ele)
{
    node *newrec,*p;
    newrec=(node*)malloc(sizeof(node));
    newrec->data=ele;
        newrec->next=NULL;
        newrec->prev=NULL;
    if(l->start==NULL)
    {
    l->start=newrec;
    l->last=newrec;
    }
    else
    {
    l->last->next=newrec;
    newrec->prev=l->last;
    l->last=newrec;
    }
}
void display(LL *l)
{
    node *p;
    if(l->start==NULL)
    {
        printf("Doubly Linked List is empty\n");
        return;
    }
    p=l->start;

    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}
void displayReverse(LL *l)
{
    node *p;
    if(l->start==NULL)
    {
        printf("Doubly Linked List is empty\n");
        return;
    }
    p=l->last;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->prev;
    }
    printf("\n");
}
int deleteBeginning(LL *l)
{
    node *p;
    if(l->start==NULL)
    {
        return -1;
    }
    p=l->start;
    if(l->start==l->last)
    l->start=l->last=NULL;
    else
    {
        l->start=l->start->next;
        l->start->prev=NULL;
        p->next=NULL;
    }
    return p->data;
}
int deleteEnd(LL *l)
{
    node *p,*q;
    if(l->last==NULL)
    {
        return -1;
    }
p=l->last;
if(l->start==l->last)
l->start=l->last=NULL;
else
{
l->last=l->last->prev;
l->last->next=NULL;
p->prev=NULL;
}
return p->data;
}
int main()
{
    LL l1;
    int ch,ele,pos;
    l1.start=NULL;
    l1.last=NULL;
    while(1)
    {        printf("\n1:InsertBeginning\n2:InsertEnd\n3:DeleteBeginning\n4:DeleteEnd\n5:Display\n6:DisplayReverse\n7:Exit\n");
        printf("Enter choice\n");
        scanf("%d",&ch);
        if(ch==7)
        break;
        switch(ch)
        {
                       case 1:
                                printf("Enter element to insert at Beginning\n");
                scanf("%d",&ele);
                insertBeginning(&l1,ele);
                printf("\nUpdated list\n ");
                display(&l1);
                break;
        case 2:
                                printf("Enter element to insert at End\n");
                scanf("%d",&ele);
                insertEnd(&l1,ele);
                printf("\nUpdated list\n ");
                display(&l1);
                break;

        case 3:
                                ele=deleteBeginning(&l1);
                if(ele==-1)
                printf("Doubly Linked List is empty");
                else
                printf("Element deleted from beginning =%d\n",ele);
                 printf("\nUpdated list\n ");
                 display(&l1);
                break;

        case 4:
                                ele=deleteEnd(&l1);
                if(ele==-1)
                printf("Doubly Linked List is empty");
                else
                printf("Element deleted from from End =%d\n",ele);
                 printf("\nUpdated list\n ");
                 display(&l1);
                                 break;
        case 5:
                                 display(&l1);
                                 break;
        case 6:
                                 displayReverse(&l1);
                                 break;
        default:
                                 printf("invalid choice\n");
        }
    }
    return 0;
}


