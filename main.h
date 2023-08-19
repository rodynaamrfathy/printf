#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

typedef struct symbols_handling{
	
	char *symbol;
	void (*func)(va_list);

} symbols_t;

int _printf(const char *format, ...);

void _sprintf(va_list); /*to print string %s*/
void _cprintf(va_list); /*to print char %c*/
/* %d vs %i 
 * %d: prints decimals
 * %i: octal and base 10
 * If the integer starts with a 0, it's treated as an octal number;
 * otherwise, it's treated as a decimal number.
 * example:
 * printf("%d", 012); output will be 10
 * printf("%i", 012); output will be 12*/
void _iprintf(va_list); /*to print integer base 10 %i*/
void _dprintf(va_list); /*to print decimal base 10 %d*/

#endif
