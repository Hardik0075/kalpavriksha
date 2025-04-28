#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void push_in_stack(node **head, int *top, int value_to_push_in_stack)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }
    new_node->data = value_to_push_in_stack;
    new_node->next = *head;
    *head = new_node;
    (*top)++;
}

void pop_from_stack(node **head, int *top)
{
    if (*head == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    node *temp = *head;
    *head = (*head)->next;
    free(temp);
    (*top)--;
}

void peek_of_stack(node *head)
{
    if (head == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top element is %d\n", head->data);
    }
}

void is_stack_empty(node *head)
{
    if (head == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack is Not Empty\n");
    }
}

void size_of_stack(int top)
{
    printf("Stack size: %d\n", top + 1);
}

void free_list(node *head)
{
    node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    head = NULL;
}

int main()
{
    node *head = NULL;
    int top = -1;

    while (1)
    {
        printf("\nYour choices are:\n1. Push in stack\n2. Pop from stack\n3. Peek of stack\n4. Check if stack is empty\n5. Size of stack\n6. Exit\n");
        int choice;
        printf("Enter Choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int value_to_push_in_stack;
            printf("Enter value to push into stack: ");
            scanf("%d", &value_to_push_in_stack);
            push_in_stack(&head, &top, value_to_push_in_stack);
        }
        else if (choice == 2)
        {
            pop_from_stack(&head, &top);
        }
        else if (choice == 3)
        {
            peek_of_stack(head);
        }
        else if (choice == 4)
        {
            is_stack_empty(head);
        }
        else if (choice == 5)
        {
            size_of_stack(top);
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            printf("Invalid Choice! Try Again.\n");
        }
    }

    free_list(head);
    return 0;
}
