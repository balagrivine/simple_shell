#include "header.h"
/**
 *create_node - creates a node
 *@data: data
 *Return: On success returns the new node, on faileure retuns NULL
 */
list_t *create_node(char *data)
{
	list_t *v = malloc(SIZE_OF_LIST_T);

	if (v == NULL)
		return (NULL);
	v->data = _strdup(data);
	v->next = NULL;
	return (v);
}
/**
 *delete_node - deletes a node
 *@env: deciding content factor on which node to be deleted
 *@_environ: works on environmental variable for the program
 *Return: On success returns a pointer on failure returns NULL
 */
list_t *delete_node(char *env, list_t **_environ)
{
	list_t *u = *_environ, *t = NULL;

	if (*_environ == NULL)
	{
		_print_str("Variable(s) Not set\n");
		free(env);
		return (NULL);
	}
	while (u)
	{
		if (_strncmp(u->data, env, _strlen(env)) == 0)
		{
			if (t == NULL)
			{
				*_environ = u->next;
			}
			else
			{
				t->next = u->next;
			}
			free(u->data);
			free(u);
			return (*_environ);
		}
		t = u;
		u = u->next;
	}
	_print_str("Environment does not exist\n");
	free(env);
	return (*_environ);
}
/**
 *add_node - adds a node
 *@head: it points to the node to be added
 *@data: data
 *Return: returns the node to be added, on failure NULL
 */
list_t *add_node(list_t **head, char *data)
{
	list_t *e = create_node(data);
	list_t *u;

	if (e == NULL)
		return (NULL);
	if (*head == NULL)
		*head = e;
	else
	{
		u = *head;
		while (u->next != NULL)
			u = u->next;
		u->next = e;
	}
	return (*head);
}
/**
 *get_environ - creates environment for the program
 *@_environ: the environment to be created
 *Return: returs environmental variable
 */
list_t *get_environ(list_t *_environ)
{
	char **c = environ;

	while (*c)
	{
		add_node(&_environ, *c);
		c++;
	}

	return (_environ);
}
