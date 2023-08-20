#include "main.h"

/**
 * _cprintf - a function to print a char
 * @ap: to pass argument passed to _printf
 *
 * Return: Nothing.
 */
void _cprintf(va_list ap, int len)
{
	if(!ap)
		return;
	write(1, va_arg(ap, char), 1);
	len++;

}
