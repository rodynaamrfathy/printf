#include "main.h"

/**
 * char_print - prints character
 * @ap: argument pointer
 * @par: the parameters struct
 * Return: number chars printed
 */
int char_print(va_list ap, par_t *par)
{
	char p_char = ' ';
	unsigned int p = 1, sum = 0, ch = va_arg(ap, int);

	if (par->minus_flag)
		sum += _putchar(ch);
	while (p++ < par->width)
		sum += _putchar(p_char);
	if (!par->minus_flag)
		sum += _putchar(ch);
	return (sum);
}

/**
 * int_print - prints integer
 * @ap: argument pointer
 * @par: the parameters struct
 * Return: number chars printed
 */
int int_print(va_list ap, par_t *par)
{
	long l;

	if (par->low_modifier)
		l = va_arg(ap, long);
	else if (par->high_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (number_print(convert(l, 10, 0, par), par));
}

/**
 * string_print - prints string
 * @ap: argument pointer
 * @par: the parameters struct
 * Return: number of chars printed
 */
int string_print(va_list ap, par_t *par)
{
	char *str = va_arg(ap, char *), p_char = ' ';
	unsigned int p = 0, sum = 0, i = 0, j;
	(void)par;

	switch ((int)(!str))
	{
		case 1:
			str = NULL_str;
	}
	j = p = _strlen(str);
	if (par->precision < p)
		j = p = par->precision;
	if (par->minus_flag)
	{
		if (par->precision != UINT_MAX)
			for (i = 0; i < p; i++)
				sum += _putchar(*str++);
		else
			sum += _put(str);
	}
	while (j++ < par->width)
		sum += _putchar(p_char);
	if (!par->minus_flag)
	{
		if (par->precision != UINT_MAX)
			for (i = 0; i < p; i++)
				sum += _putchar(*str++);
		else
			sum += _put(str);
	}
	return (sum);
}

/**
 * percent_print - prints percent sign
 * @ap: argument pointer
 * @par: the parameters struct
 * Return: number chars printed
 */
int percent_print(va_list ap, par_t *par)
{
	(void)ap;
	(void)par;
	return (_putchar('%'));
}

/**
 * s_print - custom format specifier
 * @ap: argument pointer
 * @par: the parameters struct
 * Return: number chars printed
 */
int s_print(va_list ap, par_t *par)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_put(NULL_str));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, par);
			if (!hex[1])
				sum += _putchar('0');
			sum += _put(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
