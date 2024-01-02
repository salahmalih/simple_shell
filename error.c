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

