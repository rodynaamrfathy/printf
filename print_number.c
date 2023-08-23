#include "main.h"

/**
 * _isdigit - check if is digit
 * @c: character to check
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - find length of string
 * @str: string whose length to check
 * Return: integer length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (*str++)
		i++;
	return (i);
}

/**
 * number_print - prints a number with options
 * @str: the base number as a string
 * @par: the parameter struct
 * Return: chars printed
 */
int number_print(char *str, par_t *par)
{
	unsigned int i = _strlen(str);
	int neg = (!par->unsign && *str == '-');

	if (par->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (par->precision != UINT_MAX)
		while (i++ < par->precision)
			*--str = '0';
	if (neg)
		*--str = '-';
	if (!par->minus_flag)
		return (rightshift_number_print(str, par));
	else
		return (leftshift_number_print(str, par));
}

/**
 * rightshift_number_print - prints a number with options
 * @str: the base number as a string
 * @par: the parameter struct
 * Return: chars printed
 */
int rightshift_number_print(char *str, par_t *par)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (par->zero_flag && !par->minus_flag)
		pad_char = '0';
	neg = neg2 = (!par->unsign && *str == '-');
	if (neg && i < par->width && pad_char == '0' && !par->minus_flag)
		str++;
	else
		neg = 0;
	if ((par->plus_flag && !neg2)
			|| (!par->plus_flag && par->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (par->plus_flag && !neg2 && pad_char == '0' && !par->unsign)
		n += _putchar('+');
	else if (par->plus_flag &&
			par->space_flag && !neg2 && !par->unsign && par->zero_flag)
		n += _putchar(' ');
	while (i++ < par->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (par->plus_flag && !neg2 && pad_char == ' ' && !par->unsign)
		n += _putchar('+');
	else if (!par->plus_flag &&
			par->space_flag && !neg2 && !par->unsign && !par->zero_flag)
		n += _putchar(' ');
	n += _put(str);
	return (n);
}

/**
 * leftshift_number_print - prints a number with options
 * @str: the base number as a string
 * @par: the parameter struct
 * Return: chars printed
 */
int leftshift_number_print(char *str, par_t *par)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (par->zero_flag && !par->minus_flag)
		pad_char = '0';
	neg = neg2 = (!par->unsign && *str == '-');
	if (neg && i < par->width && pad_char == '0' && !par->minus_flag)
		str++;
	else
		neg = 0;
	if (par->plus_flag && !neg2 && !par->unsign)
		n += _putchar('+'), i++;
	else if (par->space_flag && !neg2 && !par->unsign)
		n += _putchar(' '), i++;
	n += _put(str);
	while (i++ < par->width)
		n += _putchar(pad_char);
	return (n);
}
