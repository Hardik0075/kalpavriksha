#include <stdio.h>
void push_in_stack(int stack[], int *top, int maximum_size_of_stack)
{
    if (*top == maximum_size_of_stack - 1)
    {
        printf("will overflow!\n");
    }
    else
    {
        int number_to_insert_in_stack;
        printf("enter number to insert in stack : ");
        scanf("%d", &number_to_insert_in_stack);
        stack[++(*top)] = number_to_insert_in_stack;
    }
}

void pop_from_stack(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("will underflow!\n");
    }
    else
    {
        --(*top);
    }
}

void peek_of_stack(int stack[], int top)
{
    if (top == -1)
    {
        printf("No element in stack\n");
    }
    else
    {
        printf("peak element is %d\n", stack[top]);
    }
}

void check_if_stack_is_empty(int top)
{
    if (top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("Not empty\n");
    }
}

void size_of_stack(int top)
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Size of stack is %d\n", top + 1);
}

int main()
{
    int maximum_size_of_stack;
    printf("Enter maximum size of stack : ");
    scanf("%d", &maximum_size_of_stack);
    int stack[maximum_size_of_stack];
    int top = -1;
    while (1)
    {
        int choice;
        printf("Enter operation you want to do : \n1. Push \n2. Pop \n3.Peek \n4.IsEmpty \n5.Size of stack \n6.Exit \n");
        printf("Enter Choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            push_in_stack(stack, &top, maximum_size_of_stack);
        }
        else if (choice == 2)
        {
            pop_from_stack(stack, &top);
        }
        else if (choice == 3)
        {
            peek_of_stack(stack, top);
        }
        else if (choice == 4)
        {
            check_if_stack_is_empty(top);
        }
        else if (choice == 5)
        {
            size_of_stack(top);
        }
        else
        {
            break;
        }
    }

    return 0;
}
