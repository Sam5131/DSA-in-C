//WAP to implement stack using linkedlist
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top=NULL;
void push(int new_data)
{
    struct node *new_node =(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        printf("Stack Overflow");
    }
    else
    {
        new_node->data=new_data;
        new_node->next=top;
        top=new_node;
    }
}
int pop()
{
    struct node*temp;
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
    push(10);
    push(20);
    push(30);
    push(40);

    display();

    printf("\n%d is popped\n",pop()); 
    printf("\n%d is popped\n",pop());

    display();
}