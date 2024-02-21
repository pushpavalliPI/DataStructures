#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void push(int a);
void pop();
void display(struct node *head);
void myfree();
void findtop();
struct node *head, *newnode, *temp, *top,*p;
int maxsize, countformax = 0;

int main()
{
    head = malloc(sizeof(struct node));
    head->next = NULL;
    
    int choice, element, continues;
    printf("Enter max size of the stack: ");
    scanf("%d", &maxsize);
    
    do
    {
        printf("\nEnter your choice:\n1. Push\n2. Pop\n3. Display\n4.Location of top\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter element to be pushed: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                display(head->next);
                break;
            case 4:
                findtop();
                break;
            default:
                printf("\nInvalid input!\n");
                break;
        }
        printf("\nDo you wish to continue?\nEnter 1 for Yes: ");
        scanf("%d", &continues);
    } while (continues == 1);
    
    myfree();
    return 0;
}

void push(int a)
{
    countformax++;
    if(countformax <= maxsize)
    {
        newnode = malloc(sizeof(struct node));
        newnode->data = a;
        if(head->next == NULL)
        {
            head->next = newnode;
            newnode->next = NULL;
        }
        else
        {
            newnode->next = head->next;
            head->next = newnode;
        }
        top = newnode;
    }
    else
    {
        printf("Stack is full, cannot push\n");
    }
    findtop();
}

void display(struct node* head) 
{
    if (head == NULL) 
    {
        return;
    }
    display(head->next);
    printf("%d ", head->data);
}

void pop()
{
    if (head->next == NULL) 
    {
        printf("Cannot pop, stack is empty\n");
        return;
    }
    countformax--;
    temp = head->next;
    head->next = temp->next;
    printf("Popped element: %d\n", temp->data);
    free(temp);
    findtop();
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
void findtop()
{
    printf("Position of top: %d\n",countformax);
    printf("Top element %d\n",head->next->data);
}