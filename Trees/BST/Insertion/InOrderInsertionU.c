//Create a user input inorder binary search tree
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;

struct node *createNode(int data)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->right=NULL;
    newNode->left=NULL;
    return newNode;
}

void read_inorder(struct node *root)
{
    if(root!=NULL)
    {
        read_inorder(root->left);
        printf("%d ",root->data);
        read_inorder(root->right);
    }
}

struct node *insert(struct node *root, int data)
{
    if(root==NULL)
    {
        return createNode(data);
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=insert(root->right,data);
    }
}

int main()
{
    int n,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("Enter the data: ");
        scanf("%d",&data);
        root=insert(root,data);
    }
    read_inorder(root);
    return 0;
}