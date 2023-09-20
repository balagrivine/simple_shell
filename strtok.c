#include "header.h"
/**
 *_strtok - tokenizes a string
 *@str: striing to be tokenized
 *@delim: delimeter
 *Return: pointer to the next
 *	token nad NULL if none is found
 */
char *_strtok(char *str, const char *delim)
{
	static char *token;
	char *start;
	char *end;

	if (str != NULL)
		token = str;
	if (token == NULL)
		return (NULL);
	start = token;
	while (*start != '\0' && _strchr(delim, *start) != NULL)
		start++;
	if (*start == '\0')
	{
		token = NULL;
		return (NULL);
	}
	end = start + 1;
	while (*end != '\0' && _strchr(delim, *end) == NULL)
		end++;
	if (*end != '\0')
	{
		*end = '\0';
		token = end + 1;
	}
	else
		token = NULL;

	return (start);
}
/**
 *_strcspn - finds newline character and removes it from the user input
 *@str1: string 1
 *@str2: string 2
 *Return: number of bytes in the initial segment of str1
 */
size_t _strcspn(const char *str1, const char *str2)
{
	size_t count;
	const char *pos;

	count = 0;

	for (; *str1; ++str1)
	{
		for (pos = str2; *pos; ++pos)
		{
			if (*str1 == *pos)
			{
				return (count);
			}
		}
		++count;
	}

	return (count);
}
/**
 *_realloc - reallocates memory
 *@ptr: pointer whose memory is to be modified
 *@size: size of the memory to be reallocated
 *Return: pointer to the new memory
 *	on success and NULL on error
 */
void *_realloc(void *ptr, size_t size)
{
	size_t old;
	void *new_ptr = NULL;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		return (malloc(size));
	}

	new_ptr = malloc(size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}

	old = malloc_usable_size(ptr);
	_memcpy(new_ptr, ptr, old < size ? old : size);
	free(ptr);

	return (new_ptr);
}
/**
 *_strspn - function calculates the length
 *	of the initial segment of str
 *@str: string for the calculation
 *@set: string to be checked
 *Return: bytes in the initial
 *	segment of s which are not in the string reject
 *
 */
size_t _strspn(const char *str, const char *set)
{
	size_t length;
	const char *pos = set;

	length = 0;

	while (*str)
	{
		while (*pos && *pos != *str)
		{
			pos++;
		}
		if (!*pos)
		{
			return (length);
		}
		pos = set;
		length++;
		str++;
	}

	return (length);
}
/**
 *_memcpy - copies memory from src to dest
 *@dest: destination
 *@src: srource of the memory
 *@n: size of memory to be copied to dest
 *Return: returns a pointer to the copied memry
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	size_t ind;
	unsigned char *destination = (unsigned char *)dest;
	const unsigned char *source = (const unsigned char *)src;

	for (ind = 0; ind < n; ++ind)
	{
		destination[ind] = source[ind];
	}

	return (dest);
}
