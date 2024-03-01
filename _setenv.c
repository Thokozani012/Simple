#include "main.h"

/**
  * _sprintf - bootleg 'sprintf' function, specially made for _setenv
  * @name: name of the environment variable
  * @value: value of the environment variable
  *
  * Return: Always a pointer to a new allocated memory/buffer
  */
char *_sprintf(const char *name, const char *value)
{
	char *new_var;

	new_var = malloc(_strlen(name) + _strlen(value) + 1 + 1);
	if (new_var == NULL)
	{
		perror("Error: memory allocation failed\n");
		return (NULL);
	}

	_strcpy(new_var, name);
	_strcat(new_var, "=");
	_strcat(new_var, value);

	return (new_var);
}

/**
  * _setenv - Adds variable name 'name' to the environment with value 'value'
  * @name: variable name
  * @value: variable value
  * @overwrite: flag deciding whether to change the environment list or not.
  *
  * Return: 0 on success, or -1 on error or failure
  */
int _setenv(const char *name, const char *value, int overwrite)
{
	char **env = environ, *new_var;
	int i = 0, j = 0;

	if (name == NULL && value == NULL)
		return (-1);

	while (env[i] != NULL)
	{
		while (env[i][j] == name[j] && env[i][j] != '\0')
			j++;

		if (env[i][j] == '=' && name[j] == '\0')
		{
			if (overwrite != 0)
			{
				new_var = _sprintf(name, value);
				env[i] = new_var;

				return (0);
			}
			else
				return (0);
		}
		j = 0;
		i++;
	}

	/* When there is no match!*/
	if (overwrite != 0)
	{
		new_var = _sprintf(name, value);
		env[i] = new_var;
		env[i + 1] = NULL;
		return (0);
	}
	else
		return (0);
}
