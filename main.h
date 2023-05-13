#ifndef MAIN_H
#define MAIN_H
#define BUF_SIZE 1024
#define UNUSED(x) (void)(x)

unsigned int _strlen(char *str);
void write_string(int fd, const char *str);
void handle_error(const char *error_msg, const char *program_name);
#endif
