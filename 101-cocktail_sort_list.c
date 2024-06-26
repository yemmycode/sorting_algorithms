#include "sort.h"

void swap_nodes_forward(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_nodes_backward(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_nodes_forward - Swaps a node in a listint_t doubly-linked list
 *                      of integers with the node ahead of it.
 * @list: pointer to the head of a doubly-linked list of integers.
 * @tail: pointer to the tail of the doubly-linked list.
 * @shaker: pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_nodes_forward(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_nodes_backward - Swaps a node in a listint_t doubly-linked
 *                       list of integers with the node behind it.
 * @list: pointer to the head of a doubly-linked list of integers.
 * @tail: pointer to the tail of the doubly-linked list.
 * @shaker: pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_nodes_backward(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool stirred_not_shaken = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (stirred_not_shaken == false)
	{
		stirred_not_shaken = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_nodes_forward(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				stirred_not_shaken = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_nodes_backward(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				stirred_not_shaken = false;
			}
		}
	}
}
