//WAP to create a circular linkedlist by taking input from the suer
//Insert an element by taking from the user in a desired index
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

struct node *insert_btwn(struct node *head,int data,int index)
{
    struct node *current=(struct node*)malloc(sizeof(struct node));
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    int i=0;
    current=head;
    while(i<index-1)
    {
        current=current->next;
        i++;
    }
    new_node->next=current->next;
    current->next=new_node;
    return head;
}

int main()
{
    int n, data, index;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    create(n);
    display();

    printf("Enter the data to be inserted: ");
    scanf("%d", &data);

    printf("Enter the index: ");
    scanf("%d", &index);

    head=insert_btwn(head, data, index);

    display();

    return 0;
}