#include <stdio.h>
#include "main.h"

/**
  * _strlen - Calculates the length of the string
  * @str: null terminated string
  *
  * Return: length of the string
  */

int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}
