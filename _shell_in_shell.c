#include <stdio.h>
#include "main.h"

/**
  * _shell_in_shell - spawns the shell. shell within a shell
  * @args: user commands and argumets
  *
  * Return: Always 0 on success, or -1 on error
  */
int _shell_in_shell(char **args)
{
	/*char **env = environ;*/
	int status;
	pid_t shell_pid;

	shell_pid = fork();
	if (shell_pid == -1)
	{
		perror("Error: failed to fork: shell_pid\n");
		return (-1);
	}
	else if (shell_pid == 0)
	{
		if (exec_path(args[0], args) == -1)
		{
			perror("Error: execve failed: shell_args\n");
			return (-1);
		}
	}
	else
	{
		do {
			waitpid(shell_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (0);
}
