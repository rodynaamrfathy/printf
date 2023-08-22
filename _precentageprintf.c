#include "main.h"

/**
 * _precentageprintf - if the format contains %% print %
 * @ap: list
 * @len: lenth of the string printed
 *
 * Return: nothing.
 */
void _precentageprintf(va_list ap, int len)
{
	write(1,"%",1);
	len++;
}
