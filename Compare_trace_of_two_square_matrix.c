#include <stdio.h>
#include <stdlib.h>

int memory_allocation_to_matrix(int dimension, int *matrix[dimension])
{
	for (int row = 0; row < dimension; row++)
	{
		matrix[row] = (int *)malloc(dimension * sizeof(int));
		if (matrix[row] == NULL)
		{
			printf("Memory Allocation Failed!\n");
			for (int previous_row = 0; previous_row < row; previous_row++)
			{
				free(matrix[previous_row]);
				matrix[previous_row] = NULL;
			}
			return 0;
		}
	}
	return 1;
}

void free_matrix(int dimension, int *matrix[dimension])
{
	for (int row = 0; row < dimension; row++)
	{
		free(matrix[row]);
		matrix[row] = NULL;
	}
}

void read_matrix(int dimension, int *matrix[dimension])
{
	for (int row = 0; row < dimension; row++)
	{
		for (int column = 0; column < dimension; column++)
		{
			scanf("%d", &matrix[row][column]);
		}
	}
}

int calculate_trace(int dimension, int *matrix[dimension])
{
	int trace = 0;
	for (int diagonal = 0; diagonal < dimension; diagonal++)
	{
		trace += matrix[diagonal][diagonal];
	}
	return trace;
}

void compare_traces(int trace1, int trace2)
{
	if (trace1 == trace2)
	{
		printf("Both Trace are equal\n");
	}
	else
	{
		printf("Trace is not equal\n");
	}
}

int main()
{
	int dimension;
	printf("Enter dimension of your square matrix (non-zero positive integer): ");
	scanf("%d", &dimension);
	if (dimension <= 0)
	{
		printf("Invalid dimension\n");
		return 1;
	}

	int *matrix1[dimension];
	int *matrix2[dimension];

	if (!memory_allocation_to_matrix(dimension, matrix1))
	{
		printf("Failed to allocate memory for the first matrix. Exiting.\n");
		return 1;
	}

	if (!memory_allocation_to_matrix(dimension, matrix2))
	{
		printf("Failed to allocate memory for the second matrix. Cleaning up first matrix.\n");
		free_matrix(dimension, matrix1);
		return 1;
	}

	printf("Enter elements of the first matrix:\n");
	read_matrix(dimension, matrix1);

	printf("Enter elements of the second matrix:\n");
	read_matrix(dimension, matrix2);

	int trace1 = calculate_trace(dimension, matrix1);
	int trace2 = calculate_trace(dimension, matrix2);

	compare_traces(trace1, trace2);

	free_matrix(dimension, matrix1);
	free_matrix(dimension, matrix2);

	return 0;
}
