#include "header.h"
/**
 *free_array - free string of array
 *@arr: array
 */
void free_array(char **arr)
{
	int x;

	for (x = 0; arr[x]; x++)
		free(arr[x]);
	free(arr);
}
/**
 *free_list - frees list
 *@head: points to the list that is to be freed
 */
void free_list(list_t *head)
{
	list_t *e;

	while (head)
	{
		e = head;
		head = head->next;
		free(e->data);
		free(e);
	}
}
/**
 *error_and_free - frees a string & array
 *@str: string
 *@e_ex: program that displays error message
 *@i_e: has the string thats displays error message
 *@arr: array
 *@sc: handling error  message
 *Return: 2
 */
int error_and_free(char *str, char *e_ex, char *i_e, char **arr, int sc)
{
	free(str);
	free(arr);
	return (and_or_err(e_ex, i_e, sc));
}
/**
 *return_and_free - a function that frees string and an array
 *@str: string
 *@arr: array
 *@ret_val: value
 *Return: On success 0, else not zero
 */
int return_and_free(char *str, char **arr, int ret_val)
{
	free(str);
	free(arr);
	return (ret_val);
}
