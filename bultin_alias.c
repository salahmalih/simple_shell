#include "shell.h"
/**
 * _alias - Handles the creation and management of aliases.
 *
 * @command: Array of strings representing the command and its arguments.
 * @status: Pointer to an integer representing the function's execution status.
 * @head: Pointer to the head of a linked list used to store aliases.
 */
void _alias(char **command, int *status, list_t **head)
{
	char *alias_str;
	char *name, *value;

	if (!command[1])
	{
		printNodes(*head);
		(*status) = 0;
		return;
	}

	alias_str = strdup(command[1]);
	if (!alias_str)
	{
		perror("Error duplicating alias string");
		freearrayStr(command);
		(*status) = 1;
		return;
	}

	name = strtok(alias_str, "=");
	value = strtok(NULL, "=");

    if (!name || !value)
    {
		fprintf(stderr, "Invalid alias format: %s\n", command[1]);
		free(alias_str);
		freearrayStr(command);
		(*status) = 1;
		return;
	}

	if (value[0] == '\'' && value[strlen(value) - 1] == '\'')
	{
		value[strlen(value) - 1] = '\0';
		value++;
	}

	if (searchNode(*head, name))
	{
		updateNode(*head, name, value);
	}
	else
	{
		addNode(head, name, value);
	}

	free(alias_str);
	(*status) = 0;
}

