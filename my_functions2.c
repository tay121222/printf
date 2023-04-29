#define BUFFER_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <unistd.h>

static char buffer[BUFFER_SIZE];

/**
 * print_unsi2 - prints unsgined int in a particular base
 * @n: unsigned int to print
 * @base: base to print in
 *
 * Return: the number of characters printed
 */
int print_unsi2(unsigned int n, int base)
{
	int num, last = n % base, digit, exp = 1;
	int i = 1;

	n = n / base;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}

	if (num > 0)
	{
		while (num / base != 0)
		{
			exp = exp * base;
			num = num / base;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			if (digit > 9)
				_putchar(digit + 87);
			else
				_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / base;
			i++;
		}
	}
	if (last > 9)
		_putchar(last + 87);
	else
		_putchar(last + '0');

	return (i);
}

/**
 * print_S - prints string with non-printable char
 * @str: the string to print
 *
 * Return: the number of characters printed
 */
int print_S(char *str)
{
	int count = 0;
	int i;
	int output_fd = 1;
	int cast;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 32 && str[i] < 127)
		{
			_putchar(str[i]);
			count++;
		}
		else
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			cast = str[i];
			if (cast < 16)
			{
				_putchar('0');
				count++;
			}
			count += print_hex_other(output_fd, (unsigned int)str[i], 1);
		}
	}

	return (count);
}

/**
 * print_hex_other - prints an unsigned int in hex
 * @n: number to print in hex
 * @uppercase: boolean to determine if to use uppercase
 * @output_fd: the output descriptor
 *
 * Return: the number of characters printed
 */
int print_hex_other(int output_fd, unsigned int n, int uppercase)
{
	int i;
	int *array;
	int count = 0;
	unsigned int temp = n;
	int buffer_index = 0;

	while (n / 16 != 0)
	{
		n /= 16;
		count++;
	}
	count++;
	array = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}

	for (i = count - 1; i >= 0; i--)
	{
		if (array[i] > 9)
		{
			if (uppercase)
				buffer[buffer_index] = (array[i] + 55);
			else
				buffer[buffer_index] = (array[i] + 87);
		}
		else
			buffer[buffer_index] = (array[i] + '0');

		buffer_index++;

		if (buffer_index == 1024)
		{
			write(output_fd, buffer, 1024);
			buffer_index = 0;
		}
	}

	if (buffer_index != 0)
		write(output_fd, buffer, buffer_index);

	free(array);
	return (count);
}


/**
 * print_pointer - prints a void pointer in hex
 * @ptr: pointer to print
 *
 * Return: the number of characters printed
 */
int print_pointer(void *ptr)
{
	unsigned long int n = (unsigned long int)ptr;
	char hex_digits[] = "0123456789abcdef";
	int count = 0;

	if (ptr == NULL)
	{
		count += _putchar('(');
		count += _putchar('n');
		count += _putchar('i');
		count += _putchar('l');
		count += _putchar(')');
		return (count);
	}

	_putchar('0');
	_putchar('x');
	if (n == 0)
	{
		_putchar('0');
		count += 3;
	}
	else
	{
		char buffer[16];
		int i = 0, j;

		while (n != 0)
		{
			int gee = n % 16;

			buffer[i] = hex_digits[gee];
			n /= 16;
			i++;
		}
		count += i + 2;
		for (j = i - 1; j >= 0; j--)
		{
			_putchar(buffer[j]);
		}
	}
	return (count);
}

/**
 * get_flags - get flag value for specifier
 *
 * Return: resturn flag value for specifier
 */
int get_flags(char *format)
{
	int flags = 0;

	/**
	 * format[1] = '\0';
	 * printf("format: %s\n", format);
	 */

	while (*format == '+' || *format == ' ' || *format == '#')
	{
		if (*format == '+')
			flags |= PLUS_FLAG;
		else if (*format == ' ')
			flags |= SPACE_FLAG;
		else if (*format == '#')
			flags |= HASH_FLAG;

		format++;
	}

	return (flags);
}
