//WAP to create a doubly linked list by taking input from user
//Delete the element from end

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;

void create(int n)
{
    int data;
    struct node *fnNode,*temp,*enNode;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Memory cannot be allocated");
        exit(1);
    }
    else
    {
        printf("Enter the data for node 1: ");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        head->prev=NULL;
        temp=head;
        enNode=head;
        for(int i=2;i<=n;i++)
        {
            fnNode=(struct node*)malloc(sizeof(struct node));
            if(fnNode==NULL)
            {
                printf("Memory cannot be allocated further");
                break;
            }
            else
            {
                printf("Enter the data for node %d: ",i);
                scanf("%d",&data);
                fnNode->data=data;
                fnNode->next=NULL;
                fnNode->prev=temp;
                temp->next=fnNode;
                temp=temp->next;
                enNode=fnNode;
            }
        }
    }
}

void display()
{
    struct node *ptr=head;
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}

struct node *delete_end(struct node *head)
{
    struct node *p=head;
    struct node *q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    create(n);
    printf("The doubly linked list is:\n");
    display();
    printf("The doubly linked list after deletion is:\n");
    head=delete_end(head);
    display();
    return 0;
}