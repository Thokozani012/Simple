#include <stdio.h>
#include "main.h"

/**
  * _execve - executes the input command(s)
  * @args: commadn plus arguments
  *
  * Return: 0 on success, or -1 on error.
  */

int _execve(char **args)
{
	pid_t child_pid;
	int status;

	if (args)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("tsh: failed to fork: child_pid\n");
			return (-1);
		}

		if (child_pid == 0)
		{
			if (exec_with_path(args[0], args) == -1)
			{
				/*fprintf(stderr, "tsh: execve failed: child_pid\n", args[0]);*/
				perror("tsh: execve failed: child_pid\n");
				return (-1);
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
