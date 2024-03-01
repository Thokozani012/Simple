#include <stdio.h>
#include "main.h"

/**
  * built_in_env - handles the built in 'env' environment variable
  * @args: command entered by the user
  *
  * Return: Always 0.
  */
int built_in_env(char **args __attribute__((unused)))
{
	char **env;
	unsigned int i = 0;
	char *ch;

	env = environ;

	while (env[i] != NULL)
	{
		for (ch = env[i]; *ch; ch++)
		{
			_putchar(*ch);
		}
		_putchar('\n');
		i++;
	}

	return (0);
}

/**
  * built_in_setenv - handles the built in 'setenv' command for setting up env
  * @args: arguments to be passed to _setenv to set up new env variables
  *
  * Return: On success 0, or -1 on error
  */
int built_in_setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		perror("Error: Invalid arguments\n");
		return (-1);
	}

	if (_setenv(args[1], args[2], 1) != 0)
	{
		perror("Error: setenv\n");
		return (-1);
	}
	/*else
	{
		printf("Environment variable set: %s=%s\n", args[1], args[2]);
	}*/

	return (0);
}

/**
  * built_in_unsetenv - Built in 'unsetenv' command for removing env variable
  * @args: argument/variable passed to 'unsetenv' to be removed from env
  *
  * Return: On success 0 is returned, or -1 on error/failure
  */
int built_in_unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		perror("Error: provide argument\n");
		return (-1);
	}

	if (_unsetenv(args[1]) != 0)
	{
		perror("Error: unsetenv\n");
		return (-1);
	}
	/*else
	{
		printf("Environment variable removed:%s\n", args[1]);
	}*/

	return (0);
}

/**
  * new_pwd - Updates the 'PWD' env variable when switching between directories
  *
  * Return: Always 0.
  */
int new_pwd(void)
{
	char curr_dir[1024], *c_dir;

	c_dir = getcwd(curr_dir, sizeof(curr_dir));
	if (c_dir == NULL)
	{
		perror("Error: getcwd failed\n");
		return (-1);
	}

	_setenv("PWD", c_dir, 1);

	return (0);
}

/**
  * built_in_cd - built-in 'cd' command, for switching between directories
  * @args: dictories to witch to
  *
  * Return: Always 0 on success, or -1 on error
  */
int built_in_cd(char **args)
{
	char *home, *new_old;

	if (args[1] == NULL)
	{
		home = _getenv("HOME");
		if (home == NULL)
		{
			perror("Error: directory not found\n");
			return (-1);
		}
		new_old = _getenv("PWD");
		err_getenv(new_old);
		if (chdir(home) == 0)
		{
			new_pwd();
			_setenv("OLDPWD", new_old, 1);
		}
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		cd_dash();
	}
	else
	{
		char *dir = args[1], *new_old;
		/*let's get the current working directory before switching */
		new_old = _getenv("PWD");
		err_getenv(new_old);
		if (chdir(dir) == 0)
		{
			new_pwd();
			_setenv("OLDPWD", new_old, 1);
		}
		else
			perror("Error: directory not found\n");
	}
	return (0);
}
