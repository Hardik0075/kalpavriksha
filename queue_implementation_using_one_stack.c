#include <stdio.h>

void enqueue(int stack[], int *top_of_stack, int size_of_stack, int value_to_insert)

{

    if (*top_of_stack == size_of_stack - 1)

    {

        printf("Queue overflow\n");

        return;
    }

    stack[++(*top_of_stack)] = value_to_insert;
}

int dequeue(int stack[], int *top_of_stack, int size_of_stack)

{

    if (*top_of_stack == -1)

    {

        printf("Queue underflow\n");

        return -1;
    }

    int temporary_variable = stack[(*top_of_stack)--];

    if (*top_of_stack == -1)

        return temporary_variable;

    int dequeued_element = dequeue(stack, top_of_stack, size_of_stack);

    enqueue(stack, top_of_stack, size_of_stack, temporary_variable);

    return dequeued_element;
}

void peek_of_queue(int stack[], int top_of_stack)
{
    if (top_of_stack == -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    if (top_of_stack == 0)
    {
        printf("Peek is %d\n", stack[top_of_stack]);
        return;
    }
    peek_of_queue(stack, top_of_stack - 1);
}

void is_queue_empty(int top_of_stack)

{

    if (top_of_stack == -1)

        printf("Queue is empty\n");

    else

        printf("Queue is not empty\n");
}

void find_size_of_queue(int top_of_stack)

{

    if (top_of_stack == -1)

    {

        printf("Queue is empty\n");

        return;
    }

    printf("Size of queue: %d\n", top_of_stack + 1);
}

int main()

{

    int size_of_stack;

    printf("Enter size of stack: ");

    scanf("%d", &size_of_stack);

    int stack[size_of_stack];

    int top = -1;

    while (1)

    {

        int choice;

        printf("Enter choice (1-Enqueue, 2-Dequeue, 3-Peek of queue , 4-Is queue empty, 5-Find Size of queue, 6-Exit): ");

        scanf("%d", &choice);

        if (choice == 1)

        {

            int value_to_insert;

            printf("Enter value to insert: ");

            scanf("%d", &value_to_insert);

            enqueue(stack, &top, size_of_stack, value_to_insert);
        }

        else if (choice == 2)

        {

            int dequeued = dequeue(stack, &top, size_of_stack);

            if (dequeued != -1)

                printf("Dequeued: %d\n", dequeued);
        }

        else if (choice == 3)

        {

            peek_of_queue(stack, top);
        }

        else if (choice == 4)

        {

            is_queue_empty(top);
        }

        else if (choice == 5)

        {

            find_size_of_queue(top);
        }

        else

        {

            break;
        }
    }

    return 0;
}
