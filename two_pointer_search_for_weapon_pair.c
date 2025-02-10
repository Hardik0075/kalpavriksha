#include <stdio.h>
#include <stdlib.h>

typedef struct weapon
{
    int power_value;
    struct weapon *next;
} weapon;

weapon *create_weapon_node(int power_value)
{
    weapon *new_node = (weapon *)malloc(sizeof(weapon));
    if (new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    new_node->power_value = power_value;
    new_node->next = NULL;
    return new_node;
}

weapon *previous_node(weapon *head, weapon *node)
{
    if (head == node)
        return NULL;
    weapon *temporary_node = head;
    while (temporary_node != NULL && temporary_node->next != node)
    {
        temporary_node = temporary_node->next;
    }
    return temporary_node;
}

void add_weapon_to_list(weapon **head, int power_value)
{
    weapon *new_node = create_weapon_node(power_value);
    if (new_node == NULL)
        return;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        weapon *temporary_node = *head;
        while (temporary_node->next != NULL)
        {
            temporary_node = temporary_node->next;
        }
        temporary_node->next = new_node;
    }
}

int is_before(weapon *head, weapon *node1, weapon *node2)
{
    if (node1 == node2)
        return 0;
    weapon *temporary_node = head;
    while (temporary_node != NULL)
    {
        if (temporary_node == node1)
            return 1;
        if (temporary_node == node2)
            return 0;
        temporary_node = temporary_node->next;
    }
    return 0;
}

void find_weapon_pair_with_target_power(weapon *head, int target_power)
{
    if (head == NULL)
        return;
    weapon *left_weapon = head;
    weapon *right_weapon = head;
    while (right_weapon->next != NULL)
    {
        right_weapon = right_weapon->next;
    }

    int found = 0;
    while (is_before(head, left_weapon, right_weapon))
    {
        int sum = left_weapon->power_value + right_weapon->power_value;

        if (sum == target_power)
        {
            printf("Weapon pair found! Powers: %d and %d\n", left_weapon->power_value, right_weapon->power_value);
            found = 1;
            left_weapon = left_weapon->next;
            right_weapon = previous_node(head, right_weapon);
        }
        else if (sum < target_power)
        {
            left_weapon = left_weapon->next;
        }
        else
        {
            right_weapon = previous_node(head, right_weapon);
        }
    }

    if (!found)
        printf("No valid weapon pair found.\n");
}

void free_weapon_list(weapon *head)
{
    weapon *temporary_node;
    while (head != NULL)
    {
        temporary_node = head;
        head = head->next;
        free(temporary_node);
    }
    head = NULL;
}

int main()
{
    weapon *weapon_list = NULL;
    int number_of_weapons, target_power;

    printf("Enter the number of weapons: ");
    scanf("%d", &number_of_weapons);

    if (number_of_weapons < 2)
    {
        printf("Not enough weapons to form a pair.\n");
        return 0;
    }

    printf("Enter the sorted weapon powers: \n");
    for (int index = 0; index < number_of_weapons; index++)
    {
        printf("Enter power of weapon %d : ", index + 1);
        int weapon_power_value;
        scanf("%d", &weapon_power_value);
        add_weapon_to_list(&weapon_list, weapon_power_value);
    }

    printf("Enter the target power: ");
    scanf("%d", &target_power);

    find_weapon_pair_with_target_power(weapon_list, target_power);

    free_weapon_list(weapon_list);

    return 0;
}
