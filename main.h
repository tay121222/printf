#ifndef _PRINTF_PROJECT
#define _PRINTF_PROJECT

#include <stdarg.h>
#include <stddef.h>

#define BUF_SIZE 1024

int _printf(const char *format, ...);
int _putchar(char c);
int print_str(char *str);
int print_number(int n);
int print_binary(unsigned long int n);
int print_unsi(int output_fd, unsigned int n, int base);
int print_hex(int output_fd, unsigned int n, int uppercase);
int format_handler(char format, va_list args);
int write_buffer(char *buffer, int len);
int print_unsi2(unsigned int n, int base);
int print_S(char *str);
int print_pointer(void *ptr);
int printf_pointer(void *p);

#endif
