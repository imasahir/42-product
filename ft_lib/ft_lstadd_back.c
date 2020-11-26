/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 19:14:08 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/14 21:39:01 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*last_ele;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	last_ele = ft_lstlast(*lst);
	last_ele->next = new;
}
