#include <stdio.h>

void enqueue(int stack1[], int *top_of_stack1, int maximum_size_of_stack, int value_to_insert)
{
    if (*top_of_stack1 == maximum_size_of_stack)
    {
        printf("overflow will \n");
        return;
    }
    stack1[++(*top_of_stack1)] = value_to_insert;
}

void dequeue(int stack1[], int *top_of_stack1, int stack2[], int *top_of_stack2)
{
    if (*top_of_stack1 == -1)
    {
        printf("underflow will \n");
        return;
    }
    while (*top_of_stack1 != -1)
    {
        stack2[++(*top_of_stack2)] = stack1[(*top_of_stack1)--];
    }
    --(*top_of_stack2);
    while (*top_of_stack2 != -1)
    {
        stack1[++(*top_of_stack1)] = stack2[(*top_of_stack2)--];
    }
}

void peek(int stack1[], int top_of_stack1, int stack2[], int top_of_stack2)
{
    if (top_of_stack1 == -1)
    {
        printf("Nothing\n");
        return;
    }
    while (top_of_stack1 != -1)
    {
        stack2[++(top_of_stack2)] = stack1[(top_of_stack1)--];
    }
    printf("peak is %d\n", stack2[top_of_stack2]);
    while (top_of_stack2 != -1)
    {
        stack1[++(top_of_stack1)] = stack2[(top_of_stack2)--];
    }
}

void is_empty(int stack[], int top)
{
    if (top == -1)
    {
        printf("Yes it empty\n");
        return;
    }
    printf("No its not empty\n");
}

void find_size(int stack[], int top)
{
    if (top == -1)
    {
        printf("size of queue is 0\n");
    }
    else
    {
        printf("size of queue is %d\n", top + 1);
    }
}

int main()
{
    int maximum_size_of_stack;
    printf("Enter Maximum size of stacks : ");
    scanf("%d", &maximum_size_of_stack);
    int stack1[maximum_size_of_stack], stack2[maximum_size_of_stack];
    int top_of_stack1 = -1, top_of_stack2 = -1;
    while (1)
    {
        int choice;
        printf("Enter choice (1-Enqueue, 2-Dequeue, 3-Peek of queue , 4-Is queue empty, 5-Find Size of queue, 6-Exit): ");
        printf("Enter Choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int value_to_insert;
            printf("enter number to insert : ");
            scanf("%d", &value_to_insert);
            enqueue(stack1, &top_of_stack1, maximum_size_of_stack, value_to_insert);
        }
        else if (choice == 2)
        {
            dequeue(stack1, &top_of_stack1, stack2, &top_of_stack2);
        }
        else if (choice == 3)
        {
            peek(stack1, top_of_stack1, stack2, top_of_stack2);
        }
        else if (choice == 4)
        {
            is_empty(stack1, top_of_stack1);
        }
        else if (choice == 5)
        {
            find_size(stack1, top_of_stack1);
        }
        else
        {
            break;
        }
    }
    return 0;
}
