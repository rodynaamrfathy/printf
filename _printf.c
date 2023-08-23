#include <stdarg.h>
#include <unistd.h>

#define MAX_INT_LENGTH 12
#define MAX_BIN_LENGTH 33

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int chars_printed = 0;
    char c;

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                c = va_arg(args, int);
                write(1, &c, 1);
                chars_printed++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char*);
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    chars_printed++;
                }
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                chars_printed++;
            }
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                char num_str[MAX_INT_LENGTH];
                // Convert num to string using your custom function
                // ...
                // Print the string
                write(1, num_str, strlen(num_str));
                chars_printed += strlen(num_str);
            }
            else if (*format == 'b')
            {
                unsigned int num = va_arg(args, unsigned int);
                char bin_str[MAX_BIN_LENGTH];
                // Convert num to binary string using your custom function
                // ...
                // Print the string
                write(1, bin_str, strlen(bin_str));
                chars_printed += strlen(bin_str);
            }
            else if (*format == 'u')
            {
                unsigned int num = va_arg(args, unsigned int);
                // Convert and print num as unsigned decimal
            }
            else if (*format == 'o')
            {
                unsigned int num = va_arg(args, unsigned int);
                // Convert and print num as octal
            }
            else if (*format == 'x' || *format == 'X')
            {
                unsigned int num = va_arg(args, unsigned int);
                // Convert and print num as lowercase/uppercase hexadecimal
            }
            else if (*format == 'S')
            {
                char *str = va_arg(args, char*);
                while (*str)
                {
                    if (*str >= 32 && *str < 127)
                    {
                        write(1, str, 1);
                        chars_printed++;
                    }
                    else
                    {
                        char hex[5];
                        snprintf(hex, sizeof(hex), "\\x%02X", (unsigned char)(*str));
                        write(1, hex, strlen(hex));
                        chars_printed += strlen(hex);
                    }
                    str++;
                }
            }
            else
            {
                write(1, format - 1, 2); // Print the % and the next character
                chars_printed += 2;
            }
        }
        else
        {
            write(1, format, 1);
            chars_printed++;
        }
        format++;
    }

    va_end(args);
    return chars_printed;
}
