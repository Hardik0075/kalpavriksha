#include <stdio.h>
#include <stdlib.h>

int length_of_array(char array[])
{
    int count = 0;
    while (array[count] != '\0')
    {
        count++;
    }
    return count;
}

void free_memory_allocated_to_array(char **array, int size)
{
    for (int iterator = 0; iterator < size; iterator++)
    {
        free(array[iterator]);
        array[iterator] = NULL;
    }
    free(array);
    array = NULL;
}

int find_maximum_occurrences(char **array, int input, char character_to_match)
{
    int maximum_count = 0;
    int maximum_occurence_string_index = -1;
    int count = 0;
    for (int index = 0; index < input; index++)
    {
        count = 0;
        for (int string_iterator = 0; string_iterator < length_of_array(array[index]); string_iterator++)
        {
            if (array[index][string_iterator] == character_to_match)
            {
                count++;
            }
        }
        if (count > maximum_count)
        {
            maximum_count = count;
            maximum_occurence_string_index = index;
        }
    }
    return maximum_occurence_string_index;
}

int main()
{
    int number_of_input;
    printf("Enter number of strings: ");
    if (scanf("%d", &number_of_input) != 1 || number_of_input <= 0)
    {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    char **array = (char **)malloc(sizeof(char *) * number_of_input);
    if (array == NULL)
    {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }

    printf("Enter strings:\n");
    for (int iterator = 0; iterator < number_of_input; iterator++)
    {
        array[iterator] = (char *)malloc(sizeof(char) * 50);
        if (array[iterator] == NULL)
        {
            printf("Memory allocation for string failed. Exiting.\n");
            free_memory_allocated_to_array(array, iterator);
            return 1;
        }
        scanf("%s", array[iterator]);
    }

    printf("Enter character to find occurrences: ");
    char character_to_match;
    scanf(" %c", &character_to_match);

    int max_index = find_maximum_occurrences(array, number_of_input, character_to_match);
    if (max_index != -1)
    {
        printf("String with most occurrences of '%c': %s\n", character_to_match, array[max_index]);
    }
    else
    {
        printf("No Match Found\n");
    }

    free_memory_allocated_to_array(array, number_of_input);

    return 0;
}
