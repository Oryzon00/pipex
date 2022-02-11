/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:28:33 by ajung             #+#    #+#             */
/*   Updated: 2022/02/11 17:29:50 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_error(int argc, char **argv)
{
	if (argc < 5)
	{
		ft_putstr_fd("Error: nombre d'argument != 4\n", 2);
		exit (0);
	}
	(void) argv;
}
