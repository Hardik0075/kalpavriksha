#include <stdio.h>
#include <stdlib.h>

int length_of_string(char *array)
{
	int count = 0;
	while (array[count] != '\0')
	{
		count++;
	}
	return count;
}

int check_substring_in_string(char *main_string, char *substring)
{
	int main_string_length = length_of_string(main_string);
	int substring_length = length_of_string(substring);

	for (int main_index = 0; main_index <= main_string_length - substring_length; main_index++)
	{
		int substring_index = 0;
		while (substring_index < substring_length && main_string[main_index + substring_index] == substring[substring_index])
		{
			substring_index++;
		}
		if (substring_index == substring_length)
		{
			return 1;
		}
	}
	return 0;
}

void free_memory(int rows, int columns, char *array[rows][columns])
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			free(array[row][column]);
			array[row][column] = NULL;
		}
	}
}

void get_strings(int rows, int columns, char *array[rows][columns])
{
	printf("Enter strings:\n");
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			scanf("%s", array[row][column]);
		}
	}
}

void search_substring_in_array_of_string(int rows, int columns, char *array[rows][columns], char *substring)
{
	int found = 0;
	printf("Strings containing the substring '%s':\n", substring);
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			if (check_substring_in_string(array[row][column], substring))
			{
				printf("Found in: %s\n", array[row][column]);
				found = 1;
			}
		}
	}
	if (!found)
	{
		printf("No match found.\n");
	}
}

int allocate_memory_for_string(int rows, int columns, char *array[rows][columns])
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			array[row][column] = (char *)malloc(100 * sizeof(char));
			if (array[row][column] == NULL)
			{
				printf("Memory allocation failed for strings[%d][%d]. Exiting...\n", row, column);
				return 0;
			}
		}
	}
	return 1;
}

int main()
{
	int rows, columns;

	printf("Enter number of rows: ");
	if (scanf("%d", &rows) != 1 || rows <= 0)
	{
		printf("Invalid input for rows. Exiting.\n");
		return 1;
	}

	printf("Enter number of columns: ");
	if (scanf("%d", &columns) != 1 || columns <= 0)
	{
		printf("Invalid input for columns. Exiting.\n");
		return 1;
	}

	char *array[rows][columns];
	if (!allocate_memory_for_string(rows, columns, array))
	{
		return 0;
	}

	get_strings(rows, columns, array);

	char substring[50];
	printf("Enter substring: ");
	if (scanf("%s", substring) != 1)
	{
		printf("Invalid input for substring. Exiting.\n");
		free_memory(rows, columns, array);
		return 1;
	}

	search_substring_in_array_of_string(rows, columns, array, substring);

	free_memory(rows, columns, array);

	return 0;
}
