#include "main.h"

/**
* _put - prints a string with new line
* @s: the string to print
* Return: void
*/
int _put(char *s)
{
char *a = s;

while (*s)
	_putchar(*s++);
return (s - a);
}

/**
* _putchar - writes the character c to stdout
* @c: character to print
* Return: on success 1.
*	on error, -1 is returned, and errno is set appropriately
*/
int _putchar(int c)
{
static int i;
static char buf[OUT_BUFFER_SIZE];

if (c == BUFFER_FLUSH || i >= OUT_BUFFER_SIZE)
{
	write(1, buf, i);
	i = 0;
}
if (c != BUFFER_FLUSH)
	buf[i++] = c;
return (1);
}
