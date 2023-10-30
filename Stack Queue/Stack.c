//WAP to implement stack using Linkedlist and array based on user input
//Perform push and pop operations.
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000;

struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;

void pushLL(int item)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        printf("Memory cannot be allocated");
    }
    else
    {
        new_node->data=item;
        new_node->next=top;
        top=new_node;
    }
}

void popLL()
{
    if(top==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        struct node *temp=top;
        printf("Popped element is %d",temp->data);
        top=top->next;
        free(temp);
    }
}

void display()
{
    if(top==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        struct node *temp=top;
        printf("Stack:\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
#define MAX1 1000
int stack[MAX1];
int top1;
void initialize()
{
    top1=-1;
}

void push_A(int item)
{
    if(top1==MAX1-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        stack[++top1]=item;
    }
}

void pop_A()
{
    if(top1==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("Popped element is %d",stack[top1--]);
    }
}

void display_A()
{
    if(top1==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Stack:\n");
        for(int i=top1;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

int main()
{
    int ch,item;
    printf("1. Push in Linked List\n");
    printf("2. Pop in Linked List\n");
    printf("3. Display in Linked List\n");
    printf("4. Push in Array\n");
    printf("5. Pop in Array\n");
    printf("6. Display in Array\n");
    printf("7. Exit\n");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d",&item);
                pushLL(item);
                break;
            case 2:
                popLL();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter the element to be pushed: ");
                scanf("%d",&item);
                push_A(item);
                break;
            case 5:
                pop_A();
                break;
            case 6:
                display_A();
                break;
            case 7:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(ch!=7);
    return 0;
}