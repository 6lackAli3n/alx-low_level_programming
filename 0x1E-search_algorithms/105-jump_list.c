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
	size_t step, prev;
	listint_t *current, *prev_node;

	if (list == NULL || size == 0)
		return (NULL);

	step = (size_t) sqrt(size);
	current = list;
	prev = 0;

	while (current->next && current->index +
			step < size && current->n < value)
	{
		prev_node = current;
		prev = current->index;
		while (current->next && current->index < prev + step)
			current = current->next;

		printf("Value checked at index [%lu] = [%d]\n",
				current->index, current->n);

		if (current->n >= value)
			break;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
			prev, current->index);

	current = prev_node;
	while (current && current->index <= prev + step)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				current->index, current->n);
		if (current->n == value)
			return (current);
		current = current->next;
	}

	return (NULL);
}
