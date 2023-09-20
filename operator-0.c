#include "header.h"

/**
 *run_and_logical - handles the executing of "&&" operator
 *@newstr: contains the "&&" commands
 *@type: indicate the type of commandto be entered
 *@e_ex: contains the program executable file
 *@sc: counter for when the error is displayed
 *@_environ: works on environmental variable for the program
 *Return: 0 on success and error if not 0
 */
int run_and_logical(char *newstr, char type, char *e_ex, int sc,
		list_t *_environ)
{
	char *x, *j;
	int z = 0;

	x = _strtok_r(newstr, ";", &j);
	if (x == NULL)
	{
		return (-1);
	}
	if (type == '&')
	{
		while (x)
		{
			z = comment(x, e_ex, sc, _environ);
			if (z != 0)
				break;
			x = _strtok_r(NULL, ";", &j);
		}
	}

	return (z);
}
/**
 *and_operator - handles commands of "&&" and executing
 *@token: user's command
 *@e_ex: contains the program executable file
 *@sc: counter for when the error is displayed
 *@_environ: works on environmental variable for the program
 *Return: 0 on success and  error  if not 0
 */
int and_operator(char *token, char *e_ex, int sc, list_t *_environ)
{
	int a, b = 0, size = _strlen(token), z = 0;
	char *m = malloc(size + 1);

	if (m == NULL)
		return (-1);
	for (a = 0; token[a]; a++)
	{
		if (token[a] == '&' && token[a + 1] == '&')
		{
			a++;
			token[a] = ';';
		}
		m[b] = token[a];
		b++;
	}
	m[b] = '\0';
	z = run_and_logical(m, '&', e_ex, sc, _environ);
	free(m);
	return (z);
}

/**
 *and_in_or - handles commands for  "&&" also  "||" commands
 *@i: continuity
 *@token: user's commands
 *@e_ex: contains the program executable file
 *@sc: counter for when the error is displayed
 *@input: users input
 *@_environ: works on environmental variable of the program
 *Return: 0 on success and error if not 0
 */

int and_in_or(int i, char *token, char *e_ex, int sc, char *input,
		list_t *_environ)
{
	char *m = NULL;
	int w = 0, z;

	for (; token[i]; i++)
	{
		if ((token[i] == '|' && token[i + 1] == '|'))
		{
			m[w] = '\0';
			z = and_operator(m, e_ex, sc, _environ);
			free(m);
			if (z != 0)
				or_first(token, e_ex, sc, i, input, _environ);
			return (i);
		}

		if (m == NULL)
		{
			m = malloc(SIZE_OF_CHAR * (_strlen(token) + 1));
			if (m == NULL)
			{
				return (-1);
			}
		}

		m[w] = token[i];
		w++;
	}
	m[w] = '\0';
	and_operator(m, e_ex, sc, _environ);
	free(m);
	return (i);
}
/**
 *and_first - handles commands for "&&" &  "||"
 *@token: users command
 *@e_ex:contains the program executable file
 *@sc: counter for when the error is displayed
 *@i: continuity
 *@input: user's input
 *@_environ: works on environmental variable for the program
 *Return: 0 on success and error if not 0
 */
int and_first(char *token, char *e_ex, int sc, int i, char *input,
		list_t *_environ)
{
	char *m = NULL;
	int k = 0, l = 0, e = _strlen(token), z = 0;

	for (; token[i]; i++)
	{
		if ((token[i] == '|' && token[i + 1] == '|'))
		{
			m[k] = '\0';
			z = and_operator(m, e_ex, sc, _environ);
			i = or_in_and(i, token, e_ex, sc, z, input, _environ);
			free(m);
			m = NULL;
			if (i >= e)
				return (z);
			k = 0;
			l++;
			if (i == -1)
				return (-1);
		}

		if (m == NULL)
		{
			m = malloc(SIZE_OF_CHAR * (_strlen(token) + 1));
			if (m == NULL)
			{
				return (-1);
			}
		}
		m[k] = token[i];
		k++;
	}
	if (l == 0)
	{
		if (m != NULL)
			m[k] = '\0';
		z = and_operator(m, e_ex, sc, _environ);
	}
	free(m);
	return (z);
}
