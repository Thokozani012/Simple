#include <stdio.h>
#include "main.h"

/**
  * _strcpy - Copies a string
  * @src: source string
  * @dest: destination string
  *
  * Return: On success, destination string is returned.
  */

char *_strcpy(char *dest, const char *src)
{
	char *start_dest;

	/*error checking*/
	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}

	/*keep the start of the dest pointer*/
	start_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';

	return (start_dest);
}
