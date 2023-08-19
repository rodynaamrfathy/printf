#include "main.h"
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
	int len = 0;
	symbols_t symbol_func[] = {{"s", }
				{"c", }
				{"i", }
				{"d", }
				{NULL, NULL}
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
					symbol_func.func(ap);
					len++;
				}
			}
		}
	}

	return (len);
	va_end(ap);
}
