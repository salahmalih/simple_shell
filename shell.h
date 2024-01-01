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

char *read_line();
char **tokenizer(char *line, char *delimiter);
char *get_command(char *cmd_line);
int _execute(char **cmd_info, char **argv, int idx);
void freearrayStr(char **arr);
char *_getenv(const char *name);
void write_error(char *name, int idx, char *cmd, char *mssg);

/*builtin*/
int is_builtin(char *command);
void handle_builtin(char **cmd, char **argv, int *status, int idx,
char **new_env);
void exit_builtin(char **command,char *name, int *status, int idx);
void print_env(int *status);
void _unsetenv(char **command, int *status);
void _setenv(char **command, char *name, int *status, int idx);
void set_wd_env(char *env_key, char *env_value, char **new_env);
void change_directory(char **command, char **argv, int *status, int idx,
char **new_env);

/* STRING */
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(const char *s);
char *_strchr(char *s, char c);
void reverse_string(char *str, int len);
int cmp_chars(char str[], const char *delim);
char *_strtok(char *str, const char *delim);
/* tool int */
int _atoi(char *str);
char *_itoa(int n);
int is_positive_number(char *str);
#endif
