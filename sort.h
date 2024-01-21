#ifndef SORT_H
#define SORT_H

/* libraries declaration section */
#include <stddef.h>

/* structures declaration section */

/**
 * struct listint_s - doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* prototypes declaration section */
void print_array(const int *, size_t);
void print_list(const listint_t *);
void bubble_sort(int *array, size_t size);
void quick_sort(int *, size_t);


#endif
