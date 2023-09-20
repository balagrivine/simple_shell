#include "header.h"
/**
 *sigintHandler - handles EOF
 *@sig_num: sign number
 *
 */
void sigintHandler(__attribute__((unused)) int sig_num)
{
	signal(SIGINT, sigintHandler);
	_print_str("\n$");
	fflush(stdout);
}
/**
 *main - entry function
 *@argc: number of arguments passed to the program
 *@argv: actual arguments passed to the program
 *Return: returns 0 on success and nonzero otherwise
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	size_t buff_size = 0;
	ssize_t getline_status;
	char *buffer = NULL;
	int sc = 0, ef = 0;
	list_t *_environ = NULL;

	_environ = get_environ(_environ);
	signal(SIGINT, sigintHandler);
	while (1)
	{
		sc++;
		if (isatty(STDIN_FILENO))
		{
			_putchar('$');
			fflush(stdout);
			getline_status = getline(&buffer, &buff_size, stdin);

			if (getline_status != -1)
			{
				if (_strcmp(buffer, "\n") == 0)
					continue;
				if (buffer[_strlen(buffer) - 1] == '\n')
					buffer[_strlen(buffer) - 1] = '\0';
				ef = semi_colon(buffer, argv[0], sc, _environ);
			}
			if ((getline_status == -1 && EOF) || (getline_status == -1 && SIGINT))
			{
				free(buffer);
				free_list(_environ);
				_putchar('\n');
				fflush(stdout);
				return (ef);
			}
		}
		else
			return (non_interactive(buff_size, getline_status,
						buffer, sc, argv[0], _environ));
	}
	return (0);
}
/**
 *non_interactive - handles non-interactive mode of the user input
 *@n: size of bytes to be read from input
 *@input_count: status of the getline function
 *@input: input from the user
 *@sc: session count
 *@e_ex: executable  for error handling
 *@_environ: environmental variables
 *Return: 0 on success and nonzero on error
 */
int non_interactive(size_t n, ssize_t input_count, char *input, int sc,
		char *e_ex, list_t *_environ)
{
	int ret_val;

	input_count = getline(&input, &n, stdin);
	if (input_count == -1 || input == NULL)
	{
		free(input);
		free_list(_environ);
		return (-1);
	}
	if (_strcmp(input, "\n") == 0)
	{
		free(input);

		return (-2);
	}
	if (input[_strlen(input) - 1] == '\n')
		input[_strlen(input) - 1] = '\0';
	ret_val = semi_colon(input, e_ex, sc, _environ);
	free(input);
	free_list(_environ);
	return (ret_val);
}
