//WAP to create a doubly linked list by taking input from user
//Insert an element from user in the beginning 

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

struct node *insert_beg(struct node *head,int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    ptr->prev=NULL;
    head->prev=ptr;
    head=ptr;
    return head;
}

int main()
{
    int n,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    create(n);
    printf("The initial doubly linked list is:\n");
    display();
    printf("Enter the data to be inserted: ");
    scanf("%d",&data);
    head=insert_beg(head,data);
    printf("The final doubly linked list is:\n");
    display();
    return 0;
}

/*Output:
Enter the number of nodes: 3
Enter the data for node 1: 1
Enter the data for node 2: 2
Enter the data for node 3: 3
The initial doubly linked list is:
1
2
3
Enter the data to be inserted: 4
The final doubly linked list is:
4
1
2
3
*/