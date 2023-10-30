//WAP to create a circular linkedlist self initialized
//Delete an element in the desired index
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

    printf("The circular linkedlist is:\n");
    display(head);

    head=delete_btwn(head,3);

    printf("The circular linkedlist after deletion is:\n");
    display(head);

    return 0;
}