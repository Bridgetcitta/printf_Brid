#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: pointer
 * Return: printed chars.
 */
int _printf(const char *format, ...)
{
	int result = 0;
	char *str, c;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			result++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				result++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char*);
				while (*str != '\0')
				write(1, str, 1);
				result++;
			}
			else if (*format == '%')
			{
				write(1, "% ", 1);
				result++;
			}
		}
		format++;
	}
	va_end(args);
	return (result);
}
