#include "holberton.h"
/**
 * extract_args - Extracts and stores each input typed by the user into an array.
 * @input_str: String with the input from the user.
 * @args_array: Array to be filled with extracted arguments.
 * Return: Length of the array.
 */

int extract_args(char *input_str, char **args_array)
{
	int i = 0;
	char *token, *temp_input = input_str, *command;

	command = strtok(input_str, "\n\t\r "); /**Extract the command (token 0) */
	args_array[i] = command; /**Store the command (token 1) in args_array*/
	while (temp_input != NULL) /**While there are more tokens*/
	{
		++i;
		token = strtok(NULL, "\n\t\r "); /**Store the nth argument in token*/
		temp_input = token;
		args_array[i] = token; /**Store the nth argument in args_array[i]*/
	}
	args_array[i] = NULL; /**Mark the end of the array*/
	return (i); /**Return the length of args_array[]*/
}
