#include "shell.h"
/**
 * main - Entry point for the shell program.
 * @ac: The number of arguments passed to the program.
 * @argv: An array of strings containing the arguments.
 *
 * Return: The exit status of the shell program.
 */
int main(int ac, char **argv)
{

	list_t *aliasList = NULL;
	char *line, *new_env = NULL;
	int status = 0, index = 0;
	char **tokens;
	char *aliasValue;
	char **aliasTokens;

	(void)ac;
	(void)argv;
	while (1)
	{
		line = read_line();
		if (!line)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			free(new_env);
			return (status);
		}
		index++;
		tokens = tokenizer(line, " \n\t");
		if (tokens != NULL && tokens[0] != NULL && is_builtin(tokens[0]))
		{
			handle_builtin(tokens, argv, &status, index, &new_env, &aliasList);
		}
		else if (searchNode(aliasList, tokens[0]))
        {
            aliasValue = getValueOfNode(aliasList, tokens[0]);
            aliasTokens = tokenizer(aliasValue, " \n\t");
            status = _execute(aliasTokens, argv, index);
        }
		else
		{
			status = _execute(tokens, argv, index);
		}
		free(line);
	}
	freearrayStr(aliasTokens);
	return (status);
}
