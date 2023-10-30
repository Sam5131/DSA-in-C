//WAP to create a circular linkedlist by taking input from user
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int n)
{
    struct node *fnNode, *temp;
    int data;

    printf("Enter the data for node 1: ");
    scanf("%d", &data);
    
    head = (struct node*)malloc(sizeof(struct node));

    if (head == NULL)
    {
        printf("Memory cannot be allocated\n");
        return;
    }

    head->data = data;
    head->next = head;
    temp = head;

    for (int i = 2; i <= n; i++)
    {
        fnNode = (struct node*)malloc(sizeof(struct node));

        if (fnNode == NULL)
        {
            printf("Memory cannot be allocated further\n");
            break;
        }

        printf("Enter the data for node %d: ", i);
        scanf("%d", &data);
        
        fnNode->data = data;
        fnNode->next = head; // Connect the new node to the head
        temp->next = fnNode; // Connect the previous node to the new node
        temp = fnNode;       // Update the temp pointer to the new node
    }
}

void display()
{
    struct node *current = head;

    if (head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        printf("The list:\n");

        do
        {
            printf("%d\n", current->data);
            current = current->next;
        } while (current != head);
    }
}

int main()
{
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    create(n);

    display();

    return 0;
}
