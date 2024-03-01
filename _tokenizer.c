#include "main.h"


char **_token_lineptr(char *lineptr)
{
	char *delimiter = " ", *token, *copy_lineptr, **args, *pipe_token;
	int i = 0, wordCount = 0, has_pipe = 0;

	copy_lineptr = strdup(lineptr);
	if (copy_lineptr == NULL)
	{
		perror("tsh: failed to strdup 'lineptr'\n");
		exit(1);
	}

	/*Detect pipe symbol existance */
	pipe_token = strchr(copy_lineptr, '|');
	if (pipe_token)
	{
		has_pipe = 1;

		/* Count words before and after pipe */
		token = strtok(copy_lineptr,delimiter);
		while (token != NULL)
		{
			if (token == pipe_token)
			{
				break;
			}
			wordCount++;
			token = strtok(NULL, delimiter);
		}

		token = strtok(NULL, delimiter); /* Move past pipe */
		while (token != NULL)
		{
			wordCount++;
			token = strtok(NULL, delimiter);
		}
	}
	else
	{
		/* Count words in entire line if no pipe */
		token = strtok(copy_lineptr, delimiter);
		while (token != NULL)
		{
			wordCount++;
			token = strtok(NULL, delimiter);
		}
	}

	/* Allocate memory for arguments */
	args = malloc(sizeof(char *) * (wordCount + 1));
	if (args == NULL)
	{
		perror("tsh: memory allocation failed: args\n");
		exit (1);
	}

	/* Reset copy_lineptr and tokenize again */
	strcpy(copy_lineptr, lineptr);
	token = strtok(copy_lineptr, delimiter);

	/* Add arguments before pipe (if any) */
	i = 0;
	while (token != NULL && token != pipe_token)
	{
		args[i] = _strdup(token);
		if (args[i] == NULL)
		{
			perror("tsh: memory allocation failed: args[i]\n");
			exit (1);
		}
		token = strtok(NULL, delimiter);
		i++;
	}

	if (has_pipe)
	{
		/* Add pipe symbol as separate argument */
		args[i] = strdup("|");
		if (args[i] == NULL)
		{
			perror("tsh: memory allocation failed: args[i]\n");
			exit(1);
		}
		i++;

		/* Add argument after pipe */
		token = strtok(NULL, delimiter);
		while (token != NULL)
		{
			args[i] = strdup(token);
			if (args[i] == NULL)
			{
				perror("tsh: memory allocation failed: args[i]\n");
				exit(1);
			}
			token = strtok(NULL, delimiter);
			i++;
		}
	}

	/* Terminate argument list */
	args[i] = NULL;

	free(copy_lineptr);
	return (args);
}
