/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:43:13 by ajung             #+#    #+#             */
/*   Updated: 2022/02/09 19:11:24 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int			infile;
	int			outfile;
	t_arg_main	arg_main;

	check_error(argc, argv);
	// Check how the shell treats infile and outfile when they do not exist, 
	// are not readable, writable etc.
	infile = open(argv[1], O_RDONLY);
	outfile = open (argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644); //0644 necessaire?
	if (infile < 0 || outfile < 0)
	{
		ft_putstr_fd("Error: open", 2);
		return (-1);
	}
	fill_arg_main(&arg_main, argc, argv, envp);
	pipex(infile, outfile, &arg_main);
	return (0);
}
