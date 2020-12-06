#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* CreateNode(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void insert(struct node **root, int value)
{
    if(*root == 0)
    {
        *root = CreateNode(value);
    }
    else if(value < (*root)->data)
    {
        insert(&(*root)->left, value);
    }
    else if(value > (*root)->data)
    {
        insert(&(*root)->right, value);
    }
}
void Preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d\n", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
    else
    {
        return;
    }
    
}
void Inorder(struct node *root)
{
    if(root != NULL)
    {
        Inorder(root->left);
        printf("%d\n", root->data);
        Inorder(root->right);
    }
    else
        return;
    
}
void Postorder(struct node *root)
{
    if(root != NULL)
    {
        Inorder(root->left);
        Inorder(root->right);
        printf("%d\n", root->data);
    }
    else
        return;
    
}

int main()
{
    int value;
    struct node *root = NULL;
    printf("Enter Data for  Node : ");
    scanf("%d", &value);

    insert(&root, value);   
    insert(&root, 4);
    insert(&root, 7);
    insert(&root, 1);
    insert(&root, 10);
    printf("Preorder Traversal : \n");
    Preorder(root);
    printf("Inorder Traversal : \n");
    Inorder(root);
    printf("Postorder Traversal : \n");
    Postorder(root);
    return 0;
}