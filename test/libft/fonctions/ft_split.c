/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:45:45 by ajung             #+#    #+#             */
/*   Updated: 2022/01/17 21:31:57 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static unsigned int	find_nb_word(char const *s, char c);
static size_t		find_len_word(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**output;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	output = malloc(sizeof(char *) * (find_nb_word(s, c) + 1));
	if (output == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			output[j] = ft_substr(s, i, find_len_word(&s[i], c));
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	output[j] = NULL;
	return (output);
}

static unsigned int	find_nb_word(char const *s, char c)
{
	int				i;
	unsigned int	nb_word;

	i = 0;
	nb_word = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			nb_word++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nb_word);
}

static size_t	find_len_word(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}
