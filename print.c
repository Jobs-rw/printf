#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Prints output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings).
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	char *str;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			if (*format == 'c')
				printed_chars += write(1, &va_arg(args, int), 1);
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					printed_chars += write(1, str, 1);
					str++;
				}
			}
			else if (*format == '%')
				printed_chars += write(1, "%", 1);
			else
			{
				printed_chars += write(1, &format[-1], 1);
				printed_chars += write(1, format, 1);
			}
		}
		else
			printed_chars += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (printed_chars);
}

