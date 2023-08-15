#include "sort.h"

/**
 * insertion_sort_list - Sorts dll of ints in order l-h.
 * @list: Double pointer to the head of the linked list.
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *current_node, *previous_node;
	int tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		current_node = current;
		while (current_node->prev != NULL)
		{
			tmp = 0;
			if (current_node->n < current_node->prev->n)
			{
				if (current_node->prev->prev != NULL)
					current_node->prev->prev->next = current_node;
				current_node->prev->next = current_node->next;
				previous_node = current_node->prev->prev;
				current_node->prev->prev = current_node;

				if (current_node->next != NULL)
					current_node->next->prev = current_node->prev;
				current_node->next = current_node->prev;
				current_node->prev = previous_node;
				tmp = 1;

				if (current_node->prev == NULL)
					*list = current_node;
				print_list(*list);
			}
			if (tmp == 0)
				current_node = current_node->prev;
		}
		current = current->next;
	}
}
