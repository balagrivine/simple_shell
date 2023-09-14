#include "header.h"
/**
 *cd_command - navigates paths and directories of the program
 *@path: path displayed by the user
 *@e_ex: executing to display correct error
 *@sc: counter to display the error
 *@_environ: variables of program
 *Return: on success 0 and on error not zero
 */
int cd_command(char *path, char *e_ex, int sc, list_t *_environ)
{
	char *rep, *try;

	if (path == NULL)
	{
		rep = _getenv("HOME", _environ);
		if (chdir(rep) == -1)
			return (cd_err(e_ex, sc, path));
		return (0);
	}
	if (_strcmp(path, "-") == 0)
	{
		try = _getenv("OLDPWD", _environ);
		if (chdir(try) == -1)
			return (cd_err(e_ex, sc, path));
	}
	if (chdir(path) == -1)
		return (cd_err(e_ex, sc, path));
	return (0);
}
