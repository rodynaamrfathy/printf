#include "main.h"

/**
 * hex_print - prints unsigned hex numbers in lowercase
 * @ap: the argument pointer
 * @par: the parameters struct
 * Return: bytes printed
 */
int hex_print(va_list ap, par_t *par)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (par->low_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (par->high_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CON_LOWERCASE, par);
	if (par->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	par->unsign = 1;
	return (c += number_print(str, par));
}

/**
 * HEX_print - prints unsigned hex numbers in lowercase
 * @ap: the argument pointer
 * @par: the parameters struct
 * Return: bytes printed
 */
int HEX_print(va_list ap, par_t *par)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (par->low_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (par->high_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, par);
	if (par->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	par->unsign = 1;
	return (c += number_print(str, par));
}

/**
 * binary_print - prints unsigned binary number
 * @ap: the argument pointer
 * @par: the parameters struct
 * Return: bytes printed
 */
int binary_print(va_list ap, par_t *par)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, par);
	int c = 0;

	if (par->hashtag_flag && n)
		*--str = '0';
	par->unsign = 1;
	return (c += number_print(str, par));
}

/**
 * octal_print - prints unsigned octal numbers
 * @ap: the argument pointer
 * @par: the parameters struct
 * Return: bytes printed
 */
int octal_print(va_list ap, par_t *par)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (par->low_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (par->high_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = convert(l, 8, CON_UNSIGNED, par);

	if (par->hashtag_flag && l)
		*--str = '0';
	par->unsign = 1;
	return (c += number_print(str, par));
}
