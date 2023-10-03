/*
 * Alx project: 0x16.C - Simple Shell
 * Authors: Peter Agada and Runyi Oyom
 * Cohort: 18
 * Duration: October 4 to 19 2023.
 */

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * is_delimiter - checks if a character is a delimiter.
 * @c: the character to check.
 * @delim: the delimiter string.
 *
 * Description:
 *	This function checks if the character 'c' is a delimiter
 *	found in the 'delim' string.
 *
 * Return: (1) if 'c' is a delimiter
 * (0) otherwise.
 */
int is_delimiter(char c, const char *delim)
{
	size_t len = strlen(delim);

	for (size_t i = 0; i < len; i++)
	{
		if (c == delim[i])
			return (1);
	}
	return (0);
}

/**
 * string_to_integer - converts a string to an integer.
 * @s: the string to be converted.
 *
 * Description:
 *	This function converts a string 's' to an integer. If there are
 *	no valid numbers in the string, it returns 0.
 *
 * Return: The converted integer if successful
 * 0 if no valid numbers in string.
 */
int string_to_integer(const char *s)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	/* Handle negative sign */
	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}

	/* Convert digits to integer */
	for (; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result = result * 10 + (s[i] - '0');
		}
		else
		{
			/* Non-digit character encountered, exit loop */
			break;
		}
	}

	/* If no digits were found, return 0 */
	if (i == (sign == -1 ? 1 : 0) || s[i] != '\0')
		return (0);

	return (result * sign);
}

/**
 * check_interactive - checks if the shell is in interactive mode.
 * @info: a struct containing information about the shell.
 *
 * Description:
 *	This function determines if the shell is running in interactive
 *	mode by checking if it's connected to a terminal.
 *
 * Return: (1) if the shell is in interactive mode
 * (0) otherwise.
 */
int check_interactive(struct shell_info *info)
{
	if (isatty(STDIN_FILENO))
		return (1);
	else
		return (0);
}

/**
 * is_alphabetic - checks if a character is alphabetic.
 * @c: the character to check.
 *
 * Description:
 *	This function checks if the character 'c' is an alphabetic
 *	character (a letter).
 *
 * Return: (1) if 'c' is alphabetic
 * (0) otherwise.
 */
int is_alphabetic(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
