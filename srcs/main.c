/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:43:13 by ajung             #+#    #+#             */
/*   Updated: 2022/02/08 21:06:53 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;

	check_error(argc, argv);
	// Check how the shell treats infile and outfile when they do not exist, 
	// are not readable, writable etc.
	infile = open(argv[1], O_RDONLY);
	outfile = open (argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (infile < 0 || outfile < 0)
		return (-1);
	pipex(infile, outfile, argv, envp);
	return (0);
}
