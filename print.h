#include "main.h"

/**
 * print - print
 * @str: the string
 * Return: string length
**/

int print(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	return (i);
}
