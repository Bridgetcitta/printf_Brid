#include "main.h"

/**
 * get_precise - Calculates precise
 * @format: Formatted string
 * @i: List to be printed.
 * @list: list of arguments.
 *
 * Return: precise.
 */
int get_precise(const char *format, int *i, va_list list)
{
	int current = *i + 1;
	int precise = -1;

	if (format[current] != '.')
		return (precise);

	precise = 0;

	for (current += 1; format[current] != '\0'; current++)
	{
		if (is_digit(format[current]))
		{
			precise *= 10;
			precise += format[current] - '0';
		}
		else if (format[current] == '*')
		{
			current++;
			precise = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = current - 1;

	return (precise);
}
