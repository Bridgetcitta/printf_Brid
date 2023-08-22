#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments
 * @format_index: Index of the current character in the format string
 * @args_list: List of arguments
 *
 * Return: Width
 */
int get_width(const char *format, int *format_index, va_list args_list)
{
	int curr_index;
	int width = 0;

	for (curr_index = *format_index + 1; format[curr_index] != '\0'; curr_index++)
	{
		if (is_digit(format[curr_index]))
		{
			width *= 10;
			width += format[curr_index] - '0';
		}
		else if (format[curr_index] == '*')
		{
			curr_index++;
			width = va_arg(args_list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*format_index = curr_index - 1;

	return (width);
}
