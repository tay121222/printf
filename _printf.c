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
			else if (format[i] == 'd' || format[i] == 'i')
				len += print_number(va_arg(args, int));
			else if (format[i] == 'b')
				len += print_binary(va_arg(args, unsigned int));
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

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: the number of characters printed
 */
int print_number(int n)
{
	unsigned int num;
	int len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		num = -n;
	}
	else
		num = n;

	if (num / 10 != 0)
	{
		len += print_number(num / 10);
	}

	len += _putchar('0' + num % 10);

	return (len);
}

/**
 * print_binary - prints unsigned int to binary
 * @n: unsigned int to convert to binary
 *
 * Return: the number of characters printed
 */
int print_binary(unsigned int n)
{
	int len = 0;
	unsigned int mask = 1;

	while (mask <= n / 2)
		mask *= 2;

	while (mask > 0)
	{
		if (n & mask)
			len += _putchar('1');
		else
			len += _putchar('0');
		mask /= 2;
	}

	return (len);
}
