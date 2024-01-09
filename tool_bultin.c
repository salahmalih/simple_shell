#include "shell.h"

/**
 * exit_builtin - Custom implementation of the exit
 * built-in command.
 *
 * @command: An array of strings representing the
 * command and its arguments.
 * @name: The name of the program or shell.
 * @status: A pointer to the exit status variable.
 * @idx: The index of the command in the input.
 */
void exit_builtin(char **command,char *name, int *status, int idx)
{
	int exit_status = (*status);

	if (command[1])
	{
		if (!is_positive_number(command[1]))
		{
			write_error(name, idx, command[0], ": Illegal number: ");
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			freearrayStr(command);
			(*status) = 2;
			return;
		}
		else
			exit_status = _atoi(command[1]);
	}
	freearrayStr(command);
	exit(exit_status);
}
/**
 * change_directory - Change the current
 * working directory.
 * @command: Array of command and arguments.
 * @argv: Array of program arguments.
 * @status: Pointer to the exit status of the shell.
 * @idx: Index of the command in the command history.
 * @new_env: Array of environment variables to update.
 *
 * @return: No explicit return value. Updates
 * status and new_env.
 */
void change_directory(char **command, char **argv, int *status, int idx,
char **new_env)
{
	char *HOME, *OLDPWD, current_wd[1024];

	getcwd(current_wd, 1024);
	if (!command[1])
	{
		HOME = getenv("HOME");
		if (!HOME)
		{
			freearrayStr(command), (*status) = 0;
			return;
		}
		chdir(HOME), set_wd_env("PWD", HOME, new_env);
		free(HOME);
	}
	else if (strcmp(command[1], "-") == 0)
	{
		OLDPWD = _getenv("OLDPWD");
		if (!OLDPWD)
		{
			write(STDOUT_FILENO, current_wd, _strlen(current_wd));
			write(STDOUT_FILENO, "\n", 1);
			freearrayStr(command), (*status) = 0;
			return;
		}
		chdir(OLDPWD), set_wd_env("PWD", OLDPWD, new_env);
		write(STDOUT_FILENO, OLDPWD, _strlen(OLDPWD));
		write(STDOUT_FILENO, "\n", 1);
		free(OLDPWD);
	}
	else if (chdir(command[1]) == -1)
	{
		write_error(argv[0], idx, command[0], ": cd: can't cd to ");
		write(STDERR_FILENO, command[1], _strlen(command[1]));
		write(STDERR_FILENO, "\n", 1);
	}
	else
		set_wd_env("PWD", command[1], new_env);

	freearrayStr(command), (*status) = 0;
	set_wd_env("OLDPWD", current_wd, new_env);
}
