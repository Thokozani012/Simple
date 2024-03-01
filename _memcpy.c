#include <stdio.h>
#include "main.h"

/**
  * _memcpy - Copies n bytes from 'src' mem to 'dest' mem
  * @dest: Memory area to be copied to
  * @src: Memory to be copied from
  * @n: The amount to copy from memory area
  *
  * Return: A pointer to the new memory area
  */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
