//Create a linked list
//Delete the element in first index
//display the list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

void display(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element in node: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct node *delete_beg(struct node *head)
{
    struct node *ptr;
    ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node));
    struct node *fourth=(struct node*)malloc(sizeof(struct node));
    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=fourth;
    
    fourth->data=5;
    fourth->next=NULL;

    printf("Linked List before deletion: \n");
    display(head);
    printf("Linked List after deletion: \n");
    head=delete_beg(head);
    display(head);
    return 0;
}