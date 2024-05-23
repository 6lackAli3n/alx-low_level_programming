#include "search_algos.h"
#include <math.h>
#include <stdio.h>

/**
 * jump_search - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 * Return: The first index where value is located,
 * or -1 if the value is not present or array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump;
	size_t left = 0;
	size_t right = 0;

	if (array == NULL || size == 0)
		return (-1);

	jump = (size_t)sqrt(size);

	while (right < size && array[right] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", right, array[right]);
		left = right;
		right += jump;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", left, right);

	right = (right < size) ? right : size - 1;
	for (; left <= right; left++)
	{
		printf("Value checked array[%lu] = [%d]\n", left, array[left]);
		if (array[left] == value)
			return (left);
	}

	return (-1);
}
