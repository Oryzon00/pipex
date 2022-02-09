/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:29:43 by ajung             #+#    #+#             */
/*   Updated: 2022/02/09 19:12:04 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

void	check_error(int argc, char **argv);
void	pipex(int infile, int outfile, t_arg_main *arg_main);
int		exec_cmd(t_arg_main *arg_main, int cmd_num);
void 	free_path_and_args(char **cmd_paths, char **cmd_args);
void	free_split(char **str);
void	add_slash(char **str);
void	fill_arg_main(t_arg_main *arg_main, int argc, char **argv, char **envp);


typedef struct s_arg_main
{
	int		argc;
	char	**argv;
	char	**envp;
} t_arg_main;


#endif
