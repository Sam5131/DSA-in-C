//WAP to implement binary search using linkedlist
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
        
        printf("Enter the data of the node 1:");
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
                printf("Enter the data of the node %d:",i);
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
        printf("The list is:\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}

void binarySearch(int data)
{
    int left=0;
    int right=-1;
    struct node *temp=head;
    while(temp!=NULL)
    {
        right++;
        temp=temp->next;
    }
    int mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        temp=head;
        int i=0;
        for(int i=0;i<mid;i++)
        {
            temp=temp->next;
        }
        if(temp->data==data)
        {
            printf("Element found at %d position",mid+1);
            break;
        }
        else if(temp->data>data)
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
}

int main()
{
    int n,data;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    create(n);
    display();
    printf("Enter the element to be searched\n");
    scanf("%d",&data);
    binarySearch(data);
    return 0;
}