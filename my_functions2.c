#include <stdio.h>
#include <stdlib.h>
#include "main.h"
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
			count += print_hex(output_fd, (unsigned int)str[i], 1);
		}
	}

	return (count);
}
