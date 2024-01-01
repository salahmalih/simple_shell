#include "shell.h"
/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}

/**
 * _itoa - convert an integer to string.
 * @n: the integer.
 * Return: string.
*/
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	reverse_string(buffer, i);

	return (_strdup(buffer));
}
/*
 * freearrayStr - Frees the memory allocated for an array of strings.
 *
 * @arr: The array of strings to be freed.
 *
 * This function iterates through each string in the array and frees the
 * memory allocated for each string. Then, it frees the memory allocated
 * for the array itself. After freeing, it sets each element to NULL and
 * the array pointer to NULL to avoid dangling pointers.
 */
void freearrayStr(char **arr)
{
	int i = 0;

	if (!arr)
		return;
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}
/**
 * is_positive_number - check if a string is positive number.
 * @str: the string to check.
 * Return: 1 if the string is a positive number
 * otherwise 0.
*/
int is_positive_number(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
 .