#include "shell.h"
/**
 * write_error - Writes an error message to the standard error stream.
 *
 * @name: The name of the program or module.
 * @idx: The index or line number where the error occurred.
 * @cmd: The command or function associated with the error.
 * @mssg: The error message to be displayed.
 */
void write_error(char *name, int idx, char *cmd, char * mssg)
{
	char *index;

	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, _strlen(mssg));
	free(index);
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
		key = _strtok(tmp, "=");
		if (strcmp(key, env_key) == 0)
		{
			variable = _strtok(NULL, "\n");
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
