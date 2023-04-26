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
int print_unsi(unsigned int n, int base);
int print_hex(unsigned int n, int uppercase);
int format_handler(char format, va_list args);
int write_buffer(char *buffer, int len);
void reverse_string(char *str);
size_t my_strlen(const char *s);
int print_S(char *str);
int print_hex2(unsigned int num, int uppercase, int width);

#endif
