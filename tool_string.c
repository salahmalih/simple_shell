#include "shell.h"
/**
 * _strdup - function that returns a pointer,
 * to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 *
 * @str: Memory for the new string is obtained
 *
 * Return: pointer.
 */

char *_strdup(char *str)
{
	int size, i;
	char *pnt;

	if (str == NULL)
		return (NULL);
	size = 0;
	while (str[size])
	{
		size++;
	}
	pnt = malloc(sizeof(char) * (size + 1));
	if (pnt == NULL)
		return (NULL);
	for (i = 0; i < size + 1; i++)
	{
		pnt[i] = str[i];
	}

	return (pnt);
}
/**
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: string to append to
 * @src: string to add
 *
 * Return: a pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
