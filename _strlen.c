#include "main.h"

/**
 * _strlen - calculates the length of a string
 * @str: the string
 * Return: length of @str
**/

int _strlen(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;

	return (i);
}
