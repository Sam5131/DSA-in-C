//WAP to create a circular linkedlist by taking input from user
//Delete the last element
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

struct node *delete_end(struct node *head)
{
    if (head == NULL)
    {
        printf("The list is already empty\n");
        return NULL;
    }

    struct node *current=(struct node*)malloc(sizeof(struct node));
    current=head;
    struct node *last=(struct node*)malloc(sizeof(struct node));
    last=head;
    
    while (last->next != head)
    {
        current=last;
        last = last->next;
    }

    current->next=head;
    free(last);

    return head; 
}

int main()
{
    printf("Enter the number of nodes: ");
    int n;
    scanf("%d",&n);
    create(n);
    display();

    head=delete_end(head);
    printf("After deletion: \n");
    display();
    return 0;
}