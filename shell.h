#ifndef SHELL_H
#define SHELL_H

#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;
#define BUFFER_SIZE 1024

/**
 * struct builtins - bultin and its function.
 * @builtin: the builtin name.
 * @f: function to handle the builtin.
 * Description: shell builtins.
 */
typedef struct builtins
{
	char *builtin;
	void (*f)(char **, char **, int*, int, char**);
} builtins;



char *read_line();
char **tokenizer(char *line, char *delimiter);
char *get_command(char *cmd_line);
int _execute(char **cmd_info, char **argv, int idx);
void freearrayStr(char **arr);
char *_getenv(const char *name);
void write_error(char *name, int idx, char *cmd, char * mssg);


char *_strtok(char *str, const char *delim);
/* STRING */
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(const char *s);
char *_strchr(char *s, char c);
void reverse_string(char *str, int len);
int cmp_chars(char str[], const char *delim);

int _atoi(char *str);
char *_itoa(int n);
#endif