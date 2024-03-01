#include "main.h"

/**
  * _strchr - Returns pointer to the first occurance of 'c' in 'str'
  * @str: string to be parsed
  * @c: character to be checked
  *
  * Return: Pointer to the first occurance of c in string 'str' or,
  * NULL when there is no match
  */
char *_strchr(const char *str, int c)
{
	char *ptr;

	if (str != NULL)
	{
		ptr = (char *)str;
	}
	else
	{
		return (NULL);
	}

	while (*ptr != '\0')
	{
		if (*ptr == c)
		{
			return (ptr);
		}
		ptr++;
	}

	/*handling null-termintor a searchable character*/
	if (c == 0 && *ptr == '\0')
	{
		return (ptr);
	}

	return (NULL);
}
