#include "header.h"
/**
 *and_or_user_input - accept input from user contains "&&" & "||"
 *@input: user input
 *@e_ex:needed for the program
 *@sc: counts
 *@_environ: variable for the program
 *Return: on success 0 and on error not zero
 */
int and_or_user_input(char *input, char *e_ex, int sc, list_t *_environ)
{
	int z = 0;
	size_t f = 0;
	ssize_t g;
	char *u = NULL;

	while (1)
	{
		_print_str(">");
		fflush(stdout);
		g = getline(&u, &f, stdin);
		if (g != -1)
		{
			if (_strcmp(u, "\n") == 0)
				continue;
			if (u[_strlen(u) - 1] == '\n')
			{
				u[_strlen(u) - 1] = '\0';
				if (u[0] == '#')
					continue;
				_strcat(input, u);
				free(u);
				z = semi_colon(input, e_ex, sc, _environ);
				return (z);
			}
			if ((g == -1 && EOF) || (g == -1 && SIGINT))
			{
				free(u);
				return (and_or_input_err(e_ex, sc));
			}
		}
		else
			return (z);
	}
	return (z);
}
