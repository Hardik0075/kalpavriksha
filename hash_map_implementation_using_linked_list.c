#include <stdio.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE 10

typedef struct hash_node
{
    int key;
    int value;
    struct hash_node *next;
} hash_node;

int hash_function(int key)
{
    return key % HASH_TABLE_SIZE;
}

hash_node *insert_into_hashmap(hash_node *map, int key, int value)
{
    int index = hash_function(key);

    if (map[index].key == -1)
    {
        map[index].key = key;
        map[index].value = value;
        map[index].next = NULL;
        printf("Inserted successfully\n");
        return map;
    }

    if (map[index].key == key)
    {
        map[index].value = value;
        return map;
    }

    hash_node *temporary_node_for_updation = map[index].next;
    while (temporary_node_for_updation != NULL)
    {
        if (temporary_node_for_updation->key == key)
        {
            temporary_node_for_updation->value = value;
            printf("Value updated successfully!\n");
            return map;
        }
        temporary_node_for_updation = temporary_node_for_updation->next;
    }

    hash_node *new_node = (hash_node *)malloc(sizeof(hash_node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return map;
    }
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;

    hash_node *temporary_node_for_iteration = &map[index];
    while (temporary_node_for_iteration->next != NULL)
    {
        temporary_node_for_iteration = temporary_node_for_iteration->next;
    }
    temporary_node_for_iteration->next = new_node;
    printf("Inserted successfully\n");
    return map;
}

void search_key_in_hash_map(hash_node *map, int key)
{
    int index = hash_function(key);
    hash_node *temporary_node = &map[index];

    while (temporary_node != NULL)
    {
        if (temporary_node->key == key)
        {
            printf("Key found: Value = %d\n", temporary_node->value);
            return;
        }
        temporary_node = temporary_node->next;
    }
    printf("Key not found\n");
}

hash_node *delete_key_from_hash_map(hash_node *map, int key)
{
    int index = hash_function(key);
    hash_node *temporary_node = &map[index];
    hash_node *previous_node = NULL;

    while (temporary_node != NULL)
    {
        if (temporary_node->key == key)
        {
            if (previous_node == NULL)
            {
                if (temporary_node->next != NULL)
                {
                    temporary_node->key = temporary_node->next->key;
                    temporary_node->value = temporary_node->next->value;
                    hash_node *to_delete = temporary_node->next;
                    temporary_node->next = temporary_node->next->next;
                    free(to_delete);
                }
                else
                {
                    temporary_node->key = -1;
                    temporary_node->value = -1;
                    temporary_node->next = NULL;
                }
            }
            else
            {
                previous_node->next = temporary_node->next;
                free(temporary_node);
            }
            printf("Key %d deleted successfully\n", key);
            return map;
        }
        previous_node = temporary_node;
        temporary_node = temporary_node->next;
    }
    printf("Key not found\n");
    return map;
}

void display_map(hash_node *map)
{
    printf("Hash Table:\n");
    for (int index = 0; index < HASH_TABLE_SIZE; index++)
    {
        printf("Index %d: ", index + 1);
        hash_node *temporary_node = &map[index];

        if (temporary_node->key == -1)
        {
            printf("Empty\n");
            continue;
        }

        while (temporary_node != NULL)
        {
            printf("(%d, %d) -> ", temporary_node->key, temporary_node->value);
            temporary_node = temporary_node->next;
        }
        printf("NULL\n");
    }
}

void free_map(hash_node *map)
{
    for (int index = 0; index < HASH_TABLE_SIZE; index++)
    {
        hash_node *temporary_node = map[index].next;
        while (temporary_node)
        {
            hash_node *to_delete = temporary_node;
            temporary_node = temporary_node->next;
            free(to_delete);
        }
    }
    free(map);
}

int main()
{
    hash_node *map = (hash_node *)calloc(HASH_TABLE_SIZE, sizeof(hash_node));

    if (map == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int index = 0; index < HASH_TABLE_SIZE; index++)
    {
        map[index].key = -1;
    }

    while (1)
    {
        int user_choice;
        printf("\nChoose an operation:\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n> ");
        scanf("%d", &user_choice);

        if (user_choice == 1)
        {
            int key, value;
            printf("Enter a non-negative integer as key: ");
            scanf("%d", &key);
            while (key < 0)
            {
                printf("Enter a non-negative integer: ");
                scanf("%d", &key);
            }

            printf("Enter a non-negative integer as value: ");
            scanf("%d", &value);
            while (value < 0)
            {
                printf("Enter a non-negative integer: ");
                scanf("%d", &value);
            }

            map = insert_into_hashmap(map, key, value);
        }
        else if (user_choice == 2)
        {
            int key;
            printf("Enter key to search: ");
            scanf("%d", &key);
            search_key_in_hash_map(map, key);
        }
        else if (user_choice == 3)
        {
            int key;
            printf("Enter key to delete: ");
            scanf("%d", &key);
            map = delete_key_from_hash_map(map, key);
        }
        else if (user_choice == 4)
        {
            display_map(map);
        }
        else if (user_choice == 5)
        {
            printf("Exiting, Have a nice day\n");
            free_map(map);
            break;
        }
        else
        {
            printf("Invalid choice, please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}
