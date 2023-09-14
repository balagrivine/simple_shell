#include "header.h"
/**
 *exec_err_msg - displays error message
 *@_argv: command strings to be used
 *@sc: displaying expected error message
 * @e_ex: proper display error message
 */
void exec_err_msg(char **_argv, char *e_ex, int sc)
{
	print_error(e_ex);
	print_error(": ");
	error_num(sc);
	print_error(": ");
	print_error(_argv[0]);
	print_error(EXEC_ERR);
}
/**
 *exit_err_msg - display error message
 *@_argv: Command strings to be used
 *@sc: displaying expected error message
 *@e_ex: proper display error message
 */
void exit_err_msg(char **_argv, char *e_ex, int sc)
{
	print_error(e_ex);
	print_error(": ");
	error_num(sc);
	print_error(EXIT_ERROR);
	print_error(_argv[1]);
	print_error("\n");
}
/**
 *setenv_usage_err_msg - displays error
 *@e_ex: diplay of error message
 */
void setenv_usage_err_msg(__attribute__((unused)) char *e_ex)
{
	print_error("Usage: setenv <VARIABLE> <VALUE>\n");
}
/**
 *unsetenv_usage_err_msg - display error
 *@e_ex: display of error message
 */
void unsetenv_usage_err_msg(__attribute__((unused)) char *e_ex)
{
	print_error("Usage: unsetenv <VARIABLE>\n");
}
/**
 *and_or_err - display error message
 *@e_ex: display of correct error message
 *@ao: paramerter
 *@sc: the count that displays the correct error
 *Return: returns 2
 */
int and_or_err(char *e_ex, char *ao, int sc)
{
	print_error(e_ex);
	print_error(": ");
	error_num(sc);
	print_error(LOGIC_ERROR);
	print_error(ao);
	print_error(LOGIC_ERRND);
	return (2);
}
