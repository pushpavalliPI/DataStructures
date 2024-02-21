#include<stdio.h>
#include<stdlib.h>
void print();
void deleteatfirst();
void deleteatend();
void deleteatmid();
void insertatfirst(int a);
void insertatend(int a);
void insertatmid(int a);
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node *head,*p,*newnode,*temp,*tail;
int main()
{
    head=malloc(sizeof(struct node));
    head->next=NULL;
    int choice,x,c;
    do
    {
        printf("Enter \n1.Insert at first\n2.Insert at end\n3.Insert at mid\n4.Delete at first\n5.Delete at end\n6.Delete at mid\n7.Printlist\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter element to be inserted\n");
            scanf("%d",&x);
            insertatfirst(x);
            break;
            case 2:
            printf("Enter element to be inserted\n");
            scanf("%d",&x);
            insertatend(x);
            break;
            case 3:
            printf("Enter element to be inserted\n");
            scanf("%d",&x);
            insertatmid(x);
            break;
            case 4:
            deleteatfirst();
            break;
            case 5:
            deleteatend();
            break;
            case 6:
            deleteatmid();
            break;
            case 7:
            print();
            break;
            defauly:
            printf("Invalid input\n");
        }
        printf("Do you wish to continue?(1/0)\n");
        scanf("%d",&c);
    } while (c==1);
    myfree();
    return 0;
    
}
void insertatfirst(int a)
{
    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=a;
    if(head->next==NULL)
    {
        head->next=newnode;
        newnode->next=NULL;
        newnode->prev=head;
        tail=newnode;
    }
    else
    {
        newnode->next=head->next;
        newnode->prev=head;
        head->next->prev=newnode;
        head->next=newnode;
    }
}
void insertatend(int a)
{
    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=a;
    newnode->next=NULL;
    if(head->next==NULL)
    {
        head->next=newnode;
        newnode->prev=head;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
void insertatmid(int a)
{
    int c,n;
    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=a;
    printf("Enter 1.Insert at position\n2.Insert after an element\n");
    scanf("%d",&c);
    int x=0;
    switch (c)
    {
    case 1:
        printf("Enter position to be entered in\n");
        scanf("%d",&n);
        if(head->next==NULL)
        {
            head->next=newnode;
            newnode->next=NULL;
            newnode->prev=head;
            tail=newnode;
        }
        else
        {
            p=head;
            while(x<n)
            {
                x++;
                p=p->next;
            }
            p->next->prev=newnode;
            newnode->next=p->next;
            p->next=newnode;
            newnode->prev=p;
        }
        break;
        case 2:
        printf("Enter element to be insert after\n");
        scanf("%d",&n);
        if(head->next==NULL)
        {
            head->next=newnode;
            newnode->next=NULL;
            newnode->prev=head;
            tail=newnode;
         }
        else
        {
            p=head;
            while(p->data!=n)
            {
                p=p->next;
            }
            p->next->prev=newnode;
            newnode->next=p->next;
            p->next=newnode;
            newnode->prev=p;
        }
        break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    
}
void print()
{
    p=head->next;
    while(p->next!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d ",p->data);
    printf("\n");
}
void deleteatfirst()
{
    if(head->next==NULL)
    {
        printf("Cannot delete\n");
    }
    else
    {
        temp=head->next;
        head->next=temp->next;
        temp->next->prev=head;
        free(temp);
    }
}
void deleteatend()
{
    if(head->next==NULL)
    {
        printf("Cannot delete\n");
    }
    else
    {
        tail=tail->prev;
        free(tail->next);
        tail->next=NULL;
    }
}
void deleteatmid()
{
    int x;
    p=head;
    printf("Enter element to be deleted\n");
    scanf("%d",&x);
    if(head->next==NULL)
    {
        printf("Cannot delete\n");
    }
    else
    {
        while(p->next->data!=x)
        {
            p=p->next;
        }
        temp=p->next;
        p->next=temp->next;
        temp->next->prev=p;
        free(temp);
    }

}
void myfree()
{
    p=head;
    while(p->next!=NULL)
    {
        temp=p;
        p=p->next;
        free(temp);
    }
    free(p);
    free(head);
}

