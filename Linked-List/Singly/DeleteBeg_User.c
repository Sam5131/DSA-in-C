// Create LL by taking input from user
// Delete the first element
// Display it

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
    int data;
    struct node *fnNode, *temp;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Memory cannot be allocated\n");
    }
    else
    {
        printf("Enter data for node 1: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        temp = head;
        for (int i = 2; i <= n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if (fnNode == NULL)
            {
                printf("Memory cannot be allocated further");
                break;
            }
            else
            {
                printf("Enter the data for node %d: ", i);
                scanf("%d", &data);
                fnNode->data = data;
                fnNode->next = NULL;
                temp->next = fnNode;
                temp = temp->next;
            }
        }
    }
}
void display()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        ptr=head;
        while (ptr != NULL)
        {
            printf("Element: %d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}
struct node *delete_begin(struct node *head)
{
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
int main()
{   int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    create(n);
    printf("Initial List:\n");
    display();
    head=delete_begin(head);
    printf("List after deletion:\n");
    display();
}