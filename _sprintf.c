#include "main.h"

/**
 * _sprintf - a function to print a string
 * @ap: to pass argument passed to _printf
 *
 * Return: Nothing.
 */
void _sprintf(va_list ap, int len)
{
	int i;
	char str;

	if(!ap)
		return;
	for (i = 0; str ; i++)
	{
		char str = va_arg(ap, char);
		write(1, str[i], 1);
		len++;
	}
}
