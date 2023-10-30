//WAP to create a circular linkedlist
//Insert an element at the end
//WAP to create a circular linked list
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

struct node *insert_end(struct node *head,int data)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    struct node *last=head;
    do
    {
        last=last->next;
    } while (last->next!=head);
    last->next=new_node;
    new_node->next=head;
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

    printf("List after insertion:\n");
    head=insert_end(head,25);
    display(head);

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}