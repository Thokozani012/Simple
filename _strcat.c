#include <stdio.h>
#include "main.h"

/**
  * _strcat - Concatenates a string
  * @dest: string to be concatenated
  * @src: string to be copied
  *
  * Return: On success, dest string will be returned
  */
char *_strcat(char *dest, const char *src)
{
	size_t i;
	size_t dest_len = 0;

	while (dest[dest_len] != '\0')
		dest_len++;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';

	return (dest);
}
