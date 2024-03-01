#include <stdio.h>
#include "main.h"

/**
  * command_prompt - Prints the command prompt symbol '$'
  *
  * Return: Nothing (void function)
  */

void command_prompt(void)
{
	char *str = "#cisfun$ ";
	
	while (*str !='\0')
	{
		_putchar(*str);
		str++;
	}
}
