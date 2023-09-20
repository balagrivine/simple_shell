#include "header.h"
/**
 *semi_colon - handles the semi colon
 *@input: user command input
 *@e_ex: program executable for error
 *	handling
 *@sc: session count for error handling
 *@_environ: custom environmenta variables
 *		for the program
 *Return: returns 0 on success and nonzero
 *	on error
 */
int semi_colon(char *input, char *e_ex, int sc, list_t *_environ)
{
	char *tkn, *ptr;
	int ret_val;

	if (input[0] == ';')
		return (and_or_err(e_ex, ";", sc));

	tkn = _strtok_r(input, ";", &ptr);
	if (tkn == NULL)
	{
		return (-1);
	}
	while (tkn)
	{
		ret_val = and_or_check(tkn, e_ex, sc, input, _environ);
		tkn = _strtok_r(NULL, ";", &ptr);
	}
	return (ret_val);
}
