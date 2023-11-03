//Create a in order algorithm binary search tree and delete elements self initialized
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

void read_inorder(struct node *root)
{
    if(root!=NULL)
    {
        read_inorder(root->left);
        printf("%d ",root->data);
        read_inorder(root->right);
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
        //Node with 1 or No child
        if(root->left==NULL)
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
            //Node with 2 children
            struct node *MinRight=findMin(root->right);
            root->data=MinRight->data;
            root->right=delete(root->right,MinRight->data);
        }
    }
    return root;
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
    printf("Inorder traversal of BST before deletion\n");
    read_inorder(root);
    printf("\n");
    printf("After deletion of 20\n");
    root=delete(root,20);
    read_inorder(root);
    printf("\n");
    printf("After deletion of 30\n");
    root=delete(root,30);
    read_inorder(root);
    printf("\n");
    printf("After deletion of 70\n");
    root=delete(root,70);
    read_inorder(root);
    return 0;
}*/


int main()
{
    int n,data;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    printf("Enter the data to be inserted:\n");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&data);
        root=insert(root,data);
    }
    printf("Inorder traversal of BST:\n");
    read_inorder(root);
    printf("\nEnter the number of elements to be deleted:\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("Enter the data to be deleted:\n");
        scanf("%d",&data);
        root=delete(root,data);
        printf("BST after deletion of %d\n",data);
        read_inorder(root);
        printf("\n");
    }
}