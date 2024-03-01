#include "main.h"

/**
  * cd_dash - Command for switching between two working directories
  *
  * Return: Nothing (void function)
  */
void cd_dash(void)
{
	char *pwd = _getenv("PWD");
	char *oldpwd = _getenv("OLDPWD");

	if (chdir(oldpwd) == 0)
	{
		_setenv("PWD", oldpwd, 1);
		_setenv("OLDPWD", pwd, 1);
	}
}

/**
  * err_getenv - Error handling for '_getenv'
  * @var: pointer to the environment variable
  *
  * Return: Always -1.
  */
int err_getenv(char *var)
{
	if (var == NULL)
	{
		perror("Error: _getenv failed\n");
	}
	return (-1);
}
