#include "main.h"

/**
 * _dprintf - a function to print a decimal (base 10) number
 * @ap: to pass argument passed to _printf
 *
 * Return: Nothing.
 */
void _dprintf(va_list ap, int len)
{
	char *dec;
	int i;

	if(!ap)
		return;
	for ()
	{
		dec[i] = va_arg(ap, char)
	}
	if (dec[0] != '0' && dec[1])
	{
		for (i = 0; dec ; i++)
		{
			write(1, dec[i], 1);
			len++;
		}
	}

	else
	{
		for (i = 1; dec ; i++)
		{
			/*handels octal cass*/
		}
	}

}
