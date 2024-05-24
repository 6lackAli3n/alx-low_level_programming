#include <stdlib.h>
#include "../search_algos.h"

/**
 * create_list - Creates a singly linked list from an array of integers
 * @array: Pointer to the array of integers
 * @size: Size of the array
 *
 * Return: Pointer to the head of the created list
 */
listint_t *create_list(int *array, size_t size)
{
	listint_t *head = NULL, *node, *temp;
	size_t i;

	for (i = 0; i < size; i++)
	{
		node = malloc(sizeof(listint_t));
		if (!node)
			return (NULL);
		node->n = array[i];
		node->index = i;
		node->next = NULL;
		if (head == NULL)
			head = node;
		else
		{
			temp = head;
			while (temp->next)
				temp = temp->next;
			temp->next = node;
		}
	}
	return (head);
}
