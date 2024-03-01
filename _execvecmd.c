#include <stdio.h>
#include "main.h"

/**
  * _execvecmd - executes the commands in the non-interactive mode
  * @args: command plus arguments
  *
  * Return: On success 1, or 1 on error.
  */

int _execvecmd(char **args)
{
	/*char *cmd = NULL;*/
	char **env = environ;
	pid_t shell_child_pid;
	/*int status;*/

	if (args)
	{
		shell_child_pid = fork();
		if (shell_child_pid == -1)
		{
			perror("tsh: failed to fork: shell_child_pid\n");
			return (-1);
		}

		if (shell_child_pid == 0)
		{
			if (execve(args[0], args, env) == -1)
			{
				perror("tsh: execve failed: shell_child_pid\n");
				return (-1);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
