//Create list by taking input from user
//Take input from data and insert at end
//Display the list

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

void createLL(int n)
{
    int data,i;
    struct node *fnNode,*temp;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Memory can't be allocated");
    }
    else
    {
        printf("Enter the data for node 1: ");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        temp=head;
        for(int i=2;i<=n;i++)
        {
            fnNode=(struct node*)malloc(sizeof(struct node));
            if(fnNode==NULL)
            {
                printf("Memory can't be allocated further");
            }
            else
            {
                printf("Enter the data for node %d: ",i);
                scanf("%d",&data);
                fnNode->data=data;
                fnNode->next=NULL;
                temp->next=fnNode;
                temp=temp->next;
            }
        }
    }
}

void displayLL()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("The List is Empty");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}

struct node *insert_End(struct node *head,int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    ptr->data=data;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

int main()
{
    int n,data;
    printf("Enter the number of Nodes: ");
    scanf("%d",&n);
    createLL(n);
    printf("The list: \n");
    displayLL();
    printf("Enter the data to be inserted: ");
    scanf("%d",&data);
    printf("List after insertion: \n");
    head=insert_End(head,data);
    displayLL();
    return 0;
}