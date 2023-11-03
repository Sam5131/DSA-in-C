//Create a Binary Search Tree with post order algorithm and delete element
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
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void read_postorder(struct node *root)
{
    if(root!=NULL)
    {
        read_postorder(root->left);
        read_postorder(root->right);
        printf("%d ",root->data);
    }
}

struct node *insert(struct node *root,int data)
{
    if(root==NULL)
    {
        return createNode(data);
    }
    else if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=insert(root->right,data);
    }
    return root;
}

struct node *findMin(struct node *root)
{
    struct node *temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}

struct node *delete(struct node *root,int data)
{
    if(root==NULL)
    {
        return root;
    }
    else if(data<root->data)
    {
        root->left=delete(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=delete(root->right,data);
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            root=NULL;
        }
        else if(root->left==NULL)
        {
            struct node *temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL)
        {
            struct node *temp=root;
            root=root->left;
            free(temp);
        }
        else
        {
            struct node *temp=findMin(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
    }
    return root;
}

int main()
{
    int n,data;
    printf("Enter the number of elements to be inserted in the tree\n");
    scanf("%d",&n);
    printf("Enter the elements to be inserted in the tree\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        root=insert(root,data);
    }
    printf("The elements in the tree are\n");
    read_postorder(root);
    printf("\nEnter the element to be deleted\n");
    scanf("%d",&data);
    root=delete(root,data);
    printf("The elements in the tree after deletion are\n");
    read_postorder(root);
    return 0;
}

/*int main()
{
    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    printf("Postorder traversal of BST before deletion\n");
    read_postorder(root);
    printf("\n");
    printf("After deletion of 20\n");
    root=delete(root,20);
    read_postorder(root);
    printf("\n");
    printf("After deletion of 30\n");
    root=delete(root,30);
    read_postorder(root);
    printf("\n");
    printf("After deletion of 70\n");
    root=delete(root,70);
    read_postorder(root);
    return 0;
}*/