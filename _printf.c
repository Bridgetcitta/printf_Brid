#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Prints like printf
 * @format: format string
 * Return: succes
 */
int _printf(const char *format, ...)
{
	int i, print = 0, success = 0;
	int flags, width, precise, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			success++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precise = get_precise(format, &i, list);
			size = get_size(format, &i);
			++i;
			print = handle_print(format, &i, list, buffer,
				flags, width, precise, size);
			if (print == -1)
				return (-1);
			success += print;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (success);
}

/**
 * print_buffer - Prints out contents of the buffer
 * @buffer: Array of chars used
 * @buff_ind: Index at which to add next char.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
