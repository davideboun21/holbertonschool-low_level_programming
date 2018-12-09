#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts node at index
 * @h: head of node
 * @idx: index to insert node
 * @n: data for new node
 * Return: list with inserted node
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int count = 1;
	dlistint_t *temp = NULL, *new = NULL;

	if (h == NULL)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;

	temp = *h;
	while (temp != NULL)
	{
		if (count == idx) /* found back */
		{
			new->prev = temp;
			new->next = temp->next;
			temp->next = new;
		}
		if (count == (idx + 1)) /* found front */
		{
			temp->prev = temp->prev->next;
		}
		temp = temp->next;
		count++;
	}

	if (count < idx)
	{
		free(new);
		return (NULL);
	}
	else
	{
		return (new);
	}

	return (NULL);
}
