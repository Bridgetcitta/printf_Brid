#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @for_mat: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precise: precise specification
 * @size: Size specifier
 *
 * Return: 1 or 2;
 */
int handle_print(const char *for_mat, int *ind, va_list list, char buffer[],
	int flags, int width, int precise, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	for_mat_t for_mat_line[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; for_mat_line[i].for_mat != '\0'; i++)
		if (for_mat[*ind] == for_mat_line[i].for_mat)
			return (for_mat_line[i].fn(list, buffer, flags, width, precise, size));

	if (for_mat_line[i].for_mat == '\0')
	{
		if (for_mat[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (for_mat[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (for_mat[*ind] != ' ' && for_mat[*ind] != '%')
				--(*ind);
			if (for_mat[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &for_mat[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
