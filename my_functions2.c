#include "main.h"
#include <stdio.h>
/**
 * print_S - prints a string with non printable char
 * @str: string to print
 *
 * Return: number of chars
 */
int print_S(char *str)
{
	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (*str != '\0')
	{
		if ((*str < 32) || (*str >= 127))
		{
			len += _putchar('\\');
			len += _putchar('x');
			len += print_hex2(*str, 1, 2);
		}
		else
		{
			len += _putchar(*str);
		}
		str++;
	}
	return (len);
}

/**
 * print_hex2 - prints number in hex format
 * @num: number to print
 * @uppercase: whether to print upper or not
 * @width: min width of output
 *
 * Return: number of characters
 */
int print_hex2(unsigned int num, int uppercase, int width)
{
	char hex[] = "0123456789abcdef";
	int len = 0;
	int upper;

	if (num / 16)
	{
		len += print_hex2(num / 16, uppercase, width - 1);
	}
	else
	{
		while (width - 1 > 0)
		{
			len += _putchar('0');
			width--;
		}
	}
	upper = uppercase && hex[num % 16] >= 'a' && hex[num % 16] <= 'f';
	len += _putchar(hex[num % 16] + (upper * ('A' - 'a'));
	return (len);
}
