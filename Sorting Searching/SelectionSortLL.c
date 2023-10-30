//WAP to selection sort a linkedlist by taking user input
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

void SelectionSort(int n)
{
    struct node *p,*q;
    for(p=head;p!=NULL;p=p->next)
    {
        struct node *min=p;
        for(q=p->next;q!=NULL;q=q->next)
        {
            if(q->data<min->data)
            {
                min=q;
            }
            int temp=p->data;
            p->data=min->data;
            min->data=temp;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    create(n);
    printf("The elements of the linked list are:\n");
    display();
    SelectionSort(n);
    printf("The elements of the linked list after sorting are:\n");
    display();
    return 0;
}
