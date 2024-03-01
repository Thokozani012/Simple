#include <stdio.h>
#include "main.h"

/**
  * _snprint - bootleg 'snprint' function for sole purpose of simple_shell
  * @file_path: buffer to store the user command and tokenize 'PATH'
  * @token: Tokenized directories in the 'PATH' environment variable
  * @command: command of the user together with the "PATH' dir
  *
  * Return: Always a pointer to the buffer 'file_path'
  */

int _snprint(char *file_path, size_t buffer_size, char *token, char *command)
{
	size_t required_size;

	if (!file_path || !buffer_size|| !token || !command)
	{
		perror("tsh: Invalid argument\n");
		return (-1);
	}

	required_size = _strlen(token) + _strlen("/") + _strlen(command) + 1;
	if (required_size > buffer_size)
	{
		perror("tsh: buffer_overflow\n");
		return (-1);
	}

	_strcpy(file_path, token);
	file_path[_strlen(token)] = '/';

	_strcpy(file_path + _strlen(token) + 1, command);
	
	return (0);
}
