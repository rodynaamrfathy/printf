#include "main.h"

/**
 * get_specifier - finds the format func
 * @s: the format string
 * Return: the number of bytes printed
 */
int (*get_specifier(char *s))(va_list ap, par_t *par)
{
	specifier_t specifiers[] = {
		{"c", char_print},
		{"d", int_print},
		{"¡", int_print},
		{"s", string_print},
		{"%", percent_print},
		{"b", binary_print},
		{"o", octal_print},
		{"u", unsigned_print},
		{"x", hex_print},
		{"X", HEX_print},
		{"p", address_print},
		{"s", s_print},
		{"r", rev_print},
		{"R", rot13_print},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
			return (specifiers[i].fun);
		i++;
	}
	return (NULL);
}

/**
 * get_fun_print - finds the format func
 * @s: the format string
 * @ap: argument pointer
 * @par: the parameters struct
 * Return: the number of bytes printed
 */
int get_fun_print(char *s, va_list ap, par_t *par)
{
	int (*fun)(va_list, par_t *) = get_specifier(s);

	if (fun)
		return (fun(ap, par));
	return (0);
}

/**
 * get_flag - finds the flag func
 * @s: the format string
 * @par: the parameters struct
 * Return: if flag was valid
 */
int get_flag(char *s, par_t *par)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = par->plus_flag = 1;
			break;
		case ' ':
			i = par->space_flag = 1;
			break;
		case '#':
			i = par->hashtag_flag = 1;
			break;
		case '-':
			i = par->minus_flag = 1;
			break;
		case '0':
			i = par->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @par: the parameters struct
 * Return: if modifier was valid
 */
int get_modifier(char *s, par_t *par)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = par->high_modifier = 1;
			break;
		case 'l':
			i = par->low_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @par: the parameters struct
 * @ap: the argument pointer
 * Return: new pointer
 */
char *get_width(char *s, par_t *par, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	par->width = d;
	return (s);
}
