/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:52:14 by ajung             #+#    #+#             */
/*   Updated: 2022/02/11 19:31:07 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	infile_redirection(int infile)//,int *pont)
{
	if (dup2(infile, STDIN_FILENO) < 0)
		return (EXIT_FAILURE);
	close(infile);
	return (EXIT_SUCCESS);
}

int	outfile_redirection(int outfile, int *pont)
{
	if (dup2(outfile, STDOUT_FILENO) < 0)
		return (EXIT_FAILURE);
	if (dup2(pont[0], STDIN_FILENO) < 0)
		return (EXIT_FAILURE);
	close(outfile);
	return (EXIT_SUCCESS);
}


int	exec_child_process(int *pont, t_arg_main *arg_main, int i)
{
	//dprintf(1, "start process enfant\n");
	if (dup2(pont[1], STDOUT_FILENO) < 0)
		return (EXIT_FAILURE);
	close(pont[0]);
	if (exec_cmd(arg_main, i) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	//dprintf(1, "end process enfant\n");
	return (EXIT_SUCCESS);
}

int	exec_parent_process(int *pont, int pid)
{
	//printf("start process parent\n");
	if (dup2(pont[0], STDIN_FILENO) < 0)
		return (EXIT_FAILURE);
	close(pont[1]);
	waitpid(pid, NULL, 0);
	//dprintf(1, "end process parent\n");
	return (EXIT_SUCCESS);
}

void	multi_pipex(int infile, int outfile, t_arg_main *arg_main)
{
	int		i;
	// int		pont[2];
	//int		pont2[2];
	pid_t	pid;

	infile_redirection(infile);
	i = 0;
	while (i < arg_main->argc - 3)
		if (pipe(arg_main->pont[i++]))
			perror_and_exit();
	i = 2;
	while (i < arg_main->argc - 1)
	{
		//dprintf(1, "i = %d\n", i);
		// if (pipe(pont) < 0)
		// 	perror_and_exit();
		pid = fork();
		if (pid < 0)
			perror_and_exit();
		else if (pid == 0)
		{
			if (exec_child_process(arg_main->pont[i - 2], arg_main, i) == EXIT_FAILURE)
				perror_and_exit();
		}
		else if (pid > 0)
		{
			if (exec_parent_process(arg_main->pont[i - 2], pid) == EXIT_FAILURE)
				perror_and_exit();
		}
		i++;
	}
	//pipe(arg_main->pont[i - 2]);
	outfile_redirection(outfile, arg_main->pont[i - 2]);
	exec_cmd(arg_main, i);
}
