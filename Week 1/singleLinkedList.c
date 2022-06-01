/**
 * @file singleLinkedList.c
 * @author Innocent Chukwuemeka
 * @brief Creating a linked list and performing different operations
 * @version 0.1
 * @date 2022-06-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdlib.h>
#include <stdio.h>

/**
 * struct list - singly linked list struct
 * @str: string
 * @len: length of the string
 * @next: pointer to the next node
 *
 * Description: singly linked list node structure
 */

typedef struct list
{
	int val;
	struct list *next;
} list_t;

/**
 * print_list - prints all the elements of a list_t list
 * @h: list
 *
 */

void print_list(const list_t *h)
{

	const list_t *current = h;
    int i = 0;

	while (current != NULL)
	{
		printf("node %d:  with value: %d\n", i, current->val);
		current = current->next;
		i++;
	}
}

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: first node in the list
 * @number: string for a node
 *
 * Return: updated list
 */
list_t *add_node_end(list_t **head, int number)
{
	list_t *temp;
	list_t *current;

	current = *head;

	while (current && current->next != NULL)
		current = current->next;

	temp = malloc(sizeof(list_t));

	if (temp == NULL)
	{
		free(temp);
		return (NULL);
	}

	temp->val = number;
	temp->next = NULL;

	if (current)
		current->next = temp;
	else
		*head = temp;

	return (temp);
}


/**
 * free_list - function that frees a list_t
 * @head: beginning of list pointer
 *
 */

void free_list(list_t *head)
{
	list_t *current, *nxt;

	current = head;

	while (current != NULL)
	{
		nxt = current->next;
		free(current);
		current = nxt;
	}
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	list_t *head;

	head = NULL;
	add_node_end(&head, 1);
	add_node_end(&head, 2);
	add_node_end(&head, 3);
	add_node_end(&head, 4);
	add_node_end(&head, 5);
	print_list(head);
	free_list(head);
	head = NULL;
	return (0);
}