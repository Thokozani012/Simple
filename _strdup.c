#include "main.h"

/**
  * _strdup - Duplicates a string
  * @str: string to be duplicated
  *
  * Return: On Success a duplicated string is returned,
  * or NULL on error/failure
  */
char *_strdup(const char *str)
{
	char *strdupl;

	/*error handling*/
	if (str == NULL)
		return (NULL);

	/*memory allocation*/
	strdupl = malloc(sizeof(char) * (_strlen(str) + 1));
	if (strdupl == NULL)
	{
		perror("Error: memory allocation failed\n");
		return (NULL);
	}

	/*string copying*/
	_strcpy(strdupl, str);

	return (strdupl);
}
