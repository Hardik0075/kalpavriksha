#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dimension; 
    scanf("%d", &dimension);
    int *array[dimension];
    for (int index = 0; index < dimension; index++)
    {
        array[index] = (int *)malloc(dimension * sizeof(int));
    }
    int *rotated[dimension];
    for (int index = 0; index < dimension; index++)
    {
        rotated[index] = (int *)malloc(dimension * sizeof(int));
    }
    for (int index1 = 0; index1 < dimension; index1++)
    {
        for (int index2 = 0; index2 < dimension; index2++)
        {
            scanf("%d", (*(array + index1) + index2));
        }
    }

    printf("before: \n");
    for (int index1 = 0; index1 < dimension; index1++)
    {
        for (int index2 = 0; index2 < dimension; index2++)
        {
            printf("%d ", *(*(array + index1) + index2));
        }
        printf("\n");
    }

    int array_row_start = 0, array_row_end = dimension - 1, array_column_start = 0, array_column_end = dimension - 1;
    int rotated_row_start = 0, rotated_row_end = dimension - 1, rotated_column_start = 0, rotated_column_end = dimension - 1;
    while (array_row_start <= array_row_end && array_column_start <= array_column_end)
    {
        for (int index = array_column_start; index <= array_column_end; index++)
        {
            *(*(rotated + index) + rotated_column_end) = *(*(array + array_row_start) + index);
        }
        array_row_start++;
        rotated_column_end--;
        for (int index = array_row_start; index <= array_row_end; index++)
        {
            *(*(rotated + rotated_row_end) + (dimension - 1 - index)) = *(*(array + index) + array_column_end);
        }
        array_column_end--;
        rotated_row_end--;
        for (int index = array_column_end; index >= array_column_start; index--)
        {
            *(*(rotated + index) + rotated_column_start) = *(*(array + array_row_end) + index);
        }
        array_row_end--;
        rotated_column_start++;
        for (int index = array_row_end; index >= array_row_start; index--)
        {
            *(*(rotated + rotated_row_start) + index) = *(*(array + (dimension - 1 - index)) + array_column_start);
        }
        array_column_start++;
        rotated_row_start++;
    }
    printf("after: \n");
    for (int index1 = 0; index1 < dimension; index1++)
    {
        for (int index2 = 0; index2 < dimension; index2++)
        {
            printf("%d ", *(*(rotated + index1) + index2));
        }
        printf("\n");
    }
    for (int i = 0; i < dimension; i++)
    {
        free(array[i]);
        free(rotated[i]);
    }
}
