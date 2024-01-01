#include "shell.h"
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
