#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (!new_node)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(node **head, int data, int position)
{
    if (position <= 0)
    {
        printf("Invalid position. Position must be greater than 0.\n");
        return;
    }

    node *new_node = create_node(data);
    if (!new_node)
        return;
    if (position > 1 && *head == NULL)
    {
        printf("Invalid Location");
        return;
    }
    if (position == 1 || *head == NULL)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    node *current = *head;
    while (position > 2 && current != NULL)
    {
        current = current->next;
        position--;
    }

    if (current == NULL)
    {
        printf("Invalid position.\n");
        free(new_node);
        return;
    }

    new_node->next = current->next;
    current->next = new_node;
}

void delete_node(node **head, int position)
{
    if (position <= 0)
    {
        printf("Invalid position. Position must be greater than 0.\n");
        return;
    }

    if (*head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    node *temp;
    if (position == 1)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    node *current = *head;
    while (position > 2 && current != NULL)
    {
        current = current->next;
        position--;
    }

    if (current == NULL || current->next == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    temp = current->next;
    current->next = temp->next;
    free(temp);
}

void update_node(node *head, int position, int new_data)
{
    if (position <= 0)
    {
        printf("Invalid position. Position must be greater than 0.\n");
        return;
    }

    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    node *current = head;
    while (position > 1 && current != NULL)
    {
        current = current->next;
        position--;
    }

    if (current == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    current->data = new_data;
}

void display_list(node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    printf("The Linked List is: ");
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void free_list(node **head)
{
    node *current = *head;
    node *next_node;
    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head = NULL;
}

int main()
{
    node *head = NULL;
    int number_of_operations;

    printf("Enter the number of operations you want to perform: ");
    scanf("%d", &number_of_operations);
    if (!(number_of_operations >= 1 && number_of_operations <= 100))
    {
        printf("Invalid input for the number of operations.\n");
        return 0;
    }

    for (int i = 0; i < number_of_operations; i++)
    {
        int choice;
        printf("\n1. Insert at beginning\n2. Insert at position\n3. Insert at end\n4. Display\n5. Update at position\n6. Delete at start\n7. Delete at position\n8. Delete at end\n");
        printf("\nEnter a choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int data;
            printf("\nEnter the data to be inserted at the beginning: ");
            scanf("%d", &data);
            insert_node(&head, data, 1);
        }
        else if (choice == 2)
        {
            int position, data;
            printf("\nEnter the data to be inserted: ");
            scanf("%d", &data);
            printf("\nEnter the position: ");
            scanf("%d", &position);
            insert_node(&head, data, position);
        }
        else if (choice == 3)
        {
            int data;
            printf("\nEnter the data to be inserted at the end: ");
            scanf("%d", &data);
            int position = 1;
            node *current = head;
            while (current != NULL)
            {
                position++;
                current = current->next;
            }
            insert_node(&head, data, position);
        }
        else if (choice == 4)
        {
            display_list(head);
        }
        else if (choice == 5)
        {
            int position, new_data;
            printf("\nEnter the position to be updated: ");
            scanf("%d", &position);
            printf("\nEnter the new data: ");
            scanf("%d", &new_data);
            update_node(head, position, new_data);
        }
        else if (choice == 6)
        {
            delete_node(&head, 1);
        }
        else if (choice == 7)
        {
            int position;
            printf("\nEnter the position to delete: ");
            scanf("%d", &position);
            delete_node(&head, position);
        }
        else if (choice == 8)
        {
            int position = 0;
            node *current = head;
            while (current != NULL)
            {
                position++;
                current = current->next;
            }
            delete_node(&head, position);
        }
        else
        {
            printf("Invalid selection. Please select between 1 to 8.\n");
        }
    }

    free_list(&head);
    return 0;
}
