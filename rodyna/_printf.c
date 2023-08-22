#include "main.h"
#include <stdarg.h>
#include <string.h>

/**
 * printf - a function that produces output according to a format.
 * @format: strind passed to function.
 * @...: arguments to be added
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, j, len = 0;
	symbols_t symbol_func[] = {{"s", _sprintf},
				{"c", _cprintf},
				{"i", _iprintf},
				{"%", _precentageprintf},
				{NULL, NULL},
	};

	len = strlen(format);
	va_start(ap, format);

	/*check if the sting passed "format" contains %s or whatever variable
	 * pinting special character then call its funcltion with prototype
	 * will be included in main.h exapmle _sprintf() this function
	 * will be called when you find %s in the format
	 * struct for this array will be included in main.h
	 * len will be increminted with the len of format then the len of
	 * any other variable to be printed 
	 * len = strlen(format) + strlen(variables)*/
	
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%' && format[i + 1])
		{
			for (j = 0; symbol_func[j].symbol; j++)
			{
				if (format[i + 1] == symbol_func[j].symbol[0])
				{
					symbol_func->func(ap, len);
					break;
				}
			}
			
			write(1,&format[i],1);

			/* tb lw 3ndy % bs mfish match ll specifiers htb3 brdo bs el %
			 * httb3 azay men 8ir \% hwa msh hy2raha aslun i think*/

		}
	}
	
	va_end(ap);
	return (len);
}
