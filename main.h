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
void exit_shell(void);
int find_command(char *command, char *full_path, int buffer_size);
char *_strncpy(char *dest, const char *src, size_t n);
int command_args(char *command, char *args[], int max_args);
size_t _strlen(const char *str);
void write_string(int fd, const char *str);
void handle_error(const char *error_msg, const char *program_name);
#endif
