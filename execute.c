#include "shell.h"
/**
 * _execute - Executes a command given its command info and arguments.
 * @cmd_info: An array containing the command and its arguments.
 * @argv: The arguments passed to the shell.
 * @idx: The index of the command.
 *
 * Return: The exit status of the executed command.
 */
int _execute(char **cmd_info, char **argv, int idx) {
	pid_t child;
	int status = 0;
	char *cmd;

	cmd = get_command(cmd_info[0]);
	if (!cmd)
	{
		write_error(argv[0], idx, cmd_info[0], ": not found\n");
		freearrayStr(cmd_info);
		return (status);
	}

	child = fork();
	if (child == 0) {
		if (execve(cmd, cmd_info, environ) == -1)
		{
			if (errno == EACCES)
			{
				write_error(argv[0], idx, cmd_info[0], ": Permission denied\n");
            }
			free(cmd);
			cmd = NULL;
			freearrayStr(cmd_info);
			exit(status);
		}
    }
	else
	{
		waitpid(child, &status, 0);
		free(cmd);
		cmd = NULL;
		freearrayStr(cmd_info);
    }
	return (WEXITSTATUS(status));
}