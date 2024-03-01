#include "main.h"

/**
  * _unsetenv - Removes an environment variable from the environment list
  * @name: The name of the variable to be removed
  *
  * Return: On success 0 is returned, or -1 on error
  */
int _unsetenv(char *name)
{
	char **env = environ;
	int i = 0, j = 0, k = 0;

	if (name == NULL)
	{
		perror("Error: No argument provided\n");
		return (-1);
	}

	while (name[k] != '\0')
	{
		if (name[k] == '=')
		{
			return (-1);
		}
		k++;
	}

	while (env[i] != NULL)
	{
		while (env[i][j] == name[j] && env[i][j] != '\0' && env[i][j] != '=')
			j++;

		if (env[i][j] == '=' && name[j] == '\0')
		{
			free(env[i]);
			/*shift the contents to fill the gap*/
			while (env[i + 1] != NULL)
			{
				env[i] = env[i + 1];
				i++;
			}
			env[i] = NULL;
			return (0);
		}
		j = 0;
		i++;
	}
	/*no match!*/
	return (0);
}
