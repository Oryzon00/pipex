/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:21:54 by ajung             #+#    #+#             */
/*   Updated: 2022/01/14 17:16:24 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define MAX_FD 1024

typedef struct s_fdlist
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
}	t_fdlist;

char	*get_next_line(int fd);
char	*fill_stock(char *stock, char *buffer, int fd);
char	*ft_strndup_gnl(const char *s, int n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_free_s1(char *s1, char *s2);
char	*get_buffer(int my_fd, t_fdlist *fd_list);
char	*make_line(char *stock, char *buffer);

#endif
