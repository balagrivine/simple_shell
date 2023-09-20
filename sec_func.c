#include "header.h"
/**
 *_strlen - calculate the length of a string
 *@s: string whose length is to be calculated
 *Return: returns the lenth of the string
 */
size_t _strlen(const char *s)
{
	const char *position = s;

	while (*position)
	{
		position++;
	}
	return (position - s);
}
/**
 *_strdup - a function that duplicates a string
 *@str: string to be duplicated
 *Return: returns poiner to the new string
 *	on success and NULL on error
 */
char *_strdup(char *str)
{
	char *new_string;
	size_t length = (_strlen(str) + 1);

	new_string = malloc(length);
	if (new_string == NULL)
		return (NULL);
	_memcpy(new_string, str, length);
	return (new_string);
}
/**
 *_strcpy - copies an string to another string
 *@dest: destination string to be copied
 *@src: string to be copied
 *Return: returns a pointer to the copied string
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr_dest = dest;

	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (ptr_dest);
}
/**
 *_strcmp - compares two strigs
 *@s1: first string
 *@s2: sec string
 *Return: 0 if the strings are the same
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/**
 *_strncmp - compares only the first n bytes strings
 *@s1: first string
 *@s2: sec string
 *@n: number of bytes to be compared
 *Return: 0 if strings are the same
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
	{
		return (0);
	}
	while (*s1 && (*s1 == *s2) && --n)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
