//WAP to linear search in singly linkedlist
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void create(int n)
{
    head=(struct node*)malloc(sizeof(struct node));
    struct node *fnNode,*temp;
    if(head==NULL)
    {
        printf("Memory cannot be allocated");
    }
    else
    {
        int i,data;
        
        printf("Enter the data of the node 1:\n");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        temp=head;
        for(i=2;i<=n;i++)
        {
            struct node *fnNode=(struct node*)malloc(sizeof(struct node));
            if(fnNode==NULL)
            {
                printf("Memory cannot be allocated");
            }
            else
            {
                printf("Enter the data of the node %d\n",i);
                scanf("%d",&data);
                fnNode->data=data;
                fnNode->next=NULL;
                temp->next=fnNode;
                temp=temp->next;
            }
        }
    }
}

void display()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}

void searching(int value)
{
    struct node *temp;
    int pos=0;
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            pos++;
            if(temp->data==value)
            {
                printf("Element %d found at position %d\n",value,pos);
                break;
            }
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("Element %d not found\n",value);
        }
    }
}

int main()
{
    int n,value;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    create(n);
    printf("The elements of the linked list are:\n");
    display();
    printf("Enter the element to be searched:\n");
    scanf("%d",&value);
    searching(value);
    return 0;
}