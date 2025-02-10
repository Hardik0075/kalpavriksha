#include <stdio.h>
#include <stdlib.h>

typedef struct player
{
    int player_id;
    char name[50];
    int score;
    struct player *next;
    struct player *previous;
} player;

char to_lower_conversion(char character)
{
    if (character >= 'A' && character <= 'Z')
    {
        return character + ('a' - 'A');
    }
    return character;
}

char *copy_string(char *destination, char *source)
{
    char *destination_pointer = destination;
    while (*source != '\0')
    {
        *destination_pointer = *source;
        destination_pointer++;
        source++;
    }
    *destination_pointer = '\0';
    return destination;
}

int compare_string(char *string1, char *string2)
{
    int index = 0;
    while (string1[index] != '\0' && string2[index] != '\0')
    {
        char character1 = to_lower_conversion(string1[index]);
        char character2 = to_lower_conversion(string2[index]);
        if (character1 != character2)
        {
            return character1 - character2;
        }
        index++;
    }
    return to_lower_conversion(string1[index]) - to_lower_conversion(string2[index]);
}

player *create_player(int id, char name[], int score)
{
    player *new_player = (player *)malloc(sizeof(player));
    if (new_player == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    new_player->player_id = id;
    copy_string(new_player->name, name);
    new_player->score = score;
    new_player->next = NULL;
    new_player->previous = NULL;
    return new_player;
}

void free_players(player *head)
{
    player *temporary_node;
    while (head != NULL)
    {
        temporary_node = head;
        head = head->next;
        free(temporary_node);
    }
    head = NULL;
}

void append_player(player **head, int id, char name[], int score)
{
    player *new_player = create_player(id, name, score);
    if (new_player == NULL)
    {
        free(*head);
        return;
    }
    if (*head == NULL)
    {
        *head = new_player;
        return;
    }
    player *temporary_node = *head;
    while (temporary_node->next != NULL)
    {
        temporary_node = temporary_node->next;
    }
    temporary_node->next = new_player;
    new_player->previous = temporary_node;
}

void swap_players(player *first_player, player *second_player)
{
    int temporary_variable_for_id = first_player->player_id;
    char temporary_variable_for_name[50];
    int temporary_variable_for_score = first_player->score;

    copy_string(temporary_variable_for_name, first_player->name);

    first_player->player_id = second_player->player_id;
    copy_string(first_player->name, second_player->name);
    first_player->score = second_player->score;

    second_player->player_id = temporary_variable_for_id;
    copy_string(second_player->name, temporary_variable_for_name);
    second_player->score = temporary_variable_for_score;
}

player *partition(player *low, player *high)
{
    int pivot_score = high->score;
    char pivot_name[50];
    copy_string(pivot_name, high->name);

    player *pivot_left = low->previous;
    player *pivot_right = low;

    while (pivot_right != high)
    {
        // Using custom compare_string for case-insensitive name comparison.
        if (pivot_right->score > pivot_score ||
            (pivot_right->score == pivot_score && compare_string(pivot_right->name, pivot_name) < 0))
        {
            pivot_left = (pivot_left == NULL) ? low : pivot_left->next;
            swap_players(pivot_left, pivot_right);
        }
        pivot_right = pivot_right->next;
    }
    if (pivot_left == NULL)
    {
        pivot_left = low;
    }
    else
    {
        pivot_left = pivot_left->next;
    }
    swap_players(pivot_left, high);
    return pivot_left;
}

void quick_sort(player *low, player *high)
{
    if (low != NULL && high != NULL && low != high && low != high->next)
    {
        player *pivot = partition(low, high);
        quick_sort(low, pivot->previous);
        quick_sort(pivot->next, high);
    }
}

player *get_tail(player *head)
{
    while (head != NULL && head->next != NULL)
    {
        head = head->next;
    }
    return head;
}

void display_leaderboard(player *head)
{
    printf("Sorted Leaderboard:\n");
    while (head != NULL)
    {
        printf("Player ID: %d, Name: %s, Score: %d\n", head->player_id, head->name, head->score);
        head = head->next;
    }
}

int main()
{
    int number_of_players;
    printf("Enter number of players: ");
    scanf("%d", &number_of_players);

    if (number_of_players <= 0)
    {
        printf("No players to sort.\n");
        return 0;
    }

    player *head = NULL;
    for (int index = 0; index < number_of_players; index++)
    {
        int player_id, player_score;
        char player_name[50];
        printf("Enter details of player %d:\n", index + 1);
        printf("Player ID: ");
        scanf("%d", &player_id);
        while (player_id < 0)
        {
            printf("Please enter a valid player id: ");
            scanf("%d", &player_id);
        }
        printf("Name: ");
        scanf("%s", player_name);
        printf("Score: ");
        scanf("%d", &player_score);
        append_player(&head, player_id, player_name, player_score);
    }

    player *tail = get_tail(head);
    quick_sort(head, tail);
    display_leaderboard(head);
    free_players(head);
    return 0;
}
