#define BUFFER_SIZE 1024
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

static char buffer[BUFFER_SIZE];
/**
 * print_unsi - prints unsgined int in a particular base
 * @n: unsigned int to print
 * @base: base to print in
 * @output_fd: the output descriptor
 *
 * Return: the number of characters printed
 */
int print_unsi(int output_fd, unsigned int n, int base)
{
	int i;
	int *array;
	int count = 0;
	unsigned int temp = n;
	int buffer_index = 0;

	while (n / base != 0)
	{
		n /= base;
		count++;
	}
	count++;
	array = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		array[i] = temp % base;
		temp /= base;
	}

	for (i = count - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			buffer[buffer_index] = (array[i] + 87);
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
 * print_hex - prints an unsigned int in hex
 * @n: number to print in hex
 * @uppercase: boolean to determine if to use uppercase
 * @output_fd: the output descriptor
 *
 * Return: the number of characters printed
 */
int print_hex(int output_fd, unsigned int n, int uppercase)
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
int print_number(int n, int flags)
{
	unsigned long int num;
	int len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		num = -n;
	}
	else
		num = n;

	if ((flags & PLUS_FLAG) && n >= 0)
	{
		len += _putchar('+');
		flags &= ~PLUS_FLAG;
	}
	else if ((flags & SPACE_FLAG) && n >= 0)
	{
		len += _putchar(' ');
		flags &= ~SPACE_FLAG;
	}
	
	if (num / 10 != 0)
	{
		len += print_number(num / 10, flags);
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

int print_binary(unsigned long int n)
{
	int len = 0;
	unsigned long int mask = 1;

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
