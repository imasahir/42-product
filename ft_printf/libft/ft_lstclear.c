/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 01:52:20 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/14 21:40:47 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*del_ele;

	if (!del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		del_ele = *lst;
		*lst = del_ele->next;
	}
	free(del_ele);
	*lst = NULL;
}
