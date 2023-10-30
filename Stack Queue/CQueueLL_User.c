//WAP to implement circular queue using linkedlist
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
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
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
            rear->next=front;
        }
        else
        {
            rear->next=new_node;
            rear=new_node;
            rear->next=front;
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
        rear->next=front;
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
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp=front;
        while(temp->next!=front)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}

int main()
{
    int choice,item;
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d",&item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}