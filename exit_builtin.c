#include "main.h"

/**
  * _atoi - Converts a integer string into an int
  * @nptr: pointer to the integer string
  *
  * Return: The converted numner
  */
int _atoi(const char *nptr)
{
	int i = 0, results = 0, sign = 1;

	/*skipping the leading white-spaces*/
	while (nptr[i] == ' ')
	{
		i++;
	}

	/*handling negative and positive sign(s)*/
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
	{
		sign = 1;
		i++;
	}

	for (; nptr[i] != '\0'; i++)
	{
		/*handling non-interger values*/
		if (nptr[i] < '0' || nptr[i] > '9')
		{
			break;
		}

		results = results * 10 + (nptr[i] - '0');
		/*handling extremely small and big numbers, e.g INT_MIN and INT_MAX*/
		if (results > INT_MAX / 10 || (results == INT_MAX / 10 && nptr[i] - '0' > 7))
		{
			return (0);
		}
	}

	return (sign * results);
}

/**
  * exit_builtin - Built-in exit feature for exiting the shell
  * @args: arguments to the 'exit' command
  *
  * Return: Always 0, or different exit status
  */
int exit_builtin(char **args)
{
	int exit_code, i, str_len;
	char str[] = "exit\n\n\n[Disconnected ...]\n";

	str_len = _strlen(str);

	for (i = 0; i < str_len; i++)
	{
		_putchar(str[i]);
	}

	if (args[1])
	{
		exit_code = _atoi(args[1]);
		if (exit_code < 0 || exit_code > 255)
		{
			exit(1);
		}
		exit(exit_code);
	}
	else if (args[0])
	{
		exit(0);
	}

	return (0);
}
