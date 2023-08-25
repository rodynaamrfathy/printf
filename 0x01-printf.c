#include <stdlib.h>
#include "main.h"
/**
 * print_integer - Handle the following conversion specifiers
 * @num: integer
 * Return: void
 */
void print_integer(int num)
{
	char buffer[32];
	int i = 0;
	int is_negative = 0;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	do {
		buffer[i++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);
	if (is_negative)
	{
		buffer[i++] = '-';
	}
	while (i > 0)
	{
		i--;
		_putchar(buffer[i]);
	}
}
/**
 * main - make the function check
 * Return: Always 0
 */
int main(void)
{
	int number = 123;

	print_integer(number);
	return (0);
}
