#include <stdio.h>
#include<stdlib.h>
void enqueue(int x);
void dequeue();
void display();
void findfrontandrear();
void myfree();
int front=0;int rear=0,maxsize=0;;
//node
struct node
{
    int data;
    struct node* next;
};
struct node *head,*p,*newnode,*temp,*rearp;
int main()
{
    head = malloc(sizeof(struct node));
    int c,n,d,ch;
    printf("Enter maximum size of the queue\n");
    scanf("%d",&maxsize);
    do
    {
        printf("\nEnter 1/2/3\n1.Enqueue\n2.Dequeue\n3.Display\n4.Find front and rear\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("\nEnter element to be enqueued\n");
            scanf("%d",&n);
            enqueue(n);
            break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                findfrontandrear();
                break;
            default:
            printf("\nPlease enter a valid choice\n");
            break;
        }
        printf("\nDo you wish to continue(0/1)?\n");
        scanf("%d",&ch);
    } while (ch==1);
    myfree();
    return 0;
}
void enqueue(int a)
{
    if(rear==maxsize)
    {
        printf("Cannot enqueue\n");
    }
    else
    {
        rear++;
        newnode=malloc(sizeof(struct node));
        newnode->data=a;
        rearp=newnode;
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
}
void dequeue()
{
    front++;
    if(front>rear)
    {
        printf("Cannot dequeue\n");
    }
    else
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
}
void display()
{
    
    if(front>rear)
    {
        printf("\nQueue is empty!\n");
    }
    else
    {
        printf("\n Queue:\n");
        p=head->next;
        while(p->next!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("%d ",p->data);
        printf("\n");
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
void findfrontandrear()
{
    printf("Front : %d\n",front);
    printf("Front element is %d\n",head->next->data);
    printf("Rear is %d\n",rear);
    printf("Rear element is %d\n",rearp->data);
}
