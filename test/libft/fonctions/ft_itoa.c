/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:34:56 by ajung             #+#    #+#             */
/*   Updated: 2021/11/23 11:34:59 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_find_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

char	*ft_is0(void)
{
	char	*output;

	output = (char *)malloc(sizeof(char) * 2);
	if (output == NULL)
		return (NULL);
	output[0] = '0';
	output[1] = '\0';
	return (output);
}

char	*ft_isintmin(void)
{
	char	*output;

	output = (char *)malloc(sizeof(char) * 12);
	if (output == NULL)
		return (NULL);
	output[0] = '-';
	output[1] = '2';
	output[2] = '1';
	output[3] = '4';
	output[4] = '7';
	output[5] = '4';
	output[6] = '8';
	output[7] = '3';
	output[8] = '6';
	output[9] = '4';
	output[10] = '8';
	output[11] = '\0';
	return (output);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*output;

	if (n == 0)
		return (ft_is0());
	if (n == -2147483648)
		return (ft_isintmin());
	output = (char *)malloc(sizeof(char) * (ft_find_len(n) + 1));
	if (output == NULL)
		return (NULL);
	i = ft_find_len(n);
	output[i--] = '\0';
	if (n < 0)
	{
		output[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		output[i--] = n % 10 + '0';
		n = n / 10;
	}
	return (output);
}
