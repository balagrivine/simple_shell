#include "header.h"
/**
 *run_or_logical - handles execution of or logical operator
 *@newstr: command to be handled
 *@type: identify command to be executed
 *@e_ex: executable for error handling
 *@sc: count to handle errors
 *@_environ: environmental variables
 *Return: 0 on succeess and nonzero on error
 */
int run_or_logical(char *newstr, char type, char *e_ex,
		int sc, list_t *_environ)
{
	char *tkn, *ptr;
	int ret_val = 0;

	tkn = _strtok_r(newstr, ";", &ptr);
	if (tkn == NULL)
	{
		return (-1);
	}
	if (type == '|')
	{
		while (tkn)
		{
			ret_val = comment(tkn, e_ex, sc, _environ);
			if (ret_val == 0)
				break;
			tkn = _strtok_r(NULL, ";", &ptr);
		}
	}

	return (ret_val);
}
/**
 *or_operator - handles "||"
 *		command in the useer input
 *@token: input to be checked
 *@e_ex: executable for error handling
 *@sc: count
 *@_environ: environmental variables for the program
 *Return: 0 on succeess and nonzero on error
 */
int or_operator(char *token, char *e_ex, int sc, list_t *_environ)
{
	int ind, j = 0, size = _strlen(token), ret_val = 0;
	char *new_string = malloc(size + 1);

	if (new_string == NULL)
		return (-1);
	for (ind = 0; token[ind]; ind++)
	{
		if (token[ind] == '|' && token[ind + 1] == '|')
		{
			ind++;
			token[ind] = ';';
		}
		new_string[j] = token[ind];
		j++;
	}
	new_string[j] = '\0';

	ret_val = run_or_logical(new_string, '|', e_ex, sc, _environ);

	free(new_string);
	return (ret_val);
}
/**
 *or_in_and - handles "||" commands
 *		found within "&&" commands
 *@i: for iteration continuaion
 *@token: input to be checked
 *@e_ex: executable
 *@sc: session count
 *@ret_val: return value
 *@input: input to be freed
 *@_environ: environmental variables
 *Return: 0 on success and nonzero on error
 */
int or_in_and(int i, char *token, char *e_ex, int sc, int ret_val,
		char *input, list_t *_environ)
{
	char *new_string = NULL;
	int n = 0;

	for (; token[i]; i++)
	{
		if ((token[i] == '&' && token[i + 1] == '&'))
		{
			new_string[n] = '\0';
			if (ret_val != 0)
				or_operator(new_string, e_ex, sc, _environ);
			free(new_string);
			and_first(token, e_ex, sc, i, input, _environ);
			return (i);
		}

		if (new_string == NULL)
		{
			new_string = malloc(SIZE_OF_CHAR * (_strlen(token) + 1));
			if (new_string == NULL)
			{
				return (-1);
			}
		}

		new_string[n] = token[i];
		n++;
	}
	new_string[n] = '\0';
	if (ret_val != 0)
		or_operator(new_string, e_ex, sc, _environ);
	free(new_string);
	return (i);
}
/**
 *or_first - user input that has
 *		the "||" command first
 *@token: command string
 *@e_ex: program executable
 *@sc: session count
 *@i: iterates through the array of strings
 *@input: input to be freed
 *@_environ: environmental variables
 *Return: 0 on succeess and nonzero on error
 */
int or_first(char *token, char *e_ex, int sc, int i, char *input,
		list_t *_environ)
{
	char *new_string = NULL;
	int j = 0, n = 0, length = _strlen(token), ret_val = 0;

	for (; token[i]; i++)
	{
		if ((token[i] == '&' && token[i + 1] == '&'))
		{
			new_string[j] = '\0';
			ret_val = or_operator(new_string, e_ex, sc, _environ);
			i = and_in_or(i, token, e_ex, sc, input, _environ);
			free(new_string);
			new_string = NULL;

			if (i >= length)
				return (ret_val);
			j = 0;
			n++;
			if (i == -1)
				return (-1);
		}
		if (new_string == NULL)
		{
			new_string = malloc(SIZE_OF_CHAR * (_strlen(token) + 1));
			if (new_string == NULL)
			{
				return (-1);
			}
		}
		new_string[j] = token[i];
		j++;
	}
	new_string[j] = '\0';
	if (n == 0)
	{
		if (new_string != NULL)
			ret_val = or_operator(new_string, e_ex, sc, _environ);
	}
	free(new_string);
	return (ret_val);
}
