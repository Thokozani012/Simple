#include <stdio.h>
#include "main.h"

/**
  * handle_int - handles the integer specifier for the _fprintf function
  * @stream: file stream where the output is directed (e.g stderr, ..)
  * @num: integer value
  *
  * Return: Nothing (void function)
  */
void handle_int(FILE *stream, int num)
{
	int i = 0;
	char buffer[20];
	(void) stream;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	do {
		buffer[i++] = '0' + (num % 10);
		num /= 10;
	} while (num != 0);

	while (i > 0)
	{
		_putchar(buffer[--i]);
	}
}

/**
  * handle_str - handles the string specifier for the _fprintf function
  * @stream: file stream where the output is directed (e.g stderr, ..)
  * @str: null terminated string
  *
  * Return: Nothing (void function)
  */
void handle_str(FILE *stream, const char *str)
{
	(void) stream;
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}

/**
  * _fprintf - bootleg fprintf for basic formatted output
  * @stream: File stream where the output is directed (e.g stderr)
  * @format: format string containing specifiers (e.g %d, %s..)
  *
  * Return: Always returns 0 on success
  */
int _fprintf(FILE *stream, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd')
			{
				handle_int(stream, va_arg(args, int));
			}
			else if (*format == 's')
			{
				handle_str(stream, va_arg(args, char *));
			}
			else
			{
				_putchar(*format);
			}
		}
		else
		{
			_putchar(*format);
		}
		format++;
	}

	va_end(args);
	return (0);
}
