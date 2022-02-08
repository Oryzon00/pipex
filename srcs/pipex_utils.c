/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:11:11 by ajung             #+#    #+#             */
/*   Updated: 2022/02/08 21:27:41 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmd_path(char **envp, char **argv)
{
char *PATH_envp;
char **cmd_paths;
// COMMENT RECUPERER PATH_envp e maniere securise ??
// PATH_envp = ft_substr(envp ....);
cmd_paths = ft_split(PATH_envp, ":");
free(PATH_envp);
return (cmd_paths);
}


char	**get_cmd_arg(char **argv, int cmd_num) //cmd_num = 2 ou 3
{
	char **cmd_args;

	cmd_args = ft_split(argv[cmd_num], " ");
	cmd_args++; //on avance de 1 pour ne pas etre sur la commande
	return (cmd_args);
}


int exec_cmd(char ** envp, char **argv, int cmd_num)  //cmd_num = 2 ou 3
{
int  i;
char *cmd;
char **cmd_paths;
char **cmd_args;

cmd_args = get_cmd_arg(argv, cmd_num);

i = -1;
while (cmd_paths[++i])
{
    cmd = ft_join(cmd_paths[i], argv[cmd_num]);
	if (!cmd)
		return (EXIT_FAILURE);
    execve(cmd, cmd_args, envp); // if execve succeeds, it exits and free
    perror("Error"); //<- add perror to debug
    free(cmd); // if execve fails, we free and we try a new path
}
free(cmd_paths);
free(cmd_args--);
return (EXIT_FAILURE);
}
