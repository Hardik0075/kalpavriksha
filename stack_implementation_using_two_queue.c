#include <stdio.h>

#define MAX_SIZE 100

void store_value_from_queue2_to_queue1(int queue1[], int queue2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        queue1[i] = queue2[i];
    }
}

void transfer_elements_from_queue1_to_queue2(int queue1[], int *front_of_queue1, int *rear_of_queue1, int queue2[], int *rear_of_queue2)
{
    while (*front_of_queue1 <= *rear_of_queue1)
    {
        queue2[++(*rear_of_queue2)] = queue1[(*front_of_queue1)++];
    }
}

void push_to_stack(int queue1[], int queue2[], int *front_of_queue1, int *rear_of_queue1, int *front_of_queue2, int *rear_of_queue2, int value_to_insert)
{
    if (*rear_of_queue1 == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    if (*front_of_queue2 == -1 && *rear_of_queue2 == -1)
    {
        *front_of_queue2 = 0;
        *rear_of_queue2 = 0;
        queue2[*rear_of_queue2] = value_to_insert;
    }
    else
    {
        queue2[++(*rear_of_queue2)] = value_to_insert;
    }

    transfer_elements_from_queue1_to_queue2(queue1, front_of_queue1, rear_of_queue1, queue2, rear_of_queue2);
    store_value_from_queue2_to_queue1(queue1, queue2, *rear_of_queue2 + 1);

    *front_of_queue1 = 0;
    *rear_of_queue1 = *rear_of_queue2;
    *front_of_queue2 = -1;
    *rear_of_queue2 = -1;
}

void pop_from_stack(int queue1[], int *front_of_queue1, int *rear_of_queue1)
{
    if (*front_of_queue1 == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Popped element: %d\n", queue1[*front_of_queue1]);
    (*front_of_queue1)++;

    if (*front_of_queue1 > *rear_of_queue1)
    {
        *front_of_queue1 = -1;
        *rear_of_queue1 = -1;
    }
}

void peek_of_stack(int queue[], int front)
{
    if (front == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is: %d\n", queue[front]);
}

void is_stack_empty(int front)
{
    printf("Stack is %s\n", front == -1 ? "empty" : "not empty");
}

void size_of_stack(int front, int rear)
{
    printf("Stack size is %d\n", front == -1 ? 0 : rear - front + 1);
}

int main()
{
    int queue1[MAX_SIZE], queue2[MAX_SIZE];
    int front_of_queue1 = -1, rear_of_queue1 = -1;
    int front_of_queue2 = -1, rear_of_queue2 = -1;

    while (1)
    {
        printf("\nChoose an operation:\n");
        printf("1. Push in stack\n2. Pop from stack\n3. Peek of stack\n4. Is stack Empty\n5. Size of stack\n6. Exit\n");
        printf("Enter choice: ");
        int user_choice;
        scanf("%d", &user_choice);

        switch (user_choice)
        {
        case 1:
        {
            printf("Enter value to push: ");
            int value_to_insert;
            scanf("%d", &value_to_insert);
            if (rear_of_queue1 == -1)
            {
                queue1[++rear_of_queue1] = value_to_insert;
                front_of_queue1 = 0;
            }
            else
            {
                push_to_stack(queue1, queue2, &front_of_queue1, &rear_of_queue1, &front_of_queue2, &rear_of_queue2, value_to_insert);
            }
            break;
        }
        case 2:
            pop_from_stack(queue1, &front_of_queue1, &rear_of_queue1);
            break;
        case 3:
            peek_of_stack(queue1, front_of_queue1);
            break;
        case 4:
            is_stack_empty(front_of_queue1);
            break;
        case 5:
            size_of_stack(front_of_queue1, rear_of_queue1);
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    }
}
