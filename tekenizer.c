#include "shell.h"
/**
 * tokenizer - Splits a string into tokens based on a given delimiter.
 * @line: The string to be tokenized.
 * @delimiter: The delimiter used for tokenization.
 *
 * Return: An array of strings representing the tokens.
 *         NULL if @line is NULL or if memory allocation fails.
 */
char **tokenizer(char *line, char *delimiter)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int count = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);
	token = _strtok(tmp, delimiter);
	while (token)
    {
		count++;
		token = _strtok(NULL, delimiter);
	}
	free(tmp);
	tmp = NULL;
	command = malloc(sizeof(char *) * (count + 1));
	if (!command)
	{
		return (NULL);
	}
	tmp = _strdup(line);
	token = _strtok(tmp, delimiter);
	while (token)
    {
		command[i] = _strdup(token);
		token = _strtok(NULL, delimiter);
		i++;
	}
	free(tmp);
	tmp = NULL;
	command[i] = NULL;
	return (command);
}
/**
 * get_command - Retrieves the full path of a command based on the PATH variable.
 * @cmd_line: The command line input containing the command name.
 *
 * Return: The full path of the command if found, NULL otherwise.
 */
char *get_command(char *cmd_line)
{
	char *full_cmd;
	char *path = NULL;
	char *tokens;
	struct stat st;
	int i = 0;

	for (i = 0; cmd_line[i]; i++)
	{
		if (cmd_line[i] == '/')
		{
			if (stat(cmd_line, &st) == 0)
			{
				return (_strdup(cmd_line));
			}
			else
				return (NULL);
		}
	}
	path = _strdup(_getenv("PATH"));
	if (!path)
		return (NULL);
	tokens = _strtok(path, ":");
	while (tokens)
	{
		full_cmd = malloc((_strlen(tokens) + _strlen(cmd_line) + 2) * sizeof(char *));
		if (full_cmd)
        {
			_strcpy(full_cmd, tokens);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, cmd_line);
			if (stat(full_cmd, &st) == 0)
			{
				free(path);
				return (full_cmd);
			}
			free(full_cmd);
			tokens = _strtok(NULL, ":");
        }
	}
	free(path);
	return (NULL);
}
