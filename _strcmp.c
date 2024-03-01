#include "main.h"

/**
  * _strcmp - Compares two strings
  * @s1: First string to be compared against
  * @s2: Second string to be compared
  *
  * Return: 0 when the two strings match, less than 0
  * if the n bytes of s1 are less than of s2,
  * or greater than 1 when the n bytes of s1 are greater than s2
  */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
