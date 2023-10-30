//Create a linked list
//delete an element for an index
//display it

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element in node: %d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct node *delete_btwn(struct node *head,int index)
{
    struct node *p=head;
    struct node *q=head->next;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
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
    head=delete_btwn(head,2);
    display(head);
    return 0;
}