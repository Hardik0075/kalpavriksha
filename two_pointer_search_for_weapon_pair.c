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
        weapon *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void find_weapon_pair_with_target_power(weapon *head, int target_power)
{
    weapon *left_weapon = head;
    weapon *right_weapon = head;
    while (right_weapon->next != NULL)
    {
        right_weapon = right_weapon->next;
    }
    while (left_weapon != right_weapon)
    {
        int sum = left_weapon->power_value + right_weapon->power_value;

        if (sum == target_power)
        {
            printf("Weapon pair found! Indices: %d and %d\n", left_weapon->power_value, right_weapon->power_value);
            return;
        }
        else if (sum < target_power)
        {
            left_weapon = left_weapon->next;
        }
        else
        {
            weapon *temporary_node = head;
            while (temporary_node->next != right_weapon)
            {
                temporary_node = temporary_node->next;
            }
            right_weapon = temporary_node;
        }
    }
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
