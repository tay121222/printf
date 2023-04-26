#include "main.h"
#include <stdio.h>
#include <stdlib.h>
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
		while (num /base != 0)
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
