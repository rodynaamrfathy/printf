#include "main.h"

/**
 * _cprintf - a function to print a char
 * @ap: to pass argument passed to _printf
 *
 * Return: Nothing.
 */
void _cprintf(va_list ap, int len)
{
	char character;

	if(!ap)
		return;

	character = (char)va_arg(ap, int);
	write(1, &character, 1);
	len++;

}
