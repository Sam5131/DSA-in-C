//WAP to create a linkedlist by taking input from user
//Delete an element from the desired index
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

struct node *delete_btwn(struct node *head,int index)
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
    
    int i=0;
    while (i<index-1)
    {
        current=current->next;
        i++;
    }
    last=current->next;
    current->next=last->next;
    free(last);

    return head; 
}

int main()
{
    int n, data, index;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    create(n);
    display();

    printf("Enter the index of the node to be deleted: ");
    scanf("%d", &index);
    printf("After deletion:\n");
    head=delete_btwn(head,index);
    display();

    return 0;
}