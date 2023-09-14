#include "header.h"
/**
 *check_error_comp - checks for	error in
 *			the syntax of the "&&"
 *			and "||" commands
 *@arr: array of strings to be checked for "&&"
 *	and "||" command errors
 *@token: command containing the "&&"
 *	and "||" commands
 *@j: iterates through the array of strings
 *@e_ex: program executable
 *@input: input by the user
 *@sc: session count
 *@_environ: environmental variable
 *Return: 0 on success and nonzero on error
 */
int check_error_comp(char **arr, char *token, int j,
		char *e_ex, char *input, int sc, list_t *_environ)
{
	if ((arr[j][_strlen(arr[j]) - 2] == '|' &&
				arr[j][_strlen(arr[j]) - 1] == '|') ||
			(arr[j][_strlen(arr[j]) - 2] == '&' &&
			 arr[j][_strlen(arr[j]) - 1] == '&'))
	{
		if (_strlen(arr[j]) > 2)
		{
			if (arr[j][_strlen(arr[j]) - 3] == '|' ||
					arr[j][_strlen(arr[j]) - 3] == '&')
			{
				free_array(arr);
				return (get_operators(token, e_ex, sc, input, _environ));
			}
			else
			{
				free_array(arr);
				return (and_or_user_input(token, e_ex, sc, _environ));
			}
		}
		free_array(arr);
		return (and_or_user_input(token, e_ex, sc, _environ));
	}
	free_array(arr);
	return (get_operators(token, e_ex, sc, input, _environ));
}
/**
 *handle_error_com - handles errors for "&&"
 *			and "||" commands
 *@arr: array of strings to be checked for "&&"
 *	and "||" command errors
 *@n: iteates through the array
 *@e_ex: program executable
 *@sc: session count
 *Return: 0 on success and nonzero on error
 */
int handle_error_com(char **arr, int n, char *e_ex, int sc)
{
	if ((arr[n][_strlen(arr[n]) - 2] == '&' &&
				arr[n][_strlen(arr[n]) - 1] == '&'))
	{
		return (handle_error_com_ex(arr, n, e_ex, sc, '&', "&&"));
	}
	else if ((arr[n][_strlen(arr[n]) - 2] == '|' &&
				arr[n][_strlen(arr[n]) - 1] == '|'))
	{
		return (handle_error_com_ex(arr, n, e_ex, sc, '|', "||"));
	}
	else if ((arr[n][_strlen(arr[n]) - 2] == '&' &&
				arr[n][_strlen(arr[n]) - 1] == '&'))
	{
		return (handle_error_com_ex(arr, n, e_ex, sc, '&', "&&"));
	}
	else if ((arr[n][_strlen(arr[n]) - 2] == '|' &&
				arr[n][_strlen(arr[n]) - 1] == '|'))
	{
		return (handle_error_com_ex(arr, n, e_ex, sc, '|', "||"));
	}
	return (0);
}
/**
 *handle_error_com_ex - handles error for "&&" and
 *			"||" commands
 *@arr: array of strings to be checked for "&&"
 *	and "||" command errors
 *@n: iterates through the array of strings
 *@e_ex: program executable
 *@sc: session count
 *@a: "|" or "&" fro error handling
 *@aa: variable for "&&" or "||" for error handling
 *Return: 0 on success and nonzero on error
 */
int handle_error_com_ex(char **arr, int n, char *e_ex, int sc, char a,
		char *aa)
{
	if (arr[n + 1])
	{
		if (arr[n + 1][0] == a && arr[n + 1][1] == a)
		{
			return (and_or_err(e_ex, aa, sc));
		}
	}
	return (0);
}

