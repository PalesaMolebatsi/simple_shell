#include "holberton.h"
/**
 * execute_command - Creates a new child process,
 * executes a command and waits for the child process
 * to update the status.
 * @args: Array of inputs provided by the user.
 * Return: 0 if success.
 */
int execute_command(char **args)
{
	pid_t child_pid = 0;/**Child process id*/
	int child_status = 0, exe_status = 0;/**Status of the child process*/

	child_pid = fork();/**Create a child process*/
	if (child_pid == -1)/**Failed to create*/
		_printp("failed\n", 7);
	else if (child_pid == 0)/**Child process*/
	{
		exe_status = execute(args[0], args, environ);/**Execute the command*/
		if (exe_status == -1)
		{
			exe_status = 126;
			perror("hsh");
			exit(exe_status);
		} /**Exit the child process successfully*/
		exit(0);
	}
	else/**Parent process*/
		wait(&child_status);/**Stop the parent's execution until the child process finishes*/
	exe_status = WEXITSTATUS(child_status);
	return (exe_status);
}
