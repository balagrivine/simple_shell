#include "header.h"
/**
 *_strncpy - copies n bytes of
 *	strings
 *@dest: destination
 *@src: string to be copied
 *@n: number of bytes to be copied
 *Return: returns a pointer to the dest string
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t ind;

	for (ind = 0; ind < n && src[ind]; ind++)
		dest[ind] = src[ind];
	dest[ind] = '\0';
	return (dest);
}
/**
 *_strchr - searches for the first
 *	occurance of a character in a string
 *@str: string to be searched
 *@c: charcter to search for
 *Return: return a pointer to the matched character
 *	or NULL if the character is not found
 */
char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (c == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}
/**
 *_strcat - a function that concatenates two strings
 *@dest: destination
 *@src: string to be concatenated
 *Return: returns a pointer to the dst string
 */
char *_strcat(char *dest, const char *src)
{
	char *dest_start = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_start);
}
/**
 *_strtok_r - a function that tokenizes a string using
 *		provided delimeter
 *@str: strng to be tokenized
 *@delim: delimeter
 *@saveptr: pointer to a char variable
 *Return: return a pointer to the next token, or NULL
 *	if there are no more tokens
 */
char *_strtok_r(char *str, const char *delim, char **saveptr)
{
	char *start;
	char *end;

	if (str != NULL)
		*saveptr = str;

	if (*saveptr == NULL || **saveptr == '\0')
		return (NULL);

	start = *saveptr;
	end = _strpbrk(start, delim);

	if (end != NULL)
	{
		*end = '\0';
		*saveptr = end + 1;
	}
	else
		*saveptr = NULL;
	return (start);
}
/**
 *_strpbrk - a function that searches for the first
 *	occurence of a string
 *@s: string to search for
 *@accept: string to be searched
 *Return: retruns a apointer to the found string
 *	or NULL if none is found
 */
char *_strpbrk(const char *s, const char *accept)
{
	const char *var;

	if (s == NULL || accept == NULL)
		return (NULL);

	while (*s != '\0')
	{
		var = accept;
		while (*var != '\0')
		{
			if (*s == *var)
			{
				return ((char *)s);
			}
			var++;
		}
		s++;
	}

	return (NULL);
}

