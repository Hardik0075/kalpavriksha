#include <stdio.h>

void enqueue(int queue[], int *front, int *rear, int value_to_insert_in_queue, int size_of_queue)
{
    if (*rear == size_of_queue - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (*front == -1)
        *front = 0;

    queue[++(*rear)] = value_to_insert_in_queue;
    printf("%d inserted into queue\n", value_to_insert_in_queue);
}

void dequeue(int queue[], int *front, int *rear)
{
    if (*front == -1 || *front > *rear)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Removed element: %d\n", queue[*front]);

    if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        (*front)++;
    }
}

void peek_of_queue(int queue[], int front, int rear)
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Peek element is %d\n", queue[front]);
}

void is_queue_empty(int front, int rear)
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue is not empty\n");
}

void size_queue(int front, int rear)
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Size of queue is %d\n", rear - front + 1);
}

int main()
{
    int size_of_queue;
    printf("Enter size of queue: ");
    scanf("%d", &size_of_queue);

    int queue[size_of_queue];
    int front = -1, rear = -1;

    while (1)
    {
        printf("\nEnter the choice you want to implement on queue:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Is queue empty\n5. Size of queue\n6. Exit\n");
        printf("Enter choice: ");
        int operation_user_want_to_apply;
        scanf("%d", &operation_user_want_to_apply);
        
        if (operation_user_want_to_apply == 1)
        {
            int value_to_insert_in_queue;
            printf("Enter value to insert in queue: ");
            scanf("%d", &value_to_insert_in_queue);
            enqueue(queue, &front, &rear, value_to_insert_in_queue, size_of_queue);
        }
        else if (operation_user_want_to_apply == 2)
        {
            dequeue(queue, &front, &rear);
        }
        else if (operation_user_want_to_apply == 3)
        {
            peek_of_queue(queue, front, rear);
        }
        else if (operation_user_want_to_apply == 4)
        {
            is_queue_empty(front, rear);
        }
        else if (operation_user_want_to_apply == 5)
        {
            size_queue(front, rear);
        }
        else
        {
            break;
        }
    }
    return 0;
}
