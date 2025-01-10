#include <stdio.h>
#include <stdlib.h>

int length(char array[])
{
    int count = 0;
    while (array[count] != '\0')
    {
        count++;
    }
    return count;
}

int main()
{
    int input;
    scanf("%d", &input);
    char *array[input];
    for (int iterator = 0; iterator < input; iterator++)
    {
        array[iterator] = (char *)malloc(sizeof(char) * 50);
    }
    printf("Enter strings : \n");
    for (int index = 0; index < input; index++)
    {
        scanf("%s", array[index]);
    }

    printf("Enter Character: \n");
    char character;
    scanf(" %c", &character);
    int max_count = 0, flag = 0;
    char *max_string;
    max_string = (char *)malloc(sizeof(char) * 50);
    for (int index = 0; index < input; index++)
    {
        int count = 0;
        for (int inner_index = 0; inner_index < length(array[index]); inner_index++)
        {
            if (*(*(array + index) + inner_index) == character)
            {
                count++;
                flag = 1;
            }
        }
        if (count > max_count)
        {
            max_count = count;
            max_string = array[index];
        }
    }
    if (flag == 1)
        printf("%s\n", max_string);
    else
        printf("No Match Found \n");

    for (int iterator = 0; iterator < input; iterator++)
    {
        free(array[iterator]);
    }
    return 0;
}