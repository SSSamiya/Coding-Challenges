#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define SIZE 10
struct stack
{
    int data[SIZE];
    int top;
};  
bool isEmpty(struct stack **s)
{
    if((*s)->top == -1)
        return true;
    else
        return false;
}
bool isFull(struct stack **s)
{
    if((*s)->top == SIZE - 1)
        return true;
    else
        return false;
} 
int Push(struct stack *s)
{
    int num;
    if(isFull(&s))
    {
        printf("Can't push element, Stack is already full.\n");
        return 0;
    }
    else
    {
        printf("Enter Data : ");
        scanf("%d", &num);
        s->top = s->top + 1;
        s->data[s->top] = num;
    }
}
int Pop(struct stack *s)
{
    if(isEmpty(&s))
    {
        printf("Can't pop element, Stack is Empty.\n");
        return 0;
    }
    else
    {
        printf("Element Popped : %d\n", s->data[s->top]);
        s->top = s->top - 1;
    }
}
int Print(struct stack *s)
{
    int i;
    if(isEmpty(&s))
    {
        printf("Stack is Empty\n");
        return 0;
    }
    else
    {
        printf("Stack Contains Following Elements : \n");
        for(i = s->top; i >= 0; i--)
        {
            printf("%d\n", s->data[i]);
        }
    }
    printf("\n");
}
int main()
{
    int choice;
    struct stack s;
    s.top = -1;
    while(1)
    {
        printf("1.Push Element\n2.Pop Element\n3.Print\n4.Exit\n");
        printf("Select Option : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                Push(&s);
                break;
            case 2:
                Pop(&s);
                break;
            case 3:
                Print(&s);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}