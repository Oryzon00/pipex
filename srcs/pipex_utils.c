/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:11:11 by ajung             #+#    #+#             */
/*   Updated: 2022/02/14 20:36:48 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmd_path(char **envp)
{
	char	*path_envp;
	char	**cmd_paths;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path_envp = ft_strdup(envp[i]);
	if (path_envp == NULL)
		return (NULL);
	cmd_paths = ft_split(path_envp + 5, ':');
	if (cmd_paths == NULL)
		return (NULL);
	free(path_envp);
	add_slash(cmd_paths);
	return (cmd_paths);
}

char	**get_cmd_arg(char **argv, int cmd_num)
{
	char	**cmd_args;

	cmd_args = ft_split(argv[cmd_num], ' ');
	return (cmd_args);
}

char	*get_cmd_no_arg(t_arg_main *arg_main, int cmd_num)
{
	char	**ret_split;
	char	*cmd_no_arg;

	ret_split = ft_split(arg_main->argv[cmd_num], ' ');
	if (!ret_split || !ret_split[0])
	{
		free_split(ret_split);
		return (NULL);
	}
	cmd_no_arg = ft_strdup(ret_split[0]);
	free_split(ret_split);
	return (cmd_no_arg);
}

int	try_all_path(char **cmd_paths, char *cmd_no_arg, char **cmd_args,
	t_arg_main *arg_main)
{
	int		i;
	char	*cmd;

	i = 0;
	while (cmd_paths[i])
	{
		cmd = ft_strjoin(cmd_paths[i], cmd_no_arg);
		if (!cmd)
		{
			free_path_and_args(cmd_paths, cmd_args, cmd_no_arg);
			return (EXIT_FAILURE);
		}
		execve(cmd, cmd_args, arg_main->envp);
		free(cmd);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	exec_cmd(t_arg_main *arg_main, int cmd_num)
{
	char	*cmd_no_arg;
	char	**cmd_paths;
	char	**cmd_args;

	if (ft_strchr(arg_main->argv[cmd_num], '/') != NULL)
		if (relative_path(arg_main, cmd_num) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	cmd_args = get_cmd_arg(arg_main->argv, cmd_num);
	cmd_paths = get_cmd_path(arg_main->envp);
	cmd_no_arg = get_cmd_no_arg(arg_main, cmd_num);
	if (cmd_paths == NULL || cmd_no_arg == NULL)
	{
		free_path_and_args(cmd_paths, cmd_args, cmd_no_arg);
		write(2, "Error: invalid cmd or path\n", 27);
		exit (1);
	}
	if (try_all_path(cmd_paths, cmd_no_arg, cmd_args, arg_main) == EXIT_FAILURE)
	{
		free_path_and_args(cmd_paths, cmd_args, cmd_no_arg);
		return (EXIT_FAILURE);
	}
	free_path_and_args(cmd_paths, cmd_args, cmd_no_arg);
	return (EXIT_FAILURE);
}
