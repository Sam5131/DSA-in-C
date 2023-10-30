//WAP to create a self initialized circular linkedlist
//Delete the first element
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void display(struct node *head)
{
    struct node *current=head;
    if(head==NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        do
        {
            printf("%d\n",current->data);
            current=current->next;
        }
        while(current!=head);
    }
}
struct node *delete_beg(struct node *head)
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
        last = last->next;
    }

    head = head->next;
    last->next = head;
    free(current);

    return head; 
}

int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node));
    struct node *fourth=(struct node*)malloc(sizeof(struct node));

    head->data=5;
    head->next=second;

    second->data=10;
    second->next=third;

    third->data=15;
    third->next=fourth;

    fourth->data=20;
    fourth->next=head;

    printf("The list is:\n");
    display(head);

    printf("The list after deletion is:\n");
    head=delete_beg(head);
    display(head);

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}