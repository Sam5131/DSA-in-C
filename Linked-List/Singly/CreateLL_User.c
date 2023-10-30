//Create LL by taking data from user
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
int main()
{
    int n;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    create(n);
    printf("The list: \n");
    display();
}