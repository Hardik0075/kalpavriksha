#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int bananas;
    struct node *next;
} node;

node *create_node(int bananas)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    new_node->bananas = bananas;
    new_node->next = NULL;
    return new_node;
}

void free_list(node *head)
{
    node *temporary_node;
    while (head != NULL)
    {
        temporary_node = head;
        head = head->next;
        free(temporary_node);
    }
}

void append_node(node **head, int bananas)
{
    node *new_node = create_node(bananas);
    if (new_node == NULL)
    {
        free(*head);
        return;
    }
    if (new_node == NULL)
    {
        return;
    }
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

int hours_to_finish(node *head, int bananas_per_hour)
{
    int hours = 0;
    node *current = head;
    while (current != NULL)
    {
        hours += current->bananas / bananas_per_hour;
        if (current->bananas % bananas_per_hour != 0)
        {
            hours += 1;
        }
        current = current->next;
    }
    return hours;
}

int find_minimum_bananas_per_hour(node *head, int number_of_hours_to_finish)
{
    int left = 1, right = 0;
    node *current = head;

    while (current != NULL)
    {
        if (current->bananas > right)
        {
            right = current->bananas;
        }
        current = current->next;
    }

    int minimum_number_of_hours = right;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        int hours = hours_to_finish(head, middle);

        if (hours <= number_of_hours_to_finish)
        {
            minimum_number_of_hours = middle;
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }

    return minimum_number_of_hours;
}

int main()
{
    node *head = NULL;
    int number_of_inputs;
    printf("Enter number of inputs : ");
    scanf("%d", &number_of_inputs);
    for (int index = 0; index < number_of_inputs; index++)
    {
        int number_of_bananas_in_pile;
        printf("Enter number of bananas in pile %d : ", index + 1);
        scanf("%d", &number_of_bananas_in_pile);
        append_node(&head, number_of_bananas_in_pile);
    }
    int number_of_hours_have_to_finish;
    printf("Enter number of hours to finish : ");
    scanf("%d", &number_of_hours_have_to_finish);
    int min_bananas_per_hour = find_minimum_bananas_per_hour(head, number_of_hours_have_to_finish);
    printf("Minimum bananas per hour Koko must eat: %d\n", min_bananas_per_hour);

    free_list(head);
    return 0;
}
