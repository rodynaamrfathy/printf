#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

#define OUT_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1
#define NULL_str "(null)"
#define PARAMS_IN {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CON_LOWERCASE 1
#define CONVERT_LOWERCASE 1
#define con_uppercase 2
#define CON_UNSIGNED 2
#define CONVERT_UNSIGNED 2


/**
 * struct parameter - Holds the format flags and
 * modifiers for a conversion specifier
 * @unsign: if the argument is unsigned
 * @plus_flag: if the '+' flag is specified
 * @space_flag: if the ' ' flag is specified
 * @hashtag_flag: if the '#' flag is specified
 * @zero_flag: if the '0' flag is specified
 * @minus_flag: if the '-' flag is specified
 * @width: the field width specified
 * @precision: the field precision specified
 * @high_modifier: if the 'l' or 'L' length modifier is specified
 * @low_modifier: if the 'h' length modifier is specified
 */
typedef struct parameter
{
		unsigned int unsign		: 1;
		unsigned int plus_flag		: 1;
		unsigned int space_flag		: 1;
		unsigned int hashtag_flag	: 1;
		unsigned int zero_flag		: 1;
		unsigned int minus_flag		: 1;
		unsigned int width;
		unsigned int precision;
		unsigned int high_modifier	: 1;
		unsigned int low_modifier	: 1;
} par_t;

/**
 * struct specifier - Holds the conversion specifier
 * and its associated function
 * @specifier: the format token
 * @fun: the function associated with the specifier
 */
typedef struct specifier
{
		char *specifier;
		int (*fun)(va_list, par_t *);
} specifier_t;

int _put(char *s);
int _putchar(int c);
int char_print(va_list ap, par_t *par);
int int_print(va_list ap, par_t *par);
int string_print(va_list ap, par_t *par);
int percent_print(va_list ap, par_t *par);
int s_print(va_list ap, par_t *par);
char *convert(long int num, int base, int flags, par_t *par);
int unsigned_print(va_list ap, par_t *par);
int address_print(va_list ap, par_t *par);
int hex_print(va_list ap, par_t *par);
int binary_print(va_list ap, par_t *par);
int octal_print(va_list ap, par_t *par);
int HEX_print(va_list ap, par_t *par);
int rev_print(va_list ap, par_t *par);
int rot13_print(va_list ap, par_t *par);
int (*get_specifier(char *s))(va_list ap, par_t *par);
int get_fun_print(char *s, va_list ap, par_t *par);
int get_flag(char *s, par_t *par);
int get_modifier(char *s, par_t *par);
char *get_width(char *s, par_t *par, va_list ap);
int from_to_print(char *start, char *end, char *except);
int _isdigit(int c);
int _strlen(char *str);
int number_print(char *str, par_t *par);
int rightshift_number_print(char *str, par_t *par);
int leftshift_number_print(char *str, par_t *par);
void in_params(par_t *par, va_list ap);
char *get_precision(char *p, par_t *par, va_list ap);
int _printf(const char *format, ...);

#endif
