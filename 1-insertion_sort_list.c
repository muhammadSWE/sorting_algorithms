#include "sort.h"
/**
 *insertion_sort_list - sorts a linked list using Insert Sort algorithm
 *@list: double pointer to the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *first = NULL;
	listint_t *second = NULL, *third = NULL, *fourth = NULL;

	if (!list || !(*list) || list_length(*list) < 2)
		return;

	current = *list;

	while (current)
	{
		if (current->prev && current->n < current->prev->n)
		{
			first = current->prev->prev;
			second = current->prev;
			third = current;
			fourth = current->next;

			second->next = fourth;
			if (fourth)
				fourth->prev = second;
			third->next = second;
			third->prev = first;
			if (first)
				first->next = third;
			else
				*list = third;
			second->prev = third;
			current = *list;
			print_list(*list);
			continue;
		}
		else
			current = current->next;
	}
}
#include "sort.h"
/**
 *list_length - returns the length of a linked list
 *@p: pointer to the list
 *
 *Return: length of list
 */
int list_length(listint_t *p)
{
	int len = 0;

	while (p)
	{
		len++;
		p = p->next;
	}
	return (len);
}
