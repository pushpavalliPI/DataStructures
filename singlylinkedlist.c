#include<stdio.h>
#include<stdlib.h>
void print();
void deleteatfirst();
void deleteatend();
void deleteatmid();
void insertatfirst(int a);
void insertatend(int a);
void insertatmid(int a);
void myfree();
struct node
{
    int data;
    struct node* next;
};
struct node *head,*p,*newnode,*temp;
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
    newnode=malloc(sizeof(struct node));
    newnode->data=a;
    if(head->next==NULL)
    {
        head->next=newnode;
        newnode->next=NULL;
    }
    else
    {
        newnode->next=head->next;
        head->next=newnode;
    }
}
void insertatend(int a)
{
    newnode=malloc(sizeof(struct node));
    newnode->data=a;
    newnode->next=NULL;
    if(head->next==NULL)
    {
        head->next=newnode;
    }
    else
    {
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=newnode;
    }
}
void insertatmid(int a)
{
    int c,n,ele;
    newnode=malloc(sizeof(struct node));
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
        }
        else
        {
            p=head;
            while(x<n)
            {
                x++;
                p=p->next;
            }
            newnode->next=p->next;
            p->next=newnode;
        }
        break;
        case 2:
        printf("Enter element to be insert after\n");
        scanf("%d",&ele);
        if(head->next==NULL)
        {
            head->next=newnode;
            newnode->next=NULL;
        }
        else
        {
            p=head;
            while(p->data!=ele && p->next!=NULL)
            {
                p=p->next;
            }
            newnode->next=p->next;
            p->next=newnode;
        }
        break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    
}
void print()
{
    printf("\n Singly linked list:\n");
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
        p=head;
        while(p->next->next!=NULL)
        {
            p=p->next;
        }
        temp=p->next;
        p->next=NULL;
        free(temp);
    }
}
void deleteatmid()
{
    int x;
    p=head;
    printf("Enter element to be deleted\n");
    print();
    scanf("%d",&x);
    if(head->next==NULL)
    {
        printf("Cannot delete\n");
    }
    else
    {
        while(p->next->data!=x&&p->next!=NULL)
        {
            p=p->next;
        }
        temp=p->next;
        p->next=temp->next;
        free(temp);
    }

}
void myfree()
{
    p=head->next;
    while(p->next!=NULL)
    {
        temp=p;
        p=p->next;
        free(temp);
    }
    free(p);
    free(head);
}
