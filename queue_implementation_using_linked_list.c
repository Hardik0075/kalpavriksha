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
        return;
    }

    (*rear_pointer)->next = new_node;
    *rear_pointer = new_node;
}

int dequeue(node **front_pointer, node **rear_pointer)
{
    if (*front_pointer == NULL)
    {
        printf("Queue underflow\n");
        return -1;
    }
    node *temporary_node = *front_pointer;
    printf("Dequeued element is %d\n", temporary_node->data);
    *front_pointer = (*front_pointer)->next;

    if (*front_pointer == NULL)
    {
        *rear_pointer = NULL;
    }
    free(temporary_node);
}

void peek_of_queue(node *front_pointer)
{
    if (front_pointer == NULL)
    {
        printf("queue is empty\n");
        return;
    }
    printf("%d is peak element\n", front_pointer->data);
}

void is_queue_empty(node *front_pointer)
{
    if (front_pointer == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue is not empty\n");
}

void size_of_queue(node *front_pointer)
{
    if (front_pointer == NULL)
    {
        printf("size of queue is 0\n");
        return;
    }
    int length_of_queue = 0;
    while (front_pointer != NULL)
    {
        length_of_queue++;
        front_pointer = front_pointer->next;
    }
    printf("%d is size of queue \n", length_of_queue);
}

void free_queue(node *front_pointer)
{
    while (front_pointer != NULL)
    {
        node *temp = front_pointer;
        front_pointer = front_pointer->next;
        free(temp);
    }
}

int main()
{
    node *front_pointer = NULL;
    node *rear_pointer = NULL;
    int number_of_operation;
    printf("Enter number of opeartion : ");
    scanf("%d", &number_of_operation);
    while (number_of_operation--)
    {
        printf("Your choices are :\n1.Push in queue\n2.Pop from queue\n3.Peek of queue\n4.is queue empty\n5.Size of queue\n6.Exit\n");
        int operation_user_want_to_apply;
        printf("Enter opeartion user want to apply : ");
        scanf("%d", &operation_user_want_to_apply);
        if (operation_user_want_to_apply == 1)
        {
            int value_to_insert_in_queue;
            printf("Enter value to insert in queue : ");
            scanf("%d", &value_to_insert_in_queue);
            enqueue(&front_pointer, &rear_pointer, value_to_insert_in_queue);
        }
        else if (operation_user_want_to_apply == 2)
        {
            dequeue(&front_pointer, &rear_pointer);
        }
        else if (operation_user_want_to_apply == 3)
        {
            peek_of_queue(front_pointer);
        }
        else if (operation_user_want_to_apply == 4)
        {
            is_queue_empty(front_pointer);
        }
        else if (operation_user_want_to_apply == 5)
        {
            size_of_queue(front_pointer);
        }
    }
    free_queue(front_pointer);
    return 0;
}
