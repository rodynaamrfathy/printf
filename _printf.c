#include "main.h"

/**
* _printf - prints anything
* @format: format string
* Return: number of bytes printed
*/
int _printf(const char *format, ...)
{
int sum = 0;
va_list ap;
char *p, *start;

par_t par = PARAMS_IN;
va_start(ap, format);
if (!format || (format[0] == '%' && !format[1]))
	return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
	return (-1);
for (p = (char *)format; *p; p++)
{
	in_params(&par, ap);
	if (*p != '%')
	{
		sum += _putchar(*p);
		continue;
	}
	start = p;
	p++;
	while (get_flag(p, &par))
	{
		p++;
	}
	p = get_width(p, &par, ap);
	p = get_precision(p, &par, ap);
	if (get_modifier(p, &par))
	{
		p++;
	}
	if (!get_specifier(p))
		sum += from_to_print(start, p, par.low_modifier
		|| par.high_modifier ? p - 1 : 0);
	else
		sum += get_fun_print(p, ap, &par);
}

_putchar(BUFFER_FLUSH);
va_end(ap);
return (sum);
}
