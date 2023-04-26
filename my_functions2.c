#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_digit - prints a single digit
 * @digit: digit to print
 * @is_hex: indeicate if base is hex
 */
void print_digit(int digit, int is_hex)
{
	if (digit > 9 && is_hex)
		_putchar(digit + 87);
	else
		_putchar(digit + '0');
}

/**
 * print_num_rec - recursively prints a number in a particular base
 * @num: number to print
 * @base: base to print in
 * @exp: exponent used to determine the left-most digit
 * @is_hex: flag indicating if base is hexadecimal
 * @i: pointer to the counter of digits printed
 */
void print_num_rec(int num, int base, int exp, int is_hex, int *i)
{
	if (exp > 0)
	{
		int digit = num / exp;

		print_digit(digit, is_hex);
		num -= digit * exp;
		exp /= base;
		(*i)++;
		print_num_rec(num, base, exp, is_hex, i);
	}
	else
	{
		print_digit(num, is_hex);
		(*i)++;
	}
}

/**
 * print_unsigned_number - prints unsigned integer in a particular base
 * @n: unsigned integer to print
 * @base: base to print in
 *
 * Return: the number of characters printed
 */
int print_unsigned_number(unsigned int n, int base)
{
	int num = n, last = n % base, exp = 1;
	int i = 0, is_hex = (base == 16);

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		last = -last;
		i++;
	}

	if (num > 0)
	{
		while (num / base != 0)
		{
			exp *= base;
			num /= base;
		}
		print_num_rec(n, base, exp, is_hex, &i);
	}
	else
	{
		_putchar('0');
		i++;
	}

	print_digit(last, is_hex);
	i++;

	return (i);
}
/**
 * print_unsi2 - prints unsgined int in a particular base
 * @n: unsigned int to print
 * @base: base to print in
 *
 * Return: the number of characters printed
 */
int print_unsi2(unsigned int n, int base)
{
	return (print_unsigned_number(n, base));
}
