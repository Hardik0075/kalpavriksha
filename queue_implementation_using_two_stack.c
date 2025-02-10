#include <stdio.h>

void enqueue(int stack1[], int *top_of_stack1, int maximum_size_of_stack, int value_to_insert)
{
    if (*top_of_stack1 == maximum_size_of_stack - 1)
    {
        printf("Queue Overflow: Cannot insert %d, the queue is full.\n", value_to_insert);
        return;
    }
    stack1[++(*top_of_stack1)] = value_to_insert;
    printf("Enqueued: %d\n", value_to_insert);
}

void dequeue(int stack1[], int *top_of_stack1, int stack2[], int *top_of_stack2)
{
    if (*top_of_stack1 == -1)
    {
        printf("Queue Underflow: No elements to dequeue.\n");
        return;
    }
    
    while (*top_of_stack1 != -1)
    {
        stack2[++(*top_of_stack2)] = stack1[(*top_of_stack1)--];
    }
    
    int dequeued_value = stack2[(*top_of_stack2)--];
    printf("Dequeued: %d\n", dequeued_value);

    while (*top_of_stack2 != -1)
    {
        stack1[++(*top_of_stack1)] = stack2[(*top_of_stack2)--];
    }
}

void peek(int stack1[], int top_of_stack1, int stack2[], int top_of_stack2)
{
    if (top_of_stack1 == -1)
    {
        printf("Queue is Empty: No elements to peek.\n");
        return;
    }

    while (top_of_stack1 != -1)
    {
        stack2[++(top_of_stack2)] = stack1[(top_of_stack1)--];
    }
    
    printf("Front Element (Peek): %d\n", stack2[top_of_stack2]);

    while (top_of_stack2 != -1)
    {
        stack1[++(top_of_stack1)] = stack2[(top_of_stack2)--];
    }
}

void is_empty(int top)
{
    if (top == -1)
    {
        printf("Queue Status: Empty\n");
    }
    else
    {
        printf("Queue Status: Not Empty\n");
    }
}

void find_size(int top, int maximum_size_of_stack)
{
    if (top == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue Size: %d\n", top + 1);
    }
}

int main()
{
    int maximum_size_of_stack;
    printf("Enter Maximum Queue Size: ");
    scanf("%d", &maximum_size_of_stack);
    
    int stack1[maximum_size_of_stack], stack2[maximum_size_of_stack];
    int top_of_stack1 = -1, top_of_stack2 = -1;

    while (1)
    {
        int choice;
        printf("Queue Operations:\n");
        printf("1 - Enqueue\n");
        printf("2 - Dequeue\n");
        printf("3 - Peek\n");
        printf("4 - Check if Empty\n");
        printf("5 - Find Size\n");
        printf("6 - Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int value_to_insert;
            printf("Enter value to insert: ");
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
            is_empty(top_of_stack1);
        }
        else if (choice == 5)
        {
            find_size(top_of_stack1, maximum_size_of_stack);
        }
        else if (choice == 6)
        {
            printf("Exiting Program...\n");
            break;
        }
        else
        {
            printf("Invalid Choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
