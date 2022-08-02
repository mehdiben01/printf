#include "main.h"

/**
 * handler -format controller
 * @str: string format
 * @list: list of arguments
 * Return: size
**/

int handler(const char *str, va_list list)
{
	int size, i, aux;

	size = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] =='%')
		{
			aux = percent_handler(str, list, &i);

			if (aux == -1)
				return (-1);

			size += aux;
			continue;
		}

		_putchar(str[i]);
		size = size + 1;
	}

	return (size);
}

/**
 * percent_handler - percent format controller
 * @str: string format
 * @list: list of argumets
 * @i: iterator
 * Return: size
**/

int percent_handler(const char *str, va_list list, int *i)
{
	int size, j, number_formats;
	format formats[] = {
		{'s', print_string}, {'c', print_char}
	};

	*i = *i + 1;

	if (str[*i] == '\0')
		return (-1);

	if (str[*i] == '%')
	{
		_putchar('%');
		return (1);
	}

	number_formats = sizeof(formats) / sizeof(formats[0]);

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
