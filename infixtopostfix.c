#include <stdio.h>
#include <string.h>
int precedence(char x);
int top = -1,op_top=-1;
void push(char);
void push_op(char);
void pop();
char infix[80];
char postfix[80];
char input[80];
char op_stack[80];
int main()
{
    printf("Enter the infix expression\n");
    scanf("%s",input);
    for(int i=0;i<strlen(input);i++)
    {
        infix[i]=input[i];
    }
    for(int j=0;j<strlen(input);j++)
    {
        if(infix[j] == '+' || infix[j] == '-' || infix[j] == '*' || infix[j] == '/' || infix[j] == ')' || infix[j] == '(' || infix[j] == '^')
        {
            check:
            if(op_top == -1)
            {
                push_op(infix[j]);
            }
            else if(postfix[op_top] == '(')
            {
                push_op(infix[j]);
            }
            else if(infix[j] == ')')
            {
                do
                {
                    pop();
                }while(op_stack[op_top]!='(');
                pop();
            }
            else if(precedence(infix[j]) > precedence(op_stack[op_top]))
            {
                push_op(infix[j]);
            }
            else if(precedence(infix[j]) <= precedence(op_stack[op_top]))
            {
                pop();
                goto check;
            }
        } 
        else
        {
            push(infix[j]);
        }
        
    }

    printf("%s",postfix);
    printf("%s",op_stack);
    return 0;
}
void push_op(char x)
{
    op_top = op_top + 1;
    op_stack[op_top] = x;
}
void push(char x)
{
    top = top+1;
    postfix[top] = x;
}
void pop()
{
    if(op_stack[op_top] != '(' && op_stack[op_top] != ')')
    {
       push(op_stack[op_top]);
    }
    op_stack[op_top] = 0;
    op_top = op_top - 1;
}
int precedence(char x)
{
    if(x == '*' || x =='/')
    {
        return 2;
    }
    else if(x == '+' || x == '-')
    {
        return 1;
    }
    else if(x == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}