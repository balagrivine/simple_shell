#include "header.h"
/**
 *_execute - handles the users commands
 *@path: path
 *@_argv: user's entery of commands
 *@e_ex: displays proper error message
 *@sc: session count for the program
 *Return: On success 0 and On failure not zero
 */
int _execute(char *path, char **_argv, char *e_ex,
		__attribute__((unused)) int sc)
{
	pid_t x;
	int v;

	x = fork();
	if (x == -1)
		return (-1);
	else if (x == 0)
	{

		if (execve(path, _argv, environ) == -1)
		{
			perror(e_ex);
			return (0);
		}
	}
	else
	{
		if (waitpid(x, &v, 0) == -1)
		{
			perror(e_ex);
		}
		if (v == 512)
		{
			return (2);
		}
		else if (v == 256)
			return (1);
	}
	return (0);
}
/**
 *_access - check's the path of the directorties
 *@path: path
 *@_argv: user's commands
 *@e_ex: displays proper error message
 *@sc: session count for the program
 *Return: On success 0 and On failure -2
 */
int _access(char *path, char **_argv, char *e_ex, int sc)
{
	if (access(path, X_OK) == 0)
	{
		return (_execute(path, _argv, e_ex, sc));
	}
	return (-2);
}
