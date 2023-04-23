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

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				len += _putchar(va_arg(args, int));
			else if (format[i] == 's')
				len += print_str(va_arg(args, char *));
			else if (format[i] == '%')
				len += _putchar('%');
			else
				len += _putchar('%'), len += _putchar(format[i]);
		}
		else
			len += _putchar(format[i]);

		i++;
	}

	va_end(args);

	return (len);
}

/**
 * print_str - prints string
 * @str: string to print
 *
 * Return: the number of characters printed
 */
int print_str(char *str)
{
	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		_putchar(*str);
		str++;
		len++;
	}

	return (len);
}
