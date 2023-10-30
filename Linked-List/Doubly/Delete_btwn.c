//WAP to create a self initialized a doubly linkedlist
//Delete an element from a desired index
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
void display(struct node *head)
{
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
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
    q->next->prev=p; //q node ke next wala node ka previous address pointer ab p ko point karega
    free(q);
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
    head->prev=NULL;

    second->data=10;
    second->next=third;
    second->prev=head;

    third->data=15;
    third->next=fourth;
    third->prev=second;

    fourth->data=20;
    fourth->next=NULL;
    fourth->prev=third;
    
    printf("The list is:\n");
    display(head);
    printf("The list after deletion is:\n");
    head=delete_btwn(head,2);
    display(head);
    return 0;
}
/*Output:
The list is:
5
10
15
20
The list after deletion is:
5
10
20
*/