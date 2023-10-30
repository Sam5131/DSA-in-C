//Create LL by taking input from user
//Take an element from user and input it in begin
//Display it

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
    int data;
    struct node *fnNode,*temp;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Memory cannot be allocated");
    }
    else
    {
        printf("Enter data of node 1: ");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        temp=head;
        for(int i=2;i<=n;i++)
        {
            fnNode=(struct node*)malloc(sizeof(struct node));
            if(fnNode==NULL)
            {
                printf("Memory cannot be allocated");
                break;
            }
            else
            {
                printf("Enter data of node %d: ",i);
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
    struct node *ptr;
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            printf("Data: %d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}
struct node *insert_begin(struct node *head, int data)
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->next=head;
    head=p;
    return head;
}
int main()
{
    int n,data;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    create(n);
    printf("The list: \n");
    display();
    printf("Enter the data to be inserted:");
    scanf("%d",&data);
    head=insert_begin(head,data);
    printf("The list after insertion: \n");
    display();
}