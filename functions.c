#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @line: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precise: precise specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list line, char buffer[],
	int flags, int width, int precise, int size)
{
	char c = va_arg(line, int);

	return (handle_write_char(c, buffer, flags, width, precise, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @line: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precise: precise specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list line, char buffer[],
	int flags, int width, int precise, int size)
{
	int length = 0, i;
	char *str = va_arg(line, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precise);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precise >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precise >= 0 && precise < length)
		length = precise;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @line: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precise: precise specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list line, char buffer[],
	int flags, int width, int precise, int size)
{
	UNUSED(line);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precise);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @line: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precise: precise specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list line, char buffer[],
	int flags, int width, int precise, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(line, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precise, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @line: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precise: precise specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list line, char buffer[],
	int flags, int width, int precise, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precise);
	UNUSED(size);

	n = va_arg(line, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
