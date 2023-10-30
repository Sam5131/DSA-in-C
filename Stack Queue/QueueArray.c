//WAP to implement queue using array self initialized
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int item)
{
    if(rear==MAX-1)
    {
        printf("Queue overflow");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear++;
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
        front++;
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
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }
}

int main()
{
    enqueue(40);
    printf("Front:%d\t",front);
    printf("Rear:%d\n",rear);

    enqueue(50);
    printf("Front:%d\t",front);
    printf("Rear:%d\n",rear);

    enqueue(60);
    printf("Front:%d\t",front);
    printf("Rear:%d\n",rear);
    
    enqueue(70);
    printf("Front:%d\t",front);
    printf("Rear:%d\n",rear);
    

    display();

    dequeue();
    printf("Front:%d\t",front);
    printf("Rear:%d\n",rear);
    
    dequeue();
    printf("Front:%d\t",front);
    printf("Rear:%d\n",rear);
    
    enqueue(80);
    printf("Front:%d\t",front);
    printf("Rear:%d\n",rear);
    
    display();
}