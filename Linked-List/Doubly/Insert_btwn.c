//Wap to create a self initialized linkedlist
//Insert an element in between the list
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
struct node *insert_btwn(struct node *head,int data,int index)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    ptr->prev=p;
    p->next->prev=ptr;
    p->next=ptr;
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
    printf("The list after insertion is:\n");
    head=insert_btwn(head,30,2);
    display(head);
    return 0;
}
/*Output:
The list is:
5
10
15
20
The list after insertion is:
5
10
30
15
20
*/