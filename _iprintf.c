#include "main.h"

/**
 * _iprintf - a function to print an integer in base 10.
 * @ap: to pass argument passed to _printf
 *
 * Return: Nothing.
 */
void _iprintf(va_list ap, int len)
{
	char *integer = va_arg(ap, char *);
	int i;

	if(!ap)
		return;

	if (integer[0] == 0 && integer[1])
	{
		for (i = 1; integer; i++)
		{
			write(1, &integer[i], 1);
			len++;
		}
	}

	else
	{
		for (i = 1; integer; i++)
		{
			write(1, &integer[i], 1);
			len++;
		}
	}
}
