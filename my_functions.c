#include "main.h"
#include <stdio.h>
/**
 * print_unsi - prints unsgined int in a particular base
 * @n: unsigned int to print
 * @base: base to print in
 *
 * Return: the number of characters printed
 */
int print_unsi(unsigned long int n, int base)
{
	int len = 0;
	char *digits = "0123456789";
	char buffer[1024];
	int i = 0;

	if (n == 0)
		return (_putchar('0'));

	while (n != 0)
	{
		buffer[i] = digits[n % base];
		n /= base;
		i++;
	}

	while (i > 0)
	{
		i--;
		len += _putchar(buffer[i]);
	}

	return (len);
}

/**
 * print_hex - prints an unsigned int in hex
 * @n: number to print in hex
 * @uppercase: boolean to determine if to use uppercase
 *
 * Return: the number of characters printed
 */
int print_hex(unsigned long int n, int uppercase)
{
	const char *hex_digits = "0123456789abcdef";
	int len = 0;
	unsigned long int mask = 0xF0000000;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";

	while (mask > 0)
	{
		int hex_digit = (n & mask) >> (4 * (8 - len - 1));

		_putchar(hex_digits[hex_digit]);
		mask >>= 4;
		len++;
	}

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
	int num;
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
