ifndef _PRINTF_H
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
#define CON_LOWERCASE   1
#define con_uppercase   2

/**
 * struct parameter - parameter struct
 * @unsign: if unsigned value
 * @plus_flag: if plus_flag specified
 * @space_flag: if hashtag_flag specified
 * @hashtag_flag: if _flag specified
 * @zero_flag: if _flag specified
 * @minus_flag: if _flag specified
 * @width: field width specified
 * @precision: field precision specified
 * @high_modifier: if high_modifier specified
 * @low_modifier: if low_modifier specified
 */
typedef struct parameter
{
        unsigned int unsign             : 1;
        unsigned int plus_flag          : 1;
        unsigned int space_flag         : 1;
        unsigned int hashtag_flag       : 1;
        unsigned int zero_flag          : 1;
        unsigned int minus_flag         : 1;
        unsigned int width;
        unsigned int precision;
        unsigned int high_modifier      : 1;
        unsigned int low_modifier       : 1;
} par_t;
/**
 * struct specifier - struct token
 * @specifier: format token
 * @fun: function associated
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
int S_print(va_list ap, par_t *par);
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
