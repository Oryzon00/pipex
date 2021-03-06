/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:44:52 by ajung             #+#    #+#             */
/*   Updated: 2022/02/14 21:17:37 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_and_exit(void)
{
	perror("pipex");
	exit (1);
}

//(*arg_main).pont = malloc(sizeof(int *) * (argc - 3));
void	fill_arg_main(t_arg_main *arg_main, int argc, char **argv, char **envp)
{
	arg_main->argc = argc;
	arg_main->argv = argv;
	arg_main->envp = envp;
}

void	free_path_and_args(char **cmd_paths, char **cmd_args, char *cmd_no_arg)
{
	free_split(cmd_paths);
	free_split(cmd_args);
	free(cmd_no_arg);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	add_slash(char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		tmp = str[i];
		str[i] = ft_strjoin(str[i], "/");
		free(tmp);
		if (!str[i])
			exit(-1);
		i++;
	}
}
