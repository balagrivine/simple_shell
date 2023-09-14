#include "header.h"
/**
 *and_or_input_err - display error message
 *@e_ex: program that prints the exact error message
 *@sc: count that displays the error message
 *Return: 2
 */
int and_or_input_err(char *e_ex, int sc)
{
	print_error(e_ex);
	print_error(": ");
	error_num(sc);
	print_error(AND_OR_INPUT_ERR);
	return (2);
}
/**
 *cd_err - display error message resulting in error message
 *@e_ex: program that prints the exact error message
 *@sc: count that displays the error message
 *@dir: destination of the directory causeing the error
 *Return: 2
 */
int cd_err(char *e_ex, int sc, char *dir)
{
	print_error(e_ex);
	print_error(": ");
	error_num(sc);
	print_error(CD_ERROR);
	print_error(dir);
	print_error("\n");
	return (2);
}
