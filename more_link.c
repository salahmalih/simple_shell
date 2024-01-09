#include "shell.h"
/**
 * searchNode - Searches for a node with a given name in a linked list.
 * @head: A pointer to the head of the linked list.
 * @name: The name to search for in the linked list.
 *
 * Return: 1 if the name is found, 0 otherwise.
 */
int searchNode(list_t *head, char *name)
{
    list_t *current = head;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            return 1;
        }
        current = current->next;
    }

    return 0;
}
/**
 * updateNode - Updates the value of a node with a given name in a linked list.
 * @head: A pointer to the head of the linked list.
 * @name: The name to search for in the linked list.
 * @newValue: The new value to assign to the found node.
 */
void updateNode(list_t *head, char *name, char *newValue)
{
    list_t *current = head;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            free(current->value);
            current->value = strdup(newValue);
            return;
        }
        current = current->next;
    }
}
/**
 * printNodes - Prints the names and values of nodes in a linked list.
 * @head: A pointer to the head of the linked list.
 */
void printNodes(list_t *head)
{
    list_t *current = head;
    while (current != NULL)
    {
        printf("%s = %s\n", current->name, current->value);
        current = current->next;
    }
}
/**
 * freeList - Frees the memory allocated for a linked list.
 * @head: A pointer to the head of the linked list.
 */
void freeList(list_t *head)
{
    list_t *current = head;
    list_t *next;
    while (current != NULL)
    {
        next = current->next;
        free(current->name);
        free(current->value);
        free(current);
        current = next;
    }
}