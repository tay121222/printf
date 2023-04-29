#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - function that produces output according to a format
 * @format: string containing directives
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, len = 0;
	int flags = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			flags = get_flags(format, &i);
			len += format_handler(format[i], args, flags);
		}
		else
			len += _putchar(format[i]);

		i++;
	}

	va_end(args);

	return (len);
}

/**
 * format_handler - handles format directives
 * @format: the format character
 * @args: the va_list arguments
 * @flags: which flag to use for associated specifier
 *
 * Return: number of characters printed
 */
int format_handler(char format, va_list args, int flags)
{
	int len = 0;
	int output_fd = 1;

	/*printf("format: %c, flags: %d\n", format, flags);*/

	if (format == 'c')
		len += _putchar(va_arg(args, int));
	else if (format == 's')
		len += print_str(va_arg(args, char *));
	else if (format == '%')
		len += _putchar('%');
	else if (format == 'd' || format == 'i')
		len += print_number(va_arg(args, int), flags);
	else if (format == 'b')
		len += print_binary(va_arg(args, unsigned long int));
	else if (format == 'u')
		len += print_unsi2(va_arg(args, unsigned int), 10);
	else if (format == 'o')
		len += print_unsi(output_fd, va_arg(args, unsigned int), 8);
	else if (format == 'x')
		len += print_hex(output_fd, va_arg(args, unsigned int), 0, flags);
	else if (format == 'X')
		len += print_hex(output_fd, va_arg(args, unsigned int), 1, flags);
	else if (format == 'S')
		len += print_S(va_arg(args, char *));
	else if (format == 'p')
		len += print_pointer(va_arg(args, void *));
	else
		len += _putchar('%'), len += _putchar(format);

	return (len);
}
