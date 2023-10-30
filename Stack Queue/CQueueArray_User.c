//WAP to implement circular queue using array user initialized
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int item)
{
    if((rear+1)%MAX==front)
    {
        printf("Queue overflow");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear=(rear+1)%MAX;
        queue[rear]=item;
    }
}

void dequeue()
{
    if(front==-1)
    {
        printf("Queue underflow");
    }
    else
    {
        printf("Popped element is: %d\n",queue[front]);
        front=(front+1)%MAX;
    }
}

void display()
{
    if(front==-1)
    {
        printf("Queue is empty");
    }
    else
    {
        for(int i=front;i!=rear;i=(i+1)%MAX)
        {
            printf("%d ",queue[i]);
        }
        printf("%d",queue[rear]);
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