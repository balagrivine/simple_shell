#include "header.h"
/**
 *order - checks the order of
 *	a "&&" and "||" command
 *@token: command to be checked
 *Return: 2 if "||" command comes
 *	first and 0 if "&&" comes first
 */
int order(char *token)
{
	int ind;

	for (ind = 0; token[ind]; ind++)
	{
		if (token[ind] == '|' && token[ind + 1] == '|')
			return (2);
		if (token[ind] == '&' && token[ind + 1] == '&')
			return (0);
	}
	return (0);
}
/**
 *get_operators - sorts the "&&"
 *		and "||" command depending on
 *		which comes first
 *@token: user command
 *@e_ex: program executable
 *@sc: session count
 *@input: user input
 *@_environ: environmental variables
 *Return: returns 0 on success and nonzero on error
 */
int get_operators(char *token, char *e_ex, int sc, char *input,
				  list_t *_environ)
{

	if (order(token) == 2)
	{
		return (or_first(token, e_ex, sc, 0, input, _environ));
	}
	return (and_first(token, e_ex, sc, 0, input, _environ));
}
/**
 *and_or_check - checks if a
 *		command contains "&&" or "||"
 *@token: command to be checked
 *@e_ex: program executable
 *@sc: session count
 *@input: user input to be freed
 *@_environ: environmental variables
 *Return: 0 on success and nonzero on error
 */
int and_or_check(char *token, char *e_ex, int sc, char *input,
				 list_t *_environ)
{
	int index;

	for (index = 0; token[index]; index++)
	{
		if ((token[index] == '&' && token[index + 1] == '&') ||
			(token[index] == '|' && token[index + 1] == '|'))
		{
			return (check_error(token, e_ex, sc, input, _environ));
		}
	}
	return (comment(token, e_ex, sc, _environ));
}
/**
 *handle_error - handles error
 *		in a "&&" and "||" command
 *@arr: array of strings to be checked for
 *	"||" and "&&" error
 *@input: user command
 *@j: for iteration continuation
 *@u_input: user input
 *@_environ: environmental variables
 *@n: for iteration
 *@i: for iteration
 *@e_ex: program executable
 *@sc: count
 *Return: 0 on success and nonzero on error
 */
int handle_error(char **arr, char *input, int j, char *u_input,
		list_t *_environ, int n, int i, char *e_ex, int sc)
{
	int ret = 0;

	for (n = 0; arr[n]; n++)
	{
		for (i = 0; arr[n][i]; i++)
		{
			if ((arr[n][i] == '&' && arr[n][i + 1] == '&') &&
				(arr[n][i + 2] == '&' && arr[n][i + 3] == '&'))
			{
				return (and_or_err(e_ex, "&&", sc));
			}
			else if ((arr[n][i] == '|' && arr[n][i + 1] == '|') &&
					 (arr[n][i + 2] == '|' && arr[n][i + 3] == '|'))
			{
				return (and_or_err(e_ex, "||", sc));
			}
			else if ((arr[n][i] == '&' && arr[n][i + 1] == '&') &&
					 (arr[n][i + 2] == '|' && arr[n][i + 3] == '|'))
			{
				return (and_or_err(e_ex, "||", sc));
			}
			else if ((arr[n][i] == '|' && arr[n][i + 1] == '|') &&
					 (arr[n][i + 2] == '&' && arr[n][i + 3] == '&'))
			{
				return (and_or_err(e_ex, "&&", sc));
			}
			else
			{
				ret = handle_error_com(arr, n, e_ex, sc);
				if (ret != 0)
					return (ret);
			}
		}
	}
	return (check_error_comp(arr, input, j, e_ex, u_input, sc, _environ));
}
/**
 *check_error - checks for error in
 *		the "&&" and "||" user command
 *@input: command to be checked
 *@e_ex: program executable
 *@sc: session count
 *@u_input: user input
 *@_environ: environmental variables
 *Return: 0 on success and nonzero on error
 */
int check_error(char *input, char *e_ex, int sc, char *u_input,
		list_t *_environ)
{
	int ind = 0, num = 0, j = 0;
	char *tkn, *string = _strdup(input);
	char **arr = malloc(_strlen(input) * SIZE_OF_CHARP);

	if (arr == NULL)
		return (-1);
	tkn = _strtok(string, " \t");
	if (tkn == NULL)
		return (-1);
	while (tkn)
	{
		arr[ind] = _strdup(tkn);
		ind++;
		tkn = _strtok(NULL, " \t");
	}
	arr[ind] = NULL;
	j = (ind - 1);
	if ((arr[0][0] == '&' && arr[0][1] == '&'))
	{
		return (error_and_free(string, e_ex, "&&", arr, sc));
	}
	if ((arr[0][0] == '|' && arr[0][1] == '|'))
	{
		return (error_and_free(string, e_ex, "||", arr, sc));
	}
	free(string);
	return (handle_error(arr, input, j, u_input, _environ, num, ind, e_ex, sc));
}

