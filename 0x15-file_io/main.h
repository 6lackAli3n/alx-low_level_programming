#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void print_error_and_exit(int error_code, const char *message, const char *arg);

#endif /* MAIN_H */
