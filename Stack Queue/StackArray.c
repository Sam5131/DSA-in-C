//WAP to perform push and pop operations in a stack using array
#include <stdio.h>
#define MAX 1000

int top;
int stack[MAX];

void push(int item)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top] = item;
    }
}

void printStack()
{
    int i;
    printf("Stack: ");
    for(i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int item = stack[top--];
        return item;
    }
}

void initialize()
{
    top=-1;
}

int main()
{
    initialize();
    push(10);
    push(20);
    push(30);
    push(40);

    printStack();

    int item=pop();
    printf("Popped item: %d\n", item);

    printStack();
}