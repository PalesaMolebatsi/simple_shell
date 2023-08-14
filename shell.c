#include "holberton.h"

/**
 * main - Entry point for the shell program.
 * Return: 0 on success.
 */
int main(void)
{
	ssize_t rd_bytes = 0; /* Bytes read from getline */
	size_t buffer_size = 0; /* Buffer size */
	char *input = NULL, *args[20]; /* User input arguments */
	int cmd_count = 1, path_stat = 0, exist_stat = 0, exit_status = 0, builtin_stat = 0;

	_print_prompt("$ ", 2); /* Display prompt for the shell */
	rd_bytes = getline(&input, &buffer_size, stdin); /* Read user input */

	while (rd_bytes != -1)
	{
		if (*input != '\n')
		{
			fill_arguments(input, args);

			if (args[0] != NULL)
			{
				path_stat = check_path(args[0]); /* Check if the path exists */

				if (path_stat != 0) /* File not found */
				{
					exist_stat = verify_path_existence(args);

					if (exist_stat == 0)
					{
						exit_status = execute_command(args);
						free(input);
						free(*args);
					}
					else
					{
						builtin_stat = check_builtin(args, exit_status);

						if (builtin_stat != 0)
						{
							exit_status = print_not_found(args, cmd_count);
							free(input);
						}
					}
				}
				else /* File found */
				{
					exit_status = execute_command(args);
					free(input);
				}
			}
			else
			{
				free(input);
			}
		}
		else if (*input == '\n')
		{
			free(input);
		}

		input = NULL;
		cmd_count++;
		_print_prompt("$ ", 2);
		rd_bytes = getline(&input, &buffer_size, stdin);
	}

	clean_up(input);
	return (exit_status);
}

