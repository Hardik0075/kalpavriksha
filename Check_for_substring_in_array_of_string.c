#include <stdio.h>
#include <string.h>
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
	int rows, columns;
	scanf("%d", &rows);
	scanf("%d", &columns);
	printf("Enter String: \n");
	char *array[rows][columns];
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			array[row][column] = (char *)malloc(sizeof(char) * 50);
		}
	}
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			scanf("%s", array[row][column]);
		}
	}
	char *substring;
	substring = (char *)malloc(sizeof(char) * 50);
	printf("Enter Substring : \n");
	scanf("%s", substring);
	int result_count = 0;
	printf("result : \n");
	for (int outer_loop = 0; outer_loop < rows; outer_loop++)
	{
		for (int inner_loop = 0; inner_loop < columns; inner_loop++)
		{
			for (int mainStringIndex = 0; mainStringIndex < length(array[outer_loop][inner_loop]); mainStringIndex++)
			{
				if (array[outer_loop][inner_loop][mainStringIndex] == substring[0])
				{
					int substring_incrementor = 0, main_string_incrementor = 0;
					int match_count = 0;
					while (substring_incrementor < length(substring) && mainStringIndex < length(array[outer_loop][inner_loop]) && match_count <= length(substring))
					{
						if (substring[substring_incrementor] == array[outer_loop][inner_loop][mainStringIndex + main_string_incrementor])
						{
							match_count++;
						}
						substring_incrementor++;
						main_string_incrementor++;
					}
					if (match_count == length(substring))
					{
						result_count++;
						printf("%s\n", *(*(array + outer_loop) + inner_loop));
						break;
					}
				}
			}
		}
	}
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			free(array[row][column]);
		}
	}
	free(substring);
	printf("%d", result_count);
	return 0;
}