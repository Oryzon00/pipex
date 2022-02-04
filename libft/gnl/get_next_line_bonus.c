/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:21:32 by ajung             #+#    #+#             */
/*   Updated: 2021/12/07 17:09:26 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_fdlist	fd_list[MAX_FD];
	char			*buffer;
	char			*output;
	char			*stock;

	buffer = get_buffer(fd, fd_list);
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (buffer[0] != '\0')
		stock = ft_strndup_gnl(buffer, ft_strlen(buffer));
	else
		stock = ft_strndup_gnl("", 1);
	stock = fill_stock(stock, buffer, fd);
	if (!stock)
		return (NULL);
	output = make_line(stock, buffer);
	return (free(stock), output);
}

char	*make_line(char *stock, char *buffer)
{
	int		i;
	int		j;
	char	*output;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	output = ft_strndup_gnl(stock, i + (stock[i] != '\0'));
	j = 0;
	i += (stock[i] != '\0');
	while (stock[i])
		buffer[j++] = stock[i++];
	buffer[j] = '\0';
	return (output);
}

char	*fill_stock(char *stock, char *buffer, int fd)
{
	int	read_output;

	read_output = 1;
	while (read_output && !(ft_strchr(stock, '\n')))
	{
		read_output = read(fd, buffer, BUFFER_SIZE);
		buffer[read_output] = '\0';
		if (read_output == 0)
			break ;
		if (read_output < 0)
		{
			free(stock);
			return (NULL);
		}
		stock = ft_strjoin_free_s1(stock, buffer);
	}
	if (stock[0] == 0 && read_output == 0)
		return (free(stock), NULL);
	return (stock);
}

char	*get_buffer(int my_fd, t_fdlist *fd_list)
{
	int	i;

	i = 1;
	if (my_fd == 0)
		return (fd_list[0].buffer);
	while (i < MAX_FD && fd_list[i].fd != 0)
	{
		if (fd_list[i].fd == my_fd)
			return (fd_list[i].buffer);
		i++;
	}
	if (i == MAX_FD)
		return (NULL);
	else
		fd_list[i].fd = my_fd;
	return (fd_list[i].buffer);
}
