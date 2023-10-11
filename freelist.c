#include "main.h"

/**
 * add_node- add
 * @head: ...
 * @str: .....
 * Return: ....
 */

list_t *add_node(list_t **head, char *str)
{
	list_t *add_node;

	add_node = malloc(sizeof(list_t));
		add_node->str = str;
	add_node->next = *head;
	*head = add_node;

	return (add_node);
}

/**
 * free_list - Realease the memory allocated for a list
 *
 * @head: A pointer to the first node of the list to free
 */
void free_list(list_t *head)
{
	if (head)
	{
		free_list(head->next);
		if (head->str)
			free(head->str);
		free(head);
	}
}
