/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:35:33 by ajung             #+#    #+#             */
/*   Updated: 2021/11/23 11:35:35 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	int		i;
	char	*adresse;

	i = 0;
	adresse = s;
	while (n)
	{
		adresse[i] = (unsigned char) c;
		i++;
		n--;
	}
	return (s);
}
