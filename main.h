#ifndef MAIN_H
#define MAIN_H

extern char **environ;

/**
  * struct cmdMap - Built-in command structure
  * @command: built-in command
  * @function: function pointer
  *
  * Description: The structure containing function pointers to the commands
  */
typedef struct cmdMap
{
	const char *command;
	int (*function)(char **);
} CommandMapping;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <limits.h>

int _putchar(char c);
int _execve(char **args);
int _execvecmd(char **args);
char **token_lineptr(char *lineptr);
void command_prompt(void);
int _strlen(const char *str);
void path_token(char *command);
int _found(char *file_path, char *command, char **args, int found);
int exec_with_path(char *command, char **args);
int exec_path(char *command, char **args); /* for testing purposes */

void built_in_exit(void);
int built_in_env(char **args);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _snprint(char *file_path, size_t buffer_size, char *token, char *command);
int _fprintf(FILE *stream, const char *format, ...);
void handle_int(FILE *stream, int num);
void handle_str(FILE *stream, const char *str);
int _path_err(char *path);
int _file_path_err(char *file_path);
int _malloc_args_err(char **args);
int _shell_in_shell(char **args);

ssize_t _getline(char **lineptr, size_t *len, FILE *stream);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int new_size, unsigned int old_size);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _process_char(char **lineptr, size_t *n, size_t *current_len, char ch);
int _strcmp(const char *s1, const char *s2);
char *_strtok(char *str, const char *delimiters);
int exit_builtin(char **args);
int _atoi(const char *nptr);
char *_strchr(const char *str, int c);
char *_strdup(const char *str);
int _setenv(const char *name, const char *value, int overwrite);
char *_sprintf(const char *name, const char *value);
int built_in_setenv(char **args);
int _unsetenv(char *name);
int built_in_unsetenv(char **args);
void tokenStart_null(char **lastToken);
int built_in_cd(char **args);
int new_pwd(void);
void cd_dash(void);
int err_getenv(char *var);
char *_getenv(const char *name);
int executer(char *file_path, char **args, char **env, int status);
char **_token_lineptr(char *lineptr);
int exec_pipe(char **args1, char **args2);

#endif /* MAIN_H */
