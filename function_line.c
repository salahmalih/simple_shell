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
/**
 * set_wd_env - set environment for PWD and OLDPWD.
 * @env_key: environment key.
 * @env_value: environment value.
 * @new_env: new_environment variable.
 * Return: (void).
*/
void set_wd_env(char *env_key, char *env_value, char **new_env)
{
	int i;
	char *key, *variable, *tmp, *new;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (strcmp(key, env_key) == 0)
		{
			variable = strtok(NULL, "\n");
			if (strcmp(variable, env_value) == 0)
			{
				free(tmp);
				return;
			}
			_strcpy(environ[i], env_key);
			_strcat(environ[i], "=");
			_strcat(environ[i], env_value);
			free(tmp);
			return;
		}
		free(tmp), tmp = NULL;
	}
	new = malloc(_strlen(env_key) + _strlen(env_value) + 2);
	_strcpy(new, env_key);
	_strcat(new, "=");
	_strcat(new, env_value);
	environ[i] = new, environ[i + 1] = NULL;
	(*new_env) = new;
}
