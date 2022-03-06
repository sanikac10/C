#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
}
*first,*last,*current,*follow,*ahead,*pnode;

void create()
{
    pnode=(struct node *)malloc(sizeof (struct node));
    if(pnode==NULL)
        printf("Insufficient memory\n");
    else
    {
        printf("Enter data : ");
        scanf("%d",&pnode->data);
        if(first==NULL)
        {
            first=pnode;
            last=pnode;
            pnode->next=NULL;
        }
        else
        {
            last->next=pnode;
            pnode->next=NULL;
            last=pnode;
        }
    }
}

void insertBefore()
{
    int x;
    pnode=(struct node *)malloc(sizeof(struct node));
    if(pnode==NULL)
        printf("Insufficient memory\n");
    else
    {
        printf("Enter data : ");
        scanf("%d",&pnode->data);
        printf("Enter the data before which you want to insert new node : ");
        scanf("%d",&x);
        current=first;
        follow=NULL;
        while(current->data!=x&&current!=NULL)
        {
            follow=current;
            current=current->next;
            if(current==NULL)
            break;
        }
        if(current==NULL)
            printf("Node not found\n");
        else
        {
            if(current==first)
            {
                pnode->next=first;
                first=pnode;
            }
            else
            {
                follow->next=pnode;
                pnode->next=current;
            }
        }
    }
}

void insertAfter()
{
   int x;
    pnode=(struct node *)malloc(sizeof (struct node));
    if(pnode==NULL)
        printf("Insufficient memory\n");
    else
    {
        printf("Enter data : ");
        scanf("%d",&pnode->data);
        printf("Enter the data before which you want to insert new node : ");
        scanf("%d",&x);
        current=first;
        while(current->data!=x&&current!=NULL)
        {
            current=current->next;
            if(current==NULL)
            break;
            ahead=current->next;
        }
        if(current==NULL)
            printf("Node not found\n");
        else
        {
            if(current==last)
            {
                last->next=pnode;
                pnode->next=NULL;
                last=pnode;
            }
            else
            {
                current->next=pnode;
                pnode->next=ahead;
            }
        }
    }
}

void deletion()
{
    int x;
    printf("Enter the data which you want to delete : ");
    scanf("%d",&x);
    current=first;
    follow=NULL;
    while(current->data!=x&&current!=NULL)
    {
        follow=current;
        current=current->next;
        if(current==NULL)
        break;
        ahead=current->next;
    }
    if(current==NULL)
       printf("Node not found\n");
    else
    {
        if(current==first&&current==last)
           first=NULL;
        else
        {
            if(current==first)
                first=first->next;
            else
            {
                if(current==last)
                   {
                       last=follow;
                       last->next=NULL;
                   }
                else
                   follow->next=ahead;
            }
        }
        free(current);
    }
}

void search()
{
    int x;
    printf("Enter data you want to search : ");
    scanf("%d",&x);
    current=first;
    while(current->data!=x&&current!=NULL)
    {
         current=current->next;
         if(current==NULL)
         break;
    }
    if(current==NULL)
       printf("Node not found\n");
    else
       printf("Node having data %d found",x);
}

void traverse()
{
    if(first==NULL)
       printf("Linked list is empty\n");
    else
    {
        current=first;
        while(current!=NULL)
        {
            printf("%d\t",current->data);
            current=current->next;
        }
    }
}

int main()
{
    int n;
    do
    {
        printf("\nEnter your choice\n");
        printf("1. create\n2. insertbefore\n3. insertafter\n4. delete\n5. search\n6. traverse\n7. exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1 : create();
        break;
            case 2 : insertBefore();
        break;
            case 3 : insertAfter();
        break;
            case 4 : deletion();
        break;
            case 5 : search();
        break;
            case 6 : traverse();
        break;
            case 7 : exit(0);
        }
    }while(n!=7);
   
    return 0;
}
