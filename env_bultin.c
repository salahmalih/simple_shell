#include "shell.h"

/**
 * _setenv - Set environment variable
 * @command: Array of strings containing the command and arguments
 * @name: Name of the shell program
 * @status: Pointer to the exit status
 * @idx: Index of the command in the history
 */

void _setenv(char **command, char *name, int *status, int idx)
{
	int i;
	char *new, *tmp = NULL;
	char **env = environ;

	(void)idx;
	if (!command[1] || !command[2])
	{
		(*status) = 0;
		freearrayStr(command);
		freearrayStr(env);
		return;
	}
	for(i = 0; env[i] != NULL; i++)
	{
		tmp = _strdup(env[i]);
		if(strcmp(tmp, name) == 0)
		{
			_strcpy(tmp, command[1]);
			_strcat(tmp, "=");
			_strcat(tmp, command[2]);
			(*status) = 0;
			free(tmp);
			tmp = NULL;
			freearrayStr(env);
			freearrayStr(command);
			return;
		}
		free(tmp);
		tmp = NULL;
	}
	new = malloc(strlen(command[1]) + strlen(command[2]) + 2);
	if (!new)
	{
		freearrayStr(command);
		freearrayStr(env);
		return;
	}
	_strcpy(new, command[1]);
	_strcat(new, "=");
	_strcat(new, command[2]);
	env[i] = new;
	env[i+1] = NULL;
	(*status) =0;
}
/**
 * _unsetenv - Remove an environment variable.
 *
 * @command: An array of strings containing
 * the command and arguments.
 * @status: A pointer to an integer representing
 * the status of the operation.
 */
void _unsetenv(char **command, int *status)
{
	int i;
	char *tmp, *key;


	if (command[1])
	{
		for (i = 0; environ[i]; i++)
		{
			tmp = _strdup(environ[i]);
			key = strtok(tmp, "=");
			if (strcmp(command[1], key) == 0)
			{
				free(tmp), tmp = NULL;
				break;
			}
			free(tmp);
			tmp = NULL;
		}

		while (environ[i])
		{
			environ[i] = environ[i + 1];
			i++;
		}
	}
	(*status) = 0;
}
/**
 * print_env - Prints the environment variables
 * to the standard output.
 *
 * This function iterates through
 * the array of environment variables
 * and prints each variable
 * followed by a newline character.
 *
 * @status: Pointer to an integer to store
 * the status of the function.
 *
 */
void print_env(int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	(*status) = 0;
}
