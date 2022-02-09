/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:33:44 by ajung             #+#    #+#             */
/*   Updated: 2021/11/24 17:01:19 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	p;

	p = (unsigned char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == p)
			return ((char *)&(s[i]));
		i++;
	}
	if (p == 0)
		return ((char *)&(s[i]));
	return (NULL);
}
