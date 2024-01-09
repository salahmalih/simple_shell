#include "shell.h"
/**
 * createNode - Creates a new node for a linked list.
 * @name: The name to be stored in the new node.
 * @value: The value to be stored in the new node.
 *
 * Return: A pointer to the newly created node.
 */
list_t *createNode(char *name, char *value)
{
    list_t *newNode = (list_t *)malloc(sizeof(list_t));
    if (newNode == NULL)
    {
        perror("Failed to allocate memory for the new node");
        exit(EXIT_FAILURE);
    }

    newNode->name = strdup(name);
    newNode->value = strdup(value);
    newNode->next = NULL;

    return newNode;
}

/**
 * addNode - Adds a new node to the beginning of a linked list.
 * @head: A pointer to the head of the linked list.
 * @name: The name to be stored in the new node.
 * @value: The value to be stored in the new node.
 */
void addNode(list_t **head, char *name, char *value)
{
    list_t *newNode = createNode(name, value);
    newNode->next = *head;
    *head = newNode;
}
/**
 * getValueOfNode - Retrieves the value associated with a given name in a linked list.
 * @head: A pointer to the head of the linked list.
 * @name: The name to search for in the linked list.
 *
 * Return: The value associated with the given name, or NULL if the name is not found.
 */
char *getValueOfNode(list_t *head, char *name)
{
    list_t *current = head;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            return current->value;
        }
        current = current->next;
    }

    return NULL;
}
