//WAP to implement circular queue using array
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