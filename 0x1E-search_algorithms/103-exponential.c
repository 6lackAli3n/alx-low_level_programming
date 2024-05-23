#include "search_algos.h"
#include <stdio.h>

/**
 * binary_search_range - Searches for a value in a sorted array of integers
 * using the Binary search algorithm within a specified range.
 * @array: Pointer to the first element of the array to search in
 * @left: The left index of the subarray to search in
 * @right: The right index of the subarray to search in
 * @value: The value to search for
 *
 * Return: The index where value is located, or -1 if the value is not present
 */
int binary_search_range(int *array, size_t left, size_t right, int value)
{
	size_t mid, i;

	while (left <= right)
	{
		printf("Searching in array: ");
		for (i = left; i <= right; i++)
		{
			printf("%d", array[i]);
			if (i < right)
				printf(", ");
		}
		printf("\n");

		mid = left + (right - left) / 2;

		if (array[mid] == value)
			return (mid);
		if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array of integers using
 * the Exponential search algorithm.
 * @array: Pointer to the first element of the array to search in
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The first index where value is located, or -1 if the value is not
 * present or array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;
	size_t right;

	if (array == NULL)
		return (-1);

	if (array[0] == value)
		return (0);

	while (bound < size && array[bound] <= value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	right = bound < size ? bound : size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", bound / 2, right);

	return (binary_search_range(array, bound / 2, right, value));
}
