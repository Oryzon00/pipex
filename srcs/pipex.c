/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:43:31 by ajung             #+#    #+#             */
/*   Updated: 2022/02/11 19:39:36 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	left_side(int infile, int *pont, t_arg_main *arg_main, int i)
{
	if (dup2(infile, STDIN_FILENO) < 0)
		return (EXIT_FAILURE);
	if (dup2(pont[1], STDOUT_FILENO) < 0)
		return (EXIT_FAILURE);
	close(pont[0]);
	close(infile);
	if (exec_cmd(arg_main, i) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int	right_side(int outfile, int *pont, t_arg_main *arg_main, int i)
{
	if (dup2(outfile, STDOUT_FILENO) < 0)
		return (EXIT_FAILURE);
	if (dup2(pont[0], STDIN_FILENO) < 0)
		return (EXIT_FAILURE);
	close(pont[1]);
	close(outfile);
	if (exec_cmd(arg_main, i + 1) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void	pipex(int infile, int outfile, t_arg_main *arg_main, int i)
{
	int		pont[2];
	int		status1;
	int		status2;
	pid_t	child_left;
	pid_t	child_right;

	pipe(pont);
	child_left = fork();
	if (child_left < 0)
		return (perror("Fork: "));
	if (child_left == 0)
		if (left_side(infile, pont, arg_main, i) == EXIT_FAILURE)
			perror_and_exit();
	child_right = fork();
	if (child_right < 0)
		return (perror("Fork: "));
	if (child_right == 0)
		if (right_side(outfile, pont, arg_main, i) == EXIT_FAILURE)
			perror_and_exit();
	close(pont[0]);
	close(pont[1]);
	waitpid(child_left, &status1, 0);
	waitpid(child_right, &status2, 0);
	if (status1 > status2)
		exit(status1);
	else
		exit(status2);
}
