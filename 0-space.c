#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * printchar - prints out characters
 * @c: character to be printed
 */

void printchar(va_list list)
{
	_putchar(va_arg(list, int));
}

/**
 * printstr - prints out strings
 * @str: string to be printed
 */

void printstr(va_list list)
{
	int i;
	char *s = va_arg(list, char *);

	if (s != NULL)
	{
		for (i = 0; s[i]; i++)
			_putchar(s[i]);
	}
}

/**
 * _printf - prints out arguments passed to it
 * @str: string to be printed
 */

int _printf(const char *format, ...)
{
	va_list ap;
	unsigned int i;

	flag type_list[] = {
		{ "c", printchar },
		{ "s", printstr }
	};

	va_start(ap, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
			_putchar(format[i]);
		else
		{
			if (format[i + 1] == 'c')
			{
				type_list[0].f(ap);
				i++;
			}

			else if (format[i + 1] == 's')
			{
				type_list[1].f(ap);
				i++;
			}

			else if (format[i + 1] == '%')
				_putchar('%');
		}
	}

	va_end(ap);
	return (i);
}
