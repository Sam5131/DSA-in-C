//Create linked list using data taken from user
//Insert data in btwn that too taken from user
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

struct node *insert_in_btwn(struct node *head,int data, int index)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

int main()
{
    int n,data,index;
    printf("Enter the number of Nodes: ");
    scanf("%d",&n);
    createLL(n);
    printf("The list: \n");
    displayLL();
    printf("Enter the index for insertion:\n");
    scanf("%d",&index);
    printf("Enter the data to be inserted:\n");
    scanf("%d",&data);
    head=insert_in_btwn(head,data,index);
    printf("The List after insertion: \n");
    displayLL();
}