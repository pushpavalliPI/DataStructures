#include <stdio.h>
void enqueue(int x);
int dequeue();
void display();
int isempty();
int isfull();
int front=-1;int rear=-1;
int queue[10];
int main()
{
    int c,n,d,ch;
    do
    {
        printf("\nEnter 1/2/3\n1.Enqueue\n2.Dequeue\n3.Display\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("\nEnter element to be enqueued\n");
            scanf("%d",&n);
            enqueue(n);
            break;
            case 2:
            d=dequeue();
            printf("\n%d was dequeued\n",d);
            break;
            case 3:
            display();
            break;
            default:
            printf("\nPlease enter a valid choice\n");
            break;
        }
        printf("\nDo you wish to continue(0/1)?\n");
        scanf("%d",&ch);
    } while (ch==1);
    return 0;
}
void enqueue(int x)
{
    if (isfull())
    {
        printf("\nQueue is full!Cannot enqueue\n");
    }
    else
    {
        if (front==-1&&rear==-1)
        {
            front=0;
            rear=0;
            queue[front]=x;
        }
        else
        {
            rear++;
            queue[rear]=x;
        }
    }
    display();
}
int dequeue()
{
    int y;
    if(isempty())
    {
        printf("\nQueue is empty!Cannot dequeue!\n");
    }
    else
    {
        if(front==rear)
        {
            y=queue[front];
            front=-1;
            rear=-1;
        }
        else
        {
            y=queue[front];
            front++;
        }
    }
    display();
    return y;
}
void display()
{
    
    if(isempty())
    {
        printf("\nQueue is empty!\n");
    }
    else
    {
        printf("\n Normal queue:\n");
        for(int i=front;i<=rear;i++)
        {
            printf("  %d  ",queue[i]);
        }
    }
}
int isfull()
{
    if(rear==9)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty()
{
    if (front>rear||front==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}