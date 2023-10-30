//WAP to implement queue using linkedlist self initialized
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue(int item)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        printf("Memory cannot be allocated");
    }
    else
    {
        new_node->data=item;
        new_node->next=NULL;
        if(front==NULL)
        {
            front=new_node;
            rear=new_node;
        }
        else
        {
            rear->next=new_node;
            rear=new_node;
        }
    }
}

void dequeue()
{
    if(front==NULL)
    {
        printf("Queue underflow");
    }
    else
    {
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp=front;
        printf("Popped element is: %d\n",temp->data);
        front=front->next;
        free(temp);
        if(front==NULL)
        {
            rear=NULL;
        }
    }
}

void display()
{
    if(front==NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        struct node *current=front;
        printf("Queue:\n");
        while(current!=NULL)
        {
            printf("%d\n",current->data);
            current=current->next;
        }
    }
}

int main()
{
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);

    display();

    dequeue();
    dequeue();

    display();

    return 0;
}