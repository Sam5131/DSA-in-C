//WAP to take input from user and stack it using linkedlist
#include<stdio.h>
#define MAX 1000

struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;

void push(int item)
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

int pop()
{
    struct node *temp;
    if(top==NULL)
    {
        printf("Stack Underflow");
    }
    else
    {
        temp=top;
        top=top->next;
        int popped_val=temp->data;
        free(temp);
        return popped_val;
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
        struct node *p=top;
        printf("Stack:\n");
        while(p!=NULL)
        {
            printf("%d\n",p->data);
            p=p->next;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        int item;
        printf("Enter the item to be pushed: ");
        scanf("%d",&item);
        push(item);
    }

    display();
    int item=pop();
    printf("Popped item is: %d\n",item);

    display();
    return 0;
}