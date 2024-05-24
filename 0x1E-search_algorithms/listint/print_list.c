#include <stdio.h>
#include "../search_algos.h"

/**
 * print_list - Prints a singly linked list
 * @list: Pointer to the head of the list
 */
void print_list(const listint_t *list)
{
	while (list)
	{
		printf("Index[%lu] = [%d]\n", list->index, list->n);
		list = list->next;
	}
}
