#ifndef _PRINTF_PROJECT
#define _PRINTF_PROJECT

#include <stdarg.h>
#include <stddef.h>

#define BUF_SIZE 1024
#define PLUS_FLAG 1
#define SPACE_FLAG 2
#define HASH_FLAG 4

int _printf(const char *format, ...);
int _putchar(char c);
int print_str(char *str);
int print_number(int n, int flags);
int print_binary(unsigned long int n);
int print_unsi(int output_fd, unsigned int n, int base);
int print_hex(int output_fd, unsigned int n, int uppercase, int flags);
int format_handler(char format, va_list args);
int write_buffer(char *buffer, int len);
int print_unsi2(unsigned int n, int base);
int print_S(char *str);
int print_pointer(void *ptr);
void write_buffer2(int output_fd, char *buffer, int buffer_size);
void fill_buffer(unsigned int n, int uppercase, char *buffer, int *buffer_index);
int print_hex3(int output_fd, unsigned int n, int uppercase);
int get_flags(char *format);
int print_hex_other(int output_fd, unsigned int n, int uppercase);

#endif
