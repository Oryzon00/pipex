/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:36:31 by ajung             #+#    #+#             */
/*   Updated: 2022/02/14 21:19:49 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	relative_path(t_arg_main *arg_main, int cmd_num)
{
	char	*cmd_no_arg;
	char	**cmd_args;

	cmd_no_arg = get_cmd_no_arg(arg_main, cmd_num);
	if (!cmd_no_arg)
		return (EXIT_FAILURE);
	cmd_args = get_cmd_arg(arg_main->argv, cmd_num);
	if (!cmd_args)
		return (EXIT_FAILURE);
	execve(cmd_no_arg, cmd_args, arg_main->envp);
	free(cmd_no_arg);
	free_split(cmd_args);
	return (EXIT_FAILURE);
}
