#include <stdio.h>
#include <stdlib.h>

typedef struct order
{
    int order_id;
    int delivery_time;
    struct order *next;
} order;

order *create_node(int order_id, int delivery_time)
{
    order *new_node = (order *)malloc(sizeof(order));
    if (new_node == NULL)
    {
        printf("Memory allocation failed....SOS");
        return NULL;
    }
    new_node->order_id = order_id;
    new_node->delivery_time = delivery_time;
    new_node->next = NULL;
    return new_node;
}

void free_linked_list(order **head)
{
    order *temporary_node = NULL;
    while (*head != NULL)
    {
        temporary_node = *head;
        *head = (*head)->next;
        free(temporary_node);
    }
    *head = NULL;
}

void add_order(order **head, int order_id, int delivery_time)
{
    order *new_node = create_node(order_id, delivery_time);
    if (new_node == NULL)
    {
        free_linked_list(head);
        return;
    }
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    order *temporary_node = *head;
    while (temporary_node->next != NULL)
    {
        temporary_node = temporary_node->next;
    }
    temporary_node->next = new_node;
}

void display_orders(order *head)
{
    while (head != NULL)
    {
        printf("orderID: %d, DeliveryTime: %d -> ", head->order_id, head->delivery_time);
        head = head->next;
    }
    printf("NULL\n");
}

void bubble_sort_orders(order *head)
{
    if (head == NULL || head->next == NULL)
        return;

    int is_swapped = 0;
    order *current, *prev = NULL;

    do
    {
        current = head;
        is_swapped = 0;
        while (current->next != prev)
        {
            if (current->delivery_time > current->next->delivery_time || (current->delivery_time == current->next->delivery_time && current->order_id > current->next->order_id))
            {
                is_swapped = 1;
                int temporaray_variable_to_store_time = current->delivery_time;
                int temporaray_variable_to_store_order_id = current->order_id;

                current->delivery_time = current->next->delivery_time;
                current->order_id = current->next->order_id;

                current->next->delivery_time = temporaray_variable_to_store_time;
                current->next->order_id = temporaray_variable_to_store_order_id;
            }
            current = current->next;
        }
        prev = current;
    } while (is_swapped);
}

int main()
{
    order *head = NULL;
    int number_of_inputs, order_id, delivery_time;

    printf("Enter the number of orders: ");
    scanf("%d", &number_of_inputs);
    if (number_of_inputs <= 0)
    {
        printf("Enter a valid number of orders. ");
        return 0;
    }
    for (int iterator = 0; iterator < number_of_inputs; iterator++)
    {
        printf("Enter orderID for order %d: ", iterator + 1);
        scanf("%d", &order_id);
        printf("Enter Delivery Time for order %d (in hours): ", iterator + 1);
        scanf("%d", &delivery_time);
        if (delivery_time < 0)
        {
            printf("Invalid delivery time!");
            return 0;
        }
        add_order(&head, order_id, delivery_time);
    }

    printf("\noriginal orders List:\n");
    display_orders(head);

    bubble_sort_orders(head);

    printf("\nSorted orders List by Delivery Time:\n");
    display_orders(head);
    free_linked_list(&head);
    return 0;
}
