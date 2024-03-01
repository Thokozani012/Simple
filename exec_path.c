#include <stdio.h>
#include "main.h"

/**
  * executer - Runs the user commands through 'exceve'
  * @file_path: buffer for user commands and arguments wit path resolution
  * @args: user arguments
  * @env: environment list
  * @status: status of the child_pid
  *
  * Return: Always 0 or -1 on error
  */
int executer(char *file_path, char **args, char **env, int status)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("tsh: fork failed: child_pid\n");
		return (-1);
	}
	else if (child_pid == 0)
	{
		if (execve(file_path, args, env) == -1)
		{
			perror("tsh: execve failed: child_pid\n");
			return (-1);
		}
	}
	else
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (0);
}
/**
  * _found - executes the command if it exits/found
  * @file_path: file path (though 'PATH')
  * @command: command to be executed
  * @args: command arguments
  * @found: flag used to indicate when 'command' is found
  *
  * Return: Always 0 on success, or -1 on failure
  */
int _found(char *file_path, char *command, char **args, int found)
{
	int status = 0;
	char **env = environ;

	if (found == 1)
	{
		if (command[0] == '/')
		{
			executer(file_path, args, env, status);
		}
		else
		{
			executer(file_path, args, env, status);
		}
	}
	else
	{
		fprintf(stderr, "%s: command not found\n", command);
		return (-1);
	}
	return (0);

}

/**
  * _path_err - error handlinng for the environment varable 'PATH'
  * @path: environment variable
  *
  * Return: Always -1.
  */
int _path_err(char *path)
{
	if (path == NULL)
	{
		perror("tsh:failed to get environment variable 'PATH'\n");
	}
	return (-1);
}

/**
  * _file_path_err - error handling for file_path malloc operation
  * @file_path: command path.
  *
  * Return: Always -1.
  */
int _file_path_err(char *file_path)
{
	if (file_path == NULL)
	{
		perror("memory allocation failed: args\n");
	}
	return (-1);
}
/**
  * exec_with_path - search for executeable in each dir in 'PATH'
  * @command: command to be executed
  * @args: command arguments
  *
  *
  * Return: 0 On success, or -1 on error.
  */

int exec_path(char *command, char **args)
{
	char *path, *path_copy, *file_path, *token;
	int found = 0;
	size_t path_len, command_len, buffer_size;
	int pipe_found = 0, i;
	char **args1, **args2;

	path = getenv("PATH");
	_path_err(path);

	path_copy = _strdup(path);
	if (path_copy == NULL)
	{
		perror("tsh: memory allocation failed: copy_path\n");
		return (-1);
	}

	token = _strtok(path_copy, ":");
	while (token != NULL)
	{
		if (command[0] == '/')
		{
			file_path = command;
		}
		else
		{
			path_len = _strlen(token);
			command_len = _strlen(command);
			buffer_size = path_len + 1 + command_len + 1;

			file_path = malloc(buffer_size);
			if (file_path == NULL)
			{
				perror("tsh: memory allocation failed: file_path\n");
				free(path_copy);
				return (-1);
			}
			/*_file_path_err(file_path);*/
			/*_snprint(file_path, buffer_size, token, command);*/
			snprintf(file_path, buffer_size, "%s/%s", token, command);
		}

		/* Check for pipe symbol */
		pipe_found = 0;
		for (i = 0; args[i] != NULL; i++)
		{
			if (strcmp(args[i], "|") == 0)
			{
				pipe_found = 1;
				break;
			}
		}

		if (pipe_found)
		{
			/* Split arguments into two sub-arrays*/
			int pipe_index = 0, args1_size, args2_size;
			/*int status1, status2;*/
			while (args[pipe_index] != NULL && strcmp(args[pipe_index], "|") != 0)
			{
				pipe_index++;
			}

			args1_size = pipe_index + 1;
			args2_size = sizeof(args) - (pipe_index + 1) / sizeof(args[0]);

			args1 = malloc(sizeof(char *) * args1_size);
			args2 = malloc(sizeof(char *) * args2_size);

			memcpy(args1, args, sizeof(char *) * args1_size);
			memcpy(args2, args + pipe_index + 1, sizeof(char *) * args2_size);

			args1[args1_size - 1] = NULL;
			args2[args2_size - 1] = NULL;

			/*execute commands recursively for each side of the pipe */
			/*int status1, status2;*/
			/*if (exec_path(command, args1) == -1)
			{
				free(args1);
				free(args2);
				free(file_path);
				break;
			}
			if (exec_path(args2[0], args2 + 1) == -1)
			{
				free(args1);
				free(args2);
				free(file_path);
				break;
			}*/

			/* wait for both child processes to finish */
			/*waitpid(-1, &status1, WUNTRACED);
			waitpid(-1, &status2, WUNTRACED);*/

			if (exec_pipe(args1, args2) == -1)
			{
				free(args1);
				free(args2);
				free(file_path);
				break;
			}

			free(args1);
			free(args2);
			free(file_path);
			/*found = (WIFEXITED(status1) && WEXITSTATUS(status1) == 0 && WIFEXITED(status2) && WEXITSTATUS(status2) == 0);*/
			found = 1;
			break;
		}
		else
		{
			if (access(file_path, X_OK) == 0)
			{
				found = 1;
				_found(file_path, command, args, found);
				free(file_path);
				break;
			}
			else
			{
				found = 0;
			}
			free(file_path);
		}
		token = _strtok(NULL, ":");
	}

	free(path_copy);
	return (found == 1 ? 0 : -1);
}
