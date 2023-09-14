#include "header.h"
/**
 *to_argv - converts user input for execution
 *@input: user's input
 *@e_ex: program that provides error message
 *@sc: count
 *@_environ: variable of the program
 *Return: on success 0 and on error not zero
 */
int to_argv(char *input, char *e_ex, int sc, list_t *_environ)
{
	char *o, **j = NULL, *p = _strdup(input);
	int i = 0, z;

	if (p == NULL)
		return (-1);
	o = _strtok(p, " \t");
	if (o == NULL)
	{
		free(p);
		return (-1);
	}
	while (o)
	{
		if (*o != '\0')
		{
			j = _realloc(j, (i + 1) * SIZE_OF_CHARP);
			if (j == NULL)
			{
				free(p);
				free(j);
				return (-1);
			}
			j[i] = o;
			i++;
		}
		o = _strtok(NULL, " \t");
	}
	j = _realloc(j, (i + 1) * SIZE_OF_CHARP);
	if (j == NULL)
	{
		free(p);
		free(j);
		return (-1);
	}
	j[i] = NULL;
	z = _identify(j, e_ex, sc, p, input, _environ);
	free(p);
	free(j);
	return (z);
}

