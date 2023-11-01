//Create a PostOrder algorithm based Binary Search Tree by taking user input
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

struct node *createNode(int data)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void read_postorder(struct node *root)
{
    if (root != NULL)
    {
        read_postorder(root->left);
        read_postorder(root->right);
        printf("%d ", root->data);
    }
}

struct node *insert(struct node *root,int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

int main()
{
    int n, data;
    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &n);
    printf("Enter the data of the nodes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }
    read_postorder(root);
    return 0;
}