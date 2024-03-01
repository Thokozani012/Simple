#include <stdio.h>
#include "main.h"

/**
  * _process_char - Proccesses the characters read from the stdin
  * @lineptr: pointer to the stin stream
  * @n: original size of the line on stdin
  * @current_len: size of the line read
  * @ch: buffer where the lineptr content is stored
  *
  * Return: On success 0 is returned, 1 is returned when '\n' is encountered,
  * , and -1 is returned on failure or errror
  */
int _process_char(char **lineptr, size_t *n, size_t *current_len, char ch)
{
	size_t new_size;
	char *temp_buffer;

	if (*current_len >= *n - 1)
	{
		new_size = *n * 2;
		temp_buffer = _realloc(*lineptr, *current_len, new_size);
		if (temp_buffer == NULL)
		{
			perror("Error: _realloc failed\n");
			free(*lineptr);
			return (-1);
		}
		*lineptr = temp_buffer;
		*n = new_size;
	}

	(*lineptr)[*current_len] = ch;
	++*current_len;

	if (ch == '\n')
	{
		return (1); /* indicating newline char */
	}

	return (0);
}

/**
  * _getline - custom getline function that reads from the FILEe stream stdin
  * @lineptr: Pointer to the stdin stream
  * @n: Original size of rhe line on the stdin
  * @stream: specified file stream
  *
  * Return: On success the number of read characters from 'stream' is returned
  * , or -1 is returned on failure or error.
  */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char ch;
	size_t current_len;
	int c, result;

	if (lineptr == NULL || n == NULL)
	{
		perror("Error: Invalid arguments\n");
		return (-1);
	}
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(sizeof(char) * (*n));
		if (*lineptr == NULL)
		{
			perror("Error: malloc failed\n");
			return (-1);
		}
	}
	if (current_len != 0)
		fflush(stream);
	current_len = 0;
	while (ch != EOF)
	{
		c = read(STDIN_FILENO, &ch, 1);
		if (c == -1 || c == 0)
		{
			if (c == -1)
			{
				perror("Error: read failed\n");
				return (-1);
			}
			else if (c == 0 && current_len == 0)
				exit(0);
		}
		result = _process_char(lineptr, n, &current_len, ch);
		if (result == 1)
			break;
	}
	return (current_len);
}
