/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:42:27 by ajung             #+#    #+#             */
/*   Updated: 2021/11/24 19:12:25 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_elem;

	if (!del || !lst || !(*lst))
		return ;
	while (*lst && lst)
	{
		next_elem = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_elem;
	}
	lst = NULL;
}
