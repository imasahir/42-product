/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 00:44:12 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/19 16:48:14 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_calloc(size_t nmemb, size_t size)
{
	void		*point;

	if (nmemb == 0 || size == 0)
	{
		point = malloc(1);
		if (point == NULL)
			return (0);
		ft_memset(point, 0, 1);
		return (void *)point;
	}
	point = (void *)malloc(nmemb * size);
	if (point == NULL)
		return (0);
	ft_memset(point, 0, nmemb * size);
	return ((void *)point);
}
