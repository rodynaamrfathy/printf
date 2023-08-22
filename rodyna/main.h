#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * stuct symbols_handling - 
 * @symbol:
 * @func:
 */
typedef struct symbols_handling{
	
	char *symbol;
	void (*func)(va_list, int);

} symbols_t;

int _printf(const char *format, ...);

void _sprintf(va_list ap, int len); /*to print string %s*/
void _cprintf(va_list ap, int len); /*to print char %c*/
/* %d vs %i 
 * %d: prints decimals
 * %i: octal and base 10
 * If the integer starts with a 0, it's treated as an octal number;
 * otherwise, it's treated as a decimal number.
 * example:
 * printf("%d", 012); output will be 10
 * printf("%i", 012); output will be 12*/
void _iprintf(va_list ap, int len); /*to print integer base 10 %i*/
void _dprintf(va_list ap, int len); /*to print decimal base 10 %d*/
void _precentageprintf(va_list ap, int len);

#endif
