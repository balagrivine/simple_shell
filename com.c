#include "header.h"
/**
 *comment - the user's input comments are handled
 *@input: user's input
 *@e_ex: the program executable for proper error display
 *@sc: program displays the correct error
 *@_environ: variables of program
 *Return: success 0 and On error not zero
 */
int comment(char *input, char *e_ex, int sc, list_t *_environ)
{
	int x;

	if (input[0] == '#')
	{
		input[0] = '\0';
		return (0);
	}
	for (x = 0; input[x]; x++)
	{
		if (input[x] == ' ' && input[x + 1] == '#')
		{
			input[x] = '\0';
			break;
		}
	}
	return (to_argv(input, e_ex, sc, _environ));
}
