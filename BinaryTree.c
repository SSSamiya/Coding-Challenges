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
struct node *Search(struct node *root, int key)
{
    if(root != NULL)
    {
        if(key == root->data)
        {
            return root;
        }
        else if(key < root->data)
        {
            return Search(root->left, key);
        }
        else
        {
            return Search(root->right, key);
        }
    }
    else
    {
        return 0;
    }
    
}
struct node *Replace(struct node **root, int key)
{
    struct node *temp;
    int newValue;
    temp = Search(root, key);
    if(temp != NULL)
    {
        printf("Enter new value : ");
        scanf("%d", &newValue);
        temp->data = newValue;
    }
    else
    {
        printf("Element not Present\n");
    }
}
int main()
{
    int value, key;
    struct node *root = NULL;
    struct node *temp;
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

    printf("Enter Element to be Searched : ");
    scanf("%d", &key);
    temp = Search(root, key);
    if(temp != 0)
        printf("Element Present\n");
    else
        printf("Element not Present\n");
    
    printf("Enter Element to be Replaced : ");
    scanf("%d", &key);
    root = Replace(&root, key);
    return 0;
}