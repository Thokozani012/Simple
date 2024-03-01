#include "main.h"
#include <stddef.h>

/**
  * tokenStart_null - Updates lastToken pointer to NULL after reaching '\0'
  * @lastToken: Double pointer to the last token of the tokenized string
  *
  * Return: Nothing (void funtion);
  */
void tokenStart_null(char **lastToken)
{
	if (*(*lastToken) == '\0')
	{
		lastToken = NULL;
		return;
	}
}

/**
  * _strtok - String tokenizer
  * @str: string to be tokenized
  * @delimiters: seperators used to tokenize the string 'str'
  *
  * Return: On success, A pointer to the next token or
  * NULL if there are no more tokens
  */
char *_strtok(char *str, const char *delimiters)
{
	static char *lastToken; /*keep track of the last token */
	char *tokenStart;
	const char *delimPtr; /* pointer to a string of delimiters */

	if (str != NULL)
		lastToken = str;
	if (lastToken == NULL || *lastToken == '\0')
		return (NULL);
	tokenStart = lastToken;
	for (; *tokenStart != '\0'; tokenStart++)
	{
		delimPtr = delimiters;
		while (*delimPtr != '\0' && *tokenStart != *delimPtr)
			delimPtr++;
		if (*delimPtr == '\0')
			break;
	}
	tokenStart_null(&lastToken);
	for (; *lastToken != '\0'; lastToken++)
	{
		delimPtr = delimiters;
		while (*delimPtr != '\0' && *lastToken != *delimPtr)
			delimPtr++;
		if (*delimPtr != '\0')
			break;
	}
	if (*lastToken != '\0')
	{
		*lastToken = '\0';
		lastToken++;
		while (*lastToken != '\0' && _strchr(delimiters, *lastToken) != NULL)
			lastToken++;
		if (*lastToken == '\0')
			lastToken = NULL;
	}
	else
		lastToken = NULL;
	return (tokenStart);
}
