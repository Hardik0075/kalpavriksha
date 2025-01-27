#include <stdio.h>
#include <stdlib.h>

typedef struct item_details
{
    int item_id;
    char item_name[50];
    struct item_details *next;
} item;

void copy_string(char destination[], char source[])
{
    int index = 0;
    while (source[index] != '\0')
    {
        destination[index] = source[index];
        index++;
    }
    destination[index] = '\0';
}
int compare_string(char *string1, char *string2)
{
    int index = 0;
    while (string1[index] != '\0' && string2[index] != '\0')
    {
        if (string1[index] != string2[index])
        {
            return (string1[index] - string2[index]);
        }
        index++;
    }
    return (string1[index] - string2[index]);
}

void free_list(item *inventory)
{
    item *temporary_node;
    while (inventory != NULL)
    {
        temporary_node = inventory;
        inventory = inventory->next;
        free(temporary_node);
    }
}

item *create_node(int item_id, char item_name[])
{
    item *new_node = (item *)malloc(sizeof(item));
    if (new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    new_node->item_id = item_id;
    copy_string(new_node->item_name, item_name);
    new_node->next = NULL;
    return new_node;
}

void add_to_list(item **head, int item_id, char item_name[])
{
    item *new_node = create_node(item_id, item_name);
    if (new_node == NULL)
    {
        free_list(*head);
        return;
    }
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        item *temporary_node = *head;
        while (temporary_node->next != NULL)
        {
            temporary_node = temporary_node->next;
        }
        temporary_node->next = new_node;
    }
}

int linear_search(item *head, char target_item_name[])
{
    item *current = head;
    while (current != NULL)
    {
        if (compare_string(current->item_name, target_item_name) == 0)
        {
            return current->item_id;
        }
        current = current->next;
    }
    return -1;
}

int main()
{
    item *inventory = NULL;
    int number_of_items;

    printf("Enter the number of items in the inventory: ");
    scanf("%d", &number_of_items);

    for (int index = 0; index < number_of_items; index++)
    {
        int item_id;
        char item_name[50];

        printf("Enter Item ID and Item Name (comma separated): ");
        scanf("%d", &item_id);
        getchar();
        scanf("%[^\n]%*c", item_name);
        add_to_list(&inventory, item_id, item_name);
    }

    char target_item_name[50];
    printf("Enter the target item name: ");
    scanf("%[^\n]%*c", target_item_name);

    int searched_item_id = linear_search(inventory, target_item_name);

    if (searched_item_id != -1)
    {
        printf("Item found! Item ID: %d\n", searched_item_id);
    }
    else
    {
        printf("Item not found\n");
    }

    free_list(inventory);

    return 0;
}
