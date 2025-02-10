#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void enqueue(node **front_pointer, node **rear_pointer, int value_to_insert_in_queue)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = value_to_insert_in_queue;
    new_node->next = NULL;

    if (*rear_pointer == NULL)
    {
        *front_pointer = new_node;
        *rear_pointer = new_node;
    }
    else
    {
        (*rear_pointer)->next = new_node;
        *rear_pointer = new_node;
    }
}

int dequeue(node **front_pointer, node **rear_pointer)
{
    if (*front_pointer == NULL)
    {
        printf("Queue underflow\n");
        return -1;
    }
    node *temporary_node = *front_pointer;
    int dequeued_value = temporary_node->data;

    *front_pointer = (*front_pointer)->next;

    if (*front_pointer == NULL)
    {
        *rear_pointer = NULL;
    }

    free(temporary_node);
    return dequeued_value;
}

void peek_of_queue(node *front_pointer)
{
    if (front_pointer == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element is %d\n", front_pointer->data);
}

void is_queue_empty(node *front_pointer)
{
    if (front_pointer == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is not empty\n");
    }
}

void size_of_queue(node *front_pointer)
{
    int length_of_queue = 0;
    while (front_pointer != NULL)
    {
        length_of_queue++;
        front_pointer = front_pointer->next;
    }
    printf("Queue size: %d\n", length_of_queue);
}

void free_queue(node **front_pointer, node **rear_pointer)
{
    while (*front_pointer != NULL)
    {
        node *temp = *front_pointer;
        *front_pointer = (*front_pointer)->next;
        free(temp);
    }
    *rear_pointer = NULL;
}

int main()
{
    node *front_pointer = NULL;
    node *rear_pointer = NULL;

    while (1)
    {
        printf("\nYour choices are:\n");
        printf("1. Enqueue (Insert in Queue)\n");
        printf("2. Dequeue (Remove from Queue)\n");
        printf("3. Peek (Front of Queue)\n");
        printf("4. Check if Queue is Empty\n");
        printf("5. Get Queue Size\n");
        printf("6. Exit\n");

        int operation_choice;
        printf("Enter operation number: ");
        scanf("%d", &operation_choice);

        if (operation_choice < 1 || operation_choice > 6)
        {
            printf("Invalid choice. Please enter a number between 1 and 6.\n");
            continue;
        }

        if (operation_choice == 1)
        {
            int value_to_insert_in_queue;
            printf("Enter value to enqueue: ");
            scanf("%d", &value_to_insert_in_queue);
            enqueue(&front_pointer, &rear_pointer, value_to_insert_in_queue);
        }
        else if (operation_choice == 2)
        {
            int dequeued_value = dequeue(&front_pointer, &rear_pointer);
            if (dequeued_value != -1)
            {
                printf("Dequeued element is %d\n", dequeued_value);
            }
        }
        else if (operation_choice == 3)
        {
            peek_of_queue(front_pointer);
        }
        else if (operation_choice == 4)
        {
            is_queue_empty(front_pointer);
        }
        else if (operation_choice == 5)
        {
            size_of_queue(front_pointer);
        }
        else if (operation_choice == 6)
        {
            break;
        }
    }

    free_queue(&front_pointer, &rear_pointer);
    return 0;
}
