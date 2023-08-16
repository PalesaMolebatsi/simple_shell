#include "holberton.h"
/**
 * exec - Creates a new child process,
 * executes a command and wait for the child process
 * to update the status
 * @arguments: Array of inputs by the user
 * Return: 0 if success
 */
int exec(char **arguments)
{
	pid_t pid = 0;/**Child process id*/
	int stat = 0, exe_stat = 0;/**Indicate the status of the child process.*/

	pid = fork();/**Create a child processCreate a child process*/
	if (pid == -1)/**Failed to create*/
		_printp("failed\n", 7);
	else if (pid == 0)/**It's the child...*/
	{
		exe_stat = execve(arguments[0], arguments, environ);/**Execute the command*/
		if (exe_stat == -1)
		{
			exe_stat = 126;
			perror("hsh");
			exit(exe_stat);
		} /**Terminate the child process successfully*/
		exit(0);
	}
	else /**It's the parent*/
		wait(&stat);/**Halt the parent's execution until the child completes*/
	exe_stat = WEXITSTATUS(stat);
	return (exe_stat);
	}
