#include "main.h"

/**
 * from_to_print - prints a range of char addresses
 * @start: starting address
 * @end: stopping address
 * @except: except address
 * Return: number bytes printed
 */
int from_to_print(char *start, char *end, char *except)
{
	int sum = 0;

	while (start <= end)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * rev_print - prints string in reverse
 * @ap: string
 * @par: the parameters struct
 * Return: number bytes printed
 */
int rev_print(va_list ap, par_t *par)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *);
	(void)par;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * rot13_print - print string in rot13
 * @ap: string
 * @par: parameter struct
 * Return: number bytes printed
 */
int rot13_print(va_list ap, par_t *par)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM		nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)par;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z') ||
		    (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
