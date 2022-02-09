/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:11:11 by ajung             #+#    #+#             */
/*   Updated: 2022/02/09 20:27:39 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


char	**get_cmd_path(char **envp)
{
char	*PATH_envp;
char	**cmd_paths;
int		i;

i = 0;
while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
	i++;
PATH_envp = ft_strdup(envp[i]);
if (PATH_envp == NULL)
	return (NULL);
cmd_paths = ft_split(PATH_envp + 5, ':');
if (cmd_paths == NULL)
	return (NULL);
free(PATH_envp);
add_slash(cmd_paths);
return (cmd_paths);
}


char	**get_cmd_arg(char **argv, int cmd_num) //cmd_num = 2 ou 3
{
	char **cmd_args;

	cmd_args = ft_split(argv[cmd_num], ' ');
	return (cmd_args);
}

char	*get_cmd_no_arg(t_arg_main *arg_main, int cmd_num)
{
	char	**ret_split;
	char	*cmd_no_arg;

	ret_split = ft_split(arg_main->argv[cmd_num], ' ');
	cmd_no_arg = ft_strdup(ret_split[0]);
	free_split(ret_split);
	return (cmd_no_arg);
}

int exec_cmd(t_arg_main *arg_main, int cmd_num)  //cmd_num = 2 ou 3
{
int		i;
char	*cmd;
char	*cmd_no_arg;
char 	**cmd_paths;
char 	**cmd_args;

cmd_args = get_cmd_arg(arg_main->argv, cmd_num); //peut etre sur NULL si pas argument
cmd_paths = get_cmd_path(arg_main->envp);
cmd_no_arg = get_cmd_no_arg(arg_main, cmd_num);
if (cmd_paths == NULL)
	return (EXIT_FAILURE);
i = 0;
while (cmd_paths[i]) 
{
    cmd = ft_strjoin(cmd_paths[i], cmd_no_arg);
	if (!cmd)
	{
		free_path_and_args(cmd_paths, cmd_args, cmd_no_arg);
		return (EXIT_FAILURE);
	}
	//execve devrait avance tout seul de 1 si cmd_arg[0] est la commande
	printf("cmd = %s, \ncmd_arg[1] = %s\n, cmd_no_arg = %s\n\n", cmd, cmd_args[1], cmd_no_arg);
    execve(cmd, cmd_args, arg_main->envp); // if execve succeeds, it exits and free
    free(cmd); // if execve fails, we free and we try a new path
	i++;
}
//si on a rien trouve on free tout
free_path_and_args(cmd_paths, cmd_args, cmd_no_arg);
return (EXIT_FAILURE);
}
