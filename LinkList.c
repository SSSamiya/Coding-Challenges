/*
Program for link list
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *ptr;
    
};

void insertNode(struct node **head)
{
    int num;   
    struct node *temp = *head;
    struct node *newNode = (struct node *) malloc(sizeof(struct node));

    printf("Enter Data for Node : ");
    scanf("%d", &num);
    newNode->data = num;
    newNode->ptr = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        while(temp->ptr != NULL)
            temp = temp->ptr;
        temp->ptr = newNode;
    }
}
void PrintList(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->ptr;
    }
}
int DeleteNode(struct node **head)
{
    struct node *temp1, *temp2;
    int num;
    if(*head != NULL)
    {
        temp1 = *head;
        temp2 = temp1->ptr;
    }
    else
    {
        printf("List is Empty\n");
        return 0;
    }
    
    printf("Enter Node value to Delete : ");
    scanf("%d", &num);
    //If First Node
    if(temp1->data == num)
    {
        *head = temp1->ptr;
        return 0; 
    }
    else
    {
        while(temp2 != NULL)
        {
            if(temp2->data == num)
            {
                temp1->ptr = temp2->ptr;
                return 0;
            }
            else
            {
                temp2 = temp2->ptr;
                temp1 = temp1->ptr;
            }   
        }
    }  
}
void SearchNode(struct node *head)
{
    int search;
    printf("Enter Value to Search :");
    scanf("%d", &search);
    while(head != NULL)
    {
        if(head->data == search)
        {
            printf("Node is Present\n");
        }
        else
        {
            head = head->ptr;
        }
    }
    if(head == NULL)
    {
        printf("Node is not Present\n");
    }

}
int UpdateNode(struct node **head)
{
    int old_value, new_value;
    struct node *temp = *head;

    printf("Enter Node Value to Update : ");
    scanf("%d", &old_value);
    printf("Enter New Value : ");
    scanf("%d", &new_value);

    while(temp != NULL)
    {
        if(temp->data == old_value)
        {
            temp->data = new_value;
            printf("Node value Updated\n");
            return 0;
        }
        else
        {
            temp = temp->ptr;
        }
    }
    if(temp == NULL)
    {
        printf("Node is not Present in the List\n");
    }
}
void Reverse(struct node *head)
{
    struct node *temp1 = head;
    struct node *temp2, *temp3 = NULL;
    temp2 = temp1->ptr;

    while(temp1 != NULL)
    {
        temp1->ptr = temp3;
        temp3 = temp1;
        temp1 = temp2;
        if(temp2 != NULL)
        {
            temp2 = temp2->ptr;
        }
        else
        {
            head = temp3;
        }
    }
    PrintList(head);
    /*while(head != NULL)
    {
        printf("%d\n", head->data);
        head = head->ptr;
    }*/
}
int sort(struct node **head)
{
    int value;
    struct node *temp1, *temp2, *temp3, *ptr_value;
    if(*head != NULL)
    {
        temp1 = *head;
        temp3 = head;
    }
    else
    {
        printf("List is Empty");
        return 0;
    }
    while(temp1 != NULL)
    {
        temp2 = temp1->ptr;
        while(temp2 != NULL)
        {
            if(temp1->data > temp2->data)
            {
                //Swapping by value
                /*value = temp1->data;
                temp1->data = temp2->data;
                temp2->data = value;*/

                //Swapping by pointer
                ptr_value = temp1->ptr;
                temp1->ptr = temp2->ptr;
                temp2->ptr = temp1;
                temp3 = temp2;
                temp1 = temp2;

                PrintList(temp3);
            }
            temp2 = temp2->ptr;
        }
        temp3 = temp1;
        temp1 = temp1->ptr;
    }
}
int main()
{
    struct node *head = NULL;
    int choice;
    while(1)
    {
        printf("1.Insert Node\n2.Delete Node\n3.Print List\n4.Search Node\n5.Update Node\n6.Print List in Reverse\n7.Sort List\n8.Exit\n");
        printf("Select Operation : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insertNode(&head);
                break;
            case 2:
                DeleteNode(&head);
                break;
            case 3:
                PrintList(head);
                break;
            case 4:
                SearchNode(head);
                break;
            case 5:
                UpdateNode(&head);
                break;
            case 6:
                Reverse(head);
                break;
            case 7: 
                sort(&head);
                break;
            case 8:
                exit(0);
        }
    }
    return 0;
}