#include "shell.h"

/**
 * is_builtin - checks if a command is a built-in command
 * @command: command to check
 *
 * Return: 1 if the command is a built-in, 0 otherwise
 */

int is_builtin(char *command)
{
	int i;
	char *builtins[] = {
		"exit", "env", "setenv",
		"unsetenv", "cd","alias",
		NULL
	};

	for (i = 0; builtins[i]; i++)
	{
		if (strcmp(command, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handle_builtin - executes the appropriate built-in command
 * @cmd: built-in command
 * @argv: array of arguments
 * @status: exit status
 * @idx: The index of the command in the command array.
 * @new_env: The environment variable as an array
 * of strings.
 *
 * Return: exit status
 */

void handle_builtin(char **cmd, char **argv, int *status, int idx,
char **new_env, list_t **head)
{
	if (strcmp(cmd[0], "exit") == 0)
		exit_builtin(cmd, argv[0], status, idx);
	else if (strcmp(cmd[0], "env") == 0)
		print_env(status);
	else if (strcmp(cmd[0], "setenv") == 0)
		_setenv(cmd, argv[0], status, idx);
	else if (strcmp(cmd[0], "unsetenv") == 0)
		_unsetenv(cmd, status);
	else if (strcmp(cmd[0], "cd") == 0)
		change_directory(cmd, argv, status, idx, new_env);
	else if (strcmp(cmd[0], "alias") == 0)
		_alias(cmd, status, head);
	freearrayStr(cmd);
}
