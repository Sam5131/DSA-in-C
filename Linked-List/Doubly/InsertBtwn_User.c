//WAP to create a doubly linked list by taking input from user
//Insert an element at the desired index by taking input from user

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
    int n,index,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    create(n);
    printf("The initial doubly linked list is:\n");
    display();
    printf("Enter the data to be inserted: ");
    scanf("%d",&data);
    printf("Enter the index at which you want to insert the data: ");
    scanf("%d",&index);
    head=insert_btwn(head,data,index);
    printf("The final doubly linked list is:\n");
    display();
    return 0;
}