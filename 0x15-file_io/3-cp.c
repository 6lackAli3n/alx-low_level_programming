#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

void print_error_and_exit(int error_code, const char *message, const char *arg) {
	dprintf(STDERR_FILENO, message, arg);
	exit(error_code);
}

int main(int argc, char *argv[]) {
	int file_from, file_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUF_SIZE];

	if (argc != 3) {
		print_error_and_exit(97, "Usage: cp file_from file_to\n", NULL);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1) {
		print_error_and_exit(98, "Error: Can't read from file %s\n", argv[1]);
	}

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (file_to == -1) {
		print_error_and_exit(99, "Error: Can't write to %s\n", argv[2]);
	}

	do {
		bytes_read = read(file_from, buffer, BUF_SIZE);
		if (bytes_read == -1) {
			print_error_and_exit(98, "Error: Can't read from file %s\n", argv[1]);
		}

		bytes_written = write(file_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read) {
			print_error_and_exit(99, "Error: Can't write to %s\n", argv[2]);
		}
	} while (bytes_read > 0);

	if (close(file_from) == -1) {
		print_error_and_exit(100, "Error: Can't close fd %d\n", file_from);
	}

	if (close(file_to) == -1) {
		print_error_and_exit(100, "Error: Can't close fd %d\n", file_to);
	}

	return (0);
}
