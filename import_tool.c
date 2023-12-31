#include "shell.h"

/**
 * _strtok - Custom string tokenizer that splits a string into tokens
 * @str: The input string to be tokenized
 * @delim: The delimiter string used to determine token boundaries
 *
 * Return: A pointer to the next token in the string, or NULL if no more tokens
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	/* Initialize or reset static variables on the first function call */
	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str;
		i = _strlen(str);
		str_end = &str[i];
	}

	str_start = splitted;

	/* Return NULL if there are no more tokens in the string */
	if (str_start == str_end)
		return (NULL);

	/* Tokenize the string based on the specified delimiter */
	for (bool = 0; *splitted; splitted++)
	{
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted)
			bool = 1;
	}

	/* Return NULL if there are no more tokens in the string */
	if (bool == 0)
		return (NULL);

	return (str_start);
}
