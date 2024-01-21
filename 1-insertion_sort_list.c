#include "sort.h"

/**
 * swap_nodes - swap the nodes at a point
 * @node1: the first node
 * @node2: the second node
 */

void swap_nodes(listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}


/**
 * insertion_sort_list - swap nodes of doubly linked list
 * till the array is sorted
 * @list: pointer to doubly linked list
 *
 * Return: None
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *next_node, *next_2_node;

	if (!list || !(*list) || !(*list)->next)
		return;

	next_node = (*list)->next;
	while (next_node != NULL)
	{
		next_2_node = next_node;
		next_node = next_node->next;

		while (next_2_node && next_2_node->prev)
		{
			if (next_2_node->prev->n > next_2_node->n)
			{
				swap_nodes(next_2_node->prev, next_2_node);
				if (next_2_node->prev == NULL)
					*list = next_2_node;
				print_list((const listint_t *)*list);
			}
			else
				next_2_node = next_2_node->prev;
		}
	}
}
