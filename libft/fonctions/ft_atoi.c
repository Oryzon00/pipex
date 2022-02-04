/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:31:48 by ajung             #+#    #+#             */
/*   Updated: 2022/02/01 17:18:08 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

void	check_overflow(long long output, int sign)
{
	if (output * sign > 2147483647)
		error_and_exit();
	else if (output * sign < -2147483648)
		error_and_exit();
}

void	check_multiple_sign(char c)
{
	if ((c == '-') || (c == '+'))
		error_and_exit();
}

int	ft_atoi(const char *nptr)
{
	int				i;
	long long		output;
	int				sign;

	i = 0;
	output = 0;
	sign = 1;
	if (ft_strlen(nptr) > 11)
		error_and_exit();
	while (((9 <= nptr[i]) && (nptr[i] <= 13)) || (nptr[i] == ' '))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	check_multiple_sign(nptr[i]);
	while (('0' <= nptr[i]) && (nptr[i] <= '9'))
	{
		output = nptr[i] - '0' + (output * 10);
		i++;
		check_overflow(output, sign);
	}
	return (output * sign);
}
