#include "header.h"
/**
 *exit_func - handle the users commands before exiting
 *@_argv: inputs of user
 *@e_ex: change for the program to display error handling
 *@sc: handling of error
 *@copy: string before exiting
 *@input: input
 *@_environ: variables
 *Return: On error 2, else exits the program
 */
int exit_func(char **_argv, char *e_ex, int sc, char *copy,
		char *input, list_t *_environ)
{
	char *t, v, x;
	int s, b;

	if (_argv[1])
	{
		t = _argv[1];
		for (b = 0; t[b]; b++)
		{
			for (v = 'A', x = 'a'; v <= 'Z'; v++, x++)
			{
				if (t[b] == v || t[b] == x)
				{
					exit_err_msg(_argv, e_ex, sc);
					fflush(stdout);
					return (2);
				}
			}
		}
		s = _atoi(t);
		if (s < 0 || s > 999999999)
		{
			exit_err_msg(_argv, e_ex, sc);
			fflush(stdout);
			return (2);
		}
		free_list(_environ);
		free(copy);
		free(_argv);
		free(input);
		exit(s);
	}
	free_list(_environ);
	free(copy);
	free(_argv);
	free(input);
	exit(0);
}
