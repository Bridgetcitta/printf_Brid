#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024


#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16


#define S_LONG 2
#define S_SHORT 1

/**
 * struct for_mat - Struct operations
 *
 * @for_mat: The format used 
 * @fn: The function associated with it
 */
struct for_mat
{
	char for_mat;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct for_mat for_mat_t - Struct op
 *
 * @for_mat: The format.
 * @fm_t: The function associated.
 */
typedef struct for_mat for_mat_t;

int _printf(const char *format, ...);
int handle_print(const char *for_mat, int *i,
va_list list, char buffer[], int flags, int width, int precise, int size);



int print_char(va_list line, char buffer[],
	int flags, int width, int precise, int size);
int print_str(va_list line, char buffer[],
	int flags, int width, int precise, int size);
int print_percent(va_list line, char buffer[],
	int flags, int width, int precise, int size);

int print_int(va_list line, char buffer[],
	int flags, int width, int precise, int size);
int print_binary(va_list line, char buffer[],
	int flags, int width, int precise, int size);
int print_unsigned(va_list line, char buffer[],
	int flags, int width, int precise, int size);
int print_octal(va_list line, char buffer[],
	int flags, int width, int precise, int size);
int print_hexadecimal(va_list line, char buffer[],
	int flags, int width, int precise, int size);
int print_hexa_upper(va_list line, char buffer[],
	int flags, int width, int precise, int size);

int print_hexa(va_list line, char go_to[],
char buffer[], int flags, char flag_ch, int width, int precise, int size);

int print_non_printable(va_list line, char buffer[],
	int flags, int width, int precise, int size);

int print_rot13str(va_list line, char buffer[],
	int flags, int width, int precise, int size);


int print_pointer(va_list line, char buffer[],
	int flags, int width, int precise, int size);


int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precise(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

int control_write_char(char c, char buffer[],
	int flags, int width, int precise, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precise, int size);
int write_num(int ind, char bff[], int flags, int width, int precise,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int pt_rev(va_list line, char buffer[],
	int flags, int width, int precise, int size);

int write_unsgnd(int is_not, int ind,
char buffer[],
	int flags, int width, int precise, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
