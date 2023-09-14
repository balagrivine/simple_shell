#include "header.h"
/**
 *_setenv - creating new environmental varibale for the user
 *@env: newvariable to be named
 *@value: value to be set for the variable
 *@_environ: varibales to be changed
 *Return: On success 0 and On error not zero
 */
int _setenv(char *env, char *value, list_t **_environ)
{
	char *p;
	list_t *cur = *_environ;

	p = to_env_var(env, value);
	while (cur)
	{
		if (_strncmp(cur->data, p, _strlen(env) + 1) == 0)
		{
			free(cur->data);
			cur->data = _strdup(p);
			free(p);
			return (0);
		}
		cur = cur->next;
	}
	add_node(_environ, p);
	free(p);
	return (0);
}
/**
 *_unsetenv - deletion of variables in the program
 *@env: variable to be removed
 *@_environ: environment for the program to be nodified
 *Return: on success 0 and on error not zero
 *
 */
int _unsetenv(char *env, list_t **_environ)
{
	list_t *c = *_environ;
	char *t = malloc(_strlen(env) + 2);

	if (t == NULL)
		return (-1);
	_strcpy(t, env);
	t = _strcat(t, "=");
	if (delete_node(t, &c) == NULL)
	{
		free(t);
		return (-1);
	}
	free(t);
	return (0);
}
