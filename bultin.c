#include "shell.h"

/**
 * is_builtin - checks if a command is a built-in command
 * @cmd: command to check
 *
 * Return: 1 if the command is a built-in, 0 otherwise
 */
int is_builtin(char *command)
{
	int i;
	char *builtins[] = {
		"exit", "env", "setenv",
		"unsetenv", "cd",
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
 *
 * Return: exit status
 */
void handle_builtin(char **cmd, char **argv, int *status, int idx,
char **new_env)
{

	if (strcmp(cmd[0], "exit") == 0)
		exit_builtin(cmd, argv[0], status, idx);
	if (strcmp(cmd[0], "env") == 0)
		print_env(status);
	if (strcmp(cmd[0], "setenv") == 0)
		_setenv(cmd, argv[0], status, idx);
	if (strcmp(cmd[0], "unsetenv") == 0)
		_unsetenv(cmd, status);
	if (strcmp(cmd[0], "cd") == 0)
		change_directory(cmd, argv, status, idx, new_env);
}
