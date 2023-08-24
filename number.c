#include "main.h"

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @par: parameter struct
 * Return: string
 */
char *convert(long int num, int base, int flags, par_t *par)
{
	static char *arr;
	static char buf[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)par;

	if (!(flags & CON_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	arr = flags & CON_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buf[49];
	*ptr = '\0';
	do {
		*--ptr = arr[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * unsigned_print - prints unsigned integer numbers
 * @ap: argument pointer
 * @par: parameter struct
 * Return: bytes printed
 */
int unsigned_print(va_list ap, par_t *par)
{
	unsigned long l;

	if (par->low_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (par->high_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	par->unsign = 1;
	return (number_print(convert(l, 10, CON_UNSIGNED, par), par));
}

/**
 * address_print - prints address
 * @ap: argument pointer
 * @par: parameter struct
 * Return: bytes printed
 */
int address_print(va_list ap, par_t *par)
{
	unsigned long int r = va_arg(ap, unsigned long int);
	char *str;

	if (!r)
		return (_put("(nil)"));
	str = convert(r, 16, CON_UNSIGNED | CON_LOWERCASE, par);
	*--str = 'x';
	*--str = '0';
	return (number_print(str, par));
}
