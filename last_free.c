#include "holberton.h"
/**
 * clear_memory - Free the allocated memory after the last execution.
 * @user_input: Input typed by the user.
 */
void clear_memory(char *user_input)
{
	if (isatty(STDIN_FILENO))
	{
		print_character('\n');
		free(user_input);
	}
	if (!isatty(STDIN_FILENO))
		free(user_input);
}
