#include "main.h"
#include <stdarg.h>

/**
 * _printf - Produces output according to a format
 * @format: Is a character string. The format string
 * is composed of zero or more directives
 *
 * Return: The number of characters printed (excluding
 * the null byte used to end output to strings)
 **/

int _printf(const char *format, ...)
{
	va_list ap;
        int size;

	if (format == NULL)
		return (-1);

	size = _strlen(format);
	if (size <= 0)
		return (0);

	va_start(ap, format);
	size = formatter(format, ap);

	_putchar(-1);
	va_end(ap);

	return (size);
}

/**
 * formatter - controls the format of the string to be printed
 * @str: String format
 * @list: List of auguments
 * Return: Total size of argument including the size of the string arguments
 */

int formatter(const char *str, va_list list)
{
	int size, i, aug;

	size = 0;
	for (i = 0; str[i]; i++)
	{
		if (str[i] == '%')
		{
			aug = percent_formatter(str, list, &i);
			if (aug == -1)
				return (-1);

			size += aug;
			continue;
		}

		_putchar(str[i]);
		size += 1;
	}

	return (size);
}

/**
 * percent_formatter - controls the selection specifiers
 * @str: String format
 * @list: list of arguments
 * @i: pointer integer Iterator
 * Return: size of the numbers of the elements printed including the sub strings
 */

{
	int size, j, number_formats;
	flag formats[] = {
		{'s', print_string}, {'c', print_char},
		{'d', print_integer}, {'i', print_integer},
		{'b', print_binary}, {'u', print_unsigned},
		{'o', print_octal}, {'x', print_hexadecimal_low},
		{'X', print_hexadecimal_upp}, {'p', print_pointer},
		{'r', print_rev_string}, {'R', print_rot}
	};

	*i = *i + 1;

	if (str[*i] == '\0')
		return (-1);

	if (str[*i] == '%')
	{
		_putchar('%');
		return (1);
	}

	number_formats = sizeof(f) / sizeof(formats[0]);
	for (size = j = 0; j < number_formats; j++)
	{
		if (str[*i] == formats[j].type)
		{
			size = formats[j].f(list);
			return (size);
		}

	}

	_putchar('%'), _putchar(str[*i]);

	return (2);
}
