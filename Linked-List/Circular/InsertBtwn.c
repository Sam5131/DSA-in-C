//WAP to create a circular linkedlist self initialized
//Insert an element at the desired node
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

    printf("The list after insertion is:\n");
    head=insert_btwn(head,25,2);
    display(head);

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}