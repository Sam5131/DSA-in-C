//WAP to a stack using array by taking input from the user
#include <stdio.h>
#define MAX 1000

int top;
int stack[MAX];

void push(int item)
{
    if(top==MAX-1)
    {
        printf("Stack overflow");
    }
    else
    {
        stack[++top]=item;
    }
}

void printStack()
{
    int i;
    printf("Stack: ");
    for(i=0;i<=top;i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int pop()
{
    if(top==-1)
    {
        printf("Stack underflow");
        return -1;
    }
    else
    {
        int item=stack[top--];
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
    int n;
    printf("Enter the number of elements to be pushed: ");
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        int item;
        printf("Enter the item to be pushed: ");
        scanf("%d",&item);
        push(item);
    }
    printStack();
    int item=pop();
    printf("Popped item: %d\n",item);
    printStack();
    return 0;
}