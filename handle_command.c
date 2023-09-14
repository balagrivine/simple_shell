#include "header.h"
/**
 *_identify - identifies a command
 *@_argv: array of command strings
 *@e_ex: program executable
 *@sc: session count
 *@copy: string to be freed
 *@input: user inut to be freed
 *@_environ: environmental variables
 *Return: 0 on success and nonzero on error
 */
int _identify(char **_argv, char *e_ex, int sc, char *copy,
		char *input, list_t *_environ)
{
	if (_strcmp(_argv[0], "exit") == 0)
		return (exit_func(_argv, e_ex, sc, copy, input, _environ));
	else if (_strcmp(_argv[0], "env") == 0)
	{
		print_list(_environ);
		return (0);
	}
	else if (_strcmp(_argv[0], "cd") == 0)
	{
		return (cd_command(_argv[1], e_ex, sc, _environ));
	}
	else if (_strcmp(_argv[0], "setenv") == 0)
	{
		if (_argv[1] && _argv[2])
		{
			return (_setenv(_argv[1], _argv[2], &_environ));
		}
		setenv_usage_err_msg(e_ex);
		return (2);
	}
	else if (_strcmp(_argv[0], "unsetenv") == 0)
	{
		if (_argv[1])
		{
			return (_unsetenv(_argv[1], &_environ));
		}
		unsetenv_usage_err_msg(e_ex);
		return (0);
	}
	return (locate_path(_argv, e_ex, sc));
}
