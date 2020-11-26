/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 16:01:41 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/12 16:27:42 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list *new_ele;

	if (!(new_ele = malloc(sizeof(t_list))))
		return (NULL);
	new_ele->content = content;
	new_ele->next = NULL;
	return (new_ele);
}
