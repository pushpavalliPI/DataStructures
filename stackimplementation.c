#include <stdio.h>
void peek();
void disp();
int top = -1;
int stack[10];
int main()
{
    int choice=0 , element=0 , continues=0 ;
    do
    {
        printf("Enter your choice\n1.Push\n2.Pop\n3.Peek\n4.Display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter element to be pushed\n");
                scanf("%d",&element);
                push(element);
                break;
            case 2:
                printf("\n Popped element is %d",pop());
                break;
            case 3:
                peek();
                break;
            case 4:
                disp();
                break;
            default:
                printf("\nInvalid input!\n");
                break;
        }
        printf("\nDo you wish to continue?\nEnter 1 for Yes\n");
        scanf("%d",&continues);
        
    } while (continues == 1);
    return 0;
}
void push(int x)
{
    
    if(top == 9)
    {
        printf("Stack is full\n");
    }
    else
    {
        top = top + 1;
        stack[top] = x;
    }
    
}
int pop()
{
    int y = 0;
    if (top == -1)
    {
        printf("Stack is empty!");
    }
    else
    {
        y = stack[top];
        stack[top] = 0;
        top = top - 1;
    }
    return y;
}
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Top position is %d\n",top);
        printf("Top element is %d\n",stack[top]);
    }
}
void disp()
{
    
    if (top == -1)
    {
        printf("Stack is empty!");
    }
    else
    {
        printf("Stack:\n");
        for(int i = 0;i <= top; i++)
        {
            printf("%d ",stack[i]);
        }
    }
    
}