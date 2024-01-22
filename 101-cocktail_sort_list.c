#include "sort.h"

/**
 * switch_nodes - a function that switches two nodes
 * @list: head of the list
 * @p: pointer to a node
 */

void switch_nodes(listint_t **list, listint_t **p)
{
	listint_t *one, *two, *three, *four;

	one = (*p)->prev;
	two = *p;
	three = (*p)->next;
	four = (*p)->next->next;
	two->next = four;
	if (four)
		four->prev = two;
	three->next = two;
	three->prev = two->prev;
	if (one)
		one->next = three;
	else
		*list = three;
	two->prev = three;
	*p = three;
}

/**
 * list_len - function that returns the length of a list
 * @list: doubly linked list
 * Return: length
 */

size_t list_len(listint_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/**
 * cocktail_sort_list - sorts a list with the cocktail sort mecanism
 * @list: doubly linked list to be sorted
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *p;
	int swap = 1;

	if (!list || !*list || list_len(*list) < 2)
		return;

	p = *list;
	while (swap)
	{
		swap = 0;
		while (p->next)
		{
			if (p->n > p->next->n)
			{
				swap = 1;
				switch_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->next;
		}
		if (!swap)
			break;

		while (p->prev)
		{
			if (p->n < p->prev->n)
			{
				swap = 1;
				p = p->prev;
				switch_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->prev;
		}
	}
}
