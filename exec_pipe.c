#include "main.h"

int exec_pipe(char **args1, char **args2)
{
	int pipefd[2];
	pid_t pid1, pid2;
	int status1, status2;

	/*Create a pipe */
	if (pipe(pipefd) == -1)
	{
		perror("tsh: pipe creation failed\n");
		return (-1);
	}

	/* Fork the first child process */
	if ((pid1 = fork()) == -1)
	{
		perror("tsh: fork failed (pid1)\n");
		return (-1);
	}
	else if (pid1 == 0) /* in the child process */
	{
		/* Close the read end of the pipe */
		close(pipefd[0]);

		/* Redirect stdout to the write end of the pipr */
		dup2(pipefd[1], STDOUT_FILENO);

		/* Close the unused end of the pipe */
		close(pipefd[1]);

		/* Execute the first command */
		execvp(args1[0], args1);
		/*{
			perror("tsh: execve failed (args1)\n");
			exit(EXIT_FAILURE);
		}*/
		 exit(EXIT_FAILURE);
	}

	/* Fork the second child process */
	if ((pid2 = fork()) == -1)
	{
		perror("tsh: exec_path failed (args2)\n");
		return (-1);
	}
	else if (pid2 == 0)
	{
		/*Close the write end of the pipe */
		close(pipefd[1]);

		/*Redirect stdin to te read end of the pipe */
		dup2(pipefd[0], STDIN_FILENO);

		/* Close the unused end  of the pipe */
		close(pipefd[0]);

		/* Execute the second command */
		if (execve(args2[0], args2, NULL) == -1)
		{
			perror("tsh: execve failed (args2)\n");
			exit(EXIT_FAILURE);
		}
	}

	/* Close both ends of the pipe in the parent process */
	close(pipefd[0]);
	close(pipefd[1]);

	/* Wait for both child processes to finish */
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);

	return (0);
}
