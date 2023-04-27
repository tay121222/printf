#define BUFFER_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <unistd.h>

/**
 * write_buffer2 - writes the buffer to the output file descriptor
 * @output_fd: the output file descriptor
 * @buffer: the buffer to write
 * @buffer_size: the size of the buffer
 */
void write_buffer2(int output_fd, char *buffer, int buffer_size)
{
	write(output_fd, buffer, buffer_size);
}

/**
 * fill_buffer - fills the buffer with the hexadecimal representation of n
 * @n: the number to convert to hexadecimal
 * @uppercase: a flag indicating whether to use uppercase letters
 * @buffer: the buffer to fill
 * @buffer_index: a pointer to the current index of the buffer
 */
void fill_buffer(unsigned int n, int uppercase, char *buffer, int *buffer_index)
{
	int i;
	int *array;
	unsigned int temp = n;
	int count = 1;

	while (temp >= 16)
	{
		temp /= 16;
		count++;
	}

	array = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		if (array[i] > 9)
		{
			if (uppercase)
				buffer[*buffer_index] = (array[i] + 55);
			else
				buffer[*buffer_index] = (array[i] + 87);
		}
		else
			buffer[*buffer_index] = (array[i] + '0');

		(*buffer_index)++;

		if (*buffer_index == 1024)
		{
			write_buffer2(STDOUT_FILENO, buffer, 1024);
			*buffer_index = 0;
		}
	}
	free(array);
}

/**
 * print_hex3 - prints an unsigned int in hex
 * @n: number to print in hex
 * @uppercase: boolean to determine if to use uppercase
 * @output_fd: the output descriptor
 *
 * Return: the number of characters printed
 */
int print_hex3(int output_fd, unsigned int n, int uppercase)
{
	int buffer_index = 0;
	char buffer[1024];

	fill_buffer(n, uppercase, buffer, &buffer_index);

	if (buffer_index != 0)
	{
		write_buffer2(output_fd, buffer, buffer_index);
	}

	return (buffer_index);
}
