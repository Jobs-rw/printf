#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - produces output according to a format.
 * @format: format string containing zero or more directives.
 *
 * Return: number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    char c;
    char *s;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    c = va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;
                case 's':
                    s = va_arg(args, char *);
                    if (s == NULL)
                        s = "(null)";
                    while (*s)
                    {
                        write(1, s, 1);
                        s++;
                        count++;
                    }
                    break;
                case '%':
                    write(1, "%", 1);
                    count++;
                    break;
                default:
                    write(1, "%", 1);
                    count++;
                    write(1, &(*format), 1);
                    count++;
                    break;
            }
        }
        else
        {
            write(1, &(*format), 1);
            count++;
        }
        format++;
    }
    va_end(args);
    return count;
}
