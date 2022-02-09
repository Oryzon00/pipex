/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:41:53 by ajung             #+#    #+#             */
/*   Updated: 2021/11/23 16:19:36 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	p;
	char			*output;

	i = 0;
	p = (unsigned char) c;
	output = NULL;
	while (s[i])
	{
		if (s[i] == p)
			output = (char *)(&s[i]);
		i++;
	}
	if (p == 0)
		return ((char *)(&s[i]));
	return (output);
}
