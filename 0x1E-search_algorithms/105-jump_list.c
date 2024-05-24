#include <math.h>
#include <stdio.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted singly linked list
 * @list: Pointer to the head of the list
 * @size: The number of nodes in the list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located,
 * or NULL if value is not present
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, i;
	listint_t *prev, *current;

	if (list == NULL || size == 0)
		return (NULL);

	step = (size_t)sqrt(size);
	prev = current = list;

	while (current->next && current->index <
			size && current->n < value)
	{
		prev = current;
		for (i = 0; i < step; i++)
		{
			if (current->next)
				current = current->next;
			else
				break;
		}
		printf("Value checked at index [%lu] = [%d]\n",
				current->index, current->n);
		if (current->n >= value)
			break;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, current->index);

	while (prev && prev->index <= current->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
