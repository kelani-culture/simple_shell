#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#define BUF_SIZE 1024
#define UNUSED(x) (void)(x)

extern char **environ;
char *_getenv(const char *name);
void run_shell(const char *program_name);
void execute_command(char *command);
int _strcmp(const char *s1, const char *s2);
void exit_shell(int status);
int find_command(const char *command, char *full_path, size_t path_size);
char *_strncpy(char *dest, const char *src, size_t n);
int command_args(char *command, char *args[], int max_args);
size_t _strlen(const char *str);
ssize_t _getline(char **line, size_t *n, FILE *stream);
void write_string(int fd, const char *str);
void handle_error(const char *error_msg);
char *custom_realloc(char *ptr, size_t size);
void process_command(const char *program_name, char *command);
int exit_status(const char *status_str);
char *_strtok(char *str, const char *delim);
char *_strncat(char *dest, const char *src, size_t n);
char *_strchr(const char *str, int c);
int _strncmp(const char *str1, const char *str2, size_t n);
void shell_unsetenv(const char *variable);
void shell_setenv(const char *variable, const char *value);
int is_builtin_command(const char *command);
void shell_cd(const char *program_name, char *command);
#endif
