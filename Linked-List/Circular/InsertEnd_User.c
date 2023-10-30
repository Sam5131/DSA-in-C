//WAP to initialized a user input circular linkedlist
//Insert an element from the user in the end of the linkedlist
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
    head=(struct node*)malloc(sizeof(struct node));
    struct node *fnNode,*temp;
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
        head->next=head;        
        temp=head;

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
                fnNode->next=head;
                
                temp->next=fnNode;
                temp=fnNode;
            }
        }
    }
}

void display()
{
    struct node *current=head;
    
    if(head==NULL)
    {
        printf("The list is Empty\n");
    }
    else
    {
        do
        {
            printf("%d\n",current->data);
            current=current->next;
        }while(current!=head);
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
    int data,n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    create(n);
    printf("The list:\n");
    display();

    printf("Enter the data to be inserted: ");
    scanf("%d",&data);
    head=insert_end(head,data);

    printf("The updated list:\n");
    display();

    return 0;
}