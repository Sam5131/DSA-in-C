//WAP to create a circular linkedlist by taking data from user
//Insert an element in beginning from taking input from user
#include <stdio.h>
#include <stdlib.h>

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

    if (n <= 0)
    {
        printf("Invalid input for the number of nodes\n");
        return;
    }

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
            printf("Data: %d\n", current->data);
            current = current->next;
        } while (current != head);
    }
}

struct node *insert_beg(struct node *head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;

    if (head == NULL)
    {
        new_node->next = new_node; // Make it point to itself
        head = new_node; // Update the head to the new node
    }
    else
    {
        struct node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = new_node; // Connect the last node to the new node
        new_node->next = head; // Make the new node the new head
        head = new_node; // Update the head to the new node
    }

    return head;
}

int main()
{
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    create(n);
    printf("The list:\n");
    display();
    printf("Enter the data to be inserted at the beginning: ");
    scanf("%d", &data);
    head = insert_beg(head, data);
    printf("The list after insertion:\n");
    display();

    // Free memory here if needed

    return 0;
}