#include <stdio.h>

void push(int queue[], int *front, int *rear, int value_to_insert, int size)
{
    if ((*rear + 1) % size == *front)
    {
        printf("Stack Overflow\n");
        return;
    }
    if (*front == -1)
    {
        *front = 0;
        *rear = 0;
    }
    else
    {
        *rear = (*rear + 1) % size;
    }

    queue[*rear] = value_to_insert;
    int count = (*rear - *front + size) % size;
    for (int index = 0; index < count; index++)
    {
        int temp = queue[*front];
        *front = (*front + 1) % size;
        *rear = (*rear + 1) % size;
        queue[*rear] = temp;
    }
}

void pop(int queue[], int *front, int *rear, int size)
{
    if (*front == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Popped element: %d\n", queue[*front]);

    if (*front == *rear)
    {
        *front = *rear = -1;
    }
    else
    {
        *front = (*front + 1) % size;
    }
}

void peek(int queue[], int front)
{
    if (front == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n", queue[front]);
}

void is_empty(int front)
{
    if (front == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }
}

void stack_size(int front, int rear, int size)
{
    if (front == -1)
    {
        printf("Stack size is 0\n");
        return;
    }
    int count = (rear - front + size) % size + 1;
    printf("Stack size is %d\n", count);
}

int main()
{
    int size_of_stack;
    printf("Enter stack size: ");
    scanf("%d", &size_of_stack);

    int queue[size_of_stack];
    int front = -1, rear = -1;

    while (1)
    {
        printf("\nChoose an operation:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Is Empty\n5. Size\n6. Exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter value to push: ");
            int value;
            scanf("%d", &value);
            push(queue, &front, &rear, value, size_of_stack);
        }
        else if (choice == 2)
        {
            pop(queue, &front, &rear, size_of_stack);
        }
        else if (choice == 3)
        {
            peek(queue, front);
        }
        else if (choice == 4)
        {
            is_empty(front);
        }
        else if (choice == 5)
        {
            stack_size(front, rear, size_of_stack);
        }
        else
        {
            break;
        }
    }

    return 0;
}
