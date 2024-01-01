#include "shell.h"

/**
 * _getenv - Retrieves the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable or NULL if not found.
 */

char *_getenv(const char *name)
{
	char **env = environ;

	while (*env != NULL)
	{
		if (strncmp(*env, name, _strlen(name)) == 0)
		{
			return (_strchr(*env, '=') + 1);
		}
		env++;
	}
	freearrayStr(env);
	return (NULL);
}

/**
 * read_line - Reads a line from the standard input.
 *
 * Return: A pointer to the read line or NULL on failure.
 */

char *read_line()
{
	size_t char_c = 0;
	char *buffer = NULL;
	size_t lent_buffer = 0;

	if (isatty(STDIN_FILENO))
	{
		write(1, "$ ", 2);
	}
	char_c = getline(&buffer, &lent_buffer, stdin);
	if ((int)char_c == -1)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer[char_c - 1] = '\0';
	return (buffer);
}
